#include <iostream>
#include <fstream>

#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>

#include "util.h"
#include "drawing.h"
#include "mesh.h"
#include "camera.h"
#include "ui.h"
#include "world.h"
#include "model.h"

#include "yabsl-driver.hh"

#define MAX_HSV 1536

using namespace std;

double max(double a, double b) {
	if(a < b) 
		return b;
	else 
		return a;
}
double min(double a, double b) {
	if(a < b) 
		return a;
	else 
		return b;
}

void runSDL();

World *world;
Mesh *mesh;
ModelInstance *miTest;
Camera *camera;
Surface *surface;
UI_SDL *ui_sdl;

int main() {
	int width = 800;
	int height = 800;

	//yabsl testing
	yabsl_driver driver;
	//Model::models["loadedtest"] = driver.parse("sample.yabsl");

	//MODEL TESTING, TODO
	Model::models["test"];
	Model::models["test"].addChild("torus", new Mesh());
	Model::models["test"].addChild("sphere", new Mesh());

	Model::models["test"].getChild("torus")->genPrimTorus(5, 1);
	Model::models["test"].getChild("sphere")->genPrimSphere(2);

	Model::models["test"].addTransform("torus");
	Model::models["test"].addTransform("sphere");

	Model::models["test"].getTransform("torus")->addTransformElement("r", "1", "0", "0");
	

	miTest = new ModelInstance("test");
	miTest->setLocation(Vect4 (0,0,-2));
	miTest->setScale(1);

	//Prepare world
	World w;

	//Prepare mesh
	mesh = new Mesh(); //Not on heap
	///*
	mesh->loadFromObjFile("wt_teapot.obj");
	{
		Mesh *temp = new Mesh();
		temp->genPrimTorus(1, 0.1);
		temp->setScale(0.2);
		temp->setLocation(Vect4 (1, 2, 0));
		mesh->addChild("smoke", temp);

		temp = new Mesh();
		temp->genPrimSphere(0.6);
		temp->setLocation(Vect4 (1, -1, 1));
		mesh->addChild("ball 1", temp);

		temp = new Mesh(*temp);
		temp->genPrimSphere(0.6);
		temp->setLocation(Vect4 (-1, -1, 1));
		mesh->addChild("ball 2", temp);

		temp = new Mesh(*temp);
		temp->genPrimSphere(0.6);
		temp->setLocation(Vect4 (1, -1, -1));
		mesh->addChild("ball 3", temp);

		temp = new Mesh(*temp);
		temp->genPrimSphere(0.6);
		temp->setLocation(Vect4 (-1, -1, -1));
		mesh->addChild("ball 4", temp);
	}
	//mesh->loadFromObjFile("testlandscape.obj");
	mesh->setLocation(Vect4 (0, 0, -2));
	mesh->setScale(1);
	//*/
	//mesh->genPrimTorus(4, 2);
	//mesh->genPrimBox(4, 2, 3);
	w.addMesh(mesh);


	//Prepare render
	Surface s (width, height);
	s.clear(255);
	Camera c (90);


	//Hold onto things
	world = &w;
	camera = &c;
	surface = &s;

	//Render once
	s.clear(255);
	c.renderMeshes(&w, &s);

	//Write to file
	s.write_to_file("out.ppm");
	cout << "Done Writing" << endl;


	runSDL();

	cout << " done" << endl;
}

void runSDL() {
	UI_SDL uis(surface, world);
	ui_sdl = &uis;

	//world->addMesh(&ui_sdl->dragMesh);

	cout << "Initialized\n";
	

	double i = 0;
	while(!ui_sdl->quit) {
		if(!ui_sdl->isPaused()) {
			//Prepare mesh
			i+=5;
			mesh->setRotation(Vect4(d2r(i / 3.92), d2r(i), 0));
			miTest->setRotation(Vect4(d2r(i / 3.92), d2r(i), 0));
		}

		//mesh->setRotation(ui_sdl->rotation[0], ui_sdl->rotation[1], ui_sdl->rotation[2]);
		//mesh->setLocation(ui_sdl->translation);
		//mesh->setScale(ui_sdl->scale);

		//Render Mesh
		surface->clear(255);
		camera->renderMesh(&(ui_sdl->dragMesh), surface);
		camera->renderMeshes(world, surface);

		//TODO
		camera->renderModel(miTest, surface);

		//Handle UI
		ui_sdl->mainloop();

		usleep(20 * 1000);
	}
}
