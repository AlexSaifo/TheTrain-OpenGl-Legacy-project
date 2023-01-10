#include "Books.h"
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

using namespace std;

Books::Books(int cover1 ,int cover2,int cover3,int cover4 )
{
	this->cover1 = cover1;
	this->cover2 = cover2;
	this->cover3 = cover3;
	this->cover4 = cover4;
}


Books::~Books(void)
{
}


void Books::draw(void)
{
	//book1
	/*glPushMatrix();
	Point *P1 = new Point(0,0,0,0,0);
	Point *p2 = new Point(0.5,0,0,1,0);
	Point *p3 = new Point(0.5,2,0,1,1);
	Point *p4 = new Point(0,2,0,0,1);

	Quad *quad1 = new Quad(P1,p2,p3,p4,texture1);
	quad1->draw();*/

	/*free(quad1);*/

		//drawOneBook( cover2,3.5);
		//drawOneBook( cover3,4);
		////
	
		glPushMatrix();
	glRotated(180,0,1,0);
	glTranslated(0,0,0);
	drawIn2();
	glPopMatrix();

	glPushMatrix();
	
	glTranslated(0,0,13.7);
	drawIn2();
	glPopMatrix();
	/////////////////////////////////
	drawIn1();
	glPushMatrix();
	glRotated(180,0,1,0);
	glTranslated(0,0,13.5);
	drawIn1();
	glPopMatrix();

	glPushMatrix();
	glRotated(-90,0,1,0);
	glTranslated(5,0,15);
	drawIn1();
	glPopMatrix();

	glPushMatrix();
	glRotated(-90,0,1,0);
	glTranslated(5,0,-1.5);
	drawIn1();
	glPopMatrix();
	////////////////



}
void Books::drawOneBook(int cover ,float x ,float y){


		glPushMatrix();
		glTranslated(x,0,0);
		glRotated(y,0,0,1);
		
		
	cubid *book1=new cubid (cover,cover,cover,cover,cover,cover);
	///*glTranslated(0.05,0,-0.7);
	glScaled(0.3,2,0.6);
	book1->draw();
	glPopMatrix();














}
void Books::drawBooksInShelf(float x,float y)
{
	if (y==1)
	{
	glPushMatrix();
		glTranslated(0,x,0);
	glTranslated(13.2,1.5,-9.65);
	glRotated(-90,0,1,0);
		drawOneBook( cover1,1,-20);
		drawOneBook( cover2,1.5,-15);
	
		drawOneBook( cover3,2,-10);
		drawOneBook( cover4,2.5,-4);
		glTranslated(1.8,0,0);
			drawOneBook( cover1,1,-20);
		drawOneBook( cover2,1.5,-15);
	
		drawOneBook( cover3,2,-10);
		drawOneBook( cover4,2.5,-4);
		glTranslated(0,1,0);
		glScaled(1,0.8,1);
		drawOneBook( cover1,1,-22);
		glPopMatrix();
	}
	if(y==2)
	{
	glPushMatrix();
		glTranslated(0,x,0);
	glTranslated(13.2,1.5,-9.65);
	glRotated(-90,0,1,0);
		drawOneBook( cover1,1,-20);
		drawOneBook( cover2,1.5,-15);
	
		drawOneBook( cover3,2,-10);
		drawOneBook( cover4,2.5,-4);
	glPopMatrix();
	
	
	
	
	
	
	}
	

}
void Books::drawIn1()
{

	drawBooksInShelf(0,1);
	drawBooksInShelf(4,1);
	drawBooksInShelf(-4,1);
	drawBooksInShelf(-8,1);

}
void Books::drawIn2()
{
	glPushMatrix();
		glTranslated(0.2,-0.1,-0.3);
	glPushMatrix();
	glTranslated(0.2,-0.1,2);
	drawBooksInShelf(4,2);
	drawBooksInShelf(-4,2);
	glPopMatrix();
	drawBooksInShelf(0,2);
	
	drawBooksInShelf(-8,2);
	glPopMatrix();

}