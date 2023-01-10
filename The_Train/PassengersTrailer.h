#pragma once
class PassengersTrailer
{
public:
	bool *keys;

	Point *translate;
	//curtains interaction
	float w1[3][2],tran1[3][2];
	//door interaction
	bool backDoorState;
	int last;
	float s[13];
	PassengersTrailer(bool *keys);
	void init1();
	void Translate(Point *translate);
	bool innerCollision1(float minX,float maxX,float minZ,float maxZ,Point *cam);
	bool outerCollision1(float minX,float maxX,float minZ,float maxZ,Point *cam);
	bool collision(Point *cam);
	void openCurtains(int i,int j);
	void closeCurtains(int i,int j);
	void interact(Point *pos);
	void drawPart(float vv=0,float trann=2);
	void draw1(Point *cam,int last=-1);
	~PassengersTrailer(void);
};

