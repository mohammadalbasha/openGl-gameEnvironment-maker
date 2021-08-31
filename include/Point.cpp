#ifndef POINT_H
#define POINT_H

#include "Point.h"
#include <windows.h>
#include <gl.h>
#include <vector>
#include "Cube.h"
#include "texture.h"

struct point { double x, y, z; };

struct rectangle { point p; double  xAxis, yAxis, zAxis; };

Cube draw_quad(std::vector<point> v, std::vector<double> texcoor, int out_texture, int in_texture, bool is_rebeated, bool is_blended, bool blocked) {
	Cube c;
	if (blocked) {
		if (v[0].x == v[1].x) {
			c = Cube({ v[1].x,v[1].y,v[1].z }, 1, v[2].y - v[1].y, v[1].z - v[0].z, 0);




		}
		else 	c = Cube({ v[0].x,v[0].y,v[0].z }, v[1].x - v[0].x, v[2].y - v[1].y, 1, 0);
	}
	glEnable(GL_TEXTURE_2D);
	if (is_blended)
		glEnable(GL_BLEND);
	glEnable(GL_CULL_FACE);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


	glCullFace(GL_BACK);
	glBindTexture(GL_TEXTURE_2D, in_texture);


	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(v[0].x, v[0].y, v[0].z);
	glTexCoord2d(texcoor[0], 0);
	glVertex3f(v[1].x, v[1].y, v[1].z);
	glTexCoord2d(texcoor[0], texcoor[1]);
	glVertex3f(v[2].x, v[2].y, v[2].z);
	glTexCoord2d(0, texcoor[1]);
	glVertex3f(v[3].x, v[3].y, v[3].z);

	glEnd();



	glFrontFace(GL_CW);
	glCullFace(GL_FRONT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, out_texture);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(v[0].x, v[0].y, v[0].z);
	glTexCoord2d(texcoor[0], 0);
	glVertex3f(v[1].x, v[1].y, v[1].z);
	glTexCoord2d(texcoor[0], texcoor[1]);
	glVertex3f(v[2].x, v[2].y, v[2].z);
	glTexCoord2d(0, texcoor[1]);
	glVertex3f(v[3].x, v[3].y, v[3].z);

	glEnd();

	//glDisable(GL_TEXTURE2D); //***DELETE IT"""
	glDisable(GL_CULL_FACE);
	glDisable(GL_BLEND);
	return c;
}

#endif 