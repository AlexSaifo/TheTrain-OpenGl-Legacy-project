#include "library.h"


library::library(int WallShelfType,int texture)
{this-> WallShelfType=WallShelfType;
	this->texture=texture;
}

library::~library(void)
{
}
void library::draw(){

	if (WallShelfType==1)
	{
		WallShelf();
	}
	if (WallShelfType==2)
	{
		WallShelf2();
	}
	if (WallShelfType==3)
	{
		WallShelf3();
	}
	

}
void library::WallShelf(){
	////////////////////////////
	cubid *t = new cubid(texture,texture,texture,texture,texture,texture);
	glPushMatrix();

	glScaled(1.5,1,1);
	glPushMatrix();

	glTranslated(-0.25,0,0);
	glScaled(0.25,6.5,1);
	
	t->draw();
	
	glPopMatrix();
	////////////////////////////////
	glPushMatrix();

glTranslated(2,0,0);
	glScaled(0.25,6.5,1);
	
	t->draw();
	
	glPopMatrix();
//////////////////////////////
	for (int i = 0; i < 5; i++)
	{
		glPushMatrix();
		glScaled(2,0.5,1);
		glTranslated(0,3*i,0);
			t->draw();
			
			glPopMatrix();
	}
	;
				
			
		

	free(t);
	////////////////////////////////w

		cubid *c = new cubid(-1,-1,-1,-1,texture,texture);
	
	glPushMatrix();
	
	glTranslated(0,0,0);
	glScaled(2,6.5,0);
	
	c->draw();
	free(c);
	glPopMatrix();
	glPopMatrix();
	
	///////////////////////////////////////////////////////////////////////////
}
void library:: WallShelf2()
{	
	////////////////////////////up
	cubid *t = new cubid(texture,texture,texture,texture,texture,texture);
	glPushMatrix();

	glTranslated(-0.25,1.5,0);
    glScaled(1.5,0.25,1);
	
	t->draw();
	
	glPopMatrix();
	////////////////////////////////right

	glPushMatrix();

	glTranslated(1.25,0.25,0);
	glScaled(0.25,1.5,1);
	
	t->draw();
	
	glPopMatrix();

	/////////////////////////////////////////////////left
	
	glPushMatrix();

	glTranslated(-0.40,0.25,0);
	glScaled(0.25,1.5,1);
	
	t->draw();
	
	glPopMatrix();

	/////////////////////////////////////////////////////////////////////////bot

	glPushMatrix();

	glTranslated(-2,0,0);
	glScaled(3.5,0.25,1);
	
	t->draw();
	
	glPopMatrix();

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////up
	glPushMatrix();
	glTranslated(0,-3,0);
		glPushMatrix();
	glTranslated(-4,0,0);
	
	////////////////////////////////right

	glPushMatrix();

	glTranslated(3.75,1.75,0);
	glScaled(0.25,1.25,1);
	
	t->draw();
	
	glPopMatrix();

	/////////////////////////////////////////////////left
	
	glPushMatrix();

	glTranslated(2,1.75,0);
	glScaled(0.25,1.25,1);
	
	t->draw();
	
	glPopMatrix();
		glPopMatrix();
	/////////////////////////////////////////////////////////////////////////bot

		glPushMatrix();

	glTranslated(-2,1.5,0);
	glScaled(3.5,0.25,1);
	
	t->draw();
	
	glPopMatrix();
	glPopMatrix();
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////up
	glPushMatrix();

	glTranslated(0,-3,0);
	glPushMatrix();

	glTranslated(-0.25,1.5,0);
    glScaled(1.5,0.25,1);
	
	t->draw();
	
	glPopMatrix();
	////////////////////////////////right

	glPushMatrix();

	glTranslated(1.25,0.25,0);
	glScaled(0.25,1.5,1);
	
	t->draw();
	
	glPopMatrix();

	/////////////////////////////////////////////////left
	
	glPushMatrix();

	glTranslated(-0.40,0.25,0);
	glScaled(0.25,1.5,1);
	
	t->draw();
	
	glPopMatrix();

	/////////////////////////////////////////////////////////////////////////bot

	glPushMatrix();

	glTranslated(-2,0,0);
	glScaled(3.5,0.25,1);
	
	t->draw();
	
	glPopMatrix();

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////up
	glPushMatrix();
	glTranslated(0,-3,0);
		glPushMatrix();
	glTranslated(-4,0,0);
	
	////////////////////////////////right

	glPushMatrix();

	glTranslated(3.75,1.75,0);
	glScaled(0.25,1.25,1);
	
	t->draw();
	
	glPopMatrix();

	/////////////////////////////////////////////////left
	
	glPushMatrix();

	glTranslated(2,1.75,0);
	glScaled(0.25,1.25,1);
	
	t->draw();
	
	glPopMatrix();
		glPopMatrix();
	/////////////////////////////////////////////////////////////////////////bot

		glPushMatrix();

	glTranslated(-2,1.5,0);
	glScaled(3.5,0.25,1);
	
	t->draw();
	
	glPopMatrix();
	glPopMatrix();
		glPopMatrix();
		free(t);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
void library::WallShelf3()
{
	glPushMatrix();
	glTranslated(0,0,0.5);
	glScaled(2,1,1.5);
	WallShelf();
	glPopMatrix();

	///////////////////////
	glPushMatrix();
	glTranslated(-4.1,0,0);
	WallShelf();
	glPopMatrix();
	///////////////////
	glPushMatrix();
		glTranslated(7.1,0,0);
	WallShelf();
	glPopMatrix();



}
	























//float yr=0;
//
//void LibraryBase(float x){
//	glPushMatrix();
//	/*glRotated(yr,0,1,0);
//	yr+=0.4;
//*/
//
//glBegin(GL_QUADS);
//////////////////////////////////////////////////////////////////////////////////up
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(6*x, 12*x, x);
//
//	 glTexCoord2f(1.0f, 1.0f);glVertex3f(-6*x, 12*x, x);
//
//	
//	    glTexCoord2f(1.0f, 0.0f);glVertex3f(-6*x, 12*x,- x);
//    
//	 glTexCoord2f(0.0f, 0.0f);glVertex3f(6*x, 12*x,- x);
//	
//	/////////////////////////////////////////////////////////////////////fro-t
//		glTexCoord2f(1.0f, 0.0f);glVertex3f(-6*x,- 12*x, x);
//
//		glTexCoord2f(1.0f, 1.0f);glVertex3f(6*x, -12*x, x);
//
//	
//	glTexCoord2f(0.0f, 1.0f);glVertex3f(6*x, 12*x, x);
//    
//	glTexCoord2f(0.0f, 0.0f);glVertex3f(-6*x, 12*x, x);
//	
//	/////////////////////////////////////////////////////////////////////back
//	glTexCoord2f(1.0f, 0.0f);glVertex3f(-6*x, -12*x, -x);
//
//	glTexCoord2f(1.0f, 1.0f);glVertex3f(6*x, -12*x, -x);
//
//	
//	glTexCoord2f(0.0f, 1.0f);glVertex3f(6*x, 12*x, -x);
//    
//	glTexCoord2f(0.0f, 0.0f);glVertex3f(-6*x, 12*x, -x);
//	
//
//	/////////////////////////////////////////////////////////////////////left
//	glTexCoord2f(1.0f, 0.0f);glVertex3f(-6*x, -12*x, -x);
//
//	glTexCoord2f(1.0f, 1.0f);glVertex3f(-6*x, -12*x, x);
//
//	
//	glTexCoord2f(0.0f, 1.0f);glVertex3f(-6*x, 12*x, x);
//    
//	glTexCoord2f(0.0f, 0.0f);glVertex3f(-6*x, 12*x, -x);
//	/////////////////////////////////////////////////////////////////////bot
//	glTexCoord2f(0.0f, 1.0f);glVertex3f(-6*x, -12*x, -x);
//
//	glTexCoord2f(1.0f, 1.0f);glVertex3f(-6*x, -12*x, x);
//
//	
//	glTexCoord2f(1.0f, 0.0f);glVertex3f(6*x, -12*x, x);
//    
//	glTexCoord2f(0.0f, 0.0f);glVertex3f(6*x, -12*x, -x);
//	/////////////////////////////////////////////////////////////////////
//	glTexCoord2f(1.0f, 0.0f);glVertex3f(6*x, -12*x, -x);
//
//	glTexCoord2f(1.0f, 1.0f);glVertex3f(6*x, -12*x, x);
//
//	
//	glTexCoord2f(0.0f, 1.0f);glVertex3f(6*x, 12*x, x);
//    
//	glTexCoord2f(0.0f, 0.0f);glVertex3f(6*x, 12*x, -x);
//	
//	/////////////////////////////////////////////////////////////////////
//		
//	
//	glEnd();
//	glPopMatrix();
//	
//	
//
//
//
//}
////////////////////////////////////////////////////////////////////
//float yu=0;
//void shelf(float x){
//	//////////////////the downside base////////////////////////////////////////////////
//	glPushMatrix();
//	/*glRotated(yu,0,1,0);
//	yu+=0.1;*/
//	glBegin(GL_QUADS);
//	////back
//	glColor3f(0.34, 0.14, 0.05);
//	glVertex3f(5.5*x, x, -4*x);
//
//	glVertex3f(-5.5*x, x, -4*x);
//
//	
//	glVertex3f(-5.5*x, -x, -4*x);
//    
//	glVertex3f(5.5*x, -x, -4*x);
//	///front
//	glVertex3f(5.5*x,x,4*x);
//
//	glVertex3f(-5.5*x, x,4*x);
//
//	
//	glVertex3f(-5.5*x, -x, 4*x);
//    
//	glVertex3f(5.5*x, -x, 4*x);
//	//up
//		glVertex3f(5.5*x,x, -4*x);
//
//	glVertex3f(-5.5*x, x, -4*x);
//	glVertex3f(-5.5*x,x,4*x);
//
//	glVertex3f(5.5*x, x,4*x);
//	//bot
//	glVertex3f(-5.5*x, -x, -4*x);
//    
//	glVertex3f(5.5*x, -x, -4*x);
//
//
//	glVertex3f(5.5*x, -x,4*x);
//    
//	glVertex3f(-5.5*x, -x,4*x);
//	/////left
//	glVertex3f(-5.5*x, x, -4*x);
//
//	
//	glVertex3f(-5.5*x, -x, -4*x);
//	
//	glVertex3f(-5.5*x, -x,4*x);
//
//	
//	glVertex3f(-5.5*x,x,4*x);
//	///right
//	glVertex3f(5.5*x, x, -4*x);
//	 
//	glVertex3f(5.5*x, -x, -4*x);
//	glVertex3f(5.5*x, -x,4*x);
//	glVertex3f(5.5*x, x,4*x);
//
//
//
//	glEnd();
//	glPopMatrix();
//	
//		}
//
//void FrontBase(float x){
//	glPushMatrix();
//	/*glRotated(yr,0,1,0);
//	yr+=0.4;*/
//	glScaled(1,1,1.5);
//
//glBegin(GL_QUADS);
//////////////////////////////////////////////////////////////////////////////////up
//	glVertex3f(6*x, 12*x, -x);
//
//	glVertex3f(6*x, 12*x, x);
//
//	
//	glVertex3f(-6*x, 12*x, x);
//    
//	glVertex3f(-6*x, 12*x, -x);
//	
//
//	
//	/////////////////////////////////////////////////////////////////////12*ot
//	glVertex3f(-6*x, -12*x, -x);
//
//	glVertex3f(-6*x, -12*x, x);
//
//	
//	glVertex3f(6*x, -12*x, x);
//    
//	glVertex3f(6*x, -12*x, -x);
//	
//	/////////////////////////////////////////////////////////////////////left
//	glVertex3f(-6*x, -12*x, -x);
//
//	glVertex3f(-6*x, -12*x, x);
//
//	
//	glVertex3f(-6*x, 12*x, x);
//    
//	glVertex3f(-6*x, 12*x, -x);
//	
//	/////////////////////////////////////////////////////////////////////
//	glVertex3f(6*x, 12*x, -x);
//
//	glVertex3f(6*x, -12*x, -x);
//
//	
//	glVertex3f(6*x, -12*x, x);
//    
//	glVertex3f(6*x, 12*x, x);
//	
//	/////////////////////////////////////////////////////////////////////
//		
//	
//	glEnd();
//	glPopMatrix();
//	
//	
//
//
//
//}
//
//void MiddleWayLibrarry()
//{
//glPushMatrix();
//	glTranslatef(0,0,-40);
//	glRotated(yr,0,1,0);
//	yr+=0.4;
//
//	LibraryBase(1);
//	/*glTranslated(0,0,2);
//	FrontBase(1);
//	glTranslated(0,0,-2);*/
//	glTranslated(0,9,0);
//	 shelf(1);
//	 glTranslated(0,-10,0);
//	 glTranslated(0,3,0);
//	  shelf(1);
//	  glTranslated(0,-3,0);
//	  glTranslated(0,-5,0);
//	  shelf(1);
//	   glTranslated(0,5,0);
//	    glTranslated(0,-12,0);
//	  shelf(1);
//	  glPopMatrix();
//}
//void quad()
//{
//	glTranslated(0,0,-6);
//	glScaled(6,12,1);
//	glBegin(GL_QUADS);
//////////////////////////////////////////////////////////////////////////////////up
//	glVertex3f(1, -1, 0);
//
//	glVertex3f(1, 1, 0);
//
//	
//	glVertex3f(-1, 1, 0);
//    
//	glVertex3f(-1, -1, 0);
//
//	glEnd();
//
//
//
//
//
//
//
//}
//void WallShelf()
//{		glRotated(yr,0,1,0);
//		yr+=0.1;
//		glScaled(1,1,0.4);
//			glPushMatrix();
//
//			quad();
//
//
//
//
//			glPopMatrix();
//
//
//	glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,-13);
//	glScaled(1,0.665,1);
//	glColor3f(1, 1, 1);
//	LibraryBase(1);
//	glPopMatrix();
//
//	glPushMatrix();
//
//	glRotated(90,0,1,0);
//	glTranslated(0,0,-7);
//	glColor3f(1, 1, 1);
//	LibraryBase(1);
//	
//	glPopMatrix();
//
//
//	glPushMatrix();
//	glRotated(90,0,1,0);
//	glTranslated(0,0,7);
//	LibraryBase(1);
//	
//	glPopMatrix();
//
//
//		glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,13);
//	glScaled(1,0.665,1);
//	
//	LibraryBase(1);
//	glPopMatrix();
//
//	glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,0);
//	glScaled(1,0.5,1);
//	
//	LibraryBase(1);
//	glPopMatrix();
//
//
//
//		glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,-6);
//	glScaled(1,0.5,1);
//	
//	LibraryBase(1);
//	glPopMatrix();
//
//
//
//		glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,6);
//	glScaled(1,0.5,1);
//	
//	LibraryBase(1);
//	glPopMatrix();
//}
//void WallShelf2()
//{	/*	glRotated(yr,0,1,0);
//		yr+=0.1;*/
//	glTranslated(0,10,0);
//		glScaled(1,1,0.4);
//		glColor3f(0.7, 0.7, 0.7);
//
//
//	glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,-6.5);
//	glScaled(1,0.665,1);
//	
//	LibraryBase(1);
//	glPopMatrix();
//
//	glPushMatrix();
//	glScaled(1,0.5,1);
//	glRotated(90,0,1,0);
//	glTranslated(0,0,-7);
//
//	LibraryBase(1);
//	
//	glPopMatrix();
//
//
//	glPushMatrix();
//		glScaled(1,0.5,1);
//	glRotated(90,0,1,0);
//	glTranslated(0,0,7);
//	LibraryBase(1);
//	
//	glPopMatrix();
//
//
//		glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,6.5);
//	glScaled(1,0.665,1);
//	
//	LibraryBase(1);
//	glPopMatrix();
//
//	//////////////////////////////////////////
//	glTranslated(-16,-13,0);
//	glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,-6.5);
//	glScaled(1,0.665,1);
//
//	LibraryBase(1);
//	glPopMatrix();
//
//	glPushMatrix();
//	glScaled(1,0.5,1);
//	glRotated(90,0,1,0);
//	glTranslated(0,0,-7);
//
//	LibraryBase(1);
//	
//	glPopMatrix();
//
//
//	glPushMatrix();
//		glScaled(1,0.5,1);
//	glRotated(90,0,1,0);
//	glTranslated(0,0,7);
//	LibraryBase(1);
//	
//	glPopMatrix();
//
//
//		glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,6.5);
//	glScaled(1,0.665,1);
//	
//	LibraryBase(1);
//	glPopMatrix();
//
//	//////////////////////////////////////////
//	glTranslated(16,-13,0);
//	glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,-6.5);
//	glScaled(1,0.665,1);
//
//	LibraryBase(1);
//	glPopMatrix();
//
//	glPushMatrix();
//	glScaled(1,0.5,1);
//	glRotated(90,0,1,0);
//	glTranslated(0,0,-7);
//
//	LibraryBase(1);
//	
//	glPopMatrix();
//
//
//	glPushMatrix();
//		glScaled(1,0.5,1);
//	glRotated(90,0,1,0);
//	glTranslated(0,0,7);
//	LibraryBase(1);
//	
//	glPopMatrix();
//
//
//		glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,6.5);
//	glScaled(1,0.665,1);
//	
//	LibraryBase(1);
//	glPopMatrix();
//
//	//////////////////////////////////////////
//	glTranslated(-16,-13,0);
//	glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,-6.5);
//	glScaled(1,0.665,1);
//
//	LibraryBase(1);
//	glPopMatrix();
//
//	glPushMatrix();
//	glScaled(1,0.5,1);
//	glRotated(90,0,1,0);
//	glTranslated(0,0,-7);
//	
//	LibraryBase(1);
//	
//	glPopMatrix();
//
//
//	glPushMatrix();
//		glScaled(1,0.5,1);
//	glRotated(90,0,1,0);
//	glTranslated(0,0,7);
//	LibraryBase(1);
//	
//	glPopMatrix();
//
//
//		glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,-7.7,6.5);
//	glScaled(1,1.33,1);
//	
//	LibraryBase(1);
//	glPopMatrix();
//
//	/////////////////////////////////////////////////////////////////////////
//}
//
//
//
//
//void BigWallShelf(){
//
//			glPushMatrix();
//
//		glScaled(2,1.5,0.6);
//		glTranslated(0,0,2);
//			glPushMatrix();
//
//			quad();
//
//
//
//
//			glPopMatrix();
//
//
//	glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,-13);
//	glScaled(1,0.665,1);
//	glColor3f(0.8, 0.8, 0.8);
//	LibraryBase(1);
//	glPopMatrix();
//
//	glPushMatrix();
//
//	glRotated(90,0,1,0);
//	glTranslated(0,0,-7);
//	
//	LibraryBase(1);
//	
//	glPopMatrix();
//
//
//	glPushMatrix();
//	glRotated(90,0,1,0);
//	glTranslated(0,0,7);
//	LibraryBase(1);
//	
//	glPopMatrix();
//
//
//		glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,13);
//	glScaled(1,0.665,1);
//	
//	LibraryBase(1);
//	glPopMatrix();
//
//	glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,0);
//	glScaled(1,0.5,1);
//	
//	LibraryBase(1);
//	glPopMatrix();
//
//
//
//		glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,-6);
//	glScaled(1,0.5,1);
//	
//	LibraryBase(1);
//	glPopMatrix();
//
//
//
//		glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,6);
//	glScaled(1,0.5,1);
//	
//	LibraryBase(1);
//	glPopMatrix();
//		glPopMatrix();
//
////	/////////////////////////////////////////////////////////////////////
//	
//					glPushMatrix();
//		glScaled(1,1.5,0.4);
//		glTranslated(-24,0,0);
//			glPushMatrix();
//
//			quad();
//
//
//
//
//			glPopMatrix();
//
//
//	glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,-13);
//	glScaled(1,0.665,1);
//	
//	LibraryBase(1);
//	glPopMatrix();
//
//	glPushMatrix();
//
//	glRotated(90,0,1,0);
//	glTranslated(0,0,-7);
//
//	LibraryBase(1);
//	
//	glPopMatrix();
//
//
//	glPushMatrix();
//	glRotated(90,0,1,0);
//	glTranslated(0,0,7);
//	LibraryBase(1);
//	
//	glPopMatrix();
//
//
//		glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,13);
//	glScaled(1,0.665,1);
//	
//	LibraryBase(1);
//	glPopMatrix();
//
//	glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,0);
//	glScaled(1,0.5,1);
//	
//	LibraryBase(1);
//	glPopMatrix();
//
//
//
//		glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,-6);
//	glScaled(1,0.5,1);
//	
//	LibraryBase(1);
//	glPopMatrix();
//
//
//
//		glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,6);
//	glScaled(1,0.5,1);
//	
//	LibraryBase(1);
//	glPopMatrix();
//	glPopMatrix();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	
//		glPushMatrix();
//glScaled(1,1.5,0.4);
//		glTranslated(24,0,0);
//			glPushMatrix();
//
//			quad();
//
//
//
//
//			glPopMatrix();
//
//
//	glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,-13);
//	glScaled(1,0.665,1);
//	
//	LibraryBase(1);
//	glPopMatrix();
//
//	glPushMatrix();
//
//	glRotated(90,0,1,0);
//	glTranslated(0,0,-7);
//	
//	LibraryBase(1);
//	
//	glPopMatrix();
//
//
//	glPushMatrix();
//	glRotated(90,0,1,0);
//	glTranslated(0,0,7);
//	LibraryBase(1);
//	
//	glPopMatrix();
//
//
//		glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,13);
//	glScaled(1,0.665,1);
//	
//	LibraryBase(1);
//	glPopMatrix();
//
//	glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,0);
//	glScaled(1,0.5,1);
//	
//	LibraryBase(1);
//	glPopMatrix();
//
//
//
//		glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,-6);
//	glScaled(1,0.5,1);
//	
//	LibraryBase(1);
//	glPopMatrix();
//
//
//
//		glPushMatrix();
//	glRotated(90,1,0,0);
//	glRotated(90,0,0,1);
//	glTranslated(0,0,6);
//	glScaled(1,0.5,1);
//	
//	LibraryBase(1);
//	glPopMatrix();
//
//		glPopMatrix();
//
//
//
//	}
//	void BookCover(float x){
//		glColor3f(0,0,1);
//	glPushMatrix();
//	/*glRotated(yr,0,1,0);
//	yr+=0.4;
//*/
//	glScaled(1,0.8,4);
//
//glBegin(GL_QUADS);
//
//	
//	/////////////////////////////////////////////////////////////////////fro-t
//		glVertex3f(-6*x,- 12*x, x);
//
//	glVertex3f(6*x, -12*x, x);
//
//	
//       glVertex3f(6*x, 12*x, x);
//    
//	glVertex3f(-6*x, 12*x, x);
//	
//	/////////////////////////////////////////////////////////////////////back
//	glVertex3f(-6*x, -12*x, -x);
//
//	glVertex3f(6*x, -12*x, -x);
//
//	
//	glVertex3f(6*x, 12*x, -x);
//    
//	glVertex3f(-6*x, 12*x, -x);
//	
//
//	
//	/////////////////////////////////////////////////////////////////////right
//	glTexCoord2f(1.0f, 0.0f);glVertex3f(6*x, -12*x, -x);
//
//	glTexCoord2f(1.0f, 1.0f);glVertex3f(6*x, -12*x, x);
//
//	
//	glTexCoord2f(0.0f, 1.0f);glVertex3f(6*x, 12*x, x);
//    
//	glTexCoord2f(0.0f, 0.0f);glVertex3f(6*x, 12*x, -x);
//	
//	/////////////////////////////////////////////////////////////////////
//		
//	
//	glEnd();
//	glPopMatrix();
//	
//	
//
//
//
//}
////////////////////
//	void BookPaper(float x){
//	glPushMatrix();
//	/*glRotated(yr,0,1,0);
//	yr+=0.4;
//*/
//	glColor3f(1,1,1);
//	glScaled(0.8,0.7,3.5);
//
//glBegin(GL_QUADS);
//
//////////////////////////////////////////////////////////////////////////////////up
//	 glVertex3f(6*x, 12*x, x);
//
//	 glVertex3f(-6*x, 12*x, x);
//
//	
//	    glVertex3f(-6*x, 12*x,- x);
//    
//	 glVertex3f(6*x, 12*x,- x);
//	
//
//	/////////////////////////////////////////////////////////////////////bot
//	glVertex3f(-6*x, -12*x, -x);
//
//	glVertex3f(-6*x, -12*x, x);
//
//	
//	glVertex3f(6*x, -12*x, x);
//    
//	glVertex3f(6*x, -12*x, -x);
//
//	
//	/////////////////////////////////////////////////////////////////////fro-t
//		glVertex3f(-6*x,- 12*x, x);
//
//	glVertex3f(6*x, -12*x, x);
//
//	
//       glVertex3f(6*x, 12*x, x);
//    
//	glVertex3f(-6*x, 12*x, x);
//	
//	/////////////////////////////////////////////////////////////////////back
//	glVertex3f(-6*x, -12*x, -x);
//
//	glVertex3f(6*x, -12*x, -x);
//
//	
//	glVertex3f(6*x, 12*x, -x);
//    
//	glVertex3f(-6*x, 12*x, -x);
//	
//
//	
//	/////////////////////////////////////////////////////////////////////left
//	glVertex3f(-6*x, -12*x, -x);
//	glVertex3f(-6*x, -12*x, x);
//
//	
//	glVertex3f(-6*x, 12*x, x);
//    glVertex3f(-6*x, 12*x, -x);
//	
//	/////////////////////////////////////////////////////////////////////
//		
//	
//	glEnd();
//	glPopMatrix();
//	}
//
//void Laptop()
//{
////keyboard_part
//
//	//up_side
//	glColor3ub(60.4f,100.8f,100.2f);
//	//glBindTexture(GL_TEXTURE_2D,img2);
//	glBegin(GL_QUADS);
//
//	glTexCoord2d(0,0);
//	glVertex3f(0,0,0);
//
//	glTexCoord2d(1,0);
//	glVertex3f(2,0,0);
//
//	glTexCoord2d(1,1);
//	glVertex3f(2,0,-1);
//
//	glTexCoord2d(0,1);
//	glVertex3f(0,0,-1);
//	glEnd();
//
//	//down_side
//	glColor3ub(60.4f,80.8f,92.2f);
//	//glBindTexture(GL_TEXTURE_2D,img2);
//	glBegin(GL_QUADS);
//
//	//glTexCoord2d(0,0);
//	glVertex3f(0,-0.2,0);
//
//	//glTexCoord2d(1,0);
//	glVertex3f(2,-0.2,0);
//
//	//glTexCoord2d(1,1);
//	glVertex3f(2,-0.2,-1);
//
//	//glTexCoord2d(0,1);
//	glVertex3f(0,-0.2,-1);
//	glEnd();
//
//	//right_side
//	glColor3ub(60.4f,80.8f,92.2f);
//	//glBindTexture(GL_TEXTURE_2D,img2);
//	glBegin(GL_QUADS);
//
//	//glTexCoord2d(0,0);
//	glVertex3f(2,0,0);
//
//	//glTexCoord2d(1,0);
//	glVertex3f(2,-0.2,0);
//
//	//glTexCoord2d(1,1);
//	glVertex3f(2,-0.2,-1);
//
//	//glTexCoord2d(0,1);
//	glVertex3f(2,0,-1);
//	glEnd();
//
//	//left_side
//	glColor3ub(60.4f,80.8f,92.2f);
//	//glBindTexture(GL_TEXTURE_2D,img2);
//	glBegin(GL_QUADS);
//
//	//glTexCoord2d(0,0);
//	glVertex3f(0,0,0);
//
//	//glTexCoord2d(1,0);
//	glVertex3f(0,-0.2,0);
//
//	//glTexCoord2d(1,1);
//	glVertex3f(0,-0.2,-1);
//
//	//glTexCoord2d(0,1);
//	glVertex3f(0,0,-1);
//	glEnd();
//
//	//front_side
//	glColor3ub(60.4f,80.8f,92.2f);
//	//glBindTexture(GL_TEXTURE_2D,img2);
//	glBegin(GL_QUADS);
//
//	//glTexCoord2d(0,0);
//	glVertex3f(0,0,-1);
//
//	//glTexCoord2d(1,0);
//	glVertex3f(0,-0.2,-1);
//
//	//glTexCoord2d(1,1);
//	glVertex3f(2,-0.2,-1);
//
//	//glTexCoord2d(0,1);
//	glVertex3f(2,0,-1);
//	glEnd();
//
//	//back_side
//	glColor3ub(60.4f,80.8f,92.2f);
//	//glBindTexture(GL_TEXTURE_2D,img2);
//	glBegin(GL_QUADS);
//
//	//glTexCoord2d(0,0);
//	glVertex3f(0,0,0);
//
//	//glTexCoord2d(1,0);
//	glVertex3f(0,-0.2,0);
//
//	//glTexCoord2d(1,1);
//	glVertex3f(2,-0.2,0);
//
//	//glTexCoord2d(0,1);
//	glVertex3f(2,0,0);
//	glEnd();
//
//
//	/////////////////////////////////////////////////Screen_part
//
//	//front_side
//	glColor3ub(255,255,255);
//	
//	glBegin(GL_QUADS);
//
//	glTexCoord2d(0,0);
//	glVertex3f(0,-0.2,0);
//
//	glTexCoord2d(1,0);
//	glVertex3f(2,-0.2,0);
//
//	glTexCoord2d(1,1);
//	glVertex3f(2,1,0);
//
//	glTexCoord2d(0,1);
//	glVertex3f(0,1,0);
//	glEnd();
//
//	//back_side
//	glColor3ub(67.8f,84.7f,90.2f);
//	
//	glBegin(GL_QUADS);
//
//	glTexCoord2d(0,0);
//	glVertex3f(0,-0.2,0.2);
//
//	glTexCoord2d(1,0);
//	glVertex3f(2,-0.2,0.2);
//
//	glTexCoord2d(1,1);
//	glVertex3f(2,1,0.2);
//
//	glTexCoord2d(0,1);
//	glVertex3f(0,1,0.2);
//	glEnd();
//
//	//up_side
//	glColor3ub(67.8f,84.7f,90.2f);
//	//glBindTexture(GL_TEXTURE_2D,img2);
//	glBegin(GL_QUADS);
//
//	//glTexCoord2d(0,0);
//	glVertex3f(0,1,0);
//
//	//glTexCoord2d(1,0);
//	glVertex3f(2,1,0);
//
//	//glTexCoord2d(1,1);
//	glVertex3f(2,1,0.2);
//
//	//glTexCoord2d(0,1);
//	glVertex3f(0,1,0.2);
//	glEnd();
//
//	//down_side
//	glColor3ub(67.8f,84.7f,90.2f);
//	//glBindTexture(GL_TEXTURE_2D,img2);
//	glBegin(GL_QUADS);
//
//	//glTexCoord2d(0,0);
//	glVertex3f(0,-0.2,0);
//
//	//glTexCoord2d(1,0);
//	glVertex3f(2,-0.2,0);
//
//	//glTexCoord2d(1,1);
//	glVertex3f(2,-0.2,0.2);
//
//	//glTexCoord2d(0,1);
//	glVertex3f(0,-0.2,0.2);
//	glEnd();
//
//	//right_side
//	glColor3ub(67.8f,84.7f,90.2f);
//	//glBindTexture(GL_TEXTURE_2D,img2);
//	glBegin(GL_QUADS);
//
//	//glTexCoord2d(0,0);
//	glVertex3f(2,1,0);
//
//	//glTexCoord2d(1,0);
//	glVertex3f(2,1,0.2);
//
//	//glTexCoord2d(1,1);
//	glVertex3f(2,-0.2,0.2);
//
//	//glTexCoord2d(0,1);
//	glVertex3f(2,-0.2,0);
//	glEnd();
//
//	//left_side
//	glColor3ub(67.8f,84.7f,90.2f);
//	//glBindTexture(GL_TEXTURE_2D,img2);
//	glBegin(GL_QUADS);
//
//	//glTexCoord2d(0,0);
//	glVertex3f(0,1,0);
//
//	//glTexCoord2d(1,0);
//	glVertex3f(0,1,0.2);
//
//	//glTexCoord2d(1,1);
//	glVertex3f(0,-0.2,0.2);
//
//	//glTexCoord2d(0,1);
//	glVertex3f(0,-0.2,0);
//	glEnd();
//}
//
//
//
//
//




