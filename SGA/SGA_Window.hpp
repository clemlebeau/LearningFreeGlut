#pragma once

#include "SGA_ShaderProgram.hpp"

//clang-format off
#include <GL/glew.h>
//clang-format on

#include <GL/freeglut.h>

class SGA_Window {
public:
   SGA_Window(int width, int height, const char* title);

   virtual ~SGA_Window();

   virtual void update(double deltaTime) = 0;

   virtual void handleEvents() = 0;

protected:
   virtual void setupDrawCallback() = 0;

   // Bring back access to shader program in SGA_Window
};
