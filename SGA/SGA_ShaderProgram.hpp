#pragma once

#include "SGA_Shader.hpp"

#include <list>

class SGA_ShaderProgram {
public:
   SGA_ShaderProgram();

   virtual ~SGA_ShaderProgram();

   void addShader(SGA_Shader* shader);

   bool doesProgramLink();

   void validateProgram();

   void use();

private:
   GLuint programIdentifier_;

   std::list<SGA_Shader*> shaders_;

   void attachShaders();
};
