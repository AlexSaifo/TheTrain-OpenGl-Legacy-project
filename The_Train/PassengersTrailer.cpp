

#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include<math.h>
#include <Triangle.h>
#include <Point.h>
#include <texture.h>
#include <iostream>
#include <Quad.h>
#include <Circle.h>
#include <Cylinder.h>
#include <AccordionDoor.h>
#include<Trailer.h>
#include<cubid.h>
#include<Curtains.h>
#include<passengerSeat.h>
#include<color.h>
#include<Table.h>
#include<Chair.h>
#include "PassengersTrailer.h"
using namespace std;




int textureSeat1,textureInnerSide1,textureOuterSide1,textureCeiling1,textureFloor1,textureOuterCeiling1;
int textureWindow1,textureDoor1;

void PassengersTrailer::init1()
{
	textureDoor1=LoadTexture("door3.bmp");
	textureInnerSide1=LoadTexture("wall6.bmp");
	textureCeiling1=LoadTexture("ceilingTexture.bmp");
	textureFloor1=LoadTexture("floor2.bmp");
	textureWindow1=LoadTexture("glassTexture.bmp",50);
	textureSeat1=LoadTexture("fabric11.bmp");
	textureOuterCeiling1= LoadTexture("metalTexure.bmp");
	textureOuterSide1=LoadTexture("metalTexure.bmp");
}

