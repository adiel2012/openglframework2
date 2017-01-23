

//#ifndef PomObject
//#define PomObject


//#include <GL/gl.h>
//#include <GL/glut.h>

#include "commons.h"

//#pragma once

#include <vector>

//class GLfloat;



class PomObject
{

protected:
	GLfloat cambient[3] = { 0, 0, 0 };
	GLfloat diffuse[3] = { 0, 0, 0 };
	GLfloat specular[3] = { 0, 0, 0 };
public:
	PomObject(GLfloat cambient[3], GLfloat diffuse[3], GLfloat specular[3]);
	~PomObject();
};


//#endif // !PomObject
