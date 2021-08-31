
#include "MainBuildingAssests.h"



struct point { double x, y, z; };
struct rectangle { point p; double  xAxis, yAxis, zAxis; };
Cube draw_quad(std::vector<point> v, std::vector<double> texcoor, int out_texture, int in_texture, bool is_rebeated, bool is_blended) {
	Cube c;

	if (v[0].x == v[1].x) {
		c = Cube({ v[1].x,v[1].y,v[1].z }, 1, v[2].y - v[1].y, v[1].z - v[0].z,  0);




	}
	else 	c = Cube({ v[0].x,v[0].y,v[0].z }, v[1].x - v[0].x, v[2].y - v[1].y, 1,  0);

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
















class Window {

private: point p1, p2, p3, p4; int tex;
		 Cube c;

public: Window(point p1, point p2, point p3, point p4, int tex) {
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->p4 = p4;
	this->tex = tex;
}
		int i = 0;
		void draw() {


			c = draw_quad({ p1,p2,p3,p4 }, { 1,1 }, tex, tex, 0, 1);
			if (!i)
				camera.addMovementObserver(&c);

			i++;
			i = min(i, 1);
		}



};
