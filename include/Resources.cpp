#include "Resources.h"

int in_building_texture1,in_building_texture2,in_building_texture3,out_building_texture1,out_building_texture3 ,glass_window_texture;
//TGAImage grass;
int out_building_texture_1, out_building_texture_2, out_building_texture_3, glass_window_texture2;
int elevatorWall, elevatorFloor, buttonTexture, transparent, grass;
int skyUp, skyDown, skyFront, skyBack, skyLeft, skyRight;

void loadTextures() {
	//glEnable(GL_TEXTURE_2D);
	in_building_texture1 = LoadTexture("data\\in_building_texture1.bmp", 255);
	in_building_texture2 = LoadTexture("data\\in_building_texture2.bmp", 255);
	in_building_texture3 = LoadTexture("data\\in_building_texture3.bmp", 255);
	out_building_texture_1 = LoadTexture("data\\out_building_texture1.bmp", 255);
	out_building_texture_2 = LoadTexture("data\\out_building_texture2.bmp", 255);
	out_building_texture_3 = LoadTexture("data\\out_building_texture3.bmp", 255);
	glass_window_texture2=LoadTexture("data\\glass_window_texture.bmp", 55);
	grass = LoadTexture("data/grass.bmp");
	buttonTexture = LoadTexture("data/elevatorButton.bmp");
	elevatorFloor = LoadTexture("data/elevatorFloor.bmp");
	elevatorWall = LoadTexture("data/elevatorWall.bmp");
	transparent = LoadTexture("data/elevatorButton.bmp", 0);

	skyUp = LoadTexture("data/up.bmp");
	skyDown = LoadTexture("data/down.bmp");
	skyLeft = LoadTexture("data/left.bmp");
	skyRight = LoadTexture("data/right.bmp");
	skyFront = LoadTexture("data/front.bmp");
	skyBack = LoadTexture("data/back.bmp");
}