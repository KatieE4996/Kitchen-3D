#define _PRISM_
#ifndef _GL_
#define _GL_
#include <GL/glut.h>
#endif
#include "RGBColor.h"
#include "Location.h"

/*************************************
Function:   Rectangle Prism class file
Purpose:    create a prism
Author:      Katie Easlon modified to use Location and RGB class files
Date:   3/31/2020
*************************************/

class Prism{
	GLfloat side_length;
	GLfloat side_width;
	GLfloat front_length;
	GLfloat front_width;
	Location centerPos;
	RGBColor color;
	bool light_source;

public:
	Prism();

	Prism(GLfloat s_len, GLfloat s_w, GLfloat f_len, GLfloat f_w, Location l, RGBColor c, bool l_s);

	//Set methods
	void setSideLength(GLfloat s_len);
	void setSideWidth(GLfloat s_w);
	void setFrontLength(GLfloat f_len);
	void setFrontWidth(GLfloat f_w);
	void setColor(RGBColor c);
	void setLocation(Location l);
	void setLightSource(bool l_s);

	//Get methods
	GLfloat getSideLength();
	GLfloat getSideWidth();
	GLfloat getFrontLength();
	GLfloat getFrontWidth();
	RGBColor getColor();
	Location getLocation();
	bool getLightSource();

	//Draw 
	void drawPrism();
};