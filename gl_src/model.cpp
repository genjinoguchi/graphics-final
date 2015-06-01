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
double AnimFunc::eval(double x) { //TODO, for testing only
	return 1.5;
}


//===Anims===
void Anim::addFunc(string name, AnimFunc *f) {
	functions.push_back({name, f});
}

void Anim::prepareVars(var_hash *vars) {

	//placeholder
	double x = 0.1;

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

	currState = "default";
};

void ModelInstance::prepareTransforms() {
	Model* m = getModel();
	
	//prepare all vars
	for(auto it = m->vars.begin(); it != m->vars.end(); it++) {
		it->second = 0;
	}

	//Check that an animation exists for the current state
	if(m->anims.count(currState)) {
		m->anims[currState].prepareVars(&(m->vars));
	} else {
		cerr << "Error: no animation named \"" << currState << "\"\n";
	}
	
	//Prepare all transforms using aforementioned vars
	for(auto it = m->transforms.begin(); it != m->transforms.end(); it++) {
		transforms[it->first] = it->second.createMat(&(m->vars));
	}


}

Model* ModelInstance::getModel() {
	return &Model::models[modelclass];
}
