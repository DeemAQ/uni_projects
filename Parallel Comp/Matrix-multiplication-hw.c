#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 250 // edit this number to overcome the segmentation fault

int printMatrix(double matrix[N][N]); // print matrix function

int main(int argc, char *argv[]) {
	
    omp_set_num_threads(16);//set the number of threads here
    int i, j, k;
    double sum;
    double start[10], end[10], elapsed[10], average = 0.0; // used for timing
    double A[N][N], B[N][N], C[N][N];
    
	//initlizing the matrices 
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = j*1;
            B[i][j] = i*j+2;
			C[i][j] = 0; 
        }
    }
	
	
	//do not use this if N is large 
	/*
	//printing matrix A
	printf("Matrix A \n");
	printMatrix(A);
	//printing matrix B
	printf("Matrix B \n");
	printMatrix(B);
	*/
	
	
    for(int t=0; t<10;t++)// this loop is to run the multiplication 10 times
    {
    
        start[t] = omp_get_wtime(); //start time measurement
		
		//matrix multiplication
		// #pragma omp parallel for private(i, j, k, sum) shared(A, B, C)
		// #pragma omp parallel for collapse(2) private(i, j, k, sum) shared(A, B, C)
        for (i = 0; i < N; i++) {
        	// #pragma omp parallel for private(j, k, sum) shared(i, A, B, C)
            for (j = 0; j < N; j++) {
                sum = 0;
                for (k=0; k < N; k++) {
                    sum += A[i][k]*B[k][j];
                }
                C[i][j] = sum;
            }
        }// end of matrix multiplication 

        end[t] = omp_get_wtime(); //end time measurement
        elapsed[t] = end[t]-start[t]; // calculate the time
        printf("Time of computation for %d: %f seconds\n", t,elapsed[t]);

        
		
		
    }// end of the 10 runs loop
	
	//do not use this if N is large 
	/*
	//printing matrix C
	printf("Matrix C \n");
	printMatrix(C);
	*/
	
	//calculate the average time
    for(i=0;i<10;i++)
    {
        average += elapsed[i];
    }
    average = average/10;
    printf("The average time of computation: %f seconds\n",average);
	 
	 
        return(0);
}

//print matrix function
int printMatrix(double matrix[N][N]){
	
	for (int row=0; row< N; row++)
	{
		for(int column=0; column< N; column++)
		{
			printf("%1.0f     ", matrix[row][column]);
		}
		printf("\n");
	}
	return(0);
}