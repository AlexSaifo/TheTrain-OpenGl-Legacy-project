#include "Circle.h"

Circle::Circle(int texture)
{
	this->texture = texture;
}


Circle::~Circle(void)
{
}

void Circle::draw(){
	if(this->texture != -1){
		this->drawWithTexture();
		return;
	}
	this->drawWithoutTexture();
}

void Circle::drawWithTexture(){
	Point *center = new Point(0,0,0,0.5,0.5);
	float pi = 3.14;
	float step = 0.2;
	for(float i = 0; i < 2*pi; i += step){
		Point *x = new Point( cos(i), 0,sin(i), 0.5 * cos(i) + 0.5, 0.5 * sin(i) + 0.5);
		Point *y = new Point( cos(i + step), 0,sin(i + step), 0.5 * cos(i + step) + 0.5, 0.5 * sin(i + step) + 0.5);
		Triangle *t = new Triangle(center,x,y,this->texture);
		t->draw();
		free(t);
		free(x);
		free(y);
	}
	free(center);
}

void Circle::drawWithoutTexture(){
	Point *center = new Point(0,0,0,0.5,0.5);
	float pi = 3.14;
	float step = 0.2;
	for(float i = 0; i < 2*pi; i += step){
		Point *x = new Point( cos(i), 0,sin(i));
		Point *y = new Point( cos(i + step), 0,sin(i + step));
		Triangle *t = new Triangle(center,x,y);
		t->draw();
		free(t);
		free(x);
		free(y);
	}
	free(center);
}