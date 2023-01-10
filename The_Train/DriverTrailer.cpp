#include "DriverTrailer.h"
#include <Point.h>
#include <Trailer.h>
#include "drawable.h"
#include "Quad.h"
#include <Triangle.h>
#include <color.h>
#include <passengerSeat.h>
#include <AccordionDoor.h>
#include <Cylinder.h>
#include <cubid.h>
#include <texture.h>


DriverTrailer::DriverTrailer(Point *player,bool *keys)
{
	this->player=player;
this->keys=keys;


}
void DriverTrailer::kh2tran(float x,float z)
{
	this->x=x;
this->z=z;



}

DriverTrailer::~DriverTrailer(void)
{
}
int xxx=30;
int latency2=0;
int backDoorState2=0;
void DriverTrailer::loadkh1texture()
{
		
	
	rooftexture=LoadTexture("ceilingpaint2.bmp");
	textures[0] = LoadTexture("paint3.bmp");
	textures[1] = LoadTexture("trainwall4.bmp");
	textures[2] = LoadTexture("control_panel.bmp");
	textures[3] = LoadTexture("control_panel2.bmp");
	textures[4] = LoadTexture("trainsides3.bmp");
	textures[5] = LoadTexture("Dchair6.bmp");

	 textureDoor=LoadTexture("door2.bmp");
	 textureTrainSide=LoadTexture("brownTexture.bmp");
	
	 textureFloor=LoadTexture("floorpaint2.bmp");
	cylin[0] = LoadTexture("Dchair6.bmp");
	cylin[1] = LoadTexture("Dchair6.bmp");
	cylin[2] = LoadTexture("Dchair6.bmp");
	
	  WallPaint = LoadTexture("paint3.bmp");
	
}
void DriverTrailer::draw(){
	

	

glColor3ub(234, 221, 202);
	glPushMatrix();
		glScaled(2.5,1,1);
		Point *p[] = {
		new Point(0,0,1), //A , 0
		new Point(1,0,1), //B , 1
		new Point(1,0,0), //C , 2
		new Point(0,0,0), //D , 3
		new Point(0,2,1), //E , 4//
		new Point(1,2,1), //F , 5//
		new Point(1,2,0), //G , 6
		new Point(0,2,0), //H , 7
		new Point(1,1,2),//		8//
		new Point(0,1,2),//		9//
		new Point(1,0,2), //	10//
		new Point(0,0,2), //	11//
		new Point(1,1,1), //	12//
		new Point(0,1,1), //	13//
		new Point(0.05,2,1),    //14
		new Point(0.05,1,2), //15
		new Point(0,1.9,1), //16
		new Point(0,1,1.9), //17
		new Point(0.95,2,1), //18
		new Point(0.95,1,2), //19
		new Point(1,1.9,1), //20
		new Point(1,1,1.9), //21
		new Point(0,0.6,1), //22
		new Point(1,0.6,1), //23

		};
						
	// bottom A, B, C, D
	p[0]->s = 0;
	p[0]->t = 0;
	p[1]->s = 1;
	p[1]->t = 0;
	p[2]->s = 1;
	p[2]->t = 1;
	p[3]->s = 0;
	p[3]->t = 1;
	glPushMatrix();
	glScaled(1,1,4);

	Quad *down = new Quad (p[0], p[1], p[2], p[3],this->bottom);
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
//////////////////////////////////////////////////////
	Quad *top = new Quad(p[4], p[5], p[6], p[7], this->rooftexture);
	Quad *topin = new Quad(p[4], p[5], p[6], p[7], this->textures[1]);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);

	top->draw();
	glDisable(GL_CULL_FACE);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	topin->draw();
	glDisable(GL_CULL_FACE);
	
/////////////////////////////////////////
	// Right B, C, G, F
	p[1]->s = 0;
	p[1]->t = 0;
	p[2]->s = 1;
	p[2]->t = 0;
	p[6]->s = 1;
	p[6]->t = 1;
	p[5]->s = 0;
	p[5]->t = 1;
	
	
