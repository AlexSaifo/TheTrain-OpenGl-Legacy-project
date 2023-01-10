#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include<texture.h>
#include"Point.h"
#include"Quad.h"
#include"cubid.h"
#include "passengerSeat.h"


passengerSeat::passengerSeat(void)
{
}
passengerSeat::passengerSeat(color *baseCol,color *handRestsCol,int seatText)
{
	baseColor=baseCol;
	handRestsColor=handRestsCol;
	seatTexture=seatText;
}
void drawSheered(Point*p1,Point*p2,Point*p3,Point*p4,float h,float xSheer,float zSheer,int texture)
{
	Point *p[] = {
		new Point(p1->x,p1->y,p1->z), //A , 0
		new Point(p2->x,p2->y,p2->z), //B , 1
		new Point(p3->x,p3->y,p3->z), //C , 2
		new Point(p4->x,p4->y,p4->z), //D , 3
		new Point(p1->x+xSheer,p1->y+h,p1->z+zSheer), //E , 4
		new Point(p2->x+xSheer,p2->y+h,p2->z+zSheer), //F , 5
		new Point(p3->x+xSheer,p3->y+h,p3->z+zSheer), //G , 6
		new Point(p4->x+xSheer,p4->y+h,p4->z+zSheer)  //H , 7
		};

	Quad *test=new Quad(p[4],p[5],p[6],p[7],-1);
	test->draw();
	// bottom A, B, C, D
	p[0]->s = 0;
	p[0]->t = 0;
	p[1]->s = 1;
	p[1]->t = 0;
	p[2]->s = 1;
	p[2]->t = 1;
	p[3]->s = 0;
	p[3]->t = 1;

	Quad *down = new Quad (p[0], p[1], p[2], p[3],texture);
	down->draw();

	// Top E, F, G, H
	p[4]->s = 0;
	p[4]->t = 0;
	p[5]->s = 1;
	p[5]->t = 0;
	p[6]->s = 1;
	p[6]->t = 1;
	p[7]->s = 0;
	p[7]->t = 1;
	
	Quad *top = new Quad(p[4], p[5], p[6], p[7], texture);
	top->draw();

	// Front A, B, F, E 
	p[0]->s = 0;
	p[0]->t = 0;
	p[1]->s = 1;
	p[1]->t = 0;
	p[5]->s = 1;
	p[5]->t = 1;
	p[4]->s = 0;
	p[4]->t = 1;
	
	Quad *front = new Quad(p[0], p[1], p[5], p[4], texture);
	front->draw();

	// Back D, C, G, H
	p[3]->s = 0;
	p[3]->t = 0;
	p[2]->s = 1;
	p[2]->t = 0;
	p[6]->s = 1;
	p[6]->t = 1;
	p[7]->s = 0;
	p[7]->t = 1;

	Quad *back = new Quad(p[3], p[2], p[6], p[7], texture);
	back->draw();

	// Right B, C, G, F
	p[1]->s = 0;
	p[1]->t = 0;
	p[2]->s = 1;
	p[2]->t = 0;
	p[6]->s = 1;
	p[6]->t = 1;
	p[5]->s = 0;
	p[5]->t = 1;

	Quad *right = new Quad(p[1], p[2], p[6], p[5], texture);
	right->draw();
	// Left A, D, H, E
	p[0]->s = 0;
	p[0]->t = 0;
	p[3]->s = 1;
	p[3]->t = 0;
	p[7]->s = 1;
	p[7]->t = 1;
	p[4]->s = 0;
	p[4]->t = 1;

	Quad *left = new Quad(p[0], p[3], p[7], p[4],texture);
	left->draw();
	free(top);
	free(down);
	free(left);
	free(right);
	free(front);
	free(back);
	for(int i = 0; i < 8; i++){
		free(p[i]);
	}


}
void passengerSeat::drawBase(Point*p1,Point*p2,Point*p3,Point*p4,Point*p5,Point*p6,Point*p7,Point*p8)
{
	Quad *sq1=new Quad(p1,p2,p3,p4,-1);
	sq1->draw();

	Quad *sq2=new Quad(p5,p6,p7,p8,-1);
	sq2->draw();

	Quad *sq3=new Quad(p1,p2,p6,p5,-1);
	sq3->draw();

	Quad *sq4=new Quad(p2,p3,p7,p6,-1);
	sq4->draw();
	Quad *sq5=new Quad(p3,p4,p8,p7,-1);
	sq5->draw();

	Quad *sq6=new Quad(p4,p1,p5,p8,-1);
	sq6->draw();
}
void passengerSeat::drawSeat(Point*p1,Point*p2,Point*p3,Point*p4,int texture)
{
	drawSheered(p1,p2,p3,p4,1,0,0,texture);



	Point *p22=new Point(p1->x+1,p2->y,p2->z);
	Point *p33=new Point(p4->x+1,p3->y,p3->z);

	drawSheered(p1,p22,p33,p4,8,-1,0,texture);
}
void passengerSeat::drawHandRests(Point*p1,Point*p2,Point*p3,Point*p4)
{
	p1->y+=2.5;
	p2->y+=2.5;
	p3->y+=2.5;
	p4->y+=2.5;


	Point*p5=new Point(p1->x,p1->y,p1->z+1);
	Point*p6=new Point(p2->x,p2->y,p2->z+1);

	drawSheered(p5,p6,p2,p1,1,-0.5,0,-1);

	Point*p7=new Point(p3->x,p3->y,p3->z-1);
	Point*p8=new Point(p4->x,p4->y,p4->z-1);

	drawSheered(p4,p3,p7,p8,1,-0.5,0,-1);
}
void passengerSeat::draw(int passengeres)
{
	
	Point*p1 =new Point(-1.5,0,1.5);
	Point*p2=new Point(1.5,0,1.5);
	Point*p3=new Point(1.5,0,-1.5);
	Point*p4=new Point(-1.5,0,-1.5);

	Point*p5=new Point(-2.5,3,2.5);
	Point*p6=new Point(2.5,3,2.5);
	Point*p7=new Point(2.5,3,-2.5);
	Point*p8=new Point(-2.5,3,-2.5);


	if(passengeres>1)
	{
		p1->z+=1.5;
		p2->z+=1.5;
		p3->z+=-1.5;
		p4->z+=-1.5;
		p5->z+=3;
		p6->z+=3;
		p7->z+=-3;
		p8->z+=-3;
	}
	glPushMatrix();

	glPushMatrix();
		glColor3f(baseColor->x,baseColor->y,baseColor->z);
		drawBase(p1,p2,p3,p4,p5,p6,p7,p8);
	glPopMatrix();

	glPushMatrix();
		glColor3f(1,1,1);
		drawSeat(p5,p6,p7,p8,seatTexture);
	glPopMatrix();

	glPushMatrix();
		glColor3f(handRestsColor->x,handRestsColor->y,handRestsColor->z);
		drawHandRests(p5,p6,p7,p8);
	glPopMatrix();

	glPopMatrix();

	glColor3f(1,1,1);
}

passengerSeat::~passengerSeat(void)
{
}
/*
color *cl=new color(0.1,0.1,0.1);
	passengerSeat *ps=new passengerSeat(cl,cl,textureSeat);
	ps->draw(2);
	*/