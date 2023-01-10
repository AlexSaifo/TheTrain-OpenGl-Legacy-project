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
class Cylinder :
	public Drawable
{
public:
	int *texture ;
	bool hasTexture;
	float height;
	float radius;
	Cylinder(float radius, float height,int *texture = nullptr);
	~Cylinder(void);
	void draw();
private:
	void drawWithTexture();
	void drawWithoutTexture();
};

