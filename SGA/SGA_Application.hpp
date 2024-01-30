#pragma once

#include "SGA_Timer.hpp"
#include "SGA_Window.hpp"

#include <GL/freeglut.h>
#include <GL/glew.h>
#include <iostream>
#include <list>

class SGA_Application {
public:
   SGA_Application(int argc,
                   char** argv,
                   unsigned int displayMode = GLUT_DOUBLE | GLUT_RGBA |
                                              GLUT_DEPTH);

   SGA_Application& getInstance();

   void addWindow(SGA_Window* window);

   void start();

private:
   static SGA_Application instance_;

   SGA_Timer timer_;

   std::list<SGA_Window*> windows_;

   int initGlew();
};

SGA_Application SGA_Application::instance_;
