#pragma once
#include "Sphere.h"
#include "commons.h"
#include "Transformable.h"
#include "IDrawable.h"
#include <math.h>

typedef struct {
	double x;
	double y;
	double z;
	
} XYZ;

class SphereTextured: public Sphere, public Transformable, public IDrawable
{
protected:
	GLuint textureid;
public:
	SphereTextured::SphereTextured(GLfloat radii, GLuint textureid):Sphere::Sphere(radii), Transformable::Transformable(), IDrawable::IDrawable()
	{
		this->textureid = textureid;
	}


	SphereTextured::~SphereTextured()
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
		XYZ c; c.x = 0; c.y = 0; c.z = 0;
		CreateSphere(c, radii, 30);

		glDisable(GL_TEXTURE_2D);

	}

	void CreateSphere(XYZ c, double r, int n)
	{
		int i, j;
		double phi1, phi2, theta, s, t;
		XYZ e, p;

		if (r < 0)
			r = -r;
		if (n < 0)
			n = -n;
		if (n < 4 || r <= 0) {
			glBegin(GL_POINTS);
			glVertex3f(c.x, c.y, c.z);
			glEnd();
			return;
		}

		for (j = 0;j < n; j++) {
			phi1 = j * TWOPI / n;
			phi2 = (j + 1) * TWOPI / n;	//next phi

			glBegin(GL_QUAD_STRIP);
			for (i = 0;i <= n;i++) {
				theta = i * PI / n;

				e.x = sin(theta) * cos(phi2);
				e.y = sin(theta) * sin(phi2);
				e.z = cos(theta);
				p.x = c.x + r * e.x;
				p.y = c.y + r * e.y;
				p.z = c.z + r * e.z;

				glNormal3f(e.x, e.y, e.z);
				s = phi2 / TWOPI;          // column
				t = 1 - theta / PI;          // row
				glTexCoord2f(s, t);
				glVertex3f(p.x, p.y, p.z);

				e.x = sin(theta) * cos(phi1);
				e.y = sin(theta) * sin(phi1);
				e.z = cos(theta);
				p.x = c.x + r * e.x;
				p.y = c.y + r * e.y;
				p.z = c.z + r * e.z;

				glNormal3f(e.x, e.y, e.z);
				s = phi1 / TWOPI;        // column
				t = 1 - theta / PI;      // row
				glTexCoord2f(s, t);

				glVertex3f(p.x, p.y, p.z);
			}
			glEnd();
		}
	}

};

