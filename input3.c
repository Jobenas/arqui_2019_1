#include <stdio.h>
#include <stdlib.h>

int n = 20;

extern void asmAverage(float *array, int size, float *res);
void cAvg(float *array, int size, float *res);

int main()
{
    //float *vals;
    float vals[n];
    int size;
    int i = 0;
    int flag = 0;

    float cResult, asmResult;

    //vals = malloc(n * sizeof(float));

    while (flag == 0 && i < 20)
    {
    	printf("Ingrese un numero (ingrese 0 para salir)\n");
        scanf("%f",(vals+i));
        if (vals[i] == 0)
        {
        	flag = 1;
        }
        i++;
    }

    if(i < 20)
    {
        size = i - 1;    
    }
    else
    {
        size = i;   
    }
      

    printf("\nCantidad de Valores ingresados: %d\n", size);
    printf("\nValores ingresados:\n");
    for(i=0;i<size;i++)
    {
        printf("%f\n",*(vals+i));
    }

    cAvg(vals, size, &cResult);

    printf("\nEl promedio es: %f\n",cResult);

    asmAverage(vals, size, &asmResult);

    printf("\nEl promedio en ASM es: %f\n", asmResult);

    return 0;
}

void cAvg(float *array, int size, float *res)
{
    float accum = 0;

    for(int i=0; i<size; i++)
    {
        accum += array[i];
    }

    res[0] = accum/(float)size;
}