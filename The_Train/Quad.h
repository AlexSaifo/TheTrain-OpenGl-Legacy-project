#include <Point.h>
#pragma once
class Quad
{
public:
	int texture;
	Point *p1, *p2, *p3, *p4;
	Quad(Point *p1, Point *p2, Point *p3, Point *p4, int texture = -1);
	~Quad(void);
	void draw();
private:
	void drawWithTexture();
	void drawWithoutTexture();
};

