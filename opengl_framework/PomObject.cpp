#include "PomObject.h"



PomObject::PomObject(GLfloat cambient[3], GLfloat diffuse[3], GLfloat specular[3])
{
	this->cambient[0] = cambient[0];
	this->cambient[1] = cambient[1];
	this->cambient[2] = cambient[2];

	this->diffuse[0] = diffuse[0];
	this->diffuse[1] = diffuse[1];
	this->diffuse[2] = diffuse[2];

	this->specular[0] = specular[0];
	this->specular[1] = specular[1];
	this->specular[2] = specular[2];


}


PomObject::~PomObject()
{
}
