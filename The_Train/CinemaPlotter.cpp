
#include "CinemaPlotter.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <Point.h>
#include <Triangle.h>
#include <Quad.h>
#include <AccordionDoor.h>
#include<Trailer.h>
#include<cubid.h>
#include<Curtains.h>
#include<passengerSeat.h>
#include<color.h>
#include<Table.h>
#include<Chair.h>
#include<texture.h>
#include<thread>

CinemaPlotter::CinemaPlotter(int cinemaTextureSeat, int cinemaTextureSeatBase, int cinemaTextureFloor, int cinemaTextureCeiling, int cinemaTextureTrainSide, int cinemaTextureDoor, int cinemaMovieTexture, int cinemaScreenTexture,int cinemaTextureOutSide)
{
	this->cinemaMovieTexture = cinemaMovieTexture;
	this->cinemaScreenTexture = cinemaScreenTexture;
	this->cinemaTextureFloor = cinemaTextureFloor;
	this->cinemaTextureDoor = cinemaTextureDoor;
	this->cinemaTextureCeiling = cinemaTextureCeiling;
	this->cinemaTextureSeat = cinemaTextureSeat;
	this->cinemaTextureTrainSide = cinemaTextureTrainSide;
	this->cinemaTextureSeatBase = cinemaTextureSeatBase;
	this->cinemaTextureOutSide = cinemaTextureOutSide;
	this->isScreenOn = true;
	this->isDoorOpened = false;
}
CinemaPlotter::CinemaPlotter()
{
	this->cinemaMovieTexture = -1;
	this->cinemaScreenTexture = -1;
	this->cinemaTextureFloor = -1;
	this->cinemaTextureDoor = -1;
	this->cinemaTextureCeiling = -1;
	this->cinemaTextureSeat = -1;
	this->cinemaTextureTrainSide = -1;
	this->cinemaTextureSeatBase = -1;
	this->isScreenOn = true;
	this->isDoorOpened = false;
}


CinemaPlotter::~CinemaPlotter(void)
{
}



bool CinemaPlotter::between(float a, float x, float b){
	return (x >= a && x <= b);
}

bool CinemaPlotter::out(float a, float x, float b){
	return !this->between(a,x,b);
}

Point  *getCoordinate(Point *p){
	float pointMatrix[4][1] = {{p->x}, {p->y}, {p->z},{1}};
	float resMatrix[4][1] = {{0},{0},{0},{0}};
	float recievedMatrix[16];
	glGetFloatv(GL_MODELVIEW_MATRIX,recievedMatrix);
	float modelMatrix[4][4];
	for(int i = 0; i < 16; i++){
		modelMatrix[i/4][i%4] = recievedMatrix[i];
	}
	int C1 = 4, R1 = 4, C2 = 1, R2 = 4;
	for(int i = 0; i < R1; i++){
		for(int j = 0; j < C2; j++){
			resMatrix[i][j] = 0;
			for(int k = 0; k < R2; k++){
				resMatrix[i][j] += modelMatrix[i][k] * pointMatrix[k][i];
			}
		}
	}
	return new Point(resMatrix[0][0],resMatrix[1][0], resMatrix[2][0]);
}

 

