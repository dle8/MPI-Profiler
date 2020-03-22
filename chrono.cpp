#include <chrono>

using namespace std::chrono;

namespace chrono {
    typedef high_resolution_clock::time_point hrc_time;

    double elasped_time(hrc_time t1, hrc_time t2) {
        return (t2 - t1).count();
    }
}
