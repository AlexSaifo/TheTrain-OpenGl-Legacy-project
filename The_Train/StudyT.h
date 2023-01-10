

#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include<Chair.h>
#include <Point.h>
#include<Curtains.h>
#include <Vase.h>
#include <Flower.h>


#pragma once


class StudyT
{
public:
	Vase *vas;
	int t[5];
	void khtran(float x,float z);
	void drawbooks(void);
	void drawOneBook(int cover ,float x ,float y);
	void drawBooksInShelf(float x,float y);
	void drawIn1();
    void drawIn2();
	float x,z;
	float s11[13];
	int backDoorState1;
	int rooftexture,textureDoor,textureTrainSide,textureFloor,textureGlass,WallPaint,bookCover,TableTexture,chairtexture;
	Point *player;
	bool khouterCollision(float minX,float maxX,float minZ,float maxZ,Point *cam);

	bool khinnerCollision(float minX,float maxX,float minZ,float maxZ,Point *cam);
    bool khcollision(Point *cam);
	bool *keys;
    float zcur[6];
    float xcur[6];
	StudyT(Point *player,bool *keys);
	~StudyT(void);
	void draw();
	void loadkhtexture();
	void khinteract(Point *nxt,bool *keys);
private:
void studyingcurtains(Curtains *curtain,int y,float x);
void khinteract(bool *keys);
void drawVase(char s);

void draw7waml(float x2);
void drawchair(Chair *ch,char s,int xchair);

	
};

