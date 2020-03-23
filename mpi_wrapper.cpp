/********************************************************************
*                                                                   *
* This library can be used to acquire communication and computation *
* profile for a given MPI program. Written by Jidong Zhai.          *
* July.12.2012. Contact: zhaijidong@gmail.com                       *
*                                                                   *
********************************************************************/

#include <mpi.h>
#include "profile.h"

/******************************************************************
*                                                                 *
*                   MPI Functions for Management                  *
*                                                                 *
******************************************************************/

int MPI_Init(int *argc, char ***argv) {
    int returnVal;
    int proc_id;
    int size;
    char procname[MPI_MAX_PROCESSOR_NAME];
    int procnamelength;

#ifdef PERF_PROFILE
    //PROFILE_START(0);
#endif

#ifdef DEBUG
    printf("Enter MPI_Init\n");
#endif

    returnVal = PMPI_Init(argc, argv);

#ifdef PERF_PROFILE
    PMPI_Comm_rank( MPI_COMM_WORLD, &proc_id );
    PROFILE_INIT(proc_id);
    //PROFILE_STOP(0);
#endif

    return returnVal;
}

#ifdef PERF_MPI_THREADED
int  MPI_Init_thread (int * argc, char *** argv, int required, int *provided ) {
  int  returnVal;

#ifdef PERF_PROFILE
  PROFILE_START(1);
#endif

#ifdef DEBUG
  printf("Enter MPI_Init_thread\n");
#endif

  returnVal = PMPI_Init_thread( argc, argv, required, provided );

#ifdef PERF_PROFILE
  PROFILE_STOP(1);
#endif

  return returnVal;
}

#endif /* PERF_MPI_THREADED */


int MPI_Finalize() {
    int returnVal;
    int size;
    char procname[MPI_MAX_PROCESSOR_NAME];
    int procnamelength;

#ifdef PERF_PROFILE
    PROFILE_FINISH();
#endif

#ifdef DEBUG
    printf("Enter MPI_Finalize\n");
#endif

    returnVal = PMPI_Finalize();
    return returnVal;
}


int MPI_Abort(MPI_Comm comm, int errorcode) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(15);
#endif

#ifdef DEBUG
    printf("Enter MPI_Abort\n");
#endif

    returnVal = PMPI_Abort(comm, errorcode);

#ifdef PERF_PROFILE
    PROFILE_STOP(15);
#endif

    return returnVal;
}

int MPI_Accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank,
                   MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(18);
#endif

#ifdef DEBUG
    printf("Enter MPI_Accumulate\n");
#endif

    returnVal = PMPI_Accumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count,
                                target_datatype, op, win);

#ifdef PERF_PROFILE
    PROFILE_STOP(18);
#endif

    return returnVal;
}


int MPI_Add_error_class(int *errorclass) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(21);
#endif

#ifdef DEBUG
    printf("Enter MPI_Add_error_class\n");
#endif

    returnVal = PMPI_Add_error_class(errorclass);

#ifdef PERF_PROFILE
    PROFILE_STOP(21);
#endif

    return returnVal;
}


int MPI_Add_error_code(int errorclass, int *errorcode) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(24);
#endif

#ifdef DEBUG
    printf("Enter MPI_Add_error_code\n");
#endif

    returnVal = PMPI_Add_error_code(errorclass, errorcode);

#ifdef PERF_PROFILE
    PROFILE_STOP(24);
#endif

    return returnVal;
}


int MPI_Add_error_string(int errorcode, const char *string) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(27);
#endif

#ifdef DEBUG
    printf("Enter MPI_Add_error_string\n");
#endif

    returnVal = PMPI_Add_error_string(errorcode, string);

#ifdef PERF_PROFILE
    PROFILE_STOP(27);
#endif

    return returnVal;
}


int MPI_Allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount,
                  MPI_Datatype recvtype, MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(39);
#endif

#ifdef DEBUG
    printf("Enter MPI_Allgather\n");
#endif

    returnVal = PMPI_Allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(39);
#endif

    return returnVal;
}


int MPI_Iallgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount,
                   MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(154);
#endif

#ifdef DEBUG
    printf("Enter MPI_Iallgather\n");
#endif

    returnVal = PMPI_Iallgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(154);
#endif

    return returnVal;
}


int MPI_Allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[],
                   const int displs[], MPI_Datatype recvtype, MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(42);
#endif

#ifdef DEBUG
    printf("Enter MPI_Allgatherv\n");
#endif

    returnVal = PMPI_Allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(42);
#endif

    return returnVal;
}


int MPI_Iallgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[],
                    const int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(157);
#endif

#ifdef DEBUG
    printf("Enter MPI_Iallgatherv\n");
#endif

    returnVal = PMPI_Iallgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(157);
#endif

    return returnVal;
}


int MPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(45);
#endif

#ifdef DEBUG
    printf("Enter MPI_Alloc_mem\n");
#endif

    returnVal = PMPI_Alloc_mem(size, info, baseptr);

#ifdef PERF_PROFILE
    PROFILE_STOP(45);
#endif

    return returnVal;
}


int MPI_Allreduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(48);
#endif

#ifdef DEBUG
    printf("Enter MPI_Allreduce\n");
#endif

    returnVal = PMPI_Allreduce(sendbuf, recvbuf, count, datatype, op, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(48);
#endif

    return returnVal;
}


int MPI_Iallreduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                   MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(160);
#endif

#ifdef DEBUG
    printf("Enter MPI_Iallreduce\n");
#endif

    returnVal = PMPI_Iallreduce(sendbuf, recvbuf, count, datatype, op, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(160);
#endif

    return returnVal;
}


int MPI_Alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount,
                 MPI_Datatype recvtype, MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(51);
#endif

#ifdef DEBUG
    printf("Enter MPI_Alltoall\n");
#endif

    returnVal = PMPI_Alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(51);
#endif

    return returnVal;
}


int MPI_Ialltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount,
                  MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(163);
#endif

#ifdef DEBUG
    printf("Enter MPI_Ialltoall\n");
#endif

    returnVal = PMPI_Ialltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(163);
#endif

    return returnVal;
}


int
MPI_Alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf,
              const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(54);
#endif

#ifdef DEBUG
    printf("Enter MPI_Alltoallv\n");
#endif

    returnVal = PMPI_Alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(54);
#endif

    return returnVal;
}


int
MPI_Ialltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf,
               const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm,
               MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(166);
#endif

#ifdef DEBUG
    printf("Enter MPI_Ialltoallv\n");
#endif

    returnVal = PMPI_Ialltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm,
                                request);

#ifdef PERF_PROFILE
    PROFILE_STOP(166);
#endif

    return returnVal;
}


int MPI_Alltoallw(const void *sendbuf, const int sendcounts[], const int sdispls[], const MPI_Datatype sendtypes[],
                  void *recvbuf, const int recvcounts[], const int rdispls[], const MPI_Datatype recvtypes[],
                  MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(57);
#endif

#ifdef DEBUG
    printf("Enter MPI_Alltoallw\n");
#endif

    returnVal = PMPI_Alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(57);
#endif

    return returnVal;
}


int MPI_Ialltoallw(const void *sendbuf, const int sendcounts[], const int sdispls[], const MPI_Datatype sendtypes[],
                   void *recvbuf, const int recvcounts[], const int rdispls[], const MPI_Datatype recvtypes[],
                   MPI_Comm comm, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(169);
#endif

#ifdef DEBUG
    printf("Enter MPI_Ialltoallw\n");
#endif

    returnVal = PMPI_Ialltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm,
                                request);

#ifdef PERF_PROFILE
    PROFILE_STOP(169);
#endif

    return returnVal;
}


int MPI_Barrier(MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(69);
#endif

#ifdef DEBUG
    printf("Enter MPI_Barrier\n");
#endif

    returnVal = PMPI_Barrier(comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(69);
#endif

    return returnVal;
}


int MPI_Ibarrier(MPI_Comm comm, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(172);
#endif

#ifdef DEBUG
    printf("Enter MPI_Ibarrier\n");
#endif

    returnVal = PMPI_Ibarrier(comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(172);
#endif

    return returnVal;
}


int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(72);
#endif

#ifdef DEBUG
    printf("Enter MPI_Bcast\n");
#endif

    returnVal = PMPI_Bcast(buffer, count, datatype, root, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(72);
#endif

    return returnVal;
}


int MPI_Bsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(75);
#endif

#ifdef DEBUG
    printf("Enter MPI_Bsend\n");
#endif

    returnVal = PMPI_Bsend(buf, count, datatype, dest, tag, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(75);
#endif

    return returnVal;
}


int MPI_Ibcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(175);
#endif

#ifdef DEBUG
    printf("Enter MPI_Ibcast\n");
#endif

    returnVal = PMPI_Ibcast(buffer, count, datatype, root, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(175);
#endif

    return returnVal;
}


int MPI_Bsend_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm,
                   MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(78);
#endif

#ifdef DEBUG
    printf("Enter MPI_Bsend_init\n");
#endif

    returnVal = PMPI_Bsend_init(buf, count, datatype, dest, tag, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(78);
#endif

    return returnVal;
}


int MPI_Buffer_attach(void *buffer, int size) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(81);
#endif

#ifdef DEBUG
    printf("Enter MPI_Buffer_attach\n");
#endif

    returnVal = PMPI_Buffer_attach(buffer, size);

#ifdef PERF_PROFILE
    PROFILE_STOP(81);
#endif

    return returnVal;
}


int MPI_Buffer_detach(void *buffer, int *size) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(84);
#endif

#ifdef DEBUG
    printf("Enter MPI_Buffer_detach\n");
#endif

    returnVal = PMPI_Buffer_detach(buffer, size);

#ifdef PERF_PROFILE
    PROFILE_STOP(84);
#endif

    return returnVal;
}


int MPI_Cancel(MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(87);
#endif

#ifdef DEBUG
    printf("Enter MPI_Cancel\n");
#endif

    returnVal = PMPI_Cancel(request);

#ifdef PERF_PROFILE
    PROFILE_STOP(87);
#endif

    return returnVal;
}


int MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims, int coords[]) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(90);
#endif

#ifdef DEBUG
    printf("Enter MPI_Cart_coords\n");
#endif

    returnVal = PMPI_Cart_coords(comm, rank, maxdims, coords);

#ifdef PERF_PROFILE
    PROFILE_STOP(90);
#endif

    return returnVal;
}


int
MPI_Cart_create(MPI_Comm old_comm, int ndims, const int dims[], const int periods[], int reorder, MPI_Comm *comm_cart) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(93);
#endif

#ifdef DEBUG
    printf("Enter MPI_Cart_create\n");
#endif

    returnVal = PMPI_Cart_create(old_comm, ndims, dims, periods, reorder, comm_cart);

#ifdef PERF_PROFILE
    PROFILE_STOP(93);
#endif

    return returnVal;
}


int MPI_Cart_get(MPI_Comm comm, int maxdims, int dims[], int periods[], int coords[]) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(96);
#endif

#ifdef DEBUG
    printf("Enter MPI_Cart_get\n");
#endif

    returnVal = PMPI_Cart_get(comm, maxdims, dims, periods, coords);

#ifdef PERF_PROFILE
    PROFILE_STOP(96);
#endif

    return returnVal;
}


int MPI_Cart_map(MPI_Comm comm, int ndims, const int dims[], const int periods[], int *newrank) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(99);
#endif

#ifdef DEBUG
    printf("Enter MPI_Cart_map\n");
#endif

    returnVal = PMPI_Cart_map(comm, ndims, dims, periods, newrank);

#ifdef PERF_PROFILE
    PROFILE_STOP(99);
#endif

    return returnVal;
}


int MPI_Cart_rank(MPI_Comm comm, const int coords[], int *rank) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(102);
#endif

#ifdef DEBUG
    printf("Enter MPI_Cart_rank\n");
#endif

    returnVal = PMPI_Cart_rank(comm, coords, rank);

#ifdef PERF_PROFILE
    PROFILE_STOP(102);
#endif

    return returnVal;
}


int MPI_Cart_shift(MPI_Comm comm, int direction, int disp, int *rank_source, int *rank_dest) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(105);
#endif

#ifdef DEBUG
    printf("Enter MPI_Cart_shift\n");
#endif

    returnVal = PMPI_Cart_shift(comm, direction, disp, rank_source, rank_dest);

#ifdef PERF_PROFILE
    PROFILE_STOP(105);
#endif

    return returnVal;
}


int MPI_Cart_sub(MPI_Comm comm, const int remain_dims[], MPI_Comm *new_comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(108);
#endif

#ifdef DEBUG
    printf("Enter MPI_Cart_sub\n");
#endif

    returnVal = PMPI_Cart_sub(comm, remain_dims, new_comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(108);
#endif

    return returnVal;
}


int MPI_Cartdim_get(MPI_Comm comm, int *ndims) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(111);
#endif

#ifdef DEBUG
    printf("Enter MPI_Cartdim_get\n");
#endif

    returnVal = PMPI_Cartdim_get(comm, ndims);

#ifdef PERF_PROFILE
    PROFILE_STOP(111);
#endif

    return returnVal;
}


int MPI_Close_port(const char *port_name) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(114);
#endif

#ifdef DEBUG
    printf("Enter MPI_Close_port\n");
#endif

    returnVal = PMPI_Close_port(port_name);

#ifdef PERF_PROFILE
    PROFILE_STOP(114);
#endif

    return returnVal;
}


int MPI_Comm_accept(const char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(117);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_accept\n");
#endif

    returnVal = PMPI_Comm_accept(port_name, info, root, comm, newcomm);

#ifdef PERF_PROFILE
    PROFILE_STOP(117);
#endif

    return returnVal;
}


