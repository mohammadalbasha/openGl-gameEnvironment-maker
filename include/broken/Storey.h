#ifndef STOREY_H_INCLUDED
#define STOREY_H_INCLUDED
#include "Room.h"




class Storey {

private:	point start;
			double xAxis, yAxis, zAxis;
			int storey_index;
			int rooms_number;
			std::vector<Room> rooms;
			std::vector<Window> windows;
			std::vector<int> in_textures;
			std::vector<int> out_textures;
			int window_texture;
			rectangle lift_and_stairs_area;
			int in_texture;
			int out_texture;
			Stairs s;
			std::vector<Cube> cu;
public:

	Storey(point start, double xAxis, double yAxis, double zAxis, int storey_index, int rooms_number, std::vector<int> in_textures, std::vector<int> out_textures, int window_texture){};
	rectangle getLiftAndStairsArea() {};
		void draw() {};


};
#endif // STOREY_H_INCLUDED
