#include "AlexTrailer.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <Triangle.h>
#include <Point.h>
#include <texture.h>
#include <iostream>
#include <Quad.h>
#include <Circle.h>
#include <Cylinder.h>
#include <AccordionDoor.h>
#include<Trailer.h>
#include<camera.h>
#include<cubid.h>
#include<color.h>
#include <WoodenBox.h>
#include <Barrel.h>
#include <Lamppost.h>
#include <Model_3DS.h>


AlexTrailer::AlexTrailer(bool *keys)
{
	for (int i = 0; i < 14; i++)
	{
		s2[i]=11;

	}
		this->keys= keys;
		this->transXalex=this->transYalex=this->transZalex=0; 
		this->frontDoorStateAlex = 0;
		for(int i =0 ; i<20 ; i++)
				this->openBoxsAlex[i] = 0;
}


AlexTrailer::~AlexTrailer(void)
{

}



void AlexTrailer::Transalate(double x , double y , double z){

	this->transXalex=x;
	this->transYalex=y;
	this->transZalex=z; 
	
}


int backDoorStateAlex=0;



boolean innerCollisionAlex(float minX,float maxX,float minZ,float maxZ,Point *cam)
{
	if(cam->x-3.5<minX || cam->x+3.5>maxX)
		return false;
	if(cam->x-3.5<minX || cam->x+3.5>maxX)
		return false;
	if(cam->z-3.5<minZ || cam->z+3.5>maxZ)
		return false;
	if(cam->z-3.5<minZ || cam->z+3.5>maxZ)
		return false;
	return true;
}

boolean outerCollisionAlex(float minX,float maxX,float minZ,float maxZ,Point *cam)
{
	//return true;

	//if the camere minx or maxx is in the interval[minX,maxX] 
	if((cam->x-3.5<=maxX && cam->x-3.5>=minX) || (cam->x+3.5<=maxX && cam->x+3.5>=minX))
	{
		//if the camera minz or maxz is in the intervel[minZ,maxZ]
		if((cam->z-3.5>=minZ && cam->z-3.5<=maxZ) || (cam->z+3.5>=minZ && cam->z+3.5<=maxZ))
			return false;
	}
	return true;
}

boolean AlexTrailer::collisionAlex( Point *cam , double x , double z ) //glTranslated(-36,0,-22);
{
	
	//return true;
	if(outerCollisionAlex(-42.9+x+transXalex,42.9+x+transXalex,-59.9+z+transZalex,59.9 +z+transZalex,cam)){
		return true;	
	}

	return (innerCollisionAlex(-42.9+x+transXalex,42.9+x+transXalex,-1000+z+transZalex,59.9+z+transZalex,cam) || (frontDoorStateAlex && innerCollisionAlex(-7+transXalex,7+transXalex,47+transZalex,73+transZalex,cam)) ) &&
		   outerCollisionAlex(10+x+transXalex,30+x+transXalex,42+z+transZalex,55+z+transZalex,cam) && 
		   outerCollisionAlex(-30+x+transXalex,-10+x+transXalex,42+z+transZalex,55+z+transZalex,cam) &&
		   outerCollisionAlex(30+x+transXalex,43+x+transXalex,13+z+transZalex,26+z+transZalex,cam) && 
		   outerCollisionAlex(25+x+transXalex,42.5+x+transXalex,-28+z+transZalex,-15+z+transZalex,cam) &&
		   outerCollisionAlex(-20+x+transXalex,-6+x+transXalex,-56+z+transZalex,-43+z+transZalex,cam) && 
		   outerCollisionAlex(-41+x+transXalex,-30+x+transXalex,15+z+transZalex,22+z+transZalex,cam) &&
		   outerCollisionAlex(10+x+transXalex,24+x+transXalex,-56+z+transZalex,-43+z+transZalex,cam) &&
		   outerCollisionAlex(-12+x+transXalex,12+x+transXalex,-22+z+transZalex,20+z+transZalex,cam) &&
		   outerCollisionAlex(-43+x+transXalex,-29+x+transXalex,-27+z+transZalex,-16+z+transZalex,cam);//end

}


