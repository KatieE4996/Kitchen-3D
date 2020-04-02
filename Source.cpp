#include <windows.h>
#include <GL/glut.h>
#include "location.h"
#include "RGBColor.h"
#include "Ball.h"
#include "Checkerboard.h"
#include "Camera.h"
#include <cmath>
#include <iostream>
#include <random>
#include "Cube.h"
#include "Prism.h"

using namespace std;

/*************************************************************************
Class:		Checkboard class implementation
Purpose:	Provide a Red/White 8x8 checkerboard
Author      Cooper, using https://cs.lmu.edu/~ray/notes/openglexamples/ as an inital base
Date:	    3/2/2020

Note:       Implementation uses existing Location, RGBColor classes rather than primitives
************************************************************************/
//  globals

Ball balls[7];          //  seven balls in the example
Checkerboard board;
Camera camera;
Cube cubes;
Cube cuttingBoard;

Prism prism;
Prism fridge;
Prism counters[9];
Prism cabniets[8];
Prism table_leg;
Prism table_top;
Prism cheese;
Prism light;


//  set up colors.  Unfortunately a lot of the openGL calls use GLfloat so the RGBColor and Location information has to include a toGLFloat() function
RGBColor black(0, 0, 0);
RGBColor red(1, 0, 0);
RGBColor green(0, 1, 0);
RGBColor blue(0, 0, 1);
RGBColor cyan(0, 1, 1);
RGBColor magenta(1, 0, 1);
RGBColor yellow(1, 1, 0);
RGBColor white(1, 1, 1);
RGBColor brown(0.5, 0.35, 0.05);

GLfloat WHITE[3], RED[3], GREEN[3], BLUE[3], MAGENTA[3], YELLOW[3], CYAN[3], BLACK[3], BROWN[3];
RGBColor colors[] = { black,red,green,blue,magenta,cyan,yellow,white,brown};



/*************************************
Function:   init()
Purpose:    set up 3-D lighting
Author:      https://cs.lmu.edu/~ray/notes/openglexamples/
Date:   3/2/2020
*************************************/
void init() {
    glEnable(GL_DEPTH_TEST);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, WHITE);
    glLightfv(GL_LIGHT0, GL_SPECULAR, WHITE);
    glMaterialfv(GL_FRONT, GL_SPECULAR, WHITE);
    glMaterialf(GL_FRONT, GL_SHININESS, 30);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    board.create();
}

/*************************************
Function:   initBalls()
Purpose:    set up 7 bouncing balls
Author:      Cooper
Date:       3/2/2020
*************************************/
void initBalls() {
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1, 7);
    Location location(0, 0, 0);
    black.toGLfloatArray(BLACK);
    red.toGLfloatArray(RED);
    green.toGLfloatArray(GREEN);
    blue.toGLfloatArray(BLUE);
    magenta.toGLfloatArray(MAGENTA);
    yellow.toGLfloatArray(YELLOW);
    cyan.toGLfloatArray(CYAN);
    white.toGLfloatArray(WHITE);
    
    for (int i = 0; i < sizeof balls / sizeof(Ball); i++) {
        balls[i].setColor(colors[i]);
        balls[i].setRadius(0.5);
        balls[i].setDirection(1);
        float x = distribution(generator);
        float z = distribution(generator);
        float y = distribution(generator);
        location.setLocation(x, y, z);
        balls[i].setLocation(location);
    }

}

/*************************************
Function:   initCube()
Purpose:    set up Cube and is used for finding out deminsions during debugging
Author:      Easlon
Date:       3/31/2020
*************************************/
void initCube()
{
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1, 6);
    Location location(0, 0, 0);
    black.toGLfloatArray(BLACK);
    red.toGLfloatArray(RED);
    green.toGLfloatArray(GREEN);
    blue.toGLfloatArray(BLUE);
    magenta.toGLfloatArray(MAGENTA);
    yellow.toGLfloatArray(YELLOW);
    cyan.toGLfloatArray(CYAN);
    white.toGLfloatArray(WHITE);
    brown.toGLfloatArray(BROWN);

    cubes.setColor(colors[7]);
    cubes.setEdgeL(0.75);
    float x = distribution(generator);
    float y = distribution(generator);
    float z = distribution(generator);
    location.setLocation(1, 0.75, 3.5);
    cubes.setLocation(location);
   
}

