#ifndef CAMERA_MOVEMENT_OBSERVER_H
#define CAMERA_MOVEMENT_OBSERVER_H

class CameraMovementObserver {
public:
    virtual void notify(double& posX, double& posY, double& posZ) = 0;
};

#endif