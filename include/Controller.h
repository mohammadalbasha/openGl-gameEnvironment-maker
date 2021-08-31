#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <windows.h>
#include <glu.h>
#include <set>
#include <cmath>
#include "CameraLookedObserver.h"
#include "CameraMovementObserver.h"
#include "KeypressObserver.h"
#include "vertex.h"

#define pi acos(-1)

extern double relativeX, relativeY;
extern bool keys[256];

class FirstPersonCamera {

public:
    double posX, posY, posZ;
    double height;
   
    FirstPersonCamera();
    void initialize(HWND* hWnd, double posX, double posY, double posZ, double height);
    void addMovementObserver(CameraMovementObserver* obs);
    void removeMovementObserver(CameraMovementObserver* obs);
    void addLookObserver(CameraLookedObserver* obs);
    void removeLookObserver(CameraLookedObserver* obs);
    void addKeypressObserver(KeypressObserver* obs);
    void removeKeypressObserver(KeypressObserver* obs);
    void update();
    vertex getDirection();
    void keyboardEvent(RAWINPUT* raw);

private:

    HWND* hWnd;
    double dirX, dirY, dirZ;
    double angleX, angleY, sensitivityFactor, speedFactor; 
    std :: set<CameraMovementObserver*> movementObservers;
    std :: set<CameraLookedObserver*> directionObservers;
    std :: set<KeypressObserver*> keypressObservers;
    double* delta = new double[1 << 4] {
        // WASD
        /* 0000 */  2 * pi,
        /* 0001 */  -pi / 2,
        /* 0010 */  pi,
        /* 0011 */  -3 * pi / 4,
        /* 0100 */  pi / 2,
        /* 0101 */  0,
        /* 0110 */  3 * pi / 4,
        /* 0111 */  pi,
        /* 1000 */  0,
        /* 1001 */  -pi / 4,
        /* 1010 */  2 * pi,
        /* 1011 */  -pi / 2,
        /* 1100 */  pi / 4,
        /* 1101 */  0,
        /* 1110 */  pi / 2,
        /* 1111 */  2 * pi
    };

    void normalize(double& ang);
    void registerRawInputDevices();
    void centerCursor();
    void keyboard();
    void move(double ang);

};

extern FirstPersonCamera camera;
#endif