#pragma once
#include "drawable.h"
#include <Cylinder.h>
class Tree :
	public Drawable
{
public:
	int tree_bark, tree_leavies, tree_holder_texutre;
	Tree(int tree_bark = -1, int tree_leavies = -1, int tree_holder_texutre = -1);
	~Tree(void);
	void draw();
	void tree_holder();
};

