#include "vertex.h"

vertex::vertex() {}
    
vertex::vertex(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

vertex::vertex(vertex* obj) {
    this -> x = obj -> x;
    this -> y = obj -> y;
    this -> z = obj -> z;
}

vertex vertex::rotateY(double ang) {
    ang += atan2(-z, x);
    double d = hypot(x, z);

    return { d * cos(ang), y, d * -sin(ang) };
}

vertex vertex::operator -(vertex right) {
    return { x - right.x, y - right.y, z - right.z };
}

vertex vertex::operator +(vertex right) {
    return { x + right.x, y + right.y, z + right.z };
}

vertex vertex::scale(double d) {
    return { x * d, y * d, z * d };
}

vertex vertex::cross(vertex other) {
    return { y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x };
}
    
double vertex::dot(vertex other) {
    return other.x * x + other.y * y + other.z * z;
}


    

    
