#pragma once

//#ifndef __BasicTriangle
//#define __BasicTriangle


//#pragma once
#include "commons.h"
#include "Triangle.h"

#include "IDrawable.h"
#include "ColoredObject.h"
class BasicTriangle : virtual public ColoredObject, public Triangle
{

public:

	BasicTriangle::BasicTriangle(GLfloat p1x, GLfloat p1y, GLfloat p1z, GLfloat p2x, GLfloat p2y, GLfloat p2z, GLfloat p3x, GLfloat p3y, GLfloat p3z, GLfloat lightcolor[]) :ColoredObject::ColoredObject(lightcolor), Triangle::Triangle(p1x, p1y, p1z, p2x, p2y, p2z, p3x, p3y, p3z)
	{
		//this->p1x = p1x;
		//this->p1y = p1y;
		//this->p1z = p1z;
		//this->p2x = p2x;
		//this->p2y = p2y;
		//this->p2z = p2z;
		//this->p3x = p3x;
		//this->p3y = p3y;
		//this->p3z = p3z;
	}


	BasicTriangle::~BasicTriangle()
	{
	}




	inline virtual void draw() {
		glPushMatrix();
		glColor3f(color[0], color[1], color[2]);
		Transform();

		float cx = (p1x+p2x+p3x) / 3, cy = (p1y + p2y + p3y) / 3, cz = (p1z + p2z + p3z) / 3;
		glTranslatef(-cx, -cy, -cz);

		glBegin(GL_TRIANGLES);
		 glVertex3f(p1x, p1y, p1z);
		glVertex3f(p2x, p2y, p2z);
		 glVertex3f(p3x, p3y, p3z);
		//glTexCoord2f(1.0, 0.0); glVertex3f(0, 1, 0);
		glEnd();
		glPopMatrix();
	
	};
};

//#endif // !__BasicTriangle