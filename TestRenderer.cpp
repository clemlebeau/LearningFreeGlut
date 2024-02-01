#include "TestRenderer.hpp"

TestRenderer::TestRenderer(int width, int height, const char* title):
    SGA::Window(width, height, title) {
   setupDrawCallback();
}

TestRenderer::~TestRenderer() {}

void TestRenderer::setupDrawCallback() {
   instance_ = this;
   glutDisplayFunc(draw);
}

void TestRenderer::draw() {
   glClearColor(0.0, 1.0, 0.0, 1.0);
   glClear(GL_COLOR_BUFFER_BIT);

   glutPostRedisplay();
   glutSwapBuffers();
}

void TestRenderer::update(double deltaTime) {}

void TestRenderer::handleEvents() {}
