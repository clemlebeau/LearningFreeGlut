#pragma once

#include <ctime>
#include <chrono>

class SGA_Timer {
public:
   SGA_Timer();

   void reset();

   double getElapsedSeconds();

private:
   std::chrono::steady_clock::time_point startTime_;
};