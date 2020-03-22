// Chorno library for high-resolution timer

#include "chrono.cpp"

chrono::hrc_time current_time(void) {
    return high_resolution_clock::now();
}

chrono::hrc_time start[64];
double elapsed[64];

inline void _timer_clear(int n) {
    elapsed[n] = 0.0;
}

inline void _timer_start(int n) {
    start[n] = current_time();
}

inline void _timer_stop(int n) {
    chrono::hrc_time now;
    now = current_time();
    elapsed[n] += elapsed_time(start[n], now);
}

inline double _timer_read(int n) {
    return elapsed[n];
}