#include "ShaderProgram.hpp"

SGA::ShaderProgram::ShaderProgram() {
   programIdentifier_ = glCreateProgram();
}

SGA::ShaderProgram::~ShaderProgram() {
   for(auto shader: shaders_) {
      glDetachShader(programIdentifier_, shader->getShaderObject());
      delete shader;
   }
}

void SGA::ShaderProgram::addShader(SGA::Shader* shader) {
   shaders_.push_back(shader);
}

bool SGA::ShaderProgram::doesProgramLink() {
   attachShaders();

   GLint linkStatus;
   glGetProgramiv(programIdentifier_, GL_LINK_STATUS, &linkStatus);
   if(linkStatus == 0) {
      char infoLog[1024];
      glGetProgramInfoLog(
          programIdentifier_, sizeof(infoLog), nullptr, infoLog);
      std::cerr << "Error at shader link time : " << infoLog << std::endl;

      return false;
   }

   return true;
}

void SGA::ShaderProgram::buildShaders() {
   for(auto shader: shaders_) {
      shader->doesShaderCompile();
   }
}

void SGA::ShaderProgram::attachShaders() {
   for(auto shader: shaders_)
      glAttachShader(programIdentifier_, shader->getShaderObject());
}

void SGA::ShaderProgram::validate() {
   glValidateProgram(programIdentifier_);
}

void SGA::ShaderProgram::use() {
   glUseProgram(programIdentifier_);
}

GLint SGA::ShaderProgram::getAttributeLocation(const char* attribute) {
   return glGetAttribLocation(programIdentifier_, attribute);
}

GLint SGA::ShaderProgram::getUniformLocation(const char* uniform) {
   return glGetUniformLocation(programIdentifier_, uniform);
}