void CinemaPlotter::drawCinema(Point *centerOfCinema){
	this->centerOfCinema=centerOfCinema;
	/* drawing chaires */
	glPushMatrix();
	glTranslatef(- 35,0, -43 + 6);
		/*drawing the first row */
		glPushMatrix();
			glTranslatef(-8,0,-5);
			glScalef(20,5,91);
			cubid *row = new cubid(this->cinemaTextureSeatBase,this->cinemaTextureSeatBase,this->cinemaTextureSeatBase,
				this->cinemaTextureSeatBase,this->cinemaTextureSeatBase,this->cinemaTextureSeatBase);
			row->draw();
		glPopMatrix();
		glPushMatrix();
			glScalef(2,2,2);
			color *baseColor = new color(56.0/255.0,16.0/255,16.0/255.0);
			CinemaSeat *seat = new CinemaSeat(this->cinemaTextureSeat,this->cinemaTextureSeatBase);
			glPushMatrix();
			for(int j = 0; j < 2; j++){
				glPushMatrix();
					if(j == 0){
						glTranslatef(0,3,0);
					}
					for(int i = 0; i < 7; i++){
						seat->draw();
						glTranslatef(0,0,7);
					}
				glPopMatrix();
				glTranslatef(11,0,0);
			}
			glPopMatrix();
			glPushMatrix();
			float chairSize = 14;
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
	
	/* draw screen */
	
	
	glPushMatrix();
		//screen variables
		float height = 40;
		float width = 2 * height;
		float standHeight = 5;
		float side = 2;
		float screenDepth = 3;
		//inner screen
		Point *ai = new Point(0,height + standHeight - side, -(width/2.0) + side,0,1);
		Point *bi = new Point(0,height + standHeight - side, (width/2.0) - side,1,1);
		Point *ci = new Point(0,standHeight + side, (width/2.0) - side,1,0);
		Point *di = new Point(0,standHeight + side, -(width/2.0) + side,0,0);
		// outer screen
		Point *aot = new Point(0,height + standHeight, -(width/2.0),0,1);
		Point *bot = new Point(0,height + standHeight, (width/2.0),1,1);
		Point *cot = new Point(0,standHeight, (width/2.0),1,0);
		Point *dot = new Point(0,standHeight, -(width/2.0),0,0);
		//back side of the screen
		Point *ab = new Point(screenDepth,height + standHeight - side, -(width/2.0) + side,0,1);
		Point *bb = new Point(screenDepth,height + standHeight - side, (width/2.0) - side,1,1);
		Point *cb = new Point(screenDepth,standHeight + side, (width/2.0) - side,1,0);
		Point *db = new Point(screenDepth,standHeight + side, -(width/2.0) + side,0,0);
		glTranslatef(35,0,0);
		// draw the first stand
		glPushMatrix();
			glTranslatef(0,0,(1.0/3.0) * width);
			cubid *stand1 = new cubid(this->cinemaScreenTexture,this->cinemaScreenTexture,this->cinemaScreenTexture,this->cinemaScreenTexture,this->cinemaScreenTexture,this->cinemaScreenTexture);
			glScalef(2,standHeight,2);
			stand1->draw();
		glPopMatrix();
		// draw the second stand
		glPushMatrix();
			glTranslatef(0,0,-(1.0/3.0) * width);
			cubid *stand2 = new cubid(this->cinemaScreenTexture,this->cinemaScreenTexture,this->cinemaScreenTexture,this->cinemaScreenTexture,this->cinemaScreenTexture,this->cinemaScreenTexture);
			glScalef(2,standHeight,2);
			stand2->draw();
		glPopMatrix();
		// front left quad
		Quad *q1 = new Quad(dot,di,ai,aot,this->cinemaScreenTexture);
		q1->draw();
		// fornt top quad
		Quad *q2 = new Quad(bi,bot, aot, ai,this->cinemaScreenTexture);
		q2->draw();
		// front right quad
		Quad *q3 = new Quad(ci,cot, bot, bi,this->cinemaScreenTexture);
		q3->draw();
		// front bottom quad 
		Quad *q4 = new Quad(di, dot, cot, ci,this->cinemaScreenTexture);
		q4->draw();
		//side left quad
		Quad *q5 = new Quad(db,dot,aot,ab,this->cinemaScreenTexture);
		q5->draw();
		//side top quad
		Quad *q6 = new Quad(bot, bb, ab, aot,this->cinemaScreenTexture);
		q6->draw();
		//side right quad
		Quad *q7 = new Quad(cot,cb, bb, bot,this->cinemaScreenTexture);
		q7->draw();
		// side bottom quad
		Quad *q8 = new Quad(dot, db, cb, cot,this->cinemaScreenTexture);
		q8->draw();
		// back face of the screen 
		Quad *q9 = new Quad(ab,bb,cb,db,this->cinemaScreenTexture);
		q9->draw();
		//the screen itself
		Quad *q10 = new Quad(di,ci,bi,ai,(this->isScreenOn ? this->cinemaMovieTexture : -1));
		if(!this->isScreenOn){
			glColor3f(0,0,0);
		}
		q10->draw();
		glColor3f(1,1,1);
	glPopMatrix();
	
	
	/* end of draw screen */
	/* drawing trailer */
	glPushMatrix();
	glScaled(10,10,10);
	Trailer *cinemaTrailer = new Trailer(cinemaTextureFloor,cinemaTextureCeiling,cinemaTextureTrainSide,cinemaTextureTrainSide,cinemaTextureOutSide,cinemaTextureGlass,cinemaTextureDoor);
	cinemaTrailer->drawTrailerWithoutWindows(this->isDoorOpened);
	glPopMatrix();
	free(baseColor);
	free(row);
	free(seat);
	free(ai);
	free(bi);
	free(ci);
	free(di);
	free(aot);
	free(bot);
	free(cot);
	free(dot);
	free(ab);
	free(bb);
	free(cb);
	free(db);
	free(q1);
	free(q2);
	free(q3);
	free(q4);
	free(q5);
	free(q6);
	free(q7);
	free(q8);
	free(q9);
	free(q10);
	free(stand1);
	free(stand2);
	free(cinemaTrailer);
	
}


