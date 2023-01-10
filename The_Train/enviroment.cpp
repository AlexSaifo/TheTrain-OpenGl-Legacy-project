#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <Quad.h>
#include <texture.h>
#include <cubid.h>
#include <Tree.h>

int mode = 0;
/*
texture[0][i] for day mode
texture[1][i] for night mode
texture[2][i] for space mode
*/
int textures[3][6];
void intiDayMode(){
	textures[0][0] = LoadTexture("textures/skyboxes/groundDayTexture.bmp"); // ground
	textures[0][1] = LoadTexture("textures/skyboxes/skyDayTexture.bmp"); // sky
	textures[0][2] = LoadTexture("textures/skyboxes/side1DayTexture.bmp"); // first side
	textures[0][3] = LoadTexture("textures/skyboxes/side2DayTexture.bmp"); // second side
	textures[0][4] = LoadTexture("textures/skyboxes/side3DayTexture.bmp"); // third side
	textures[0][5] = LoadTexture("textures/skyboxes/side4DayTexture.bmp"); // fourth side
}

void initNightMode(){
	textures[1][3] = LoadTexture("textures/skyboxes/side2NightTexture.bmp"); // second side
}



void drawSides(){
	
	glPushMatrix();
		glTranslated(-5000,-20,-1090);
		glScaled(10000,10000,10000);
		cubid *cub=new cubid(textures[mode][1],textures[mode][0],textures[mode][5],textures[mode][4],textures[mode][3],textures[mode][2]);
		glColor3f(1,1,1);
		cub->draw();
		free(cub);
	glPopMatrix();

}

void metro(double posZ)
{
	

	glPushMatrix();
	
	
		glScaled(0.1,0.1,1);
		glTranslated(-5000,-350,-11500);
		

		//////////////////////
		if(posZ < 9000 && posZ != -1){
			glPushMatrix();
				glColor3d(0,0,0);
				Point *p111 = new Point(3500,0,20400);
				Point *p222 = new Point(6500,0,20400);
				Point *p333 = new Point(6500,1000,20400);
				Point *p444 = new Point(3500,1000,20400);
				Quad *q1234 = new Quad(p111,p222,p333,p444);
				q1234->draw();
				free(p111);
				free(p222);
				free(p333);
				free(p444);
				free(q1234);
				glColor3d(1,1,1);
			glPopMatrix();
		}
		
		//////////////////////
		glColor3d(0.4,0.4,0.4);

		//right
		Point *p9 = new Point(6500,0,20000);
		Point *p10 = new Point(6500,1000,20000);
		Point *p11 = new Point(6500,1000,25000);
		Point *p12 = new Point(6500,0,25000);
		Quad *q3 = new Quad(p9,p10,p11,p12);
		q3->draw();
		free(p9);
		free(p10);
		free(p11);
		free(p12);
		free(q3);

		//left
		Point *p13 = new Point(3500,0,20000);
		Point *p14 = new Point(3500,1000,20000);
		Point *p15 = new Point(3500,1000,25000);
		Point *p16 = new Point(3500,0,25000);
		Quad *q4 = new Quad(p13,p14,p15,p16);
		q4->draw();
		free(p13);
		free(p14);
		free(p15);
		free(p16);
		free(q4);

		//up
		Point *p17 = new Point(3500,1000,20000);
		Point *p18 = new Point(3500,1000,25000);
		Point *p19 = new Point(6500,1000,25000);
		Point *p20 = new Point(6500,1000,20000);
		Quad *q5 = new Quad(p17,p18,p19,p20);
		q5->draw();
		free(p17);
		free(p18);
		free(p19);
		free(p20);
		free(q5);

		//down
		Point *p21 = new Point(3500,0,20000);
		Point *p22 = new Point(3500,0,25000);
		Point *p23 = new Point(6500,0,25000);
		Point *p24 = new Point(6500,0,20000);
		Quad *q6 = new Quad(p21,p22,p23,p24);
		q6->draw();
		free(p21);
		free(p22);
		free(p23);
		free(p24);
		free(q6);
		glColor3d(1,1,1);
	glPopMatrix();
}