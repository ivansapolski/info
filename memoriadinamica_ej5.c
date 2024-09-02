#include <stdio.h>
#include <stdlib.h>

/* Cree un programa que permita reservar memoria para n caracteres (char). 
Luego cargar los n caracteres e imprimirlos por pantalla. El usuario desea agregar 
mas caracteres, por lo que ingresa la n cantidad de caracteres a agregar. Luego 
cargar los n caracteres, imprimirlos y finalmente liberar la memoria.

5. Modificar el codigo para crear una funcion mostrar los valores. 
*/

void mostrarvalores(char*,int);

int main( ) {
	
	char *ptr;
	int i=0,cant=0,newcant=0;
	
	printf("Ingrese la cantidad de caracteres que desea reservar: \n");
	scanf("%d",&cant);
	
	ptr = (char*) malloc(sizeof(char)*cant);
	
	if(ptr == NULL){
		printf("ERROR AL RESERVAR MEMORIA.");
		return 1;
	}
	
	printf("Ingrese los %d valores:",cant);
	for(i=0;i<cant;i++){
		
		scanf(" %c",ptr+i);
		
	}
	
	mostrarvalores(ptr,cant);
	
	printf("\nIngrese la nueva cantidad de caracteres que deseas agregar: : \n");
	scanf("%d",&newcant);
	
	ptr = (char*) realloc(ptr,sizeof(char)*(cant+newcant));	//cuando es realloc pasarle el ptr tmb (ptr , cant);
	
	if(ptr == NULL){
		printf("ERROR AL RESERVAR MEMORIA.");
		return 1;
	}
	
	printf("Ingrese los %d valores nuevos:",newcant);
	for(i=0;i<newcant;i++){
		
		scanf(" %c",ptr+i+cant);
		
	}
	
	mostrarvalores(ptr,(cant+newcant));
	
	free(ptr);
	
	return 0;
}

void mostrarvalores (char*ptr ,int cant){
	
	
	printf("Los %d valores son:",cant);
	for(int i=0;i<cant;i++){
		
		printf(" %c",*(ptr+i));
		
	}
	
}
