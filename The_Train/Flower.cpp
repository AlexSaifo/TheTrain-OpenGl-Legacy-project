#include "Flower.h"


Flower::Flower(int flower_petal, int flower_stem , int flower_disk_florets)
{
	this->flower_disk_florets = flower_disk_florets;
	this->flower_petal = flower_petal;
	this->flower_stem = flower_stem;
	float numOfLeaves = 60;
	float flowerRadius = 1;
	float pi = 3.14;
	float step2 = (2*pi)/10;
	for(int l = 0; l+2 < numOfLeaves * 3; l+= 3){
			float i = rand() + l;
			float y = ((float)(rand()%4))/10.0;
			this->leavies[l] = new Point(flowerRadius * cos(i), 0,flowerRadius * sin(i), 0,0);
			this->leavies[l + 1] = new Point(flowerRadius * cos(i + step2), 0,flowerRadius * sin(i + step2),1,0);
			this->leavies[l + 2] = new Point(2 * flowerRadius * cos((2 *i + step2)/2), y - 0.1,2 * flowerRadius * sin((2 * i + step2)/2),0.5,1);
		}

}


Flower::~Flower(void)
{
	for(int i = 0; i < 30 * 3; i++){
		free(this->leavies[i]);
	}
}

void Flower::draw(){
	float r = 20;
		float const pi = 3.14;
		float step = 0.03;
		Point *centerOfCircle = new Point(r,0,0);
		float last = 0;
		for(float i = 0; i < (pi/8); i+= step, last = i){
			glPushMatrix();
			glTranslatef(r * cos(i) - centerOfCircle->x,r * sin(i) - centerOfCircle -> y, 0);
			glRotatef((180*i)/pi,0,0,1);
			Point *c1 = new Point(r * cos(i) - centerOfCircle->x, r * sin(i) - centerOfCircle -> y, 0);
			Point *c2 = new Point(r * cos(i + step) - centerOfCircle->x,r * sin(i + step) - centerOfCircle -> y, 0);
			int textures_flower_stem[] = {this->flower_stem, this->flower_stem, this->flower_stem};
			Cylinder *current = new Cylinder(0.2f,this->distance(c1,c2), textures_flower_stem);
			current->draw();
			glPopMatrix();
			free(c1);
			free(c2);
			free(current);
		}
		
		glPushMatrix();

		glTranslatef(r * cos(last) - centerOfCircle->x,r * sin(last) - centerOfCircle -> y, 0);
		glRotatef((180*last)/pi,0,0,1);
		glTranslatef(0,0.01,0);
		
		Circle *c = new Circle(this->flower_disk_florets);
		c->draw();
		for(int l = 0; l+2 < 60 * 3; l+= 3){
			Triangle *t = new Triangle(this->leavies[l],this->leavies[l+1],this->leavies[l+2], this->flower_petal);
			t->draw();
			free(t);
		}
		glPopMatrix();

		free(centerOfCircle);
		free(c);
}

float Flower::distance(Point *p1, Point *p2){
	return sqrt(pow(p1->x - p2->x,2) + pow(p1->y - p2->y,2) + pow(p1->z - p2->z,2));
}

