#include "Window.hpp"

SGA::Window::Window(int width, int height, const char* title) {
   glutInitWindowSize(width, height);
   glutCreateWindow(title);
}

SGA::Window::~Window() {}
