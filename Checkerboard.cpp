#include "checkerboard.h"
#include "RGBColor.h"


/*************************************************************************
Class:		Checkboard class implementation
Purpose:	Provide a Blue/White 8x8 checkerboard, 3 walls, and a ceiling
Author  https://cs.lmu.edu/~ray/notes/openglexamples/ as modified by Cooper and Easlon
Date:	3/2/2020
************************************************************************/

//Constructors.  For the moment, only the default constructor is used
Checkerboard::Checkerboard() { width = 8, depth = 8; displayListId = 0; }
Checkerboard::Checkerboard(GLint w, GLint d) { width = w;	depth = d; displayListId = 0; }

//get the center of the board for the camera
double Checkerboard::centerx() { return width / 2; }
double Checkerboard::centerz() { return depth / 2; }

//  construct the checkerboard
void Checkerboard::create() {
    RGBColor blue(0, 0, 1);
    RGBColor white(1, 1, 1);
    RGBColor red(1, 0, 0);
    RGBColor black(0, 0, 0);

    GLfloat RED[3] = { red.getRed(), red.getGreen(), red.getBlue() };
    GLfloat BLUE[3] = { blue.getRed(),blue.getGreen(),blue.getBlue() };
    GLfloat WHITE[3] = { white.getRed(),white.getGreen(),white.getBlue() };
    GLfloat BLACK[3] = { black.getRed(), black.getGreen(), black.getBlue() };

    displayListId = glGenLists(1);
    glNewList(displayListId, GL_COMPILE);
    GLfloat lightPosition[] = { 0, 5,3, 2 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glBegin(GL_QUADS);
    glNormal3d(0, 1, 0);
    int r_z = depth - 1;

    for (int x = 0; x < width - 1; x++) {
        for (int z = 0; z < depth - 1; z++) {
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,
                (x + z) % 2 == 0 ? BLACK : WHITE);
            glVertex3d(x, 0, z);
            glVertex3d(x + 1.0, 0, z);
            glVertex3d(x + 1.0, 0, z + 1.0);
            glVertex3d(x, 0, z + 1.0);
        }
    }

    //Back wall with a window
    for (int x = 0; x < width - 1; x++) {
        for (int z = 0; z < depth - 1; z++) {
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ((x) == 1 || (x) == 2) && z == 2  ? WHITE: BLUE);
            glVertex3d(0, x, z);
            glVertex3d(0, x + 1.0, z);
            glVertex3d(0, x + 1.0, z + 1.0);
            glVertex3d(0, x, z + 1.0);
        }
    }

    //Side wall to the right
    for (int x = 0; x < width - 1; x++) {
        for (int z = 0; z < depth - 1; z++) {
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, BLUE);
            glVertex3d(x, z, 0);
            glVertex3d(x + 1.0, z, 0);
            glVertex3d(x + 1.0, z + 1.0, 0);
            glVertex3d(x, z + 1.0, 0);
        }
    }

    //Third wall (On the right)
    for (int x = 0; x < width - 1; x++) {
        for (int z = 0; z < depth - 1; z++) {
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, BLUE);
            glVertex3d(x, z, r_z);
            glVertex3d(x + 1.0, z, r_z);
            glVertex3d(x + 1.0, z + 1.0, r_z);
            glVertex3d(x, z + 1.0, r_z);
        }
    }

    //ceiling
    for (int x = 0; x < width - 1; x++) {
        for (int z = 0; z < depth - 1; z++) {
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, RED);
            glVertex3d(x, 7, z);
            glVertex3d(x + 1.0, 7, z);
            glVertex3d(x + 1.0, 7, z + 1.0);
            glVertex3d(x, 7, z + 1.0);
        }
    }

    glEnd();
    glEndList();
}

//  support function for create to identify the tile list
void Checkerboard::draw() {
    glCallList(displayListId);
}