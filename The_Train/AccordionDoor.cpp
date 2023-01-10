#include "AccordionDoor.h"

AccordionDoor::AccordionDoor(bool open,int texture)
{
	this->texture = texture;
	this->open= open;
}


AccordionDoor::~AccordionDoor(void)
{
}

void AccordionDoor::draw(){
	Point *p[] = {
		new Point(0,0,0,0,0),
		new Point(1,0,0,1,0),
		new Point(1,2,0,1,1),
		new Point(0,2,0,0,1),
	};

	glPushMatrix();

		glPushMatrix();
		glColor3d(1,1,1);
			glTranslated(0.8,0.8,0.05);
			if(open){
				glTranslated(-0.7,0,0);
			}
			else{
				glTranslated(0,0,0);
			}
			glScaled(0.05,0.05,0.05);
			glRotated(90 ,1,0,0);
			Circle *c = new Circle();
			c->draw();
			free(c);
		glPopMatrix();

		glPushMatrix();
		glColor3d(1,1,1);
			glTranslated(0.8,0.8,-0.05);
			if(open){
				glTranslated(-0.7,0,0);
			}
			else{
				glTranslated(0,0,0);
			}
			glScaled(0.05,0.05,0.05);
			glRotated(90 ,1,0,0);
			Circle *c2 = new Circle();
			c2->draw();
			free(c2);
		glPopMatrix();

		glPushMatrix();
		if(open){
			glScaled(0.2,1,1);
		}
		else{
			glScaled(1,1,1);
		}
		Quad *t = new Quad(p[0], p[1], p[2], p[3] ,texture);
			t->draw();
			free(t);
		glPopMatrix();
		glScaled(1,1,1);
	glPopMatrix();
}



