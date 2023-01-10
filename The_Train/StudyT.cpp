#include "StudyT.h"
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
#include <Books.h>
#include <Cylinder.h>
#include <AccordionDoor.h>
#include<Trailer.h>
//#include<camera.h>
//#include<cubid.h>
#include<Curtains.h>
#include<passengerSeat.h>
#include<color.h>
#include<Table.h>
#include<Chair.h>


#include<library.h>
#include<car.h>
#include<Vase.h>
//#include<Lamp.h>
#include<Flower.h>
#include<DriverTrailer.h>


int latency=0;
void StudyT::khtran(float x,float z){
this->x=x;
this->z=z;
}
	

StudyT::StudyT(Point *player,bool *keys){
this->player=player;
this->keys=keys;

this->backDoorState1=0;


for (int i = 0; i < 7; i++)
{
	this->zcur[i]=2;
	this->xcur[i]=2;

}
for (int i = 0; i < 14; i++)
{
	this->s11[i]=0;
	;

}

}


StudyT::~StudyT(void)
{
}

void StudyT::loadkhtexture(){
 rooftexture=LoadTexture("ceilingpaint2.bmp");
	

	 textureDoor=LoadTexture("door2.bmp");
	 textureTrainSide=LoadTexture("cinema_seats.bmp");
	
	 textureFloor=LoadTexture("floorpaint2.bmp");
	 textureGlass=LoadTexture("glassTexture.bmp",50);
	
	  WallPaint = LoadTexture("paint3.bmp");
	 bookCover = LoadTexture("bookback1.bmp");
	
	 TableTexture = LoadTexture("table3.bmp");
	
	chairtexture= LoadTexture("chair7.bmp");
	t[0] = LoadTexture("flower_disk_florets.bmp");
	t[1] = LoadTexture("flower_petal.bmp");
	t[2] = LoadTexture("flower_stem.bmp");
	t[3] = LoadTexture("photo.bmp");
	this->vas=new Vase(t[3],t[1],t[2],t[0]);
}




