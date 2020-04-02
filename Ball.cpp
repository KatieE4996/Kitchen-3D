#include "Ball.h" 

/*************************************
Name        Ball.cpp
Purpose:    Ball class implementation file
Author:     Cooper, based on  https://cs.lmu.edu/~ray/notes/openglexamples/
Date:       3/2/2020
*************************************/


//  Constructors
Ball::Ball() {
    {
        radius = 0.0;
        color.setRed(0); color.setGreen(0); color.setBlue(0);
        maximumHeight = 5;
        location.setX(0.0); location.setY(0.0), location.setZ(0.0);
        direction = 1;
    }
}

Ball::Ball(GLfloat r, RGBColor c, GLfloat h, Location l, GLint d) {
    radius = r;
    color.setRed(c.getRed()); color.setGreen(c.getGreen()); color.setBlue(c.getBlue());
    maximumHeight = h;
    location.setX(l.getX()); location.setY(l.getY()), location.setZ(l.getZ());
    direction = d;
}


//  member set methods
void Ball::setRadius(GLfloat r) { radius = r; }
void Ball::setColor(RGBColor c) { color.setRed(c.getRed()); color.setBlue(c.getBlue()); color.setGreen(c.getGreen()); }
void Ball::setLocation(Location l) { location.setX(l.getX()); location.setY(l.getY()); location.setZ(l.getZ()); }
void Ball::setMaximumHeight(GLfloat m) { maximumHeight = m; }
void Ball::setDirection(GLint d) { direction = d; }

//  member get methods
GLfloat Ball::getRadius() { return radius; }
RGBColor Ball::getColor() { return color; }
GLfloat Ball::getMaximumHeight() { return maximumHeight; }
Location Ball::getLocation() { return location; }
GLint Ball::getDirection() { return direction; }


/*************************************
Function:   update()
Purpose:    changes the current location and possible direction of ball movement
Author:      https://cs.lmu.edu/~ray/notes/openglexamples/
Date:   3/2/2020
*************************************/
void Ball::update() {
    location.setY(location.getY() + direction * 0.05);        //  change the Ball position
    if (location.getY() > maximumHeight) {                  //  check whether it should change direction
        location.setY(maximumHeight); direction = -1;
    }
    else if (location.getY() < radius) {
        location.setY(radius); direction = 1;
    }

    //  get the color, becaue glMaterialfv has to use a glFloat array
    GLfloat c[3] = { this->color.getRed(),this->color.getGreen(),this->color.getBlue() };
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, c);
    glTranslated(location.getX(), location.getY(), location.getZ());      //  move the ball

    glutSolidSphere(radius, 30, 30);                                    // redraw
    glPopMatrix();                                                      // and reset the stack
}