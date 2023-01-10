#include "Cylinder.h"

Cylinder::Cylinder(float radius, float height, int *texture)
{
	this->texture = texture;
	this->radius = radius;
	this->height = height;
}


Cylinder::~Cylinder(void)
{
}

void Cylinder::draw(){
	if(this->texture != nullptr){
		this->drawWithTexture();
		return;
	}
	this->drawWithoutTexture();

}

void Cylinder::drawWithTexture(){
	int texture_id1 = this->texture[0];
	int texture_id2 = this->texture[1];
	int texture_id3 = this->texture[2];
	
	glPushMatrix();
		glScalef(this->radius,1,this->radius);
		Circle *down = new Circle(texture_id3);
		down->draw();
		free(down);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,height,0);
		glScalef(this->radius,1,this->radius);
		Circle *top = new Circle(texture_id1);
		top->draw();
		free(top);
	glPopMatrix();

	float pi = 3.14;
	float step = 0.2;
	float dis = step/(2*pi);
	float last = 0;
	for(float i = 0; i < 2*pi; i += step){
		Point *a = new Point(this->radius * cos(i), this->height, this->radius * sin(i), last, 1);
		Point *b = new Point(this->radius * cos(i + step), this->height, this->radius * sin(i + step), last + dis, 1);
		Point *c = new Point(this->radius * cos(i + step), 0, this->radius * sin(i + step), last + dis, 0);
		Point *d = new Point(this->radius * cos(i), 0, this->radius * sin(i), last, 0);
		Quad *q = new Quad(a,b,c,d,texture_id2);
		q->draw();
		free(a);
		free(b);
		free(c);
		free(d);
		free(q);
		last += dis;
	}

}

void Cylinder::drawWithoutTexture(){
	glPushMatrix();
		glScalef(this->radius,1,this->radius);
		Circle *down = new Circle();
		down->draw();
		free(down);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,height,0);
		glScalef(this->radius,1,this->radius);
		Circle *top = new Circle();
		top->draw();
		free(top);
	glPopMatrix();

	float pi = 3.14;
	float step = 0.2;
	float dis = step/(2*pi);
	float last = 0;
	for(float i = 0; i < 2*pi; i += step){
		Point *a = new Point(this->radius * cos(i), this->height, this->radius * sin(i));
		Point *b = new Point(this->radius * cos(i + step), this->height, this->radius * sin(i + step));
		Point *c = new Point(this->radius * cos(i + step), 0, this->radius * sin(i + step));
		Point *d = new Point(this->radius * cos(i), 0, this->radius * sin(i));
		Quad *q = new Quad(a,b,c,d);
		q->draw();
		free(a);
		free(b);
		free(c);
		free(d);
		free(q);
	}
}
