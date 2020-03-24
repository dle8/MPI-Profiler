#include <bits/stdc++.h>

#include "profile.h"
#include "timer.h"
#include "mpi_routine.h"

static mpi_performance mpi_profile[MPI_ROUTINES];
double used_time = 0.0, comm_time = 0.0, comp_time = 0.0, t_elapsed_time = 0.0;
int proc_id = 0, profile_on = 1;
FILE *profile_file;
int threshold;

void sort_mpi(mpi_performance **_mpi_sort);

void sort_mpi(mpi_performance **_mpi_sort) {
    std::sort(_mpi_sort, _mpi_sort + MPI_ROUTINES, [](const mpi_performance *mp1, mpi_performance *mp2) {
        return mp1->total_time < mp2->total_time;
    });
}

void PROFILE_INIT(int process_id) {
    char profile_name[64];
    for (int i = 0; i < MPI_ROUTINES; ++i) timer_clear(i);
    timer_clear(0);
    for (int i = 0; i < MPI_ROUTINES; ++i) {
        mpi_profile[i].total_time = 0.0;
        mpi_profile[i].count = 0.0;
    }
    proc_id = process_id;
    sprintf(profile_name, "mpi_record.%d", proc_id);
    profile_file = fopen(profile_name, "w");
    if (profile_file == NULL) {
        printf("Open file failed");
        exit(0);
    }
}

void PROFILE_ON() {
    profile_on = 1;
}

void PROFILE_OFF() {
    profile_on = 0;
}

void PROFILE_START(int mpi_id) {
    if (profile_on) mpi_profile[mpi_id].entry_time = chrono_timer::current_time();
}

void PROFILE_STOP(int mpi_id) {
    if (profile_on) {
        used_time += chrono_timer::elapsed_time(mpi_profile[mpi_id].entry_time, chrono_timer::current_time());
        mpi_profile[mpi_id].total_time += used_time;
        mpi_profile[mpi_id].count++;
        if (mpi_profile[mpi_id].flag && threshold) {
            fprintf(profile_file, "%d\t%.2f\n", mpi_id, used_time);
            threshold--;
        }
    }
}

void PROFILE_FINISH() {
    timer_stop(0);
    t_elapsed_time = timer_read(0); // MPI time + CPU time
    for (int i = 0; i < MPI_ROUTINES; ++i) comm_time += mpi_profile[i].total_time;
    comp_time = t_elapsed_time - comm_time;

    fprintf(profile_file, "Rank: %d, Total time: %.2lf sec.\n", proc_id, t_elapsed_time);
    fprintf(
            profile_file,
            "MPI time: %.2lf (%4.2lf%%), CPU time: %.2lf (%4.2lf%%)\n",
            comm_time,
            100.0 * comm_time / t_elapsed_time,
            comp_time,
            100.0 * (1 - comm_time / t_elapsed_time)
    );
    fprintf(profile_file, "Caution: MPI_Init and MPI_Finalize are not included.\n");

    fprintf(profile_file, "%25s%12s%10s\n", "--------Function--------", "--Time(ms)--", "--Count--");

    mpi_performance *mpi_sort[MPI_ROUTINES];
    for (int i = 0; i < MPI_ROUTINES; ++i) mpi_sort[i] = &mpi_profile[i];

    sort_mpi(mpi_sort);

    for (int i = 0; i < MPI_ROUTINES; ++i) {
        if (mpi_sort[i]->count != 0) {
            int j = mpi_sort[i] - &mpi_profile[0];
            fprintf(profile_file, "%25s%12.2lf%10lld\n", MPI_Routines[j], mpi_sort[i]->total_time, mpi_sort[i]->count);
        }
    }
    fclose(profile_file);
}
