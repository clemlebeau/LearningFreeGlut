#include "SGA_Application.hpp"

SGA_Application::SGA_Application(int argc,
                                 char** argv,
                                 unsigned int displayMode) {
   window_ = nullptr;
   glutInit(&argc, argv);
   glutInitDisplayMode(displayMode);
}

SGA_Application::~SGA_Application() {
   delete window_;
}

int SGA_Application::initGlew() {
   GLenum glewInitResult = glewInit();
   if(glewInitResult != GLEW_OK) {
      std::cerr << "Error while initializing GLEW : "
                << glewGetErrorString(glewInitResult) << std::endl;
      return 1;
   }

   return 0;
}

void SGA_Application::setWindow(SGA_Window* window) {
   if(window_ == nullptr) {
      window_ = window;
      initGlew();
   }
}

void SGA_Application::start() {
   if(window_ == nullptr) {
      std::cerr << "No windows were added, couldn't start application."
                << std::endl;
      return;
   }

   glutMainLoop();
}
