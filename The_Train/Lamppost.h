#include "Triangle.h"
#include <windows.h>
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <Point.h>
#include <math.h>
#include <Circle.h>
#include <Quad.h>

#pragma once
class Lamppost
{
	int arrayOfTextureLamp[3];
	bool on ;
public:
	Lamppost(bool on,int arrayOfTextureLamp[]);
	~Lamppost(void);
	void draw();

};

