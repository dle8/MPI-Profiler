CPP = mpic++
FLAGS = -w -std=c++14
DEF= -DPERF_PROFILE
# -DMPI_TIME
AR = ar
ARTAG = rvs

all: mpi_timer run

run : mpi_timer.a
	$(CPP) $(SRC) mpi_timer.a -o run && mpirun ./run -np $(NP)

mpi_timer : mpi_wrapper.o profile.o
	$(AR) $(ARTAG) mpi_timer.a mpi_wrapper.o profile.o
	$(RM) -f *.o

mpi_wrapper.o : mpi_wrapper.cpp
	$(CPP) $(FLAGS) $(DEF) -c mpi_wrapper.cpp

profile.o : profile.cpp
	$(CPP) $(FLAGS) $(DEF) -c profile.cpp

clean :
	rm -f *.o	rm -f run

clean_all:
	rm -f mpi_record.*	rm -f *.o	rm -f run	rm -f mpi_timer.a
