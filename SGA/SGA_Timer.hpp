#pragma once

class SGA_Timer {
    public:
        SGA_Timer();

        void reset();

        double getElapsedSeconds();
    
    private:
        double startTime_;
};