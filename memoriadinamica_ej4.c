#include <stdio.h>
#include <stdlib.h>

/*4.Cree un programa que permita reservar memoria para n caracteres (char). 
Luego cargar los n caracteres e imprimirlos por pantalla. 
-El usuario desea agregar mas caracteres, por lo que ingresa la n cantidad de caracteres a agregar. 
Luego cargar los n caracteres, imprimirlos y finalmente liberar la memoria.*/

int main(  ) {

	char *ptr;
	int cant=0,i=0,cantnew=0;
	
	printf("ingrese la cant de caracteres que desea reservar en la memoria \n");
	scanf("%d",&cant);
	
	ptr = (char*) malloc(sizeof(char)*cant);
	
	printf("Ingrese los valores de: \n");
	for(i=0;i<cant;i++){
		
		scanf(" %c",ptr+i);
		
	}
	
	printf("Los valores son: \n");
	for(i=0;i<cant;i++){
		
		printf(" %c\t",*(ptr+i));
		
	}
//
	printf(" \ningrese la cantidad de caracteres que desea agregar: \n");
	scanf("%d",&cantnew);
	
	ptr = (char*) realloc(ptr,sizeof(char)*(cant+cantnew));
	
	printf("\nIngrese los %d caracteres nuevos\n",cantnew);
	
	for(i=0;i<cantnew;i++){
		scanf(" %c",ptr+i+cant);
	}
	
	printf("Los valores totales son: ");
	for(i=0;i<(cantnew+cant);i++){
		printf(" %c",*(ptr+i));
	}
	
	free(ptr);
	
	return 0;
}

