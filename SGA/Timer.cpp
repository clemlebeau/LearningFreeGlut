#include "Timer.hpp"

SGA::Timer::Timer() {
   startTime_ = std::chrono::steady_clock::now();
}

void SGA::Timer::reset() {
   startTime_ = std::chrono::steady_clock::now();
}

double SGA::Timer::getElapsedSeconds() {
   return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - startTime_).count() / 1000000000.0;
}