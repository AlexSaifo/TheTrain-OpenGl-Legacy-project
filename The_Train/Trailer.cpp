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
#include <Trailer.h>
#include <camera.h>

using namespace std;


Trailer::Trailer(void)
{
}

Trailer::~Trailer(void)
{
}
Trailer::Trailer(int floorTexture,int innerCeilingTexture,int outerCeilingTexture,int innerSideTexture,int outerSideTexture,int windowTexture,int doorTexture,int last)
{
	this->outerCeilingTexture=outerCeilingTexture;
	this->innerCeilingTexture=innerCeilingTexture;
	this->floorTexture=floorTexture;
	this->outerSideTexture=outerSideTexture;
	this->innerSideTexture=innerSideTexture;
	this->windowTexture=windowTexture;
	this->doorTexture=doorTexture;
	this->last=last;
}
void Trailer::drawFrontBackDoorSides(int texture)
{
	Point *p1=new Point(-1.8,0,0,0,0);
	Point *p2=new Point(1.8,0,0,1,0);
	Point *p3=new Point(1.8,5,0,1,1);
	Point *p4=new Point(-1.8,5,0,0,1);
	Quad *quad=new Quad(p1,p2,p3,p4,texture);
	quad->draw();

	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(quad);

}
void Trailer::drawFrontBackDoorTop(int texture)
{
	Point *p1=new Point(-0.7,0,0,0,0);
	Point *p2=new Point(0.7,0,0,1,0);
	Point *p3=new Point(0.7,2.2,0,1,1);
	Point *p4=new Point(-0.7,2.2,0,0,1);
	Quad *quad=new Quad(p1,p2,p3,p4,texture);

	quad->draw();

	free(p1);
	free(p2);
	free(p3);
	free(p4);

	

	free(quad);
}
void Trailer::drawTrailerSide(int texture)
{
	Point *p1=new Point(-2,0,0,0,0);
	Point *p2=new Point(-1,0,0,1,0);
	Point *p3=new Point(-1,5,0,1,1);
	Point *p4=new Point(-2,5,0,0,1);
	Quad *quad=new Quad(p1,p2,p3,p4,texture);
	quad->draw();

	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(quad);
	
	p1=new Point(1,0,0,0,0);
	p2=new Point(2,0,0,1,0);
	p3=new Point(2,5,0,1,1);
	p4=new Point(1,5,0,0,1);
	quad=new Quad(p1,p2,p3,p4,texture);
	quad->draw();

	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(quad);

	p1=new Point(-1,0,0,0,0);
	p2=new Point(1,0,0,1,0);
	p3=new Point(1,1,0,1,1);
	p4=new Point(-1,1,0,0,1);
	quad=new Quad(p1,p2,p3,p4,texture);
	quad->draw();

	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(quad);

	p1=new Point(-1,3,0,0,0);
	p2=new Point(1,3,0,1,0);
	p3=new Point(1,5,0,1,1);
	p4=new Point(-1,5,0,0,1);
	quad=new Quad(p1,p2,p3,p4,texture);
	quad->draw();

	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(quad);
}
void Trailer::drawFloorCeiling(int texture)
{
	Point *p1=new Point(-4.3,0,6,0,0);
	Point *p2=new Point(4.3,0,6,1,0);
	Point *p3=new Point(4.3,0,-6,1,1);
	Point *p4=new Point(-4.3,0,-6,0,1);
	Quad *quad=new Quad(p1,p2,p3,p4,texture);
	quad->draw();

	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(quad);
}
void Trailer::drawLeftRightWall(int texture)
{
	
	glPushMatrix();
		drawTrailerSide(texture);
	glPopMatrix();

	glPushMatrix();
		glTranslated(4,0,0);
		drawTrailerSide(texture);
	glPopMatrix();

	glPushMatrix();
		glTranslated(-4,0,0);
		drawTrailerSide(texture);
	glPopMatrix();
}
void Trailer::drawWindow()
{
	Point *p1=new Point(-1,1,0,0,0);
	Point *p2=new Point(1,1,0,1,0);
	Point *p3=new Point(1,3,0,1,1);
	Point *p4=new Point(-1,3,0,1,0);
	Quad *quad=new Quad(p1,p2,p3,p4,windowTexture);
	
	quad->draw();

	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(quad);
}
void Trailer::drawWindows()
{
	glPushMatrix();
		drawWindow();
		glPopMatrix();

	glPushMatrix();
		glTranslated(4,0,0);
		drawWindow();
	glPopMatrix();

	glPushMatrix();
		glTranslated(-4,0,0);
		drawWindow();
	glPopMatrix();
}
void Trailer::drawFrontBack(int texture)
{
	//draw frontLeft quad
	glPushMatrix();
		glTranslated(-2.5,0,0);
		drawFrontBackDoorSides(texture);
	glPopMatrix();
	//////////////////////////////////////

	//draw frontRight quad
	glPushMatrix();
		glTranslated(2.5,0,0);
		drawFrontBackDoorSides(texture);
	glPopMatrix();
	//////////////////////////////////////

	//draw front top
	glPushMatrix();
		glTranslated(0,2.8,0);
		drawFrontBackDoorTop(texture);
	glPopMatrix();
	/////////////////////////////////////*/

}
void Trailer::draw(boolean backDoorState)
{
	//glScaled(1.5,1,1);

	//draw innner sides

/*	glPushMatrix();
		AccordionDoor *door=new AccordionDoor(frontDoorState,doorTexture);
		glTranslated(-0.7,0,-6);
		glScaled(1.4,1.4,1);
		door->draw();
	glPopMatrix();*/

	glPushMatrix();
	AccordionDoor *door=new AccordionDoor(backDoorState,doorTexture);
		glTranslated(0,0,6);
		glRotated(180,0,1,0);
		glTranslated(-0.7,0,0);
		glScaled(1.4,1.4,1);
		door->draw();
	glPopMatrix();

	//floor
	glPushMatrix();
		drawFloorCeiling(floorTexture);
	glPopMatrix();

	//ceiling
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	glPushMatrix();
		glTranslated(0,5,0);
		drawFloorCeiling(innerCeilingTexture);
	glPopMatrix();
	glDisable(GL_CULL_FACE);

	//backSide
	glPushMatrix();
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glTranslated(0,0,6);
		glRotated(180,0,1,0);
		drawFrontBack(innerSideTexture);
		glDisable(GL_CULL_FACE);
	glPopMatrix();

	//front side
	if(last==-1)
	{
		glPushMatrix();
			glEnable(GL_CULL_FACE);
			glCullFace(GL_BACK);
			glTranslated(0,0,-6);
			drawFrontBack(innerSideTexture);
			glDisable(GL_CULL_FACE);
		glPopMatrix();
	}
	if(last!=-1)
	{
		glPushMatrix();
			glEnable(GL_CULL_FACE);
			glCullFace(GL_BACK);
			glTranslated(0,0,-6);
			Point *p11=new Point(-4.3,0,0,0,0);
			Point *p22=new Point(4.3,0,0,1,0);
			Point *p33=new Point(4.3,5,0,1,1);
			Point *p44=new Point(-4.3,5,0,0,1);

			Quad *q11=new Quad(p11,p22,p33,p44,innerSideTexture);
			q11->draw();

			free(p11);
			free(p22);
			free(p33);
			free(p44);

			free(q11);
			glDisable(GL_CULL_FACE);
		glPopMatrix();

		glPushMatrix();
			glEnable(GL_CULL_FACE);
			glCullFace(GL_FRONT);
			glTranslated(0,0,-6);
			Point *p1=new Point(-4.3,0,0,0,0);
			Point *p2=new Point(4.3,0,0,1,0);
			Point *p3=new Point(4.3,5,0,1,1);
			Point *p4=new Point(-4.3,5,0,0,1);

			Quad *q1=new Quad(p1,p2,p3,p4,last);
			q1->draw();

			free(p1);
			free(p2);
			free(p3);
			free(p4);

			free(q1);
			glDisable(GL_CULL_FACE);
		glPopMatrix();
	}
	//rightSide
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glPushMatrix();
		glTranslated(4.3,0,0);
		glRotated(-90,0,1,0);
		drawLeftRightWall(innerSideTexture);
	glPopMatrix();
	glDisable(GL_CULL_FACE);

	//leftSide
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glPushMatrix();
		glTranslated(-4.3,0,0);
		glRotated(90,0,1,0);
		drawLeftRightWall(innerSideTexture);
	glPopMatrix();
	glDisable(GL_CULL_FACE);

	
	//otuerceiling
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glPushMatrix();
		glTranslated(0,5,0);
		drawFloorCeiling(outerCeilingTexture);
	glPopMatrix();
	glDisable(GL_CULL_FACE);

	//outerLeftSide
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	glPushMatrix();
		glTranslated(-4.3,0,0);
		glRotated(90,0,1,0);
		drawLeftRightWall(outerSideTexture);
	glPopMatrix();
	glDisable(GL_CULL_FACE);

	//outerRightSide
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	glPushMatrix();
		glTranslated(4.3,0,0);
		glRotated(-90,0,1,0);
		drawLeftRightWall(outerSideTexture);
	glPopMatrix();
	glDisable(GL_CULL_FACE);

	//rightSide
	glPushMatrix();
		glTranslated(4.3,0,0);
		glRotated(-90,0,1,0);
		drawWindows();
	glPopMatrix();

	//leftSide
	glPushMatrix();
		glTranslated(-4.3,0,0);
		glRotated(90,0,1,0);
		drawWindows();
	glPopMatrix();

}


