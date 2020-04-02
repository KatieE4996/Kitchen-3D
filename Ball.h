#define _BALL_
#ifndef _GL_
#define _GL_
#include <GL/glut.h>
#endif
#include "RGBColor.h"
#include "Location.h"

/*************************************
Function:   Ball class file
Purpose:    create a ball
Author:      https://cs.lmu.edu/~ray/notes/openglexamples/ as modified to incorporate RGBColor and Location classes
Date:   3/2/2020
*************************************/
class Ball {
    GLfloat radius;
    RGBColor color;
    GLfloat maximumHeight;
    Location location;
    GLint direction;
public:
    Ball();

    Ball(GLfloat r, RGBColor c, GLfloat h, Location l, GLint d);


    //  member set methods
    void setRadius(GLfloat r);
    void setColor(RGBColor c);
    void setLocation(Location l);
    void setMaximumHeight(GLfloat m);
    void setDirection(GLint d);


    //      member get methods
    GLfloat getRadius();
    RGBColor getColor();
    GLfloat getMaximumHeight();
    Location getLocation();
    GLint getDirection();

    //  ball movement function
    void update();
};