#include <mpi.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ASCII_SIZE 256

typedef double FLOAT;

int length1()
{
        //PARALLEL SECTION
        int comm_sz;
        int my_rank;
        unsigned long long int sub_length;
        MPI_Init(NULL,NULL);
        MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);                                                                                   
        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

        sub_length = MAX_ASCII_SIZE / comm_sz;
        int residual;
        int residualTotal;
        //USING 16 BECAUSE IT REPRESENTS REMAINDER, SHOULD SPLIT THE 16 RESIDUAL TO 16 DIFFERENT NODES
        if(my_rank >= comm_sz - (MAX_ASCII_SIZE % comm_sz))
        {
                residualTotal = MAX_ASCII_SIZE % comm_sz;
                residual = 1;
        }
        else
        {
                residualTotal = 0;
                residual = 0;
        }

        unsigned long long int j;
        int count = 0;
        unsigned char guess[] = {'\x00', '\0'}; 
        unsigned char key[] = {'\xff', '\0'};
        /*FILE * DES_FILE;
        //KEY GENERATION
        if(my_rank == 0)
        {
                system("openssl rand 1 > DES.key"); 
                DES_FILE = fopen("DES.key", "r");
                fscanf(DES_FILE, "%s", key);
                key[1] = '\0';
                fclose(DES_FILE);
        }
        MPI_Bcast(&key, 2, MPI_CHAR, 0, MPI_COMM_WORLD);*/
        //TIME SETUP
        FLOAT fstart, fnow;
        struct timespec startTime, now;
        clock_gettime(CLOCK_MONOTONIC, &startTime);
        fstart = (FLOAT)startTime.tv_sec  + (FLOAT)startTime.tv_nsec / 1000000000.0;

        for(j = my_rank*sub_length; j < sub_length*(my_rank+1) + residual; j++)
        {
                if(count == 1)
                {
                        guess[0] += j + residualTotal;
                }
                else
                {
                        guess[0] += j;
                }

                if(strcmp(guess, key) == 0)
                {
                        printf("%s = %s\n", guess, key);
                        clock_gettime(CLOCK_MONOTONIC, &now);
                        fnow = (FLOAT)now.tv_sec  + (FLOAT)now.tv_nsec / 1000000000.0;
                        printf("program took %f seconds\n", fnow-fstart);
                        MPI_Abort(MPI_COMM_WORLD, 0);
                        MPI_Finalize();
                        return 0;
                }
                guess[0] = '\x00';
                count++;
        }   

        MPI_Finalize();
        return 1;
}


int length2()
{
        //PARALLEL SECTION
        int comm_sz;
        int my_rank;
        unsigned long long int sub_length;
        MPI_Init(NULL,NULL);
        MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);                                                                                   
        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

        sub_length = MAX_ASCII_SIZE / comm_sz;
        int residual;
        int residualTotal;
        //USING 16 BECAUSE IT REPRESENTS REMAINDER, SHOULD SPLIT THE 16 RESIDUAL TO 16 DIFFERENT NODES
        if(my_rank >= comm_sz - (MAX_ASCII_SIZE % comm_sz))
        {
                residualTotal = MAX_ASCII_SIZE % comm_sz;
                residual = 1;
        }
        else
        {
                residualTotal = 0;
                residual = 0;
        }

        unsigned long long int j, k;
        int count = 0;
        unsigned char guess[] = {'\x00', '\x00', '\0'}; 
        unsigned char key[] = {'\xff', '\xff', '\0'};
        /*FILE * DES_FILE;
        //KEY GENERATION
        if(my_rank == 0)
        {
                system("openssl rand 2 > DES.key"); 
                DES_FILE = fopen("DES.key", "r");
                fscanf(DES_FILE, "%s", key);
                key[2] = '\0';
                fclose(DES_FILE);
        }
        MPI_Bcast(&key, 3, MPI_CHAR, 0, MPI_COMM_WORLD);
        */
        //TIME SETUP
        FLOAT fstart, fnow;
        struct timespec startTime, now;
        clock_gettime(CLOCK_MONOTONIC, &startTime);
        fstart = (FLOAT)startTime.tv_sec  + (FLOAT)startTime.tv_nsec / 1000000000.0;

        for(j = my_rank*sub_length; j < sub_length*(my_rank+1) + residual; j++)
        {
                if(count == 1)
                {
                        guess[0] += j + residualTotal;
                }
                else
                {
                        guess[0] += j;
                }

                for(k = 0; k < MAX_ASCII_SIZE; k++)
                {

                        if(strcmp(guess, key) == 0)
                        {
                                printf("%s = %s\n", guess, key);
                                clock_gettime(CLOCK_MONOTONIC, &now);
                                fnow = (FLOAT)now.tv_sec  + (FLOAT)now.tv_nsec / 1000000000.0;
                                printf("program took %f seconds\n", fnow-fstart);
                                MPI_Abort(MPI_COMM_WORLD, 0);
                                MPI_Finalize();
                                return 0;
                        }
                        guess[1] += 1;
                }
                guess[1] = '\x00';
                guess[0] = '\x00';
                count++;
        }   

        MPI_Finalize();
        return 1;
}


