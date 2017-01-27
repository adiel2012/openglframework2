#pragma once
#include "commons.h"

class Cylinder
{
protected:
	GLfloat radii, height;
public:

	Cylinder::Cylinder(GLfloat radii, GLfloat height)
	{
		this->height = height;
		this->radii = radii;
	}


	Cylinder::~Cylinder()
	{
	}

};

