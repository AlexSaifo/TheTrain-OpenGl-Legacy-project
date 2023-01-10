#pragma once
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include"Point.h"
#include"quad.h"
#include "drawable.h"
#include <Circle.h>
#include <Flower.h>
class Vase :
	public Drawable
{
public:
	int texture;
	Flower *f;
	Vase(int texture = -1, int flower_petal = -1, int flower_stem = -1, int flower_disk_florets = -1);
	~Vase(void);
	void draw();
private:
	void drawCylinder(float radiusTop, float radiusBottom, float height, float bottom = 0);
};

