#include <cmath>
#include <GL/glut.h>

/*************************************************************************
Class:		Camera class
Purpose:	Provide a persepctive on the sceene
Author https://cs.lmu.edu/~ray/notes/openglexamples/ as modified by Cooper
Date:	3/2/2020
************************************************************************/
class Camera {
	GLfloat theta;		//	camera angle
	GLfloat y;			// camera height 
	GLfloat dTheta;		// camera angle change
	GLfloat deltaY;		// camera height change

public:
	Camera();
	// camera location information
	GLfloat getX();
	GLfloat getY();
	GLfloat getZ();


	// Camera movement
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
};