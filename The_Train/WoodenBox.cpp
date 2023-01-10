#include "WoodenBox.h"

WoodenBox::WoodenBox(bool open,int texture)
{
	this->texture = texture;
	this->open = open;

}


WoodenBox::~WoodenBox(void)
{
}

void WoodenBox::draw(double OpenRotated){
	glBindTexture(GL_TEXTURE_2D , texture);
	glPushMatrix();
		
		glPushMatrix();
				if(this->open){
						glRotated(OpenRotated,1,0,0);	
				}
				else{
						glRotated(OpenRotated,1,0,0);
				}
				glBegin(GL_QUADS); /*TOP*/	
				glTexCoord2d(0,0);
				glVertex3f(0.0f , 0.0f ,-1.0f);
				glTexCoord2d(1,0);
				glVertex3f(0.0f,0.0f ,0.0f);
				glTexCoord2d(1,1);
				glVertex3f(1.0f,0.0f ,0.0f);
				glTexCoord2d(0,1);
				glVertex3f(1.0f,0.0f ,-1.0f);
			glEnd();
		glPopMatrix();
		

		glBegin(GL_QUADS); /*Bottom*/
			glTexCoord2d(0,0);
			glVertex3f(0.0f , -1.0f ,-1.0f);
			glTexCoord2d(1,0);
			glVertex3f(0.0f,-1.0f ,0.0f);
			glTexCoord2d(1,1);
			glVertex3f(1.0f,-1.0f ,0.0f);
			glTexCoord2d(0,1);
			glVertex3f(1.0f,-1.0f ,-1.0f);
		glEnd();

		glBegin(GL_QUADS); /*Front*/
			glTexCoord2d(0,0);
			glVertex3f(0,-1 ,0);
			glTexCoord2d(1,0);
			glVertex3f(0.0f,0.0f ,0);
			glTexCoord2d(1,1);
			glVertex3f(1.0f,0.0f ,0);
			glTexCoord2d(0,1);
			glVertex3f(1.0f,-1 ,0);
		glEnd();

		glBegin(GL_QUADS); /*Back*/
			glTexCoord2d(0,0);
			glVertex3f(0,-1 ,-1.0f);
			glTexCoord2d(1,0);
			glVertex3f(0.0f,0.0f ,-1.0f);
			glTexCoord2d(1,1);
			glVertex3f(1.0f,0.0f ,-1.0f);
			glTexCoord2d(0,1);
			glVertex3f(1.0f,-1.0f ,-1.0f);
		glEnd();

		glBegin(GL_QUADS);/*Left*/
			glTexCoord2d(0,0);
			glVertex3f(0,-1 ,-1.0f);
			glTexCoord2d(1,0);
			glVertex3f(0.0f,0.0f ,-1.0f);
			glTexCoord2d(1,1);
			glVertex3f(0.0f,0.0f ,0.0f);
			glTexCoord2d(0,1);
			glVertex3f(0,-1 ,0.0f);
		glEnd();

		glBegin(GL_QUADS); /*Right*/
			glTexCoord2d(0,0);
			glVertex3f(1.0f,-1 ,-1.0f);
			glTexCoord2d(1,0);
			glVertex3f(1.0f,0.0f ,-1.0f);
			glTexCoord2d(1,1);
			glVertex3f(1.0f,0.0f ,0.0f);
			glTexCoord2d(0,1);
			glVertex3f(1.0f,-1.0f ,0.0f);
		glEnd();

	glPopMatrix();
}

