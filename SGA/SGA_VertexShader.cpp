#include "SGA_VertexShader.hpp"

SGA_VertexShader::SGA_VertexShader(const char* shaderPath) : SGA_Shader(shaderPath) {
   shaderType_ = GL_VERTEX_SHADER;
}

void SGA_VertexShader::abstract() {}