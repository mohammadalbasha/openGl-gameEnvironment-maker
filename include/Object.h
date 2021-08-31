#ifndef OBJECT_H
#define OBJECT_H

#include "vertex.h"

class Object {
public:
	virtual void draw() = 0;
	Object();
	Object(vertex center);
	vertex center;
};

#endif