int textureDoorAlex,textureTrainSideAlex,textureCeilingAlex,textureFloorAlex;
int textureGlassAlex;


int  textureWoodenBoxAlex, textureWoodenFloorAlex,textureWoodenInnerTrainSideAlex , arrayOfTextureBarrelAlex[3] , arrayOfTextureLampAlex[3] ;
int textureCarAlex[4];



GLTexture BARK,Leaf;
Model_3DS *carAll = new Model_3DS();
Model_3DS *kakashi = new Model_3DS();
Model_3DS *Coati = new Model_3DS();


void AlexTrailer::AlexTrailerInit(){
			
			textureDoorAlex=LoadTexture("texture-seamless-wood-5.bmp");
			textureTrainSideAlex=LoadTexture("cinema_seats.bmp");
			textureCeilingAlex=LoadTexture("ceilingTexture.bmp" );
			textureFloorAlex=LoadTexture("try.bmp");
			textureGlassAlex=LoadTexture("glassTexture.bmp",50);
			




			textureWoodenBoxAlex = LoadTexture("woodBoxTexture1.bmp");
			arrayOfTextureBarrelAlex[0] = LoadTexture("barrelTexture.bmp" , 255);
			arrayOfTextureBarrelAlex[1] = LoadTexture("barrelTexture.bmp" , 255);
			arrayOfTextureBarrelAlex[2] = LoadTexture("barrelTexture.bmp" , 255);

			arrayOfTextureLampAlex[0] = LoadTexture("ironTexture1.bmp");
			arrayOfTextureLampAlex[1] = LoadTexture("ironTexture2.bmp");
			arrayOfTextureLampAlex[2] = LoadTexture("ironTexture3.bmp");	

			textureWoodenFloorAlex = LoadTexture("textureWoodenFloor.bmp");
			textureWoodenInnerTrainSideAlex = LoadTexture("textureWoodenInnerTrainSide3.bmp");



			textureCarAlex[0] = LoadTexture("tier4.bmp");
			textureCarAlex[1] = LoadTexture("6ara2.bmp");
			textureCarAlex[2] = LoadTexture("carside1.bmp");
			textureCarAlex[3] = LoadTexture("carwindow1.bmp");
			

			
			
			carAll->Load("AH 64D.3ds");
			carAll->pos.y = 11;
			carAll->pos.x = 0;
			carAll->pos.z = -18;
			carAll->scale = 3;
			

			Leaf.LoadBMP("AH 64D.bmp");
			BARK.LoadBMP("AH 64D.bmp");


			kakashi->Load("kakashi.3ds"); //Coati
			kakashi->pos.y = 0;
			kakashi->pos.x = 19.5;
			kakashi->pos.z = -55;
			kakashi->scale = 0.2;

			Coati->Load("Coati.3ds");
		
}





