#include "MainBuilding.h"


MainBuilding2::MainBuilding2() {}

MainBuilding2::MainBuilding2(point start, double xAxis, double yAxis, double zAxis, int storey_number, int rooms_number,
	std::vector<int> in_textures, std::vector<int> out_textures, int window_texture, bool zombie_mode) {

	this->start = start;
	this->xAxis = xAxis;
	this->yAxis = yAxis;
	this->zAxis = zAxis;
	this->storey_number = storey_number;
	this->rooms_number = rooms_number;
	this->in_textures = in_textures;
	this->out_textures = out_textures;
	this->window_texture = window_texture;
	this->zombie_mode = zombie_mode;
	for (int i = 0; i < storey_number; i++) {
		Storey s = Storey({ start.x,i * yAxis + start.y ,start.z }, xAxis, yAxis, zAxis, i, rooms_number, in_textures, out_textures, window_texture, i == storey_number - 1);
		storeys.push_back(s);



	}
	lift_and_stairs_area = storeys[0].getLiftAndStairsArea();
	rectangle r = storeys[0].getElevatorArea();

	if (xAxis > zAxis)	elevator = Elevator(r.p.x, r.p.y, r.p.z, r.xAxis, r.zAxis, yAxis / 2, yAxis * storey_number, yAxis, 0);

	else	elevator = Elevator(r.p.x, r.p.y, r.p.z, r.xAxis, r.zAxis, yAxis / 2, yAxis * storey_number, yAxis, 0);

	//	camera.addMovementObserver(&ele)
	elevator.setTextures(elevatorFloor, elevatorWall, buttonTexture);

}

void MainBuilding2::draw() {
	camera.addMovementObserver(&elevator);
	draw_quad({ { lift_and_stairs_area.p.x, yAxis * storey_number + storey_number * 0.1,lift_and_stairs_area.p.z },{ lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis, yAxis * storey_number + storey_number * 0.1,lift_and_stairs_area.p.z },{ lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis, yAxis * storey_number + storey_number * 0.1,lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis},{ lift_and_stairs_area.p.x, yAxis * storey_number + storey_number * 0.1,lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis } }, { lift_and_stairs_area.xAxis,lift_and_stairs_area.zAxis }, { glass_window_texture2 }, { glass_window_texture2 }, 1, 1, 1);
	elevator.draw();


	if (zombie_mode) {
		glEnable(GL_LIGHTING);
		GLfloat LightDir[] = { 0.0f,0.0f,0.0f,1.0f };
		GLfloat LightPos[] = { start.x,start.y,start.z,1.0f };
		GLfloat LightAmb[] = { 1.0f,0.0f,0.0f,1.0f };
		GLfloat LightDiff[] = { 0.6f,0.6f,0.6f,1.0f };
		GLfloat LightSpec[] = { 0.2f,0.2f,0.2f,1.0f };

		GLfloat ambientColor[] = { 1.0f, 0.2f, 0.2f, 1.0f };

		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
		glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, false);


		glEnable(GL_LIGHT1);
		glLightfv(GL_LIGHT1, GL_POSITION, LightPos);
		glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmb);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiff);
		glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpec);
		for (int i = 0; i < storeys.size(); i++)
			storeys[i].draw();
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHTING);/**************************************************************************************************************
							   DONT FORGET TO REMOVE THIS					   ***********************/


	}

	else for (int i = 0; i < storeys.size(); i++)
		storeys[i].draw();

}