#ifndef _OBJECT_H_
#define _OBJECT_H_
#include <iostream>
#include "math.h"
#include <GL/glut.h>

using namespace std;

class Object{
public:
	Object();
	~Object();
	
	void drawRect(GLfloat x, GLfloat y, GLint width, GLint height);
	void drawText(const char *text, GLint length, GLint x, GLint y, void *font);
	void scale(GLfloat Sx, GLfloat Sy);
	void drawPoint(GLfloat x, GLfloat y, GLfloat size);
	GLfloat x, y, size;
};

#endif
