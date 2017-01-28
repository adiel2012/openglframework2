#pragma once
#include "commons.h"
#include "Transformable.h"
#include "IDrawable.h"
#include "Cylinder.h"
#include <math.h>

class CylinderTextured: public Cylinder, public Transformable, public IDrawable
{
protected:
	GLuint textureid;

public:
	CylinderTextured::CylinderTextured(GLfloat radii, GLfloat height, GLuint textureid):Cylinder(radii,height), Transformable::Transformable(), IDrawable::IDrawable()
	{
		this->textureid = textureid;
	}


	CylinderTextured::~CylinderTextured()
	{

	}


	virtual void draw() {
		glPushMatrix();

		Transform();
		//GLuint texture = image_handler;
		//glColor4f(0, 0, 1, 1);
		glDisable(GL_COLOR_MATERIAL);
		glEnable(GL_TEXTURE_2D);

		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glBindTexture(GL_TEXTURE_2D, textureid);
		drawpartial(textureid);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();



	}

	void drawpartial(GLuint image_handler) {

		double i, resolution = 0.1;
		//double height = 1;
		//double radius = 0.5;


		glTranslatef(0, -0.5, 0);

		glBegin(GL_TRIANGLE_FAN);
		glTexCoord2f(0.5, 0.5);
		glVertex3f(0, height, 0);  /* center */
		for (i = 2 * PI; i >= 0; i -= resolution)

		{
			glTexCoord2f(0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f);
			glVertex3f(radii * cos(i), height, radii * sin(i));
		}
		/* close the loop back to 0 degrees */
		glTexCoord2f(0.5, 0.5);
		glVertex3f(radii, height, 0);
		glEnd();

		/* bottom triangle: note: for is in reverse order */
		glBegin(GL_TRIANGLE_FAN);
		glTexCoord2f(0.5, 0.5);
		glVertex3f(0, 0, 0);  /* center */
		for (i = 0; i <= 2 * PI; i += resolution)
		{
			glTexCoord2f(0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f);
			glVertex3f(radii * cos(i), 0, radii * sin(i));
		}
		glEnd();

		/* middle tube */
		glBegin(GL_QUAD_STRIP);
		for (i = 0; i <= 2 * PI; i += resolution)
		{
			const float tc = (i / (float)(2 * PI));
			glTexCoord2f(tc, 0.0);
			glVertex3f(radii * cos(i), 0, radii * sin(i));
			glTexCoord2f(tc, 1.0);
			glVertex3f(radii * cos(i), height, radii * sin(i));
		}
		/* close the loop back to zero degrees */
		glTexCoord2f(0.0, 0.0);
		glVertex3f(radii, 0, 0);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(radii, height, 0);
		glEnd();

	}
};

