// /*
//  * Tema 2 ASC
//  * 2019 Spring
//  * Catalin Olaru / Vlad Spoiala
//  */
// #include "utils.h"

// /* 
//  * Add your BLAS implementation here
//  */
// double* my_solver(int N, double *A, double *B) {
// 	printf("BLAS SOLVER\n");
// 	return NULL;
// }
/*
 * Tema 2 ASC
 * 2019 Spring
 * Catalin Olaru / Vlad Spoiala
 */
#include "utils.h"
#include "cblas.h"

/* 
 * Add your BLAS implementation here
 */
double* my_solver(int N, double *A, double *B) {
	printf("BLAS SOLVER\n");
	int i, j;

	double *fm = malloc(N*N*sizeof(double));
	double *sm = malloc(N*N*sizeof(double));
	double *C = malloc(N*N*sizeof(double));
	cblas_sgemm('T', 'N',  N, N, N, 1.0, A, N, B, N, 0, fm, N);
	cblas_sgemm('N', 'T',  N, N, N, 1.0, A, N, B, N, 0, sm, N);
	
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			*(C+i*N+j) = *(fm+i*N+j) + *(sm+i*N+j);
		}
	}
	free(fm);
	free(sm);
	return C;
}