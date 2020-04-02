#pragma once

#ifndef _RGBCOLOR_
#define RGBCOLOR_
#endif
#include <GL/glut.h>


/********************************************
Class:			RGBColor.h
Author:			Cooper
Purpose:		hold class structure information
Created:		02/12/2020
Dependencies:	none
*********************************************/
class RGBColor {
private:
	GLfloat red;
	GLfloat green;
	GLfloat blue;


public:
	//constructors
	RGBColor();											//sets to black
	RGBColor(GLfloat red, GLfloat green, GLfloat blue);

	//set Methods
	void setRed(GLfloat red);							//set individual colors
	void setBlue(GLfloat blue);
	void setGreen(GLfloat green);
	void setColors(GLfloat red, GLfloat green, GLfloat blue);	// set all the colors

// get methods
	GLfloat getRed();
	GLfloat getBlue();
	GLfloat getGreen();
	RGBColor* getColors();								//gets a color object

// other Methods
	void toGLfloatArray(GLfloat r[3]);


};