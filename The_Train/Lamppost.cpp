#include <Lamppost.h>
#include <Point.h>
#include <GLAUX.H>

Lamppost::Lamppost(bool on,int arrayOfTextureLamp[])
{
	this->arrayOfTextureLamp[0] = arrayOfTextureLamp[0];
	this->arrayOfTextureLamp[1] = arrayOfTextureLamp[1];
	this->arrayOfTextureLamp[2] = arrayOfTextureLamp[2];
	this->on= on;
}


Lamppost::~Lamppost(void)
{
}


void DrawCube(){

	glPushMatrix();

		glBegin(GL_QUADS); /*TOP*/
			glTexCoord2d(0,0);
			glVertex3f(0.0f , 1.0f ,-1.0f);
			glTexCoord2d(1,0);
			glVertex3f(0.0f,1.0f ,0.0f);
			glTexCoord2d(1,1);
			glVertex3f(1.0f,1.0f ,0.0f);
			glTexCoord2d(0,1);
			glVertex3f(1.0f,1.0f ,-1.0f);
		glEnd();

		glBegin(GL_QUADS); /*Bottom*/
			glTexCoord2d(0,0);
			glVertex3f(0.0f , 0.0f ,-1.0f);
			glTexCoord2d(1,0);
			glVertex3f(0.0f,0.0f ,0.0f);
			glTexCoord2d(1,1);
			glVertex3f(1.0f,0.0f ,0.0f);
			glTexCoord2d(0,1);
			glVertex3f(1.0f,0.0f ,-1.0f);
		glEnd();

		glBegin(GL_QUADS); /*Front*/
			glTexCoord2d(0,0);
			glVertex3f(0,0 ,0);
			glTexCoord2d(1,0);
			glVertex3f(0.0f,1.0f ,0);
			glTexCoord2d(1,1);
			glVertex3f(1.0f,1.0f ,0);
			glTexCoord2d(0,1);
			glVertex3f(1.0f,0 ,0);
		glEnd();

		glBegin(GL_QUADS); /*Back*/
			glTexCoord2d(0,0);
			glVertex3f(0,0 ,-1.0f);
			glTexCoord2d(1,0);
			glVertex3f(0.0f,1.0f ,-1.0f);
			glTexCoord2d(1,1);
			glVertex3f(1.0f,1.0f ,-1.0f);
			glTexCoord2d(0,1);
			glVertex3f(1.0f,0 ,-1.0f);
		glEnd();

		glBegin(GL_QUADS);/*Left*/
			glTexCoord2d(0,0);
			glVertex3f(0,0 ,-1.0f);
			glTexCoord2d(1,0);
			glVertex3f(0.0f,1.0f ,-1.0f);
			glTexCoord2d(1,1);
			glVertex3f(0.0f,1.0f ,0.0f);
			glTexCoord2d(0,1);
			glVertex3f(0,0 ,0.0f);
		glEnd();

		glBegin(GL_QUADS); /*Right*/
			
			glTexCoord2d(0,0);
			glVertex3f(1.0f,0 ,-1.0f);
			glTexCoord2d(1,0);
			glVertex3f(1.0f,1.0f ,-1.0f);
			glTexCoord2d(1,1);
			glVertex3f(1.0f,1.0f ,0.0f);
			glTexCoord2d(0,1);
			glVertex3f(1.0f,0 ,0.0f);
		glEnd();

	glPopMatrix();

	
}

void DrawTriangle(Point p1, Point p2, Point p3) {
	glBegin(GL_TRIANGLES);
		glVertex3f(p1.x, p1.y, p1.z);
		glVertex3f(p2.x, p2.y, p2.z);
		glVertex3f(p3.x, p3.y, p3.z);
	glEnd( );
}

