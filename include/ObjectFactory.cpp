#include "ObjectFactory.h"
#include <vector>

ObjectFactory::ObjectFactory() {
	//BUILDING1
	building1 = LoadTexture("data\\building1.bmp");

	//BUILDING2
	building2 = LoadTexture("data\\building2.bmp");

	//BUILDING3
	building3 = LoadTexture("data\\building3.bmp");

	//PAVEMENT
	pavement = LoadTexture("data\\pavement.bmp");

	//SIDEPAVEMENT
	sidePavement = LoadTexture("data\\sidePavement.bmp");

	//BOX 
	box = LoadTexture("data\\box.bmp");

	//ASPHALT
	asphalt = LoadTexture("data/asphalt.bmp");

	//TREE 
	GLTexture bark, leaves;
	bark.LoadBMP("data\\bark.bmp");
	leaves.LoadBMP("data\\leaves.bmp");
	tree = Model_3DS();
	tree.Load("data\\tree.3DS");
	tree.Materials[0].tex = bark;
	tree.Materials[1].tex = leaves;

	//CAR1
	GLTexture car1Textures;
	car1Textures.LoadBMP("data\\car1.bmp");
	car1 = Model_3DS();
	car1.Load("data\\car1.3DS");
	car1.Materials[0].tex = car1Textures;

	//CAR2
	/*car2 = Model_3DS();
	car2.Load("data\\Car 2013 McLaren P1 Forza Horizon N260419.3DS");*/

	//LAMP POST
	GLTexture lampMetal, lampBulb;
	lampMetal.LoadBMP("data\\lamp-post-metal.bmp");
	lampBulb.LoadBMP("data\\lamp-post-bulb.bmp");
	lampPost = Model_3DS();
	lampPost.Load("data\\lamp-post.3DS");
	lampPost.Materials[0].tex = lampMetal;
	lampPost.Materials[1].tex = lampBulb;
}

Object* ObjectFactory::createObject(objectType type, vertex center, double width, double height, double length, double scale, double yRotated) {

	Object* object = NULL;

	switch (type) {
	case MAIN_BUILDING1: {
		object = new MainBuilding2({center.x, center.y, center.z}, width, height / 4, length, 4, 4, { in_building_texture1,in_building_texture2 ,in_building_texture3 }, { out_building_texture1,out_building_texture_2,out_building_texture3 }, glass_window_texture, 0);
		break;
	}


	case MAIN_BUILDING2: {
		object = new MainBuilding2({ 0.0,0,100.0 }, 100.0, 10, 70.0, 2, 4, { in_building_texture1,in_building_texture2 ,in_building_texture3 }, { out_building_texture1,out_building_texture_2,out_building_texture3 }, glass_window_texture, 1);
		break;
	}

	case BUILDING1: {
		// width = 70;
		// height = 100;
		// length = 40;
		object = new Cube(center, width, height, length, yRotated);
		((Cube*)object)->setTextures({ building1, building1, building1, building1, building1, building1 }, 
			{(int) (width / 10),(int) (width / 10),(int) (length / 10),(int) (length / 10), 1, 1 }, {(int) (height / 10),(int) (height / 10),(int) (height / 10),(int) (height / 10), 1, 1 });
		camera.addMovementObserver(((Cube*)object));
		break; 
	}

	case BUILDING2: {
		width = 70;
		height = 100;
		length = 40;
		object = new Cube(center, width, height, length, yRotated);
		((Cube*)object)->setTextures({ building2, building2, building2, building2, building2, building2 }, 
			{(int) (width / 20),(int) (width / 20),(int) (length / 20),(int) (length / 20), 1, 1 }, 
			{(int) (height / 20),(int) (height / 20),(int) (height / 20),(int) (height / 20), 1, 1 });
		camera.addMovementObserver(((Cube*)object));
		break;
	}
		
	case BUILDING3: {
		width = 70;
		height = 100;
		length = 40;
		object = new Cube(center, width, height, length, yRotated);
		((Cube*)object)->setTextures({ building3, building3, building3, building3, building3, building3 }, 
			{(int) (width / 20),(int) (width / 20),(int) (length / 20),(int) (length / 20), 1, 1 }, 
			{(int) (height / 20),(int) (height / 20),(int) (height / 20),(int) (height / 20), 1, 1 });
		camera.addMovementObserver(((Cube*)object));
		break;
	}

	case PAVEMENT: {
		object = new Cube(center, width, height, length, yRotated);
		((Cube*)object)->setTextures({ sidePavement, sidePavement, sidePavement, sidePavement, pavement, sidePavement }, 
			{(int) (width / 50),(int) (width / 50),(int) (length / 50),(int) (length / 50),(int) (width / 10), 1 }, 
			{ 1, 1, 1, 1,(int) (length / 10), 1});
		break;
	}

	case STREET:
		object = new Cube(center, width, height, length, yRotated);
		((Cube*)object)->setTextures({asphalt}, {10}, {1});
		break;

	case BOX: {
		width = height = length = 3;
		int textures[6] = { box, box, box, box, box, box };
		int repeation[6] = { 1, 1, 1, 1, 1, 1 };
		object = new Cube(center, width, height, length, yRotated);
		((Cube*)object)->setTextures({ box, box, box, box, box, box }, 
			{ 1, 1, 1, 1, 1, 1}, 
			{ 1, 1, 1, 1, 1, 1});
		break;
	}

	case TREE: {
		scale = 1;
		object = new Model(&tree, center, scale, { center.x - 1, 0, center.z + 1 }, 2, 40, 2, building1);
		break; 
	}

	case CAR1: {
		scale = 0.1;
		center.y = 2;
		object = new Model(&car1, center, scale, { center.x - 2.7, 0, center.z + 6.5 }, 5.4, 5, 13, building1, 1, { 1.6, -0.1, 5.8 }, yRotated);
		break;
	}

	/*case CAR2: {
		scale = 0.05;
		center.y = 3;
		object = new Model(&car2, center, scale, { center.x - 1.5, 0, center.z + 3.25 }, 3, 5, 6.5, building1);
		break;
	}*/

	case LAMP_POST: {
		scale = 0.005;
		center.y = 20;
		object = new Model(&lampPost, center, scale, { center.x + 0.3, 0, center.z + 0.6 }, 1.3, 40, 1.2, building1, 3, { -4, 9, 0 }, yRotated);
		break;
	}
	}

	return object;
}