void Trailer::drawTrailerWithoutWindows(boolean backDoorState){
	// drawing floor
	glPushMatrix();
	AccordionDoor *door=new AccordionDoor(backDoorState,doorTexture);
		glTranslated(0,0,6);
		glRotated(180,0,1,0);
		glTranslated(-0.7,0,0);
		glScaled(1.4,1.4,1);
		door->draw();
	glPopMatrix();

	//floor
	glPushMatrix();
		drawFloorCeiling(floorTexture);
	glPopMatrix();

	//ceiling
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	glPushMatrix();
		glTranslated(0,5,0);
		drawFloorCeiling(innerCeilingTexture);
	glPopMatrix();
	glDisable(GL_CULL_FACE);

	//backSide
	glPushMatrix();
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glTranslated(0,0,6);
		glRotated(180,0,1,0);
		drawFrontBack(innerSideTexture);
		glDisable(GL_CULL_FACE);
	glPopMatrix();

	//front side
	glPushMatrix();
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glTranslated(0,0,-6);
		drawFrontBack(innerSideTexture);
		glDisable(GL_CULL_FACE);
	glPopMatrix();

	//otuerceiling
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glPushMatrix();
		glTranslated(0,5,0);
		drawFloorCeiling(outerCeilingTexture);
	glPopMatrix();
	glDisable(GL_CULL_FACE);

	// drawing left outer side wall without widows
	glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
			glPushMatrix();
				Point *p1 = new Point(-4.3,0,6,0,1);
				Point *p2 = new Point(-4.3,5,6,1,1);
				Point *p3 = new Point(-4.3,5,-6,1,0);
				Point *p4 = new Point(-4.3,0,-6,0,0);
				Quad *q = new Quad(p1,p2,p3,p4,this->outerSideTexture);
				q->draw();
			glPopMatrix();
	glDisable(GL_CULL_FACE);
	// drawing left inner side wall without widows
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
			glPushMatrix();
				p1 = new Point(-4.3,0,6,0,1);
				p2 = new Point(-4.3,5,6,1,1);
				p3 = new Point(-4.3,5,-6,1,0);
				p4 = new Point(-4.3,0,-6,0,0);
				q = new Quad(p1,p2,p3,p4,this->innerSideTexture);
				q->draw();
			glPopMatrix();
	glDisable(GL_CULL_FACE);
	// drawing right side outer wall without windows
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
		glPushMatrix();
			p1 = new Point(4.3,0,6,0,1);
			p2 = new Point(4.3,5,6,1,1);
			p3 = new Point(4.3,5,-6,1,0);
			p4 = new Point(4.3,0,-6,0,0);
			q = new Quad(p4,p3,p2,p1,this->innerSideTexture);
			q->draw();
		glPopMatrix();
	glDisable(GL_CULL_FACE);
	
	//drawing right side outer wall without windows
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
		glPushMatrix();
			p1 = new Point(4.3,0,6,0,1);
			p2 = new Point(4.3,5,6,1,1);
			p3 = new Point(4.3,5,-6,1,0);
			p4 = new Point(4.3,0,-6,0,0);
			q = new Quad(p4,p3,p2,p1,this->outerSideTexture);
			q->draw();
		glPopMatrix();
	glDisable(GL_CULL_FACE);

}