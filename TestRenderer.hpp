#pragma once

#include "SGA/SGA_Window.hpp"

class TestRenderer: public SGA_Window {
public:
   TestRenderer(int width, int height, const char* title);

   ~TestRenderer();

   void init();

   static void draw();

   void handleEvents();

   void update(double deltaTime);

private:
   TestRenderer* instance_;

   void setupDrawCallback();
};
