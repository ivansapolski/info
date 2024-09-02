#include <stdio.h>
#include <stdlib.h>

/*Cree un programa que permita reservar memoria para n valores enteros. 
Luego cargar los n valores, imprimirlos y liberar la memoria.*/

int main(  ) {
	
	int cant=0,i=0;
	int *ptr;
	
	printf("ingrese la cantidad de numeros que desea reservar en la memoria: \n");
	scanf("%d",&cant);
	
	ptr = (int*) malloc(sizeof(int)*cant);
	
	printf("\nIngrese los valores:\n");
	for(i=0;i<cant;i++){
		
		scanf("%d",ptr+i);
		
	}
	
	printf("\nLos valores son: ");
	for(i=0;i<cant;i++){
		
		printf("%d \t ",*(ptr+i));
		
	}
	
	free(ptr);
	
	return 0;
}