double argAlex = 0;
void DrawPlan(double r , double inc = 0.01){
	GLdouble s ,c ,i = 0 ,j=0,fay=0 , r2;
	glPushMatrix();
	glRotated(argAlex , 1,1,0);
	glBegin(GL_LINE_LOOP);
	for(j=-3.14 ; j<= 3.14 ; j+=inc){
		fay =  r*cos(j);
		r2 = r*sin(j);
		for(i=0 ; i<= 3.14*2 ; i+=0.1){
			c = r2*cos(i);
			s = r2*sin(i);
			glVertex3d(c,fay,s);
		}
	}	
	glEnd();
	glPopMatrix();
}
void DrawOrbit(double r , double y = 0.05){

	GLdouble s ,c ,i = 0;
	glBegin(GL_QUAD_STRIP);
		for(i=0 ; i<= 3.14*2 ; i+=y){
			c = r *cos(i);
			s = r *sin(i);
			glVertex3d(c,0,s);
		}

	glEnd();
}
double rotAlex =0;
double plan1Alex=0 , plan2Alex = 0 , plan3Alex = 0;
void drawSollerSystem(){
	glPushMatrix();
		glTranslated(0,5,0);
		glScaled(0.25,0.25,0.25);
		glPushMatrix();
			glColor3d(1,1,0);
			DrawPlan(5,0.08);
		glPopMatrix();
	glRotated(rotAlex , 0,1,0);
	//start plan 1
	glPushMatrix();
		glRotated(argAlex , 1,1,0);
		DrawOrbit(13);	

		glPushMatrix();
			glRotated(plan1Alex + 0.5 , 0,1,0);
			glTranslated(13,0,0);

			glPushMatrix();
				glColor3d(1,0,1);
				DrawPlan(2);
			glPopMatrix();

			glPushMatrix();
				glRotated(argAlex + 0.5, 1,1,0);

				glPushMatrix();//start moon
					glRotated(plan2Alex + 0.5 , 0,1,0);
					DrawOrbit(6 , 0.09);
					glTranslated(6,0,0);

					glPushMatrix();
						glColor3d(1,0.6,1);
						DrawPlan(1.0);
					glPopMatrix();
				glPopMatrix();//end moon
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
	//end plan 1


	//start plan 2
	glPushMatrix();
		glRotated(argAlex + 300, 1,1,1);
		DrawOrbit(22);	
		glPushMatrix();
		glRotated(plan3Alex , 0,1,0);
			glTranslated(22,0,0);
			glPushMatrix();
				glColor3d(1,0.3,0.);
				DrawPlan(2.5 , 0.08);
			glPopMatrix();
		glPopMatrix();
		glColor3d(1,1,1);
	glPopMatrix();
	//end plan 2

	glPopMatrix();
	plan1Alex+=.1;
	plan2Alex+=.5;
	plan1Alex+=1.8;
	argAlex+=1;
}


double argCubeAlex = 0;
bool boolCubeAlex = true;

void drawTranslatedCube(){

	glPushMatrix();
	glTranslated(0,5,0);
	glScaled(4,4,4);
	glPushMatrix();
		glTranslated(0,argCubeAlex,0);
		glBegin(GL_QUADS); /*TOP*/
			glColor3d(0.5f,0.1f,0.5f);
			glVertex3f(0.0f , 1.0f ,-1.0f);
			glVertex3f(0.0f,1.0f ,0.0f);
			glVertex3f(1.0f,1.0f ,0.0f);
			glVertex3f(1.0f,1.0f ,-1.0f);
		glEnd();
	glPopMatrix();

	
	glPushMatrix();
	glTranslated(0,-argCubeAlex,0);
		glBegin(GL_QUADS); /*Bottom*/
			glColor3d(0.5f,0.4f,0.2f);
			glVertex3f(0.0f , 0.0f ,-1.0f);
			glVertex3f(0.0f,0.0f ,0.0f);
			glVertex3f(1.0f,0.0f ,0.0f);
			glVertex3f(1.0f,0.0f ,-1.0f);
		glEnd();
	glPopMatrix();



	glPushMatrix();
		glTranslated(0,0,argCubeAlex);
		glBegin(GL_QUADS); /*Front*/
			glColor3d(0.3f,0.3f,0.3f);
			glVertex3f(0,0 ,0);
			glVertex3f(0.0f,1.0f ,0);
			glVertex3f(1.0f,1.0f ,0);
			glVertex3f(1.0f,0 ,0);
		glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,-argCubeAlex);
		glBegin(GL_QUADS); /*Back*/
			glColor3d(0.5f,0.4f,0.7f);
			glVertex3f(0,0 ,-1.0f);
			glVertex3f(0.0f,1.0f ,-1.0f);
			glVertex3f(1.0f,1.0f ,-1.0f);
			glVertex3f(1.0f,0 ,-1.0f);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glTranslated(-argCubeAlex,0,0);
		glBegin(GL_QUADS);/*Left*/
			glColor3d(0.1f,0.5f,0.1f);
			glVertex3f(0,0 ,-1.0f);
			glVertex3f(0.0f,1.0f ,-1.0f);
			glVertex3f(0.0f,1.0f ,0.0f);
			glVertex3f(0,0 ,0.0f);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glTranslated(argCubeAlex,0,0);
		glBegin(GL_QUADS); /*Right*/
			glColor3d(0.1f,0.1f,0.5f);
			glVertex3f(1.0f,0 ,-1.0f);
			glVertex3f(1.0f,1.0f ,-1.0f);
			glVertex3f(1.0f,1.0f ,0.0f);
			glVertex3f(1.0f,0 ,0.0f);
		glEnd();
	glPopMatrix();
	glColor3d(1,1,1);
	glPopMatrix();

	if(boolCubeAlex){

		if(argCubeAlex >= 0.8){
			boolCubeAlex = false;
		}
		argCubeAlex+=0.05;

	}
	else{
		if(argCubeAlex <= 0.2){
			boolCubeAlex = true;
		}
		argCubeAlex-=0.05;
	}
	

}


