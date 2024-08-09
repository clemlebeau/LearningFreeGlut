#include "Shader.hpp"

SGA::Shader::Shader(const char* shaderPath) {
   shaderPath_ = shaderPath;
}

SGA::Shader::~Shader() {
   glDeleteShader(shaderObj_);
}

bool SGA::Shader::doesShaderCompile() {
   shaderObj_ = glCreateShader(shaderType_);

   std::string shaderText = readFile(shaderPath_);
   if(shaderText == "") {
      std::cerr << "Error: file " << shaderPath_ << " came back empty."
                << std::endl;
      return false;
   }

   const char* shaderSource[] = {shaderText.c_str()};
   GLint sourceSize[] = {(GLint) shaderText.length()};
   glShaderSource(shaderObj_, 1, shaderSource, sourceSize);

   glCompileShader(shaderObj_);
   GLint compileStatus;
   glGetShaderiv(shaderObj_, GL_COMPILE_STATUS, &compileStatus);
   if(!compileStatus) {
      char infoLog[1024];
      glGetShaderInfoLog(shaderObj_, sizeof(infoLog), NULL, infoLog);
      std::cerr << "Error at shader compile time : " << infoLog << std::endl;
      return false;
   }

   return true;
}

GLuint SGA::Shader::getShaderObject() {
   return shaderObj_;
}

std::string SGA::Shader::readFile(const char* filePath) {
   auto path = std::filesystem::path(filePath);
   std::ifstream file;
   file.open(filePath);
   if(!file.is_open()) {
      std::cerr << "Error while opening file " << filePath << std::endl;
      return "";
   }
   const auto fileSize = std::filesystem::file_size(path);
   std::string content(fileSize, '\0');
   file.read(content.data(), fileSize);
   file.close();
   return content;
}
