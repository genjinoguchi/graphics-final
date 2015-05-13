#ifndef CAMERA_H
#define CAMERA_H

#include "mesh.h"
#include "matrix.h"
#include "drawing.h"
#include "util.h"
#include "entity.h"
#include "world.h"
#include "model.h"

class Camera: public Entity { 
	double fov; //FOV in degrees

	public:
		Camera(double fov);


		//Renders this mesh and children and its location in the world
		//(just calls renderMeshOffset with identity)
		void renderMesh(const Mesh *m, Surface *s);

		//Renders this mesh and children at offset times its location (offset by t)
		void renderMeshOffset(const Mesh *m, Mat4 offset, Surface *s);

		//Renders just this mesh at location t in the world
		void renderMeshSingle(const Mesh *m, Mat4 t, Surface *s);

		void renderMeshes(const World *w, Surface *s);

		void renderModel(ModelInstance *m, Surface *s);
		//void renderSubModel(ModelInstance *m, string parent, Mat4 offset, Surface *s);

		static bool isBackface(Vect4 v1, Vect4 v2, Vect4 v3);
};

#endif
