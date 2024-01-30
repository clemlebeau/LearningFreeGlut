#pragma once

#include <filesystem>
#include <fstream>
#include <GL/freeglut.h>
#include <GL/glew.h>
#include <iostream>
#include <string>

class SGA_Shader {
public:
   SGA_Shader(const char* shaderPath);

   virtual ~SGA_Shader();

   bool doesShaderCompile();

   GLuint getShaderObject();

   void useProgram();

protected:
   GLenum shaderType_;

   virtual void abstract() = 0;

private:
   const char* shaderPath_;
   GLuint shaderObj_;

   std::string readFile(const char* filePath);
};
