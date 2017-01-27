#pragma once
#include "Triangle.h"
#include "ColoredObject.h"
class TriangleTextured: public Triangle, public Transformable, public IDrawable
{

private:
	GLuint textureid;
public:
	TriangleTextured::TriangleTextured(GLfloat p1x, GLfloat p1y, GLfloat p1z, GLfloat p2x, GLfloat p2y, GLfloat p2z, GLfloat p3x, GLfloat p3y, GLfloat p3z, GLuint textureid):Triangle::Triangle(p1x,p1y,p1z,p2x,p2y,p2z,p3x,p3y,p3z), Transformable::Transformable(), IDrawable::IDrawable()
	{
		this->textureid = textureid;
	}


	TriangleTextured::~TriangleTextured()
	{

	}


	virtual void draw() {
		glPushMatrix();

		Transform();
		//glutSolidCube(arista);
		drawpartial(textureid);
		glPopMatrix();



	}


	void drawpartial(GLuint image_handler) {
		GLuint texture = image_handler;
		//glColor4f(0, 0, 1, 1);
		glDisable(GL_COLOR_MATERIAL);
		glEnable(GL_TEXTURE_2D);

		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glBindTexture(GL_TEXTURE_2D, texture);

		
		//glColor3f(color[0], color[1], color[2]);
		//Transform();

		float cx = (p1x + p2x + p3x) / 3, cy = (p1y + p2y + p3y) / 3, cz = (p1z + p2z + p3z) / 3;
		glTranslatef(-cx, -cy, -cz);

		glBegin(GL_TRIANGLES);
		glTexCoord2f(0.0, 0.0); glVertex3f(p1x, p1y, p1z);
		glTexCoord2f(0.0, 1.0); glVertex3f(p2x, p2y, p2z);
		glTexCoord2f(1.0, 0.0); glVertex3f(p3x, p3y, p3z);
		//glTexCoord2f(1.0, 0.0); glVertex3f(0, 1, 0);
		glEnd();
		
		//-----------------------------------------------------------

		glDisable(GL_TEXTURE_2D);

	}



};

