#include "SGA_Window.hpp"

#include <GL/freeglut.h>

SGA_Window::SGA_Window(int width, int height, const char* title) {
   glutInitWindowSize(width, height);
   glutCreateWindow(title);
}