int MPI_Comm_call_errhandler(MPI_Comm comm, int errorcode) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(120);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_call_errhandler\n");
#endif

    returnVal = PMPI_Comm_call_errhandler(comm, errorcode);

#ifdef PERF_PROFILE
    PROFILE_STOP(120);
#endif

    return returnVal;
}


int MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(123);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_compare\n");
#endif

    returnVal = PMPI_Comm_compare(comm1, comm2, result);

#ifdef PERF_PROFILE
    PROFILE_STOP(123);
#endif

    return returnVal;
}


int MPI_Comm_connect(const char *port_name, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *newcomm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(126);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_connect\n");
#endif

    returnVal = PMPI_Comm_connect(port_name, info, root, comm, newcomm);

#ifdef PERF_PROFILE
    PROFILE_STOP(126);
#endif

    return returnVal;
}


int MPI_Comm_create_errhandler(MPI_Comm_errhandler_function *function, MPI_Errhandler *errhandler) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(132);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_create_errhandler\n");
#endif

    returnVal = PMPI_Comm_create_errhandler(function, errhandler);

#ifdef PERF_PROFILE
    PROFILE_STOP(132);
#endif

    return returnVal;
}


int MPI_Comm_create_keyval(MPI_Comm_copy_attr_function *comm_copy_attr_fn,
                           MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval, void *extra_state) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(138);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_create_keyval\n");
#endif

    returnVal = PMPI_Comm_create_keyval(comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state);

#ifdef PERF_PROFILE
    PROFILE_STOP(138);
#endif

    return returnVal;
}


int MPI_Comm_create_group(MPI_Comm comm, MPI_Group group, int tag, MPI_Comm *newcomm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(135);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_create_group\n");
#endif

    returnVal = PMPI_Comm_create_group(comm, group, tag, newcomm);

#ifdef PERF_PROFILE
    PROFILE_STOP(135);
#endif

    return returnVal;
}


int MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(129);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_create\n");
#endif

    returnVal = PMPI_Comm_create(comm, group, newcomm);

#ifdef PERF_PROFILE
    PROFILE_STOP(129);
#endif

    return returnVal;
}


int MPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(141);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_delete_attr\n");
#endif

    returnVal = PMPI_Comm_delete_attr(comm, comm_keyval);

#ifdef PERF_PROFILE
    PROFILE_STOP(141);
#endif

    return returnVal;
}


int MPI_Comm_disconnect(MPI_Comm *comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(144);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_disconnect\n");
#endif

    returnVal = PMPI_Comm_disconnect(comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(144);
#endif

    return returnVal;
}


int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(147);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_dup\n");
#endif

    returnVal = PMPI_Comm_dup(comm, newcomm);

#ifdef PERF_PROFILE
    PROFILE_STOP(147);
#endif

    return returnVal;
}


int MPI_Comm_idup(MPI_Comm comm, MPI_Comm *newcomm, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(177);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_idup\n");
#endif

    returnVal = PMPI_Comm_idup(comm, newcomm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(177);
#endif

    return returnVal;
}


int MPI_Comm_dup_with_info(MPI_Comm comm, MPI_Info info, MPI_Comm *newcomm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(150);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_dup_with_info\n");
#endif

    returnVal = PMPI_Comm_dup_with_info(comm, info, newcomm);

#ifdef PERF_PROFILE
    PROFILE_STOP(150);
#endif

    return returnVal;
}


int MPI_Comm_free_keyval(int *comm_keyval) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(156);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_free_keyval\n");
#endif

    returnVal = PMPI_Comm_free_keyval(comm_keyval);

#ifdef PERF_PROFILE
    PROFILE_STOP(156);
#endif

    return returnVal;
}


int MPI_Comm_free(MPI_Comm *comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(153);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_free\n");
#endif

    returnVal = PMPI_Comm_free(comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(153);
#endif

    return returnVal;
}


int MPI_Comm_get_attr(MPI_Comm comm, int comm_keyval, void *attribute_val, int *flag) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(159);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_get_attr\n");
#endif

    returnVal = PMPI_Comm_get_attr(comm, comm_keyval, attribute_val, flag);

#ifdef PERF_PROFILE
    PROFILE_STOP(159);
#endif

    return returnVal;
}


int MPI_Dist_graph_create(MPI_Comm comm_old, int n, const int nodes[], const int degrees[], const int targets[],
                          const int weights[], MPI_Info info, int reorder, MPI_Comm *newcomm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(228);
#endif

#ifdef DEBUG
    printf("Enter MPI_Dist_graph_create\n");
#endif

    returnVal = PMPI_Dist_graph_create(comm_old, n, nodes, degrees, targets, weights, info, reorder, newcomm);

#ifdef PERF_PROFILE
    PROFILE_STOP(228);
#endif

    return returnVal;
}


int MPI_Dist_graph_create_adjacent(MPI_Comm comm_old, int indegree, const int sources[], const int sourceweights[],
                                   int outdegree, const int destinations[], const int destweights[], MPI_Info info,
                                   int reorder, MPI_Comm *comm_dist_graph) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(231);
#endif

#ifdef DEBUG
    printf("Enter MPI_Dist_graph_create_adjacent\n");
#endif

    returnVal = PMPI_Dist_graph_create_adjacent(comm_old, indegree, sources, sourceweights, outdegree, destinations,
                                                destweights, info, reorder, comm_dist_graph);

#ifdef PERF_PROFILE
    PROFILE_STOP(231);
#endif

    return returnVal;
}


int MPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree, int sources[], int sourceweights[], int maxoutdegree,
                             int destinations[], int destweights[]) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(234);
#endif

#ifdef DEBUG
    printf("Enter MPI_Dist_graph_neighbors\n");
#endif

    returnVal = PMPI_Dist_graph_neighbors(comm, maxindegree, sources, sourceweights, maxoutdegree, destinations,
                                          destweights);

#ifdef PERF_PROFILE
    PROFILE_STOP(234);
#endif

    return returnVal;
}


int MPI_Dist_graph_neighbors_count(MPI_Comm comm, int *inneighbors, int *outneighbors, int *weighted) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(237);
#endif

#ifdef DEBUG
    printf("Enter MPI_Dist_graph_neighbors_count\n");
#endif

    returnVal = PMPI_Dist_graph_neighbors_count(comm, inneighbors, outneighbors, weighted);

#ifdef PERF_PROFILE
    PROFILE_STOP(237);
#endif

    return returnVal;
}


int MPI_Comm_get_errhandler(MPI_Comm comm, MPI_Errhandler *erhandler) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(162);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_get_errhandler\n");
#endif

    returnVal = PMPI_Comm_get_errhandler(comm, erhandler);

#ifdef PERF_PROFILE
    PROFILE_STOP(162);
#endif

    return returnVal;
}


int MPI_Comm_get_info(MPI_Comm comm, MPI_Info *info_used) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(165);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_get_info\n");
#endif

    returnVal = PMPI_Comm_get_info(comm, info_used);

#ifdef PERF_PROFILE
    PROFILE_STOP(165);
#endif

    return returnVal;
}


int MPI_Comm_get_name(MPI_Comm comm, char *comm_name, int *resultlen) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(168);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_get_name\n");
#endif

    returnVal = PMPI_Comm_get_name(comm, comm_name, resultlen);

#ifdef PERF_PROFILE
    PROFILE_STOP(168);
#endif

    return returnVal;
}


int MPI_Comm_get_parent(MPI_Comm *parent) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(171);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_get_parent\n");
#endif

    returnVal = PMPI_Comm_get_parent(parent);

#ifdef PERF_PROFILE
    PROFILE_STOP(171);
#endif

    return returnVal;
}


int MPI_Comm_group(MPI_Comm comm, MPI_Group *group) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(174);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_group\n");
#endif

    returnVal = PMPI_Comm_group(comm, group);

#ifdef PERF_PROFILE
    PROFILE_STOP(174);
#endif

    return returnVal;
}


int MPI_Comm_join(int fd, MPI_Comm *intercomm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(180);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_join\n");
#endif

    returnVal = PMPI_Comm_join(fd, intercomm);

#ifdef PERF_PROFILE
    PROFILE_STOP(180);
#endif

    return returnVal;
}


int MPI_Comm_rank(MPI_Comm comm, int *rank) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(183);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_rank\n");
#endif

    returnVal = PMPI_Comm_rank(comm, rank);

#ifdef PERF_PROFILE
    PROFILE_STOP(183);
#endif

    return returnVal;
}


int MPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(186);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_remote_group\n");
#endif

    returnVal = PMPI_Comm_remote_group(comm, group);

#ifdef PERF_PROFILE
    PROFILE_STOP(186);
#endif

    return returnVal;
}


int MPI_Comm_remote_size(MPI_Comm comm, int *size) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(189);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_remote_size\n");
#endif

    returnVal = PMPI_Comm_remote_size(comm, size);

#ifdef PERF_PROFILE
    PROFILE_STOP(189);
#endif

    return returnVal;
}


int MPI_Comm_set_attr(MPI_Comm comm, int comm_keyval, void *attribute_val) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(192);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_set_attr\n");
#endif

    returnVal = PMPI_Comm_set_attr(comm, comm_keyval, attribute_val);

#ifdef PERF_PROFILE
    PROFILE_STOP(192);
#endif

    return returnVal;
}


int MPI_Comm_set_errhandler(MPI_Comm comm, MPI_Errhandler errhandler) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(195);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_set_errhandler\n");
#endif

    returnVal = PMPI_Comm_set_errhandler(comm, errhandler);

#ifdef PERF_PROFILE
    PROFILE_STOP(195);
#endif

    return returnVal;
}


int MPI_Comm_set_info(MPI_Comm comm, MPI_Info info) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(198);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_set_info\n");
#endif

    returnVal = PMPI_Comm_set_info(comm, info);

#ifdef PERF_PROFILE
    PROFILE_STOP(198);
#endif

    return returnVal;
}


int MPI_Comm_set_name(MPI_Comm comm, const char *comm_name) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(201);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_set_name\n");
#endif

    returnVal = PMPI_Comm_set_name(comm, comm_name);

#ifdef PERF_PROFILE
    PROFILE_STOP(201);
#endif

    return returnVal;
}


int MPI_Comm_size(MPI_Comm comm, int *size) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(204);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_size\n");
#endif

    returnVal = PMPI_Comm_size(comm, size);

#ifdef PERF_PROFILE
    PROFILE_STOP(204);
#endif

    return returnVal;
}


int MPI_Comm_spawn(const char *command, char *argv[], int maxprocs, MPI_Info info, int root, MPI_Comm comm,
                   MPI_Comm *intercomm, int array_of_errcodes[]) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(207);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_spawn\n");
#endif

    returnVal = PMPI_Comm_spawn(command, argv, maxprocs, info, root, comm, intercomm, array_of_errcodes);

#ifdef PERF_PROFILE
    PROFILE_STOP(207);
#endif

    return returnVal;
}


int MPI_Comm_spawn_multiple(int count, char *array_of_commands[], char **array_of_argv[], const int array_of_maxprocs[],
                            const MPI_Info array_of_info[], int root, MPI_Comm comm, MPI_Comm *intercomm,
                            int array_of_errcodes[]) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(210);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_spawn_multiple\n");
#endif

    returnVal = PMPI_Comm_spawn_multiple(count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info,
                                         root, comm, intercomm, array_of_errcodes);

#ifdef PERF_PROFILE
    PROFILE_STOP(210);
#endif

    return returnVal;
}


int MPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *newcomm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(213);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_split\n");
#endif

    returnVal = PMPI_Comm_split(comm, color, key, newcomm);

#ifdef PERF_PROFILE
    PROFILE_STOP(213);
#endif

    return returnVal;
}


int MPI_Comm_split_type(MPI_Comm comm, int split_type, int key, MPI_Info info, MPI_Comm *newcomm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(216);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_split_type\n");
#endif

    returnVal = PMPI_Comm_split_type(comm, split_type, key, info, newcomm);

#ifdef PERF_PROFILE
    PROFILE_STOP(216);
#endif

    return returnVal;
}


int MPI_Comm_test_inter(MPI_Comm comm, int *flag) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(219);
#endif

#ifdef DEBUG
    printf("Enter MPI_Comm_test_inter\n");
#endif

    returnVal = PMPI_Comm_test_inter(comm, flag);

#ifdef PERF_PROFILE
    PROFILE_STOP(219);
#endif

    return returnVal;
}


int MPI_Compare_and_swap(const void *origin_addr, const void *compare_addr, void *result_addr, MPI_Datatype datatype,
                         int target_rank, MPI_Aint target_disp, MPI_Win win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(222);
#endif

#ifdef DEBUG
    printf("Enter MPI_Compare_and_swap\n");
#endif

    returnVal = PMPI_Compare_and_swap(origin_addr, compare_addr, result_addr, datatype, target_rank, target_disp, win);

#ifdef PERF_PROFILE
    PROFILE_STOP(222);
#endif

    return returnVal;
}


int MPI_Dims_create(int nnodes, int ndims, int dims[]) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(225);
#endif

#ifdef DEBUG
    printf("Enter MPI_Dims_create\n");
#endif

    returnVal = PMPI_Dims_create(nnodes, ndims, dims);

#ifdef PERF_PROFILE
    PROFILE_STOP(225);
#endif

    return returnVal;
}


int MPI_Errhandler_free(MPI_Errhandler *errhandler) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(243);
#endif

#ifdef DEBUG
    printf("Enter MPI_Errhandler_free\n");
#endif

    returnVal = PMPI_Errhandler_free(errhandler);