void StudyT::draw(){
	////////////////////////////////////
	glPushMatrix();
	glTranslated(x,0,z);

	glPushMatrix();
	glScaled(3,1.5,3);
	glTranslated(0,8,0);
	drawbooks();

	glPopMatrix();
	glPushMatrix();
	//glTranslated(-13,0,0);
	////glRotated(90,0,1,0);
	//glScaled(3,3,3);
	glColor3ub(200,200,200);

	Chair *ch=new Chair(chairtexture);
		drawchair(ch,'r',-33);
			drawchair(ch,'r',-19.8);
		drawchair(ch,'r',-6.6);
		drawchair(ch,'r',6.6);
		drawchair(ch,'r',19.8);
		drawchair(ch,'r',33);

		drawchair(ch,'l',33);
			drawchair(ch,'l',19.8);
		drawchair(ch,'l',6.6);
		drawchair(ch,'l',-6.6);
		drawchair(ch,'l',-19.8);
			drawchair(ch,'l',-33);
		
			
										

	glPopMatrix();
	glColor3ub(255,255,255);
	glColor3ub(234, 221, 202);
	////////////////////////////////////////
	glPushMatrix();
	glTranslated(-12,9.1,-40);
	glScaled(20,1,80);
	
	cubid *li=new cubid(TableTexture,TableTexture,TableTexture,TableTexture,TableTexture,TableTexture);


	li->draw();


	glPopMatrix();

	/////////////////////////////////////////
	draw7waml(0);
	draw7waml(-30);
	draw7waml(+36);
	//////////////////////////////////////////////////////////////////////////
	glPushMatrix();
	
	glScaled(4,4,4);
	
	
	library *li2=new library(1,TableTexture);

	glPushMatrix();
	glTranslated(-10.5,0,-3.5);
	glRotated(90,0,1,0);
	li2->draw();

	glPopMatrix();
		glPushMatrix();
	glTranslated(10.5,0,-6.5);
	glRotated(-90,0,1,0);
	li2->draw();

	glPopMatrix();
	library *li3=new library(2,TableTexture);

	glPushMatrix();
	glTranslated(-10.7,4.7,5);
	glRotated(90,0,1,0);
	li3->draw();

	glPopMatrix();
		glPushMatrix();
	glTranslated(10.7,4.7,5.3);
	glRotated(-90,0,1,0);
	li3->draw();
	glPopMatrix();
	glPopMatrix();
	///////////////
		library *li4=new library(3,TableTexture);

	glPushMatrix();
	glScaled(2,4,2);
	glTranslated(-9.5,0,28);
	glRotated(180,0,1,0);
	li4->draw();

	glPopMatrix();
		glPushMatrix();
		glScaled(2,4,2);
	glTranslated(15.5,0,28);
	glRotated(180,0,1,0);
	li4->draw();

	glPopMatrix();
	
	
	Table *lib4=new Table(TableTexture);
	glPushMatrix();
		glScaled(1,3,2);
	glTranslated(40,0,-28);
	
	lib4->draw();

	glPopMatrix();

	glPushMatrix();
		glScaled(1,3,2);
	glTranslated(-40,0,-28);
	
	lib4->draw();

	glPopMatrix();


	/////////////////////////////////////////////
	glColor3ub(255,255,255);	
	
//////////////////////////////////////////////////////////////////////////////////////////////////////

	
	color *col2=new color(0.866, 0.78, 0.627);
		Curtains *curtain1=new Curtains(col2);
		studyingcurtains(curtain1,1,0);
		studyingcurtains(curtain1,2,40);
	studyingcurtains(curtain1,3,-40);
	studyingcurtains(curtain1,4,0);
		studyingcurtains(curtain1,5,40);
	studyingcurtains(curtain1,6,-40);
	glColor3ub(255,255,255);
/////////////////////////////////////////////////////////////////////////////////////////////////////////
	drawVase('l');
	glPushMatrix();
	glTranslated(80,0,0);
	drawVase('r');
	glPopMatrix();
///////////////////////////////////////////	
	glPushMatrix();
	glColor3ub(234, 221, 202);
		glScaled(10,10,10);
		Trailer *tr=new Trailer(textureFloor,rooftexture,bookCover,WallPaint,textureTrainSide,textureGlass,textureDoor);
		//Trailer *tr=new Trailer();
		
		tr->draw(backDoorState1);

	glPopMatrix();

glPopMatrix();
glColor3ub(255,255,255);


}
void StudyT:: drawVase(char s)
{
int xvas=25;

glPushMatrix();
if (s=='r')
{
	xvas=16.5;
}
glTranslated(-40,20,xvas);
glScaled(0.5,0.5,0.5);

vas->draw();
glPopMatrix();
  
//glPushMatrix();
//glTranslated(-40,2,16);
//glScaled(0.5,0.5,0.5);
//glRotated(180,0,1,0);
//vas->draw();
//glPopMatrix();

glPushMatrix();
glTranslated(-40,14,-55.5);
glScaled(0.8,0.8,0.8);
glRotated(180,0,1,0);
vas->draw();
glPopMatrix();

/*///////////////////////////////////
glPushMatrix();
glTranslated(-28,12,25);
glScaled(1.5,1.5,1.5);
glRotated(90,0,1,0);
Point *po=new Point(255,100,100);
car *ca=new car(-1,-1,-1,-1,po,-1);
ca->draw();
glPopMatrix();

glPushMatrix();
glTranslated(-28,18,16);
glScaled(1.5,1.5,1.5);
glRotated(90,0,1,0);
ca->draw();
glPopMatrix();
///*//////////////


}


