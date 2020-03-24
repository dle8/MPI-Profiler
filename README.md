# MPI-Profiler
A C++ static library for fine-grain profiling MPI programs.

# Run command
mpic++ mpi_test.cpp -std=c++14 -w -o run && mpirun ./run -np {num_threads}