double CoatiAngle = 0.0;

void AlexTrailer::draw(Point *camPos){
	glPushMatrix();
	glTranslated(transXalex , transYalex , transZalex);

	


	


	//////////////////////////////////////////////////////start  section 1
	glPushMatrix();
		glTranslated(10,10,55);	
		glScaled(20,10,10);
		WoodenBox *woodenbox11 = new  WoodenBox(false , textureWoodenBoxAlex);
			woodenbox11->draw(0);
		free(woodenbox11);
	glPopMatrix();

	glPushMatrix();
		glTranslated(10,20,55);	
		glScaled(20,10,10);
		WoodenBox *woodenbox12 = new  WoodenBox(false , textureWoodenBoxAlex);
			woodenbox12->draw(0);
		free(woodenbox12);
	glPopMatrix();

	glPushMatrix();
		glTranslated(10,30,55);	
		glScaled(20,10,10);
		WoodenBox *woodenbox13 = new  WoodenBox(true , textureWoodenBoxAlex);
			woodenbox13->draw(90);
		free(woodenbox13);
	glPopMatrix();


	
	
	//////////////////////////////////////////////////////start  section 2
	glPushMatrix();
		glTranslated(-30,10,55);	
		glScaled(20,10,10);
		WoodenBox *woodenbox21 = new  WoodenBox(false , textureWoodenBoxAlex);
			woodenbox21->draw(0);
		free(woodenbox21);
	glPopMatrix();

	glPushMatrix();
		glTranslated(-30,20,55);	
		glScaled(20,10,10);
		WoodenBox *woodenbox22 = new  WoodenBox(false , textureWoodenBoxAlex);
			woodenbox22->draw(0);
		free(woodenbox22);
	glPopMatrix();

	glPushMatrix();
		glTranslated(-30,30,55);	
		glScaled(20,10,10);
		WoodenBox *woodenbox23 = new  WoodenBox(false , textureWoodenBoxAlex);
			woodenbox23->draw(0);
		free(woodenbox23);
	glPopMatrix();

	//////////////////////////////////////////////////////start  section 3
	glPushMatrix();
		glTranslated(36,0,20);
		glRotated(90,0,1,0);
		glPushMatrix();
			glTranslated(-6,12,6);
			glScaled(13,11,13);
			WoodenBox *woodenbox31 = new  WoodenBox(openBoxsAlex[0] , textureWoodenBoxAlex);
				woodenbox31->draw(openBoxsAlex[0]);
			free(woodenbox31);
		glPopMatrix();

		drawSollerSystem();
	glPopMatrix();
	

	//////////////////////////////////////////////////////start  section 4
	glPushMatrix();
		glTranslated(36,0,-20);
		glRotated(90,0,1,0);	

		glPushMatrix();
			glTranslated(-6.5,12,6);
			glScaled(13,11,13);
			WoodenBox *woodenbox41 = new  WoodenBox(false , textureWoodenBoxAlex);
				woodenbox41->draw(0);
			free(woodenbox41);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,13,-4);
			glRotated(175,0,1,0);
			glScaled(5,5,5);
			Barrel *bar = new Barrel(openBoxsAlex[1] , arrayOfTextureBarrelAlex);
			bar->draw();
			free(bar);
		glPopMatrix();

	glPopMatrix();
	//////////////////////////////////////////////////////start  section 5
	glPushMatrix();
		
		glTranslated(-17,0.5,-55);
		glRotated(180,0,1,0);
		
		glPushMatrix();
			glRotated(90,0,1,0);
			glTranslated(9,30,6);
			glScaled(13,30,13);
			glRotated(-90,0,0,1);
			WoodenBox *woodenbox51 = new  WoodenBox(openBoxsAlex[2] , textureWoodenBoxAlex);
				woodenbox51->draw(openBoxsAlex[2]);
			free(woodenbox51);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0,0.5,1);
		glScaled(0.8,0.8,0.8);
			Lamppost *LP = new Lamppost(true , arrayOfTextureLampAlex);
			LP->draw();
			free(LP);
		glPopMatrix();
	glPopMatrix();
	//////////////////////////////////////////////////////start  section 6
	glPushMatrix();
	glTranslated(-36,0,18);
		glRotated(-90,0,1,0);
	glColor3d(1,1,1);
		glPushMatrix();
			glTranslated(-5,14,5);
			glScaled(14,13,14);
			WoodenBox *woodenbox61 = new  WoodenBox(openBoxsAlex[3] , textureWoodenBoxAlex);
				woodenbox61->draw(openBoxsAlex[3]);
			free(woodenbox61);
		glPopMatrix();

		glPushMatrix();
			drawTranslatedCube();
		glPopMatrix();

	glPopMatrix();
	//////////////////////////////////////////////////////start  section 7
	glPushMatrix();
		
		glColor3ub(1 + ( rand() % ( 255 - 1 + 1 ) ) , 1 + ( rand() % ( 255 - 1 + 1 ) ) , 1 + ( rand() % ( 255 - 1 + 1 ) ));
		kakashi->Draw();
		glColor3d(1,1,1);


		glTranslated(-17,0.5,-55);
		glRotated(180,0,1,0);
		
		glPushMatrix();
			glRotated(90,0,1,0);
			glTranslated(9,30,-30);
			glScaled(13,30,13);
			glRotated(-90,0,0,1);
			WoodenBox *woodenbox71 = new  WoodenBox(openBoxsAlex[4] , textureWoodenBoxAlex);
				woodenbox71->draw(openBoxsAlex[4]);
			free(woodenbox71);
		glPopMatrix();




	glPopMatrix();
	//////////////////////////////////////////////////////start  section 8
	glPushMatrix();
		
	glTranslated(0,0,5);
		glPushMatrix();
			glPushMatrix();		
				glTranslated(0,10,-14);
					glScaled(14,10,14);
					WoodenBox *woodenbox81 = new  WoodenBox(false, textureWoodenBoxAlex);
						woodenbox81->draw(0);
					free(woodenbox81);
			glPopMatrix();

			glPushMatrix();		
					glTranslated(-14,10,-14);
					glScaled(14,10,14);
					WoodenBox *woodenbox82 = new  WoodenBox(false , textureWoodenBoxAlex);
						woodenbox82->draw(0);
					free(woodenbox82);
			glPopMatrix();
		glPopMatrix();



		glPushMatrix();

			glPushMatrix();		
				glTranslated(0,10,0);
					glScaled(14,10,14);
					WoodenBox *woodenbox83 = new  WoodenBox(false , textureWoodenBoxAlex);
						woodenbox83->draw(0);
					free(woodenbox83);
			glPopMatrix();

			glPushMatrix();		
					glTranslated(-14,10,0);
					glScaled(14,10,14);
					WoodenBox *woodenbox84 = new  WoodenBox(false , textureWoodenBoxAlex);
						woodenbox84->draw(0);
					free(woodenbox84);
			glPopMatrix();

		glPopMatrix();
		


		glPushMatrix();

			glPushMatrix();		
				glTranslated(0,10,14);
					glScaled(14,10,14);
					WoodenBox *woodenbox85 = new  WoodenBox(false , textureWoodenBoxAlex);
						woodenbox85->draw(0);
					free(woodenbox85);
			glPopMatrix();

			glPushMatrix();		
					glTranslated(-14,10,14);
					glScaled(14,10,14);
					WoodenBox *woodenbox86 = new  WoodenBox(false, textureWoodenBoxAlex);
						woodenbox86->draw(0);
					free(woodenbox86);
			glPopMatrix();

		glPopMatrix();


		glPushMatrix();
			glColor3d(0.33,0.33,0.33);
			carAll->Draw();
			carAll->Materials[0].tex=BARK;
			carAll->Materials[1].tex=Leaf;
			glColor3d(1,1,1);
		glPopMatrix();
	glPopMatrix();
	//////////////////////////////////////////////////////

	glPushMatrix();

	// glTranslated(-36,0,18);

		glTranslated(-36,0,-22);
			glRotated(-90,0,1,0);
			glColor3d(1,1,1);
		glPushMatrix();
			glTranslated(-5,14,5);
			glScaled(14,13,14);
			WoodenBox *woodenbox91 = new  WoodenBox(openBoxsAlex[5] , textureWoodenBoxAlex);
				woodenbox91->draw(openBoxsAlex[5]);
			free(woodenbox91);
		glPopMatrix();
	
		glPushMatrix();
			glColor3d(0.33,0.33,0.33);
			glRotated(180,0,1,0);
			glRotated(-45,1,0,0);
			if(openBoxsAlex[5] > 20){
				Coati->pos.y = 3.5;
				Coati->pos.z = 15.5;
			}
			else{
				glRotated(0,1,0,0);
				Coati->pos.z = 1;
				Coati->pos.y = 1.;
			}
			
			Coati->pos.x = 0;
			
			Coati->scale = 15;

			Coati->Draw();
			//CoatiAngle+=0.1;
			
		glPopMatrix();
			
	glPopMatrix();

	//////////////////////////////////////////////////////

	if(keys['O']) //open 
	{
		

		if( !outerCollisionAlex(25+transXalex,45+transXalex,10+transZalex,30+transZalex,camPos)){
			if(openBoxsAlex[0] <= 90){
				s2[1]++;
				if (s2[1]==12)
				{
					PlaySound("sounds\\boxopen.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
					s2[1]=0;
				}
				
				openBoxsAlex[0]+=5;
			}
		}

		if(!outerCollisionAlex(20+transXalex,45+transXalex,-30+transZalex,-10+transZalex,camPos)){
			if(openBoxsAlex[1] == 0){
				s2[2]++;
				if (s2[2]==12)
				{
					PlaySound("sounds\\boxopen.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
					s2[2]=0;
				}
				openBoxsAlex[1]=1;
			}
		}

		
		if( !outerCollisionAlex(-25+transXalex,0+transXalex,-60+transZalex,-35+transZalex,camPos)){
			if(openBoxsAlex[2] <= 90){
				s2[3]++;
				if (s2[3]==12)
				{
					PlaySound("sounds\\boxopen.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
					s2[3]=0;
				}
				openBoxsAlex[2]+=5;
			}
		}



		if( !outerCollisionAlex(-45+transXalex,-25+transXalex,10+transZalex,25+transZalex,camPos)){
			if(openBoxsAlex[3] <= 90){
				s2[4]++;
				if (s2[4]==12)
				{
					PlaySound("sounds\\boxopen.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
					s2[4]=0;
				}
				openBoxsAlex[3]+=5;
			}
		}

		if( !outerCollisionAlex(5+transXalex,30+transXalex,-60+transZalex,-38+transZalex,camPos)){
			if(openBoxsAlex[4] <= 90){
				s2[5]++;
				if (s2[5]==12)
				{
					PlaySound("sounds\\boxopen.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
					s2[5]=0;
				}
				openBoxsAlex[4]+=5;
			}
		}


		if( !outerCollisionAlex(-45+transXalex,-25+transXalex,-30+transZalex,0+transZalex,camPos)){
			if(openBoxsAlex[5] <= 90){
				s2[6]++;
				if (s2[6]==12)
				{
					PlaySound("sounds\\boxopen.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
				}
				if (s2[6]==20)
				{
					PlaySound("sounds\\ratSound.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
					s2[6]=0;
				}
				openBoxsAlex[5]+=5;
			}
		}


	}

	if(keys['P']) //close 
	{
		
		

		if( !outerCollisionAlex(25+transXalex,45+transXalex,10+transZalex,30+transZalex,camPos)){
			if(openBoxsAlex[0] >= 5){
				s2[7]++;
				if (s2[7]==12)
				{
					PlaySound("sounds\\boxopen.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
					s2[7]=0;
				}
				openBoxsAlex[0]-=5;
			}
		}

		if(!outerCollisionAlex(20+transXalex,45+transXalex,-30+transZalex,-10+transZalex,camPos)){
			if(openBoxsAlex[1] == 1){
			s2[8]++;
				if (s2[8]==12)
				{
					PlaySound("sounds\\boxopen.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
					s2[8]=0;
				}
				openBoxsAlex[1]=0;
			}
		}

		if( !outerCollisionAlex(-25+transXalex,0+transXalex,-60+transZalex,-35+transZalex,camPos)){
			if(openBoxsAlex[2] >= 5){
				s2[9]++;
				if (s2[9]==12)
				{
					PlaySound("sounds\\boxopen.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
					s2[9]=0;
				};
				openBoxsAlex[2]-=5;
			}
		}


		if( !outerCollisionAlex(-45+transXalex,-25+transXalex,10+transZalex,25+transZalex,camPos)){
			if(openBoxsAlex[3] >= 5){
				s2[10]++;
				if (s2[10]==12)
				{
					PlaySound("sounds\\boxopen.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
					s2[10]=0;
				}
				openBoxsAlex[3]-=5;
			}
		}

		if( !outerCollisionAlex(5+transXalex,30+transXalex,-60+transZalex,-38+transZalex,camPos)){
			if(openBoxsAlex[4] >= 5){
				s2[11]++;
				if (s2[11]==12)
				{
					PlaySound("sounds\\boxopen.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
					s2[11]=0;
				}
				openBoxsAlex[4]-=5;
			}
		}

		if( !outerCollisionAlex(-45+transXalex,-25+transXalex,-30+transZalex,0+transZalex,camPos)){
			if(openBoxsAlex[5] >= 5){
				s2[12]++;
				if (s2[12]==12)
				{
					PlaySound("sounds\\boxopen.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
					s2[12]=0;
				}
				openBoxsAlex[5]-=5;
			}
		}


	}

	// 

	if(keys['O']) //open
	{
		if(!outerCollisionAlex(-30+transXalex,30+transXalex,40+transZalex,80+transZalex,camPos)){
			frontDoorStateAlex=1;
			PlaySound("sounds\\doormove.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
		Sleep(400);
		}
	}

	if(keys['P']) //close
	{
		if(!outerCollisionAlex(-30+transXalex,30+transXalex,40+transZalex,80+transZalex,camPos)){
			frontDoorStateAlex=0;
			PlaySound("sounds\\doormove.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
		Sleep(400);
		}
	}



	glPushMatrix();
		glScaled(10,10,10);
		Trailer *tr = new Trailer(textureWoodenFloorAlex,textureWoodenInnerTrainSideAlex,textureCeilingAlex,textureWoodenInnerTrainSideAlex,textureTrainSideAlex,textureGlassAlex,textureDoorAlex); 
		tr->draw(frontDoorStateAlex);
		free(tr);
	glPopMatrix();



	glPopMatrix();
}

