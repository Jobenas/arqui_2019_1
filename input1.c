#include <stdio.h>
#include <stdlib.h>

int n = 20;

int main()
{
    float *vals;
    int size;
    int i = 0;
    int flag = 0;

    vals = malloc(n * sizeof(float));

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

    size = i;

    printf("\nCantidad de Valores ingresados: %d\n", size);
    printf("\nValores ingresados:\n");
    for(i=0;i<size;i++)
    {
        printf("%f\n",*(vals+i));
    }

    return 0;
}