void CinemaPlotter::changeScreenState(Point *player, bool state){
	float safty = 20;
	Point *frontLeft = new Point(this->centerOfCinema->x + 35 - safty,this->centerOfCinema->y ,this->centerOfCinema->z -38 - safty);
	Point *frontRight = new Point(this->centerOfCinema->x + 35 - safty,this->centerOfCinema->y,this->centerOfCinema->z + 38 + safty);
	Point *backLeft = new Point(this->centerOfCinema->x + 38 + safty,this->centerOfCinema->y,this->centerOfCinema->z -38 - safty);
	Point *backRight = new Point(this->centerOfCinema->x + 38+ safty,this->centerOfCinema->y,this->centerOfCinema->z + 38 +safty);
	if( between(frontLeft->x,player->x,backRight->x)){
		if(between(frontLeft->z,player->z,backRight->z)){
			this->isScreenOn = state;
		}
	}
	free(frontLeft);
	free(frontRight);
	free(backLeft);
	free(backRight);
	
	
}

bool CinemaPlotter::cinemaScreenCollision(Point *player){
	//calculate screen sides
	float safety = 2;
	Point *frontLeft = new Point(this->centerOfCinema->x + 35 - safety,this->centerOfCinema->y ,this->centerOfCinema->z -38 - safety);
	Point *frontRight = new Point(this->centerOfCinema->x + 35 - safety,this->centerOfCinema->y,this->centerOfCinema->z + 38 + safety);
	Point *backLeft = new Point(this->centerOfCinema->x + 38 + safety,this->centerOfCinema->y,this->centerOfCinema->z -38 - safety);
	Point *backRight = new Point(this->centerOfCinema->x + 38+ safety,this->centerOfCinema->y,this->centerOfCinema->z + 38 +safety);
	bool ret = true;
	// when a collision occurs return false otherwise return true

	if( between(frontLeft->x,player->x,backRight->x)){
		if(between(frontLeft->z,player->z,backRight->z)){
			ret = false;
		}
	}
	free(frontLeft);
	free(frontRight);
	free(backLeft);
	free(backRight);
	
	return ret;
}

bool CinemaPlotter::cinemaSeatesCollision(Point *p){
	//calculate seates sides

	float safety = -2;
	Point *frontLeft = new Point(this->centerOfCinema->x -7 - safety,this->centerOfCinema->y ,this->centerOfCinema->z + 55 - safety);
	Point *frontRight = new Point(this->centerOfCinema->x -7 - safety,this->centerOfCinema->y,this->centerOfCinema->z - 46 + safety);
	Point *backLeft = new Point(this->centerOfCinema->x -44 + safety,this->centerOfCinema->y,this->centerOfCinema->z + 55 - safety);
	Point *backRight = new Point(this->centerOfCinema->x - 44 + safety,this->centerOfCinema->y,this->centerOfCinema->z -46 +safety);
	bool ret = true;
	// when a collision occurs return false otherwise return true

	if( between(backRight->x,p->x,frontLeft->x)){
		if(between(backRight->z,p->z,frontLeft->z)){
			ret = false;
		}
	}
	free(frontLeft);
	free(frontRight);
	free(backLeft);
	free(backRight);
	
	return ret;
}