int length3()
{
        //PARALLEL SECTION
        int comm_sz;
        int my_rank;
        unsigned long long int sub_length;
        MPI_Init(NULL,NULL);
        MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);                                                                                   
        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

        sub_length = MAX_ASCII_SIZE / comm_sz;
        int residual;
        int residualTotal;
        //USING 16 BECAUSE IT REPRESENTS REMAINDER, SHOULD SPLIT THE 16 RESIDUAL TO 16 DIFFERENT NODES
        if(my_rank >= comm_sz - (MAX_ASCII_SIZE % comm_sz))
        {
                residualTotal = MAX_ASCII_SIZE % comm_sz;
                residual = 1;
        }
        else
        {
                residualTotal = 0;
                residual = 0;
        }

        unsigned long long int i, j, k;
        int count = 0;
        unsigned char guess[] = {'\x00', '\x00', '\x00', '\0'}; 
        unsigned char key[] = {'\xff', '\xff', '\xff', '\0'};
        /*FILE * DES_FILE;
        //KEY GENERATION
        if(my_rank == 0)
        {
                system("openssl rand 3 > DES.key"); 
                DES_FILE = fopen("DES.key", "r");
                fscanf(DES_FILE, "%s", key);
                key[3] = '\0';
                fclose(DES_FILE);
        }
        MPI_Bcast(&key, 4, MPI_CHAR, 0, MPI_COMM_WORLD);*/
        //TIME SETUP
        FLOAT fstart, fnow;
        struct timespec startTime, now;
        clock_gettime(CLOCK_MONOTONIC, &startTime);
        fstart = (FLOAT)startTime.tv_sec  + (FLOAT)startTime.tv_nsec / 1000000000.0;

        for(j = my_rank*sub_length; j < sub_length*(my_rank+1) + residual; j++)
        {
                if(count == 1)
                {
                        guess[0] += j + residualTotal;
                }
                else
                {
                        guess[0] += j;
                }

                for(k = 0; k < MAX_ASCII_SIZE; k++)
                {
                        for(i = 0; i < MAX_ASCII_SIZE; i++)
                        {

                                if(strcmp(guess, key) == 0)
                                {
                                        printf("%s = %s\n", guess, key);
                                        clock_gettime(CLOCK_MONOTONIC, &now);
                                        fnow = (FLOAT)now.tv_sec  + (FLOAT)now.tv_nsec / 1000000000.0;
                                        printf("program took %f seconds\n", fnow-fstart);
                                        MPI_Abort(MPI_COMM_WORLD, 0);
                                        MPI_Finalize();
                                        return 0;
                                }
                                guess[2] += 1;
                        }
                        guess[2] = '\x00';
                        guess[1] += 1;
                }
                guess[1] = '\x00';
                guess[0] = '\x00';
                count++;
        }   

        MPI_Finalize();
        return 1;
}


