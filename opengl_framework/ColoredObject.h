#pragma once
#include "commons.h"
class ColoredObject
{

protected:
	GLfloat lightcolor[3];
public:
	ColoredObject(GLfloat lightcolor[]);
	~ColoredObject();
};

