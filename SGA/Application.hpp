#pragma once

//clang-format off
#include <GL/glew.h>
//clang-format on

#include "Timer.hpp"
#include "Window.hpp"

#include <GL/freeglut.h>
#include <iostream>
#include <list>

namespace SGA {
   class Application {
   public:
      Application(int argc,
                      char** argv,
                      unsigned int displayMode = GLUT_DOUBLE | GLUT_RGBA |
                                                 GLUT_DEPTH);

      ~Application();

      void setWindow(Window* window);

      void start();

   private:
      Timer timer_;

      Window* window_;

      int initGlew();
   };
}
