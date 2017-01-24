#include "ColoredObject.h"



ColoredObject::ColoredObject(GLfloat ambientlightcolor[])
{
	this->ambientlightcolor[0] = ambientlightcolor[0];
	this->ambientlightcolor[1] = ambientlightcolor[1];
	this->ambientlightcolor[2] = ambientlightcolor[2];
}


ColoredObject::~ColoredObject()
{
}
