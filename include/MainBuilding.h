#ifndef MAIN_BUILDING_H
#define MAIN_BUILDING_H

#include <windows.h>
#include <gl.h>
#include "Elevator.h"
#include "Point.h"
#include "Room.h"
#include "Storey.h"
#include "Window.h"

class MainBuilding2 : public Object {

private:
	point start;
	double xAxis, yAxis, zAxis;
	int storey_number;
	int rooms_number;
	std::vector<Storey> storeys;
	std::vector<int> in_textures;
	std::vector<int> out_textures;
	int window_texture;
	bool zombie_mode;
	Elevator elevator;
	rectangle lift_and_stairs_area;

public:

	MainBuilding2();
	MainBuilding2(point start, double xAxis, double yAxis, double zAxis, int storey_number, int rooms_number,
		std::vector<int> in_textures, std::vector<int> out_textures, int window_texture, bool zombie_mode);
	void draw();
};


#endif 
