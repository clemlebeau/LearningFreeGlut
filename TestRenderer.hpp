#pragma once

#include "SGA/Window.hpp"

class TestRenderer: public SGA::Window {
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
