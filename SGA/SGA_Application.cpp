#include "SGA_Application.hpp"

#include <GL/freeglut.h>
#include <GL/glew.h>

#include <iostream>

SGA_Application::SGA_Application(int argc, char **argv, unsigned int displayMode = GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH) {
   glutInit(&argc, argv);
   glutInitDisplayMode(displayMode);
}

int SGA_Application::initGlew() {
   GLenum glewInitResult = glewInit();
   if(glewInitResult != GLEW_OK) {
      std::cerr << "Error while initializing GLEW : " << glewGetErrorString(glewInitResult) << std::endl;
      return 1;
   }

   return 0;
}

void SGA_Application::addWindow(SGA_Window* window) {
   windows_.push_back(window);
}

void SGA_Application::start() {
   if(windows_.size() <= 0) {
      std::cerr << "No windows were added, couldn't start application." << std::endl;
      return;
   }
   
   int glewInitResult = initGlew();
   if(glewInitResult != 0) {
      return;
   }

   // TODO: Application loop
}