#ifdef PERF_PROFILE
    PROFILE_STOP(243);
#endif

    return returnVal;
}


int MPI_Error_class(int errorcode, int *errorclass) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(252);
#endif

#ifdef DEBUG
    printf("Enter MPI_Error_class\n");
#endif

    returnVal = PMPI_Error_class(errorcode, errorclass);

#ifdef PERF_PROFILE
    PROFILE_STOP(252);
#endif

    return returnVal;
}


int MPI_Error_string(int errorcode, char *string, int *resultlen) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(255);
#endif

#ifdef DEBUG
    printf("Enter MPI_Error_string\n");
#endif

    returnVal = PMPI_Error_string(errorcode, string, resultlen);

#ifdef PERF_PROFILE
    PROFILE_STOP(255);
#endif

    return returnVal;
}


int MPI_Exscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(258);
#endif

#ifdef DEBUG
    printf("Enter MPI_Exscan\n");
#endif

    returnVal = PMPI_Exscan(sendbuf, recvbuf, count, datatype, op, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(258);
#endif

    return returnVal;
}


int MPI_Fetch_and_op(const void *origin_addr, void *result_addr, MPI_Datatype datatype, int target_rank,
                     MPI_Aint target_disp, MPI_Op op, MPI_Win win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(261);
#endif

#ifdef DEBUG
    printf("Enter MPI_Fetch_and_op\n");
#endif

    returnVal = PMPI_Fetch_and_op(origin_addr, result_addr, datatype, target_rank, target_disp, op, win);

#ifdef PERF_PROFILE
    PROFILE_STOP(261);
#endif

    return returnVal;
}


int MPI_Iexscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(181);
#endif

#ifdef DEBUG
    printf("Enter MPI_Iexscan\n");
#endif

    returnVal = PMPI_Iexscan(sendbuf, recvbuf, count, datatype, op, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(181);
#endif

    return returnVal;
}


MPI_Fint MPI_File_c2f(MPI_File file) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(264);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_c2f\n");
#endif

    returnVal = PMPI_File_c2f(file);

#ifdef PERF_PROFILE
    PROFILE_STOP(264);
#endif

    return returnVal;
}

int MPI_File_call_errhandler(MPI_File fh, int errorcode) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(267);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_call_errhandler\n");
#endif

    returnVal = PMPI_File_call_errhandler(fh, errorcode);

#ifdef PERF_PROFILE
    PROFILE_STOP(267);
#endif

    return returnVal;
}


int MPI_File_create_errhandler(MPI_File_errhandler_function *function, MPI_Errhandler *errhandler) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(273);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_create_errhandler\n");
#endif

    returnVal = PMPI_File_create_errhandler(function, errhandler);

#ifdef PERF_PROFILE
    PROFILE_STOP(273);
#endif

    return returnVal;
}


int MPI_File_set_errhandler(MPI_File file, MPI_Errhandler errhandler) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(1);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_set_errhandler\n");
#endif

    returnVal = PMPI_File_set_errhandler(file, errhandler);

#ifdef PERF_PROFILE
    PROFILE_STOP(1);
#endif

    return returnVal;
}


int MPI_File_get_errhandler(MPI_File file, MPI_Errhandler *errhandler) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(291);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_get_errhandler\n");
#endif

    returnVal = PMPI_File_get_errhandler(file, errhandler);

#ifdef PERF_PROFILE
    PROFILE_STOP(291);
#endif

    return returnVal;
}


int MPI_File_open(MPI_Comm comm, const char *filename, int amode, MPI_Info info, MPI_File *fh) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(345);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_open\n");
#endif

    returnVal = PMPI_File_open(comm, filename, amode, info, fh);

#ifdef PERF_PROFILE
    PROFILE_STOP(345);
#endif

    return returnVal;
}


int MPI_File_close(MPI_File *fh) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(270);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_close\n");
#endif

    returnVal = PMPI_File_close(fh);

#ifdef PERF_PROFILE
    PROFILE_STOP(270);
#endif

    return returnVal;
}


int MPI_File_delete(const char *filename, MPI_Info info) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(276);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_delete\n");
#endif

    returnVal = PMPI_File_delete(filename, info);

#ifdef PERF_PROFILE
    PROFILE_STOP(276);
#endif

    return returnVal;
}


int MPI_File_set_size(MPI_File fh, MPI_Offset size) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(7);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_set_size\n");
#endif

    returnVal = PMPI_File_set_size(fh, size);

#ifdef PERF_PROFILE
    PROFILE_STOP(7);
#endif

    return returnVal;
}


int MPI_File_preallocate(MPI_File fh, MPI_Offset size) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(348);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_preallocate\n");
#endif

    returnVal = PMPI_File_preallocate(fh, size);

#ifdef PERF_PROFILE
    PROFILE_STOP(348);
#endif

    return returnVal;
}


int MPI_File_get_size(MPI_File fh, MPI_Offset *size) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(306);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_get_size\n");
#endif

    returnVal = PMPI_File_get_size(fh, size);

#ifdef PERF_PROFILE
    PROFILE_STOP(306);
#endif

    return returnVal;
}


int MPI_File_get_group(MPI_File fh, MPI_Group *group) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(294);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_get_group\n");
#endif

    returnVal = PMPI_File_get_group(fh, group);

#ifdef PERF_PROFILE
    PROFILE_STOP(294);
#endif

    return returnVal;
}


int MPI_File_get_amode(MPI_File fh, int *amode) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(282);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_get_amode\n");
#endif

    returnVal = PMPI_File_get_amode(fh, amode);

#ifdef PERF_PROFILE
    PROFILE_STOP(282);
#endif

    return returnVal;
}


int MPI_File_set_info(MPI_File fh, MPI_Info info) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(4);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_set_info\n");
#endif

    returnVal = PMPI_File_set_info(fh, info);

#ifdef PERF_PROFILE
    PROFILE_STOP(4);
#endif

    return returnVal;
}


int MPI_File_get_info(MPI_File fh, MPI_Info *info_used) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(297);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_get_info\n");
#endif

    returnVal = PMPI_File_get_info(fh, info_used);

#ifdef PERF_PROFILE
    PROFILE_STOP(297);
#endif

    return returnVal;
}


int MPI_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype, const char *datarep,
                      MPI_Info info) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(10);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_set_view\n");
#endif

    returnVal = PMPI_File_set_view(fh, disp, etype, filetype, datarep, info);

#ifdef PERF_PROFILE
    PROFILE_STOP(10);
#endif

    return returnVal;
}


int MPI_File_get_view(MPI_File fh, MPI_Offset *disp, MPI_Datatype *etype, MPI_Datatype *filetype, char *datarep) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(312);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_get_view\n");
#endif

    returnVal = PMPI_File_get_view(fh, disp, etype, filetype, datarep);

#ifdef PERF_PROFILE
    PROFILE_STOP(312);
#endif

    return returnVal;
}


int MPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(363);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_read_at\n");
#endif

    returnVal = PMPI_File_read_at(fh, offset, buf, count, datatype, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(363);
#endif

    return returnVal;
}


int
MPI_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(366);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_read_at_all\n");
#endif

    returnVal = PMPI_File_read_at_all(fh, offset, buf, count, datatype, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(366);
#endif

    return returnVal;
}


int MPI_File_write_at(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype,
                      MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(28);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_write_at\n");
#endif

    returnVal = PMPI_File_write_at(fh, offset, buf, count, datatype, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(28);
#endif

    return returnVal;
}


int MPI_File_write_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype,
                          MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(31);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_write_at_all\n");
#endif

    returnVal = PMPI_File_write_at_all(fh, offset, buf, count, datatype, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(31);
#endif

    return returnVal;
}


int
MPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(321);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_iread_at\n");
#endif

    returnVal = PMPI_File_iread_at(fh, offset, buf, count, datatype, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(321);
#endif

    return returnVal;
}


int MPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype,
                       MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(336);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_iwrite_at\n");
#endif

    returnVal = PMPI_File_iwrite_at(fh, offset, buf, count, datatype, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(336);
#endif

    return returnVal;
}


int MPI_File_iread_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype,
                          MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(324);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_iread_at_all\n");
#endif

    returnVal = PMPI_File_iread_at_all(fh, offset, buf, count, datatype, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(324);
#endif

    return returnVal;
}


int MPI_File_iwrite_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype,
                           MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(339);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_iwrite_at_all\n");
#endif

    returnVal = PMPI_File_iwrite_at_all(fh, offset, buf, count, datatype, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(339);
#endif

    return returnVal;
}


int MPI_File_read(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(351);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_read\n");
#endif

    returnVal = PMPI_File_read(fh, buf, count, datatype, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(351);
#endif

    return returnVal;
}


int MPI_File_read_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(354);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_read_all\n");
#endif

    returnVal = PMPI_File_read_all(fh, buf, count, datatype, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(354);
#endif

    return returnVal;
}


int MPI_File_write(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(16);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_write\n");
#endif

    returnVal = PMPI_File_write(fh, buf, count, datatype, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(16);
#endif

    return returnVal;
}


int MPI_File_write_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(19);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_write_all\n");
#endif

    returnVal = PMPI_File_write_all(fh, buf, count, datatype, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(19);
#endif

    return returnVal;
}


int MPI_File_iread(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(315);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_iread\n");
#endif

    returnVal = PMPI_File_iread(fh, buf, count, datatype, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(315);
#endif

    return returnVal;
}


int MPI_File_iwrite(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(330);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_iwrite\n");
#endif

    returnVal = PMPI_File_iwrite(fh, buf, count, datatype, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(330);
#endif

    return returnVal;
}


int MPI_File_iread_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(318);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_iread_all\n");
#endif

    returnVal = PMPI_File_iread_all(fh, buf, count, datatype, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(318);
#endif

    return returnVal;
}


int MPI_File_iwrite_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(333);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_iwrite_all\n");
#endif

    returnVal = PMPI_File_iwrite_all(fh, buf, count, datatype, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(333);
#endif

    return returnVal;
}


int MPI_File_seek(MPI_File fh, MPI_Offset offset, int whence) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(387);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_seek\n");
#endif

    returnVal = PMPI_File_seek(fh, offset, whence);

#ifdef PERF_PROFILE
    PROFILE_STOP(387);
#endif

    return returnVal;
}


int MPI_File_get_position(MPI_File fh, MPI_Offset *offset) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(300);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_get_position\n");
#endif

    returnVal = PMPI_File_get_position(fh, offset);

#ifdef PERF_PROFILE
    PROFILE_STOP(300);
#endif

    return returnVal;
}


int MPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset, MPI_Offset *disp) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(288);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_get_byte_offset\n");
#endif

    returnVal = PMPI_File_get_byte_offset(fh, offset, disp);

#ifdef PERF_PROFILE
    PROFILE_STOP(288);
#endif

    return returnVal;
}


int MPI_File_read_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(384);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_read_shared\n");
#endif

    returnVal = PMPI_File_read_shared(fh, buf, count, datatype, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(384);
#endif

    return returnVal;
}


int MPI_File_write_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(49);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_write_shared\n");
#endif

    returnVal = PMPI_File_write_shared(fh, buf, count, datatype, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(49);
#endif

    return returnVal;
}


int MPI_File_iread_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(327);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_iread_shared\n");
#endif

    returnVal = PMPI_File_iread_shared(fh, buf, count, datatype, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(327);
#endif

    return returnVal;
}


int MPI_File_iwrite_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(342);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_iwrite_shared\n");
#endif

    returnVal = PMPI_File_iwrite_shared(fh, buf, count, datatype, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(342);
#endif

    return returnVal;
}


int MPI_File_read_ordered(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(375);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_read_ordered\n");
#endif

    returnVal = PMPI_File_read_ordered(fh, buf, count, datatype, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(375);
#endif

    return returnVal;
}


int MPI_File_write_ordered(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(40);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_write_ordered\n");
#endif

    returnVal = PMPI_File_write_ordered(fh, buf, count, datatype, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(40);
#endif

    return returnVal;
}


int MPI_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(390);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_seek_shared\n");
#endif

    returnVal = PMPI_File_seek_shared(fh, offset, whence);

#ifdef PERF_PROFILE
    PROFILE_STOP(390);
#endif

    return returnVal;
}


int MPI_File_get_position_shared(MPI_File fh, MPI_Offset *offset) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(303);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_get_position_shared\n");
#endif

    returnVal = PMPI_File_get_position_shared(fh, offset);

#ifdef PERF_PROFILE
    PROFILE_STOP(303);
#endif

    return returnVal;
}


int MPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(369);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_read_at_all_begin\n");
#endif

    returnVal = PMPI_File_read_at_all_begin(fh, offset, buf, count, datatype);

#ifdef PERF_PROFILE
    PROFILE_STOP(369);
#endif

    return returnVal;
}


int MPI_File_read_at_all_end(MPI_File fh, void *buf, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(372);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_read_at_all_end\n");
#endif

    returnVal = PMPI_File_read_at_all_end(fh, buf, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(372);
#endif

    return returnVal;
}


int MPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(34);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_write_at_all_begin\n");
#endif

    returnVal = PMPI_File_write_at_all_begin(fh, offset, buf, count, datatype);

#ifdef PERF_PROFILE
    PROFILE_STOP(34);
#endif

    return returnVal;
}


int MPI_File_write_at_all_end(MPI_File fh, const void *buf, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(37);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_write_at_all_end\n");
#endif

    returnVal = PMPI_File_write_at_all_end(fh, buf, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(37);
#endif

    return returnVal;
}


int MPI_File_read_all_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(357);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_read_all_begin\n");
#endif

    returnVal = PMPI_File_read_all_begin(fh, buf, count, datatype);

#ifdef PERF_PROFILE
    PROFILE_STOP(357);
#endif

    return returnVal;
}


