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

class AnimFunc {
public:
	double eval(double x); //evaluate the function at an x from 0-1 (undefined otherwise)
};

class Anim {
public:
	typedef struct { 
		string var;
		AnimFunc* func;
	} varsetter;
	vector<varsetter> functions;
	

	void addFunc(string name, AnimFunc *f);
	void prepareVars(var_hash *vars);
};

class Model : public Mesh{
public:
	static unordered_map<string, Model> models;

	void addVar(string name);
	void addTransform(string name);
	TransformSequence* getTransform(string name);

	//set anims directly, since they're public
	unordered_map<string, Anim> anims;
	unordered_map<string, TransformSequence> transforms; //should be one for each mesh

	var_hash vars;
};

class ModelInstance : public Entity{
public:
	unordered_map<string, Mat4> transforms;

	ModelInstance(string m);

	//sets all transforms in the parents
	void prepareTransforms();

	

	string currState; //which anim is it in
	Model* getModel();
private:
	string modelclass;
};



#endif
