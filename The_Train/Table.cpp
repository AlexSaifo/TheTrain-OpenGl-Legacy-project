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
#include<camera.h>
#include<cubid.h>
#include<Curtains.h>
#include<passengerSeat.h>
#include<color.h>
#include "Table.h"

using namespace std;

Table::Table(void)
{
}


Table::~Table(void)
{
}
Table::Table(int texture)
{
	this->texture=texture;
}

void Table::leg()
{
	cubid *cub=new cubid(texture,texture,texture,texture,texture,texture);

	glScaled(0.5,3.5,0.5);
	cub->draw();

	free(cub);

}
void Table::tableTop()
{
	cubid *cub=new cubid(texture,texture,texture,texture,texture,texture);

	glScaled(5,1,4);
	cub->draw();

	free(cub);
}
void Table::draw(void)
{

	
	//tableTop
	glPushMatrix();
		glTranslated(-2.5,3.5,-2);
		tableTop();
	glPopMatrix();

	//leftFrontLeg;
	glPushMatrix();
		glTranslated(-2.5,0,1.5);
		leg();
	glPopMatrix();

	//rightFrontLeg
	glPushMatrix();
		glTranslated(2,0,1.5);
		leg();
	glPopMatrix();

	//leftBackLeg
	glPushMatrix();
		glTranslated(-2.5,0,-2);
		leg();
	glPopMatrix();


	//rightBackLeg
	glPushMatrix();
		glTranslated(2,0,-2);
		leg();
	glPopMatrix();
}