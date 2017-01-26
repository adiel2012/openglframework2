#pragma once

#include "commons.h"
class Caca {

public:
	static void mmm() {
		glPushMatrix();
		glTranslatef(0, 1, 0);
		glutSolidCube(1);
		glPopMatrix();

	}

};