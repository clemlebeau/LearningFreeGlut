#pragma once

#include <GL/freeglut.h>

class SGA_Window {
public:
   SGA_Window(int width, int height, const char* title);

   virtual ~SGA_Window();

   virtual void update(double deltaTime) = 0;

   virtual void draw() = 0;

   virtual void handleEvents() = 0;
};
