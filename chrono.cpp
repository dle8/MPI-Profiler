#include <chrono>

using namespace std::chrono;

namespace chrono_timer {
    typedef high_resolution_clock::time_point hrc_time;

    double elapsed_time(hrc_time t1, hrc_time t2) {
        return (t2 - t1).count();
    }

    hrc_time current_time() {
        return high_resolution_clock::now();
    }
}
