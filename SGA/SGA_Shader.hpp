#pragma once

#include <GL/freeglut.h>
#include <GL/glew.h>
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

private:
   const char* shaderPath_;
   GLuint shaderObj_;

   std::string readFile(const char* filePath);
};
