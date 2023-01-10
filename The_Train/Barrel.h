#pragma once
#include "drawable.h"

#include "Quad.h"
#include "Triangle.h"
#include <windows.h>
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <Point.h>
#include <Circle.h>
#include <Cylinder.h>

class Barrel :
	public Drawable
{
public:
	int *texture ;
	bool open;
	Barrel(bool open , int *texture = nullptr);
	~Barrel(void);
	void draw();
private:
	void drawWithTexture();
};

