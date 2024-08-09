#pragma once

#include "Shader.hpp"

namespace SGA {
   class FragmentShader: public Shader {
   public:
      FragmentShader(const char* shaderPath);

   protected:
      void abstract();
   };
}
