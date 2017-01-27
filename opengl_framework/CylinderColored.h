#pragma once
#include "Cylinder.h"
#include "ColoredObject.h"
class CylinderColored : virtual public ColoredObject, public Cylinder
{
protected:

	
public:
	CylinderColored::CylinderColored(GLfloat radii, GLfloat height, GLfloat color[]):ColoredObject::ColoredObject(color), Cylinder::Cylinder(radii, height)
	{
		


		
	}


	CylinderColored::~CylinderColored()
	{
		//delete quadric;
	}

	virtual void draw() {
	

		glPushMatrix();
		Transform();
		glTranslatef(0,0, -height/2);
		glColor3f(color[0],color[1],color[2]);
		GLUquadric *quadric = gluNewQuadric();
		gluQuadricDrawStyle(quadric, GLU_FILL);
		gluQuadricOrientation(quadric, GLU_INSIDE);
		gluCylinder(quadric, radii, radii, height, 20, 20);
		gluDeleteQuadric(quadric);
		glPopMatrix();
	 
	}

	 

};

