#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <Triangle.h>
#include <Point.h>
#include <texture.h>
#include <iostream>
#include <Quad.h>
#include <Circle.h>
#include <Cylinder.h>
#include <AccordionDoor.h>
#include<Trailer.h>
#include <camera.h>
#include<cubid.h>
#include<Curtains.h>
#include<passengerSeat.h>
#include<color.h>
#include<Table.h>
#include "Chair.h"

using namespace std;


Chair::Chair(void)
{
}
Chair::Chair(int texture)
{
	this->texture=texture;
}
void Chair::draw(void)
{
	glPushMatrix();

	glScaled(0.5,0.5,0.5);

	Table *table=new Table(texture);
	table->draw();

	free(table);

	cubid *cub=new cubid(texture,texture,texture,texture,texture,texture);

	glPushMatrix();
		glTranslated(-2.5,3.5,-2);
		glScaled(5,8,0.5);
		cub->draw();

		free(cub);
	glPopMatrix();

	glPopMatrix();
}

Chair::~Chair(void)
{
}
