#include "Room.h"

Room::Room() {}

Room::Room(point start, double xAxis, double yAxis, double zAxis, bool last_room, std::vector<bool> door, int in_texture, int out_texture) {

	this->start = start;
	this->xAxis = xAxis;
	this->yAxis = yAxis;
	this->zAxis = zAxis;
	this->door = door;
	this->last_room = last_room;
	this->out_texture = out_texture;
	this->in_texture = in_texture;
}

void Room::draw() {

	glEnable(GL_TEXTURE_2D);
	// front 

	if (door[0]) {
		double dr = xAxis / 3;
		c = draw_quad({ { start.x, start.y, start.z },{ start.x + dr, start.y, start.z },{ start.x + dr, start.y + yAxis, start.z },{ start.x, start.y + yAxis, start.z } }, { dr,yAxis }, out_texture, in_texture, 1, 0, 1);
		if (!i)
			cu.push_back(c);

		c = draw_quad({ { start.x + 2 * dr, start.y, start.z },{ start.x + xAxis, start.y, start.z },{ start.x + xAxis, start.y + yAxis, start.z } ,{ start.x + 2 * dr, start.y + yAxis, start.z } }, { dr,yAxis }, out_texture, in_texture, 1, 0, 1);
		if (!i)
			cu.push_back(c);
		c = draw_quad({ { start.x, start.y + 2 * yAxis / 3, start.z },{ start.x + xAxis, start.y + 2 * yAxis / 3, start.z } ,{ start.x + xAxis, start.y + yAxis , start.z },{ start.x, start.y + yAxis , start.z } }, { xAxis,yAxis / 3 }, out_texture, in_texture, 1, 0, 1);
		if (!i)
			cu.push_back(c);
	}
	else {

		c = draw_quad({ { start.x, start.y, start.z },{ start.x + xAxis, start.y, start.z },{ start.x + xAxis, start.y + yAxis, start.z },{ start.x, start.y + yAxis, start.z } }, { xAxis,yAxis }, out_texture, in_texture, 1, 0, 1);
		if (!i)
			cu.push_back(c);
	}


	// back
	if (door[1]) {

		double dr = xAxis / 3;


		c = draw_quad({ { start.x, start.y, start.z - zAxis },{ start.x + dr, start.y, start.z - zAxis },{ start.x + dr, start.y + yAxis, start.z - zAxis },{ start.x, start.y + yAxis, start.z - zAxis } }, { dr,yAxis }, in_texture, out_texture, 1, 0, 1);
		if (!i)
			cu.push_back(c);
		c = draw_quad({ { start.x + 2 * dr, start.y, start.z - zAxis } ,{ start.x + xAxis, start.y, start.z - zAxis } ,{ start.x + xAxis, start.y + yAxis, start.z - zAxis },{ start.x + 2 * dr, start.y + yAxis, start.z - zAxis } }, { dr,yAxis }, in_texture, out_texture, 1, 0, 1);
		if (!i)
			cu.push_back(c);
		c = draw_quad({ { start.x, start.y + 2 * yAxis / 3, start.z - zAxis },{ start.x + xAxis, start.y + 2 * yAxis / 3, start.z - zAxis },{ start.x + xAxis, start.y + yAxis, start.z - zAxis },{ start.x, start.y + yAxis, start.z - zAxis } }, { xAxis,yAxis / 3 }, in_texture, out_texture, 1, 0, 1);
		if (!i)
			cu.push_back(c);
	}
	else {

		c = draw_quad({ { start.x, start.y, start.z - zAxis },{ start.x + xAxis, start.y, start.z - zAxis },{ start.x + xAxis, start.y + yAxis, start.z - zAxis },{ start.x, start.y + yAxis, start.z - zAxis } }, { xAxis,yAxis }, in_texture, out_texture, 1, 0, 1);
		if (!i)
			cu.push_back(c);

	}

	// left
	if (door[2]) {

		double dr = zAxis / 3;

		c = draw_quad({ { start.x, start.y, start.z - zAxis },{ start.x, start.y, start.z - zAxis + dr },{ start.x, start.y + yAxis, start.z - zAxis + dr },{ start.x, start.y + yAxis, start.z - zAxis } }, { dr,yAxis }, out_texture, in_texture, 1, 0, 1);
		if (!i)
			cu.push_back(c);
		c = draw_quad({ { start.x, start.y, start.z - dr },{ start.x, start.y, start.z },{ start.x , start.y + yAxis, start.z } ,{ start.x , start.y + yAxis, start.z - dr } }, { dr,yAxis }, out_texture, in_texture, 1, 0, 1);
		if (!i)
			cu.push_back(c);
		c = draw_quad({ { start.x, start.y + 2 * yAxis / 3, start.z - zAxis },{ start.x, start.y + 2 * yAxis / 3, start.z } ,{ start.x, start.y + yAxis, start.z } ,{ start.x, start.y + yAxis, start.z - zAxis } }, { zAxis,yAxis / 3 }, out_texture, in_texture, 1, 0, 1);
		if (!i)
			cu.push_back(c);
	}
	else {
		c = draw_quad({ { start.x, start.y, start.z - zAxis },{ start.x, start.y, start.z } ,{ start.x, start.y + yAxis, start.z } ,{ start.x, start.y + yAxis, start.z - zAxis } }, { zAxis,yAxis }, out_texture, in_texture, 1, 0, 1);
	}if (!i)
		cu.push_back(c);



	// right
	if (door[3]) {

		double dr = zAxis / 3;

		c = draw_quad({ { start.x + xAxis, start.y, start.z - zAxis },{ start.x + xAxis, start.y, start.z - zAxis + dr },{ start.x + xAxis, start.y + yAxis, start.z - zAxis + dr },{ start.x + xAxis, start.y + yAxis, start.z - zAxis } }, { dr,yAxis }, in_texture, out_texture, 1, 0, 1);

		if (!i)
			cu.push_back(c);
		c = draw_quad({ { start.x + xAxis, start.y, start.z - dr },{ start.x + xAxis, start.y, start.z } ,{ start.x + xAxis, start.y + yAxis, start.z },{ start.x + xAxis, start.y + yAxis, start.z - dr } }, { dr,yAxis }, in_texture, out_texture, 1, 0, 1);
		if (!i)
			cu.push_back(c);
		c = draw_quad({ { start.x + xAxis, start.y + 2 * yAxis / 3, start.z - zAxis } ,{ start.x + xAxis, start.y + 2 * yAxis / 3, start.z },{ start.x + xAxis, start.y + yAxis, start.z },{ start.x + xAxis, start.y + yAxis, start.z - zAxis } }, { zAxis,yAxis / 3 }, in_texture, out_texture, 1, 0, 1);
		if (!i)
			cu.push_back(c);


	}
	else {

		c = draw_quad({ { start.x + xAxis, start.y, start.z - zAxis },{ start.x + xAxis, start.y, start.z },{ start.x + xAxis, start.y + yAxis, start.z },{ start.x + xAxis, start.y + yAxis, start.z - zAxis } }, { zAxis,yAxis }, in_texture, out_texture, 1, 0, 1);
		if (!i)
			cu.push_back(c);
	}

	// bottom
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1, 1, 1, 0.6);
	draw_quad({ { start.x , start.y, start.z } ,{ start.x + xAxis, start.y, start.z } ,{ start.x + xAxis, start.y , start.z - zAxis } ,{ start.x , start.y , start.z - zAxis } }, { zAxis,yAxis }, in_texture, out_texture, 1, 0, 1);
	glColor4f(1, 1, 1, 1);
	glDisable(GL_BLEND);

	// up

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0, 0, 0, 0.3);
	draw_quad({ { start.x, start.y + yAxis, start.z },{ start.x + xAxis, start.y + yAxis, start.z },{ start.x + xAxis, start.y + yAxis, start.z - zAxis } ,{ start.x , start.y + yAxis, start.z - zAxis } }, { zAxis,yAxis }, out_texture, in_texture, 1, 0, 1);
	glColor4f(1, 1, 1, 1);
	glDisable(GL_BLEND);

	if (!i) {
		for (int j = 0; j < cu.size(); j++)
			camera.addMovementObserver(&cu[j]);

	}i++;
	i = min(i, 1);


}