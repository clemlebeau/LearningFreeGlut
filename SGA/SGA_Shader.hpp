#pragma once

#include <GL/freeglut.h>
#include <GL/glew.h>

class SGA_Shader {
    public:
        SGA_Shader();

        virtual ~SGA_Shader();

        void loadCompileShader();

        GLuint getShaderObject();
    
    private:
        GLenum shaderType_;
        char* shaderPath_;
        GLuint shaderObj_;
};
