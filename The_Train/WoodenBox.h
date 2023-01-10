#include <windows.h>
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <math.h>

#pragma once
class WoodenBox
{
	int texture;
	bool open;
	

public:
	WoodenBox(bool open ,int texture = -1);
	~WoodenBox(void);
	void draw(double OpenRotated);

};

