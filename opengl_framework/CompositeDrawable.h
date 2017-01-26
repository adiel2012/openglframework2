#pragma once

//#ifndef __CompositeDrawable
//#define CompositeDrawable


#include "IDrawable.h"


#include <iostream>
#include <vector>
#include <memory>
#include "commons.h"
#include "CuboColored.h"
#include "Caca.h"

class CompositeDrawable: public IDrawable
{
protected:
	std::vector<std::unique_ptr<IDrawable>> items;
public:
	CompositeDrawable();
	~CompositeDrawable();
	virtual void draw() {
		// http://stackoverflow.com/questions/31410858/adding-elements-to-stdvector-of-an-abstract-class
		for (int i = 0; i < items.size(); i++)
		{
			items[i]->draw();

			//Caca::mmm();

			/*glPushMatrix();
			glTranslatef(0, 1, 0);
			glutSolidCube(1);
			glPopMatrix();*/
		}	

		/*CuboColored* c = new CuboColored(new GLfloat[3]{ 0.0,1.0,0 }, 1);
		c->draw();
		delete c;*/

		//mmm();
		
	};


	

	std::vector<std::unique_ptr<IDrawable>>* Items() {
		return &items;
	}
	
};

//#endif

