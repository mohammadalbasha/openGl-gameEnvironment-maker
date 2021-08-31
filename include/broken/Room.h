#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED
#include "MainBuildingAssests.h"



class Room {

private: point start;
		 double xAxis, yAxis, zAxis;
		 std::vector<bool> door;
		 std::vector<Cube> cu;

		 bool last_room;
		 int out_texture, in_texture;

public:

	Room() {};
	Room(point start, double xAxis, double yAxis, double zAxis, bool last_room, std::vector<bool> door, int in_texture, int out_texture){};

	int i = 0;
	Cube c;
	void draw() ;
};
#endif // ROOM_H_INCLUDED
