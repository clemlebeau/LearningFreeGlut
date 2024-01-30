#pragma once

#include <list>

#include "SGA_Shader.hpp"

class SGA_ShaderProgram {
    public:
        SGA_ShaderProgram();

        virtual ~SGA_ShaderProgram();

        void addShader(SGA_Shader* shader);

        void linkProgram();

        void validateProgram();
    
    private:
        std::list<SGA_Shader*> shaders;
};