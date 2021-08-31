#ifndef RESOURCES_H
#define RESOURCES_H

#include "texture.h"

extern int in_building_texture1,in_building_texture2,in_building_texture3,out_building_texture1,out_building_texture3 ,glass_window_texture;
//TGAImage grass;
extern int out_building_texture_1, out_building_texture_2, out_building_texture_3, glass_window_texture2;
extern int elevatorWall, elevatorFloor, buttonTexture, transparent, grass;
extern int skyUp, skyDown, skyFront, skyBack, skyLeft, skyRight;

void loadTextures();

#endif