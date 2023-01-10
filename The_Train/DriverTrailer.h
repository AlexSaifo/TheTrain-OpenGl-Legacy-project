
#include <windows.h>
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <Point.h>
#pragma once

class DriverTrailer 
	
{
public:
	void kh2interact(Point *nxt,bool keys[]);
	Point *player;
	bool *keys;float x;float z;
	void kh2tran(float x,float y);
	bool kh2collision(Point *cam);
	bool kh2outerCollision(float minX,float maxX,float minZ,float maxZ,Point *cam);
		bool kh2innerCollision(float minX,float maxX,float minZ,float maxZ,Point *cam);
	int top, InsideTop,  bottom,  wall, InsideSides,  cp, sides, front;
	int rooftexture,WallPaint,textureDoor,textureTrainSide,textureFloor;
	int cylin[3];
	int textures[6];
	void drawDtrailer();
	
    void loadkh1texture();
	void draw(void);
	DriverTrailer(Point *player,bool *keys);
	~DriverTrailer(void);
private:
void drawWithTexture();


};