int MPI_File_read_all_end(MPI_File fh, void *buf, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(360);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_read_all_end\n");
#endif

    returnVal = PMPI_File_read_all_end(fh, buf, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(360);
#endif

    return returnVal;
}


int MPI_File_write_all_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(22);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_write_all_begin\n");
#endif

    returnVal = PMPI_File_write_all_begin(fh, buf, count, datatype);

#ifdef PERF_PROFILE
    PROFILE_STOP(22);
#endif

    return returnVal;
}


int MPI_File_write_all_end(MPI_File fh, const void *buf, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(25);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_write_all_end\n");
#endif

    returnVal = PMPI_File_write_all_end(fh, buf, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(25);
#endif

    return returnVal;
}


int MPI_File_read_ordered_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(378);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_read_ordered_begin\n");
#endif

    returnVal = PMPI_File_read_ordered_begin(fh, buf, count, datatype);

#ifdef PERF_PROFILE
    PROFILE_STOP(378);
#endif

    return returnVal;
}


int MPI_File_read_ordered_end(MPI_File fh, void *buf, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(381);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_read_ordered_end\n");
#endif

    returnVal = PMPI_File_read_ordered_end(fh, buf, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(381);
#endif

    return returnVal;
}


int MPI_File_write_ordered_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(43);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_write_ordered_begin\n");
#endif

    returnVal = PMPI_File_write_ordered_begin(fh, buf, count, datatype);

#ifdef PERF_PROFILE
    PROFILE_STOP(43);
#endif

    return returnVal;
}


int MPI_File_write_ordered_end(MPI_File fh, const void *buf, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(46);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_write_ordered_end\n");
#endif

    returnVal = PMPI_File_write_ordered_end(fh, buf, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(46);
#endif

    return returnVal;
}


int MPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype, MPI_Aint *extent) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(309);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_get_type_extent\n");
#endif

    returnVal = PMPI_File_get_type_extent(fh, datatype, extent);

#ifdef PERF_PROFILE
    PROFILE_STOP(309);
#endif

    return returnVal;
}


int MPI_File_set_atomicity(MPI_File fh, int flag) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(393);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_set_atomicity\n");
#endif

    returnVal = PMPI_File_set_atomicity(fh, flag);

#ifdef PERF_PROFILE
    PROFILE_STOP(393);
#endif

    return returnVal;
}


int MPI_File_get_atomicity(MPI_File fh, int *flag) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(285);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_get_atomicity\n");
#endif

    returnVal = PMPI_File_get_atomicity(fh, flag);

#ifdef PERF_PROFILE
    PROFILE_STOP(285);
#endif

    return returnVal;
}


int MPI_File_sync(MPI_File fh) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(13);
#endif

#ifdef DEBUG
    printf("Enter MPI_File_sync\n");
#endif

    returnVal = PMPI_File_sync(fh);

#ifdef PERF_PROFILE
    PROFILE_STOP(13);
#endif

    return returnVal;
}


int MPI_Finalized(int *flag) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(55);
#endif

#ifdef DEBUG
    printf("Enter MPI_Finalized\n");
#endif

    returnVal = PMPI_Finalized(flag);

#ifdef PERF_PROFILE
    PROFILE_STOP(55);
#endif

    return returnVal;
}


int MPI_Free_mem(void *base) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(58);
#endif

#ifdef DEBUG
    printf("Enter MPI_Free_mem\n");
#endif

    returnVal = PMPI_Free_mem(base);

#ifdef PERF_PROFILE
    PROFILE_STOP(58);
#endif

    return returnVal;
}


int MPI_Gather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount,
               MPI_Datatype recvtype, int root, MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(61);
#endif

#ifdef DEBUG
    printf("Enter MPI_Gather\n");
#endif

    returnVal = PMPI_Gather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(61);
#endif

    return returnVal;
}


int MPI_Igather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount,
                MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(184);
#endif

#ifdef DEBUG
    printf("Enter MPI_Igather\n");
#endif

    returnVal = PMPI_Igather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(184);
#endif

    return returnVal;
}


int MPI_Gatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[],
                const int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(64);
#endif

#ifdef DEBUG
    printf("Enter MPI_Gatherv\n");
#endif

    returnVal = PMPI_Gatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(64);
#endif

    return returnVal;
}


int MPI_Igatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[],
                 const int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(187);
#endif

#ifdef DEBUG
    printf("Enter MPI_Igatherv\n");
#endif

    returnVal = PMPI_Igatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(187);
#endif

    return returnVal;
}


int MPI_Get_address(const void *location, MPI_Aint *address) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(73);
#endif

#ifdef DEBUG
    printf("Enter MPI_Get_address\n");
#endif

    returnVal = PMPI_Get_address(location, address);

#ifdef PERF_PROFILE
    PROFILE_STOP(73);
#endif

    return returnVal;
}


int MPI_Get_count(const MPI_Status *status, MPI_Datatype datatype, int *count) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(76);
#endif

#ifdef DEBUG
    printf("Enter MPI_Get_count\n");
#endif

    returnVal = PMPI_Get_count(status, datatype, count);

#ifdef PERF_PROFILE
    PROFILE_STOP(76);
#endif

    return returnVal;
}


int MPI_Get_elements(const MPI_Status *status, MPI_Datatype datatype, int *count) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(79);
#endif

#ifdef DEBUG
    printf("Enter MPI_Get_elements\n");
#endif

    returnVal = PMPI_Get_elements(status, datatype, count);

#ifdef PERF_PROFILE
    PROFILE_STOP(79);
#endif

    return returnVal;
}


int MPI_Get_elements_x(const MPI_Status *status, MPI_Datatype datatype, MPI_Count *count) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(82);
#endif

#ifdef DEBUG
    printf("Enter MPI_Get_elements_x\n");
#endif

    returnVal = PMPI_Get_elements_x(status, datatype, count);

#ifdef PERF_PROFILE
    PROFILE_STOP(82);
#endif

    return returnVal;
}


int MPI_Get(void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp,
            int target_count, MPI_Datatype target_datatype, MPI_Win win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(67);
#endif

#ifdef DEBUG
    printf("Enter MPI_Get\n");
#endif

    returnVal = PMPI_Get(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count,
                         target_datatype, win);

#ifdef PERF_PROFILE
    PROFILE_STOP(67);
#endif

    return returnVal;
}


int MPI_Get_accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, void *result_addr,
                       int result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp,
                       int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(70);
#endif

#ifdef DEBUG
    printf("Enter MPI_Get_accumulate\n");
#endif

    returnVal = PMPI_Get_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count,
                                    result_datatype, target_rank, target_disp, target_count, target_datatype, op, win);

#ifdef PERF_PROFILE
    PROFILE_STOP(70);
#endif

    return returnVal;
}


int MPI_Get_library_version(char *version, int *resultlen) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(85);
#endif

#ifdef DEBUG
    printf("Enter MPI_Get_library_version\n");
#endif

    returnVal = PMPI_Get_library_version(version, resultlen);

#ifdef PERF_PROFILE
    PROFILE_STOP(85);
#endif

    return returnVal;
}


int MPI_Get_processor_name(char *name, int *resultlen) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(88);
#endif

#ifdef DEBUG
    printf("Enter MPI_Get_processor_name\n");
#endif

    returnVal = PMPI_Get_processor_name(name, resultlen);

#ifdef PERF_PROFILE
    PROFILE_STOP(88);
#endif

    return returnVal;
}


int MPI_Get_version(int *version, int *subversion) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(91);
#endif

#ifdef DEBUG
    printf("Enter MPI_Get_version\n");
#endif

    returnVal = PMPI_Get_version(version, subversion);

#ifdef PERF_PROFILE
    PROFILE_STOP(91);
#endif

    return returnVal;
}


int MPI_Graph_create(MPI_Comm comm_old, int nnodes, const int index[], const int edges[], int reorder,
                     MPI_Comm *comm_graph) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(94);
#endif

#ifdef DEBUG
    printf("Enter MPI_Graph_create\n");
#endif

    returnVal = PMPI_Graph_create(comm_old, nnodes, index, edges, reorder, comm_graph);

#ifdef PERF_PROFILE
    PROFILE_STOP(94);
#endif

    return returnVal;
}


int MPI_Graph_get(MPI_Comm comm, int maxindex, int maxedges, int index[], int edges[]) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(97);
#endif

#ifdef DEBUG
    printf("Enter MPI_Graph_get\n");
#endif

    returnVal = PMPI_Graph_get(comm, maxindex, maxedges, index, edges);

#ifdef PERF_PROFILE
    PROFILE_STOP(97);
#endif

    return returnVal;
}


int MPI_Graph_map(MPI_Comm comm, int nnodes, const int index[], const int edges[], int *newrank) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(100);
#endif

#ifdef DEBUG
    printf("Enter MPI_Graph_map\n");
#endif

    returnVal = PMPI_Graph_map(comm, nnodes, index, edges, newrank);

#ifdef PERF_PROFILE
    PROFILE_STOP(100);
#endif

    return returnVal;
}


int MPI_Graph_neighbors_count(MPI_Comm comm, int rank, int *nneighbors) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(106);
#endif

#ifdef DEBUG
    printf("Enter MPI_Graph_neighbors_count\n");
#endif

    returnVal = PMPI_Graph_neighbors_count(comm, rank, nneighbors);

#ifdef PERF_PROFILE
    PROFILE_STOP(106);
#endif

    return returnVal;
}


int MPI_Graph_neighbors(MPI_Comm comm, int rank, int maxneighbors, int neighbors[]) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(103);
#endif

#ifdef DEBUG
    printf("Enter MPI_Graph_neighbors\n");
#endif

    returnVal = PMPI_Graph_neighbors(comm, rank, maxneighbors, neighbors);

#ifdef PERF_PROFILE
    PROFILE_STOP(103);
#endif

    return returnVal;
}


int MPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(109);
#endif

#ifdef DEBUG
    printf("Enter MPI_Graphdims_get\n");
#endif

    returnVal = PMPI_Graphdims_get(comm, nnodes, nedges);

#ifdef PERF_PROFILE
    PROFILE_STOP(109);
#endif

    return returnVal;
}


int MPI_Grequest_complete(MPI_Request request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(112);
#endif

#ifdef DEBUG
    printf("Enter MPI_Grequest_complete\n");
#endif

    returnVal = PMPI_Grequest_complete(request);

#ifdef PERF_PROFILE
    PROFILE_STOP(112);
#endif

    return returnVal;
}


int MPI_Grequest_start(MPI_Grequest_query_function *query_fn, MPI_Grequest_free_function *free_fn,
                       MPI_Grequest_cancel_function *cancel_fn, void *extra_state, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(115);
#endif

#ifdef DEBUG
    printf("Enter MPI_Grequest_start\n");
#endif

    returnVal = PMPI_Grequest_start(query_fn, free_fn, cancel_fn, extra_state, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(115);
#endif

    return returnVal;
}


int MPI_Group_compare(MPI_Group group1, MPI_Group group2, int *result) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(118);
#endif

#ifdef DEBUG
    printf("Enter MPI_Group_compare\n");
#endif

    returnVal = PMPI_Group_compare(group1, group2, result);

#ifdef PERF_PROFILE
    PROFILE_STOP(118);
#endif

    return returnVal;
}


int MPI_Group_difference(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(121);
#endif

#ifdef DEBUG
    printf("Enter MPI_Group_difference\n");
#endif

    returnVal = PMPI_Group_difference(group1, group2, newgroup);

#ifdef PERF_PROFILE
    PROFILE_STOP(121);
#endif

    return returnVal;
}


int MPI_Group_excl(MPI_Group group, int n, const int ranks[], MPI_Group *newgroup) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(124);
#endif

#ifdef DEBUG
    printf("Enter MPI_Group_excl\n");
#endif

    returnVal = PMPI_Group_excl(group, n, ranks, newgroup);

#ifdef PERF_PROFILE
    PROFILE_STOP(124);
#endif

    return returnVal;
}


int MPI_Group_free(MPI_Group *group) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(127);
#endif

#ifdef DEBUG
    printf("Enter MPI_Group_free\n");
#endif

    returnVal = PMPI_Group_free(group);

#ifdef PERF_PROFILE
    PROFILE_STOP(127);
#endif

    return returnVal;
}


int MPI_Group_incl(MPI_Group group, int n, const int ranks[], MPI_Group *newgroup) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(130);
#endif

#ifdef DEBUG
    printf("Enter MPI_Group_incl\n");
#endif

    returnVal = PMPI_Group_incl(group, n, ranks, newgroup);

#ifdef PERF_PROFILE
    PROFILE_STOP(130);
#endif

    return returnVal;
}


int MPI_Group_intersection(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(133);
#endif

#ifdef DEBUG
    printf("Enter MPI_Group_intersection\n");
#endif

    returnVal = PMPI_Group_intersection(group1, group2, newgroup);

#ifdef PERF_PROFILE
    PROFILE_STOP(133);
#endif

    return returnVal;
}


int MPI_Group_range_excl(MPI_Group group, int n, int ranges[][3], MPI_Group *newgroup) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(136);
#endif

#ifdef DEBUG
    printf("Enter MPI_Group_range_excl\n");
#endif

    returnVal = PMPI_Group_range_excl(group, n, ranges, newgroup);

#ifdef PERF_PROFILE
    PROFILE_STOP(136);
#endif

    return returnVal;
}


int MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3], MPI_Group *newgroup) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(139);
#endif

