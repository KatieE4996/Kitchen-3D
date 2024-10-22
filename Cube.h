#define _CUBE_
#ifndef _GL_
#define _GL_
#include <GL/glut.h>
#endif
#include "RGBColor.h"
#include "Location.h"

/*************************************
Function:   Cube class file
Purpose:    create a cube
Author:     Easlon, math for the vertices was based on the https://www.youtube.com/watch?v=vcMox6i8f4Y. 
Date:   3/31/2020
*************************************/

class Cube {
	GLfloat edgeLength;
	Location centerPos;
	RGBColor color;
public:
	Cube();

	Cube(GLfloat eL, Location l, RGBColor c);

	//Set methods
	void setEdgeL(GLfloat eL);
	void setColor(RGBColor c);
	void setLocation(Location l);

	//Get methods
	GLfloat getEdgeL();
	RGBColor getColor();
	Location getLocation();

	//Draw 
	void drawCube();
};