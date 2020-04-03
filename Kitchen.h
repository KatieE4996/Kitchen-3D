#include <GL/glut.h>
#include "Location.h"
#include "RGBColor.h"

/*************************************************************************
Class:		Kitchen class
Purpose:	Provide a Blue/White 8x8 checkerboard, 3 walls, and a ceiling
Author https://cs.lmu.edu/~ray/notes/openglexamples/ as modified by Cooper and Easlon
Date:	3/2/2020
************************************************************************/

class Kitchen{
private:
    GLint displayListId;        //  List of individual tiles
    GLint width;               //    width and depth of checkboard in tile units
    GLint depth;
public:
    Kitchen();
    Kitchen(GLint width, GLint depth);

    // Locate the center of the checkboard for the camera
    double centerx();
    double centerz();

    // Create and draw checkerboard
    void create();
    void draw();
};

