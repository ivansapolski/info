#include <stdio.h>
#include <stdlib.h>

/*7.Crear un programa que pregunte al usuario cuantos caracteres desea introducir, 
reserve espacio para dicho número de caracteres, le permita al usuario introducirlos 
desde teclado y luego mostrar por pantalla los valores. Luego, el programa pregunta 
cuántos caracteres desea agregar a la lista de elementos ya introducida, agrega espacio de memoria 
y solicita el ingreso de los nuevos valores. Por último, mostrar la lista resultante. 
Utilizar funciones*/

void cargar_nuevos(char*,int,int);
void cargar(char*,int);
void mostrar(char*,int);


int main(  ) {

	int cant=0,cant_plus=0;
	char *ptr;
	
	printf("\ningrese la cantidad de caracteres:");
	scanf(" %d",&cant);
	
	ptr = (char*) malloc(sizeof(char)*cant);
	
	cargar(ptr,cant);
	
	mostrar(ptr,cant);
	
	printf("\nIngrese los nuevos valores que desea agregar: ");
	scanf("%d",&cant_plus);
	
	ptr = (char*) realloc(ptr,sizeof(char)*(cant+cant_plus));
	
	cargar_nuevos(ptr,cant,cant_plus);
	
	mostrar(ptr,(cant+cant_plus));
	
	free(ptr);
	
	
	return 0;
}

void cargar(char*ptr , int cant){
	
	int i=0;
	
	printf("ingrese los %d valores: \n",cant);
	for(i=0;i<cant;i++){
		
		scanf(" %c",ptr+i);
		
	}
	
}

void mostrar(char*ptr , int cant){
	
	int i=0;
	
	printf("los valores son: ");
	for(i=0;i<cant;i++){
		
		printf("%c",*(ptr+i));
		
	}
	
}
void cargar_nuevos(char*ptr, int cant, int cant_plus){
	
	int i=0;
	
	printf("ingrese los %d valores: \n",cant_plus);
	for(i=0;i<(cant_plus);i++){
		
		scanf(" %c",ptr+i+cant);
		
	}
	
}