bool  CinemaPlotter::cinemaDoorCollision(Point *p){
	//the x coordinates for trailer is -43 --> +43
	//the z coordinates for trailer is -60 --> +60

	bool ret = true;
	//calculate Door sides

	float safety = -3;
	Point *frontLeft = new Point(this->centerOfCinema->x -43 - safety,this->centerOfCinema->y ,this->centerOfCinema->z + 60 + safety);
	Point *frontRight = new Point(this->centerOfCinema->x -43 - safety,this->centerOfCinema->y,this->centerOfCinema->z - 60 - safety);
	Point *backLeft = new Point(this->centerOfCinema->x + 43 + safety,this->centerOfCinema->y,this->centerOfCinema->z + 60 + safety);
	Point *backRight = new Point(this->centerOfCinema->x + 43 + safety,this->centerOfCinema->y,this->centerOfCinema->z - 60 -safety);
	
	// when a collision occurs return false otherwise return true

	if( out(frontLeft->x,p->x,backRight->x) || out(backRight->z, p->z, frontLeft->z)){
		ret = false;
	}
	
	if(between(frontLeft->x,p->x,backRight->x) && p->z < backRight->z){
		ret = true;
	}
	
	free(frontLeft);
	free(frontRight);
	free(backLeft);
	free(backRight);	
	if(this->isDoorOpened){
		safety = -2;
		frontLeft = new Point(this->centerOfCinema->x - 5 - safety,this->centerOfCinema->y ,this->centerOfCinema->z + 60 +safety);
		frontRight = new Point(this->centerOfCinema->x - 5 - safety,this->centerOfCinema->y,this->centerOfCinema->z + 60 - safety);
		backLeft = new Point(this->centerOfCinema->x + 5 + safety,this->centerOfCinema->y,this->centerOfCinema->z + 60 + safety);
		backRight = new Point(this->centerOfCinema->x + 5 + safety,this->centerOfCinema->y,this->centerOfCinema->z + 60 -safety);
	
		// when a collision occurs return false otherwise return true

		if( between(frontLeft->x, p->x, backRight->x)){
			ret = true;
		}
		free(frontLeft);
		free(frontRight);
		free(backLeft);
		free(backRight);
	}
	
	return ret;
}