/*************************************
Function:   initPrism()
Purpose:    set up Prism and is used for finding out deminsions during debugging
Author:      Easlon
Date:       3/31/2020
*************************************/
void initPrism()
{
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1, 6);
    Location location(0, 0, 0);
    black.toGLfloatArray(BLACK);
    red.toGLfloatArray(RED);
    green.toGLfloatArray(GREEN);
    blue.toGLfloatArray(BLUE);
    magenta.toGLfloatArray(MAGENTA);
    yellow.toGLfloatArray(YELLOW);
    cyan.toGLfloatArray(CYAN);
    white.toGLfloatArray(WHITE);
    brown.toGLfloatArray(BROWN);

    prism.setColor(colors[7]);
    prism.setFrontLength(0.23);
    prism.setFrontWidth(0.15);
    prism.setSideLength(0.23);
    prism.setSideWidth(0.15);
    float x = distribution(generator);
    float y = distribution(generator);
    float z = distribution(generator);
    location.setLocation(x,5,z);
    prism.setLightSource(true);
    prism.setLocation(location);
}

/*************************************
Function:   init_Counters()
Purpose:    set up counters in an L shape around the room
Author:      Easlon
Date:       4/1/2020
*************************************/
void init_Counters()
{
    GLfloat l = 1.34, w = 1;
    float x = 0.85, y = 0.5, z = 4.8;
    Location location(0, 0, 0);
    black.toGLfloatArray(BLACK);
    red.toGLfloatArray(RED);
    green.toGLfloatArray(GREEN);
    blue.toGLfloatArray(BLUE);
    magenta.toGLfloatArray(MAGENTA);
    yellow.toGLfloatArray(YELLOW);
    cyan.toGLfloatArray(CYAN);
    white.toGLfloatArray(WHITE);
    brown.toGLfloatArray(BROWN);

    for (int i = 0; i < 4; i++) {
        counters[i].setColor(colors[8]);
        counters[i].setFrontLength(l);
        counters[i].setFrontWidth(w);
        counters[i].setSideLength(l);
        counters[i].setSideWidth(w);
        location.setLocation(x, y, z);
        counters[i].setLocation(location);
        counters[i].setLightSource(false);
        z = z - w; //update the next z 
    }

    for (int j = 4; j < 9; j++)
    {
        counters[j].setColor(colors[8]);
        counters[j].setFrontLength(l);
        counters[j].setFrontWidth(w);
        counters[j].setSideLength(l);
        counters[j].setSideWidth(w);
        location.setLocation(x, y, z);
        counters[j].setLocation(location);
        counters[j].setLightSource(false);
        x = x + l; //update the next z 
    }
}

/*************************************
Function:   init_Cabniets()
Purpose :   set up Cabniets on the right side of the room
Author : Easlon
Date : 4 / 1 / 2020
* ************************************/
void init_Cabniets()
{
    GLfloat l = 0.75, w = 1.25;
    float x = 0.77, y = 2, z = 0.4;
    Location location(0, 0, 0);
    black.toGLfloatArray(BLACK);
    red.toGLfloatArray(RED);
    green.toGLfloatArray(GREEN);
    blue.toGLfloatArray(BLUE);
    magenta.toGLfloatArray(MAGENTA);
    yellow.toGLfloatArray(YELLOW);
    cyan.toGLfloatArray(CYAN);
    white.toGLfloatArray(WHITE);
    brown.toGLfloatArray(BROWN);

    for (int i = 0; i < 8; i++)
    {
        cabniets[i].setColor(colors[0]);
        cabniets[i].setFrontLength(l);
        cabniets[i].setFrontWidth(w);
        cabniets[i].setSideLength(l);
        cabniets[i].setSideWidth(w);
        location.setLocation(x, y, z);
        cabniets[i].setLightSource(false);
        cabniets[i].setLocation(location);
        x = x + l; //update the next z 
    }
}

