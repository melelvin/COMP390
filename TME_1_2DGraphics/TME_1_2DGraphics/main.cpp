//
//  main.cpp
//  TME_1_2DGraphics
//
//  Created by Mel Mirasol on 2014-11-28.
//  Copyright (c) 2014 Mel Mirasol. All rights reserved.
//


#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "display.h"
#include "errors.h"

// Required to identify if platform is Windows
#ifdef WIN32
#include <windows.h>
#endif

// Required to identify if platform is OSX
#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif

void drawFirstHouse() {
    // rectangle
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
        glVertex2f(-2.5f, 2.5f);
        glVertex2f(-2.0f, 0.5f);
        glVertex2f( 0.0f, 1.0f);
        glVertex2f(-0.5f, 3.0f);
    glEnd ();
    
    //triangle
    glBegin(GL_LINE_LOOP);
        glVertex3f(-1.75f, 3.50f, 0.0f);
        glVertex3f(-3.00f, 2.36f, 0.0f);
        glVertex3f( 0.00f, 3.14f, 0.0f);
    glEnd ();
}

void drawSecondHouse() {
    // rectangle
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
        glVertex2f(-1.5f, -1.5f);
        glVertex2f(-1.0f, -3.5f);
        glVertex2f( 1.0f, -3.0f);
        glVertex2f( 0.5f, -1.0f);
    glEnd ();
    
    //triangle
    glBegin(GL_LINE_LOOP);
        glVertex3f(-0.75f, -0.50f, 0.0f);
        glVertex3f(-2.00f, -1.64f, 0.0f);
        glVertex3f( 1.00f, -0.86f, 0.0f);
    glEnd ();
}

void draw () {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear display window.
    glLoadIdentity();
    
    // viewing
    gluLookAt(0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    
    drawFirstHouse();
    drawSecondHouse();
    
    glutSwapBuffers();
    glFlush ();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 40.0);
    glMatrixMode(GL_MODELVIEW);
}

int main (int argc, char** argv) {
    
    glutInit (&argc, argv); // Initialize GLUT.

    initializeDisplay(400, 400, "Mel Mirasol (3046859) - COMP390 TME 1, Program 1");
    
    if(hasError()) {
        fprintf(stderr, "The application has encountered an error: %s\n", getError());
    }
    else {
        glutDisplayFunc (draw);
        glutReshapeFunc( reshape );
        glutMainLoop ( );
    }
}