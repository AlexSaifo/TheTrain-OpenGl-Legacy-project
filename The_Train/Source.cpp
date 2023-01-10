/*
 *		This Code Was Created By Jeff Molofee 2000
 *		A HUGE Thanks To Fredric Echols For Cleaning Up
 *		And Optimizing This Code, Making It More Flexible!
 *		If You've Found This Code Useful, Please Let Me Know.
 *		Visit My Site At nehe.gamedev.net
 */

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
#include<Curtains.h>
#include<passengerSeat.h>
#include<color.h>
#include<Table.h>
#include<Chair.h>
#include <WoodenBox.h>
#include <Barrel.h>
#include <Lamppost.h>
#include <AlexTrailer.h>
#include <CinemaPlotter.h>
#include<PassengersTrailer.h>
#include<StudyT.h>
#include<DriverTrailer.h>
#include<enviroment.h>



using namespace std;

HDC			hDC=NULL;		// Private GDI Device Context
HGLRC		hRC=NULL;		// Permanent Rendering Context
HWND		hWnd=NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active=TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen=TRUE;	// Fullscreen Flag Set To Fullscreen Mode By Default

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}

	glViewport(0,0,width,height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100000.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}
Camera c, c1, winC,tempCam;
float xCamera=0, yCamera=20, zCamera=25;
float speed =5 ;
bool isTrainMoving = true;

int textures[3];

int textureSkyboxFront,textureSkyboxBack,textureSkyboxRight,textureSkyboxLeft,textureSkyboxTop ;

DriverTrailer *dri = new DriverTrailer(new Point(tempCam.Position.x,tempCam.Position.y,tempCam.Position.z),keys);

StudyT *stu=new StudyT(new Point(tempCam.Position.x,tempCam.Position.y,tempCam.Position.z),keys);
StudyT *stu2=new StudyT(new Point(tempCam.Position.x,tempCam.Position.y,tempCam.Position.z),keys);

AlexTrailer *AT  = new AlexTrailer(keys);
AlexTrailer *AT2  = new AlexTrailer(keys);

CinemaPlotter *cinema = new CinemaPlotter();
CinemaPlotter *cinema2 = new CinemaPlotter();

PassengersTrailer *trailer1=new PassengersTrailer(keys);
PassengersTrailer *trailer2=new PassengersTrailer(keys);
PassengersTrailer *trailer3=new PassengersTrailer(keys);
int view = 0;
Camera freeCam;

bool leg=0,movv=0;

