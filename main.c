//Code modified from:
//https://codereview.stackexchange.com/questions/70816/printing-out-all-possible-combination-of-printable-ascii-7-bit-characters-to-std

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BYTE_SIZE 7
#define MAX_BIT_SIZE 56

typedef unsigned long long int UINT64;
typedef double FLOAT;

void length1()
{
	unsigned char guess[] = {'\x00', '\0'};
	unsigned char key[] = {'\xff', '\0'};
	int i;
	FILE * DES_FILE;
	system("openssl rand 1 > DES.key");            
	DES_FILE = fopen("DES.key", "r");              
	fscanf(DES_FILE, "%s", key);                   
	key[1] = '\0';                                 
	fclose(DES_FILE);	

	//TIME SETUP
	UINT64 microsecs=0, millisecs=0;
	FLOAT temp, fstart, fnow;
	struct timespec startTime, now;
	clock_gettime(CLOCK_MONOTONIC, &startTime);
	fstart = (FLOAT)startTime.tv_sec  + (FLOAT)startTime.tv_nsec / 1000000000.0;

	for(i = 0; i < 256; i++)
	{
		if(strcmp(guess, key) == 0)
		{
			printf("%s = %s\n", guess, key);
			clock_gettime(CLOCK_MONOTONIC, &now);
			fnow = (FLOAT)now.tv_sec  + (FLOAT)now.tv_nsec / 1000000000.0;
			printf("program took %f seconds\n", fnow-fstart);


			return;
		}

		guess[0] += 1;
	}
}

void length2()
{
	unsigned char guess[] = {'\x00', '\x00', '\0'};
	unsigned char key[] = {'\xff', '\xff', '\0'};
	/*	FILE * DES_FILE;
		system("openssl rand 2 > DES.key");
		DES_FILE = fopen("DES.key", "r");            
		fscanf(DES_FILE, "%s", key);            
		key[2] = '\0';            
		fclose(DES_FILE);*/
	int i, j;
	/*//TIME SETUP
	  UINT64 microsecs=0, millisecs=0;
	  FLOAT temp, fstart, fnow;
	  struct timespec startTime, now;
	  clock_gettime(CLOCK_MONOTONIC, &startTime);
	  fstart = (FLOAT)startTime.tv_sec  + (FLOAT)startTime.tv_nsec / 1000000000.0;
	 */
	for(i = 0; i < 256; i++)
	{

		for(j = 0; j < 256; j++)
		{
			if(strcmp(guess, key) == 0)
			{
				printf("%s = %s\n", guess, key);
				/*clock_gettime(CLOCK_MONOTONIC, &now);
				  fnow = (FLOAT)now.tv_sec  + (FLOAT)now.tv_nsec / 1000000000.0;
				  printf("program took %f seconds\n", fnow-fstart);

				 */
				return;
			}

			guess[1] += 1;
		}

		guess[0] += 1;
	}
}


void length3()
{
	unsigned char guess[] = {'\x00', '\x00', '\x00', '\0'};
	unsigned char key[] = {'\xff', '\xff', '\xff', '\0'};
	FILE * DES_FILE;	
	system("openssl rand 3 > DES.key");
	DES_FILE = fopen("DES.key", "r");            
	fscanf(DES_FILE, "%s", key);            
	key[3] = '\0';            
	fclose(DES_FILE);
	int i, j, k;
	//TIME SETUP
	UINT64 microsecs=0, millisecs=0;
	FLOAT temp, fstart, fnow;
	struct timespec startTime, now;
	clock_gettime(CLOCK_MONOTONIC, &startTime);
	fstart = (FLOAT)startTime.tv_sec  + (FLOAT)startTime.tv_nsec / 1000000000.0;

	for(i = 0; i < 256; i++)
	{

		for(j = 0; j < 256; j++)
		{
			for(k = 0; k < 256; k++)
			{
				if(strcmp(guess, key) == 0)
				{
					printf("%s = %s\n", guess, key);
					clock_gettime(CLOCK_MONOTONIC, &now);
					fnow = (FLOAT)now.tv_sec  + (FLOAT)now.tv_nsec / 1000000000.0;
					printf("program took %f seconds\n", fnow-fstart);


					return;
				}

				guess[2] += 1;
			}

			guess[2] = '\x00';

			guess[1] += 1;
		}

		guess[1] = '\x00';

		guess[0] += 1;
	}
}

