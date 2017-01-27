#include <iostream>
#include <memory>

#include <GL/freeglut.h>
#include "CompositeDrawable.h"
#include "CuboColored.h"
#include "Camera.h"
#include "CuboTextured.h"
#include "Utils.h"
#include "BasicTriangle.h"

#include "CylinderColored.h"
#include "TriangleTextured.h"

Camera cam;
std::unique_ptr<CompositeDrawable> composite(new CompositeDrawable);

void display() {

	
	

	/* clear window */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* future matrix manipulations should affect the modelview matrix */
	glMatrixMode(GL_MODELVIEW);

	/* draw scene */
	glPushMatrix();

	

	composite->draw();

	// house
	//glPushMatrix();
	//glTranslatef(0, 1, 0);
	//glutSolidCube(1);   
	//glPopMatrix();

	//
	//glPushMatrix();                   // roof
	//glTranslatef(0, 1, 0);
	//glRotatef(-90, 1, 0, 0);
	//glutSolidCone(1.5, 1, 16, 8);
	//glPopMatrix();


	/*
	// house
	glPushMatrix();
	glutSolidCube(2);                 // building

	glTranslatef(0, 1, 0);
	glPushMatrix();                   // roof
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(1.5, 1, 16, 8);
	glPopMatrix();

	glTranslatef(.75, .5, -.75);
	glPushMatrix();                   // chimney
	glScalef(1, 3, 1);
	glutSolidCube(.25);
	glPopMatrix();
	glPopMatrix();

	glTranslatef(0, -.65, 2);

	// car
	glPushMatrix();
	glPushMatrix();                   // body
	glScalef(2, .5, 1);
	glutSolidCube(.5);
	glPopMatrix();
	glTranslatef(0, 0, .25);
	glPushMatrix();
	glTranslatef(-.4, -.2, 0);
	glutSolidTorus(.05, .1, 8, 8);       // wheel
	glTranslatef(.8, 0, 0);
	glutSolidTorus(.05, .1, 8, 8);       // wheel
	glPopMatrix();
	glTranslatef(0, 0, -.5);
	glPushMatrix();
	glTranslatef(-.4, -.2, 0);
	glutSolidTorus(.05, .1, 8, 8);       // wheel
	glTranslatef(.8, 0, 0);
	glutSolidTorus(.05, .1, 8, 8);       // wheel
	glPopMatrix();
	glPopMatrix();
	*/

	glPopMatrix();



	/* flush drawing routines to the window */
	glFlush();
}

void reshape(int width, int height) {
	cam.reshape(width, height);

	/* define the viewport transformation */
	glViewport(0, 0, width, height);
}
void processSpecialKeys(int key, int xx, int yy) {
	cam.processSpecialKeys(key,xx,yy);
}
void mouseButton(int button, int state,	int x, int y) {
	cam.mouseButton( button,  state,x,  y);
}
void mouseMove(int x, int y) {
	cam.mouseMove(x,y);

}

void animate() {

	/* update state variables */
	std::vector<std::unique_ptr<IDrawable>>* list = composite->Items();
	for (size_t i = 0; i < list->size(); i++)
	{
		//cout << typeid(*(*list)[i].get()).name() << endl;
		Transformable* inst = dynamic_cast<Transformable*>((*list)[i].get());
		if (inst != NULL) {
		//	cout << "si" << endl;
			inst->glRotatef_morph[0] += 0.3;
		}


	}

	/* refresh screen */
	glutPostRedisplay();
}

GLuint idd = -1; // Utils::load_image("C:\\Users\\adiel\\Documents\\Visual Studio 2015\\Projects\\opengl_framework\\splash.bmp");

int main(int argc, char * argv[]) {

	/* initialize GLUT, using any commandline parameters passed to the
	program */
	glutInit(&argc, argv);

	/* setup the size, position, and display mode for new windows */
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);

	/* create and set up a window */
	glutCreateWindow("house2");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	//glutSpecialFunc(processSpecialKeys);
	//glutMouseFunc(mouseButton);
	//glutMotionFunc(mouseMove);
	glutIdleFunc(animate);

	/* set up depth-buffering */
	glEnable(GL_DEPTH_TEST);

	/* set up lights */
	//glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();

	//GLfloat lightpos[] = { 0.0, 0.0, 15.0 };
	//GLfloat lightcolor[] = { 1.0, 1.0, 1.0 };
	//GLfloat ambcolor[] = { 0.0, 0.0, 1.0 };

	//glEnable(GL_LIGHTING);                               // enable lighting
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambcolor);     // ambient light

	//glEnable(GL_LIGHT0);                                 // enable light source
	//glLightfv(GL_LIGHT0, GL_POSITION, lightpos);           // config light source
	//glLightfv(GL_LIGHT0, GL_AMBIENT, lightcolor);
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, lightcolor);
	//glLightfv(GL_LIGHT0, GL_SPECULAR, lightcolor);

	/* define the projection transformation */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40, 1, 4, 20);

	/* define the viewing transformation */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	
	idd = Utils::load_image("C:\\Users\\adiel\\Documents\\Visual Studio 2015\\Projects\\opengl_framework\\splash.bmp");

	std::unique_ptr<CuboColored> cubo(new CuboColored(new GLfloat[3]{1.0,0,0},1));
	std::unique_ptr<CuboColored> cubo2(new CuboColored(new GLfloat[3]{ 0.0,1.0,0 }, 1));
	cubo2->aglTranslatef(0,1,0);
	cubo->aglTranslatef(0, -1, -2);

	std::unique_ptr<CuboTextured> cuboT1(new CuboTextured(1,idd));
	cuboT1->aglTranslatef(0, -1, 2);

	std::unique_ptr<CuboTextured> domo(new CuboTextured(10, idd));

	std::unique_ptr<CuboTextured> cuboT2(new CuboTextured(1, idd));
	cuboT2->aglTranslatef(1, -1, 1);
	cuboT2->aglScalef(2, 1, 1);

	GLfloat lightcolortcolor[3] = {0.5,0,0.5};
	std::unique_ptr<BasicTriangle> T1(new BasicTriangle(0,0,1,0,1,0,1,0,0, lightcolortcolor));

	std::unique_ptr<TriangleTextured> T2(new TriangleTextured(1, 1, 2, 1, 2, 1, 2, 1, 1, idd));
	T2->aglTranslatef(0, 0, 2);

	GLfloat lightcolortcolor2[3] = { 0.5,0.3,0.5 };
	std::unique_ptr<CylinderColored> cylinder1(new CylinderColored(1, 1, lightcolortcolor2));
	cylinder1->aglTranslatef(0, 1, -2);
	

	composite->Items()->push_back(std::move(cubo));
	composite->Items()->push_back(std::move(cubo2));
	composite->Items()->push_back(std::move(cuboT1));
	composite->Items()->push_back(std::move(cuboT2));
	composite->Items()->push_back(std::move(domo));
	composite->Items()->push_back(std::move(T1));
	composite->Items()->push_back(std::move(T2));
	composite->Items()->push_back(std::move(cylinder1));

	


	/* tell GLUT to wait for events */
	glutMainLoop();


	return 0;
}