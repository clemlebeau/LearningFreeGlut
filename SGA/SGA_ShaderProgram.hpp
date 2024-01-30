#pragma once

#include "SGA_Shader.hpp"

#include <iostream>
#include <list>

class SGA_ShaderProgram {
public:
   SGA_ShaderProgram();

   virtual ~SGA_ShaderProgram();

   void addShader(SGA_Shader* shader);

   void buildShaders();

   bool doesProgramLink();

   void validate();

   void use();

   GLint getAttributeLocation(const char* attribute);

   GLint getUniformLocation(const char* uniform);

private:
   GLuint programIdentifier_;

   std::list<SGA_Shader*> shaders_;

   void attachShaders();
};
