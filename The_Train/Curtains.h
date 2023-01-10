#include"Point.h"
#include"color.h"
#pragma once
class Curtains
{
public:
	color *cl;
	float mov, tr;
	int texture;
	Curtains(color *cl);
	void drawPart(Point *p1,Point *p2,float x,float z);
	void drawOneSide(Point *p1,Point *p2,float tran,float x,float z);
	void draw(float mov,float tr);
	virtual ~Curtains(void);
};