#ifdef DEBUG
    printf("Enter MPI_Group_range_incl\n");
#endif

    returnVal = PMPI_Group_range_incl(group, n, ranges, newgroup);

#ifdef PERF_PROFILE
    PROFILE_STOP(139);
#endif

    return returnVal;
}


int MPI_Group_rank(MPI_Group group, int *rank) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(142);
#endif

#ifdef DEBUG
    printf("Enter MPI_Group_rank\n");
#endif

    returnVal = PMPI_Group_rank(group, rank);

#ifdef PERF_PROFILE
    PROFILE_STOP(142);
#endif

    return returnVal;
}


int MPI_Group_size(MPI_Group group, int *size) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(145);
#endif

#ifdef DEBUG
    printf("Enter MPI_Group_size\n");
#endif

    returnVal = PMPI_Group_size(group, size);

#ifdef PERF_PROFILE
    PROFILE_STOP(145);
#endif

    return returnVal;
}


int MPI_Group_translate_ranks(MPI_Group group1, int n, const int ranks1[], MPI_Group group2, int ranks2[]) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(148);
#endif

#ifdef DEBUG
    printf("Enter MPI_Group_translate_ranks\n");
#endif

    returnVal = PMPI_Group_translate_ranks(group1, n, ranks1, group2, ranks2);

#ifdef PERF_PROFILE
    PROFILE_STOP(148);
#endif

    return returnVal;
}


int MPI_Group_union(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(151);
#endif

#ifdef DEBUG
    printf("Enter MPI_Group_union\n");
#endif

    returnVal = PMPI_Group_union(group1, group2, newgroup);

#ifdef PERF_PROFILE
    PROFILE_STOP(151);
#endif

    return returnVal;
}


int
MPI_Ibsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(178);
#endif

#ifdef DEBUG
    printf("Enter MPI_Ibsend\n");
#endif

    returnVal = PMPI_Ibsend(buf, count, datatype, dest, tag, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(178);
#endif

    return returnVal;
}


int MPI_Improbe(int source, int tag, MPI_Comm comm, int *flag, MPI_Message *message, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(190);
#endif

#ifdef DEBUG
    printf("Enter MPI_Improbe\n");
#endif

    returnVal = PMPI_Improbe(source, tag, comm, flag, message, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(190);
#endif

    return returnVal;
}


int MPI_Imrecv(void *buf, int count, MPI_Datatype type, MPI_Message *message, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(193);
#endif

#ifdef DEBUG
    printf("Enter MPI_Imrecv\n");
#endif

    returnVal = PMPI_Imrecv(buf, count, type, message, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(193);
#endif

    return returnVal;
}


int MPI_Info_create(MPI_Info *info) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(211);
#endif

#ifdef DEBUG
    printf("Enter MPI_Info_create\n");
#endif

    returnVal = PMPI_Info_create(info);

#ifdef PERF_PROFILE
    PROFILE_STOP(211);
#endif

    return returnVal;
}


int MPI_Info_delete(MPI_Info info, const char *key) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(214);
#endif

#ifdef DEBUG
    printf("Enter MPI_Info_delete\n");
#endif

    returnVal = PMPI_Info_delete(info, key);

#ifdef PERF_PROFILE
    PROFILE_STOP(214);
#endif

    return returnVal;
}


int MPI_Info_dup(MPI_Info info, MPI_Info *newinfo) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(217);
#endif

#ifdef DEBUG
    printf("Enter MPI_Info_dup\n");
#endif

    returnVal = PMPI_Info_dup(info, newinfo);

#ifdef PERF_PROFILE
    PROFILE_STOP(217);
#endif

    return returnVal;
}


int MPI_Info_free(MPI_Info *info) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(220);
#endif

#ifdef DEBUG
    printf("Enter MPI_Info_free\n");
#endif

    returnVal = PMPI_Info_free(info);

#ifdef PERF_PROFILE
    PROFILE_STOP(220);
#endif

    return returnVal;
}


int MPI_Info_get(MPI_Info info, const char *key, int valuelen, char *value, int *flag) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(223);
#endif

#ifdef DEBUG
    printf("Enter MPI_Info_get\n");
#endif

    returnVal = PMPI_Info_get(info, key, valuelen, value, flag);

#ifdef PERF_PROFILE
    PROFILE_STOP(223);
#endif

    return returnVal;
}


int MPI_Info_get_nkeys(MPI_Info info, int *nkeys) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(226);
#endif

#ifdef DEBUG
    printf("Enter MPI_Info_get_nkeys\n");
#endif

    returnVal = PMPI_Info_get_nkeys(info, nkeys);

#ifdef PERF_PROFILE
    PROFILE_STOP(226);
#endif

    return returnVal;
}


int MPI_Info_get_nthkey(MPI_Info info, int n, char *key) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(229);
#endif

#ifdef DEBUG
    printf("Enter MPI_Info_get_nthkey\n");
#endif

    returnVal = PMPI_Info_get_nthkey(info, n, key);

#ifdef PERF_PROFILE
    PROFILE_STOP(229);
#endif

    return returnVal;
}


int MPI_Info_get_valuelen(MPI_Info info, const char *key, int *valuelen, int *flag) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(232);
#endif

#ifdef DEBUG
    printf("Enter MPI_Info_get_valuelen\n");
#endif

    returnVal = PMPI_Info_get_valuelen(info, key, valuelen, flag);

#ifdef PERF_PROFILE
    PROFILE_STOP(232);
#endif

    return returnVal;
}


int MPI_Info_set(MPI_Info info, const char *key, const char *value) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(235);
#endif

#ifdef DEBUG
    printf("Enter MPI_Info_set\n");
#endif

    returnVal = PMPI_Info_set(info, key, value);

#ifdef PERF_PROFILE
    PROFILE_STOP(235);
#endif

    return returnVal;
}


int MPI_Initialized(int *flag) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(244);
#endif

#ifdef DEBUG
    printf("Enter MPI_Initialized\n");
#endif

    returnVal = PMPI_Initialized(flag);

#ifdef PERF_PROFILE
    PROFILE_STOP(244);
#endif

    return returnVal;
}


int MPI_Init_thread(int *argc, char ***argv, int required, int *provided) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(241);
#endif

#ifdef DEBUG
    printf("Enter MPI_Init_thread\n");
#endif

    returnVal = PMPI_Init_thread(argc, argv, required, provided);

#ifdef PERF_PROFILE
    PROFILE_STOP(241);
#endif

    return returnVal;
}


int MPI_Intercomm_create(MPI_Comm local_comm, int local_leader, MPI_Comm bridge_comm, int remote_leader, int tag,
                         MPI_Comm *newintercomm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(247);
#endif

#ifdef DEBUG
    printf("Enter MPI_Intercomm_create\n");
#endif

    returnVal = PMPI_Intercomm_create(local_comm, local_leader, bridge_comm, remote_leader, tag, newintercomm);

#ifdef PERF_PROFILE
    PROFILE_STOP(247);
#endif

    return returnVal;
}


int MPI_Intercomm_merge(MPI_Comm intercomm, int high, MPI_Comm *newintercomm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(250);
#endif

#ifdef DEBUG
    printf("Enter MPI_Intercomm_merge\n");
#endif

    returnVal = PMPI_Intercomm_merge(intercomm, high, newintercomm);

#ifdef PERF_PROFILE
    PROFILE_STOP(250);
#endif

    return returnVal;
}


int MPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(253);
#endif

#ifdef DEBUG
    printf("Enter MPI_Iprobe\n");
#endif

    returnVal = PMPI_Iprobe(source, tag, comm, flag, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(253);
#endif

    return returnVal;
}


int MPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(256);
#endif

#ifdef DEBUG
    printf("Enter MPI_Irecv\n");
#endif

    returnVal = PMPI_Irecv(buf, count, datatype, source, tag, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(256);
#endif

    return returnVal;
}


int
MPI_Irsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(268);
#endif

#ifdef DEBUG
    printf("Enter MPI_Irsend\n");
#endif

    returnVal = PMPI_Irsend(buf, count, datatype, dest, tag, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(268);
#endif

    return returnVal;
}


int
MPI_Isend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(283);
#endif

#ifdef DEBUG
    printf("Enter MPI_Isend\n");
#endif

    returnVal = PMPI_Isend(buf, count, datatype, dest, tag, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(283);
#endif

    return returnVal;
}


int
MPI_Issend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(286);
#endif

#ifdef DEBUG
    printf("Enter MPI_Issend\n");
#endif

    returnVal = PMPI_Issend(buf, count, datatype, dest, tag, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(286);
#endif

    return returnVal;
}


int MPI_Is_thread_main(int *flag) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(271);
#endif

#ifdef DEBUG
    printf("Enter MPI_Is_thread_main\n");
#endif

    returnVal = PMPI_Is_thread_main(flag);

#ifdef PERF_PROFILE
    PROFILE_STOP(271);
#endif

    return returnVal;
}


int MPI_Lookup_name(const char *service_name, MPI_Info info, char *port_name) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(295);
#endif

#ifdef DEBUG
    printf("Enter MPI_Lookup_name\n");
#endif

    returnVal = PMPI_Lookup_name(service_name, info, port_name);

#ifdef PERF_PROFILE
    PROFILE_STOP(295);
#endif

    return returnVal;
}


int MPI_Mprobe(int source, int tag, MPI_Comm comm, MPI_Message *message, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(298);
#endif

#ifdef DEBUG
    printf("Enter MPI_Mprobe\n");
#endif

    returnVal = PMPI_Mprobe(source, tag, comm, message, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(298);
#endif

    return returnVal;
}


int MPI_Mrecv(void *buf, int count, MPI_Datatype type, MPI_Message *message, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(301);
#endif

#ifdef DEBUG
    printf("Enter MPI_Mrecv\n");
#endif

    returnVal = PMPI_Mrecv(buf, count, type, message, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(301);
#endif

    return returnVal;
}


int MPI_Neighbor_allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount,
                           MPI_Datatype recvtype, MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(304);
#endif

#ifdef DEBUG
    printf("Enter MPI_Neighbor_allgather\n");
#endif

    returnVal = PMPI_Neighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(304);
#endif

    return returnVal;
}


int MPI_Ineighbor_allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount,
                            MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(196);
#endif

#ifdef DEBUG
    printf("Enter MPI_Ineighbor_allgather\n");
#endif

    returnVal = PMPI_Ineighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(196);
#endif

    return returnVal;
}


int MPI_Neighbor_allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf,
                            const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(307);
#endif

#ifdef DEBUG
    printf("Enter MPI_Neighbor_allgatherv\n");
#endif

    returnVal = PMPI_Neighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(307);
#endif

    return returnVal;
}


int MPI_Ineighbor_allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf,
                             const int recvcounts[], const int displs[], MPI_Datatype recvtype, MPI_Comm comm,
                             MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(199);
#endif

#ifdef DEBUG
    printf("Enter MPI_Ineighbor_allgatherv\n");
#endif

    returnVal = PMPI_Ineighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm,
                                          request);

#ifdef PERF_PROFILE
    PROFILE_STOP(199);
#endif

    return returnVal;
}


int MPI_Neighbor_alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount,
                          MPI_Datatype recvtype, MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(310);
#endif

#ifdef DEBUG
    printf("Enter MPI_Neighbor_alltoall\n");
#endif

    returnVal = PMPI_Neighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(310);
#endif

    return returnVal;
}


int MPI_Ineighbor_alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount,
                           MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(202);
#endif

#ifdef DEBUG
    printf("Enter MPI_Ineighbor_alltoall\n");
#endif

    returnVal = PMPI_Ineighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(202);
#endif

    return returnVal;
}


int MPI_Neighbor_alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype,
                           void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype,
                           MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(313);
#endif

#ifdef DEBUG
    printf("Enter MPI_Neighbor_alltoallv\n");
#endif

    returnVal = PMPI_Neighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype,
                                        comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(313);
#endif

    return returnVal;
}


int MPI_Ineighbor_alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype,
                            void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype,
                            MPI_Comm comm, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(205);
#endif

#ifdef DEBUG
    printf("Enter MPI_Ineighbor_alltoallv\n");
#endif

    returnVal = PMPI_Ineighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype,
                                         comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(205);
#endif

    return returnVal;
}


int MPI_Neighbor_alltoallw(const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[],
                           const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
                           const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(316);
#endif

#ifdef DEBUG
    printf("Enter MPI_Neighbor_alltoallw\n");
#endif

    returnVal = PMPI_Neighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls,
                                        recvtypes, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(316);
#endif

    return returnVal;
}


int MPI_Ineighbor_alltoallw(const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[],
                            const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
                            const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm,
                            MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(208);
#endif

#ifdef DEBUG
    printf("Enter MPI_Ineighbor_alltoallw\n");
#endif

    returnVal = PMPI_Ineighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls,
                                         recvtypes, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(208);
#endif

    return returnVal;
}


int MPI_Op_create(MPI_User_function *function, int commute, MPI_Op *op) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(322);
#endif

#ifdef DEBUG
    printf("Enter MPI_Op_create\n");
#endif

    returnVal = PMPI_Op_create(function, commute, op);

#ifdef PERF_PROFILE
    PROFILE_STOP(322);
#endif

    return returnVal;
}


int MPI_Open_port(MPI_Info info, char *port_name) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(328);
#endif

#ifdef DEBUG
    printf("Enter MPI_Open_port\n");
#endif

    returnVal = PMPI_Open_port(info, port_name);

#ifdef PERF_PROFILE
    PROFILE_STOP(328);
#endif

    return returnVal;
}


int MPI_Op_free(MPI_Op *op) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(325);
#endif

