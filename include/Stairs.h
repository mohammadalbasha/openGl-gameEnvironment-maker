#ifndef STAIRS_H
#define STAIRS_H

#include <windows.h>
#include <gl.h>
#include "CameraMovementObserver.h"
#include "DrawCube.h"
#include "vertex.h"


class Stairs : public CameraMovementObserver {
private:
  
    double posX, posY, posZ, horizontal, vertical, height, yRotated, yRotatedRadians;
    int steps, texture;
    double stepHeight, stepDepth;

public:
    
    void setTexture(int texture);
    void setSteps(int steps);
    void setStepHeight(double stepHeight);
    void setStepDepth(double stepDepth);
    void draw();
    void notify(double& posX, double& posY, double& posZ);

    Stairs();
    Stairs(double posX, double posY, double posZ
        , double horizontal, double vertical, double height, double yRotated);

};

#endif 