void CinemaPlotter::changeDoorState(Point *player, bool state){
	
	float safety = -20;
	Point *frontLeft = new Point(this->centerOfCinema->x - 5 + safety,this->centerOfCinema->y ,this->centerOfCinema->z + 55 +safety);
	Point *frontRight = new Point(this->centerOfCinema->x - 5 + safety,this->centerOfCinema->y,this->centerOfCinema->z + 65 - safety);
	Point *backLeft = new Point(this->centerOfCinema->x + 5 - safety,this->centerOfCinema->y,this->centerOfCinema->z + 55 + safety);
	Point *backRight = new Point(this->centerOfCinema->x + 5 - safety,this->centerOfCinema->y,this->centerOfCinema->z + 65 -safety);
	
	// when a collision occurs return false otherwise return true

	if( between(frontLeft->x, player->x, backRight->x) && between(frontLeft->z,player->z,backRight->z )){
		PlaySound("sounds\\doormove.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
		Sleep(400);
		//PlaySound("sounds\\trainSoundEffect.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC|SND_LOOP );
		this->isDoorOpened = state;
	}
	free(frontLeft);
	free(frontRight);
	free(backLeft);
	free(backRight);
}
//o : open, p : close
void CinemaPlotter:: AlaaTrailerinteract(Point *player,bool keys[]){
	if(keys['O']){
		this->changeDoorState(player,true);
		this->changeScreenState(player,true);
	}
	if(keys['P']){
		this->changeDoorState(player,false);
		this->changeScreenState(player,false);
	}
}

bool CinemaPlotter::innerCollisionCinema(Point *player){
		float safety = -3;
		Point *frontLeft = new Point(this->centerOfCinema->x -43 + safety,this->centerOfCinema->y ,this->centerOfCinema->z + 60 - safety);
		Point *frontRight = new Point(this->centerOfCinema->x -43 + safety,this->centerOfCinema->y,this->centerOfCinema->z - 60 + safety);
		Point *backLeft = new Point(this->centerOfCinema->x + 43 - safety,this->centerOfCinema->y,this->centerOfCinema->z + 60 - safety);
		Point *backRight = new Point(this->centerOfCinema->x + 43 - safety,this->centerOfCinema->y,this->centerOfCinema->z - 60 + safety);
		bool ret = false;
		// when a collision occurs return false otherwise return true

		if( out(frontLeft->x,player->x,backRight->x) || out(backRight->z, player->z, frontLeft->z)){
			ret = true;
		}
		free(frontLeft);
		free(frontRight);
		free(backLeft);
		free(backRight);	

	// when a collision occurs return false otherwise return true so return and between functions' calls
	return ret || 
		(cinemaScreenCollision(player) && cinemaSeatesCollision(player) && cinemaDoorCollision(player));
}

void CinemaPlotter::initializeCinemaTextures(){
	// this function expects you to declare variables outside in the Global scope
	/*
	
	CinemaPlotter *cinemaPlotter;
	
	*/
	
	int cinemaTextureSeat = LoadTexture("textures/cinema_seats.bmp");
	int cinemaTextureFloor = LoadTexture("textures/floor.bmp");
	int cinemaTextureCeiling = LoadTexture("textures/cinema_roof_texture.bmp");
	int cinemaTextureTrainSide = LoadTexture("textures/cinema_roof_texture.bmp");
	int cinemaTextureGlass = LoadTexture("textures/glassTexture.bmp");
	int cinemaTextureDoor = LoadTexture("textures/cinema_roof_texture.bmp");
	int cinemaMovieTexture = LoadTexture("textures/no_signal_texture.bmp");
	int cinemaScreenTexture = LoadTexture("textures/plastic_texture.bmp");
	int cinemaTextureSeatBase = LoadTexture("textures/base_texture.bmp");
	int cinemaTextureOutSide = LoadTexture("textures/cinema_seats.bmp");
	this->cinemaTextureOutSide = cinemaTextureOutSide;
	this->cinemaMovieTexture = cinemaMovieTexture;
	this->cinemaScreenTexture = cinemaScreenTexture;
	this->cinemaTextureFloor = cinemaTextureFloor;
	this->cinemaTextureDoor = cinemaTextureDoor;
	this->cinemaTextureCeiling = cinemaTextureCeiling;
	this->cinemaTextureSeat = cinemaTextureSeat;
	this->cinemaTextureTrainSide = cinemaTextureTrainSide;
	this->cinemaTextureSeatBase = cinemaTextureSeatBase;
	this->isScreenOn = true;
	this->isDoorOpened = false;
	//cinemaPlotter = new CinemaPlotter(cinemaTextureSeat,cinemaTextureSeatBase,cinemaTextureFloor,
		//cinemaTextureCeiling,cinemaTextureTrainSide,cinemaTextureDoor,cinemaMovieTexture,cinemaScreenTexture);	
	
}

//#include "CinemaSeat.h"


CinemaSeat::CinemaSeat(int cinema_seat_texuture, int cinema_seat_base_texture)
{
	this->cinema_seat_texuture = cinema_seat_texuture;
	this->cinema_seat_base_texture = cinema_seat_base_texture;
}


CinemaSeat::~CinemaSeat(void)
{
}

void CinemaSeat::drawSheered(Point*p1,Point*p2,Point*p3,Point*p4,float h,float xSheer,float zSheer,int texture)
{
	Point *p[] = {
		new Point(p1->x,p1->y,p1->z,p1->s,p1->t), //A , 0
		new Point(p2->x,p2->y,p2->z,p2->s,p2->t), //B , 1
		new Point(p3->x,p3->y,p3->z,p3->s,p3->t), //C , 2
		new Point(p4->x,p4->y,p4->z,p4->s,p4->t), //D , 3
		new Point(p1->x+xSheer,p1->y+h,p1->z+zSheer,p1->s,p1->t), //E , 4
		new Point(p2->x+xSheer,p2->y+h,p2->z+zSheer,p2->s,p2->t), //F , 5
		new Point(p3->x+xSheer,p3->y+h,p3->z+zSheer,p3->s,p3->t), //G , 6
		new Point(p4->x+xSheer,p4->y+h,p4->z+zSheer,p4->s,p4->t)  //H , 7
		};

	Quad *test=new Quad(p[4],p[5],p[6],p[7],this->cinema_seat_base_texture);
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
void CinemaSeat::drawBase(Point*p1,Point*p2,Point*p3,Point*p4,Point*p5,Point*p6,Point*p7,Point*p8)
{
	Quad *sq1=new Quad(p1,p2,p3,p4,this->cinema_seat_base_texture);
	sq1->draw();
	free(sq1);
	
	Quad *sq2=new Quad(p5,p6,p7,p8,this->cinema_seat_base_texture);
	sq2->draw();
	free(sq2);
	
	Quad *sq3=new Quad(p1,p2,p6,p5,this->cinema_seat_base_texture);
	sq3->draw();
	free(sq3);
	
	Quad *sq4=new Quad(p2,p3,p7,p6,this->cinema_seat_base_texture);
	sq4->draw();
	free(sq4);
	
	Quad *sq5=new Quad(p3,p4,p8,p7,this->cinema_seat_base_texture);
	sq5->draw();
	free(sq5);

	Quad *sq6=new Quad(p4,p1,p5,p8,this->cinema_seat_base_texture);
	sq6->draw();
	free(sq6);
}
void CinemaSeat::drawSeat(Point*p1,Point*p2,Point*p3,Point*p4,int texture)
{
	drawSheered(p1,p2,p3,p4,1,0,0,texture);



	Point *p22=new Point(p1->x+1,p2->y,p2->z);
	Point *p33=new Point(p4->x+1,p3->y,p3->z);

	drawSheered(p1,p22,p33,p4,8,-1,0,texture);
	free(p22);
	free(p33);
}
void CinemaSeat::drawHandRests(Point*p1,Point*p2,Point*p3,Point*p4)
{
	p1->y+=2.5;
	p2->y+=2.5;
	p3->y+=2.5;
	p4->y+=2.5;


	Point*p5=new Point(p1->x,p1->y,p1->z+1);
	Point*p6=new Point(p2->x,p2->y,p2->z+1);
	
	drawSheered(p5,p6,p2,p1,1,-0.5,0,this->cinema_seat_base_texture);

	Point*p7=new Point(p3->x,p3->y,p3->z-1);
	Point*p8=new Point(p4->x,p4->y,p4->z-1);

	drawSheered(p4,p3,p7,p8,1,-0.5,0,this->cinema_seat_base_texture);
	free(p5);
	free(p6);
	free(p7);
	free(p8);

}
void CinemaSeat::draw(int passengeres)
{
	
	Point*p1 =new Point(-2.5,0,2.5,0,1);
	Point*p2=new Point(2.5,0,2.5,1,1);
	Point*p3=new Point(2.5,0,-2.5,1,0);
	Point*p4=new Point(-2.5,0,-2.5,0,0);

	Point*p5=new Point(-2.5,3,2.5,0,1);
	Point*p6=new Point(2.5,3,2.5,1,1);
	Point*p7=new Point(2.5,3,-2.5,1,0);
	Point*p8=new Point(-2.5,3,-2.5,0,0);


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
		drawBase(p1,p2,p3,p4,p5,p6,p7,p8);
	glPopMatrix();

	glPushMatrix();
		drawSeat(p5,p6,p7,p8,this->cinema_seat_texuture);
	glPopMatrix();

	glPushMatrix();
		drawHandRests(p5,p6,p7,p8);
	glPopMatrix();

	glPopMatrix();

	glColor3f(1,1,1);
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	free(p7);
	free(p8);
}
