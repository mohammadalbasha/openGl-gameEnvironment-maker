#include "Controller.h"

double relativeX = 0, relativeY = 0;
bool keys[256];
FirstPersonCamera camera;

FirstPersonCamera::FirstPersonCamera() {}

void FirstPersonCamera::initialize(HWND* hWnd, double posX, double posY, double posZ, double height) {
    this -> posX = posX;
    this -> posY = posY;
    this -> posZ = posZ;
    this -> hWnd = hWnd;
    this -> height = height;
    angleX = angleY = dirX = dirY = dirZ = 0;
    sensitivityFactor = 0.01;
    speedFactor = 0.1;
    registerRawInputDevices();
}

void FirstPersonCamera::addMovementObserver(CameraMovementObserver* obs) {
    movementObservers.insert(obs);
}

void FirstPersonCamera::removeMovementObserver(CameraMovementObserver* obs) {
    movementObservers.erase(obs);
}

void FirstPersonCamera::addLookObserver(CameraLookedObserver* obs) {
    directionObservers.insert(obs);
}

void FirstPersonCamera::removeLookObserver(CameraLookedObserver* obs) {
    directionObservers.erase(obs);
}

void FirstPersonCamera::addKeypressObserver(KeypressObserver* obs) {
    keypressObservers.insert(obs);
}
 
void FirstPersonCamera::removeKeypressObserver(KeypressObserver* obs) {
    keypressObservers.erase(obs);
}

void FirstPersonCamera::update() {
    gluLookAt(posX, posY + height, posZ,
        posX + dirX, height + posY + dirY, posZ + dirZ,
            0, 1, 0);

    angleX -= sensitivityFactor * relativeX;
    angleY -= sensitivityFactor * relativeY;

    normalize(angleX);
    normalize(angleY);

    angleY = min(angleY, (pi / 2) - 0.001);
    angleY = max(angleY, -(pi / 2) + 0.001);

    dirX = cos(angleX) * cos(angleY);
    dirY = sin(angleY);
    dirZ = -sin(angleX) * cos(angleY);

    if(relativeX || relativeY) {
        relativeX = relativeY = 0;
        centerCursor();
        for(auto observer : directionObservers)
            observer -> notify(getDirection());
    }

    keyboard();
}

vertex FirstPersonCamera::getDirection() {
    return {dirX, dirY, dirZ};
}

void FirstPersonCamera::keyboardEvent(RAWINPUT* raw) {
    if((raw->data.keyboard.Flags & RI_KEY_MAKE) == RI_KEY_MAKE) {
        if(!keys[raw->data.keyboard.VKey])
            for(auto observer : keypressObservers)
                observer -> notify(raw->data.keyboard.VKey);

        keys[raw->data.keyboard.VKey] = true;
    }
    if((raw->data.keyboard.Flags & RI_KEY_BREAK) == RI_KEY_BREAK) keys[raw->data.keyboard.VKey] = false;

}

void FirstPersonCamera::normalize(double& ang) {
    if (ang < 0) ang += floor(-ang / (2 * pi)) * 2 * pi;
    else ang -= floor(ang / (2 * pi)) * 2 * pi;
}

void FirstPersonCamera::registerRawInputDevices() {
    PRAWINPUTDEVICE Rid;
    Rid = (PRAWINPUTDEVICE)malloc(2 * sizeof(RAWINPUTDEVICE));
    Rid[0].usUsagePage = 0x01;
    Rid[0].usUsage = 0x02;
    Rid[0].dwFlags = RIDEV_NOLEGACY;   // adds HID mouse and also ignores legacy mouse messages
    Rid[0].hwndTarget = 0;

    Rid[1].usUsagePage = 0x01;
    Rid[1].usUsage = 0x06;
    Rid[1].dwFlags = RIDEV_NOLEGACY;   // adds HID keyboard and also ignores legacy keyboard messages
    Rid[1].hwndTarget = 0;
    RegisterRawInputDevices(Rid, 2, sizeof(Rid[0]));
}
       
void FirstPersonCamera::centerCursor() {
    RECT window;
    GetWindowRect(*hWnd, &window);
    POINT mouseCoords = { (window.left + window.right) / 2, (window.top + window.bottom) / 2 };

    SetCursorPos(mouseCoords.x, mouseCoords.y);
}
 
void FirstPersonCamera::keyboard() {
    if (keys[VK_SHIFT]) speedFactor *= 10; // sprint

    double ang = delta[(keys['W'] << 3) | (keys['A'] << 2) | (keys['S'] << 1) | keys['D']];
    if (ang != 2 * pi) move(ang);

    if (keys[VK_SHIFT]) speedFactor /= 10;

    if (keys[VK_ESCAPE]) exit(0);
}

void FirstPersonCamera::move(double ang) {
    double newX = posX + speedFactor * cos(angleX + ang);
    double newY = posY;
    double newZ = posZ + speedFactor * -sin(angleX + ang);

    for (auto observer : movementObservers)
        observer->notify(newX, newY, newZ);

    posX = newX, posY = newY, posZ = newZ;
}