void length4()
{
	unsigned char guess[] = {'\x00', '\x00', '\x00', '\x00', '\0'};
	unsigned char key[] = {'\xff', '\xff', '\xff', '\xff', '\0'};
	FILE * DES_FILE;	
	system("openssl rand 4 > DES.key");
	DES_FILE = fopen("DES.key", "r");            
	fscanf(DES_FILE, "%s", key);            
	key[4] = '\0';            
	fclose(DES_FILE);
	int i, j, k, l;
	//TIME SETUP
	UINT64 microsecs=0, millisecs=0;
	FLOAT temp, fstart, fnow;
	struct timespec startTime, now;
	clock_gettime(CLOCK_MONOTONIC, &startTime);
	fstart = (FLOAT)startTime.tv_sec  + (FLOAT)startTime.tv_nsec / 1000000000.0;


	for(i = 0; i < 256; i++)
	{

		for(j = 0; j < 256; j++)
		{
			for(k = 0; k < 256; k++)
			{
				for(l = 0; l < 256; l++)
				{
					if(strcmp(guess, key) == 0)
					{
						printf("%s = %s\n", guess, key);
						printf("%s = %s\n", guess, key);
						clock_gettime(CLOCK_MONOTONIC, &now);
						fnow = (FLOAT)now.tv_sec  + (FLOAT)now.tv_nsec / 1000000000.0;
						printf("program took %f seconds\n", fnow-fstart);

						return;
					}
					guess[3] += 1;
				}
				guess[2] += 1;
			}
			guess[1] += 1;
		}

		guess[0] += 1;
	}

}

void length5()
{
	unsigned char guess[] = {'\x00', '\x00', '\x00', '\x00', '\x00', '\0'};
	unsigned char key[] = {'\xff', '\xff', '\xff', '\xff', '\xff', '\0'};
	FILE * DES_FILE;	
	system("openssl rand 5 > DES.key");
	DES_FILE = fopen("DES.key", "r");            
	fscanf(DES_FILE, "%s", key);            
	key[5] = '\0';            
	fclose(DES_FILE);
	int i, j, k, l, m;
	//TIME SETUP
UINT64 microsecs=0, millisecs=0;
	FLOAT temp, fstart, fnow;
	struct timespec startTime, now;
	clock_gettime(CLOCK_MONOTONIC, &startTime);
	fstart = (FLOAT)startTime.tv_sec  + (FLOAT)startTime.tv_nsec / 1000000000.0;


	for(i = 0; i < 256; i++)
	{

		for(j = 0; j < 256; j++)
		{
			for(k = 0; k < 256; k++)
			{
				for(l = 0; l < 256; l++)
				{
					for(m = 0; m < 256; m++)
					{
						if(strcmp(guess, key) == 0)
						{
							printf("%s = %s\n", guess, key);
							clock_gettime(CLOCK_MONOTONIC, &now);
							fnow = (FLOAT)now.tv_sec  + (FLOAT)now.tv_nsec / 1000000000.0;
							printf("program took %f seconds\n", fnow-fstart);

							return;
						}
						guess[4] += 1;
					}
					guess[3] += 1;
				}
				guess[2] += 1;
			}
			guess[1] += 1;
		}
		guess[0] += 1;
	}

}


void main(int argc, char * argv[])
{
	if(argc != 2)
	{
		fprintf(stderr, "Please enter a value when runnin program\n");
		exit(1);
	}

	int I = atoi(argv[1]);
	if(I == 1)
	{
		length1();
	}
	else if(I == 2)
	{
		length2();	
	}
	else if(I == 3)
	{
		length3();
	}
	else if(I == 4)
	{
		length4();
	}
	else if(I == 5)
	{
		length5();
	}
	else
	{
		fprintf(stderr, "Invalid number, Must be 1-7, now exiting\n");
		exit(1);
	}
}
