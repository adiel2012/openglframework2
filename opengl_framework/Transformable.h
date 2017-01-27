#pragma once
#include "commons.h"
class Transformable
{
public:

	GLfloat glScalef_morph[3] = { 1.0,1.0,1.0 };
	/*void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);*/
	GLfloat glTranslatef_morph[3] = { 0,0,0 };
	GLfloat glRotatef_morph[4] = { 0,1.0,0,0 };


	Transformable();
	~Transformable();

	static void InvokeT(Transformable& co) {
		//glColor3f(co.color[0], co.color[1], co.color[2]);
		glTranslatef(co.glTranslatef_morph[0], co.glTranslatef_morph[1], co.glTranslatef_morph[2]);
		glRotatef(co.glRotatef_morph[0], co.glRotatef_morph[1], co.glRotatef_morph[2], co.glRotatef_morph[3]);
		glScalef(co.glScalef_morph[0], co.glScalef_morph[1], co.glScalef_morph[2]);

		/*;
		*/

	}


	void Transform() {
		Transformable::InvokeT(*this);
		//glTranslatef(0, 10, 0);		
		/*glRotatef(-45, 1, 0, 0);
		glScalef(1, 3, 1);*/

		/*glScalef(glScalef_morph[0], glScalef_morph[1], glScalef_morph[0]);
		glRotatef(glRotatef_morph[0], glRotatef_morph[1], glRotatef_morph[2], glRotatef_morph[3]);
		glTranslatef(glTranslatef_morph[0], glTranslatef_morph[1], glTranslatef_morph[2]);*/
	}

	void aglTranslatef(GLdouble x, GLdouble y, GLdouble z) {
		glTranslatef_morph[0] = x;
		glTranslatef_morph[1] = y;
		glTranslatef_morph[2] = z;
	}

	void aglScalef(GLdouble x, GLdouble y, GLdouble z) {
		glScalef_morph[0] = x;
		glScalef_morph[1] = y;
		glScalef_morph[2] = z;
	}


	void aglRotatef(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
		glRotatef_morph[0] = angle;
		glRotatef_morph[1] = x;
		glRotatef_morph[2] = y;
		glRotatef_morph[3] = z;
	}
};

