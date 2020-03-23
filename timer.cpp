// Chorno library for high-resolution timer

#include "chrono_timer.cpp"

chrono_timer::hrc_time start[64];
double elapsed[64];

inline void timer_clear(int n) {
    elapsed[n] = 0.0;
}

inline void timer_start(int n) {
    start[n] = chrono_timer::current_time();
}

inline void timer_stop(int n) {
    chrono_timer::hrc_time now;
    now = chrono_timer::current_time();
    elapsed[n] += chrono_timer::elapsed_time(start[n], now);
}

inline double timer_read(int n) {
    return elapsed[n];
}