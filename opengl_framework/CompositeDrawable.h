#pragma once




#include <iostream>
#include <vector>
#include "IDrawable.h"
#include <memory>

class CompositeDrawable: public IDrawable
{
private:
	std::vector<IDrawable> items;
public:
	CompositeDrawable();
	~CompositeDrawable();
	virtual void draw() {
		// http://stackoverflow.com/questions/31410858/adding-elements-to-stdvector-of-an-abstract-class
		for (int i = 0; i < items.size(); i++)
		{
			items[i].draw();
		}	     
	};

	std::vector<IDrawable>& Items() {
		return items;
	}
	
};

