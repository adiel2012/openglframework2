#include "ColoredObject.h"



ColoredObject::ColoredObject(GLfloat lightcolor[])
{
	this->lightcolor[0] = lightcolor[0];
	this->lightcolor[1] = lightcolor[1];
	this->lightcolor[2] = lightcolor[2];
}


ColoredObject::~ColoredObject()
{
}
