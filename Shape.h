#pragma once

#ifndef _SHAPE_
#define _SHAPE_
#endif

#ifndef _RGBCOLOR_
#define _RGBCOLOR_
#include "RGBColor.h"
#endif

#ifndef _LOCATION_
#define _LOCATION_
#include "Location.h"
#endif


#ifndef _GLUT_
#define _GLUT_
#include <GL/glut.h>
#endif

/********************************************
File:			shape.h
Author:			Cooper
Purpose:		shape class template
Created:		02/12/2020
Dependencies:	RGBColor.h
				Location.h
*********************************************/

class Shape
{
private:
	int NumSides;			//	Number of Polygon Sides
	RGBColor color;			//Shape color
	Location origin;		//center of the shape
	GLint drawMode;			//drawing mode
	Location* vertices;


public:
	//constructors
	Shape();
	Shape(int numSides, RGBColor color, Location origin, GLint drawMode);

	//set methods
	void setSides(int numSides);
	void setColor(RGBColor color);
	void setOrigin(Location origin);
	void setDrawMode(GLint drawMode);
	void setVertex(int index, Location l);
	void setVertices(int size);

	//get Methods
	int getSides();
	RGBColor getColor();
	GLint getDrawMode();
	Location* getVertices();


};