#pragma once
#include "drawable.h"
#include <Cylinder.h>


class Flower :
	public Drawable
{
public:
	int flower_petal, flower_stem, flower_disk_florets;
	Flower(int flower_petal = -1, int flower_stem = -1, int flower_disk_florets = -1);
	~Flower(void);
	void draw();

private:
	Point *leavies[60 * 3];
	float distance(Point *p1, Point *p2);
};

