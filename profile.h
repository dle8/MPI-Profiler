#ifndef PROFILE_H
#define PROFILE_H

#define MPI_ROUTINES 396

void PROFILE_INIT(int);
void PROFILE_START(int);
void PROFILE_STOP(int);
void PROFILE_FINISH();

#include "chrono.cpp"
typedef struct {
    hrc entry_time;
    double total_time;
    long int count;
    int flag; // if flag then print elapsed time.
} mpi_performance;

#endif