#ifndef POINT_H
#define POINT_H

#include <windows.h>
#include <gl.h>
#include <vector>
#include "Cube.h"
#include "texture.h"

struct point { double x, y, z; };

struct rectangle { point p; double  xAxis, yAxis, zAxis; };

Cube draw_quad(std::vector<point> v, std::vector<double> texcoor, int out_texture, int in_texture, bool is_rebeated, bool is_blended, bool blocked);

#endif 