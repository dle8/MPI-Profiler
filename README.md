# MPI-Profiler
A fine-grain profiler for MPI programs that measures CPU time and MPI time for each process.

# Run command
mpic++ mpi_test.cpp -std=c++14 -w -o run && mpirun ./run -np {num_threads}