#include "Window.h"

Window::Window(point p1, point p2, point p3, point p4, int tex) {
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->p4 = p4;
	this->tex = tex;
}

void Window::draw() {


	c = draw_quad({ p1,p2,p3,p4 }, { 1,1 }, tex, tex, 0, 1, 1);
	if (!i)
		camera.addMovementObserver(&c);

	i++;
	i = min(i, 1);
}