#include "object.h"

// Default constructor
Object::Object(){}

// Deconstructor
Object::~Object(){}

void Object::scale(GLfloat Sx, GLfloat Sy){
	this->size = this->size * Sx;
}

void Object::drawText(const char *text, GLint length, GLint x, GLint y, void *font){
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	
	glLoadIdentity();
	glOrtho(0, 1280, 0, 862, -5, 5);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glPushMatrix();
		glLoadIdentity();
		glRasterPos2i(x,y);
		for(int i=0; i<length; i++){
			glutBitmapCharacter(font, (int)text[i]);
		}
	glPopMatrix();
	
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}

void Object::drawRect(GLfloat x, GLfloat y, 
					  GLint width, GLint height){
	for(this->x=x; this->x<x+width; this->x++){
		for(this->y=y; this->y <y+height; this->y++){
			glColor3f(0.94117647058f, 0.9725490196f, 0.748979f); 
			this->drawPoint(this->x, this->y, 1);
		}
	}
}

void Object::drawPoint(GLfloat x, GLfloat y, GLfloat size){
	glPushMatrix();
	glPointSize(size);
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
	glPopMatrix();
}