#ifdef DEBUG
    printf("Enter MPI_Op_free\n");
#endif

    returnVal = PMPI_Op_free(op);

#ifdef PERF_PROFILE
    PROFILE_STOP(325);
#endif

    return returnVal;
}


int MPI_Pack_external(const char datarep[], const void *inbuf, int incount, MPI_Datatype datatype, void *outbuf,
                      MPI_Aint outsize, MPI_Aint *position) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(334);
#endif

#ifdef DEBUG
    printf("Enter MPI_Pack_external\n");
#endif

    returnVal = PMPI_Pack_external(datarep, inbuf, incount, datatype, outbuf, outsize, position);

#ifdef PERF_PROFILE
    PROFILE_STOP(334);
#endif

    return returnVal;
}


int MPI_Pack_external_size(const char datarep[], int incount, MPI_Datatype datatype, MPI_Aint *size) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(337);
#endif

#ifdef DEBUG
    printf("Enter MPI_Pack_external_size\n");
#endif

    returnVal = PMPI_Pack_external_size(datarep, incount, datatype, size);

#ifdef PERF_PROFILE
    PROFILE_STOP(337);
#endif

    return returnVal;
}


int MPI_Pack(const void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, int outsize, int *position,
             MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(331);
#endif

#ifdef DEBUG
    printf("Enter MPI_Pack\n");
#endif

    returnVal = PMPI_Pack(inbuf, incount, datatype, outbuf, outsize, position, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(331);
#endif

    return returnVal;
}


int MPI_Pack_size(int incount, MPI_Datatype datatype, MPI_Comm comm, int *size) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(340);
#endif

#ifdef DEBUG
    printf("Enter MPI_Pack_size\n");
#endif

    returnVal = PMPI_Pack_size(incount, datatype, comm, size);

#ifdef PERF_PROFILE
    PROFILE_STOP(340);
#endif

    return returnVal;
}


int MPI_Pcontrol(const int level, ...) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(343);
#endif

#ifdef DEBUG
    printf("Enter MPI_Pcontrol\n");
#endif

    returnVal = PMPI_Pcontrol(level);

#ifdef PERF_PROFILE
    PROFILE_STOP(343);
#endif

    return returnVal;
}


int MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(346);
#endif

#ifdef DEBUG
    printf("Enter MPI_Probe\n");
#endif

    returnVal = PMPI_Probe(source, tag, comm, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(346);
#endif

    return returnVal;
}


int MPI_Publish_name(const char *service_name, MPI_Info info, const char *port_name) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(349);
#endif

#ifdef DEBUG
    printf("Enter MPI_Publish_name\n");
#endif

    returnVal = PMPI_Publish_name(service_name, info, port_name);

#ifdef PERF_PROFILE
    PROFILE_STOP(349);
#endif

    return returnVal;
}


int
MPI_Put(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp,
        int target_count, MPI_Datatype target_datatype, MPI_Win win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(352);
#endif

#ifdef DEBUG
    printf("Enter MPI_Put\n");
#endif

    returnVal = PMPI_Put(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count,
                         target_datatype, win);

#ifdef PERF_PROFILE
    PROFILE_STOP(352);
#endif

    return returnVal;
}


int MPI_Query_thread(int *provided) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(355);
#endif

#ifdef DEBUG
    printf("Enter MPI_Query_thread\n");
#endif

    returnVal = PMPI_Query_thread(provided);

#ifdef PERF_PROFILE
    PROFILE_STOP(355);
#endif

    return returnVal;
}


int MPI_Raccumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank,
                    MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win,
                    MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(358);
#endif

#ifdef DEBUG
    printf("Enter MPI_Raccumulate\n");
#endif

    returnVal = PMPI_Raccumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count,
                                 target_datatype, op, win, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(358);
#endif

    return returnVal;
}


int
MPI_Recv_init(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(364);
#endif

#ifdef DEBUG
    printf("Enter MPI_Recv_init\n");
#endif

    returnVal = PMPI_Recv_init(buf, count, datatype, source, tag, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(364);
#endif

    return returnVal;
}


int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(361);
#endif

#ifdef DEBUG
    printf("Enter MPI_Recv\n");
#endif

    returnVal = PMPI_Recv(buf, count, datatype, source, tag, comm, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(361);
#endif

    return returnVal;
}


int
MPI_Reduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(367);
#endif

#ifdef DEBUG
    printf("Enter MPI_Reduce\n");
#endif

    returnVal = PMPI_Reduce(sendbuf, recvbuf, count, datatype, op, root, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(367);
#endif

    return returnVal;
}


int
MPI_Ireduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm,
            MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(259);
#endif

#ifdef DEBUG
    printf("Enter MPI_Ireduce\n");
#endif

    returnVal = PMPI_Ireduce(sendbuf, recvbuf, count, datatype, op, root, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(259);
#endif

    return returnVal;
}


int MPI_Reduce_local(const void *inbuf, void *inoutbuf, int count, MPI_Datatype datatype, MPI_Op op) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(370);
#endif

#ifdef DEBUG
    printf("Enter MPI_Reduce_local\n");
#endif

    returnVal = PMPI_Reduce_local(inbuf, inoutbuf, count, datatype, op);

#ifdef PERF_PROFILE
    PROFILE_STOP(370);
#endif

    return returnVal;
}


int MPI_Reduce_scatter(const void *sendbuf, void *recvbuf, const int recvcounts[], MPI_Datatype datatype, MPI_Op op,
                       MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(373);
#endif

#ifdef DEBUG
    printf("Enter MPI_Reduce_scatter\n");
#endif

    returnVal = PMPI_Reduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(373);
#endif

    return returnVal;
}


int MPI_Ireduce_scatter(const void *sendbuf, void *recvbuf, const int recvcounts[], MPI_Datatype datatype, MPI_Op op,
                        MPI_Comm comm, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(262);
#endif

#ifdef DEBUG
    printf("Enter MPI_Ireduce_scatter\n");
#endif

    returnVal = PMPI_Ireduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(262);
#endif

    return returnVal;
}


int MPI_Reduce_scatter_block(const void *sendbuf, void *recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op,
                             MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(376);
#endif

#ifdef DEBUG
    printf("Enter MPI_Reduce_scatter_block\n");
#endif

    returnVal = PMPI_Reduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(376);
#endif

    return returnVal;
}


int MPI_Ireduce_scatter_block(const void *sendbuf, void *recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op,
                              MPI_Comm comm, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(265);
#endif

#ifdef DEBUG
    printf("Enter MPI_Ireduce_scatter_block\n");
#endif

    returnVal = PMPI_Ireduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(265);
#endif

    return returnVal;
}


int MPI_Register_datarep(const char *datarep, MPI_Datarep_conversion_function *read_conversion_fn,
                         MPI_Datarep_conversion_function *write_conversion_fn,
                         MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(379);
#endif

#ifdef DEBUG
    printf("Enter MPI_Register_datarep\n");
#endif

    returnVal = PMPI_Register_datarep(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn,
                                      extra_state);

#ifdef PERF_PROFILE
    PROFILE_STOP(379);
#endif

    return returnVal;
}


int MPI_Request_free(MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(382);
#endif

#ifdef DEBUG
    printf("Enter MPI_Request_free\n");
#endif

    returnVal = PMPI_Request_free(request);

#ifdef PERF_PROFILE
    PROFILE_STOP(382);
#endif

    return returnVal;
}


int MPI_Request_get_status(MPI_Request request, int *flag, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(385);
#endif

#ifdef DEBUG
    printf("Enter MPI_Request_get_status\n");
#endif

    returnVal = PMPI_Request_get_status(request, flag, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(385);
#endif

    return returnVal;
}


int MPI_Rget(void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp,
             int target_count, MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(388);
#endif

#ifdef DEBUG
    printf("Enter MPI_Rget\n");
#endif

    returnVal = PMPI_Rget(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count,
                          target_datatype, win, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(388);
#endif

    return returnVal;
}


int MPI_Rget_accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, void *result_addr,
                        int result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp,
                        int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(391);
#endif

#ifdef DEBUG
    printf("Enter MPI_Rget_accumulate\n");
#endif

    returnVal = PMPI_Rget_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count,
                                     result_datatype, target_rank, target_disp, target_count, target_datatype, op, win,
                                     request);

#ifdef PERF_PROFILE
    PROFILE_STOP(391);
#endif

    return returnVal;
}


int
MPI_Rput(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp,
         int target_cout, MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(394);
#endif

#ifdef DEBUG
    printf("Enter MPI_Rput\n");
#endif

    returnVal = PMPI_Rput(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_cout,
                          target_datatype, win, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(394);
#endif

    return returnVal;
}


int MPI_Rsend(const void *ibuf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(2);
#endif

#ifdef DEBUG
    printf("Enter MPI_Rsend\n");
#endif

    returnVal = PMPI_Rsend(ibuf, count, datatype, dest, tag, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(2);
#endif

    return returnVal;
}


int MPI_Rsend_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm,
                   MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(5);
#endif

#ifdef DEBUG
    printf("Enter MPI_Rsend_init\n");
#endif

    returnVal = PMPI_Rsend_init(buf, count, datatype, dest, tag, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(5);
#endif

    return returnVal;
}


int MPI_Scan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(8);
#endif

#ifdef DEBUG
    printf("Enter MPI_Scan\n");
#endif

    returnVal = PMPI_Scan(sendbuf, recvbuf, count, datatype, op, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(8);
#endif

    return returnVal;
}


int MPI_Iscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
              MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(274);
#endif

#ifdef DEBUG
    printf("Enter MPI_Iscan\n");
#endif

    returnVal = PMPI_Iscan(sendbuf, recvbuf, count, datatype, op, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(274);
#endif

    return returnVal;
}


int MPI_Scatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount,
                MPI_Datatype recvtype, int root, MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(11);
#endif

#ifdef DEBUG
    printf("Enter MPI_Scatter\n");
#endif

    returnVal = PMPI_Scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(11);
#endif

    return returnVal;
}


int MPI_Iscatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount,
                 MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(277);
#endif

#ifdef DEBUG
    printf("Enter MPI_Iscatter\n");
#endif

    returnVal = PMPI_Iscatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(277);
#endif

    return returnVal;
}


int MPI_Scatterv(const void *sendbuf, const int sendcounts[], const int displs[], MPI_Datatype sendtype, void *recvbuf,
                 int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(14);
#endif

#ifdef DEBUG
    printf("Enter MPI_Scatterv\n");
#endif

    returnVal = PMPI_Scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(14);
#endif

    return returnVal;
}


int MPI_Iscatterv(const void *sendbuf, const int sendcounts[], const int displs[], MPI_Datatype sendtype, void *recvbuf,
                  int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(280);
#endif

#ifdef DEBUG
    printf("Enter MPI_Iscatterv\n");
#endif

    returnVal = PMPI_Iscatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm,
                               request);

#ifdef PERF_PROFILE
    PROFILE_STOP(280);
#endif

    return returnVal;
}


int MPI_Send_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm,
                  MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(20);
#endif

#ifdef DEBUG
    printf("Enter MPI_Send_init\n");
#endif

    returnVal = PMPI_Send_init(buf, count, datatype, dest, tag, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(20);
#endif

    return returnVal;
}


int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(17);
#endif

#ifdef DEBUG
    printf("Enter MPI_Send\n");
#endif

    returnVal = PMPI_Send(buf, count, datatype, dest, tag, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(17);
#endif

    return returnVal;
}


int MPI_Sendrecv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf,
                 int recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(23);
#endif

#ifdef DEBUG
    printf("Enter MPI_Sendrecv\n");
#endif

    returnVal = PMPI_Sendrecv(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source,
                              recvtag, comm, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(23);
#endif

    return returnVal;
}


int MPI_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag,
                         MPI_Comm comm, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(26);
#endif

#ifdef DEBUG
    printf("Enter MPI_Sendrecv_replace\n");
#endif

    returnVal = PMPI_Sendrecv_replace(buf, count, datatype, dest, sendtag, source, recvtag, comm, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(26);
#endif

    return returnVal;
}


int MPI_Ssend_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm,
                   MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(32);
#endif

#ifdef DEBUG
    printf("Enter MPI_Ssend_init\n");
#endif

    returnVal = PMPI_Ssend_init(buf, count, datatype, dest, tag, comm, request);

#ifdef PERF_PROFILE
    PROFILE_STOP(32);
#endif

    return returnVal;
}


int MPI_Ssend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(29);
#endif

#ifdef DEBUG
    printf("Enter MPI_Ssend\n");
#endif

    returnVal = PMPI_Ssend(buf, count, datatype, dest, tag, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(29);
#endif

    return returnVal;
}


int MPI_Start(MPI_Request *request) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(35);
#endif

#ifdef DEBUG
    printf("Enter MPI_Start\n");
#endif

    returnVal = PMPI_Start(request);

#ifdef PERF_PROFILE
    PROFILE_STOP(35);
#endif

    return returnVal;
}


int MPI_Startall(int count, MPI_Request array_of_requests[]) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(38);
#endif

#ifdef DEBUG
    printf("Enter MPI_Startall\n");
#endif

    returnVal = PMPI_Startall(count, array_of_requests);

#ifdef PERF_PROFILE
    PROFILE_STOP(38);
#endif

    return returnVal;
}


int MPI_Status_set_cancelled(MPI_Status *status, int flag) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(41);
#endif

#ifdef DEBUG
    printf("Enter MPI_Status_set_cancelled\n");
#endif

    returnVal = PMPI_Status_set_cancelled(status, flag);

#ifdef PERF_PROFILE
    PROFILE_STOP(41);