int length4()
{
        //PARALLEL SECTION
        int comm_sz;
        int my_rank;
        unsigned long long int sub_length;
        MPI_Init(NULL,NULL);
        MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);                                                                                   
        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

        sub_length = MAX_ASCII_SIZE / comm_sz;
        int residual;
        int residualTotal;
        //USING 16 BECAUSE IT REPRESENTS REMAINDER, SHOULD SPLIT THE 16 RESIDUAL TO 16 DIFFERENT NODES
        if(my_rank >= comm_sz - (MAX_ASCII_SIZE % comm_sz))
        {
                residualTotal = MAX_ASCII_SIZE % comm_sz;
                residual = 1;
        }
        else
        {
                residualTotal = 0;
                residual = 0;
        }

        unsigned long long int i, j, k, l;
        int count = 0;
        unsigned char guess[] = {'\x00', '\x00', '\x00', '\x00', '\0'}; 
        unsigned char key[] = {'\xff', '\xff', '\xff', '\xff', '\0'};
        /*FILE * DES_FILE;
        //KEY GENERATION
        if(my_rank == 0)
        {
                system("openssl rand 4 > DES.key"); 
                DES_FILE = fopen("DES.key", "r");
                fscanf(DES_FILE, "%s", key);
                key[4] = '\0';
                fclose(DES_FILE);
        }
        MPI_Bcast(&key, 5, MPI_CHAR, 0, MPI_COMM_WORLD);*/
        //TIME SETUP
        FLOAT fstart, fnow;
        struct timespec startTime, now;
        clock_gettime(CLOCK_MONOTONIC, &startTime);
        fstart = (FLOAT)startTime.tv_sec  + (FLOAT)startTime.tv_nsec / 1000000000.0;

        for(j = my_rank*sub_length; j < sub_length*(my_rank+1) + residual; j++)
        {
                if(count == 1)
                {
                        guess[0] += j + residualTotal;
                }
                else
                {
                        guess[0] += j;
                }

                for(k = 0; k < MAX_ASCII_SIZE; k++)
                {
                        for(i = 0; i < MAX_ASCII_SIZE; i++)
                        {
                                for(l = 0; l < MAX_ASCII_SIZE; l++)
                                {

                                        if(strcmp(guess, key) == 0)
                                        {
                                                printf("%s = %s\n", guess, key);
                                                clock_gettime(CLOCK_MONOTONIC, &now);
                                                fnow = (FLOAT)now.tv_sec  + (FLOAT)now.tv_nsec / 1000000000.0;
                                                printf("program took %f seconds\n", fnow-fstart);
                                                MPI_Abort(MPI_COMM_WORLD, 0);
                                                MPI_Finalize();
                                                return 0;

                                        }

                                        guess[3] += 1;

                                }
                                guess[3] = '\x00';
                                guess[2] += 1;
                        }
                        guess[2] = '\x00';
                        guess[1] += 1;
                }
                guess[1] = '\x00';
                guess[0] = '\x00';
                count++;
        }   


        MPI_Finalize();
        return 1;
}


int length5()
{
        //PARALLEL SECTION
        int comm_sz;
        int my_rank;
        unsigned long long int sub_length;
        MPI_Init(NULL,NULL);
        MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);                                                                                   
        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

        sub_length = MAX_ASCII_SIZE / comm_sz;
        int residual;
        int residualTotal;
        //USING 16 BECAUSE IT REPRESENTS REMAINDER, SHOULD SPLIT THE 16 RESIDUAL TO 16 DIFFERENT NODES
        if(my_rank >= comm_sz - (MAX_ASCII_SIZE % comm_sz))
        {
                residualTotal = MAX_ASCII_SIZE % comm_sz;
                residual = 1;
        }
        else
        {
                residualTotal = 0;
                residual = 0;
        }

        unsigned long long int i, j, k, l, m;
        int count = 0;
        unsigned char guess[] = {'\x00', '\x00', '\x00', '\x00', '\x00', '\0'}; 
        unsigned char key[] = {'\xff', '\xff', '\xff', '\xff', '\xff', '\0'};
        /*FILE * DES_FILE;
        //KEY GENERATION
        if(my_rank == 0)
        {
                system("openssl rand 5 > DES.key"); 
                DES_FILE = fopen("DES.key", "r");
                fscanf(DES_FILE, "%s", key);
                key[5] = '\0';
                fclose(DES_FILE);
        }
        MPI_Bcast(&key, 6, MPI_CHAR, 0, MPI_COMM_WORLD);*/
        //TIME SETUP
        FLOAT fstart, fnow;
        struct timespec startTime, now;
        clock_gettime(CLOCK_MONOTONIC, &startTime);
        fstart = (FLOAT)startTime.tv_sec  + (FLOAT)startTime.tv_nsec / 1000000000.0;

        for(j = my_rank*sub_length; j < sub_length*(my_rank+1) + residual; j++)
        {
                if(count == 1)
                {
                        guess[0] += j + residualTotal;
                }
                else
                {
                        guess[0] += j;
                }

                for(k = 0; k < MAX_ASCII_SIZE; k++)
                {
                        for(i = 0; i < MAX_ASCII_SIZE; i++)
                        {
                                for(l = 0; l < MAX_ASCII_SIZE; l++)
                                {
                                        for(m = 0; m < MAX_ASCII_SIZE; m++)
                                        {

                                                if(strcmp(guess, key) == 0)
                                                {
                                                        printf("%s = %s\n", guess, key);
                                                        clock_gettime(CLOCK_MONOTONIC, &now);
                                                        fnow = (FLOAT)now.tv_sec  + (FLOAT)now.tv_nsec / 1000000000.0;
                                                        printf("program took %f seconds\n", fnow-fstart);
                                                        MPI_Abort(MPI_COMM_WORLD, 0);
                                                        MPI_Finalize();
                                                        return 0;

                                                }
                                                guess[4] += 1;
                                        }

                                        guess[4] = '\x00';
                                        guess[3] += 1;

                                }
                                guess[3] = '\x00';
                                guess[2] += 1;
                        }
                        guess[2] = '\x00';
                        guess[1] += 1;
                }
                guess[1] = '\x00';
                guess[0] = '\x00';
                count++;
        }   


        MPI_Finalize();
        return 1;
}