bool PassengersTrailer::innerCollision1(float minX,float maxX,float minZ,float maxZ,Point *cam)
{
	if(cam->x-3.5<minX || cam->x+3.5>maxX)
		return false;
	if(cam->x-3.5<minX || cam->x+3.5>maxX)
		return false;
	if(cam->z-3.5<minZ || cam->z+3.5>maxZ)
		return false;
	if(cam->z-3.5<minZ || cam->z+3.5>maxZ)
		return false;
	return true;
}
bool PassengersTrailer::outerCollision1(float minX,float maxX,float minZ,float maxZ,Point *cam)
{
	//return true;

	//if the camere minx or maxx is in the interval[minX,maxX] 
	if((cam->x-3.5<=maxX && cam->x-3.5>=minX) || (cam->x+3.5<=maxX && cam->x+3.5>=minX))
	{
		//if the camera minz or maxz is in the intervel[minZ,maxZ]
		if((cam->z-3.5>=minZ && cam->z-3.5<=maxZ) || (cam->z+3.5>=minZ && cam->z+3.5<=maxZ))
			return false;
	}
	return true;
}
bool PassengersTrailer::collision(Point *cam)
{
	bool res=1;

	if(outerCollision1(-42.9+translate->x,42.9+translate->x,-59.9+translate->z,59.9+translate->z,cam))
		return res;
	//trailer
	res&=( innerCollision1(-42.9+translate->x,42.9+translate->x,-1000+translate->z,59.9+translate->z,cam) || ((backDoorState==1) && innerCollision1(-7+translate->x,7+translate->x,47+translate->z,73+translate->z,cam)) );

	//passengerSeats

	//00
	res&=outerCollision1(-42.9+translate->x,-12+translate->x,-59.9+translate->z,-47+translate->z,cam);
	res&=outerCollision1(-42.9+translate->x,-12+translate->x,-33+translate->z,-20.1+translate->z,cam);

	//01
	res&=outerCollision1(12+translate->x,42.9+translate->x,-59.9+translate->z,-47+translate->z,cam);
	res&=outerCollision1(12+translate->x,42.9+translate->x,-33+translate->z,-20.1+translate->z,cam);

	//10
	res&=outerCollision1(-42.9+translate->x,-12+translate->x,-19.9+translate->z,-7+translate->z,cam);
	res&=outerCollision1(-42.9+translate->x,-12+translate->x,7+translate->z,19.9+translate->z,cam);

	//11
	res&=outerCollision1(12+translate->x,42.9+translate->x,-19.9+translate->z,-7+translate->z,cam);
	res&=outerCollision1(12+translate->x,42.9+translate->x,7+translate->z,19.9+translate->z,cam);

	//20
	res&=outerCollision1(-42.9+translate->x,-12+translate->x,20.1+translate->z,33+translate->z,cam);
	res&=outerCollision1(-42.9+translate->x,-12+translate->x,47+translate->z,59.9+translate->z,cam);

	//21
	res&=outerCollision1(12+translate->x,42.9+translate->x,20.1+translate->z,33+translate->z,cam);
	res&=outerCollision1(12+translate->x,42.9+translate->x,47+translate->z,59.9+translate->z,cam);

	return res;
}
void PassengersTrailer::openCurtains(int i,int j)
{
	if(tran1[i][j]>0.5)
	{
		w1[i][j]+=0.05;
		tran1[i][j]-=0.1;
	}
}
void PassengersTrailer::closeCurtains(int i,int j)
{
	if(tran1[i][j]<2)
	{
		w1[i][j]-=0.05;
		tran1[i][j]+=0.1;
	}
}
void PassengersTrailer::interact(Point *pos)
{
	//float x=pos->x,z=pos->z;
	float tx=translate->x,tz=translate->z;



	//curtains:
	if(keys['O']) //open
	{
		//00
		if(innerCollision1(-43+tx,-12+tx,-60+tz,-20+tz,pos))
		{
			
			openCurtains(0,0);
			s[6]++;
			if (s[6]==6)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s[6]=0;
			}
			
		
		}
		//10
		else if(innerCollision1(-43+tx,-12+tx,-19+tz,19+tz,pos))
		{
		
			openCurtains(1,0);
		s[1]++;
			if (s[1]==6)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s[1]=0;
			}
		
		}

		//20
		else if(innerCollision1(-43+tx,-12+tx,20+tz,60+tz,pos))
		{
			
		openCurtains(2,0);
		
		s[2]++;
			if (s[2]==6)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s[2]=0;
			}
		}
		//01
		else if(innerCollision1(12+tx,43+tx,-60+tz,-20+tz,pos))
		{
			openCurtains(0,1);
		s[3]++;
			if (s[3]==6)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s[3]=0;
			}
		}
		//11
		else if(innerCollision1(12+tx,43+tx,-19+tz,19+tz,pos))
		{
			openCurtains(1,1);
		s[4]++;
			if (s[4]==6)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s[4]=0;
			}
		}
		//21
		else if(innerCollision1(12+tx,43+tx,20+tz,60+tz,pos))
		{
			openCurtains(2,1);
		s[5]++;
			if (s[5]==6)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s[5]=0;
			}
		
		}
		
	}
	if(keys['P']) //close
	{
		//00
		if(innerCollision1(-43+tx,-12+tx,-60+tz,-20+tz,pos))
		{
			closeCurtains(0,0);
		s[7]++;
			if (s[7]==6)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s[7]=0;
			}
		}
		//10
		else if(innerCollision1(-43+tx,-12+tx,-19+tz,19+tz,pos))
		{
			closeCurtains(1,0);
		s[8]++;
			if (s[8]==6)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s[8]=0;
			}
		}
		//20
		else if(innerCollision1(-43+tx,-12+tx,20+tz,60+tz,pos))
		{
			closeCurtains(2,0);
		s[9]++;
			if (s[9]==6)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s[9]=0;
			}
		}
		//01
		else if(innerCollision1(12+tx,43+tx,-60+tz,-20+tz,pos))
		{
			closeCurtains(0,1);
		s[10]++;
			if (s[10]==6)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s[10]=0;
			}
		}
		//11
		else if(innerCollision1(12+tx,43+tx,-19+tz,19+tz,pos))
		{
			closeCurtains(1,1);
		s[11]++;
			if (s[11]==6)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s[11]=0;
			}
		}
		//21
		else if(innerCollision1(12+tx,43+tx,20+tz,60+tz,pos))
		{
			closeCurtains(2,1);
		s[12]++;
			if (s[12]==6)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s[12]=0;
			}
		}
	}
	/////////////////////////////////////////

	//DOOR
	if(keys['O']) //open
	{
		if(innerCollision1(-8+tx,8+tx,40+tz,80+tz,pos))
		{	backDoorState=1;
		PlaySound("sounds\\doormove.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
		Sleep(400);
		}}

	if(keys['P']) //close
	{
		if(innerCollision1(-8+tx,8+tx,40+tz,80+tz,pos))
		{	backDoorState=0;
		PlaySound("sounds\\doormove.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
		Sleep(400);
		}}

}
void PassengersTrailer::drawPart(float vv,float tran)//draw two seats and one curtain
{

	glPushMatrix();
	color *cl2=new color(0.16,0.21,0.3);
		Curtains *curtain=new Curtains(cl2);

		glTranslated(42.5,20,0);
		glScaled(1.3,1.3,1.3);
		glRotated(-90,0,1,0);
		curtain->draw(vv,tran);
	glPopMatrix();	

	color *cl=new color(0.6,0.6,0.6);
	glPushMatrix();
		
		passengerSeat *ps=new passengerSeat(cl,cl,textureSeat1);

		glTranslated(25,0,-12);
		glScaled(2,2,2);
		glRotated(-90,0,1,0);
		ps->draw(2);
		free(ps);
	glPopMatrix();

	glPushMatrix();
		ps=new passengerSeat(cl,cl,textureSeat1);

		glTranslated(25,0,12);
		glScaled(2,2,2);
		glRotated(90,0,1,0);
		ps->draw(2);
		free(ps);
	glPopMatrix();

	

} 
void PassengersTrailer::draw1(Point *cam,int last)
{
	glPushMatrix();
	glTranslated(translate->x,translate->y,translate->z);

	drawPart(w1[1][1],tran1[1][1]);


	glPushMatrix();
		glTranslated(0,0,-40);
		drawPart(w1[0][1],tran1[0][1]);
	glPopMatrix();

	glPushMatrix();
		glTranslated(0,0,40);
		drawPart(w1[2][1],tran1[2][1]);
	glPopMatrix();

	glPushMatrix();
		glTranslated(-25,0,0);
		glRotated(180,0,1,0);
		glTranslated(-25,0,0);
		drawPart(w1[1][0],tran1[1][0]);
	glPopMatrix();

	glPushMatrix();
		glTranslated(-25,0,40);
		glRotated(180,0,1,0);
		glTranslated(-25,0,0);
		drawPart(w1[2][0],tran1[2][0]);
	glPopMatrix();

	glPushMatrix();
		glTranslated(-25,0,-40);
		glRotated(180,0,1,0);
		glTranslated(-25,0,0);
		drawPart(w1[0][0],tran1[0][0]);
	glPopMatrix();

	glPushMatrix();
	
		glScaled(10,10,10);
		Trailer *tr=new Trailer(textureCeiling1,textureCeiling1,textureOuterCeiling1,textureInnerSide1,textureOuterSide1,textureWindow1,textureDoor1,last);
		//Trailer *tr=new Trailer();
		//tr->drawTrailerSide(textureTrainSide);
		tr->draw(backDoorState);

		free(tr);
	glPopMatrix();

	glPopMatrix();

	interact(cam);
} 
void PassengersTrailer::Translate(Point *translate)
{
	this->translate=translate;
}
PassengersTrailer::PassengersTrailer(bool *keys)
{
	this->keys=keys;
	this->translate=new Point(0,0,0);

	for(int i=0;i<3;i++)
		for(int j=0;j<2;j++)
			w1[i][j]=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<2;j++)
			tran1[i][j]=2;
	backDoorState=0;
	for(int i=0;i<13;i++)
	{
	s[i]=5;
	}
}


PassengersTrailer::~PassengersTrailer(void)
{
}
