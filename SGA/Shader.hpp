#pragma once

//clang-format off
#include <GL/glew.h>
//clang-format on

#include <filesystem>
#include <fstream>
#include <GL/freeglut.h>
#include <iostream>
#include <string>

namespace SGA {
   class Shader {
   public:
      Shader(const char* shaderPath);

      virtual ~Shader();

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
}
