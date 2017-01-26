#pragma once
#include "ColoredObject.h"
#include "IDrawable.h"
#include "Caca.h"

class CuboColored: public ColoredObject
{
private:
	GLfloat arista;
public:
	CuboColored(GLfloat lightcolor[], GLfloat arista);
	~CuboColored();
	virtual void draw() {
		glPushMatrix();		
		glColor3f(color[0], color[1], color[2]);
		Transform();
		glutSolidCube(arista);		
		glPopMatrix();

		//Caca::mmm();
		/*glPushMatrix();
		glTranslatef(0, 1, 0);
		glutSolidCube(1);
		glPopMatrix();*/

	}
};

