#pragma once

#include "SGA_Window.hpp"
#include "SGA_ShaderProgram.hpp"

class SGA_Renderer : public SGA_Window {
    public:
        SGA_Renderer();

        virtual ~SGA_Renderer();

        virtual void update(double deltaTime) = 0;
        
        virtual void draw() = 0;

        virtual void handleEvents() = 0;

    private:
        SGA_ShaderProgram *shaderProgram_;
};