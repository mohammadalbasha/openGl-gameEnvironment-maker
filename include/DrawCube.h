#ifndef DRAW_CUBE_H
#define DRAW_CUBE_H

#include <windows.h>
#include <gl.h>
#include <cmath>
#include <vector>
#include "texture.h"
#include "vertex.h"

class DrawCube {
private:
    static void drawQuad(vertex bottomLeft, vertex bottomRight, vertex topRight, vertex topLeft,
        bool textured, int tex = 0, int hRepeation = 0, int vRepeation = 0);

public:
    static void draw(vertex pos, double width, double height, double length,
        bool textured, std :: vector<int> tex = {}, std :: vector<int> hRepeation = {}, std :: vector<int> vRepeation = {});
};

#endif 
