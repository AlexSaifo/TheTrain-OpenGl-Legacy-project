#pragma once
#include <Quad.h>
#include <Circle.h>
#include <Cylinder.h>

class car
{
public:
	Point *pp; 
	int tiercover,tara,cardoor,window,carb;
	car(int tiercover =-1,int tara=-1,int cardoor=-1,int window=-1,Point *pp=nullptr);
	~car(void);
	void draw();
private:
void drawedges();
void drawtier(int tiercover,int tara);
	
};

