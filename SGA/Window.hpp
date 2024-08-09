#pragma once

#include "ShaderProgram.hpp"

//clang-format off
#include <GL/glew.h>
//clang-format on

#include <GL/freeglut.h>

namespace SGA {
   class Window {
   public:
      Window(int width, int height, const char* title);

      virtual ~Window();

      virtual void update(double deltaTime) = 0;

      virtual void handleEvents() = 0;

   protected:
      virtual void setupDrawCallback() = 0;

      // Bring back access to shader program in Window
   };
}
