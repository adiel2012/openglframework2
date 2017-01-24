#pragma once
#include "ColoredObject.h"
#include "IDrawable.h"
class CuboColored: public ColoredObject, public IDrawable
{
private:
	GLfloat arista;
public:
	CuboColored(GLfloat lightcolor[], GLfloat arista);
	~CuboColored();
	virtual void draw() {
		glPushMatrix();
		Transform();
		//glColor3f(1.0f, 1.0f, 1.0f);
		glutSolidCube(arista);
		glPopMatrix();
	}
};

