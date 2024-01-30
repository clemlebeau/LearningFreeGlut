#pragma once

//clang-format off
#include <GL/glew.h>
//clang-format on

#include "SGA_Timer.hpp"
#include "SGA_Window.hpp"

#include <GL/freeglut.h>
#include <iostream>
#include <list>

class SGA_Application {
public:
   SGA_Application(int argc,
                   char** argv,
                   unsigned int displayMode = GLUT_DOUBLE | GLUT_RGBA |
                                              GLUT_DEPTH);

   ~SGA_Application();

   void setWindow(SGA_Window* window);

   void start();

private:
   SGA_Timer timer_;

   SGA_Window* window_;

   int initGlew();
};
