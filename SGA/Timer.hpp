#pragma once

#include <chrono>
#include <ctime>

namespace SGA {
   class Timer {
   public:
      Timer();

      void reset();

      double getElapsedSeconds();

   private:
      std::chrono::steady_clock::time_point startTime_;
   };
}
