#include "BasicTriangle.h"



BasicTriangle::BasicTriangle(GLfloat p1x, GLfloat p1y, GLfloat p1z, GLfloat p2x, GLfloat p2y, GLfloat p2z, GLfloat p3x, GLfloat p3y, GLfloat p3z, GLfloat lightcolor[]):ColoredObject::ColoredObject(lightcolor)
{
	this->p1x = p1x;
	this->p1y = p1y;
	this->p1z = p1z;
	this->p2x = p2x;
	this->p2y = p2y;
	this->p2z = p2z;
	this->p3x = p3x;
	this->p3y = p3y;
	this->p3z = p3z;
}


BasicTriangle::~BasicTriangle()
{
}
