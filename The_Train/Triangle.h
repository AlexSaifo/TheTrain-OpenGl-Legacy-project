#include <Point.h>

#pragma once
class Triangle
{
public:
	int texture;
	Point *p1,*p2,*p3;
	Triangle(Point *p1, Point *p2, Point *p3, int texture = -1);
	~Triangle(void);
	void draw();
private:
	void drawWithTexture();
	void drawWithoutTexture();
};

