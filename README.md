# MPI-Profiler
A fine-grain profiler for parallel MPI programs that measures CPU time and MPI time in nanoseconds for each process using 
high-resolution timer from Chrono library.

# Run command
mpic++ mpi_test.cpp -std=c++14 -w -o run && mpirun ./run -np {num_threads}