/*************************************
Function:   init_Fridge()
Purpose :   set up the fridge into the left back corner of the room
Author : Easlon
Date : 4 / 1 / 2020
* ************************************/
void init_Fridge()
{
    Location location(0, 0, 0);
    black.toGLfloatArray(BLACK);
    red.toGLfloatArray(RED);
    green.toGLfloatArray(GREEN);
    blue.toGLfloatArray(BLUE);
    magenta.toGLfloatArray(MAGENTA);
    yellow.toGLfloatArray(YELLOW);
    cyan.toGLfloatArray(CYAN);
    white.toGLfloatArray(WHITE);
    brown.toGLfloatArray(BROWN);

    fridge.setColor(colors[1]);
    fridge.setFrontLength(1.5);
    fridge.setFrontWidth(2);
    fridge.setSideLength(1.5);
    fridge.setSideWidth(2);
    fridge.setLightSource(false);
    location.setLocation(1, 1, 6.2);
    fridge.setLocation(location);
}

/*************************************
Function:   init_CuttingBoard()
Purpose:    set up a cutting board on the counter
Author:      Easlon
Date:      04/01/2020
*************************************/
void init_CuttingBoard()
{
    Location location(0, 0, 0);
    black.toGLfloatArray(BLACK);
    red.toGLfloatArray(RED);
    green.toGLfloatArray(GREEN);
    blue.toGLfloatArray(BLUE);
    magenta.toGLfloatArray(MAGENTA);
    yellow.toGLfloatArray(YELLOW);
    cyan.toGLfloatArray(CYAN);
    white.toGLfloatArray(WHITE);
    brown.toGLfloatArray(BROWN);

    cuttingBoard.setColor(colors[7]);
    cuttingBoard.setEdgeL(0.75);
    location.setLocation(1, 0.75, 3.5);
    cuttingBoard.setLocation(location);
}

/*************************************
Function:   init_Table()
Purpose:    set up a table
Author:      Easlon
Date:      04/01/2020
*************************************/
void init_Table()
{
    Location top_location(0, 0, 0);
    Location leg_location(0, 0, 0);
    black.toGLfloatArray(BLACK);
    red.toGLfloatArray(RED);
    green.toGLfloatArray(GREEN);
    blue.toGLfloatArray(BLUE);
    magenta.toGLfloatArray(MAGENTA);
    yellow.toGLfloatArray(YELLOW);
    cyan.toGLfloatArray(CYAN);
    white.toGLfloatArray(WHITE);
    brown.toGLfloatArray(BROWN);

    float x = 5, y = 0.75, z = 5;
    GLfloat leg_l = 0.25, leg_w = 0.75, topF_l = 1, topS_l = 2, top_w = 0.05;

    top_location.setLocation(x, y, z);
    leg_location.setLocation(x, 0.33, z);

    table_top.setColor(colors[2]);
    table_top.setFrontLength(topF_l);
    table_top.setFrontWidth(top_w);
    table_top.setSideLength(topS_l);
    table_top.setSideWidth(top_w);
    table_top.setLightSource(true);
    table_top.setLocation(top_location);

    table_leg.setColor(colors[2]);
    table_leg.setFrontLength(leg_l);
    table_leg.setFrontWidth(leg_w);
    table_leg.setSideLength(leg_l);
    table_leg.setSideWidth(leg_w);
    table_leg.setLightSource(false);
    table_leg.setLocation(leg_location);
}

