#pragma once
#include "commons.h"
#include "IDrawable.h"

#include <iostream>
//#include <memory>
using namespace std;
#include "Transformable.h"

class ColoredObject: public IDrawable, public Transformable
{

protected:
	GLfloat color[3] = { 0,0,0 };

	

public:
	

	virtual void draw() {
		cout << "no recargado"<< endl;
	}

	ColoredObject::ColoredObject(GLfloat color[]) :IDrawable::IDrawable()
	{
		this->color[0] = color[0];
		this->color[1] = color[1];
		this->color[2] = color[2];
	}


	ColoredObject::~ColoredObject()
	{
	}


};




/*glScalef(1, 3, 1);
glRotatef(-90, 1, 0, 0);
glTranslatef(0, 1, 0);*/
