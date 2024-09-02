#include <stdio.h>
#include <stdlib.h>

/*6.Crear un programa que pregunte al usuario cuantos caracteres desea introducir, 
reserve espacio para dicho número de caracteres, le permita al usuario introducirlos desde teclado. 
Por último se los muestra todos seguidos y en el orden inverso al que fueron introducidos. 
Crear funciones para cargar, mostrar en orden y mostrar en orden inverso. Utilizar funciones.*/

void mostrar(char*,int);
void cargar(char*,int);
void minverso(char* , int);

int main(  ) {

	int cant=0;
	char *ptr;
	
	printf("ingrese la cantidad de caracteres que desea introducir\n");
	scanf("%d",&cant);
	
	ptr = (char*) malloc(sizeof(char)*cant);	
	cargar(ptr,cant);
	
	mostrar(ptr,cant);
	minverso(ptr,cant);
	
	free(ptr);
	
	return 0;
}

void cargar(char*ptr ,int cant){
	
	int i=0;
	printf("Ingrese los %d valores: \n",cant);
	for(i=0;i<cant;i++){
		
		scanf(" %c",ptr+i);
		
	}
}

void mostrar(char* ptr,int cant){
	
	int i=0;
	printf("\nLos %d valores ordenados son: \n",cant);
	for(i=0;i<cant;i++){
		
		printf("%c",*(ptr+i));
		
	}
	
}
	
void minverso(char *ptr, int cant){
	
	int i=0;
	printf("\nLos %d valores inversos: \n",cant);
	
	for(i=cant;i>=0;i--){ //para ser inverso va de cant a 0
		
		printf("%c",*(ptr+i));	
		
	}
	
	
}
