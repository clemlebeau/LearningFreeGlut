#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

#include "math_util.hpp"

GLuint VBO; // Vertex buffer object

void renderScene() {
  glClearColor(0.0, 1.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 0, 0);

  glDrawArrays(GL_TRIANGLES, 0, 3);
  glDisableVertexAttribArray(0);

  glutSwapBuffers();
}

int main(int argc, char **argv) {

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

  glutInitWindowSize(1024, 768);
  glutCreateWindow("Test");

  GLenum glewInitResult = glewInit();
  if (glewInitResult != GLEW_OK) {
    fprintf(stderr, "Error while initializing GLEW : %s",
            glewGetErrorString(glewInitResult));
    return 1;
  }

  Vector3d vertices[3];
  vertices[0] = (Vector3d){-1.0, -1.0, 0.0};
  vertices[1] = (Vector3d){1.0, -1.0, 0.0};
  vertices[2] = (Vector3d){0.0, 1.0, 0.0};

  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glutDisplayFunc(renderScene); // Add renderScene() as a callback to GLUT's rendering call
  glutMainLoop(); // Give control to GLUT
  return 0;
}