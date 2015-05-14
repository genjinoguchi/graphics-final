#ifndef MESH_H
#define MESH_H

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

#include "matrix.h"
#include "entity.h"
#include "util.h"

using std::string;
using std::vector;
using std::unordered_map;

class Face {
public:
	int v1, v2, v3; //Vertices
	//char r, g, b;
	Face();
	Face(int a, int b, int c);

	string to_string();
};

class Mesh: public Entity {
public:
	vector<Vect4> verts;
	vector<Face> faces;
	unordered_map<string, Mesh *> children;

	//If true, the world this is part of will delete it when it garbage-collects
	int markedForDeath = FALSE;
	//If true, the world this is part of will delete it when it's marked for death
	int deleteOnRemove = TRUE; 
	
	Mesh();
	Mesh(const Mesh& other);
	Mesh(int deleteonremove);
	~Mesh();

	void clear(); //makes it blank again (verts/faces)

	//These child meshes will be deleted with the parent
	void addChild(string name, Mesh *m);
	Mesh* getChild(string name);

	//Returns the index of the new vertex
	int addVert(Vect4 v);
	void addFace(Face f); 

	void loadFromObjFile(string filename);

	void applyTransform(Mat4 m); //Doesn't modify the verts, only transVerts

	string to_string() const;

	void genPrimEdge(Vect4 a, Vect4 b);
	//Adds edges for a circle
	//in xy plane
	void genPrimCircle(Vect4 c, double r);
	//Start, start control, end control, end
	void genPrimBezier(Vect4 a, Vect4 b, Vect4 c, Vect4 d);
	void genPrimHermite(Vect4 p0, Vect4 p1, Vect4 r0, Vect4 r1);

	void genPrimBox(double lx, double ly, double lz);
	void genPrimSphere(double r);
	void genPrimTorus(double R, double r);

	//Interprets commands from yabsl file
	//for now just 'loadfile "foo.bar"'
	void doCommand(vector<string> c);


private:
	char *myStrtok(char *s, char delim);
};

#endif
