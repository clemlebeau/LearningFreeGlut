#pragma once

#include <list>

#include "SGA_Window.hpp"
#include "SGA_Timer.hpp"

class SGA_Application {
    public:
        SGA_Application();

        SGA_Application& getInstance();

        void addWindow(SGA_Window* window);

        void start();
    private:
        static SGA_Application instance_;

        SGA_Timer timer_;

        std::list<SGA_Window*> windows_;
};
SGA_Application SGA_Application::instance_;