#include "Stairs.h"

#define pi acos(-1)

Stairs::Stairs() {}

Stairs::Stairs(double posX, double posY, double posZ
    , double horizontal, double vertical, double height, double yRotated) {
    this->posX = posX;
    this->posY = posY;
    this->posZ = posZ;
    this->horizontal = horizontal;
    this->vertical = vertical;
    this->height = height;
    this->yRotated = yRotated;
    this->yRotatedRadians = yRotated * pi / 180.0;

    setSteps(height);
}

void Stairs::setTexture(int texture) {
    this -> texture = texture;
}

void Stairs::setSteps(int steps) {
    this->steps = steps;
    this->stepHeight = (height / steps);
    this->stepDepth = (vertical / steps);
}

void Stairs::setStepHeight(double stepHeight) {
    this->steps = (height / stepHeight);
    setSteps(this->steps);
}

void Stairs::setStepDepth(double stepDepth) {
    this->steps = (vertical / stepDepth);
    setSteps(this->steps);
}

void Stairs::draw() {
    glPushMatrix();

    glTranslated(posX, posY, posZ);
    glRotated(yRotated, 0, 1, 0);

    double zCoord = 0, yCoord = 0;
    for (int i = 0; i < steps; i++, zCoord -= stepDepth, yCoord += stepHeight) {
        DrawCube::draw({0, yCoord, zCoord}, horizontal, stepHeight, stepDepth, true, {texture}, {1}, {1});
    }

    glPopMatrix();
}

void Stairs::notify(double& posX, double& posY, double& posZ) {
    vertex pos = { posX - this->posX, posY - this->posY, posZ - this->posZ };
    pos = pos.rotateY(-yRotatedRadians);

    if ((pos.x >= -1e-3 && pos.x <= horizontal + 1e-3) && (pos.y >= -1e-3 && pos.y <= height + 1e-3) && (pos.z <= 1e-3 && pos.z >= -vertical - 1e-3)) {
        posY = this->posY + ceil((-pos.z) / stepDepth) * stepHeight;
    }

}
