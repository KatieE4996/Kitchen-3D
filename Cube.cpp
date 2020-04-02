#include "Cube.h"

/*************************************
Name        Cube.cpp
Purpose:    Cube class implementation file
Author:     Easlon based on https://cs.lmu.edu/~ray/notes/openglexamples/
Date:       3/31/2020
*************************************/

//Constructors 
Cube::Cube()
{
	edgeLength = 0.0;
	centerPos.setX(0.0); centerPos.setY(0.0), centerPos.setZ(0.0);
	color.setRed(0); color.setGreen(0); color.setBlue(0);
}

Cube::Cube(GLfloat eL, Location l, RGBColor c)
{
	edgeLength = eL;
	centerPos.setX(l.getX()); centerPos.setY(l.getY()); centerPos.setZ(l.getZ());
	color.setRed(c.getRed()); color.setGreen(c.getGreen()); color.setBlue(c.getBlue());
}

void Cube::setEdgeL(GLfloat el) {	edgeLength = el;}
void Cube::setColor(RGBColor c) {	color.setRed(c.getRed()); color.setGreen(c.getGreen()); color.setBlue(c.getBlue());}
void Cube::setLocation(Location l) {	centerPos.setX(l.getX()); centerPos.setY(l.getY()); centerPos.setZ(l.getZ());}

GLfloat Cube::getEdgeL() {	return edgeLength;}
RGBColor Cube::getColor() {	return color;}
Location Cube::getLocation() {	return centerPos;}

void Cube::drawCube()
{
	GLfloat half = edgeLength * 0.5;
	GLfloat x = centerPos.getX(); GLfloat y = centerPos.getY(); GLfloat z = centerPos.getZ();

	GLfloat vertices[] =
	{
		//Front face
		x - half, y + half, z + half,
		x + half, y + half, z + half,
		x + half, y - half, z + half,
		x - half, y - half, z + half,

		//Back face
		x - half, y + half, z - half,
		x + half, y + half, z - half,
		x + half, y - half, z - half,
		x - half, y - half, z - half,

		//Left face
		x - half, y + half, z + half,
		x - half, y + half, z - half,
		x - half, y - half, z - half,
		x - half, y - half, z + half,

		//Right face
		x + half, y + half, z + half,
		x + half, y + half, z - half,
		x + half, y - half, z - half,
		x + half, y - half, z + half,

		//Top face
		x - half, y + half, z + half,
		x - half, y + half, z - half,
		x + half, y + half, z - half,
		x + half, y + half, z + half,

		//Bottom face
		x - half, y - half, z + half,
		x - half, y - half, z - half,
		x + half, y - half, z - half,
		x + half, y - half, z + half
	};

	GLfloat c[3] = { this->color.getRed(),this->color.getGreen(),this->color.getBlue() };

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, c);
	glDrawArrays(GL_QUADS, 0, 24);
	glDisableClientState(GL_VERTEX_ARRAY);
}