int textureInnerSide111;
int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);

	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);

	GLfloat lightPos211[]={0,4000,0,1.0f};
	GLfloat lightAmp211[]={1,1,1,1.0f};
	GLfloat lightDiff211[]={0,0,0,1.0f};
	GLfloat lightSpec211[]={0,0,0,1.0f};


	glLightfv(GL_LIGHT0,GL_POSITION,lightPos211);
	glLightfv(GL_LIGHT0,GL_AMBIENT,lightAmp211);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightDiff211);
	glLightfv(GL_LIGHT0,GL_SPECULAR,lightSpec211);
	
	GLfloat lightPos[]={0,45,0,1.0f};
	GLfloat lightAmp[]={0.8,0.8,0.8,1.0f};
	GLfloat lightDiff[]={0,0,0,1.0f};
	GLfloat lightSpec[]={0,0,0,1.0f};


	glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
	glLightfv(GL_LIGHT0,GL_AMBIENT,lightAmp);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightDiff);
	glLightfv(GL_LIGHT0,GL_SPECULAR,lightSpec);

	GLfloat lightPos1[]={0,45,-120,1.0f};
	GLfloat lightAmp1[]={0.8,0.8,0.8,1.0f};
	GLfloat lightDiff1[]={0,0,0,1.0f};
	GLfloat lightSpec1[]={0,0,0,1.0f};


	glLightfv(GL_LIGHT0,GL_POSITION,lightPos1);
	glLightfv(GL_LIGHT0,GL_AMBIENT,lightAmp1);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightDiff1);
	glLightfv(GL_LIGHT0,GL_SPECULAR,lightSpec1);
	

	GLfloat lightPos2[]={0,45,-240,1.0f};
	GLfloat lightAmp2[]={0.8,0.8,0.8,1.0f};
	GLfloat lightDiff2[]={0,0,0,1.0f};
	GLfloat lightSpec2[]={0,0,0,1.0f};


	glLightfv(GL_LIGHT0,GL_POSITION,lightPos2);
	glLightfv(GL_LIGHT0,GL_AMBIENT,lightAmp2);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightDiff2);
	glLightfv(GL_LIGHT0,GL_SPECULAR,lightSpec2);


	GLfloat lightPos3[]={0,45,-360,1.0f};
	GLfloat lightAmp3[]={0.8,0.8,0.8,1.0f};
	GLfloat lightDiff3[]={0,0,0,1.0f};
	GLfloat lightSpec3[]={0,0,0,1.0f};


	glLightfv(GL_LIGHT0,GL_POSITION,lightPos3);
	glLightfv(GL_LIGHT0,GL_AMBIENT,lightAmp3);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightDiff3);
	glLightfv(GL_LIGHT0,GL_SPECULAR,lightSpec3);

	GLfloat lightPos4[]={0,45,-480,1.0f};
	GLfloat lightAmp4[]={0.8,0.8,0.8,1.0f};
	GLfloat lightDiff4[]={0,0,0,1.0f};
	GLfloat lightSpec4[]={0,0,0,1.0f};


	glLightfv(GL_LIGHT0,GL_POSITION,lightPos4);
	glLightfv(GL_LIGHT0,GL_AMBIENT,lightAmp4);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightDiff4);
	glLightfv(GL_LIGHT0,GL_SPECULAR,lightSpec4);

	GLfloat lightPos5[]={0,45,-600,1.0f};
	GLfloat lightAmp5[]={0.8,0.8,0.8,1.0f};
	GLfloat lightDiff5[]={0,0,0,1.0f};
	GLfloat lightSpec5[]={0,0,0,1.0f};


	glLightfv(GL_LIGHT0,GL_POSITION,lightPos5);
	glLightfv(GL_LIGHT0,GL_AMBIENT,lightAmp5);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightDiff5);
	glLightfv(GL_LIGHT0,GL_SPECULAR,lightSpec5);


	GLfloat lightPos6[]={0,45,-720,1.0f};
	GLfloat lightAmp6[]={0.8,0.8,0.8,1.0f};
	GLfloat lightDiff6[]={0,0,0,1.0f};
	GLfloat lightSpec6[]={0,0,0,1.0f};


	glLightfv(GL_LIGHT0,GL_POSITION,lightPos6);
	glLightfv(GL_LIGHT0,GL_AMBIENT,lightAmp6);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightDiff6);
	glLightfv(GL_LIGHT0,GL_SPECULAR,lightSpec6);

	GLfloat lightPos7[]={0,45,-840,1.0f};
	GLfloat lightAmp7[]={0.8,0.8,0.8,1.0f};
	GLfloat lightDiff7[]={0,0,0,1.0f};
	GLfloat lightSpec7[]={0,0,0,1.0f};


	glLightfv(GL_LIGHT0,GL_POSITION,lightPos7);
	glLightfv(GL_LIGHT0,GL_AMBIENT,lightAmp7);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightDiff7);
	glLightfv(GL_LIGHT0,GL_SPECULAR,lightSpec7);
	

	GLfloat lightPos8[]={0,45,-960,1.0f};
	GLfloat lightAmp8[]={0.8,0.8,0.8,1.0f};
	GLfloat lightDiff8[]={0,0,0,1.0f};
	GLfloat lightSpec8[]={0,0,0,1.0f};


	glLightfv(GL_LIGHT0,GL_POSITION,lightPos8);
	glLightfv(GL_LIGHT0,GL_AMBIENT,lightAmp8);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightDiff8);
	glLightfv(GL_LIGHT0,GL_SPECULAR,lightSpec8);


	GLfloat lightPos9[]={0,45,-1080,1.0f};
	GLfloat lightAmp9[]={0.8,0.8,0.8,1.0f};
	GLfloat lightDiff9[]={0,0,0,1.0f};
	GLfloat lightSpec9[]={0,0,0,1.0f};


	glLightfv(GL_LIGHT0,GL_POSITION,lightPos9);
	glLightfv(GL_LIGHT0,GL_AMBIENT,lightAmp9);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightDiff9);
	glLightfv(GL_LIGHT0,GL_SPECULAR,lightSpec9);

	GLfloat lightPos10[]={0,45,-1200,1.0f};
	GLfloat lightAmp10[]={0.8,0.8,0.8,1.0f};
	GLfloat lightDiff10[]={0,0,0,1.0f};
	GLfloat lightSpec10[]={0,0,0,1.0f};


	glLightfv(GL_LIGHT0,GL_POSITION,lightPos10);
	glLightfv(GL_LIGHT0,GL_AMBIENT,lightAmp10);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightDiff10);
	glLightfv(GL_LIGHT0,GL_SPECULAR,lightSpec10);

	GLfloat lightPos11[]={0,45,-1320,1.0f};
	GLfloat lightAmp11[]={0.8,0.8,0.8,1.0f};
	GLfloat lightDiff11[]={0,0,0,1.0f};
	GLfloat lightSpec11[]={0,0,0,1.0f};


	glLightfv(GL_LIGHT0,GL_POSITION,lightPos11);
	glLightfv(GL_LIGHT0,GL_AMBIENT,lightAmp11);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightDiff11);
	glLightfv(GL_LIGHT0,GL_SPECULAR,lightSpec11);



	GLfloat MatAmb[]={0.5,0.5,0.5,1.0f};
	GLfloat MatDif[]={1,1,1,1.0f};
	GLfloat MatSpec[]={1,1,1,1.0f};
	GLfloat MatShn[]={127};


	glMaterialfv(GL_FRONT,GL_AMBIENT,MatAmb);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,MatDif);
	glMaterialfv(GL_FRONT,GL_SPECULAR,MatSpec);
	glMaterialfv(GL_FRONT,GL_SHININESS,MatShn);
	glMateriali(GL_FRONT,GL_SHININESS,128);


	stu->loadkhtexture();
	dri->loadkh1texture();
	cinema->initializeCinemaTextures();
	trailer1->init1();
	AT->AlexTrailerInit();


	stu2->loadkhtexture();
	cinema2->initializeCinemaTextures();
	trailer2->init1();
	AT2->AlexTrailerInit();

	trailer3->init1();


			textures[0] = LoadTexture("wall6.bmp");
			textures[1] = LoadTexture("wall6.bmp");
			textures[2] = LoadTexture("wall6.bmp");
				textures[3] = LoadTexture("wall6.bmp");
	textureSkyboxFront=LoadTexture("skyboxtexture2Front.bmp");
	textureSkyboxBack=LoadTexture("skyboxtexture2Back.bmp");
	textureSkyboxRight=LoadTexture("skyboxtexture2Right.bmp");
	textureSkyboxLeft=LoadTexture("skyboxtexture2Left.bmp");
	textureSkyboxTop=LoadTexture("skyboxtexture2Top.bmp");

	intiDayMode();
	textureInnerSide111=LoadTexture("wall6.bmp");

	c = Camera(xCamera,yCamera, zCamera,0);
	tempCam=Camera(xCamera,yCamera, zCamera,0);
	freeCam = Camera(xCamera,yCamera, zCamera,0);
	return TRUE;										// Initialization Went OK
}
boolean innerCollision(float minX,float maxX,float minZ,float maxZ,Point *cam)
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
boolean outerCollision(float minX,float maxX,float minZ,float maxZ,Point *cam)
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
boolean collision(Point *cam)
{
	
	return  AT->collisionAlex(cam) && trailer1->collision(cam) && cinema->innerCollisionCinema(cam) && stu->khcollision(cam) &&dri->kh2collision(cam)
		  && AT2->collisionAlex(cam) && trailer2->collision(cam) && cinema2->innerCollisionCinema(cam) && stu2->khcollision(cam)  && 
		  trailer3->collision(cam);

}

