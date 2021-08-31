#include "Model.h"
#include <glu.h>

Model::Model() {}

Model::Model(Model_3DS* model, vertex center, double scale, vertex containerCenter, double width, double height, double length,
	int tex, int hasLightSource, vertex lightSource, double yRotated) : Object(center) {

	this->model = model;
	this->scale = scale;
	this->yRotated = yRotated;

	this->container = Cube(containerCenter, width, height, length, 0);
	this->container.setTextures({ tex, 100, 100, 100, 100, 100 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 });
	camera.addMovementObserver(&this->container);

	this->hasLightSource = hasLightSource;
	if (hasLightSource)
		this->lightSource = lightSource;
}

void Model::draw() {
	glPushMatrix();
	glTranslated(center.x, center.y, center.z);
	glRotated(yRotated, 0, 1, 0);
	model->pos.x = 0;
	model->pos.y = 0;
	model->pos.z = 0;
	model->scale = scale;
	model->Draw();

	//LIGHTING
	if (hasLightSource == 1) {  // CAR1
		glPushMatrix();
		glTranslated(lightSource.x, lightSource.y, lightSource.z);
		auxSolidSphere(0.2);
		glPopMatrix();

		glPushMatrix();
		glTranslated(lightSource.x - 3.2, lightSource.y, lightSource.z);
		auxSolidSphere(0.2);
		glPopMatrix();


		GLfloat LightPos1[] = { lightSource.x, lightSource.y, lightSource.z, 1.0f };
		GLfloat LightPos2[] = { lightSource.x - 3.2, lightSource.y, lightSource.z, 1.0f };
		GLfloat LightAmb[] = { 0.4f, 0.4f, 0.4f, 1.0f };
		GLfloat LightDiff[] = { 0.7f, 0.7f, 0.7f, 1.0f };
		GLfloat LightSpec[] = { 0.6f, 0.6f, 0.6f, 1.0f };

		glEnable(GL_LIGHT3);
		glLightfv(GL_LIGHT3, GL_POSITION, LightPos1);
		glLightfv(GL_LIGHT3, GL_AMBIENT, LightAmb);
		glLightfv(GL_LIGHT3, GL_DIFFUSE, LightDiff);
		glLightfv(GL_LIGHT3, GL_SPECULAR, LightSpec);

		glEnable(GL_LIGHT4);
		glLightfv(GL_LIGHT4, GL_POSITION, LightPos2);
		glLightfv(GL_LIGHT4, GL_AMBIENT, LightAmb);
		glLightfv(GL_LIGHT4, GL_DIFFUSE, LightDiff);
		glLightfv(GL_LIGHT4, GL_SPECULAR, LightSpec);

	}
	else if (hasLightSource == 3) { // LMAP POST
		glPushMatrix();
		glTranslated(lightSource.x, lightSource.y, lightSource.z);
		auxSolidSphere(0.2);
		glPopMatrix();

		GLfloat LightPos[] = { lightSource.x, lightSource.y, lightSource.z, 1.0f };
		GLfloat LightAmb[] = { 0.9f, 0.9f, 0.9f, 1.0f };
		GLfloat LightDiff[] = { 0.6f, 0.6f, 0.6f, 1.0f };
		GLfloat LightSpec[] = { 0.2f, 0.2f, 0.2f, 1.0f };

		glEnable(GL_LIGHT2);
		glLightfv(GL_LIGHT2, GL_POSITION, LightPos);
		glLightfv(GL_LIGHT2, GL_AMBIENT, LightAmb);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, LightDiff);
		glLightfv(GL_LIGHT2, GL_SPECULAR, LightSpec);
	}

	glPopMatrix();
	//container.draw();  //TO BE REMOVED AFTER ADDING THE OBSERVER
}
