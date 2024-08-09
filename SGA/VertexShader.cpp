#include "VertexShader.hpp"

SGA::VertexShader::VertexShader(const char* shaderPath) : SGA::Shader(shaderPath) {
   shaderType_ = GL_VERTEX_SHADER;
}

void SGA::VertexShader::abstract() {}