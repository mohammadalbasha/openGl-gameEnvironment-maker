#include "Elevator.h"

Elevator::Elevator() {}
 
Elevator::Elevator(double posX, double posY, double posZ, 
        double horizontal, double vertical, double height, double maxTravelDistance, double stopHeights, double yRotated) {
    this -> posX = posX;
    this -> posY = posY;
    this -> posZ = posZ;
    basePos = {posX, posY, posZ};
    this -> horizontal = horizontal;
    this -> vertical = vertical;
    this -> height = height;
    this -> maxTravelDistance = maxTravelDistance;
    this -> stopMultiples = stopHeights * 10;
    this -> yRotated = yRotated;
    this -> yRotatedRadians = yRotated * pi / 180.0;
    this -> climbed = 0;
    collisionCubes.resize(4);
    collisionCubes[0] = Cube(vertex(-1, 0, 1).rotateY(yRotatedRadians) + basePos, 1, height, vertical + 2, yRotated);            // Left
    collisionCubes[1] = Cube(vertex(horizontal, 0, 1).rotateY(yRotatedRadians) + basePos, 1, height, vertical + 2, yRotated);   // Right
    collisionCubes[2] = Cube(vertex(0, 0, -vertical).rotateY(yRotatedRadians) + basePos, horizontal, height, 1, yRotated);   // Back
    collisionCubes[3] = Cube(vertex(0, 0, +1).rotateY(yRotatedRadians) + basePos, horizontal, height, 1, yRotated);          // Front
    for(int i = 0; i < 3; i++) 
        camera.addMovementObserver(&collisionCubes[i]);
    button.initialize(this);
}

void Elevator::setTextures(int floorTexture, int wallTexture, int buttonTexture) {
    this -> floorTexture = floorTexture;
    this -> wallTexture = wallTexture;
    button.setTexture(buttonTexture);
}
        
void Elevator::draw() {
    if(button.getState()) camera.addMovementObserver(&collisionCubes[3]);
    else camera.removeMovementObserver(&collisionCubes[3]);
    glPushMatrix();

    glTranslated(posX, posY, posZ);
    glRotated(yRotated, 0, 1, 0);

    DrawCube :: draw({-0.1, 0, 0}, 0.1, height + 0.1, vertical, true, {wallTexture}, {1}, {1});  // Left side
    DrawCube :: draw({horizontal, 0, 0}, 0.1, height + 0.1, vertical, true, {wallTexture}, {1}, {1});  // Right side
    DrawCube :: draw({-0.1, 0, -vertical}, horizontal + 0.2, height + 0.1, 0.1, true, {wallTexture}, {1}, {1});  // Back side
    DrawCube :: draw({0, 0, 0}, horizontal, 0.1, vertical, true, {floorTexture}, {1}, {1});  // Floor
    DrawCube :: draw({0, height, 0}, horizontal, 0.1, vertical, true, {floorTexture}, {1}, {1});  // Roof
    button.draw();

    glPopMatrix();

    if(button.getState() == 1) {
        if(climbed < maxTravelDistance * 10) {
            posY += 0.1;
            camera.posY += 0.1;
            for(int i = 0; i < 4; i++) collisionCubes[i].center.y += 0.1;
            climbed++;
            if((climbed < maxTravelDistance * 10) && (climbed % stopMultiples == 0)) button.pause();
        }
        else button.reset();
    }
    else if(button.getState() == -1) {
        if(climbed) {
            posY -= 0.1;
            camera.posY -= 0.1;
            for(int i = 0; i < 4; i++) collisionCubes[i].center.y -= 0.1;
            climbed--;
            if((climbed > 0) && (climbed % stopMultiples == 0)) button.pause();
        }
        else button.reset();
    }
    button.initialize(this);
}
        
void Elevator::notify(double& posX, double& posY, double& posZ) {
    vertex pos = {posX - this -> posX, posY - this -> posY, posZ - this -> posZ};
    pos = pos.rotateY(-yRotatedRadians);

    if( (pos.x >= 0 && pos.x <= horizontal) && (pos.y >= 0 && pos.y <= height) && (pos.z <= 0 && pos.z >= -vertical) ) {
        camera.addLookObserver(&button);
    }

    else {
        camera.removeKeypressObserver(&button);
        camera.removeLookObserver(&button);
    }

}

void Elevator :: ElevatorButton :: initialize(Elevator* elevator) {
    this -> posX = 1;
    this -> posY = (elevator -> height / 2) - 0.25;
    this -> posZ = 1e-3;
    this -> yRotated = elevator -> yRotated + 90;
    this -> yRotatedRadians = this -> yRotated * pi / 180.0;
    this -> elevatorPos = {elevator -> posX, elevator -> posY, elevator -> posZ};
}

void Elevator :: ElevatorButton :: setTexture(int texture) {
    this -> texture = texture;
}

int Elevator :: ElevatorButton :: getState() {
    return state[i];
}

void Elevator :: ElevatorButton :: reset() {
    i = (i + 1) % 4;
}

void Elevator :: ElevatorButton :: pause() {
    i = (((i - 1) % 4) + 4) % 4;
}

void Elevator :: ElevatorButton :: draw() {
    glPushMatrix();
    glRotated(90, 0, 1, 0);

    DrawCube :: draw({this -> posX, this -> posY, this -> posZ}, 0.5, 0.5, 1e-3, true, {texture}, {1}, {1});

    glPopMatrix();
}

void Elevator :: ElevatorButton :: notify(vertex dir) {
    vertex a = vertex(posX + 0.5, posY, posZ) - vertex(posX, posY, posZ);
    vertex b = vertex(posX, posY + 0.5, posZ) - vertex(posX, posY, posZ);
    vertex n = a.cross(b);

    vertex l0 = (vertex(camera.posX, camera.posY + camera.height, camera.posZ) - elevatorPos).rotateY(-yRotatedRadians);
    dir = (vertex(camera.posX, camera.posY + camera.height, camera.posZ) + dir - elevatorPos).rotateY(-yRotatedRadians);
    dir = dir - l0;

    if(dir.dot(n) == 0.0) {
        camera.removeKeypressObserver(this);
        return;
    }
    
    vertex p0 = vertex(posX, posY, posZ);

    double d = n.dot(p0 - l0) / dir.dot(n);
    vertex intersection = l0 + dir.scale(d);

    if( (intersection.x >= p0.x && intersection.x <= p0.x + 0.5) && (intersection.y >= p0.y && intersection.y <= p0.y + 0.5) ) {
        camera.addKeypressObserver(this);
    }

    else {
        camera.removeKeypressObserver(this);
    }
}

void Elevator :: ElevatorButton :: notify(USHORT key) {
    if(key == 'E' && !state[i]) {
        i = (i + 1) % 4;
    }
}