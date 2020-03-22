// Chorno library for high-resolution timer

#include "chrono.cpp"

hrc_time current_time(void) {
    return high_resolution_clock::now();
}

hrc_time start[64];
double elapsed[64];

inline void _timer_clear(int n) {
    elapsed[n] = 0.0;
}

inline void _timer_start(int n) {
    start[n] = current_time();
}

inline void _timer_stop(int n) {
    hrc_time now;
    now = current_time();
    duration<double> elapsed_time = now - start[n];
    elapsed[n] += elapsed_time.count();
}

inline double _timer_read(int n) {
    return elapsed[n];
}