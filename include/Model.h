#ifndef MODEL_H
#define MODEL_H

#include <windows.h>
#include <gl.h>
#include "Model_3DS.h"
#include "Cube.h"

class Model : public Object {

private:
	Model_3DS* model;
	double scale;
	Cube container;
	int hasLightSource;
	vertex lightSource;
	double yRotated;

public:
	Model();
	Model(Model_3DS* model, vertex center, double scale, vertex containerCenter, double width, double height, double length,
		int tex, int hasLightSource = false, vertex lightSource = { 0, 0, 0 }, double yRotated = 0);
	void draw();
};

#endif 
