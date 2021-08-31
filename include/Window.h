#ifndef WINDOW_H
#define WINDOW_H

#include "Cube.h"
#include "Point.h"

class Window {

private: 
	point p1, p2, p3, p4; int tex;
	Cube c;

public: 

	int i = 0;
	Window(point p1, point p2, point p3, point p4, int tex);
	void draw();
};

#endif
