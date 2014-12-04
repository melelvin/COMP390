//
//  display.h
//  TME_1_2DGraphics_1
//
//  Created by Mel Mirasol on 2014-12-02.
//  Copyright (c) 2014 Mel Mirasol. All rights reserved.
//

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

#ifndef TME_1_2DGraphics_1_display_h
#define TME_1_2DGraphics_1_display_h

void initializeDisplay(int width, int height, std::string title) {
    
    const char *c_title = title.c_str();
    
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH) ;
    // Center the window to the screen, just for aesthetic purposes.
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-width)/2,
                           (glutGet(GLUT_SCREEN_HEIGHT)-height)/2);
    
    glutInitWindowSize (width, height); // Set display-window width and height.
    
    int windowHandle = glutCreateWindow (c_title); // Create display window.
    glutSetWindow(windowHandle);
    
    glClearColor (1.0, 1.0, 1.0, 0.0); // Set display-window color to white.
}

#endif
