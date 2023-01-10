#pragma once
#include "drawable.h"
class Chair :
	public Drawable
{
public:
	int texture;
	Chair(void);
	Chair(int texture);
	~Chair(void);
	void draw(void);
};