#endif

    return returnVal;
}


int MPI_Status_set_elements(MPI_Status *status, MPI_Datatype datatype, int count) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(44);
#endif

#ifdef DEBUG
    printf("Enter MPI_Status_set_elements\n");
#endif

    returnVal = PMPI_Status_set_elements(status, datatype, count);

#ifdef PERF_PROFILE
    PROFILE_STOP(44);
#endif

    return returnVal;
}


int MPI_Status_set_elements_x(MPI_Status *status, MPI_Datatype datatype, MPI_Count count) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(47);
#endif

#ifdef DEBUG
    printf("Enter MPI_Status_set_elements_x\n");
#endif

    returnVal = PMPI_Status_set_elements_x(status, datatype, count);

#ifdef PERF_PROFILE
    PROFILE_STOP(47);
#endif

    return returnVal;
}


int MPI_Testall(int count, MPI_Request array_of_requests[], int *flag, MPI_Status array_of_statuses[]) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(140);
#endif

#ifdef DEBUG
    printf("Enter MPI_Testall\n");
#endif

    returnVal = PMPI_Testall(count, array_of_requests, flag, array_of_statuses);

#ifdef PERF_PROFILE
    PROFILE_STOP(140);
#endif

    return returnVal;
}


int MPI_Testany(int count, MPI_Request array_of_requests[], int *index, int *flag, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(143);
#endif

#ifdef DEBUG
    printf("Enter MPI_Testany\n");
#endif

    returnVal = PMPI_Testany(count, array_of_requests, index, flag, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(143);
#endif

    return returnVal;
}


int MPI_Test(MPI_Request *request, int *flag, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(134);
#endif

#ifdef DEBUG
    printf("Enter MPI_Test\n");
#endif

    returnVal = PMPI_Test(request, flag, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(134);
#endif

    return returnVal;
}


int MPI_Test_cancelled(const MPI_Status *status, int *flag) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(137);
#endif

#ifdef DEBUG
    printf("Enter MPI_Test_cancelled\n");
#endif

    returnVal = PMPI_Test_cancelled(status, flag);

#ifdef PERF_PROFILE
    PROFILE_STOP(137);
#endif

    return returnVal;
}


int MPI_Testsome(int incount, MPI_Request array_of_requests[], int *outcount, int array_of_indices[],
                 MPI_Status array_of_statuses[]) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(146);
#endif

#ifdef DEBUG
    printf("Enter MPI_Testsome\n");
#endif

    returnVal = PMPI_Testsome(incount, array_of_requests, outcount, array_of_indices, array_of_statuses);

#ifdef PERF_PROFILE
    PROFILE_STOP(146);
#endif

    return returnVal;
}


int MPI_Topo_test(MPI_Comm comm, int *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(149);
#endif

#ifdef DEBUG
    printf("Enter MPI_Topo_test\n");
#endif

    returnVal = PMPI_Topo_test(comm, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(149);
#endif

    return returnVal;
}


int MPI_Type_commit(MPI_Datatype *type) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(152);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_commit\n");
#endif

    returnVal = PMPI_Type_commit(type);

#ifdef PERF_PROFILE
    PROFILE_STOP(152);
#endif

    return returnVal;
}


int MPI_Type_contiguous(int count, MPI_Datatype oldtype, MPI_Datatype *newtype) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(155);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_contiguous\n");
#endif

    returnVal = PMPI_Type_contiguous(count, oldtype, newtype);

#ifdef PERF_PROFILE
    PROFILE_STOP(155);
#endif

    return returnVal;
}


int MPI_Type_create_darray(int size, int rank, int ndims, const int gsize_array[], const int distrib_array[],
                           const int darg_array[], const int psize_array[], int order, MPI_Datatype oldtype,
                           MPI_Datatype *newtype) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(158);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_create_darray\n");
#endif

    returnVal = PMPI_Type_create_darray(size, rank, ndims, gsize_array, distrib_array, darg_array, psize_array, order,
                                        oldtype, newtype);

#ifdef PERF_PROFILE
    PROFILE_STOP(158);
#endif

    return returnVal;
}


int MPI_Type_create_hindexed_block(int count, int blocklength, const MPI_Aint array_of_displacements[],
                                   MPI_Datatype oldtype, MPI_Datatype *newtype) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(164);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_create_hindexed_block\n");
#endif

    returnVal = PMPI_Type_create_hindexed_block(count, blocklength, array_of_displacements, oldtype, newtype);

#ifdef PERF_PROFILE
    PROFILE_STOP(164);
#endif

    return returnVal;
}


int MPI_Type_create_hindexed(int count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[],
                             MPI_Datatype oldtype, MPI_Datatype *newtype) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(161);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_create_hindexed\n");
#endif

    returnVal = PMPI_Type_create_hindexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype);

#ifdef PERF_PROFILE
    PROFILE_STOP(161);
#endif

    return returnVal;
}


int MPI_Type_create_hvector(int count, int blocklength, MPI_Aint stride, MPI_Datatype oldtype, MPI_Datatype *newtype) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(167);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_create_hvector\n");
#endif

    returnVal = PMPI_Type_create_hvector(count, blocklength, stride, oldtype, newtype);

#ifdef PERF_PROFILE
    PROFILE_STOP(167);
#endif

    return returnVal;
}


int MPI_Type_create_keyval(MPI_Type_copy_attr_function *type_copy_attr_fn,
                           MPI_Type_delete_attr_function *type_delete_attr_fn, int *type_keyval, void *extra_state) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(173);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_create_keyval\n");
#endif

    returnVal = PMPI_Type_create_keyval(type_copy_attr_fn, type_delete_attr_fn, type_keyval, extra_state);

#ifdef PERF_PROFILE
    PROFILE_STOP(173);
#endif

    return returnVal;
}


int MPI_Type_create_indexed_block(int count, int blocklength, const int array_of_displacements[], MPI_Datatype oldtype,
                                  MPI_Datatype *newtype) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(170);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_create_indexed_block\n");
#endif

    returnVal = PMPI_Type_create_indexed_block(count, blocklength, array_of_displacements, oldtype, newtype);

#ifdef PERF_PROFILE
    PROFILE_STOP(170);
#endif

    return returnVal;
}


int MPI_Type_create_struct(int count, const int array_of_block_lengths[], const MPI_Aint array_of_displacements[],
                           const MPI_Datatype array_of_types[], MPI_Datatype *newtype) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(179);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_create_struct\n");
#endif

    returnVal = PMPI_Type_create_struct(count, array_of_block_lengths, array_of_displacements, array_of_types, newtype);

#ifdef PERF_PROFILE
    PROFILE_STOP(179);
#endif

    return returnVal;
}


int MPI_Type_create_subarray(int ndims, const int size_array[], const int subsize_array[], const int start_array[],
                             int order, MPI_Datatype oldtype, MPI_Datatype *newtype) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(182);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_create_subarray\n");
#endif

    returnVal = PMPI_Type_create_subarray(ndims, size_array, subsize_array, start_array, order, oldtype, newtype);

#ifdef PERF_PROFILE
    PROFILE_STOP(182);
#endif

    return returnVal;
}


int MPI_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb, MPI_Aint extent, MPI_Datatype *newtype) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(176);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_create_resized\n");
#endif

    returnVal = PMPI_Type_create_resized(oldtype, lb, extent, newtype);

#ifdef PERF_PROFILE
    PROFILE_STOP(176);
#endif

    return returnVal;
}


int MPI_Type_delete_attr(MPI_Datatype type, int type_keyval) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(185);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_delete_attr\n");
#endif

    returnVal = PMPI_Type_delete_attr(type, type_keyval);

#ifdef PERF_PROFILE
    PROFILE_STOP(185);
#endif

    return returnVal;
}


int MPI_Type_dup(MPI_Datatype type, MPI_Datatype *newtype) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(188);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_dup\n");
#endif

    returnVal = PMPI_Type_dup(type, newtype);

#ifdef PERF_PROFILE
    PROFILE_STOP(188);
#endif

    return returnVal;
}


int MPI_Type_free(MPI_Datatype *type) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(194);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_free\n");
#endif

    returnVal = PMPI_Type_free(type);

#ifdef PERF_PROFILE
    PROFILE_STOP(194);
#endif

    return returnVal;
}


int MPI_Type_free_keyval(int *type_keyval) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(197);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_free_keyval\n");
#endif

    returnVal = PMPI_Type_free_keyval(type_keyval);

#ifdef PERF_PROFILE
    PROFILE_STOP(197);
#endif

    return returnVal;
}


int MPI_Type_get_attr(MPI_Datatype type, int type_keyval, void *attribute_val, int *flag) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(200);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_get_attr\n");
#endif

    returnVal = PMPI_Type_get_attr(type, type_keyval, attribute_val, flag);

#ifdef PERF_PROFILE
    PROFILE_STOP(200);
#endif

    return returnVal;
}


int MPI_Type_get_contents(MPI_Datatype mtype, int max_integers, int max_addresses, int max_datatypes,
                          int array_of_integers[], MPI_Aint array_of_addresses[], MPI_Datatype array_of_datatypes[]) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(203);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_get_contents\n");
#endif

    returnVal = PMPI_Type_get_contents(mtype, max_integers, max_addresses, max_datatypes, array_of_integers,
                                       array_of_addresses, array_of_datatypes);

#ifdef PERF_PROFILE
    PROFILE_STOP(203);
#endif

    return returnVal;
}


int MPI_Type_get_envelope(MPI_Datatype type, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(206);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_get_envelope\n");
#endif

    returnVal = PMPI_Type_get_envelope(type, num_integers, num_addresses, num_datatypes, combiner);

#ifdef PERF_PROFILE
    PROFILE_STOP(206);
#endif

    return returnVal;
}


int MPI_Type_get_extent(MPI_Datatype type, MPI_Aint *lb, MPI_Aint *extent) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(209);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_get_extent\n");
#endif

    returnVal = PMPI_Type_get_extent(type, lb, extent);

#ifdef PERF_PROFILE
    PROFILE_STOP(209);
#endif

    return returnVal;
}


int MPI_Type_get_extent_x(MPI_Datatype type, MPI_Count *lb, MPI_Count *extent) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(212);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_get_extent_x\n");
#endif

    returnVal = PMPI_Type_get_extent_x(type, lb, extent);

#ifdef PERF_PROFILE
    PROFILE_STOP(212);
#endif

    return returnVal;
}


int MPI_Type_get_name(MPI_Datatype type, char *type_name, int *resultlen) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(215);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_get_name\n");
#endif

    returnVal = PMPI_Type_get_name(type, type_name, resultlen);

#ifdef PERF_PROFILE
    PROFILE_STOP(215);
#endif

    return returnVal;
}


int MPI_Type_get_true_extent(MPI_Datatype datatype, MPI_Aint *true_lb, MPI_Aint *true_extent) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(218);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_get_true_extent\n");
#endif

    returnVal = PMPI_Type_get_true_extent(datatype, true_lb, true_extent);

#ifdef PERF_PROFILE
    PROFILE_STOP(218);
#endif

    return returnVal;
}


int MPI_Type_get_true_extent_x(MPI_Datatype datatype, MPI_Count *true_lb, MPI_Count *true_extent) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(221);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_get_true_extent_x\n");
#endif

    returnVal = PMPI_Type_get_true_extent_x(datatype, true_lb, true_extent);

#ifdef PERF_PROFILE
    PROFILE_STOP(221);
#endif

    return returnVal;
}


int
MPI_Type_indexed(int count, const int array_of_blocklengths[], const int array_of_displacements[], MPI_Datatype oldtype,
                 MPI_Datatype *newtype) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(230);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_indexed\n");
#endif

    returnVal = PMPI_Type_indexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype);

#ifdef PERF_PROFILE
    PROFILE_STOP(230);
#endif

    return returnVal;
}


int MPI_Type_match_size(int typeclass, int size, MPI_Datatype *type) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(236);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_match_size\n");
#endif

    returnVal = PMPI_Type_match_size(typeclass, size, type);

#ifdef PERF_PROFILE
    PROFILE_STOP(236);
#endif

    return returnVal;
}


int MPI_Type_set_attr(MPI_Datatype type, int type_keyval, void *attr_val) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(239);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_set_attr\n");
#endif

    returnVal = PMPI_Type_set_attr(type, type_keyval, attr_val);

#ifdef PERF_PROFILE
    PROFILE_STOP(239);
#endif

    return returnVal;
}


int MPI_Type_set_name(MPI_Datatype type, const char *type_name) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(242);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_set_name\n");
#endif

    returnVal = PMPI_Type_set_name(type, type_name);

#ifdef PERF_PROFILE
    PROFILE_STOP(242);
#endif

    return returnVal;
}


int MPI_Type_size(MPI_Datatype type, int *size) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(245);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_size\n");
#endif

    returnVal = PMPI_Type_size(type, size);

#ifdef PERF_PROFILE
    PROFILE_STOP(245);
#endif

    return returnVal;
}


int MPI_Type_size_x(MPI_Datatype type, MPI_Count *size) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(248);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_size_x\n");
#endif

    returnVal = PMPI_Type_size_x(type, size);

#ifdef PERF_PROFILE
    PROFILE_STOP(248);
#endif

    return returnVal;
}


int MPI_Type_vector(int count, int blocklength, int stride, MPI_Datatype oldtype, MPI_Datatype *newtype) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(257);
#endif

#ifdef DEBUG
    printf("Enter MPI_Type_vector\n");
#endif

    returnVal = PMPI_Type_vector(count, blocklength, stride, oldtype, newtype);

#ifdef PERF_PROFILE
    PROFILE_STOP(257);
