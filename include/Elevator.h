#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <windows.h>
#include <gl.h>
#include <vector>
#include "CameraLookedObserver.h"
#include "CameraMovementObserver.h"
#include "Cube.h"
#include "Controller.h"
#include "DrawCube.h"
#include "KeypressObserver.h"
#include "vertex.h"

class Elevator : public CameraMovementObserver {

private:

    double posX, posY, posZ;
    vertex basePos;
    double horizontal, height, vertical, maxTravelDistance;
    double yRotated, yRotatedRadians;
    int floorTexture, wallTexture, climbed, stopMultiples;
    std :: vector<Cube> collisionCubes;

public:

    class ElevatorButton : public CameraLookedObserver, public KeypressObserver {
    private:
        double posX, posY, posZ, yRotated, yRotatedRadians;
        int texture;
        vertex elevatorPos;

    public:
        std::vector<int> state = { 0, 1, 0, -1 };
        int i = 0;
        void initialize(Elevator* elevator);

        void setTexture(int texture);

        int getState();

        void reset();

        void pause();

        void draw();

        void notify(vertex dir);

        void notify(USHORT key);

    } button;

    Elevator();
    Elevator(double posX, double posY, double posZ, 
                double horizontal, double vertical, double height, double maxTravelDistance, double stopHeights, double yRotated);
    void setTextures(int floorTexture, int wallTexture, int buttonTexture);
    void draw();
    void notify(double& posX, double& posY, double& posZ);
};

#endif