#include "SGA_FragmentShader.hpp"

SGA_FragmentShader::SGA_FragmentShader(const char* shaderPath) : SGA_Shader(shaderPath) {
   shaderType_ = GL_FRAGMENT_SHADER;
}