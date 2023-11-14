#include <GL/glew.h>
#include <GL/freeglut.h>

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

#include "math_util.hpp"

GLuint VBO; // Vertex buffer object

void renderScene()
{
  glClearColor(0.0, 1.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 0, 0);

  glDrawArrays(GL_TRIANGLES, 0, 6);
  glDisableVertexAttribArray(0);

  glutSwapBuffers();
}

GLuint generateRectangleVBO(const Vector3d &pos, const Vector2d &size)
{
  GLuint rectVBO;
  const Vector3d topLeft = pos;
  const Vector3d topRight = {pos.x + size.x, pos.y, pos.z};
  const Vector3d bottomLeft = {pos.x, pos.y + size.y, pos.z};
  const Vector3d bottomRight = {pos.x + size.x, pos.y + size.y, pos.z};
  Vector3d vertices[] = {bottomLeft, topLeft, topRight, bottomLeft, topRight, bottomRight};

  glGenBuffers(1, &rectVBO);
  glBindBuffer(GL_ARRAY_BUFFER, rectVBO);

  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  return rectVBO;
}

std::string readFile(const char *filePath)
{
  auto path = std::filesystem::path(filePath);
  std::ifstream file;
  file.open(filePath);
  if (!file.is_open())
  {
    fprintf(stderr, "Error while opening file %s\n", filePath);
    return "";
  }
  const auto fileSize = std::filesystem::file_size(path);
  std::string content(fileSize, '\0');
  file.read(content.data(), fileSize);
  file.close();
  return content;
}

int main(int argc, char **argv)
{

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

  glutInitWindowSize(1024, 768);
  glutCreateWindow("Test");

  GLenum glewInitResult = glewInit();
  if (glewInitResult != GLEW_OK)
  {
    fprintf(stderr, "Error while initializing GLEW : %s\n",
            glewGetErrorString(glewInitResult));
    return 1;
  }

  VBO = generateRectangleVBO({-1.0, -1.0, 0.0}, {2.0, 2.0});

  GLuint shaderProgram = glCreateProgram();

  GLuint vertShaderObj = glCreateShader(GL_VERTEX_SHADER);
  const GLchar *vertShaderPath = "../shader.vert";

  std::string vertShaderText = readFile(vertShaderPath);
  if (vertShaderText == "")
  {
    fprintf(stderr, "Error : File %s came back empty.\n", vertShaderPath);
    return 1;
  }

  const char *source[] = {vertShaderText.c_str()};
  GLint sourceSize[] = {(GLint)vertShaderText.length()};
  glShaderSource(vertShaderObj, 1, source, sourceSize);

  // glCompileShader()

  glutDisplayFunc(renderScene); // Add renderScene() as a callback to GLUT's rendering call
  glutMainLoop();               // Give control to GLUT
  return 0;
}