void StudyT::studyingcurtains(Curtains *curtain,int y,float x)
{			
	if (y==1)
	{
	glPushMatrix();
		glTranslated(42.6,20,x);
		glScaled(1.3,1.3,1.3);
		glRotated(-90,0,1,0);
		curtain->draw(0,xcur[0]);
	glPopMatrix();
	}
	if (y==2)
	{
	glPushMatrix();
		glTranslated(42.6,20,x);
		glScaled(1.3,1.3,1.3);
		glRotated(-90,0,1,0);
		curtain->draw(0,xcur[1]);
	glPopMatrix();
	}
	if (y==3)
	{
	glPushMatrix();
		glTranslated(42.6,20,x);
		glScaled(1.3,1.3,1.3);
		glRotated(-90,0,1,0);
		curtain->draw(0,xcur[2]);
	glPopMatrix();
	}
	////////////////////////////////////////////////////
	if (y==4)
	{
	glPushMatrix();
		glTranslated(-42.6,20,x);
		glScaled(1.3,1.3,1.3);
		glRotated(90,0,1,0);
		curtain->draw(0,xcur[3]);
	glPopMatrix();
	}
	if (y==5)
	{
	glPushMatrix();
		glTranslated(-42.6,20,x);
		glScaled(1.3,1.3,1.3);
		glRotated(90,0,1,0);
		curtain->draw(0,xcur[4]);
	glPopMatrix();
	}
		if (y==6)
	{
	glPushMatrix();
		glTranslated(-42.6,20,x);
		glScaled(1.3,1.3,1.3);
		glRotated(90,0,1,0);
		curtain->draw(0,xcur[5]);
	glPopMatrix();
	}

		}


void StudyT::draw7waml(float x){ 

		//////////////////////////////////////////////////////////////////////////
	glPushMatrix();
	glTranslated(0,0,x);
		glPushMatrix();
		glRotated(90,0,1,0);
	glTranslated(0,0,-6);
	glScaled(3,1,10);
	
	cubid *li2=new cubid(TableTexture,TableTexture,TableTexture,TableTexture,TableTexture,TableTexture);


	li2->draw();


	glPopMatrix();
		//////////////////////////////////////////////////////////////////////////
		glPushMatrix();
	
	glTranslated(-2,0,-2.5);
	glScaled(2,9,2);
	
	cubid *li3=new cubid(TableTexture,TableTexture,TableTexture,TableTexture,TableTexture,TableTexture);


	li3->draw();


	glPopMatrix();
	////////////////////////////////////////////////////////////////////////////
		glPushMatrix();
	glTranslated(-2.5,0,-6.5);
	glScaled(3,1,10);
	
	cubid *li1=new cubid(TableTexture,TableTexture,TableTexture,TableTexture,TableTexture,TableTexture);


	li1->draw();


	glPopMatrix();
	glPopMatrix();
		//////////////////////////////////////////////////////////////////////////
	}
