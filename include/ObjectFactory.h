#ifndef OBJECT_FACTORY_H
#define OBJECT_FACTORY_H

#include "Cube.h"
#include "MainBuilding.h"
#include "Model.h"
#include "Object.h"
#include "Resources.h"

enum objectType
{
	MAIN_BUILDING1,
	MAIN_BUILDING2,
	BUILDING1,
	BUILDING2,
	BUILDING3,
	PAVEMENT,
	STREET,
	BOX,
	TREE,
	CAR1,
	//CAR2,
	LAMP_POST
};

class ObjectFactory {
public:

	int building1, building2, building3, pavement, sidePavement, box, asphalt;
	Model_3DS tree, car1, car2, lampPost;

	int in_building_texture1, in_building_texture2, in_building_texture3, out_building_texture1, out_building_texture3, glass_window_texture;
	int out_building_texture_1, out_building_texture_2, out_building_texture_3, glass_window_texture2;
	int elevatorWall, elevatorFloor, buttonTexture, transparent, grass;
	int skyUp, skyDown, skyFront, skyBack, skyLeft, skyRight;

	ObjectFactory();
	Object* createObject(objectType type, vertex center, double width = 10, double height = 10, double length = 10, double scale = 1, double yRotated = 0);
};

#endif
