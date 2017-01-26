//#pragma once
//
//#include "soil.h"
//#include <stdio.h>
//// house.cc
//
//
//#include <GL/freeglut.h>
////  http://math.hws.edu/bridgeman/courses/324/s06/doc/opengl.html
//
//
//GLuint idd;
//
//
//GLuint LoadBMP2(const char *fileName)
//{
//	
//
//	int width, height;
//	unsigned char* data =
//		SOIL_load_image(fileName, &width, &height, 0, SOIL_LOAD_RGB);
//	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,GL_UNSIGNED_BYTE, data);
//
//	GLuint texture;
//	glGenTextures(1, &texture);
//	glBindTexture(GL_TEXTURE_2D, texture);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//	return texture;
//}
//
//
//void display55() {
//
//	/* clear window */
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	/* future matrix manipulations should affect the modelview matrix */
//	glMatrixMode(GL_MODELVIEW);
//
//	/* draw scene */
//	glPushMatrix();
//
//
//	//glColor3f(0.0, 0.0, 0.0);
//
//	GLuint texture =idd;
//
//	glEnable(GL_TEXTURE_2D);
//
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
//	glBindTexture(GL_TEXTURE_2D, texture);
//	
//	glPushMatrix();
//	glBegin(GL_QUADS);
//	glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
//	glTexCoord2f(0.0, 1.0); glVertex3f(1, 0, 0);
//	glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, 0);
//	glTexCoord2f(1.0, 0.0); glVertex3f(0, 1, 0);
//	glEnd();
//
//	glTranslatef(0, 0, 1);
//
//	glBegin(GL_QUADS);
//	glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
//	glTexCoord2f(0.0, 1.0); glVertex3f(1, 0, 0);
//	glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, 0);
//	glTexCoord2f(1.0, 0.0); glVertex3f(0, 1, 0);
//	glEnd();
//   glPopMatrix();
//   //----------------------------------------------------
//
//   glPushMatrix();
//   glBegin(GL_QUADS);
//   glTexCoord2f(0.0, 0.0); glVertex3f(0,0, 0);
//   glTexCoord2f(0.0, 1.0); glVertex3f(0,1, 0);
//   glTexCoord2f(1.0, 1.0); glVertex3f(0,1, 1);
//   glTexCoord2f(1.0, 0.0); glVertex3f(0,0, 1);
//   glEnd();
//
//   glTranslatef(1, 0, 0);
//
//   glBegin(GL_QUADS);
//   glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
//   glTexCoord2f(0.0, 1.0); glVertex3f(0, 1, 0);
//   glTexCoord2f(1.0, 1.0); glVertex3f(0, 1, 1);
//   glTexCoord2f(1.0, 0.0); glVertex3f(0, 0, 1);
//   glEnd();
//   glPopMatrix();
//
//   //----------------------------------------------------
//
//   glPushMatrix();
//   glBegin(GL_QUADS);
//   glTexCoord2f(0.0, 0.0); glVertex3f( 0,0, 0);
//   glTexCoord2f(0.0, 1.0); glVertex3f( 1,0, 0);
//   glTexCoord2f(1.0, 1.0); glVertex3f( 1,0, 1);
//   glTexCoord2f(1.0, 0.0); glVertex3f( 0,0, 1);
//   glEnd();
//
//   glTranslatef(0, 1, 0);
//
//   glBegin(GL_QUADS);
//   glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
//   glTexCoord2f(0.0, 1.0); glVertex3f(1, 0, 0);
//   glTexCoord2f(1.0, 1.0); glVertex3f(1, 0, 1);
//   glTexCoord2f(1.0, 0.0); glVertex3f(0, 0, 1);
//   glEnd();
//   glPopMatrix();
//   //-----------------------------------------------------------
//
//	glDisable(GL_TEXTURE_2D);
//	
//
//	//// house
//	//glPushMatrix();
//	//glutSolidCube(2);                 // building
//
//	//glTranslatef(0, 1, 0);
//	//glPushMatrix();                   // roof
//	//glRotatef(-90, 1, 0, 0);
//	//glutSolidCone(1.5, 1, 16, 8);
//	//glPopMatrix();
//
//	//glTranslatef(.75, .5, -.75);
//	//glPushMatrix();                   // chimney
//	//glScalef(1, 3, 1);
//	//glutSolidCube(.25);
//	//glPopMatrix();
//	//glPopMatrix();
//
//	//glTranslatef(0, -.65, 2);
//
//	//// car
//	//glPushMatrix();
//	//glPushMatrix();                   // body
//	//glScalef(2, .5, 1);
//	//glutSolidCube(.5);
//	//glPopMatrix();
//	//glTranslatef(0, 0, .25);
//	//glPushMatrix();
//	//glTranslatef(-.4, -.2, 0);
//	//glutSolidTorus(.05, .1, 8, 8);       // wheel
//	//glTranslatef(.8, 0, 0);
//	//glutSolidTorus(.05, .1, 8, 8);       // wheel
//	//glPopMatrix();
//	//glTranslatef(0, 0, -.5);
//	//glPushMatrix();
//	//glTranslatef(-.4, -.2, 0);
//	//glutSolidTorus(.05, .1, 8, 8);       // wheel
//	//glTranslatef(.8, 0, 0);
//	//glutSolidTorus(.05, .1, 8, 8);       // wheel
//	//glPopMatrix();
//	//glPopMatrix();
//
//
//
//
//
//	glPopMatrix();
//
//	/* flush drawing routines to the window */
//	glFlush();
//}
//
//void reshape55(int width, int height) {
//
//	/* define the viewport transformation */
//	glViewport(0, 0, width, height);
//}
//
//int main(int argc, char * argv[]) {
//
//	/* initialize GLUT, using any commandline parameters passed to the
//	program */
//	glutInit(&argc, argv);
//
//	/* setup the size, position, and display mode for new windows */
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(0, 0);
//	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
//
//	/* create and set up a window */
//	glutCreateWindow("hello, teapot!");
//	glutDisplayFunc(display55);
//	glutReshapeFunc(reshape55);
//
//	/* set up depth-buffering */
//	glEnable(GL_DEPTH_TEST);
//
//	/* turn on default lighting */
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//
//	/* define the projection transformation */
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(40, 1, 4, 20);
//
//	/* define the viewing transformation */
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//
//
//
//	idd = LoadBMP2("C:\\Users\\adiel\\Documents\\Visual Studio 2015\\Projects\\opengl_framework\\splash.bmp");
//
//	//int width, height;
//	//unsigned char* image =
//	//	SOIL_load_image("C:\\Users\\adiel\\Documents\\Visual Studio 2015\\Projects\\opengl_framework\\splash.bmp", &width, &height, 0, SOIL_LOAD_RGB);
//	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
//	//	GL_UNSIGNED_BYTE, image);
//
//
//	/* tell GLUT to wait for events */
//	glutMainLoop();
//
//
//	return 0;
//}
//
//
