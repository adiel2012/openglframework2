#pragma once

//#ifndef __BasicTriangle
//#define __BasicTriangle


//#pragma once
#include "commons.h"

#include "IDrawable.h"
#include "ColoredObject.h"
class BasicTriangle : virtual public IDrawable, virtual public ColoredObject
{
protected:
	GLfloat p1x,  p1y,  p1z,  p2x,  p2y,  p2z,  p3x,  p3y,  p3z;
public:
	BasicTriangle(GLfloat p1x, GLfloat p1y, GLfloat p1z, GLfloat p2x, GLfloat p2y, GLfloat p2z, GLfloat p3x, GLfloat p3y, GLfloat p3z, GLfloat lightcolor[]);
	~BasicTriangle();

	inline virtual void draw() {
	     
	
	};
};

//#endif // !__BasicTriangle