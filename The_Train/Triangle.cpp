#include "Triangle.h"
#include <windows.h>
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <Point.h>
#include <texture.h>

Triangle::Triangle(Point *p1, Point *p2, Point *p3, int texture )
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->texture = texture;
}
void Triangle::draw(){
	if(this->texture != -1){
		this->drawWithTexture();
		return;
	}
	this->drawWithoutTexture();
}
void Triangle::drawWithTexture(){
	glBindTexture(GL_TEXTURE_2D,texture);
	glBegin(GL_TRIANGLES);

		glTexCoord2d(this->p1->s, this->p1->t);
		glVertex3f(this->p1->x,this->p1->y, this->p1->z);
	
		glTexCoord2d(this->p2->s,this->p2->t);
		glVertex3f(this->p2->x,this->p2->y, this->p2->z);
		
		glTexCoord2d(this->p3->s, this->p3->t);
		glVertex3f(this->p3->x,this->p3->y, this->p3->z);

	glEnd();
}
void Triangle::drawWithoutTexture(){
	glBegin(GL_TRIANGLES);
		glVertex3f(this->p1->x, this->p1->y, this->p1->z);
		glVertex3f(this->p2->x,this->p2->y,this->p2->z);
		glVertex3f(this->p3->x,this->p3->y,this->p3->z);
	glEnd();
}

Triangle::~Triangle(void)
{
	
}
