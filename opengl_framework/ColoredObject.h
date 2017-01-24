#pragma once
#include "commons.h"
class ColoredObject
{

protected:
	GLfloat ambientlightcolor[3] = { 0,0,0 };

	GLfloat glScalef_morph[3] = { 1.0,1.0,1.0 };
	/*void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);*/
	GLfloat glRotatef_morph[4] = { 0,1.0,0,0 };
	GLfloat glTranslatef_morph[3] = { 0,0,0 };

public:
	ColoredObject(GLfloat ambientlightcolor[]);
	~ColoredObject();

	void Transform() {
		glScalef(glScalef_morph[0], glScalef_morph[1], glScalef_morph[0]);
		glRotatef(glRotatef_morph[0], glRotatef_morph[1], glRotatef_morph[2], glRotatef_morph[3]);
		glTranslatef(glTranslatef_morph[0], glTranslatef_morph[1], glTranslatef_morph[2]);
	}

	void glTranslatef( GLdouble x, GLdouble y, GLdouble z) {
		glTranslatef_morph[0] = x;
		glTranslatef_morph[1] = y;
		glTranslatef_morph[2] = z;
	}

	void glScalef(GLdouble x, GLdouble y, GLdouble z) {
		glScalef_morph[0] = x;
		glScalef_morph[1] = y;
		glScalef_morph[2] = z;
	}


	void glRotatef(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
		glRotatef_morph[0] = angle;
		glRotatef_morph[1] = x;
		glRotatef_morph[2] = y;
		glRotatef_morph[3] = z;
	}
};




/*glScalef(1, 3, 1);
glRotatef(-90, 1, 0, 0);
glTranslatef(0, 1, 0);*/
