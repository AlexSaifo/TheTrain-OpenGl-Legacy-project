#include <windows.h>
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <math.h>
#include <Point.h>
#pragma once
class AlexTrailer
{
	bool *keys ;
	int s2[13];
	int frontDoorStateAlex;
	double transXalex,transYalex,transZalex; 
	double openBoxsAlex[30] ;
public:
	AlexTrailer(bool *keys);
	~AlexTrailer(void);

	void draw(Point *camPos);
	void AlexTrailerInit();
	void Transalate(double x , double y , double z);

	boolean collisionAlex( Point *cam , double x=0 , double z=0);


};

