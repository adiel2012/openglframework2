#pragma once

#include "commons.h"

class Singleton
{
private:
	static Singleton* __instance;
	Singleton::Singleton()
	{
	}
public:
	static Singleton* getIntance() {
		if (!__instance)
			__instance = new Singleton();
		return __instance;
	}
	
	

	Singleton::~Singleton()
	{
		if (__instance)
			delete __instance;
	}

	void mmm() {
		glPushMatrix();
		glTranslatef(0, 1, 0);
		glutSolidCube(1);
		glPopMatrix();

	}
};

