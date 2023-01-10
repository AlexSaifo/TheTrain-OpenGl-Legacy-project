#include "Quad.h"
#include "Triangle.h"
#include <windows.h>
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <Point.h>


Quad::Quad(Point *p1, Point *p2, Point *p3, Point *p4, int texture)
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->p4 = p4;
	this->texture = texture;
}


Quad::~Quad(void)
{
}

void Quad::draw(){
	if(this->texture != -1){
		this->drawWithTexture();
		return;
	}
	this->drawWithoutTexture();
}

void Quad::drawWithTexture(){
	glBindTexture(GL_TEXTURE_2D,this->texture);
	glBegin(GL_QUADS);
		glTexCoord2d(this->p1->s, this->p1->t);
		glVertex3f(this->p1->x,this->p1->y,this->p1->z);
		glTexCoord2d(this->p2->s, this->p2->t);
		glVertex3f(this->p2->x,this->p2->y,this->p2->z);
		glTexCoord2d(this->p3->s, this->p3->t);
		glVertex3f(this->p3->x,this->p3->y,this->p3->z);
		glTexCoord2d(this->p4->s, this->p4->t);
		glVertex3f(this->p4->x,this->p4->y,this->p4->z);
	glEnd();
}

void Quad::drawWithoutTexture(){
	glBindTexture(GL_TEXTURE_2D,this->texture);
	glBegin(GL_QUADS);
		glVertex3f(p1->x,p1->y,p1->z);
		glVertex3f(p2->x,p2->y,p2->z);
		glVertex3f(p3->x,p3->y,p3->z);
		glVertex3f(p4->x,p4->y,p4->z);
	glEnd();
}