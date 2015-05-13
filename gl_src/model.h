#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>
#include <unordered_map>

#include "matrix.h"
#include "mesh.h"
#include "entity.h"

using std::string;
using std::vector;
using std::unordered_map;

typedef unordered_map<string, double> var_hash;

class TransformSequence {
public:
	vector<std::array<string, 4>> tElements;

	//adds another transformation onto the list
	//x y and z can be doubles (in string form) or var names
	void addTransformElement(string type, string x, string y, string z);

	Mat4 createMat(var_hash *v);
};

class Anim {
	
};

class Model : public Mesh{
public:
	static unordered_map<string, Model> models;


	void addTransform(string name);
	TransformSequence* getTransform(string name);

	unordered_map<string, TransformSequence> transforms; //should be one for each mesh

private:
	var_hash vars;
};

class ModelInstance : public Entity{
public:
	unordered_map<string, Mat4> transforms;

	ModelInstance(string m);

	//sets all transforms in the parents
	void prepareTransforms();

	Model* getModel();
private:
	string modelclass;
	string currState;
};



#endif
