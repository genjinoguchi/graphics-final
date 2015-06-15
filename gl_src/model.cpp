#include <stdexcept>

#include "model.h"


//===MODELS===

unordered_map<string, Model> Model::models;


void Model::addVar(string name) {
	vars[name] = 0;
}

void Model::addTransform(string name) {
	if(!getChild(name)) {
		cerr << "There is no mesh with name " << name << "\n";
		return;
	}
	if(transforms.count(name)) {
		cerr << "Transform already exists with name " << name << "\n";
		return;
	}

	transforms[name];
}

TransformSequence* Model::getTransform(string name) {
	if(!transforms.count(name)) {
		cerr << "No transform exists with name " << name << "\n";
		return NULL;
	}
	return &transforms[name];
}





//===TRANSFORMS===

void TransformSequence::addTransformElement(string type, string x, string y, string z) {
	tElements.push_back({type, x, y, z});
	tElements.back()[0] = type;
	tElements.back()[1] = x;
	tElements.back()[2] = y;
	tElements.back()[3] = z;
}


//Creates a transformation matrix from the given vars and the transformelements in this
Mat4 TransformSequence::createMat(var_hash *v) {

	Mat4 temp = Mat4::IdentityMat();

	//For each transformelement
	for(int i = 0; (size_t)i < tElements.size(); i++) {
		//prepare coords (parse/look-up-vars)
		Vect4 coords;
		for(int j = 1; j <= 3; j++) {
			//try parsing each coordinate as a double
			try {
				coords[j - 1] = std::stod(tElements[i][j]);
			} catch (const std::invalid_argument& ia) {
				//Then try interpreting it as a variable
				if(v->count(tElements[i][j])) {
					coords[j - 1] = v->at(tElements[i][j]);
				} else {
					cerr << "No variable of name \"" << tElements[i][j] << "\" \n";
					return Mat4::IdentityMat();
				}
			}
		}

		//actually make the matrix
		if(!tElements[i][0].compare("t")) {
			temp = Mat4::mult(Mat4::TranslateMat(coords) , temp);
		} else if(!tElements[i][0].compare("r")) {
			temp = Mat4::mult(Mat4::RotateZMat(coords[2]) , temp);
			temp = Mat4::mult(Mat4::RotateYMat(coords[1]) , temp);
			temp = Mat4::mult(Mat4::RotateXMat(coords[0]) , temp);
		} else if(!tElements[i][0].compare("s")) {
			temp = Mat4::mult(Mat4::ScaleMat(coords) , temp);
		} else {
			cerr << "Invalid transformation type\n";
		}
	}

	return temp;
}


//===Functions===
AnimFunc::AnimFunc() {
	type = 'l';
}

AnimFunc* AnimFunc::constFunc(double constant) {
	AnimFunc *temp = new AnimFunc;
	temp->type = 'c';
	temp->addOrderedPair(0, constant);

	return temp;
}

double AnimFunc::eval(double x) { //TODO, for testing only
	switch(type) {
		case 'c':
			return pairs.begin()->second;
			break;
		case 'l':
			{
				if(pairs.empty()) {
					cerr << "No control points in animfunc\n";
					return 0;
				}

				auto it = pairs.begin();

				//check if before first point
				if(it->first > x) {
					return it->second;
				}

				while(true) {
					//Check if after last point
					//ends dont lerp, just continue at last y value
					if(std::next(it) == pairs.end()) {
						return it->second;
					} 

					//otherwise, check if reached right pair, do the thing
					if(std::next(it)->first >= x) {
						return lerp(
								it->second, 
								std::next(it)->second, 
								(x - it->first) / (std::next(it)->first - it->first)); 
					}

					it++;
				}
				break;
			}
		default:
			cerr << "Error invalid func type\n";
			return -1;
			break;
	}
}

//x from 0-1
void AnimFunc::addOrderedPair(double x, double y) {
	//check bounds
	if(x > 1 || x < 0) {
		cerr << "Can't add ordered pairs outside x E [0,1]\n";
		return;
	}

	pairs[x] = y;
}


//===Anims===
Anim::Anim() {
	duration = 0;
	next = "loop";
}

void Anim::addFunc(string name, AnimFunc *f) {
	functions.push_back({name, f});
}

void Anim::prepareVars(var_hash *vars, double time) {

	double x;

	if(duration == 0) {
		x = 0;
	} else {
		x = time / duration;
	}
		

	//loop through all function and apply them to vars
	for(int i = 0; (size_t)i < functions.size(); i++) {
		if(vars->count(functions[i].var)) {
			vars->at(functions[i].var) = functions[i].func->eval(x);
		} else {
			cerr << "VARIABLE SET IN ANIM WHICH DOESNT EXIST\n";
			continue;
		}
	}
}


//===ModelInstance===
ModelInstance::ModelInstance(string m) : modelclass(m) { 
	if(!Model::models.count(m)) {
		cerr << "INSTANCE OF MODEL WHICH DOESNT EXIST\n";
	}

	currstate = "default";
};

void ModelInstance::prepareTransforms() {
	Model* m = getModel();
	
	//prepare all vars
	for(auto it = m->vars.begin(); it != m->vars.end(); it++) {
		it->second = 0;
	}

	//Check that an animation exists for the current state
	if(m->anims.count(currstate)) {
		m->anims[currstate]->prepareVars(&(m->vars), animtime);
	} else {
		cerr << "Error: no animation named \"" << currstate << "\"\n";
	}
	
	//Prepare all transforms using aforementioned vars
	for(auto it = m->transforms.begin(); it != m->transforms.end(); it++) {
		transforms[it->first] = it->second.createMat(&(m->vars));
	}


}

void ModelInstance::update(double time) {
	Model* m = getModel();

	//Check that an animation exists for the current state
	if(!m->anims.count(currstate)) {
		return;
	}

	Anim* animP = m->anims[currstate];
	double duration = animP->duration;
	
	animtime += time;
	if(animP->next == "loop") {
		while(animtime > duration) {
			animtime -= duration;
		}
	} else {
		if(!m->anims.count(animP->next)) {
			cerr << "Error, next anim set to \"" << animP->next << "\", but anim does not exist\n";
			return;
		}
		currstate = animP->next;
		animtime = 0;
	}
	
}

Model* ModelInstance::getModel() {
	return &Model::models[modelclass];
}
