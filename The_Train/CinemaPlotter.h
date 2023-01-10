
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <Point.h>
#pragma once

class CinemaPlotter
{
int cinemaTextureSeat;
int cinemaTextureFloor,cinemaTextureCeiling,cinemaTextureTrainSide,cinemaTextureGlass,cinemaTextureDoor;
int cinemaMovieTexture;
int cinemaScreenTexture;
int cinemaTextureSeatBase;
int cinemaTextureOutSide;
bool isScreenOn ;
bool isDoorOpened;
Point *centerOfCinema;

public:
	CinemaPlotter(int cinemaTextureSeat, int cinemaTextureSeatBase, int cinemaTextureFloor, int cinemaTextureCeiling, int cinemaTextureTrainSide, int cinemaTextureDoor, int cinemaMovieTexture, int cinemaScreenTexture,int cinemaTextureOutSide);
	~CinemaPlotter(void);
	CinemaPlotter(void);
	void drawCinema(Point *centerOfCinema);
	void changeScreenState(Point *player, bool state);
	void changeDoorState(Point *player, bool state);
	bool innerCollisionCinema(Point *player);
	void initializeCinemaTextures();
	void AlaaTrailerinteract(Point *player,bool keys[]);
private:
	bool between(float a, float x, float b);
	bool out(float a, float x, float b);
	bool cinemaScreenCollision(Point *p);
	bool cinemaSeatesCollision(Point *p);
	bool cinemaDoorCollision(Point *p);
	
};

class CinemaSeat
{
public:
	int cinema_seat_texuture;
	int cinema_seat_base_texture;
	CinemaSeat(int cinema_seat_texuture = -1,int cinema_seat_base_texture = -1);
	~CinemaSeat(void);
	void draw(int passengeres = 1);
	void drawHandRests(Point*p1,Point*p2,Point*p3,Point*p4);
	void drawSeat(Point*p1,Point*p2,Point*p3,Point*p4,int texture);
	void drawBase(Point*p1,Point*p2,Point*p3,Point*p4,Point*p5,Point*p6,Point*p7,Point*p8);
	void drawSheered(Point*p1,Point*p2,Point*p3,Point*p4,float h,float xSheer,float zSheer,int texture);
};


