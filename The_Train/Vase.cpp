#include "Vase.h"
#include <math.h>

Vase::Vase(int texture, int flower_petal, int flower_stem, int flower_disk_florets)
{
	this->texture = texture;
	this->f = new Flower(flower_petal, flower_stem, flower_disk_florets);
}


void Vase::drawCylinder(float radiusTop, float radiusBottom, float height, float bottom ){
	float pi = 3.14;
	float step = 0.2;
	float dis = step/(2*pi);
	for(float i = 0; i < 2*pi; i += step){
		Point *a = new Point(radiusTop * cos(i), height, radiusTop * sin(i), (i)/(2*pi), (bottom + height)/(16/2.5));
		Point *b = new Point(radiusTop * cos(i + step), height, radiusTop * sin(i + step),(i + step)/(2 * pi),(bottom + height)/(16/2.5));
		Point *c = new Point(radiusBottom * cos(i + step), 0, radiusBottom * sin(i + step),( i + step)/(2 * pi),bottom/(16/2.5));
		Point *d = new Point(radiusBottom * cos(i), 0, radiusBottom * sin(i),(i)/(2 * pi),bottom/(16/2.5));
		Quad *q = new Quad(a,b,c,d,this->texture);
		q->draw();
		free(a);
		free(b);
		free(c);
		free(d);
		free(q);
	}
}

void Vase::draw(){
	float height = 16/2.5;
	float step = height/25;
	float shift = -0.5;
	glPushMatrix();
		glPushMatrix();
			glScalef(sin(shift) + 3, 1, sin(shift) + 3);
				Circle *c = new Circle(this->texture);
				c->draw();
				free(c);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0,0.75*height,0);
			glScalef(sin(shift + 0.75 * height) + 3, 1, sin(shift + 0.75 * height) + 3);
				c = new Circle();
				glColor3ub(182,109,30);
				c->draw();
				glColor3f(1,1,1);
				free(c);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0,0.1,0);
			glRotatef(90,0,1,0);
			glScalef(1.2,1.2,1.2);
			f->draw();
		glPopMatrix();

		glColor3f(1,1,1);
		for(float i = 0 ; i < height; i += step){
			float bottomRadius = sin(i + shift) + 3;
			float topRaduis = sin(i + step + shift) + 3;
			this->drawCylinder(topRaduis,bottomRadius,step,i);
			glTranslatef(0,step,0);
		}
	glPopMatrix();
}

Vase::~Vase(void)
{
	free(f);
}

