#ifndef MAINBUILDING2_H_INCLUDED
#define MAINBUILDING2_H_INCLUDED

#include "Storey.h"

class MainBuilding2 {

private: point start;
		 double xAxis, yAxis, zAxis;
		 int storey_number;
		 int rooms_number;
		 std::vector<Storey> storeys;
		 std::vector<int> in_textures;
		 std::vector<int> out_textures;
		 int window_texture;
		 bool zombie_mode;
		 Elevator elevator;
public:
	MainBuilding2() {};
	MainBuilding2(point start, double xAxis, double yAxis, double zAxis, int storey_number, int rooms_number, std::vector<int> in_textures, std::vector<int> out_textures, int window_texture, bool zombie_mode){};
    	void draw() {};



}



#endif // MAINBUILDING2_H_INCLUDED
