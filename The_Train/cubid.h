#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include"Point.h"
#include"quad.h"
#include "drawable.h"
#pragma once
class cubid
{
public:
	
	int top, bottom, left, right, front , back;
	
	cubid(int top = -1, int bottom = -1, int left = -1 , int right = -1, int front = -1, int back = -1);
	void draw(void);
	virtual ~cubid(void);
	private:
	void drawWithTexture();
	void drawWithoutTexture();

};

