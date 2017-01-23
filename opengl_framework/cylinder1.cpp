///*
//
//Copyright 2010 Etay Meiri
//
//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//Tutorial 01 - Create a window
//*/
//
//#include <GL/freeglut.h>
//
//
//static double deg = 0.0;
//
//void display1(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glPushMatrix();
//	glRotatef(deg, 0.0, 0.0, 1.0); // Rotate by deg
//
//								   // field
//	glColor3f(0.0, 0.5, 0.0);
//	glBegin(GL_POLYGON);
//	glVertex3f(0, 0, 0.0);
//	glVertex3f(1, 0, 0.0);
//	glVertex3f(1, 0.75, 0.0);
//	glVertex3f(0.8, 0.82, 0.0);
//	glVertex3f(0.6, 0.85, 0.0);
//	glVertex3f(0.4, 0.85, 0.0);
//	glVertex3f(0.2, 0.82, 0.0);
//	glVertex3f(0.0, 0.75, 0.0);
//	glEnd();
//
//	// pitch
//	glColor3f(0.25, 0.30, 0.0);
//	glBegin(GL_POLYGON);
//	glVertex3f(0.5, 0.65, 0.0);
//	glVertex3f(0.47, 0.35, 0.0);
//	glVertex3f(0.60, 0.35, 0.0);
//	glVertex3f(0.57, 0.65, 0.0);
//	glEnd();
//
//	//ump line
//	glColor3f(1.0, 1.0, 1.0);
//	glBegin(GL_POLYGON);
//	glVertex3f(0.49, 0.63, 0.0);
//	glVertex3f(0.49, 0.6315, 0.0);
//	glVertex3f(0.58, 0.6315, 0.0);
//	glVertex3f(0.58, 0.63, 0.0);
//	glEnd();
//
//	//bat line
//	glColor3f(1.0, 1.0, 1.0);
//	glBegin(GL_POLYGON);
//	glVertex3f(0.46, 0.40, 0.0);
//	glVertex3f(0.46, 0.4025, 0.0);
//	glVertex3f(0.61, 0.4025, 0.0);
//	glVertex3f(0.61, 0.40, 0.0);
//	glEnd();
//
//	glPopMatrix();
//
//	glFlush();
//}
//
//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//	switch (key) {
//	case 27: // "esc" on keyboard
//		exit(0);
//		break;
//	case 'a': // "a" on keyboard
//		deg = deg + 5.0;
//		glutPostRedisplay();
//		break;
//	case 'z':
//		deg = deg - 5.0;
//		glutPostRedisplay();
//		break;
//	}
//}
//
//int mainjhjhj(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(600, 600);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("hello");
//	init();
//	glutDisplayFunc(display1);
//	glutKeyboardFunc(keyboard);
//	glutMainLoop();
//	return 0;
//}