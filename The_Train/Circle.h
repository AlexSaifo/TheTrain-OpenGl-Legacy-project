#include "Triangle.h"
#include <windows.h>
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <Point.h>
#include <math.h>

#pragma once
class Circle
{
	int texture;

public:
	Circle(int texture = -1);
	~Circle(void);
	void draw();
private:
	void drawWithTexture();
	void drawWithoutTexture();
};

