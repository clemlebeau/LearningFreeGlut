#pragma once

#include "SGA_ShaderProgram.hpp"
#include "SGA_Window.hpp"

class SGA_Renderer: public SGA_Window {
public:
   SGA_Renderer(int width, int height, const char* title);

   virtual ~SGA_Renderer();

   virtual void update(double deltaTime) = 0;

   virtual void draw() = 0;

   virtual void handleEvents() = 0;

private:
   SGA_ShaderProgram shaderProgram_;
};
