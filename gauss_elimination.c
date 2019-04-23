#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void ini_array(float *arr, int numel, float var, float media) {

	int i, k;
	float temp, desv;

	desv = (float) sqrt((double) var);

	srand(time(NULL));

	for(i=0; i<numel; ++i){
		temp=0;
		for (k=0;k<100;k++) temp += (float) rand()/RAND_MAX;
		arr[i] = desv*sqrt((float) 3/25)*(temp-(float)50) + media;
	}

	return;

}

void triang(float *M, float *b, int numel) {

	int i, j, k;
	float xmu;

	// triangularización de M
	for(k=0; k<numel-1; ++k) {
		for(i=k+1; i<numel; ++i) {
			for(j=k; j<numel; ++j) {
				xmu = M[i*numel+k]/M[k*numel+k];
				M[i*numel+j] = M[i*numel+j] - xmu*M[k*numel+j];
			}
			b[i] = b[i] - xmu*b[k];
		}	
	}

	return;

}

void triang_imp(float *M, float *b, int numel) {

	int i, j, k;
	float xmu;

	// triangularizacion de M
	for(k=0; k<numel-1; ++k) {
		for(i=k+1; i<numel; ++i) {
			xmu = M[i*numel+k]/M[k*numel+k];
			for(j=k; j<numel; ++j) {
				M[i*numel+j] = M[i*numel+j] - xmu*M[k*numel+j];
			}
			b[i] = b[i] - xmu*b[k];
		}	
	}

	return;

}

void backsub(float *M, float *b, float *x, int numel) {

	int i, j;
	float temp;

	// solucion hacia atras
	x[numel-1] = b[numel-1]/M[(numel-1)*numel+numel-1];

	for(i=numel-2; i>-1; --i) {
		temp = b[i];
		for(j=i+1; j<numel; ++j) temp = temp - x[j]*M[i*numel+j];
        	x[i] = temp/M[i*numel+i];
    	}

	return;

}

int main() {

    int numel = 1024;
    clock_t start_t, end_t, total_t;

	// reserva de memoria
	float *M = (float *) calloc(numel*numel, sizeof(float));
	float *x = (float *) calloc(numel, sizeof(float));
	float *b = (float *) calloc(numel, sizeof(float));

    // inicializacion de M y b
	ini_array(M, numel*numel, 1.0, 0.0);
	ini_array(b, numel, 1.0, 0.0);

	// medicion del tiempo empieza ahora
	start_t = clock();

	triang(M, b, numel);

	//triang_imp(M, b, numel);

	backsub(M, b, x, numel);

	// medicion del tiempo termina ahora
	end_t = clock();
   
	total_t = end_t - start_t;

	printf("%.0f us\n",1000000*((float) total_t)/CLOCKS_PER_SEC);

	return 0;

}
