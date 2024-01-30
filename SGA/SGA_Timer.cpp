#include "SGA_Timer.hpp"

SGA_Timer::SGA_Timer() {
   startTime_ = std::chrono::steady_clock::now();
}

void SGA_Timer::reset() {
   startTime_ = std::chrono::steady_clock::now();
}

double SGA_Timer::getElapsedSeconds() {
   return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - startTime_).count() / 1000000000.0;
}