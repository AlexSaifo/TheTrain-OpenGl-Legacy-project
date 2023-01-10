#pragma once
class Trailer
{
public:
	int last;
	int floorTexture,outerCeilingTexture,innerCeilingTexture,outerSideTexture,innerSideTexture,windowTexture,doorTexture;
	Trailer(void);
	Trailer(int floorTexture,int innerCeilingTexture,int outerCeilingTexture,int innerSideTexture,int outerSideTexture,int windowTexture,int doorTexture,int last=-1);
	~Trailer(void);
	void drawFrontBack(int texture);
	void draw(boolean backDoorState);
	void drawFrontBackDoorSides(int texture);
	void drawFrontBackDoorTop(int texture);
	void drawTrailerSide(int texture);
	void drawLeftRightWall(int texture);
	void drawFloorCeiling(int texture);
	void drawWindow(void);
	void drawWindows(void);
	void drawTrailerWithoutWindows(boolean backDoorState);
	
	

};

