#pragma once
#include "drawable.h"
class Table :
	public Drawable
{
public:
	int texture;
	Table(void);
	Table(int texture);
	~Table(void);
	void leg(void);
	void tableTop(void);
	void draw(void);
};

