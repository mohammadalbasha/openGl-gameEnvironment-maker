#ifndef CUBE_H
#define CUBE_H

#include <windows.h>
#include <gl.h>
#include <vector>
#include "Controller.h"
#include "CameraMovementObserver.h"
#include "DrawCube.h"
#include "Object.h"


class Cube : public Object, public CameraMovementObserver {

	double  width, height, length, yRotated, yRotatedRadians;
	bool isTextured;
	std :: vector<int> textures, hRepeation, vRepeation;

public:
	void setTextures(std :: vector<int> textures, std :: vector<int> hRepeation, std :: vector<int> vRepeation);
	void draw();
	void notify(double& posX, double& posY, double& posZ);

	Cube();

	Cube(vertex center, double width, double height, double length, double yRotated);
};

#endif 