/*************************************
Function:   init_Cheese()
Purpose:    set up cheese on a cutting board
Author:      Easlon
Date:      04/01/2020
*************************************/
void init_Cheese()
{
    Location location(0, 0, 0);
    location.setLocation(1, 1.2, 3.4);
    black.toGLfloatArray(BLACK);
    red.toGLfloatArray(RED);
    green.toGLfloatArray(GREEN);
    blue.toGLfloatArray(BLUE);
    magenta.toGLfloatArray(MAGENTA);
    yellow.toGLfloatArray(YELLOW);
    cyan.toGLfloatArray(CYAN);
    white.toGLfloatArray(WHITE);
    brown.toGLfloatArray(BROWN);

    cheese.setColor(colors[6]);
    cheese.setFrontLength(0.23);
    cheese.setFrontWidth(0.15);
    cheese.setSideLength(0.23);
    cheese.setSideWidth(0.15);
    cheese.setLightSource(false);
    cheese.setLocation(location);
}

/*************************************
Function:   init_Light()
Purpose:    set up a Light from the ceiling
Author:      Easlon
Date:      04/01/2020
*************************************/
void init_Light()
{
    Location location(0, 0, 0);
    black.toGLfloatArray(BLACK);
    red.toGLfloatArray(RED);
    green.toGLfloatArray(GREEN);
    blue.toGLfloatArray(BLUE);
    magenta.toGLfloatArray(MAGENTA);
    yellow.toGLfloatArray(YELLOW);
    cyan.toGLfloatArray(CYAN);
    white.toGLfloatArray(WHITE);
    brown.toGLfloatArray(BROWN);

    light.setColor(colors[7]);
    light.setFrontLength(0.25);
    light.setFrontWidth(2);
    light.setSideLength(0.25);
    light.setSideWidth(2);

    location.setLocation(6, 5.5, 6);
    light.setLightSource(true);
    light.setLocation(location);
}


/*************************************
Function:   display()
Purpose:    set up display and update
Author:      https://cs.lmu.edu/~ray/notes/openglexamples/ modified by Easlon
Date:       4/1/2020
*************************************/
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(camera.getX(), camera.getY(), camera.getZ(),
        board.centerx(), 0.0, board.centerz(),
        0.0, 1.0, 0.0);
    board.draw();
    prism.drawPrism();

    //draws the counters
    for (int i = 0; i < 9; i++) {
        counters[i].drawPrism();
    }
    
    //draws the cabniets
    for (int j = 0; j < 8; j++) {
        cabniets[j].drawPrism();
    }
    
    //draws the fridge
    fridge.drawPrism();

    //draws cutting board
    cuttingBoard.drawCube();

    //draws the table
    table_top.drawPrism();
    table_leg.drawPrism();

    //draws the cheese on the cutting board
    cheese.drawPrism();
    
    light.drawPrism();

    glFlush();
    glutSwapBuffers();
}

/*************************************
Function:   reshape()
Purpose:    manage changes to the window aspect ratio
Author:      https://cs.lmu.edu/~ray/notes/openglexamples/
Date:       3/2/2020
*************************************/
void reshape(GLint w, GLint h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, GLfloat(w) / GLfloat(h), 1.0, 150.0);
    glMatrixMode(GL_MODELVIEW);
}

/*************************************
Function:   timer()
Purpose:    manage update speed
Author:      https://cs.lmu.edu/~ray/notes/openglexamples/
Date:       3/2/2020
*************************************/
void timer(int v) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, v);
}

/*************************************
Function:   special()
Purpose:    manage special keys, Arrow keys
Author:      https://cs.lmu.edu/~ray/notes/openglexamples/
Date:       3/2/2020
*************************************/
void special(int key, int, int) {
    switch (key) {
    case GLUT_KEY_LEFT: camera.moveLeft(); break;
    case GLUT_KEY_RIGHT: camera.moveRight(); break;
    case GLUT_KEY_UP: camera.moveUp(); break;
    case GLUT_KEY_DOWN: camera.moveDown(); break;
    }
    glutPostRedisplay();
}

// Initializes GLUT and enters the main loop.
int main(int argc, char** argv) {
    //initCube();
    //initPrism();
    //initBalls();
    init_Counters();
    init_Cabniets();
    init_Fridge();
    init_CuttingBoard();
    init_Table();
    init_Cheese();
    init_Light();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Kitchen");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(special);
    glutTimerFunc(100, timer, 0);

    init();
    glutMainLoop();
}