#include "Barrel.h"

Barrel::Barrel(bool open , int *texture)
{
	this->texture = texture;
	this->open = open;
}


Barrel::~Barrel(void)
{

}

void Barrel::draw(){
		this->drawWithTexture();
}

void Barrel::drawWithTexture(){
	int texture_id1 = this->texture[0];
	int texture_id2 = this->texture[1];
	int texture_id3 = this->texture[2];
	int arrayOfTexture[3] = {texture_id1, texture_id2 ,texture_id3};

	glPushMatrix();
		glPushMatrix();
			Cylinder *barrel  = new Cylinder(1 , 2.5 , arrayOfTexture);
			barrel ->draw();
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,0.5,1);

			glPushMatrix();
				glRotated(90 , 1 ,0 , 0);
				Cylinder *Faucet  = new Cylinder(0.1 ,0.5);
				Faucet ->draw();
			glPopMatrix();

			glPushMatrix();
				glColor3d(1,1,0);
				if(open){
					glRotated(-45 , 0,0,1);
				}
				else{
					glRotated(0 , 0,0,1);
				}
				Cylinder *FaucetHand  = new Cylinder(0.05 ,0.3);
				FaucetHand ->draw();
				glColor3d(1,1,1);
			glPopMatrix();
			
			if(open){
				glPushMatrix();
					glTranslated(0,-0.5,0);
					glColor3d(0,0,1);
					Cylinder *Water  = new Cylinder(0.05 ,0.5);
					Water ->draw();
					glColor3d(1,1,1);
					free(Water);
				glPopMatrix();
			}
		glPopMatrix();

		free(Faucet);
		free(FaucetHand);
		free(barrel );
	glPopMatrix();
	//end barrel

}
