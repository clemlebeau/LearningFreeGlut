#pragma once

class SGA_Window {
    public:
        SGA_Window();

        virtual ~SGA_Window();

        virtual void update(double deltaTime) = 0;

        virtual void draw() = 0;

        virtual void handleEvents() = 0;
};