//////////////////////////////////////
	Quad *right = new Quad(p[1], p[2], p[6], p[5], this->textures[1]);
	Quad *rightin = new Quad(p[1], p[2], p[6], p[5], this->textures[0]);
		glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	rightin->draw();
	glDisable(GL_CULL_FACE);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	right->draw();
	glDisable(GL_CULL_FACE);
	//////////////////////////////
	// Left A, D, H, E
	p[0]->s = 0;
	p[0]->t = 0;
	p[3]->s = 1;
	p[3]->t = 0;
	p[7]->s = 1;
	p[7]->t = 1;
	p[4]->s = 0;
	p[4]->t = 1;

	Quad *left = new Quad(p[0], p[3], p[7], p[4], this->textures[1]);
	Quad *leftin = new Quad(p[0], p[3], p[7], p[4], this->textures[0]);
		glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	left->draw();
	glDisable(GL_CULL_FACE);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	leftin->draw();
	glDisable(GL_CULL_FACE);
		
	glPopMatrix();
	glPushMatrix();
		glTranslated(0,0,3);

		p[0]->s = 0;
	p[0]->t = 0;
	p[11]->s = 1;
	p[11]->t = 0;
	p[9]->s = 1;
	p[9]->t = 1;
	p[13]->s = 0;
	p[13]->t = 1;






		Quad *le=new Quad( p[0], p[11],  p[9], p[13],this->textures[4]);//left
		le->draw();



	//		Quad *right = new Quad(p[1], p[2], p[6], p[5], this->wall);
	//right->draw();
		p[1]->s = 0;
	p[1]->t = 0;
	p[10]->s = 1;
	p[10]->t = 0;
	p[8]->s = 1;
	p[8]->t = 1;
	p[12]->s = 0;
	p[12]->t = 1;
	
	




		Quad *ra=new Quad(p[1], p[10],  p[8], p[12],this->textures[4]);//right
		ra->draw();



	p[8]->s = 1;
	p[8]->t = 1;
	p[9]->s = 0;
	p[9]->t = 1;
	p[11]->s = 0;
	p[11]->t = 0;
	p[10]->s = 1;
	p[10]->t = 0;


		Quad *fr=new Quad(p[8], p[9],  p[11], p[10],this->textures[3]);//front
			fr->draw();




			p[0]->t = 0;
	p[0]->s = 1;
	p[9]->t = 0;
	p[11]->s = 1;
	p[11]->t = 1;
	p[10]->s = 0;
	p[10]->t = 1;

		Quad *bo=new Quad(p[0], p[1],  p[10], p[11],this->textures[1]);//bot
		bo->draw();



		//new Point(0,0,1), //A , 0
		//new Point(1,0,1), //B , 1
		
		p[0]->s = 0;
					p[0]->t = 0;
	p[1]->s = 1;
	p[1]->t = 0;
	p[23]->s = 1;
	p[23]->t = 1;
	p[22]->s = 0;
	p[22]->t = 1;
	
		Quad *ct1=new Quad(p[0], p[1],  p[23], p[22]);//bot
		ct1->draw();

		free(ct1);

		//new Point(0,0.6,1), //22
		//new Point(1,0.6,1), //23
		//new Point(1,1,2),//		8//
		//new Point(0,1,2),//		9//
		
		p[23]->s = 1;
	p[23]->t = 0;
	p[22]->s = 0;
	p[22]->t = 0;
	p[9]->s = 0;
	p[9]->t = 1;
	p[8]->s = 1;
	p[8]->t = 1;
		glColor3ub(255, 255, 255);

		Quad *ct2=new Quad(p[23], p[8],p[9],p[22],this->textures[2]);//bot
		ct2->draw();

		free(ct2);








	free(le);
	free(ra);	
	free(fr);	
	free(bo);
	free(top);
	free(down);
	free(left);
	free(right);
	







	
	
	

			
	Quad *q1[]={
	
		new Quad(p[4], p[9],  p[15], p[14]),//
		new Quad(p[17], p[9],  p[4], p[16]),//
		new Quad(p[8], p[19],  p[18], p[5]),
		new Quad(p[20], p[21],  p[8], p[5]),
		new Quad(p[8], p[9],  p[4], p[5]),//window
		
	};


		Triangle *t1[]={
		new Triangle( p[8], p[12],  p[5]),
		new Triangle(p[4], p[13],  p[9]),
		
		};
		
		glColor4f(1,1,1,0.2);
	for (int i = 0; i < 2; i++)
	{
			t1[i]->draw();
			free(t1[i]);
	}
	;
	
	q1[4]->draw();

	free	(q1[4]);
	glColor4f(1,1,1,1);
	glColor3ub(100, 100, 100);
	for (int i = 0; i < 4; i++)
	{
			q1[i]->draw();
			free(q1[i]);
	}
	glColor3ub(255, 255, 255);
	for(int i = 0; i < 18; i++){
		free(p[i]);
	}
	;
glPopMatrix();

