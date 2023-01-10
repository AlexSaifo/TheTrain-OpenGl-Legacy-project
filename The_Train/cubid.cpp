
#include "cubid.h"



cubid::cubid(int top, int bottom, int left, int right, int front, int back)
{
	this->top = top;
	this->back = back;
	this->bottom = bottom;
	this->front = front;
	this->right = right;
	this->left = left;
}
void cubid::draw()
{
	Point *p[] = {
		new Point(0,0,1), //A , 0
		new Point(1,0,1), //B , 1
		new Point(1,0,0), //C , 2
		new Point(0,0,0), //D , 3
		new Point(0,1,1), //E , 4
		new Point(1,1,1), //F , 5
		new Point(1,1,0), //G , 6
		new Point(0,1,0)  //H , 7
		};
	// bottom A, B, C, D
	p[0]->s = 0;
	p[0]->t = 0;
	p[1]->s = 1;
	p[1]->t = 0;
	p[2]->s = 1;
	p[2]->t = 1;
	p[3]->s = 0;
	p[3]->t = 1;

	Quad *down = new Quad (p[0], p[1], p[2], p[3],this->bottom);
	down->draw();

	// Top E, F, G, H
	p[4]->s = 0;
	p[4]->t = 0;
	p[5]->s = 1;
	p[5]->t = 0;
	p[6]->s = 1;
	p[6]->t = 1;
	p[7]->s = 0;
	p[7]->t = 1;
	
	Quad *top = new Quad(p[4], p[5], p[6], p[7], this->top);
	top->draw();

	// Front A, B, F, E 
	p[0]->s = 0;
	p[0]->t = 0;
	p[1]->s = 1;
	p[1]->t = 0;
	p[5]->s = 1;
	p[5]->t = 1;
	p[4]->s = 0;
	p[4]->t = 1;
	
	Quad *front = new Quad(p[0], p[1], p[5], p[4], this->front);
	front->draw();

	// Back D, C, G, H
	p[3]->s = 0;
	p[3]->t = 0;
	p[2]->s = 1;
	p[2]->t = 0;
	p[6]->s = 1;
	p[6]->t = 1;
	p[7]->s = 0;
	p[7]->t = 1;

	Quad *back = new Quad(p[3], p[2], p[6], p[7], this->back);
	back->draw();

	// Right B, C, G, F
	p[1]->s = 0;
	p[1]->t = 0;
	p[2]->s = 1;
	p[2]->t = 0;
	p[6]->s = 1;
	p[6]->t = 1;
	p[5]->s = 0;
	p[5]->t = 1;

	Quad *right = new Quad(p[1], p[2], p[6], p[5], this->right);
	right->draw();
	// Left A, D, H, E
	p[0]->s = 0;
	p[0]->t = 0;
	p[3]->s = 1;
	p[3]->t = 0;
	p[7]->s = 1;
	p[7]->t = 1;
	p[4]->s = 0;
	p[4]->t = 1;

	Quad *left = new Quad(p[0], p[3], p[7], p[4], this->left);
	left->draw();
	free(top);
	free(down);
	free(left);
	free(right);
	free(front);
	free(back);
	for(int i = 0; i < 8; i++){
		free(p[i]);
	}
}
	
cubid::~cubid(void)
{
}
