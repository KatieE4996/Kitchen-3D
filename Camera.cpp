#include "Camera.h"

/*************************************************************************
Class:		Camera class implementation
Purpose:	Provide a persepctive on the sceene
Author https://cs.lmu.edu/~ray/notes/openglexamples/ as modified by Cooper
Date:	3/2/2020
************************************************************************/
Camera::Camera() {
	theta = 0;			// Camera andle
	y = 3;				// Camera height
	dTheta = 0.04;		// Camera angle change 
	deltaY = 0.2;		// Camera height Change
}

// get camera information
GLfloat Camera::getX() { return 10 * cos(theta); }
GLfloat Camera::getY() { return y; }
GLfloat Camera::getZ() { return 10 * sin(theta); }


//Modify camera position
void Camera::moveRight() { theta += dTheta; }
void Camera::moveLeft() { theta -= dTheta; }
void Camera::moveUp() { y += deltaY; }
void Camera::moveDown() { y -= deltaY; }