int xchair=-40;
void StudyT::drawchair(Chair *ch,char s,int xchair){
		
	if (s=='r')
	{

		glPushMatrix();
	glTranslated(-13,0,xchair);
	glRotated(90,0,1,0);

	glScaled(3,3,3);
	
		ch->draw();
	
		glPopMatrix();
	}
	if (s=='l')
	{
		glPushMatrix();
	glTranslated(9,0,xchair);
	glRotated(-90,0,1,0);
	glScaled(3,3,3);
	
		ch->draw();
	
		glPopMatrix();
	}
	



}
void StudyT::khinteract(Point *nxt,bool keys[]){

	
	if(keys['O']) //open
	{
		if (!khouterCollision(-10+x,10+x,51.6+z,65.9+z,nxt)){
		latency++;
		if (latency==5)
		{

		
			if (backDoorState1==0)
			{
				backDoorState1=1;
				PlaySound("sounds\\doormove.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
		
				latency=0;
			}
			else
			{
				backDoorState1=0;
				PlaySound("sounds\\doormove.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
		
				latency=0;
			}
			
		}}

		
	
	/*if (!khouterCollision(-10+x,10+x,-59.9+z,-51.6+z,nxt)){
		latency++;
		if (latency==5)
		{

		
			if (backDoorState==0)
			{
				backDoorState=1;
				
				latency=0;
			}
			else
			{
				backDoorState=0;
				latency=0;
			}
			
		}}*/
	if (!khouterCollision(-42.9+x,-37.5+x,27.2+z,50+z,nxt))
	{
		if (xcur[4]<=zcur[4])
			{
				xcur[4]-=0.1;
				s11[1]++;
			if (s11[1]==1)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s11[1]=-10;
			}
				if (xcur[4]<=0.2)
				zcur[4]=0;

				
				

			}
			if(xcur[4]>zcur[4])
			{
				xcur[4]+=0.1;
				s11[2]++;
			if (s11[2]==1)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s11[2]=-10;
			}
				if (xcur[4]>=2)
				zcur[4]=2.5;
			}
}

	if (!khouterCollision(-42.9+x,-37.5+x,-13.5+z,14.2+z,nxt))
	{
	
	if (xcur[3]<=zcur[3])
			{
				xcur[3]-=0.1;
					s11[3]++;
			if (s11[3]==1)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s11[3]=-10;
			}
				if (xcur[3]<=0.2)
				zcur[3]=0;

				
				

			}
			if(xcur[3]>zcur[3])
			{
				xcur[3]+=0.1;
					s11[4]++;
			if (s11[4]==1)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s11[4]=-10;
			}
				if (xcur[3]>=2)
				zcur[3]=2.5;
			}	}
	if (!khouterCollision(37.5+x,42.9+x,-13.5+z,13.5+z,nxt))
	{
	if (xcur[0]<=zcur[0])
			{
				xcur[0]-=0.1;
					s11[5]++;
			if (s11[5]==1)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s11[5]=-10;
			}
				if (xcur[0]<=0.2)
				zcur[0]=0;

				
				

			}
			if(xcur[0]>zcur[0])
			{
				xcur[0]+=0.1;
					s11[6]++;
			if (s11[6]==1)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s11[6]=-10;
			}
				if (xcur[0]>=2)
				zcur[0]=2.5;
			}

		}
	if (!khouterCollision(37.5+x,42.9+x,26.5+z,50+z,nxt))
	{
		if (xcur[1]<=zcur[1])
			{
				xcur[1]-=0.1;
					s11[7]++;
			if (s11[7]==1)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s11[7]=-10;
			}
				if (xcur[1]<=0.2)
				zcur[1]=0;

				
				

			}
			if(xcur[1]>zcur[1])
			{
				xcur[1]+=0.1;
					s11[8]++;
			if (s11[8]==1)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s11[8]=-10;
			}
				if (xcur[1]>=2)
				zcur[1]=2.5;
			}}

	if (!khouterCollision(37.5+x,42.9+x,-52.5+z,-27+z,nxt))
	{
		if (xcur[2]<=zcur[2])
			{
				xcur[2]-=0.1;
					s11[9]++;
			if (s11[9]==1)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s11[9]=-10;
			}
				if (xcur[2]<=0.2)
				zcur[2]=0;

				
				

			}
			if(xcur[2]>zcur[2])
			{
				xcur[2]+=0.1;
				s11[10]++;
			if (s11[10]==1)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s11[10]=-10;
			}
				if (xcur[2]>=2)
				zcur[2]=2.5;
			}

			}
	if (!khouterCollision(-42.9+x,-37.5+x,-52.5+z,-27+z,nxt))
	{
		
			if (xcur[5]<=zcur[5])
			{
				xcur[5]-=0.1;
					s11[11]++;
			if (s11[11]==1)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s11[11]=-10;
			}
				if (xcur[5]<=0.2)
				zcur[5]=0;

				
				

			}
			if(xcur[5]>zcur[5])
			{
				xcur[5]+=0.1;
					s11[12]++;
			if (s11[12]==1)
			{
				PlaySound("sounds\\curSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				s11[12]=-10;
			}
				if (xcur[5]>=2)
				zcur[5]=2.5;
			}
	
				}
	}}


	bool StudyT::khinnerCollision(float minX,float maxX,float minZ,float maxZ,Point *cam)
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
bool StudyT::khouterCollision(float minX,float maxX,float minZ,float maxZ,Point *cam)
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
bool pp=true;

