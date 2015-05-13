#include <iostream>
#include <cmath>

#include "camera.h"

Camera::Camera(double fov) 
: Entity() {
	this->fov = fov;
}

void Camera::renderMeshSingle(const Mesh *m, Mat4 t, Surface *s) {
	Graphics g (s);
	Vect4 *transVerts = new Vect4[m->verts.size()]; //Temporary storage for transformed vertices
	Mat4 temp (t);
	//double sf = 1;

	Vect4 tempLighting = Vect4::unit(Vect4(1, 1, 2));
	int *lightVals = new int[m->faces.size()];

	//Temporary shift!!
	temp = Mat4::mult(Mat4::TranslateMat(Vect4(0,0,-15)), temp);
	temp = Mat4::mult(Mat4::ProjectPersp(), temp);

	//Transform points
	for(int i = 0; (size_t)i < m->verts.size(); i++) {
		transVerts[i] = temp.mult(m->verts[i]);
	}

	//Grab light values
	for(int i = 0; (size_t)i < m->faces.size(); i++) {
		Vect4 v1 = transVerts[m->faces[i].v1];
		Vect4 v2 = transVerts[m->faces[i].v2];
		Vect4 v3 = transVerts[m->faces[i].v3];

		if(isBackface(v1, v2, v3))
			;//continue;//g.setColor(255, 0, 0);//continue;
	
		double light = Vect4::dot(tempLighting, Vect4::unit(Vect4::cross(v2 - v1, v3 - v1)));
		if(light > 0) {
			lightVals[i] = light * 255;
		} else {
			lightVals[i] = 0;
		}
	}

	//Normalize w (only for x and y)
	for(int i = 0; (size_t)i < m->verts.size(); i++) {
		transVerts[i].coord[0] /= transVerts[i].coord[3];
		transVerts[i].coord[1] /= transVerts[i].coord[3];

		if(transVerts[i].coord[3] < 0.01 && transVerts[i].coord[3] > -0.01) {
			//std::cerr << i << " " << transVerts[i].coord[3] << " woop\n";
		}
	}

	//Figure out mapping of points to screen
	//mapsize is how wide half the screen should be
	//In world units
	double mapsize = tan(d2r(fov / 2));
	double pixScale = s->width / (2 * mapsize); //How wide is a unit in pixels
	double offX = s->width / 2;
	double offY = s->height / 2;

	//Transform to screen coords
	for(int i = 0; (size_t)i < m->verts.size(); i++) {
		transVerts[i].coord[0] = transVerts[i].coord[0] * pixScale + offX;
		transVerts[i].coord[1] = transVerts[i].coord[1] * pixScale + offY;
	}



	//Draw Triangles
	for(int i = 0; (size_t)i < m->faces.size(); i++) {
		Vect4 v1 = transVerts[m->faces[i].v1];
		Vect4 v2 = transVerts[m->faces[i].v2];
		Vect4 v3 = transVerts[m->faces[i].v3];

		if(isBackface(v1, v2, v3))
			continue;//g.setColor(255, 0, 0);//continue;
	
		double l = lightVals[i];
		g.setColor(l,l,l);

		g.fillTri(
				PointZ ((int)v1[0], (int)v1[1], v1[2]),
				PointZ ((int)v2[0], (int)v2[1], v2[2]),
				PointZ ((int)v3[0], (int)v3[1], v3[2]));
	}

	//Draw wireframe faces with transformed vertices
	/*
	g.setColor(0,0,0);
	for(int i = 0; (size_t)i < m->faces.size(); i++) {
		Vect4 v1 = transVerts[m->faces[i].v1];
		Vect4 v2 = transVerts[m->faces[i].v2];
		Vect4 v3 = transVerts[m->faces[i].v3];

		g.drawLineZ((int)v1[0], (int)v1[1], v1[2], (int)v2[0], (int)v2[1], v2[2]);
		g.drawLineZ((int)v2[0], (int)v2[1], v2[2], (int)v3[0], (int)v3[1], v3[2]);
		g.drawLineZ((int)v3[0], (int)v3[1], v3[2], (int)v1[0], (int)v1[1], v1[2]);
	}
	*/

	delete transVerts;
	delete lightVals;
}

void Camera::renderMeshOffset(const Mesh *m, Mat4 offset, Surface *s) {
	offset = Mat4::mult(offset, m->forwardMat());
	//Render itself
	renderMeshSingle(m, offset, s);


	//Render Children
	for(auto it = m->children.cbegin(); it != m->children.cend(); it++) {
		renderMeshOffset(it->second, offset, s);
	}
}

void Camera::renderMesh(const Mesh *m, Surface *s) {
	renderMeshOffset(m, Mat4::IdentityMat(), s);
}

void Camera::renderMeshes(const World *w, Surface *s) {
	for(int i = 0; (size_t)i < w->meshes.size(); i++) {
		//Skip nulls
		if(!w->meshes[i])
			continue;

		renderMesh(w->meshes[i], s);
	}
}

void Camera::renderModel(ModelInstance *m, Surface *s) {
	m->prepareTransforms();

	Model *mclass = m->getModel();
	//Doesn't support nested children
	for(auto it = mclass->children.cbegin(); it != mclass->children.cend(); it++) {
		renderMeshSingle(it->second, m->transforms[it->first], s);
	}
}

/*
void Camera::renderSubModel(ModelInstance *m, string parent, Mat4 offset, Surface *s) {
	Mat4 temp = Mat4::mult(offset, m->transforms[parent]);

	//Render Children
}
*/

bool Camera::isBackface(Vect4 v1, Vect4 v2, Vect4 v3) {
	return Vect4::crossZ(v2 - v1, v3 - v1) <= 0;
}
