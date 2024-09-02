#include <stdio.h>
#include <stdlib.h>

/*Cree un programa que permita reservar memoria para n caracteres (char). 
Luego cargar los n caracteres e imprimirlos por pantalla.*/


int main( ) {
	
	char *ptr;
	int cantidad=0,i=0;
	
	printf("ingrese la cantidad de caracteres que desea reservar en la memoria \n");
	scanf("%d",&cantidad);
	
	ptr = (char*) malloc(sizeof(char)*cantidad);
	
	printf("ingrese los valores : \n");
	for(i=0;i<cantidad;i++){
		
		scanf(" %c",(ptr+i));
	}
	
	printf("los valores son: \n");
	for(i=0;i<cantidad;i++){
		
		printf(" %c",*(ptr+i));
		
	}
	
	
	free(ptr);
	
	return 0;
}