bool StudyT::khcollision(Point *cam)
{
	if(khouterCollision(-42.9+x,42.9+x,-59+z,59.9+z,cam))
		return true;
	
	if	 (backDoorState1==0){
	 pp= khinnerCollision(-42.9+x,42.9+x,-1000000+z,59.9+z,cam);
	}
	else{
	pp= khinnerCollision(-42.9+x,42.9+x,-1000000+z,100000+z,cam);
	}
	///////////////////////

	pp&= khinnerCollision(-42.9+x,42.9+x,-1000000+z,1000000+z,cam);
	

	 pp&= khouterCollision(-42.9+x,-38.5+x,-59.9+z,-52.5+z,cam) && khouterCollision(38+x,42.9+x,-59.9+z,-52.5+z,cam) ;

	 pp&= khouterCollision(-42.9+x,-38+x,-28+z,-13.5+z,cam) && khouterCollision(38+x,42.9+x,-27+z,-13.5+z,cam) ;

	 pp&= khouterCollision(-42.9+x,-38.5+x,14.2+z,27.2+z,cam) && khouterCollision(38.5+x,42.9+x,13.5+z,26.5+z,cam) ;

	 pp&= khouterCollision(-42.9+x,-10+x,51.6+z,59.9+z,cam) && khouterCollision(10+x,42.9+x,51.6+z,59.9+z,cam) ;
	  pp&= khouterCollision(-42.9+x,-8+x,-60.9+z,-59+z,cam) && khouterCollision(8+x,42.9+x,-60.9+z,-59+z,cam) ;
	 pp&= khouterCollision(-15.9+x,12+x,-38.5+z,40+z,cam);

	// pp&= khinnerCollision(-42.9,42.9,-140,100000,cam) && khouterCollision(-42.9,-8,-140,-119,cam)&& khouterCollision(19,42.9,-140,-119,cam);
	// /*pp&= khouterCollision(4.9,24.9,-19.9,-7,cam) && khouterCollision(4.9,24.9,7,19.9,cam);*/
	// 
	///* pp&= khinnerCollision(-42.9,42.9,-140,-60,cam) && khouterCollision(-42.9,-8,-140,-119,cam)&& khouterCollision(19,42.9,-140,-119,cam);*/
	// 
	// 
	 
	 //	
//
//
//
//	//pp= khinnerCollision(-42.9,42.9,-59.9,59.9,cam) && khouterCollision(4.9,24.9,-19.9,-7,cam) && khouterCollision(4.9,24.9,7,19.9,cam);
//}
//	
	if	 (keys['P']) {
		pp=true;}
	return pp;
	}
void StudyT::drawbooks(void)
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
void StudyT::drawOneBook(int cover ,float x ,float y){


		glPushMatrix();
		glTranslated(x,0,0);
		glRotated(y,0,0,1);
		
		
	cubid *book1=new cubid (cover,cover,cover,cover,cover,cover);
	///*glTranslated(0.05,0,-0.7);
	glScaled(0.3,2,0.6);
	book1->draw();
	glPopMatrix();














}
void StudyT::drawBooksInShelf(float x,float y)
{
	if (y==1)
	{
	glPushMatrix();
		glTranslated(0,x,0);
	glTranslated(13.2,1.5,-9.65);
	glRotated(-90,0,1,0);
		drawOneBook( bookCover,1,-20);
		drawOneBook( WallPaint,1.5,-15);
	
		drawOneBook( chairtexture,2,-10);
		drawOneBook( textureFloor,2.5,-4);
		glTranslated(1.8,0,0);
			drawOneBook( bookCover,1,-20);
		drawOneBook( WallPaint,1.5,-15);
	
		drawOneBook( chairtexture,2,-10);
		drawOneBook( textureFloor,2.5,-4);
		glTranslated(0,1,0);
		glScaled(1,0.8,1);
		drawOneBook( bookCover,1,-22);
		glPopMatrix();
	}
	if(y==2)
	{
	glPushMatrix();
		glTranslated(0,x,0);
	glTranslated(13.2,1.5,-9.65);
	glRotated(-90,0,1,0);
		drawOneBook( bookCover,1,-20);
		drawOneBook( WallPaint,1.5,-15);
	
		drawOneBook( chairtexture,2,-10);
		drawOneBook( textureFloor,2.5,-4);
	glPopMatrix();
	
	
	
	
	
	
	}
	

}
void StudyT::drawIn1()
{

	drawBooksInShelf(0,1);
	drawBooksInShelf(4,1);
	drawBooksInShelf(-4,1);
	drawBooksInShelf(-8,1);

}
void StudyT::drawIn2()
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
	