#endif

    return returnVal;
}


int MPI_Unpack(const void *inbuf, int insize, int *position, void *outbuf, int outcount, MPI_Datatype datatype,
               MPI_Comm comm) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(260);
#endif

#ifdef DEBUG
    printf("Enter MPI_Unpack\n");
#endif

    returnVal = PMPI_Unpack(inbuf, insize, position, outbuf, outcount, datatype, comm);

#ifdef PERF_PROFILE
    PROFILE_STOP(260);
#endif

    return returnVal;
}


int MPI_Unpublish_name(const char *service_name, MPI_Info info, const char *port_name) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(266);
#endif

#ifdef DEBUG
    printf("Enter MPI_Unpublish_name\n");
#endif

    returnVal = PMPI_Unpublish_name(service_name, info, port_name);

#ifdef PERF_PROFILE
    PROFILE_STOP(266);
#endif

    return returnVal;
}


int MPI_Waitall(int count, MPI_Request array_of_requests[], MPI_Status *array_of_statuses) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(272);
#endif

#ifdef DEBUG
    printf("Enter MPI_Waitall\n");
#endif

    returnVal = PMPI_Waitall(count, array_of_requests, array_of_statuses);

#ifdef PERF_PROFILE
    PROFILE_STOP(272);
#endif

    return returnVal;
}


int MPI_Waitany(int count, MPI_Request array_of_requests[], int *index, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(275);
#endif

#ifdef DEBUG
    printf("Enter MPI_Waitany\n");
#endif

    returnVal = PMPI_Waitany(count, array_of_requests, index, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(275);
#endif

    return returnVal;
}


int MPI_Wait(MPI_Request *request, MPI_Status *status) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(269);
#endif

#ifdef DEBUG
    printf("Enter MPI_Wait\n");
#endif

    returnVal = PMPI_Wait(request, status);

#ifdef PERF_PROFILE
    PROFILE_STOP(269);
#endif

    return returnVal;
}


int MPI_Waitsome(int incount, MPI_Request array_of_requests[], int *outcount, int array_of_indices[],
                 MPI_Status array_of_statuses[]) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(278);
#endif

#ifdef DEBUG
    printf("Enter MPI_Waitsome\n");
#endif

    returnVal = PMPI_Waitsome(incount, array_of_requests, outcount, array_of_indices, array_of_statuses);

#ifdef PERF_PROFILE
    PROFILE_STOP(278);
#endif

    return returnVal;
}


int MPI_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(281);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_allocate\n");
#endif

    returnVal = PMPI_Win_allocate(size, disp_unit, info, comm, baseptr, win);

#ifdef PERF_PROFILE
    PROFILE_STOP(281);
#endif

    return returnVal;
}


int MPI_Win_allocate_shared(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(284);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_allocate_shared\n");
#endif

    returnVal = PMPI_Win_allocate_shared(size, disp_unit, info, comm, baseptr, win);

#ifdef PERF_PROFILE
    PROFILE_STOP(284);
#endif

    return returnVal;
}


int MPI_Win_attach(MPI_Win win, void *base, MPI_Aint size) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(287);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_attach\n");
#endif

    returnVal = PMPI_Win_attach(win, base, size);

#ifdef PERF_PROFILE
    PROFILE_STOP(287);
#endif

    return returnVal;
}


int MPI_Win_call_errhandler(MPI_Win win, int errorcode) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(290);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_call_errhandler\n");
#endif

    returnVal = PMPI_Win_call_errhandler(win, errorcode);

#ifdef PERF_PROFILE
    PROFILE_STOP(290);
#endif

    return returnVal;
}


int MPI_Win_complete(MPI_Win win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(293);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_complete\n");
#endif

    returnVal = PMPI_Win_complete(win);

#ifdef PERF_PROFILE
    PROFILE_STOP(293);
#endif

    return returnVal;
}


int MPI_Win_create(void *base, MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, MPI_Win *win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(296);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_create\n");
#endif

    returnVal = PMPI_Win_create(base, size, disp_unit, info, comm, win);

#ifdef PERF_PROFILE
    PROFILE_STOP(296);
#endif

    return returnVal;
}


int MPI_Win_create_dynamic(MPI_Info info, MPI_Comm comm, MPI_Win *win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(299);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_create_dynamic\n");
#endif

    returnVal = PMPI_Win_create_dynamic(info, comm, win);

#ifdef PERF_PROFILE
    PROFILE_STOP(299);
#endif

    return returnVal;
}


int MPI_Win_create_errhandler(MPI_Win_errhandler_function *function, MPI_Errhandler *errhandler) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(302);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_create_errhandler\n");
#endif

    returnVal = PMPI_Win_create_errhandler(function, errhandler);

#ifdef PERF_PROFILE
    PROFILE_STOP(302);
#endif

    return returnVal;
}


int
MPI_Win_create_keyval(MPI_Win_copy_attr_function *win_copy_attr_fn, MPI_Win_delete_attr_function *win_delete_attr_fn,
                      int *win_keyval, void *extra_state) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(305);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_create_keyval\n");
#endif

    returnVal = PMPI_Win_create_keyval(win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state);

#ifdef PERF_PROFILE
    PROFILE_STOP(305);
#endif

    return returnVal;
}


int MPI_Win_delete_attr(MPI_Win win, int win_keyval) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(308);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_delete_attr\n");
#endif

    returnVal = PMPI_Win_delete_attr(win, win_keyval);

#ifdef PERF_PROFILE
    PROFILE_STOP(308);
#endif

    return returnVal;
}


int MPI_Win_detach(MPI_Win win, const void *base) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(311);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_detach\n");
#endif

    returnVal = PMPI_Win_detach(win, base);

#ifdef PERF_PROFILE
    PROFILE_STOP(311);
#endif

    return returnVal;
}


int MPI_Win_fence(int assert, MPI_Win win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(314);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_fence\n");
#endif

    returnVal = PMPI_Win_fence(assert, win);

#ifdef PERF_PROFILE
    PROFILE_STOP(314);
#endif

    return returnVal;
}


int MPI_Win_flush(int rank, MPI_Win win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(317);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_flush\n");
#endif

    returnVal = PMPI_Win_flush(rank, win);

#ifdef PERF_PROFILE
    PROFILE_STOP(317);
#endif

    return returnVal;
}


int MPI_Win_flush_all(MPI_Win win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(320);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_flush_all\n");
#endif

    returnVal = PMPI_Win_flush_all(win);

#ifdef PERF_PROFILE
    PROFILE_STOP(320);
#endif

    return returnVal;
}


int MPI_Win_flush_local(int rank, MPI_Win win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(323);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_flush_local\n");
#endif

    returnVal = PMPI_Win_flush_local(rank, win);

#ifdef PERF_PROFILE
    PROFILE_STOP(323);
#endif

    return returnVal;
}


int MPI_Win_flush_local_all(MPI_Win win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(326);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_flush_local_all\n");
#endif

    returnVal = PMPI_Win_flush_local_all(win);

#ifdef PERF_PROFILE
    PROFILE_STOP(326);
#endif

    return returnVal;
}


int MPI_Win_free(MPI_Win *win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(329);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_free\n");
#endif

    returnVal = PMPI_Win_free(win);

#ifdef PERF_PROFILE
    PROFILE_STOP(329);
#endif

    return returnVal;
}


int MPI_Win_free_keyval(int *win_keyval) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(332);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_free_keyval\n");
#endif

    returnVal = PMPI_Win_free_keyval(win_keyval);

#ifdef PERF_PROFILE
    PROFILE_STOP(332);
#endif

    return returnVal;
}


int MPI_Win_get_attr(MPI_Win win, int win_keyval, void *attribute_val, int *flag) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(335);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_get_attr\n");
#endif

    returnVal = PMPI_Win_get_attr(win, win_keyval, attribute_val, flag);

#ifdef PERF_PROFILE
    PROFILE_STOP(335);
#endif

    return returnVal;
}


int MPI_Win_get_errhandler(MPI_Win win, MPI_Errhandler *errhandler) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(338);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_get_errhandler\n");
#endif

    returnVal = PMPI_Win_get_errhandler(win, errhandler);

#ifdef PERF_PROFILE
    PROFILE_STOP(338);
#endif

    return returnVal;
}


int MPI_Win_get_group(MPI_Win win, MPI_Group *group) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(341);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_get_group\n");
#endif

    returnVal = PMPI_Win_get_group(win, group);

#ifdef PERF_PROFILE
    PROFILE_STOP(341);
#endif

    return returnVal;
}


int MPI_Win_get_info(MPI_Win win, MPI_Info *info_used) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(344);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_get_info\n");
#endif

    returnVal = PMPI_Win_get_info(win, info_used);

#ifdef PERF_PROFILE
    PROFILE_STOP(344);
#endif

    return returnVal;
}


int MPI_Win_get_name(MPI_Win win, char *win_name, int *resultlen) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(347);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_get_name\n");
#endif

    returnVal = PMPI_Win_get_name(win, win_name, resultlen);

#ifdef PERF_PROFILE
    PROFILE_STOP(347);
#endif

    return returnVal;
}


int MPI_Win_lock(int lock_type, int rank, int assert, MPI_Win win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(350);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_lock\n");
#endif

    returnVal = PMPI_Win_lock(lock_type, rank, assert, win);

#ifdef PERF_PROFILE
    PROFILE_STOP(350);
#endif

    return returnVal;
}


int MPI_Win_lock_all(int assert, MPI_Win win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(353);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_lock_all\n");
#endif

    returnVal = PMPI_Win_lock_all(assert, win);

#ifdef PERF_PROFILE
    PROFILE_STOP(353);
#endif

    return returnVal;
}


int MPI_Win_post(MPI_Group group, int assert, MPI_Win win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(356);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_post\n");
#endif

    returnVal = PMPI_Win_post(group, assert, win);

#ifdef PERF_PROFILE
    PROFILE_STOP(356);
#endif

    return returnVal;
}


int MPI_Win_set_attr(MPI_Win win, int win_keyval, void *attribute_val) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(359);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_set_attr\n");
#endif

    returnVal = PMPI_Win_set_attr(win, win_keyval, attribute_val);

#ifdef PERF_PROFILE
    PROFILE_STOP(359);
#endif

    return returnVal;
}


int MPI_Win_set_errhandler(MPI_Win win, MPI_Errhandler errhandler) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(362);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_set_errhandler\n");
#endif

    returnVal = PMPI_Win_set_errhandler(win, errhandler);

#ifdef PERF_PROFILE
    PROFILE_STOP(362);
#endif

    return returnVal;
}


int MPI_Win_set_info(MPI_Win win, MPI_Info info) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(365);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_set_info\n");
#endif

    returnVal = PMPI_Win_set_info(win, info);

#ifdef PERF_PROFILE
    PROFILE_STOP(365);
#endif

    return returnVal;
}


int MPI_Win_set_name(MPI_Win win, const char *win_name) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(368);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_set_name\n");
#endif

    returnVal = PMPI_Win_set_name(win, win_name);

#ifdef PERF_PROFILE
    PROFILE_STOP(368);
#endif

    return returnVal;
}


int MPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size, int *disp_unit, void *baseptr) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(371);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_shared_query\n");
#endif

    returnVal = PMPI_Win_shared_query(win, rank, size, disp_unit, baseptr);

#ifdef PERF_PROFILE
    PROFILE_STOP(371);
#endif

    return returnVal;
}


int MPI_Win_start(MPI_Group group, int assert, MPI_Win win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(374);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_start\n");
#endif

    returnVal = PMPI_Win_start(group, assert, win);

#ifdef PERF_PROFILE
    PROFILE_STOP(374);
#endif

    return returnVal;
}


int MPI_Win_sync(MPI_Win win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(377);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_sync\n");
#endif

    returnVal = PMPI_Win_sync(win);

#ifdef PERF_PROFILE
    PROFILE_STOP(377);
#endif

    return returnVal;
}


int MPI_Win_test(MPI_Win win, int *flag) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(380);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_test\n");
#endif

    returnVal = PMPI_Win_test(win, flag);

#ifdef PERF_PROFILE
    PROFILE_STOP(380);
#endif

    return returnVal;
}


int MPI_Win_unlock(int rank, MPI_Win win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(383);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_unlock\n");
#endif

    returnVal = PMPI_Win_unlock(rank, win);

#ifdef PERF_PROFILE
    PROFILE_STOP(383);
#endif

    return returnVal;
}


int MPI_Win_unlock_all(MPI_Win win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(386);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_unlock_all\n");
#endif

    returnVal = PMPI_Win_unlock_all(win);

#ifdef PERF_PROFILE
    PROFILE_STOP(386);
#endif

    return returnVal;
}


int MPI_Win_wait(MPI_Win win) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(389);
#endif

#ifdef DEBUG
    printf("Enter MPI_Win_wait\n");
#endif

    returnVal = PMPI_Win_wait(win);

#ifdef PERF_PROFILE
    PROFILE_STOP(389);
#endif

    return returnVal;
}


double MPI_Wtick(void) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(392);
#endif

#ifdef DEBUG
    printf("Enter MPI_Wtick\n");
#endif

    returnVal = PMPI_Wtick();

#ifdef PERF_PROFILE
    PROFILE_STOP(392);
#endif

    return returnVal;
}


double MPI_Wtime(void) {
    int returnVal;

#ifdef PERF_PROFILE
    PROFILE_START(395);
#endif

#ifdef DEBUG
    printf("Enter MPI_Wtime\n");
#endif

    returnVal = PMPI_Wtime();

#ifdef PERF_PROFILE
    PROFILE_STOP(395);
#endif

    return returnVal;
}

