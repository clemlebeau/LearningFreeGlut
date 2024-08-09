#include "Application.hpp"

SGA::Application::Application(int argc,
                                 char** argv,
                                 unsigned int displayMode) {
   window_ = nullptr;
   glutInit(&argc, argv);
   glutInitDisplayMode(displayMode);
}

SGA::Application::~Application() {
   delete window_;
}

int SGA::Application::initGlew() {
   GLenum glewInitResult = glewInit();
   if(glewInitResult != GLEW_OK) {
      std::cerr << "Error while initializing GLEW : "
                << glewGetErrorString(glewInitResult) << std::endl;
      return 1;
   }

   return 0;
}

void SGA::Application::setWindow(SGA::Window* window) {
   if(window_ == nullptr) {
      window_ = window;
      initGlew();
   }
}

void SGA::Application::start() {
   if(window_ == nullptr) {
      std::cerr << "No windows were added, couldn't start application."
                << std::endl;
      return;
   }

   glutMainLoop();
}
