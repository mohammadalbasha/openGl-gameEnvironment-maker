#include "Cube.h"
#include <vector>


Cube::Cube() {}

Cube::Cube(vertex center, double width, double height, double length, double yRotated) : Object(center) {
	this->width = width;
	this->height = height;
	this->length = length;
	this->yRotated = yRotated;
	this->yRotatedRadians = yRotated * pi / 180.0;
	this->isTextured = false;
}

void Cube::setTextures(std :: vector<int> textures, std :: vector<int> hRepeation, std :: vector<int> vRepeation) {
	this -> textures = textures;
	this -> hRepeation = hRepeation;
	this -> vRepeation = vRepeation;
	isTextured = true;
}

void Cube::draw() {
	glPushMatrix();

	glTranslated(center.x, center.y, center.z);
	glRotated(yRotated, 0, 1, 0);

	DrawCube :: draw({0, 0, 0}, width, height, length, isTextured, textures, hRepeation, vRepeation); 

	glPopMatrix();
}

void Cube::notify(double& posX, double& posY, double& posZ) {
	vertex pos = {posX - this -> center.x, posY - this -> center.y, posZ - this -> center.z};
	pos = pos.rotateY(-yRotatedRadians);

	double collisionDistance = 0.2;
	if( (pos.x >= -collisionDistance && pos.x <= width + collisionDistance) && 
		(pos.y >= -collisionDistance && pos.y <= height + collisionDistance) &&
		(pos.z <= collisionDistance && pos.z >= -length - collisionDistance) ) {
		posX = camera.posX;
		posY = camera.posY;
		posZ = camera.posZ;
	}
}