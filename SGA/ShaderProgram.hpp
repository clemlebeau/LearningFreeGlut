#pragma once

#include "Shader.hpp"

#include <iostream>
#include <list>

namespace SGA {
   class ShaderProgram {
   public:
      ShaderProgram();

      virtual ~ShaderProgram();

      void addShader(Shader* shader);

      void buildShaders();

      bool doesProgramLink();

      void validate();

      void use();

      GLint getAttributeLocation(const char* attribute);

      GLint getUniformLocation(const char* uniform);

   private:
      GLuint programIdentifier_;

      std::list<Shader*> shaders_;

      void attachShaders();
   };
}
