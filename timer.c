// Chorno library for high-resolution timer

#include <chrono>
#include <stdlib.h>
#include <iostream>
#include <ctime>

using namespace chrono;

typedef high_resolution_clock::time_point tp;

tp current_time(void) {
    return high_resolution_clock::now();
}

tp start[64];
double elapsed[64];

inline void _timer_clear(int n) {
    elapsed[n] = 0.0;
}

inline void _timer_start(int n) {
    start[n] = current_time();
}

inline void _timer_stop(int n) {
    tp now;
    now = current_time();
    duration<double> elapsed_time = now - start[n];
    elapsed[n] += elapsed_time.count();
}

inline double _timer_read(int n) {
    return elapsed[n];
}