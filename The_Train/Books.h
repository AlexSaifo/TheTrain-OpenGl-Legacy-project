#pragma once
#include "drawable.h"
class Books :
	public Drawable
{
public:
	int cover1 , cover2, cover3, cover4;
	Books(void);
	Books(int cover1,int cover2,int cover3, int cover4);
	~Books(void);
	void draw(void);
private:
	void drawOneBook(int cover,float,float y);
	void drawBooksInShelf(float,float);
	void drawIn1();
	void drawIn2();
};

