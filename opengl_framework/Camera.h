#pragma once

//#ifndef __Camera
//#define __Camera

#include "commons.h"

#include <iostream>
#include <memory>
#include <iostream>
using namespace std;


class Camera
{
private:
	
	
	
public:
	Camera();
	~Camera();

	void reshape(int width, int height) {
	
	}



	void processSpecialKeys(int key, int xx, int yy) {

		float fraction = 0.1f;

		cout << key << endl;

		switch (key) {
		case GLUT_KEY_LEFT:
			/*angle -= 0.01f;
			lx = sin(angle);
			lz = -cos(angle);*/
			break;
		case GLUT_KEY_RIGHT:
			//angle += 0.01f;
			//lx = sin(angle);
			//lz = -cos(angle);
			break;
		case GLUT_KEY_UP:
			//x += lx * fraction;
			//z += lz * fraction;
			break;
		case GLUT_KEY_DOWN:
			//x -= lx * fraction;
			//z -= lz * fraction;
			break;
		}
	}

	void mouseButton(int button, int state,int x, int y) {
		cout << "Button: " << button << " " << state << " "<< x << " " << y<< endl;
	}

	void mouseMove(int x, int y) {
		cout << x << "  " << y << endl;
	}

	/*static void processArrowKeys(int key, int x, int y) {
		Camera::getInstance().processSpecialKeys(key, x, y);
	}*/
};

//Camera* Camera::__instance = nullptr;






//#endif // !__IDrawable