int length6()
{
        //PARALLEL SECTION
        int comm_sz;
        int my_rank;
        unsigned long long int sub_length;
        MPI_Init(NULL,NULL);
        MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);                                                                                   
        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

        sub_length = MAX_ASCII_SIZE / comm_sz;
        int residual;
        int residualTotal;
        //USING 16 BECAUSE IT REPRESENTS REMAINDER, SHOULD SPLIT THE 16 RESIDUAL TO 16 DIFFERENT NODES
        if(my_rank >= comm_sz - (MAX_ASCII_SIZE % comm_sz))
        {
                residualTotal = MAX_ASCII_SIZE % comm_sz;
                residual = 1;
        }
        else
        {
                residualTotal = 0;
                residual = 0;
        }

        unsigned long long int i, j, k, l, m, n;
        int count = 0;
        unsigned char guess[] = {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\0'}; 
        unsigned char key[] = {'\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\0'};
        /*FILE * DES_FILE;
        //KEY GENERATION
        if(my_rank == 0)
        {
                system("openssl rand 6 > DES.key"); 
                DES_FILE = fopen("DES.key", "r");
                fscanf(DES_FILE, "%s", key);
                key[6] = '\0';
                fclose(DES_FILE);
        }
        MPI_Bcast(&key, 7, MPI_CHAR, 0, MPI_COMM_WORLD); */
        //TIME SETUP
        FLOAT fstart, fnow;
        struct timespec startTime, now;
        clock_gettime(CLOCK_MONOTONIC, &startTime);
        fstart = (FLOAT)startTime.tv_sec  + (FLOAT)startTime.tv_nsec / 1000000000.0;

        for(j = my_rank*sub_length; j < sub_length*(my_rank+1) + residual; j++)
        {
                if(count == 1)
                {
                        guess[0] += j + residualTotal;
                }
                else
                {
                        guess[0] += j;
                }

                for(k = 0; k < MAX_ASCII_SIZE; k++)
                {
                        for(i = 0; i < MAX_ASCII_SIZE; i++)
                        {
                                for(l = 0; l < MAX_ASCII_SIZE; l++)
                                {
                                        for(m = 0; m < MAX_ASCII_SIZE; m++)
                                        {
                                                for(n = 0; n < MAX_ASCII_SIZE; n++)
                                                {
                                                        if(strcmp(guess, key) == 0)
                                                        {
                                                                printf("%s = %s\n", guess, key);
                                                                clock_gettime(CLOCK_MONOTONIC, &now);
                                                                fnow = (FLOAT)now.tv_sec  + (FLOAT)now.tv_nsec / 1000000000.0;
                                                                printf("program took %f seconds\n", fnow-fstart);
                                                                MPI_Abort(MPI_COMM_WORLD, 0);
                                                                MPI_Finalize();
                                                                return 0;

                                                        }
                                                        guess[5] += 1;
                                                }
                                                guess[5] = '\x00';
                                                guess[4] += 1;
                                        }

                                        guess[4] = '\x00';
                                        guess[3] += 1;

                                }
                                guess[3] = '\x00';
                                guess[2] += 1;
                        }
                        guess[2] = '\x00';
                        guess[1] += 1;
                }
                guess[1] = '\x00';
                guess[0] = '\x00';
                count++;
        }   


        MPI_Finalize();
        return 1;
}

int main(int argc, char * argv[])
{
        int length = atoi(argv[1]);

        if(length == 1) //8 bits
        {
                length1();
        }
        else if(length == 2) //16 bits
        {
                length2();
        }
        else if(length == 3) //24 bits
        {
                length3();
        }
        else if(length == 4) //32 bits
        {
                length4();
        }
        else if(length == 5) //40 bits
        {
                length5();
        }
        else if(length == 6) //48 bits
        {
                length6();
        } 
        else if(length == 7) //56 bits DES KEY
        {
                //length7();
        }
        else
        {
                fprintf(stderr, "Enter a number 1 through 7 in command line\n");
                return 1;
        }

        return 0;
}
