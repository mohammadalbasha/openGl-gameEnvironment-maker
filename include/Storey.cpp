#include "Storey.h"

rectangle Storey::getLiftAndStairsArea() { 
	return lift_and_stairs_area; 
}

rectangle Storey::getElevatorArea() {
	return elevator_area; 
}

void Storey::draw() {


	Cube c;


	if (rooms_number % 2 == 1 || 6 * xAxis > 10 * zAxis || 6 * zAxis >= 10 * xAxis) {
		if (xAxis > zAxis)
		{

			double block = xAxis / (rooms_number * 1.0);
			double roomlength = 1 * block / 2;
			// bottom
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glColor4f(1, 1, 1, 0.6);
			draw_quad({ { start.x, start.y, start.z },{ start.x + xAxis - 3 * (block - roomlength) / 4, start.y, start.z },{ start.x + xAxis - 3 * (block - roomlength) / 4, start.y, start.z - zAxis } ,{ start.x, start.y, start.z - zAxis } }, { xAxis,zAxis }, out_texture, out_texture, 1, 0, 1);
			glColor4f(1, 1, 1, 1);
			glDisable(GL_BLEND);
			// up
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			draw_quad({ { start.x, start.y + yAxis, start.z },{ start.x + xAxis - 3 * (block - roomlength) / 4, start.y + yAxis, start.z },{ start.x + xAxis - 3 * (block - roomlength) / 4, start.y + yAxis, start.z - zAxis } ,{ start.x, start.y + yAxis, start.z - zAxis } }, { xAxis,zAxis }, out_texture, in_texture, 1, 0, 1);
			glColor4f(1, 1, 1, 1);
			glDisable(GL_BLEND);










		}
		else
		{
			double block = zAxis / (rooms_number * 1.0);
			double roomlength = 1 * block / 2;




			//buttom
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glColor4f(1, 1, 1, 0.6);
			draw_quad({ { start.x, start.y, start.z },{ start.x + xAxis, start.y, start.z },{ start.x + xAxis, start.y, start.z - zAxis + 3 * (block - roomlength) / 4 } ,{ start.x, start.y, start.z - zAxis + 3 * (block - roomlength) / 4 } }, { xAxis,zAxis }, out_texture, out_texture, 1, 0, 1);
			glColor4f(1, 1, 1, 1);
			glDisable(GL_BLEND);
			// up
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			//	 glColor4f(0, 0, 0, 1);
			draw_quad({ { start.x, start.y + yAxis, start.z },{ start.x + xAxis, start.y + yAxis, start.z },{ start.x + xAxis, start.y + yAxis, start.z - zAxis + 3 * (block - roomlength) / 4 } ,{ start.x, start.y + yAxis, start.z - zAxis + 3 * (block - roomlength) / 4 } }, { xAxis,zAxis }, out_texture, in_texture, 1, 0, 1);
			glColor4f(1, 1, 1, 1);
			glDisable(GL_BLEND);
		}

	}



	else {
		if (xAxis > zAxis)
		{

			double block = 2 * xAxis / (rooms_number * 1.0);
			double roomlength = 3 * block / 4;
			double windowlength = block / 4;
			double roomlength2 = (zAxis - windowlength) / 2;
			// bottom
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glColor4f(1, 1, 1, 0.6);
			draw_quad({ { start.x, start.y, start.z },{ start.x + xAxis - 3 * (block - roomlength) / 4, start.y, start.z },{ start.x + xAxis - 3 * (block - roomlength) / 4, start.y, start.z - zAxis } ,{ start.x, start.y, start.z - zAxis } }, { xAxis,zAxis }, out_texture, out_texture, 1, 0, 1);
			glColor4f(1, 1, 1, 1);
			glDisable(GL_BLEND);
			// up
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			//	 glColor4f(0, 0, 0, 1);
			draw_quad({ { start.x, start.y + yAxis, start.z },{ start.x + xAxis - 3 * (block - roomlength) / 4, start.y + yAxis, start.z },{ start.x + xAxis - 3 * (block - roomlength) / 4, start.y + yAxis, start.z - zAxis } ,{ start.x, start.y + yAxis, start.z - zAxis } }, { xAxis,zAxis }, out_texture, in_texture, 1, 0, 1);
			glColor4f(1, 1, 1, 1);
			glDisable(GL_BLEND);



		}
		else
		{
			double block = 2 * zAxis / (rooms_number * 1.0);
			double roomlength = 3 * block / 4;
			double windowlength = block / 4;
			double roomlength2 = (xAxis - windowlength) / 2;
			//buttom
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glColor4f(1, 1, 1, 0.6);
			draw_quad({ { start.x, start.y, start.z },{ start.x + xAxis, start.y, start.z },{ start.x + xAxis, start.y, start.z - zAxis + 3 * (block - roomlength) / 4 } ,{ start.x, start.y, start.z - zAxis + 3 * (block - roomlength) / 4 } }, { xAxis,zAxis }, out_texture, out_texture, 1, 0, 1);
			glColor4f(1, 1, 1, 1);
			glDisable(GL_BLEND);
			// up
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			//	 glColor4f(0, 0, 0, 1);
			draw_quad({ { start.x, start.y + yAxis, start.z },{ start.x + xAxis, start.y + yAxis, start.z },{ start.x + xAxis, start.y + yAxis, start.z - zAxis + 3 * (block - roomlength) / 4 } ,{ start.x, start.y + yAxis, start.z - zAxis + 3 * (block - roomlength) / 4 } }, { xAxis,zAxis }, out_texture, in_texture, 1, 0, 1);
			glColor4f(1, 1, 1, 1);
			glDisable(GL_BLEND);
		}
	}



	if (storey_index == 0) {
		// front
		c = draw_quad({ { start.x, start.y, start.z },{ start.x + xAxis / 3, start.y, start.z },{ start.x + xAxis / 3, start.y + yAxis, start.z },{ start.x, start.y + yAxis, start.z } }, { xAxis / 3,yAxis }, out_texture, in_texture, 1, 0, 1);
		if (!i)cu.push_back(c);
		c = draw_quad({ { start.x + 2 * xAxis / 3, start.y, start.z },{ start.x + xAxis, start.y, start.z },{ start.x + xAxis, start.y + yAxis, start.z },{ start.x + 2 * xAxis / 3, start.y + yAxis, start.z } }, { xAxis / 3,yAxis }, out_texture, in_texture, 1, 0, 1);
		if (!i)cu.push_back(c);
		c = draw_quad({ { start.x, start.y + yAxis / 2, start.z },{ start.x + xAxis, start.y + yAxis / 2, start.z },{ start.x + xAxis, start.y + yAxis, start.z } ,{ start.x, start.y + yAxis, start.z } }, { xAxis,yAxis / 2 }, out_texture, in_texture, 1, 0, 1);
		if (!i)cu.push_back(c);

		// back

		c = draw_quad({ { start.x, start.y, start.z - zAxis },{ start.x + xAxis, start.y, start.z - zAxis },{ start.x + xAxis, start.y + yAxis, start.z - zAxis },{ start.x, start.y + yAxis, start.z - zAxis } }, { xAxis,zAxis }, in_texture, out_texture, 1, 0, 1);
		if (!i)cu.push_back(c);


		// left

		c = draw_quad({ { start.x, start.y, start.z - zAxis },{ start.x , start.y, start.z },{ start.x , start.y + yAxis, start.z },{ start.x, start.y + yAxis, start.z - zAxis } }, { xAxis,zAxis }, out_texture, in_texture, 1, 0, 1);
		if (!i)cu.push_back(c);

		// right
		c = draw_quad({ { start.x + xAxis, start.y, start.z - zAxis },{ start.x + xAxis, start.y, start.z },{ start.x + xAxis, start.y + yAxis, start.z },{ start.x + xAxis, start.y + yAxis, start.z - zAxis } }, { xAxis,zAxis }, in_texture, out_texture, 1, 0, 1);
		if (!i)cu.push_back(c);

		//buttom 
		draw_quad({ { start.x, start.y + 0.5, start.z },{ start.x + xAxis, start.y + 0.5, start.z },{ start.x + xAxis, start.y + 0.5, start.z - zAxis  } ,{ start.x, start.y + 0.5, start.z - zAxis} }, { xAxis,zAxis }, out_texture, out_texture, 1, 0, 1);

	}


	if (xAxis > zAxis) {
		draw_quad({ { lift_and_stairs_area.p.x,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis / 2 }, { lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis / 2 },{  lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis  },{ lift_and_stairs_area.p.x,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis  } }, { lift_and_stairs_area.xAxis,lift_and_stairs_area.zAxis / 2 }, { glass_window_texture2 }, { glass_window_texture2 }, 1, 1, 0);
		draw_quad({ { lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis / 2,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z - 7 * lift_and_stairs_area.zAxis / 8 },{ lift_and_stairs_area.p.x + 3 * lift_and_stairs_area.xAxis / 4,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z - 7 * lift_and_stairs_area.zAxis / 8 },{ lift_and_stairs_area.p.x + 3 * lift_and_stairs_area.xAxis / 4,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis + 2 },{ lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis / 2,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis + 2 } }, { lift_and_stairs_area.xAxis,lift_and_stairs_area.zAxis / 2 }, { 1 }, { 1 }, 1, 1, 0);



	}
	else {

		draw_quad({ { lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis / 2,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z  },{ lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z},{ lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis },{ lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis / 2,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis } }, { lift_and_stairs_area.xAxis,lift_and_stairs_area.zAxis / 2 }, { glass_window_texture2 }, { glass_window_texture2 }, 1, 1, 0);
		draw_quad({ { lift_and_stairs_area.p.x + 7 * lift_and_stairs_area.xAxis / 8,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis / 2 },{ lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis - 2,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis / 2 },{ lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis - 2,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z - 3 * lift_and_stairs_area.zAxis / 4  },{ lift_and_stairs_area.p.x + 7 * lift_and_stairs_area.xAxis / 8,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z - 3 * lift_and_stairs_area.zAxis / 4 } }, { lift_and_stairs_area.xAxis,lift_and_stairs_area.zAxis / 2 }, { 1 }, { 1 }, 1, 1, 0);



	}




	if (!i) {
		if (xAxis > zAxis && storey_index) {
			Window w = Window({ lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis }, { lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z }, { lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis,lift_and_stairs_area.p.y + lift_and_stairs_area.yAxis,lift_and_stairs_area.p.z }, { lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis,lift_and_stairs_area.p.y + yAxis,lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis }, window_texture);
			windows.push_back(w);
		}
		else if (zAxis >= xAxis && storey_index) {
			Window w = Window({ lift_and_stairs_area.p.x ,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis }, { lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis }, { lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis,lift_and_stairs_area.p.y + lift_and_stairs_area.yAxis,lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis }, { lift_and_stairs_area.p.x ,lift_and_stairs_area.p.y + yAxis,lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis }, window_texture);
			windows.push_back(w);
		}

		if (xAxis > zAxis) {


			if (storey_index % 2 == 0)
				s = Stairs(lift_and_stairs_area.p.x, lift_and_stairs_area.p.y - 1, lift_and_stairs_area.p.z - 1, lift_and_stairs_area.xAxis / 2, lift_and_stairs_area.zAxis / 2, lift_and_stairs_area.yAxis + 2, 0);
			else
				s = Stairs(lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis, lift_and_stairs_area.p.y - 1, lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis / 2 - 1, lift_and_stairs_area.xAxis / 2, lift_and_stairs_area.zAxis / 2, lift_and_stairs_area.yAxis + 2, 180);

			c = Cube({ lift_and_stairs_area.p.x, lift_and_stairs_area.p.y - 1, lift_and_stairs_area.p.z - 3 }, 1, yAxis + 1, zAxis / 2, 0);
			cu.push_back(c);
			c = Cube({ lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis / 2, lift_and_stairs_area.p.y - 1, lift_and_stairs_area.p.z - 3 }, 1, yAxis + 1, zAxis / 2, 0);
			cu.push_back(c);
			c = Cube({ lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis, lift_and_stairs_area.p.y - 1, lift_and_stairs_area.p.z - 3 }, 1, yAxis + 1, zAxis / 2, 0);
			cu.push_back(c);


		}

		else {

			if (storey_index % 2 == 0 && !last_storey)
				s = Stairs(lift_and_stairs_area.p.x + 2, lift_and_stairs_area.p.y - 1, lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis / 2, lift_and_stairs_area.zAxis / 2, lift_and_stairs_area.xAxis / 2, lift_and_stairs_area.yAxis + 2.3, -90);
			else if (storey_index % 2 && !last_storey)
				s = Stairs(lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis / 2 + 2, lift_and_stairs_area.p.y - 1, lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis / 2, lift_and_stairs_area.zAxis / 2, lift_and_stairs_area.xAxis / 2, lift_and_stairs_area.yAxis + 2.3, 90);
			int a[] = { 1,1,1,1,1,1 };

			c = Cube({ lift_and_stairs_area.p.x + 4, lift_and_stairs_area.p.y - 1, lift_and_stairs_area.p.z }, xAxis / 2 - 2, yAxis + 1, 1, 0);
			cu.push_back(c);
			c = Cube({ lift_and_stairs_area.p.x + 4, lift_and_stairs_area.p.y - 1, lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis / 2 }, xAxis / 2 - 2, yAxis + 1, 1, 0);
			cu.push_back(c);
			c = Cube({ lift_and_stairs_area.p.x + 4, lift_and_stairs_area.p.y - 1, lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis }, xAxis / 2 - 2, yAxis + 1, 1, 0);
			cu.push_back(c);





		}
		for (int j = 0; j < cu.size(); j++) {
			camera.addMovementObserver(&cu[j]);
		}
		camera.addMovementObserver(&s);

	}
	i++;
	i = min(i, 1);




	for (int i = 0; i < rooms.size(); i++)
		rooms[i].draw();
	for (int i = 0; i < windows.size(); i++)
		windows[i].draw();
	if (!last_storey)
		s.draw();
}

