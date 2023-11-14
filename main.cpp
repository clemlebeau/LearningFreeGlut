#include <GL/glew.h>
#include <GL/freeglut.h>

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

#include "math_util.hpp"

GLuint VBO; // Vertex buffer object

GLint vertPositionLocation;
GLint screenSize;

void renderScene()
{
  glClearColor(0.0, 1.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glUniform2f(screenSize, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));

  glEnableVertexAttribArray(vertPositionLocation);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 0, 0);

  glDrawArrays(GL_TRIANGLES, 0, 6);
  glDisableVertexAttribArray(vertPositionLocation);

  glutPostRedisplay(); // Force freeGLUT to call render() again
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

bool loadCompileShader(const char *shaderPath, GLenum shaderType, GLuint *outShaderObj)
{
  *outShaderObj = glCreateShader(shaderType);

  std::string vertShaderText = readFile(shaderPath);
  if (vertShaderText == "")
  {
    fprintf(stderr, "Error : File %s came back empty.\n", shaderPath);
    return false;
  }

  const char *source[] = {vertShaderText.c_str()};
  GLint sourceSize[] = {(GLint)vertShaderText.length()};
  glShaderSource(*outShaderObj, 1, source, sourceSize);

  glCompileShader(*outShaderObj);
  GLint success;
  glGetShaderiv(*outShaderObj, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    GLchar infoLog[1024];
    glGetShaderInfoLog(*outShaderObj, sizeof(infoLog), NULL, infoLog);
    fprintf(stderr, "Error at shader compile time : %s\n", infoLog);
    return false;
  }
  return true;
}

int main(int argc, char **argv)
{
  // TODO : Tidy up source code with OOP now that shaders are working.

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

  const char *vertShaderPath = "../shader.vert";
  GLuint vertShaderObj;
  if (!loadCompileShader(vertShaderPath, GL_VERTEX_SHADER, &vertShaderObj))
    return 1;
  glAttachShader(shaderProgram, vertShaderObj);

  const char *fragShaderPath = "../shader.frag";
  GLuint fragShaderObj;
  if(!loadCompileShader(fragShaderPath, GL_FRAGMENT_SHADER, &fragShaderObj))
    return 1;
  glAttachShader(shaderProgram, fragShaderObj);

  glLinkProgram(shaderProgram);
  GLint success;
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if(success == 0) {
    GLchar infoLog[1024];
    glGetProgramInfoLog(shaderProgram, sizeof(infoLog), NULL, infoLog);
    fprintf(stderr, "Error at shader program link time : %s\n", infoLog);
    return 1;
  }

  glValidateProgram(shaderProgram);

  glDetachShader(shaderProgram, vertShaderObj);
  glDeleteShader(vertShaderObj);
  glDetachShader(shaderProgram, fragShaderObj);
  glDeleteShader(fragShaderObj);

  glUseProgram(shaderProgram);

  vertPositionLocation = glGetAttribLocation(shaderProgram, "position");
  if (vertPositionLocation == 0xFFFFFFFF) {
    fprintf(stderr, "Couldn't find 'position' in shader program.\n");
    return 1;
  }

  screenSize = glGetUniformLocation(shaderProgram, "screenSize");
  if (screenSize == 0xFFFFFFFF) {
    fprintf(stderr, "Couldn't find 'screenSize' in shader program.\n");
    return 1;
  }

  glutDisplayFunc(renderScene); // Add renderScene() as a callback to GLUT's rendering call
  glutMainLoop();               // Give control to GLUT
  return 0;
}