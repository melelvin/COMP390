//
//  errors.h
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

#ifndef TME_1_2DGraphics_1_errors_h
#define TME_1_2DGraphics_1_errors_h

int hasError() {
    return glGetError();
}

const GLubyte * getError() {
    return gluErrorString(glGetError());
}

#endif