Storey::Storey() {}

Storey::Storey(point start, double xAxis, double yAxis, double zAxis, int storey_index, int rooms_number,
	std::vector<int> in_textures, std::vector<int> out_textures, int window_texture, bool last_storey) {

	this->start = start;
	this->xAxis = xAxis;
	this->yAxis = yAxis;
	this->zAxis = zAxis;
	this->storey_index = storey_index;
	this->rooms_number = rooms_number;
	this->in_textures = in_textures;
	this->out_textures = out_textures;
	this->window_texture = window_texture;
	this->last_storey = last_storey;
	srand(time(0));
	in_texture = in_textures[rand() % in_textures.size()];
	out_texture = out_textures[rand() % out_textures.size()];

	if (rooms_number % 2 == 1 || 6 * xAxis > 10 * zAxis || 6 * zAxis >= 10 * xAxis) {
		if (xAxis > zAxis)
		{

			double block = xAxis / (rooms_number * 1.0);
			double roomlength = 1 * block / 2;
			for (int r = 0; r < rooms_number; r++) {
				if (storey_index == 0)continue;
				Room rm;
				if (r == 0)				 rm = Room({ start.x + block * r ,start.y,start.z }, roomlength, yAxis, zAxis, (r == 0), { 0,0,0,1,0,0 }, in_texture, out_texture);//convert textures to random
				else
					rm = Room({ start.x + block * r ,start.y,start.z }, roomlength, yAxis, zAxis, (r == 0), { 0,0,1,1,0,0 }, in_texture, out_texture);//convert textures to random
				rooms.push_back(rm);
				Window w = Window({ start.x + block * r + roomlength,start.y,start.z }, { start.x + block * (r + 1),start.y,start.z }, { start.x + block * (r + 1) ,start.y + yAxis,start.z }, { start.x + block * r + roomlength,start.y + yAxis,start.z }, window_texture);
				windows.push_back(w);
				w = Window({ start.x + block * r + roomlength,start.y,start.z - zAxis }, { start.x + block * (r + 1),start.y,start.z - zAxis }, { start.x + block * (r + 1) ,start.y + yAxis,start.z - zAxis }, { start.x + block * r + roomlength,start.y + yAxis,start.z - zAxis }, window_texture);
				windows.push_back(w);
			}


			// lift area on the xaxis 
			double la = 3 * (block - roomlength) / 4;
			lift_and_stairs_area.p = { start.x + xAxis - la,start.y,start.z };
			lift_and_stairs_area.xAxis = la;
			lift_and_stairs_area.zAxis = zAxis;
			lift_and_stairs_area.yAxis = yAxis;


		}
		else
		{

			double block = zAxis / (rooms_number * 1.0);
			double roomlength = 1 * block / 2;
			for (int r = 0; r < rooms_number; r++) {
				if (storey_index == 0)continue;

				Room rm;
				if (r == 0)			 rm = Room({ start.x  ,start.y,start.z - block * r }, xAxis, yAxis, roomlength, (r == 0), { 0,1,0,0,0,0 }, in_texture, out_texture);//convert textures to random
				else
					rm = Room({ start.x  ,start.y,start.z - block * r }, xAxis, yAxis, roomlength, (r == 0), { 1,1,0,0,0,0 }, in_texture, out_texture);//convert textures to random				

				rooms.push_back(rm);
				Window w = Window({ start.x ,start.y,start.z - block * (r + 1) }, { start.x ,start.y,start.z - (block * r + roomlength) }, { start.x ,start.y + yAxis,start.z - (block * r + roomlength) }, { start.x  ,start.y + yAxis,start.z - block * (r + 1) }, window_texture);

				windows.push_back(w);
				w = Window({ start.x + xAxis ,start.y,start.z - block * (r + 1) }, { start.x + xAxis ,start.y,start.z - (block * r + roomlength) }, { start.x + xAxis,start.y + yAxis,start.z - (block * r + roomlength) }, { start.x + xAxis ,start.y + yAxis,start.z - block * (r + 1) }, window_texture);

				windows.push_back(w);
			}

			// lift area on the zaxis 
			double la = 3 * (block - roomlength) / 4;

			lift_and_stairs_area.p = { start.x  ,start.y,start.z - zAxis + la };
			lift_and_stairs_area.xAxis = xAxis;
			lift_and_stairs_area.zAxis = la;
			lift_and_stairs_area.yAxis = yAxis;

		}



	}



	else {
		if (xAxis > zAxis)
		{

			double block = 2 * xAxis / (rooms_number * 1.0);
			double roomlength = 3 * block / 4;
			double windowlength = block / 4;
			double roomlength2 = (zAxis - windowlength) / 2;
			for (int r = 0; r < rooms_number / 2; r++) {
				if (storey_index == 0)continue;

				Room rm = Room({ start.x + block * r ,start.y,start.z }, roomlength, yAxis, roomlength2, r == 0, { 0,1,0,0,0,0 }, in_texture, out_texture);//convert textures to random
				rooms.push_back(rm);
				rm = Room({ start.x + block * r ,start.y,start.z - (roomlength2 + windowlength) }, roomlength, yAxis, roomlength2, r == 0, { 1,0,0,0,0,0 }, in_texture, out_texture);//convert textures to random
				rooms.push_back(rm);
				Window w = Window({ start.x + block * r + roomlength,start.y,start.z }, { start.x + block * (r + 1),start.y,start.z }, { start.x + block * (r + 1) ,start.y + yAxis,start.z }, { start.x + block * r + roomlength,start.y + yAxis,start.z }, window_texture);
				windows.push_back(w);
				w = Window({ start.x + block * r + roomlength,start.y,start.z - zAxis }, { start.x + block * (r + 1),start.y,start.z - zAxis }, { start.x + block * (r + 1) ,start.y + yAxis,start.z - zAxis }, { start.x + block * r + roomlength,start.y + yAxis,start.z - zAxis }, window_texture);
				windows.push_back(w);
			}
			if (storey_index) {
				Window w = Window({ start.x ,start.y ,start.z - zAxis + roomlength2 }, { start.x ,start.y ,start.z - roomlength2 }, { start.x ,start.y + yAxis ,start.z - roomlength2 }, { start.x ,start.y + yAxis,start.z - zAxis + roomlength2 }, window_texture);
				windows.push_back(w);
			}
			// lift area on the xaxis 
			double la = 3 * (block - roomlength) / 4;
			lift_and_stairs_area.p = { start.x + xAxis - la,start.y,start.z };
			lift_and_stairs_area.xAxis = la;
			lift_and_stairs_area.zAxis = zAxis;
			lift_and_stairs_area.yAxis = yAxis;

		}
		else
		{
			double block = 2 * zAxis / (rooms_number * 1.0);
			double roomlength = 3 * block / 4;
			double windowlength = block / 4;
			double roomlength2 = (xAxis - windowlength) / 2;
			for (int r = 0; r < rooms_number / 2; r++) {
				if (storey_index == 0)continue;

				Room rm = Room({ start.x  ,start.y,start.z - block * r }, roomlength2, yAxis, roomlength, r == 0, { 0,0,0,1,0,0 }, in_texture, out_texture);//convert textures to random
				rooms.push_back(rm);
				rm = Room({ start.x + roomlength2 + windowlength ,start.y,start.z - block * r }, roomlength2, yAxis, roomlength, r == 0, { 0,0,1,0,0,0 }, in_texture, out_texture);//convert textures to random
				rooms.push_back(rm);

				Window w = Window({ start.x ,start.y,start.z - block * (r + 1) }, { start.x ,start.y,start.z - (block * r + roomlength) }, { start.x ,start.y + yAxis,start.z - (block * r + roomlength) }, { start.x  ,start.y + yAxis,start.z - block * (r + 1) }, window_texture);

				windows.push_back(w);
				w = Window({ start.x + xAxis ,start.y,start.z - block * (r + 1) }, { start.x + xAxis ,start.y,start.z - (block * r + roomlength) }, { start.x + xAxis,start.y + yAxis,start.z - (block * r + roomlength) }, { start.x + xAxis ,start.y + yAxis,start.z - block * (r + 1) }, window_texture);
				windows.push_back(w);
				if (storey_index) {
					Window w = Window({ start.x + roomlength2 ,start.y ,start.z }, { start.x + 2 * roomlength2 ,start.y ,start.z }, { start.x + 2 * roomlength2,start.y + yAxis ,start.z }, { start.x + roomlength2,start.y + yAxis,start.z }, window_texture);
					windows.push_back(w);
				}
			}
			// lift area on the zaxis 
			double la = 3 * (block - roomlength) / 4;
			lift_and_stairs_area.p = { start.x  ,start.y,start.z - zAxis + la };
			lift_and_stairs_area.xAxis = xAxis;
			lift_and_stairs_area.zAxis = la;
			lift_and_stairs_area.yAxis = yAxis;
		}



	};



	if (xAxis > zAxis)
	{
		elevator_area.p = { lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis / 2,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z - 7 * lift_and_stairs_area.zAxis / 8 };
		elevator_area.xAxis = lift_and_stairs_area.xAxis / 4;
		elevator_area.yAxis = yAxis;
		elevator_area.zAxis = lift_and_stairs_area.zAxis / 8 - 1;
	}
	else {

		draw_quad({ { lift_and_stairs_area.p.x + 7 * lift_and_stairs_area.xAxis / 8,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis / 2 },{ lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis - 2,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis / 2 },{ lift_and_stairs_area.p.x + lift_and_stairs_area.xAxis - 2,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z - 3 * lift_and_stairs_area.zAxis / 4 },{ lift_and_stairs_area.p.x + 7 * lift_and_stairs_area.xAxis / 8,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z - 3 * lift_and_stairs_area.zAxis / 4 } }, { lift_and_stairs_area.xAxis,lift_and_stairs_area.zAxis / 2 }, { 1 }, { 1 }, 1, 1, 0);

		elevator_area.p = { lift_and_stairs_area.p.x + 7 * lift_and_stairs_area.xAxis / 8,lift_and_stairs_area.p.y,lift_and_stairs_area.p.z - lift_and_stairs_area.zAxis / 2 };
		elevator_area.xAxis = lift_and_stairs_area.xAxis / 8 - 1;
		elevator_area.yAxis = yAxis;
		elevator_area.zAxis = lift_and_stairs_area.zAxis / 4;

	}



}