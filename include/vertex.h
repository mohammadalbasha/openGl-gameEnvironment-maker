#ifndef VERTEX_H
#define VERTEX_H

#include <cmath>

class vertex {
public:
    double x, y, z;

    vertex();
    vertex(double x, double y, double z);
    vertex(vertex *obj);
    vertex rotateY(double ang);
    vertex operator -(vertex right);
    vertex operator +(vertex right);
    vertex scale(double d);
    vertex cross(vertex other);
    double dot(vertex other);
};

#endif