glPopMatrix();

	glColor3ub(255,255,255);
}
void DriverTrailer::drawDtrailer()
{
	
	glPushMatrix();
	
	glTranslated(x,0,z);
	glRotated(180,0,1,0);
	Trailer *tr=new Trailer();
	int z;
	glPushMatrix();
	glRotated(180,0,1,0);
	glTranslated(0,0,100);
	

	glPushMatrix();
	glColor3ub(100,100,255);
		glScaled(3,3,3);
		color *colo=new color(0.866, 0.78, 0.627);
		glTranslated(9,0,-25);
		glRotated(-90,0,1,0);
		passengerSeat *ch=new passengerSeat(colo ,colo ,textures[5]);
		
		ch->draw();
		
	glPopMatrix();
	
	glPushMatrix();
		glScaled(3,3,3);
		glTranslated(-9,0,-25);
		glRotated(-90,0,1,0);
		ch->draw();
		free(ch);
		glColor3ub(255,255,255);
	glPopMatrix();


glPushMatrix();

		
		
		glTranslated(11.5,2,-74);
	/*	if (keys['F']) {
			latency2++;
			if(latency2==9){
			xxx=-xxx;
			latency2=0;
			}}*/
		glRotated(xxx,1,0,0);
	glScaled(2,20,2);
		cubid *ch2=new cubid(textures[5],textures[5],textures[5],textures[5],textures[5],textures[5]);
		
		ch2->draw();
		free(ch2);
		glPopMatrix();


	
		glPushMatrix();
		glScaled(1,2,1);
		
		glTranslated(13,0,-72.5);
	
		Cylinder *ch3=new Cylinder(4,3,cylin);
		
		ch3->draw();
		free(ch3);
		glPopMatrix();

				glPushMatrix();
			glTranslated(0,0,-140);
	glScaled(10,10,10);
		glRotated(180,0,1,0);
		glEnable(GL_CULL_FACE);
		glCullFace(GL_FRONT);
	tr->drawFrontBack(textureTrainSide);
	glDisable(GL_CULL_FACE);
	glRotated(180,0,1,0);
	AccordionDoor *doo=new AccordionDoor(backDoorState2,textureDoor);
		glTranslated(0.7,0,0);
		glRotated(180,0,1,0);
		glScaled(1.4,1.4,1);
		//doo->draw();
		free(doo);
	glPopMatrix();
	

		glPushMatrix();
		glScaled(34.5,25,20);
		glTranslated(-1.25,0,-7);
		
		draw();
		
	
		glPopMatrix();
		
		glPopMatrix();

		glPopMatrix();
		glColor3ub(255,255,255);
}
	bool DriverTrailer::kh2innerCollision(float minX,float maxX,float minZ,float maxZ,Point *cam)
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
bool DriverTrailer::kh2outerCollision(float minX,float maxX,float minZ,float maxZ,Point *cam)
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
bool pp2=true;

bool DriverTrailer::kh2collision(Point *cam)
{
	if(kh2outerCollision(-42.9+x,42.9+x,-40+z,40+z,cam))
	return true;
	if	 (backDoorState2==0){
	 pp2= kh2innerCollision(-42.9+x,42.9+x,-1000000+z,59.9+z,cam);
	}
	else{
	pp2= kh2innerCollision(-42.9+x,42.9+x,-1000000+z,100000+z,cam);
	}
	

	
	

	

	 pp2&= kh2innerCollision(-42.9+x,42.9+x,-1000000+z,40+z,cam) && kh2outerCollision(-42.9+x,-19+x,19+z,40+z,cam)&& kh2outerCollision(8+x,42.9+x,19+z,40+z,cam);
	// /*pp2&= khouterCollision(4.9,24.9,-19.9,-7,cam) && khouterCollision(4.9,24.9,7,19.9,cam);*/
	// 
	///* pp2&= khinnerCollision(-42.9,42.9,-140,-60,cam) && khouterCollision(-42.9,-8,-140,-119,cam)&& khouterCollision(19,42.9,-140,-119,cam);*/
	// 
	// 
	 
	 //
//
//
//
//	//pp2= khinnerCollision(-42.9,42.9,-59.9,w59.9,cam) && khouterCollision(4.9,24.9,-19.9,-7,cam) && khouterCollision(4.9,24.9,7,19.9,cam);
//}
//	
	if	 (keys['P']) {
		pp2=true;}
	return pp2;
	}

void DriverTrailer::kh2interact(Point *nxt,bool keys[]){

if	 (keys['F']) {
	if (!kh2outerCollision(6+x,11+x,17+z,40+z,nxt))
	{
	latency2++;
		if (latency2==5)
		{
		xxx=-xxx;
		latency2=0;
		}
	}	}}













	

