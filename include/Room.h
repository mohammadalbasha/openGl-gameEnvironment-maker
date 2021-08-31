#ifndef ROOM_H
#define ROOM_H

#include <windows.h>
#include <gl.h>
#include <vector>
#include "Cube.h"
#include "Point.h"
#include "Window.h"

class Room {

private: 
	point start;
	double xAxis, yAxis, zAxis;
	std::vector<bool> door;
	std::vector<Cube> cu;
	bool last_room;
	int out_texture, in_texture;

public:
	int i = 0;
	Cube c;

	Room();
	Room(point start, double xAxis, double yAxis, double zAxis, bool last_room, std::vector<bool> door, int in_texture, int out_texture);
	void draw();
};

#endif 
