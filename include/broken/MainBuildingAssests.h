#ifndef MAINBUILDINGASSESTS_H_INCLUDED
#define MAINBUILDINGASSESTS_H_INCLUDED

#include <windows.h>
#include <gl.h>
#include <vector>
#include "Controller.h"
#include "Elevator.h"
#include <windows.h>
#include <vector>
#include "Controller.h"
#include "Elevator.h"
#include "CameraMovementObserver.h"
#include "DrawCube.h"
#include "Object.h"
#include "Cube.h"
#include "vertex.h"
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <fstream>
#include <iostream>
#include <cmath>
#include "include/texture.h"
#include "include/3DTexture.h"
#include "include/heightMap.h"
#include "include/Model_3DS.h"
#include "include/TgaLoader.h"

#include "include/3DTexture.cpp"
#include "include/Model_3DS.cpp"
#include "include/texture.cpp"

struct point { double x, y, z; };
struct rectangle { point p; double  xAxis, yAxis, zAxis; };
Cube draw_quad(std::vector<point> v, std::vector<double> texcoor, int out_texture, int in_texture, bool is_rebeated, bool is_blended) {};



class Window {

private: point p1, p2, p3, p4; int tex;
		 Cube c;

public: Window(point p1, point p2, point p3, point p4, int tex) {};
		void draw() {};
};
#endif // MAINBUILDINGASSESTS_H_INCLUDED
