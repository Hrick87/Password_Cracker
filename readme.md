# What is this?

This program is a test of what I can do with the processing power of 240 cores
using mpi in order to crack the 56 bit DES key. I will attempt to iterate through each key
size and track speed up at each size until this isn’t viable because of time constraints.

## How can I use this?

The following commands can be used to compile and run the program. Beware that it was written with assumed access to a nanoPi cluster of 240 cores and access to the mpi c library. This project was purely experimental in nature and not intended for any end user. Some large modifications of the code as well as the compilation command would be necessary for your own home environment. 

INSTRUCTIONS TO COMPILE AND RUN

TO COMPILE main.c:
	“gcc main.c -o main”
TO RUN main.c:
	“./main <key length in bytes> (must be 1-7)”

TO COMPILE mpiDEScracker.c and mpiWorstCase.c:
	“make”
TO RUN mpiDEScracker.c:
	mpirun -np 240 -ppn 4  -f c1_hosts ./mpiDEScracker <key length in bytes> (must be 1-7, but note 7 was not implemented. It’s not viable)

TO RUN mpiWorstCase.c:
	mpirun -np 240 -ppn 4  -f c1_hosts ./mpiWorstCase <key length in bytes> 
(must be 1-7, but note 7 was not implemented. It’s not viable)

## More information

For a complete fully in depth look at the project, please refer to the included pdf titled [Research_Results.pdf](./Research_Results.pdf). Inside is runtime comparisons, explanations of the project in depth, and a brief explanation of openSSL encryption and des.key.