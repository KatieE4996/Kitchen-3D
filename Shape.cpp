#ifndef _SHAPE_
#include "Shape.h"
#define _SHAPE_
#endif
#include <cmath>
#define PI 3.1415926



/********************************************
File:			shape.cpp
Author:			Cooper
Purpose:		shape class definition
Created:		02/12/2020
Dependencies:	shape.h
*********************************************/

Shape::Shape() {																	//default constructor
	this->NumSides = 0;
	this->setColor(RGBColor(0, 0, 0));
	this->setOrigin(Location(0, 0, 0));
	this->setDrawMode(GL_LINE_LOOP);
	this->vertices = new Location[NumSides];
}

using namespace std;

Shape::Shape(int numSides, RGBColor color, Location origin, GLint drawMode) {	//constructor
	this->NumSides = numSides;
	this->setColor(color);
	this->setOrigin(origin);
	this->setDrawMode(drawMode);
	this->vertices = new Location[numSides];
}

// Set Methods

void Shape::setSides(int numSides) {
	this->NumSides = numSides;
}
void Shape::setColor(RGBColor color) {
	this->color.setRed(color.getRed());
	this->color.setGreen(color.getGreen());
	this->color.setBlue(color.getBlue());
	this->vertices = new Location[NumSides];
	this->setVertices(10);
}
void Shape::setOrigin(Location origin) {
	this->origin = origin;
}
void Shape::setDrawMode(GLint drawMode) {
	this->drawMode = drawMode;
}
void Shape::setVertex(int index, Location l) {
	vertices[index] = l;
}

//get Methods
int Shape::getSides() {
	return this->NumSides;
}

RGBColor Shape::getColor() {
	return color;
}

GLint Shape::getDrawMode() {
	return drawMode;
}

Location* Shape::getVertices() {
	return vertices;
}
void Shape::setVertices(int size) {
	double angle = 2 * PI / NumSides;
	int x, y;
	Location currentVertex;
	for (int i = 0; i < NumSides; i++) {
		x = (int)this->origin.getX() + size * sin(i * angle);
		y = (int)this->origin.getY() + size * cos(i * angle);
		currentVertex.setX(x);
		currentVertex.setY(y);
		currentVertex.setZ(0);
		vertices[i].setLocation(currentVertex.getX(), currentVertex.getY(), currentVertex.getZ());
	}
}