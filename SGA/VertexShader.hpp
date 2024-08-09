#pragma once

#include "Shader.hpp"

namespace SGA {
   class VertexShader: public Shader {
   public:
      VertexShader(const char* shaderPath);

   protected:
      void abstract();
   };
};
