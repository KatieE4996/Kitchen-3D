#include "Prism.h"

/*************************************
Function:   Rectangle Prism class file
Purpose:    create a prism
Author:      Katie Easlon modified from the Cube.cpp to allow for more deminsions
Date:   04/01/2020
*************************************/

//Constructors 
Prism::Prism()
{
	side_length = 0.0;
	side_width = 0.0;
	front_length = 0.0;
	front_width = 0.0;
	centerPos.setX(0.0), centerPos.setY(0.0), centerPos.setZ(0.0);
	color.setRed(0), color.setGreen(0), color.setBlue(0);
}

Prism::Prism(GLfloat s_len, GLfloat s_w, GLfloat f_len, GLfloat f_w, Location l, RGBColor c, bool l_s)
{
	side_length = s_len;
	side_width = s_w;
	front_length = f_len;
	front_width = f_w;
	centerPos.setX(l.getX()); centerPos.setY(l.getY()); centerPos.setZ(l.getZ());
	color.setRed(c.getRed()); color.setGreen(c.getGreen()); color.setBlue(c.getBlue());
	light_source = l_s;
}

void Prism::setSideLength(GLfloat s_len) {	side_length = s_len;}
void Prism::setSideWidth(GLfloat s_w) {	side_width = s_w;}
void Prism::setFrontLength(GLfloat f_len) { front_length = f_len; }
void Prism::setFrontWidth(GLfloat f_w) { front_width = f_w; }
void Prism::setColor(RGBColor c) { color.setRed(c.getRed()); color.setGreen(c.getGreen()); color.setBlue(c.getBlue()); }
void Prism::setLocation(Location l) { centerPos.setX(l.getX()); centerPos.setY(l.getY()); centerPos.setZ(l.getZ()); }
void Prism::setLightSource(bool s_l){light_source = s_l; }

GLfloat Prism::getSideLength() { return side_length; }
GLfloat Prism::getSideWidth() {	return side_width;}
GLfloat Prism::getFrontLength() { return front_length; }
GLfloat Prism::getFrontWidth() { return front_width; }
RGBColor Prism::getColor() { return color; }
Location Prism::getLocation() { return centerPos; }
bool Prism::getLightSource() { return light_source; }

void Prism::drawPrism()
{
	GLfloat x = centerPos.getX(); GLfloat y = centerPos.getY(); GLfloat z = centerPos.getZ();
	GLfloat f_l_half = front_length * 0.5; GLfloat f_w_half = front_width * 0.5; 
	GLfloat s_l_half = side_length * 0.5; GLfloat s_w_half = side_width * 0.5;

	GLfloat vertices[] =
	{
		//Front face
		x - f_l_half, y + f_w_half, z + f_l_half,
		x + f_l_half, y + f_w_half, z + f_l_half,
		x + f_l_half, y - f_w_half, z + f_l_half,
		x - f_l_half, y - f_w_half, z + f_l_half,

		//Back face
		x - f_l_half, y + f_w_half, z - f_l_half,
		x + f_l_half, y + f_w_half, z - f_l_half,
		x + f_l_half, y - f_w_half, z - f_l_half,
		x - f_l_half, y - f_w_half, z - f_l_half,

		//Left face
		x - s_l_half, y + s_w_half, z + s_l_half,
		x - s_l_half, y + s_w_half, z - s_l_half,
		x - s_l_half, y - s_w_half, z - s_l_half,
		x - s_l_half, y - s_w_half, z + s_l_half,

		//Right face
		x + s_l_half, y + s_w_half, z + s_l_half,
		x + s_l_half, y + s_w_half, z - s_l_half,
		x + s_l_half, y - s_w_half, z - s_l_half,
		x + s_l_half, y - s_w_half, z + s_l_half,

		//Top face
		x - s_l_half, y + s_w_half, z + s_l_half,
		x - s_l_half, y + s_w_half, z - s_l_half,
		x + s_l_half, y + s_w_half, z - s_l_half,
		x + s_l_half, y + s_w_half, z + s_l_half,

		//Bottom face
		x - s_l_half, y - s_w_half, z + s_l_half,
		x - s_l_half, y - s_w_half, z - s_l_half,
		x + s_l_half, y - s_w_half, z - s_l_half,
		x + s_l_half, y - s_w_half, z + s_l_half
	};

	GLfloat c[3] = { this->color.getRed(),this->color.getGreen(),this->color.getBlue() };

	if (light_source == true)
	{
		GLfloat lightPosition[] = { x,y+1, z , 1 };
		glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
		glEnableClientState(GL_VERTEX_ARRAY);
		
		glVertexPointer(3, GL_FLOAT, 0, vertices);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, c);
		glDrawArrays(GL_QUADS, 0, 24);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
	else
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, vertices);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, c);
		glDrawArrays(GL_QUADS, 0, 24);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
	
}