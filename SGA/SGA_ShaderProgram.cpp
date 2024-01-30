#include "SGA_ShaderProgram.hpp"

SGA_ShaderProgram::SGA_ShaderProgram() {
   programIdentifier_ = glCreateProgram();
}

SGA_ShaderProgram::~SGA_ShaderProgram() {
   for(auto shader: shaders_) {
      glDetachShader(programIdentifier_, shader->getShaderObject());
      delete shader;
   }
}

void SGA_ShaderProgram::addShader(SGA_Shader* shader) {
   shaders_.push_back(shader);
}

bool SGA_ShaderProgram::doesProgramLink() {
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

void SGA_ShaderProgram::buildShaders() {
   for(auto shader: shaders_) {
      shader->doesShaderCompile();
   }
}

void SGA_ShaderProgram::attachShaders() {
   for(auto shader: shaders_)
      glAttachShader(programIdentifier_, shader->getShaderObject());
}

void SGA_ShaderProgram::validate() {
   glValidateProgram(programIdentifier_);
}

void SGA_ShaderProgram::use() {
   glUseProgram(programIdentifier_);
}

GLint SGA_ShaderProgram::getAttributeLocation(const char* attribute) {
   return glGetAttribLocation(programIdentifier_, attribute);
}

GLint SGA_ShaderProgram::getUniformLocation(const char* uniform) {
   return glGetUniformLocation(programIdentifier_, uniform);
}