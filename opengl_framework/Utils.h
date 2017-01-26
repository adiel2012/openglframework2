#pragma once
#include "commons.h"
#include <soil.h>
class Utils
{
public:
	Utils();
	~Utils();

	static GLuint load_image(const char *fileName)
	{


		int width, height;
		unsigned char* data =
			SOIL_load_image(fileName, &width, &height, 0, SOIL_LOAD_RGB);
		//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,GL_UNSIGNED_BYTE, data);

		GLuint texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		return texture;
	}
};

