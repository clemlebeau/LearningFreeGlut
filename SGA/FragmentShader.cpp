#include "FragmentShader.hpp"

SGA::FragmentShader::FragmentShader(const char* shaderPath) : SGA::Shader(shaderPath) {
   shaderType_ = GL_FRAGMENT_SHADER;
}

void SGA::FragmentShader::abstract() {}