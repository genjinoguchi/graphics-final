#include "model.h"

void Model::addMesh(string name) {
	if(meshes.count(name)) {
		cerr << "Mesh already exists with name " << name << "\n";
		return;
	}
	meshes[name];
}

Mesh* Model::getMesh(string name) {
	if(!meshes.count(name)) {
		cerr << "No mesh exists with name " << name << "\n";
		return NULL;
	}
	return &meshes[name];
}

void Model::addTransform(string name) {
	if(!meshes.count(name)) {
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
