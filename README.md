# [MPI-Profiler](https://github.com/dle8/MPI-Profiler) &middot; [![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/dle8/MPI-Profiler/blob/master/LICENSE) 

A C++ static library for fine-grain profiling MPI programs. Measure each MPI routines & CPU time for each process with
better visualization.

## 📚 Table of contents

- [Technical stack](#technical-stack)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Contributors](#contributors)
- [License](#license)

## ⚙ Technical stack

- [C++](https://www.cplusplus.com/)
- [MPI](https://computing.llnl.gov/tutorials/mpi/)

## 🚀 Features

- Time MPI routines used in linked programs
- Render timed result in mpi_record.<process_id>

## ⬇ Installation

- In order to run MPI, you should have GNU C++ compiler (g++). 
    - For Windows users, you should start by installing MinGW Package Installer
    - For Mac users, XCode has already (most of the time) had g++ pre-installed to you
    - For Ubuntu users, you can download [Homebrew](https://brew.sh/) and use the following command ```brew install gcc``` 

## 📋 Usage

- To compile and get the static library ```mpi_timer.a```, run ```make```
- To profile your program, compile & run it together with the generated ```.a``` file and supply number of threads:
    - For example, to profile ```a.cpp``` running with 4 tasks (processes): ```mpic++ mpi_timer.a your_program_name.cpp -o run && mpirun ./run -np 4```
- After compile & run, each timing result for each process p will be in ```mpi_record.p``` file
- To clean object files, run ```make clean```
- To clean processes' records, run ```make clean_record```

## 👨‍💻 Contributors

- [Dung Tuan Le](https://github.com/dle8) <br/>
Computer Science major.  
University of Rochester '21.

## 📄 License

Kronos is [MIT licensed](./LICENSE).
