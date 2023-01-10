#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include"Point.h"
#include"color.h"
#include"Quad.h"
#include"Cubid.h"
#include"Cylinder.h"
#include "Curtains.h"




Curtains::Curtains(color *cl)
{
	this->cl=cl;
}
void Curtains::drawPart(Point *p1,Point *p2,float xx,float zz)
{
	

	
	Point *p3=new Point(p1->x-1+xx,p1->y,1.5+zz);
	Point *p4=new Point(p1->x-1+xx,p2->y,1.5+zz);
	Point *p5=new Point(p1->x+1-xx,p1->y,1.5+zz);
	Point *p6=new Point(p1->x+1-xx,p2->y,1.5+zz);
	
	
	glBegin(GL_QUADS);
		
	glColor3f((cl->x)-0.04,(cl->y)-0.04,(cl->z)-0.04);
		glVertex3f(p1->x, p1->y, p1->z);

	glColor3f((cl->x)-0.04,(cl->y)-0.04,(cl->z)-0.04);
		glVertex3f(p2->x, p2->y, p2->z);

	glColor3f(cl->x,cl->y,cl->z);
		glVertex3f(p4->x, p4->y, p4->z);

	glColor3f(cl->x,cl->y,cl->z);
		glVertex3f(p3->x, p3->y, p3->z);
	glEnd( );

	glBegin(GL_QUADS);
		
	glColor3f((cl->x)-0.04,(cl->y)-0.04,(cl->z)-0.04);
		glVertex3f(p1->x, p1->y, p1->z);

	glColor3f((cl->x)-0.04,(cl->y)-0.04,(cl->z)-0.04);
		glVertex3f(p2->x, p2->y, p2->z);

	glColor3f(cl->x,cl->y,cl->z);
		glVertex3f(p6->x, p6->y, p6->z);

	glColor3f(cl->x,cl->y,cl->z);
		glVertex3f(p5->x, p5->y, p5->z);
	glEnd( );

	free(p3);
	free(p4);
	free(p5);
	free(p6);


}
void Curtains::drawOneSide(Point *p1,Point *p2,float tran,float cc,float v)
{

		glPushMatrix();
			glTranslated(0,0,0);
			drawPart(p1,p2,cc,v);
		glPopMatrix();

		glPushMatrix();
			glTranslated(tran,0,0);
			drawPart(p1,p2,cc,v);
		glPopMatrix();

		glPushMatrix();
			glTranslated(2*tran,0,0);
			drawPart(p1,p2,cc,v);
		glPopMatrix();

		glPushMatrix();
			glTranslated(3*tran,0,0);
			drawPart(p1,p2,cc,v);
		glPopMatrix();

		glPushMatrix();
			glTranslated(4*tran,0,0);
			drawPart(p1,p2,cc,v);
		glPopMatrix();

		/*glPushMatrix();
			glTranslated(5*tran,0,0);
			drawPart(p1,p2,cc,v);
		glPopMatrix();
		*/
	
}
void Curtains::draw(float mov,float tr)
{
	
		Point *p1=new Point(0,8,0);
		Point *p2=new Point(0,-8,0);

		glPushMatrix();
			glTranslated(-8.05,0,0);
		
			glPushMatrix();
				Point *p11=new Point(p1->x-1.5,p1->y-1,p1->z+0.3);
				glColor3f(0.4,0.4,0.4);
				glTranslated(p11->x,p11->y,p11->z);
				glRotated(-90,0,0,1);
				Cylinder *cy11=new Cylinder(0.2,19.1);
				cy11->draw();

				free(cy11);
			glPopMatrix();
	
			glPushMatrix();
				drawOneSide(p1,p2,tr,mov,mov);
	
					glTranslated(16,0,0);
					drawOneSide(p1,p2,-1*tr,mov,mov);
			glPopMatrix();
		glPopMatrix();

		free(p1);
		free(p2);
	glColor3f(1,1,1);
}
Curtains::~Curtains(void)
{
}
/*

/*
// draw the Curtains
glScaled(0.1,0.1,0.1);
	Curtains *cur=new Curtains();
	cur->draw(vv,tran);
*/

 /*
 //move the Curtains
	 if(keys['J']) //open
{
	if(tran>0.5)
	{
		vv+=0.05;
		tran-=0.1;
	}
}
if(keys['K']) //close
{
	if(tran<2)
	{
		vv-=0.05;
		tran+=0.1;
	}
}


	*/