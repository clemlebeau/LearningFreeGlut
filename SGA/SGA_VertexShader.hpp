#pragma once

#include "SGA_Shader.hpp"

class SGA_VertexShader: public SGA_Shader {
public:
   SGA_VertexShader(const char* shaderPath);

protected:
   void abstract();
};
