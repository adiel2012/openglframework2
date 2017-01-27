#pragma once

#include "commons.h"
#include "Transformable.h"
#include "IDrawable.h"
#include "Utils.h"
class CuboTextured : public Transformable, public IDrawable
{

private:
	GLfloat arista;
	GLuint image_handler;

public:
	CuboTextured::CuboTextured(GLfloat arista, GLuint image_handler) :Transformable::Transformable()
	{
		this->arista = arista;
		this->image_handler = image_handler;
	}


	CuboTextured::~CuboTextured()
	{
	}

	virtual void draw() {
		glPushMatrix();
		//glColor3f(color[0], color[1], color[2]);


		GLfloat a = this->glScalef_morph[0], b = this->glScalef_morph[1], c = this->glScalef_morph[2];

		this->glScalef_morph[0] = arista*this->glScalef_morph[0];
		this->glScalef_morph[1] = arista*this->glScalef_morph[1];
		this->glScalef_morph[2] = arista*this->glScalef_morph[2];
		Transform();
		//glutSolidCube(arista);
		drawpartial(image_handler);
		glPopMatrix();

		this->glScalef_morph[0] = a;
		this->glScalef_morph[1] = b;
		this->glScalef_morph[2] = c;

		//Caca::mmm();
		/*glPushMatrix();
		glTranslatef(0, 1, 0);
		glutSolidCube(1);
		glPopMatrix();*/

	}


	void drawpartial(GLuint image_handler) {
		GLuint texture = image_handler;
		//glColor4f(0, 0, 1, 1);
		glDisable(GL_COLOR_MATERIAL);
		glEnable(GL_TEXTURE_2D);
		
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTranslatef(-0.5, -0.5, -0.5);

		glPushMatrix();
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
		glTexCoord2f(0.0, 1.0); glVertex3f(1, 0, 0);
		glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, 0);
		glTexCoord2f(1.0, 0.0); glVertex3f(0, 1, 0);
		glEnd();

		glTranslatef(0, 0, 1);

		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
		glTexCoord2f(0.0, 1.0); glVertex3f(1, 0, 0);
		glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, 0);
		glTexCoord2f(1.0, 0.0); glVertex3f(0, 1, 0);
		glEnd();
		glPopMatrix();
		//----------------------------------------------------

		glPushMatrix();
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
		glTexCoord2f(0.0, 1.0); glVertex3f(0, 1, 0);
		glTexCoord2f(1.0, 1.0); glVertex3f(0, 1, 1);
		glTexCoord2f(1.0, 0.0); glVertex3f(0, 0, 1);
		glEnd();

		glTranslatef(1, 0, 0);

		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
		glTexCoord2f(0.0, 1.0); glVertex3f(0, 1, 0);
		glTexCoord2f(1.0, 1.0); glVertex3f(0, 1, 1);
		glTexCoord2f(1.0, 0.0); glVertex3f(0, 0, 1);
		glEnd();
		glPopMatrix();

		//----------------------------------------------------

		glPushMatrix();
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
		glTexCoord2f(0.0, 1.0); glVertex3f(1, 0, 0);
		glTexCoord2f(1.0, 1.0); glVertex3f(1, 0, 1);
		glTexCoord2f(1.0, 0.0); glVertex3f(0, 0, 1);
		glEnd();

		glTranslatef(0, 1, 0);

		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
		glTexCoord2f(0.0, 1.0); glVertex3f(1, 0, 0);
		glTexCoord2f(1.0, 1.0); glVertex3f(1, 0, 1);
		glTexCoord2f(1.0, 0.0); glVertex3f(0, 0, 1);
		glEnd();
		glPopMatrix();
		//-----------------------------------------------------------

		glDisable(GL_TEXTURE_2D);
	
	}




};

