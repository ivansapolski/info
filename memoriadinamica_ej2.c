#include <stdio.h>
#include <stdlib.h>

/*2.Cree un programa que permita reservar memoria para n valores decimales (float). 
Luego cargar los n valores, imprimirlos y liberar la memoria.*/


int main(  ) {
	
	float *ptr;
	int cant=0,i=0;
	
	printf("Ingrese la cantidad de numeros flotantes que desea reservar en la memoria \n");
	scanf("%d",&cant);
	
	ptr = (float*) malloc(sizeof(float)*cant);//reservar malloc
	
	printf("\nIngrese los valores:\n");
	for(i=0;i<cant;i++){
		
		scanf("%f",ptr+i);
		
	}
	
	printf("\nLos valores son: \n");
	
	for(i=0;i<cant;i++){
		
		printf("%.2f \t",*(ptr+i));
		
	}
	
	free(ptr);
	
	return 0;
}

