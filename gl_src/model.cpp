#include <stdexcept>

#include "model.h"


//===MODELS===

unordered_map<string, Model> Model::models;


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

Mat4 TransformSequence::createMat(var_hash *v) {
	//v is ignored for now

	Mat4 temp = Mat4::IdentityMat();

	for(int i = 0; (size_t)i < tElements.size(); i++) {
		Vect4 coords;
		try {
			coords = Vect4(std::stod(tElements[i][1]), 
									std::stod(tElements[i][2]),
									std::stod(tElements[i][3]));
		} catch (const std::invalid_argument& ia) {
			cerr << "Transform argument not double\n";
		}

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




//===ModelInstance===
ModelInstance::ModelInstance(string m) : modelclass(m) { 
	if(!Model::models.count(m)) {
		cerr << "INSTANCE OF MODEL WHICH DOESNT EXIST\n";
	}


};

void ModelInstance::prepareTransforms() {
	Model* m = getModel();
	
	for(auto it = m->transforms.begin(); it != m->transforms.end(); it++) {
		//That null will eventually be vars
		transforms[it->first] = it->second.createMat((var_hash *)NULL);
	}


}

Model* ModelInstance::getModel() {
	return &Model::models[modelclass];
}
