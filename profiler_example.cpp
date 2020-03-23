#include "mpi.h"
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

#define SIZE 4

#include <chrono>

using namespace std::chrono;

typedef high_resolution_clock::time_point hrc_time;

double elasped_time(hrc_time t1, hrc_time t2) {
    return duration_cast<microseconds >(t2 - t1).count();
}

hrc_time start, cur;
double total_time = 0;
int MPI_Scatter(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                void *recvbuf, int recvcount, MPI_Datatype recvtype,
                int root, MPI_Comm comm) {
    int   returnVal;
    start = high_resolution_clock::now();
    returnVal = PMPI_Scatter( sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm );

    cur = high_resolution_clock::now();
    total_time += elasped_time(start, cur);
    return returnVal;
}

int main(int argc, char *argv[]) {
    int numtasks, rank, sendcount, recvcount, source;
    float sendbuf[SIZE][SIZE] = {
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0,  10.0, 11.0, 12.0},
            {13.0, 14.0, 15.0, 16.0}};
    float recvbuf[SIZE];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    if (rank == 0) {
        total_time = 0.0;
    }
    if (numtasks == SIZE) {
        // define source task and elements to send/receive, then perform collective scatter
        source = 1;
        sendcount = SIZE;
        recvcount = SIZE;
//        printf("task %d, sendcount %d, recvcount %d\n", rank, sendcount, recvcount);
        MPI_Scatter(sendbuf, sendcount, MPI_FLOAT, recvbuf, recvcount,
                    MPI_FLOAT, source, MPI_COMM_WORLD);

        printf("rank= %d  Results: %f %f %f %f\n", rank, recvbuf[0],
               recvbuf[1], recvbuf[2], recvbuf[3]);
    } else
        printf("Must specify %d processors. Terminating.\n", SIZE);

    MPI_Finalize();
    if (rank == 0) cout << total_time << '\n';
//    if (rank == 0)
//    cout << rank << " " << total_time << '\n';
    return 0;
}
