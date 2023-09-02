INCLUDE_DIRS = -I/opt/intel/compilers_and_libraries_2020.0.166/linux/mpi/intel64/include/
LIB_DIRS = -L/opt/intel/compilers_and_libraries_2020.0.166/linux/mpi/intel64/lib/debug -L/opt/intel/compilers_and_libraries_2020.0.166/linux/mpi/intel64/lib
#LIB_DIRS = -L/opt/intel/compilers_and_libraries_2020.0.166/linux/mpi/intel64/lib/release -L/opt/intel/compilers_and_libraries_2020.0.166/linux/mpi/intel64/lib
CC = mpicc
CXX = mpicxx

CDEFS=
CFLAGS= -o3 -Wall $(INCLUDE_DIRS) $(CDEFS)
LIBS=

PRODUCT= mpiDEScracker mpiWorstCase 

HFILES= 
CFILES= mpiDEScracker.c mpiWorstCase.c
SRCS= ${HFILES} ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	${PRODUCT}

clean:
	-rm -f *.o *.NEW *~
	-rm -f ${PRODUCT} ${DERIVED} ${GARBAGE}

mpiDEScracker: mpiDEScracker.c
	$(CC) $(CFLAGS) -o $@ mpiDEScracker.c $(LIB_DIRS) -lm
mpiWorstcase: mpiWorstCase.c
	$(CC) $(CFLAGS) -o $@ mpiWorstCase.c $(LIB_DIRS) -lm
