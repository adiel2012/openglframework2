#pragma once
#include "commons.h"
class Sphere
{
protected:
	GLfloat radii;
public:
	Sphere::Sphere(GLfloat radii)
	{
		this->radii = radii;
	}


	Sphere::~Sphere()
	{
	}

};

