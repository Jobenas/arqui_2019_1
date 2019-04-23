#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void asmFloatInnerProd(float *v1, float *v2, int N, float *ip);
void cFloatInnerProd(float *v1, float *v2, int N, float *ip);

int main()
{
	clock_t start_t, end_t, total_t_c, total_t_asm;

	float *v1, *v2, ipC, ipAsm;
	int N = 1024;

	v1 = malloc(N * sizeof(float));
	v2 = malloc(N * sizeof(float));

	for(int i=0; i < N; i++)
	{
		v1[i] = (float)i;
		v2[i] = (float)i;
	}

	start_t = clock();
	cFloatInnerProd(v1, v2, N, &ipC);
	end_t = clock();
	total_t_c = end_t - start_t;

	start_t = clock();
	asmFloatInnerProd(v1, v2, N, &ipAsm);
	end_t = clock();
	total_t_asm = end_t - start_t;


	printf("resultado en C: %f\nresultado en ASM: %f\n",ipC, ipAsm);

	printf("Tiempo total para codigo en C: %.0fus\n", 1000000*((float) total_t_c)/CLOCKS_PER_SEC);
	printf("Tiempo total para codigo en ASM: %.0fus\n", 1000000*((float) total_t_asm)/CLOCKS_PER_SEC);

	return 0;
}

void cFloatInnerProd(float *v1, float *v2, int N, float *ip)
{
	float sum = 0;
	for(int i=0; i < N; i++)
	{
		sum += v1[i] * v2[i];
	}

	ip[0] = sum;
}