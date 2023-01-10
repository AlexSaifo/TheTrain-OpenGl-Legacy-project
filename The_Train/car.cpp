#include "car.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include<texture.h>
#include"Point.h"
#include"Quad.h"
#include"cubid.h"
#include "passengerSeat.h"

car::car(int tiercover,int tara,int cardoor ,int window ,Point *pp)

{
	this->pp=pp;
	this->tiercover = tiercover;
	this->tara = tara;
	
	this->window = window;
	this->cardoor = cardoor;
}



car::~car(void)
{
}

	Point *p[]={
		
		new Point(0,0.5,1),//0
		new Point(1,0.8,1),//1
		new Point(1,0.5,1),//2
		new Point(0,0.5,0),//3
		new Point(1,0.8,0),//4
	//////////
		new Point(1.25,1.1,1),//5
		
		new Point(1.25,0.8,1),//6
		new Point(1.25,1.1,0),//7
		
		
		
		};
void car::draw()
{
	


		//0,3,4,1
		//5,7,4,1


	glColor3ub(pp->x,pp->y,pp->z);
		glPushMatrix();
		glTranslated(-2,-2,-8.5);

		drawedges();



		glPushMatrix();
		glTranslated(4,0,1);
		glRotated(180,0,1,0);
		
		drawedges();
		glPopMatrix();

		//////////////////////////////////////////////////////////

		glPushMatrix();
		
		
		glScaled(4,0.5,1);

			cubid *cub1=new cubid(-1,-1,-1,-1,cardoor,-1);
			cubid *cub3=new cubid(-1,-1,-1,-1,-1,-1);
		cub1->draw();
		glPopMatrix();

	




		glPushMatrix();
		glTranslated(1,0.5,0);
		glScaled(2,0.3,1);
		
		cub3->draw();
		glPopMatrix();
		
		
		glPushMatrix();
		cubid *cub2=new cubid(-1,-1,-1,-1,window,-1);
		glTranslated(1.25,0.8,0);
		glScaled(1.5,0.3,1);
			
		cub2->draw();
		
		glPopMatrix();
		glColor3ub(255,255,255);
//////////////////////////////////////////
		
		
		glPushMatrix();
		glTranslated(2,-0.1,0.85);
		glRotated(180,0,1,0);
		drawtier(tiercover,tara);
		glPopMatrix();

			glPushMatrix();
		glTranslated(4,-0.1,0.85);
			glRotated(180,0,1,0);
		
		drawtier(tiercover,tara);
		glPopMatrix();

		
		
		
		
			glPushMatrix();
		glTranslated(2,0,0.17);
		
		
		drawtier(tiercover,tara);
		glPopMatrix();


			glPushMatrix();
		glTranslated(0,0,0.17);
		
		
		drawtier(tiercover,tara);
		glPopMatrix();
		
		/*glTranslated();
		cy1->draw();
		glTranslated();
		cy1->draw();*/

		



















		glPopMatrix();

}
void car::drawedges()
{
	
		glPushMatrix();
			
		Quad *quad1= new Quad(p[0],p[3],p[4],p[1],window);
		quad1->draw();
			
	Quad *quad2= new Quad(p[5],p[7],p[4],p[1],window);
	quad2->draw();







		glPopMatrix();
		//////////////////////////////////////
			glPushMatrix();
	
		Triangle *tr=new Triangle(p[0],p[2],p[1]);
		tr->draw();
		glTranslated(0,0,-1);
			tr->draw();
	
		glPopMatrix();



			glPushMatrix();
		
		Triangle *tr1=new Triangle(p[1],p[6],p[5]);
		tr1->draw();
		glTranslated(0,0,-1);
			tr1->draw();
		
		glPopMatrix();

		//////////////////////////////////////////
}
void car::drawtier(int tiercover,int tara ){
glPushMatrix();
		
int cy1[2]={tiercover,tara};
		Cylinder *cy10=new Cylinder(-1,-1,cy1);
		
		glTranslated(1,0,0);
		glRotated(90,1,0,0);
		glScaled(0.3,0.3,0.3);
		cy10->draw();
		glPopMatrix();

}