void DrawSquare(Point p1, Point p2, Point p3, Point p4) {
	glBegin(GL_QUADS);

		glTexCoord2d(0,0);
		glVertex3f(p1.x, p1.y, p1.z);

		glTexCoord2d(1,0);
		glVertex3f(p2.x, p2.y, p2.z);

		glTexCoord2d(1,1);
		glVertex3f(p3.x, p3.y, p3.z);

		glTexCoord2d(0,1);
		glVertex3f(p4.x, p4.y, p4.z);
	glEnd( );
}

void DrawCircle(Point center , float rad ){
	float angle=0, x=rad, y=0, z=0;
	for(angle = 0.0f; angle <= 2*3.14+0.1; angle += 3.14/20){
		Point First = Point(x, y, center.z , 0 ,0); 
			x = rad*cos(angle);
			y = rad*sin(angle);
		Point Second = Point( x, y, center.z , 0 ,0); 
		DrawTriangle(center, First, Second);
	}
}

void DrawConeBody (Point Top , float rad ){
	float angle=0, x=rad, y=0, z=0;
	for(angle = 0.0f; angle <= 2*3.14+0.1; angle += (3.14/20)){
		Point First = Point(x, y, z , 0 ,0); 
			x = rad*cos(angle);
			y = rad*sin(angle);
		Point Second = Point( x, y, z , 0 ,0); 
		DrawTriangle(Top , First, Second); 
	} 
}

void DrawCone (Point Base_center, float Base_rad, float height)
{
	DrawCircle(Base_center,Base_rad);
	Point Top= Point(Base_center.x, Base_center.y, height , 0 ,0);
	DrawConeBody(Top, Base_rad); 
}

void DrawCylinder(Point Base_center, float Base_rad , float Base_rad2, float height)
{
	glPushMatrix( );
		glRotated(-90 , 1 , 0 , 0);
		glTranslated(Base_center.x,Base_center.y, Base_center.z);
		Base_center=Point(0,0,0 , 0 ,0);
		Point Base_center2=Point(Base_center.x,Base_center.y, height , 0 ,0);
		DrawCircle(Base_center, Base_rad);
		DrawCircle(Base_center2, Base_rad2);
		float angle=0, x=Base_rad, y=0 , z = Base_rad2 ,v =0;
		for (angle=0; angle <=2*3.14+0.1; angle+=0.1)
		{
			Point a= Point (x,y,Base_center.z , 0 ,0);
			Point b= Point (z,v,Base_center2.z , 0 ,0);
			x=Base_rad*cos(angle);
			y=Base_rad*sin(angle);
			z=Base_rad2*cos(angle);
			v=Base_rad2*sin(angle);
			Point c= Point (z,v,Base_center2.z , 0 ,0);
			Point d= Point (x,y,Base_center.z , 0 ,0);
			DrawSquare(a,b,c,d);
		}
	glPopMatrix( );
}


void Lamppost::draw(){
	double height = 8;
	glPushMatrix();
	glRotated(90 , 0,1,0);
	Point pp = Point(0,0,0 , 0 ,0);
	glPushMatrix();
	glScaled(2,3,2);

	//lamp-stand
	glPushMatrix();
		glColor3d(1,1,1);
		glBindTexture(GL_TEXTURE_2D , this->arrayOfTextureLamp[0]);
		glTranslated(-0.5,8,1);
		glScaled(5,0.5,2);
		DrawCube();
	glPopMatrix();
	//lamp
	glPushMatrix();
		glColor3d(1,1,0);
		glTranslated(2.5,8,0);
		glScaled(2.5,1,1.2);
		auxSolidCube(0.8);
	glPopMatrix();
	//lamppost
	glPushMatrix();
		glColor3d(1,1,1);
		glBindTexture(GL_TEXTURE_2D , this->arrayOfTextureLamp[1]);
		//glColor3d(0.6,0.6,0.6);
		DrawCylinder(pp,0.3,0.3,height);
	glPopMatrix();
	//cube
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D , this->arrayOfTextureLamp[2]);
		glColor3d(0.3,0.3,0.3);
		
		glTranslated(-0.7,-1,0.7);
		
		glScaled(1.5,1.5,1.5);
		DrawCube();
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}
