int numOfSound = 0;
int numberOfFrame = 0;
void moveSounde(){
  if(numberOfFrame % 5 == 0){
    if(numOfSound){
      PlaySound("sounds\\pl_dirt1.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC );
    }
    else{
      PlaySound("sounds\\pl_dirt2.wav", NULL, SND_FILENAME | SND_ALIAS | SND_ASYNC);
    }
      numOfSound ^= 1;  
  }
  numberOfFrame++;
}
void camera()
{
  bool moved = false;
  movv=0;
  if (keys['W']) {
    
     if(view!=2)
    {
      tempCam.MoveForward(speed);
      Point *nxt=new Point(0,0,0);
      nxt->x=tempCam.Position.x;
      nxt->y=tempCam.Position.y;
      nxt->z=tempCam.Position.z;

      if(!collision(nxt))
        tempCam.MoveForward(-speed);
      else
      {
        moved = true;
        c.MoveForward(speed); 
      }
    }
    freeCam.MoveForward(speed); 
    
  }

  if (keys['S']) {
    
    if(view!=2)
    {
      tempCam.MoveForward(-speed);
      Point *nxt=new Point(0,0,0);
      nxt->x=tempCam.Position.x;
      nxt->y=tempCam.Position.y;
      nxt->z=tempCam.Position.z;


      if(!collision(nxt))
        tempCam.MoveForward(speed);
      else
        {
        moved = true;
        c.MoveForward(-speed); 
        }
    }
    freeCam.MoveForward(-speed); 
  }

  if (keys['A']) {   
    
    if(view!=2)
      {tempCam.MoveRight(-speed);
      Point *nxt=new Point(0,0,0);
      nxt->x=tempCam.Position.x;
      nxt->y=tempCam.Position.y;
      nxt->z=tempCam.Position.z;


      if(!collision(nxt))
        tempCam.MoveRight(speed);
      else
        {
        moved = true;
        c.MoveRight(-speed); 
        }
        
    }
    freeCam.MoveRight(-speed); 
  }

  if (keys['D']) {
    
    if(view!=2)
    {
      tempCam.MoveRight(speed);
      Point *nxt=new Point(0,0,0);
      nxt->x=tempCam.Position.x;
      nxt->y=tempCam.Position.y;
      nxt->z=tempCam.Position.z;


      if(!collision(nxt))
        tempCam.MoveRight(-speed);
      else
        {
        moved = true;
        c.MoveRight(speed);
        }
        
    }  
    freeCam.MoveRight(speed); 
  }

  if (keys[VK_LEFT])  {
    
    if(view!=2)
    {
      tempCam.RotateY(5);
      Point *nxt=new Point(0,0,0);
      nxt->x=tempCam.Position.x;
      nxt->y=tempCam.Position.y;
      nxt->z=tempCam.Position.z;

      if(!collision(nxt))
        tempCam.RotateY(-5);
      else
        {
        moved = true;
        c.RotateY(5);
        }

        
    }
    freeCam.RotateY(5);
    
  }
  if (keys[VK_RIGHT])  {
    
    if(view!=2)
    {
      tempCam.RotateY(-5);
      Point *nxt=new Point(0,0,0);
      nxt->x=tempCam.Position.x;
      nxt->y=tempCam.Position.y;
      nxt->z=tempCam.Position.z;

      if(!collision(nxt))
        tempCam.RotateY(5);
      else
        {
        moved = true;
        c.RotateY(-5);
        }
        
    }
    freeCam.RotateY(-5);

  }
  if (keys[VK_UP] )  {
    
    if(view!=2)
    {
      tempCam.RotateX(-5);
      Point *nxt=new Point(0,0,0);
      nxt->x=tempCam.Position.x;
      nxt->y=tempCam.Position.y;
      nxt->z=tempCam.Position.z;
    

      if(!collision(nxt))
        tempCam.RotateX(5);
      else
        c.RotateX(-5); 
    }
    freeCam.RotateX(-5);
  }
  if (keys[VK_DOWN])  {
    
    if(view!=2)
    {
      tempCam.RotateX(5);
      Point *nxt=new Point(0,0,0);
      nxt->x=tempCam.Position.x;
      nxt->y=tempCam.Position.y;
      nxt->z=tempCam.Position.z;
    

      if(!collision(nxt))
        tempCam.RotateX(-5);
      else
        {
        moved = true;
        c.RotateX(5);
        }
        
    }
    freeCam.RotateX(5);
  }
  if(keys['Q'])
  {
    freeCam.MoveUpward(speed);
  }
  if(keys['E'])
  {
    freeCam.MoveUpward(-speed);
  }
  c1 = c;
  c1.MoveForward(-26.5);
  c1.MoveUpward(12);

  if(view==0)
    c.Render();
  else if(view==1)
    c1.Render();
  else
    freeCam.Render();
  if(moved){
    moveSounde();
	movv=1;
	leg^=1;
  }
}
void drawlamp(){
glPushMatrix();
	float x=0;
	float y=0;
	Lamppost *lam=new Lamppost(true,textures);
	glScaled(4,6,4);
	glRotated(90,0,1,0);
	for (int i = 0; i < 200; i++)
	{glPushMatrix();
		glTranslated(-10000+x,-2,17);
	lam->draw();
	x+=60;
	glPopMatrix();
	}
	
	for (int i = 0; i < 200; i++)
	{
		glPushMatrix();
		glTranslated(-10000+y,-2,-17);
	glRotated(180,0,1,0);
	lam->draw();
	y+=60;;
	glPopMatrix();
	}
	glPopMatrix();
}
void drawska(){
glPushMatrix();
	glScaled(0.4,1,1);
	glPushMatrix();
	float x=4;
	float y=4;
	float z=4;
	glColor3ub(165,42,42);
	glTranslated(-95,-20,-960);
	glScaled(20,20,40);
	
	cubid *ska=new cubid();
	for (int i = 0; i < 500; i++)
	{
		glPushMatrix();
		glTranslated(0,0,x);
		ska->draw();
		x+=1;
		glPopMatrix();
	}
	for (int i1 = 0; i1 < 500; i1++)
	{
		glPushMatrix();
		glTranslated(8.6,0,y);
		ska->draw();
		y+=1;
		glPopMatrix();
	}
	for (int i1 = 0; i1 < 500; i1++)
	{
		glPushMatrix();
		
		glTranslated(-2,0,z);
		glScaled(14,0.5,0.3);
		ska->draw();
		z+=1;
		glPopMatrix();
	}
	glColor3ub(255,255,255);
	glPopMatrix();
		glPopMatrix();
}
void drawCubid()
{
	glPushMatrix();
		glTranslated(-0.5,0,-0.5);
		cubid *player=new cubid();
		player->draw();

		free(player);
	glPopMatrix();
}
void drawPlayer()
{
	//Player
	glPushMatrix();
	Camera cc = Camera(c);
	cc.MoveForward(-2);
	glTranslated(cc.Position.x,0,cc.Position.z	);
		glRotated(cc.RotatedY,0,1,0);

	float rightAngle=0;
	float leftAngle=0;

	if(movv){
		if(leg){
		  rightAngle=20;
		}
		else{
		  leftAngle=20;
		}  
	}

		//leftleg
		glPushMatrix();
			glTranslated(0,8,0);
			glRotated(leftAngle,1,0,0);
			glTranslated(0,-8,0);

			
			glColor3f(0.27,0.17,0);
			glPushMatrix();
				glTranslated(-0.95,0,0);
				glScaled(1.9,2,2);
				drawCubid();
			glPopMatrix();
			glColor3f(0.11,0,0.58);
			glPushMatrix();
				glTranslated(-0.95,2,0);
				glScaled(1.9,6,2);
				drawCubid();
			glPopMatrix();

		glPopMatrix();
		
		
		//rightleg
		glPushMatrix();
			glTranslated(0,8,0);
			glRotated(rightAngle,1,0,0);
			glTranslated(0,-8,0);	
		
		
			glColor3f(0.27,0.17,0);
			glPushMatrix();
				glTranslated(0.95,0,0);
				glScaled(1.9,2,2);
				drawCubid();
			glPopMatrix();

			glColor3f(0.11,0,0.58);
			glPushMatrix();
				glTranslated(0.95,2,0);
				glScaled(1.9,6,2);
				drawCubid();
			glPopMatrix();
		glPopMatrix();

		/*//legs
		
		glPushMatrix();
			glTranslated(-0.880,2,0);
			glScaled(1.75,6,2);
			drawCubid();
		glPopMatrix();

		glPushMatrix();
			glTranslated(0.880,2,0);
			glScaled(1.75,6,2);
			drawCubid();
		glPopMatrix();*/
		
		glColor3f(0,0,0);
		glPushMatrix();
			//glTranslated(0.875,2,0);
			glScaled(0.2,8,2);
			drawCubid();
		glPopMatrix();


		//body
		glColor3f(0,0.89,0.83);
		glPushMatrix();
			glTranslated(0,8,0);
			glScaled(3.5,6,2);
			drawCubid();
		glPopMatrix();


		//shoulders
		glPushMatrix();
			glTranslated(2.625,12,0);
			glScaled(1.75,2,2);
			drawCubid();
		glPopMatrix();

		glPushMatrix();
			glTranslated(-2.625,12,0);
			glScaled(1.75,2,2);
			drawCubid();
		glPopMatrix();

		//arms
		glColor3f(1,0.8,0.58);
		glPushMatrix();
			glTranslated(2.625,7.5,0);
			glScaled(1.75,4.5,2);
			drawCubid();
		glPopMatrix();

		glPushMatrix();
			glTranslated(-2.625,7.5,0);
			glScaled(1.75,4.5,2);
			drawCubid();
		glPopMatrix();

		//head
		glColor3f(0.27,0.17,0);
		glPushMatrix();
			glTranslated(0,14,0);
			glScaled(3,3,3);
			drawCubid();
		glPopMatrix();
		
	glPopMatrix();

	glColor3f(1,1,1);


}
int moveTrain = 0;


bool cin1=1,cin2=1;
bool at1=1,at2=1;
bool st1=1,st2=1;
bool pas1=1,pas2=1,pas3=1;
bool dr=1;
void DrawGLScene(GLvoid)// Here's Where We Do All The Drawing
{
	

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();
	glScaled(0.05,0.05,0.05);
	

	
	/*******no translate********/
	camera();
		
	/********* with translate ********/
	glPushMatrix();

	if(keys['M']){
		isTrainMoving = !isTrainMoving;
		//Sleep(300);
	}

	if(isTrainMoving){
		glTranslatef(0,0,(moveTrain -=100));
	}
	drawska();
	drawlamp();
	if((moveTrain > -9000 &&  moveTrain < 1300)){
		drawSides();
	  }
  
	  // front metro 
	  metro(c.Position.z);

	  //end metro
	  glPushMatrix();
		glTranslated(0,0,-14000);
	  metro();
  
	  glPopMatrix();
	  glPopMatrix();
	  /*******with translate*******/
	

	
	if(keys['V'])
	{
		view++;
		view%=3;
		freeCam=c;
	}

	if(keys['L'])
	{
		if(innerCollision(-43,43,-60,60,new Point(c.Position.x,c.Position.y,c.Position.z)))
		{
			at1^=1;
		}
		if(innerCollision(-43,43,-180,-60,new Point(c.Position.x,c.Position.y,c.Position.z)))
		{
			cin1^=1;
		}
		if(innerCollision(-43,43,-300,-180,new Point(c.Position.x,c.Position.y,c.Position.z)))
		{
			pas1^=1;
		}
		if(innerCollision(-43,43,-420,-300,new Point(c.Position.x,c.Position.y,c.Position.z)))
		{
			st1^=1;
		}
		if(innerCollision(-43,43,-540,-420,new Point(c.Position.x,c.Position.y,c.Position.z)))
		{
			at2^=1;
		}
		if(innerCollision(-43,43,-660,-540,new Point(c.Position.x,c.Position.y,c.Position.z)))
		{
			pas2^=1;
		}
		if(innerCollision(-43,43,-780,-660,new Point(c.Position.x,c.Position.y,c.Position.z)))
		{
			cin2^=1;
		}
		if(innerCollision(-43,43,-900,-780,new Point(c.Position.x,c.Position.y,c.Position.z)))
		{
			st2^=1;
		}
		if(innerCollision(-43,43,-1020,-900,new Point(c.Position.x,c.Position.y,c.Position.z)))
		{
			pas3^=1;
		}
		if(innerCollision(-43,43,60,160,new Point(c.Position.x,c.Position.y,c.Position.z)))
		{
			dr^=1;
		}
		Sleep(200);
		
	}

	glTranslated(0,4,0);
	
	glEnable(GL_LIGHT0);
	drawPlayer();

	if(!at1)
		glDisable(GL_LIGHT0);

	AT->draw(new Point(tempCam.Position.x , tempCam.Position.y , tempCam.Position.z )); ///0
	AT->Transalate(0,0,0);

	glEnable(GL_LIGHT0);
	if(!cin1)
		glDisable(GL_LIGHT0);
	glPushMatrix();
		glTranslated(0,0,-120);
			cinema->drawCinema(new Point(0,0,-120));///120
			cinema->AlaaTrailerinteract(new Point(c.Position.x , c.Position.y , c.Position.z ),keys);
	glPopMatrix();

	glEnable(GL_LIGHT0);
	if(!pas1)
		glDisable(GL_LIGHT0);

	trailer1->Translate(new Point(0,0,-240));///240
	trailer1->draw1(new Point(tempCam.Position.x , tempCam.Position.y , tempCam.Position.z ));


	glEnable(GL_LIGHT0);
	if(!st1)
		glDisable(GL_LIGHT0);

	stu->draw();///360
	stu->khinteract(new Point(c.Position.x , c.Position.y , c.Position.z ),keys);
	stu->khtran(0,-360);

	glEnable(GL_LIGHT0);
	if(!dr)
		glDisable(GL_LIGHT0);

	dri->drawDtrailer();///1000000
	dri->kh2interact(new Point(c.Position.x , c.Position.y , c.Position.z ),keys);
	dri->kh2tran(0,100);
	///////////


	glEnable(GL_LIGHT0);
	if(!at2)
		glDisable(GL_LIGHT0);

	AT2->draw(new Point(tempCam.Position.x , tempCam.Position.y , tempCam.Position.z )); ///480
	AT2->Transalate(0,0,-480);

	glEnable(GL_LIGHT0);
	if(!pas2)
		glDisable(GL_LIGHT0);

	trailer2->Translate(new Point(0,0,-600));///600
	trailer2->draw1(new Point(tempCam.Position.x , tempCam.Position.y , tempCam.Position.z ));

	glEnable(GL_LIGHT0);
	if(!cin2)
		glDisable(GL_LIGHT0);

	glPushMatrix();
		glTranslated(0,0,-720);
			cinema2->drawCinema(new Point(0,0,-720));///720
			cinema2->AlaaTrailerinteract(new Point(c.Position.x , c.Position.y , c.Position.z ),keys);
	glPopMatrix();


	glEnable(GL_LIGHT0);
	if(!st2)
		glDisable(GL_LIGHT0);

	stu2->draw();///840
	stu2->khinteract(new Point(c.Position.x , c.Position.y , c.Position.z ),keys);
	stu2->khtran(0,-840);
	
	//////////////////////////////

	glEnable(GL_LIGHT0);
	if(!pas3)
		glDisable(GL_LIGHT0);

	glPushMatrix();
		trailer3->Translate(new Point(0,0,-960));//960
		trailer3->draw1(new Point(tempCam.Position.x , tempCam.Position.y , tempCam.Position.z ),textures[2]);
	glPopMatrix();
	/*******no translate********/
	if(moveTrain <= -11000){
		moveTrain = 2500;
	}
	glFlush();											// Done Drawing The Quad	

    //DO NOT REMOVE THIS
	SwapBuffers(hDC);		


	/*glPushMatrix();
			glTranslated(0,0,-780);
			Quad *trailer3Back = new Quad(new Point(43,0,0) , new Point(-43,0,0)  ,  new Point(-43,50,0) ,  new Point(43,50,0) , textureInnerSide111);
			trailer3Back->draw();
		glPopMatrix();*/
}

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL,0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL,NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL,"Release Of DC And RC Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL,"Release Rendering Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}
		hRC=NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd,hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL,"Release Device Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hDC=NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL,"Could Not Release hWnd.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hWnd=NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL",hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL,"Could Not Unregister Class.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hInstance=NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
 *	title			- Title To Appear At The Top Of The Window				*
 *	width			- Width Of The GL Window Or Fullscreen Mode				*
 *	height			- Height Of The GL Window Or Fullscreen Mode			*
 *	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
 *	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/
 
BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left=(long)0;			// Set Left Value To 0
	WindowRect.right=(long)width;		// Set Right Value To Requested Width
	WindowRect.top=(long)0;				// Set Top Value To 0
	WindowRect.bottom=(long)height;		// Set Bottom Value To Requested Height

	fullscreen=fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance			= GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc		= (WNDPROC) WndProc;					// WndProc Handles Messages
	wc.cbClsExtra		= 0;									// No Extra Window Data
	wc.cbWndExtra		= 0;									// No Extra Window Data
	wc.hInstance		= hInstance;							// Set The Instance
	wc.hIcon			= LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground	= NULL;									// No Background Required For GL
	wc.lpszMenuName		= NULL;									// We Don't Want A Menu
	wc.lpszClassName	= "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL,"Failed To Register The Window Class.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}
	
	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings,0,sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize=sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth	= width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight	= height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel	= bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields=DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL,"The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?","NeHe GL",MB_YESNO|MB_ICONEXCLAMATION)==IDYES)
			{
				fullscreen=FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL,"Program Will Now Close.","ERROR",MB_OK|MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle=WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle=WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle=WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle=WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd=CreateWindowEx(	dwExStyle,							// Extended Style For The Window
								"OpenGL",							// Class Name
								title,								// Window Title
								dwStyle |							// Defined Window Style
								WS_CLIPSIBLINGS |					// Required Window Style
								WS_CLIPCHILDREN,					// Required Window Style
								0, 0,								// Window Position
								WindowRect.right-WindowRect.left,	// Calculate Window Width
								WindowRect.bottom-WindowRect.top,	// Calculate Window Height
								NULL,								// No Parent Window
								NULL,								// No Menu
								hInstance,							// Instance
								NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Window Creation Error.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd=				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};
	
	if (!(hDC=GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Device Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat=ChoosePixelFormat(hDC,&pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Find A Suitable PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!SetPixelFormat(hDC,PixelFormat,&pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Set The PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC=wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!wglMakeCurrent(hDC,hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Activate The GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd,SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Initialization Failed.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(	HWND	hWnd,			// Handle For This Window
							UINT	uMsg,			// Message For This Window
							WPARAM	wParam,			// Additional Message Information
							LPARAM	lParam)			// Additional Message Information
{
	static PAINTSTRUCT ps;

	switch (uMsg)									// Check For Windows Messages
	{
		case WM_PAINT: 
			DrawGLScene();
			BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			return 0;
	
		case WM_TIMER:
			DrawGLScene();
			return 0;

		case WM_ACTIVATE:							// Watch For Window Activate Message
		{
			if (!HIWORD(wParam))					// Check Minimization State
			{
				active=TRUE;						// Program Is Active
			}
			else
			{
				active=FALSE;						// Program Is No Longer Active
			}

			return 0;								// Return To The Message Loop
		}

		case WM_SYSCOMMAND:							// Intercept System Commands
		{
			switch (wParam)							// Check System Calls
			{
				case SC_SCREENSAVE:					// Screensaver Trying To Start?
				case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
				return 0;							// Prevent From Happening
			}
			break;									// Exit
		}

		case WM_CLOSE:								// Did We Receive A Close Message?
		{
			PostQuitMessage(0);						// Send A Quit Message
			return 0;								// Jump Back
		}

		case WM_KEYDOWN:							// Is A Key Being Held Down?
		{
			keys[wParam] = TRUE;					// If So, Mark It As TRUE
			return 0;								// Jump Back
		}

		case WM_KEYUP:								// Has A Key Been Released?
		{
			keys[wParam] = FALSE;					// If So, Mark It As FALSE
			return 0;								// Jump Back
		}

		case WM_SIZE:								// Resize The OpenGL Window
		{
			ReSizeGLScene(LOWORD(lParam),HIWORD(lParam));  // LoWord=Width, HiWord=Height
			return 0;								// Jump Back
		}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}

int WINAPI WinMain(	HINSTANCE	hInstance,			// Instance
					HINSTANCE	hPrevInstance,		// Previous Instance
					LPSTR		lpCmdLine,			// Command Line Parameters
					int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done=FALSE;								// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen=FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("Madhat NeHe Template",640,480,16,fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}


	//Set drawing timer to 20 frame per second
	UINT timer=SetTimer(hWnd,20,0,(TIMERPROC) NULL);

	while (GetMessage(&msg, NULL, 0, 0)) 
	{
			TranslateMessage(&msg);	
			DispatchMessage(&msg);
	}

	return 0;

}
//GLAUX.lib;GLU32.lib;glut.lib;OPENGL32.lib;glut32.lib