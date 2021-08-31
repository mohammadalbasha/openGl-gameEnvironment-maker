#ifndef STOREY_H
#define STOREY_H

#include <windows.h>
#include <gl.h>
#include <time.h>     
#include <vector>
#include "Point.h"
#include "Room.h"
#include "Stairs.h"
#include "Window.h"
#include "Resources.h"

class Storey {

private:	
	point start;
	double xAxis, yAxis, zAxis;
	int storey_index;
	int rooms_number;
	std::vector<Room> rooms;
	std::vector<Window> windows;
	std::vector<int> in_textures;
	std::vector<int> out_textures;
	int window_texture;
	rectangle lift_and_stairs_area;
	rectangle elevator_area;
	int in_texture;
	int out_texture;
	Stairs s;
	std::vector<Cube> cu;
	bool last_storey;

public:

	int i = 0;

	rectangle getLiftAndStairsArea();
	rectangle getElevatorArea();
	void draw();
	Storey();
	Storey(point start, double xAxis, double yAxis, double zAxis, int storey_index, int rooms_number,
		std::vector<int> in_textures, std::vector<int> out_textures, int window_texture, bool last_storey);
};

#endif 
