#pragma once
#include <windows.h>
#include <gl\gl.h>			
#include <gl\glu.h>			
#include <glaux.h>		
#include "Point.h"
#include <math.h>
#include "Quad.h"

#include <cubid.h>



class library
{
public:
	int WallShelfType;
		int texture;
	library(int WallShelfType,int texture);
	~library(void);
		void draw();
	private:
	void WallShelf();
	void drawWithoutTexture();
	void WallShelf2();
	void WallShelf3();
};

                     






























