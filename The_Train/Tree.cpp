#include "Tree.h"


Tree::Tree(int tree_bark, int tree_leavies, int tree_holder_texture)
{
	this->tree_bark = tree_bark;
	this->tree_leavies = tree_leavies;
	this->tree_holder_texutre = tree_holder_texture;
}


Tree::~Tree(void)
{

}

void Tree::tree_holder(){
	
	glColor3ub(38,32,212);
	float r[] = {4,5,6,7,5.75};
	float height =  8;
	Point *center1 = new Point(0,0,0);
	Point *center2 = new Point(0,height,0);
	Point *center3 = new Point(0,(3.0/4.0)*height, 0);
	float const pi = 3.14;
	float step = pi/2;

	for(float i = 0; i < 2*pi; i += step){
		Point *a1 = new Point(r[0] * cos((float)i), center1->y, r[0] * sin((float)i));
		Point *b1 = new Point(r[1] * cos((float)i), center1->y, r[1] * sin((float)i));
		Point *c1 = new Point(r[1] * cos((float)i + step), center1->y, r[1] * sin((float)i + step));
		Point *d1 = new Point(r[0] * cos((float)i + step), center1->y, r[0] * sin((float)i + step));
		Point *a2 = new Point(r[2] * cos((float)i), center2->y, r[2] * sin((float)i));
		Point *b2 = new Point(r[3] * cos((float)i), center2->y, r[3] * sin((float)i));
		Point *c2 = new Point(r[3] * cos((float)i + step), center2->y, r[3] * sin((float)i + step));
		Point *d2 = new Point(r[2] * cos((float)i + step), center2->y, r[2] * sin((float)i + step));
		Quad *q1 = new Quad(a1,b1,c1,d1,this->tree_holder_texutre);
		Quad *q2 = new Quad(a2,b2,c2,d2, this->tree_holder_texutre);
		Quad *q3 = new Quad(a1,a2,d2,d1, this->tree_holder_texutre);
		Quad *q4 = new Quad(b1,b2,c2,c1, this->tree_holder_texutre);
		q1->draw();
		q2->draw();
		q3->draw();
		q4->draw();
		free(a1);
		free(a2);
		free(b1);
		free(b2);
		free(c1);
		free(c2);
		free(d1);
		free(d2);
		
	}
	glBegin(GL_QUADS);
	for(float i = 0; i < 2*pi; i += step){
		Point *a = new Point(r[1] * cos((float)i), center1->y, r[1] * sin((float)i));
		glVertex3f(a->x,a->y,a->z);
		free(a);
	}
	glEnd();
	glColor3ub(101,67,33);
	glBegin(GL_QUADS);
	for(float i = 0; i < 2*pi; i += step){
		Point *a = new Point(r[4] * cos((float)i), center3->y, r[4] * sin((float)i));
		glVertex3f(a->x,a->y,a->z);	
		free(a);
	}
	glEnd();
	glColor3ub(255,255,255);
	free(center1);
	free(center2);
	free(center3);
}

void Tree::draw(){
	float height = 7;
	float radius = 1;
	int tree_bark_textures_array[] = {this->tree_bark, this->tree_bark, this->tree_bark};
	Cylinder *bark = new Cylinder(radius, height, tree_bark_textures_array);
	bark->draw();
	free(bark);
	float pi = 3.14;
	float step = pi / 2;
	float height_step = 5;
	float tree_radius = 6;
	float ratio = 1.8/3.0;
	glPushMatrix();
		glTranslatef(0,height,0);
		for(int j = 0; j < 2; j++){
			for(float i = 0; i < 2 * pi; i += step){
				Point *a = new Point(tree_radius * cos(i) * (1 - ratio), height_step * ratio, tree_radius * sin(i) * (1 - ratio), (i / (2 * pi)),ratio);
				Point *b = new Point(tree_radius * cos(i + step) * (1 - ratio), height_step * ratio, tree_radius * sin(i + step) * ( 1 - ratio), ((i + step) / (2 * pi)),ratio);
				Point *c = new Point(tree_radius * cos(i + step), 0, tree_radius * sin(i + step), ((i + step) / (2 * pi)),0);
				Point *d = new Point(tree_radius * cos(i), 0, tree_radius * sin(i), (i / (2 * pi)),0);
				Quad *q = new Quad(a,b,c,d, this->tree_leavies);
				q->draw();
				free(a);
				free(b);
				free(c);
				free(d);
				free(q);
			}
			Point *points[4];
			for(int i = 0; i < 4; i++){
				points[i] = new Point(tree_radius * cos((pi/2) * i), 0, tree_radius * sin((pi/2) * i), i&1, i&2);
			}
			Quad *q = new Quad(points[0], points[1], points[2], points[3], this->tree_leavies);
			q->draw();
			for(int i = 0; i < 4; i++){
				free(points[i]);
			}
			free(q);
			glTranslatef(0,height_step * ratio,0);
		}
		for(float i = 0; i < 2 * pi; i += step){
				Point *a = new Point(tree_radius * cos(i), 0,tree_radius * sin(i), (i) / (2 * pi),0);
				Point *b = new Point(tree_radius * cos(i + step), 0,tree_radius * sin(i + step), (i + step) / (2 * pi),0);
				Point *c = new Point(0, height, 0,(2 * i + step)/(4 * pi) , 1);
				Triangle *t = new Triangle(a,b,c,this->tree_leavies);
				t->draw();
				free(t);
				free(a);
				free(b);
				free(c);
			}
		Point *points[4];
			for(int i = 0; i < 4; i++){
				points[i] = new Point(tree_radius * cos((pi/2) * i), 0, tree_radius * sin((pi/2) * i), i&1, i&2);
			}
			Quad *q = new Quad(points[0], points[1], points[2], points[3], this->tree_leavies);
			q->draw();
			for(int i = 0; i < 4; i++){
				free(points[i]);
			}
			free(q);
	glPopMatrix();
	float holder_size_scale = 0.6;
	glPushMatrix();
		glScalef(holder_size_scale,holder_size_scale,holder_size_scale);
		this->tree_holder();

	glPopMatrix();
}
