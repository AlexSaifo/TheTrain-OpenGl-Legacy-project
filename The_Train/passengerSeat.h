#include"color.h"
#include"Point.h"
#pragma once
class passengerSeat
{
public:

	color *handRestsColor,*baseColor;
	int seatTexture;
	passengerSeat(void);
	passengerSeat(color *baseCol,color *handRestsCol,int seatText);
	void drawBase(Point*p1,Point*p2,Point*p3,Point*p4,Point*p5,Point*p6,Point*p7,Point*p8);
	void drawSeat(Point*p1,Point*p2,Point*p3,Point*p4,int texture);
	void drawHandRests(Point*p1,Point*p2,Point*p3,Point*p4);
	void draw(int passenger=1);
	virtual ~passengerSeat(void);
};

