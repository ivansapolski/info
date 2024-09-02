#include <stdio.h>
#include <stdlib.h>

/*8. Crear un programa en la cual contenga un menú de opciones con distintas operaciones:
A. Reserva de memoria e introducción de datos enteros
B. Agregar reserva de memoria e introducción de nuevos datos enteros
C. Mostrar los datos en el orden y orden invertido al que fueron introducidos
*/

void reservar(int* ,int);
void agregar(int*,int,int);
void mostrar(int*,int);
void inverso(int*,int);

int main( ) {
	
	int cant=0,salir=0,cant_new=0;
	int *ptr;
	char opc;
	
	printf("ingrese \nA)Reserva de memoria e introduccion de datos enteros \nB)Agregar reserva de memoria e introduccion de nuevos datos enteros \n");
	printf("C)Mostrar los datos en orden y en el orden invertido que fueron introducidos \nD)Salir del menu \n");
	
	do{
		printf("\n___\nopc: ");
		scanf(" %c",&opc);
		
		switch(opc){
			
		case 'a':
		case 'A':
			
			printf("\ningrese los enteros que desea reservar:");
			scanf("%d",&cant);
			
			ptr = (int*) malloc(sizeof(int)*cant);
			
			reservar(ptr,cant);
			
			break;
			
		case 'b':
		case 'B':
			
			printf("\ningrese los valores que desea agregar: ");
			scanf("%d",&cant_new);
			
			ptr = (int*) realloc(ptr,sizeof(int)*(cant+cant_new));
			
			agregar(ptr,cant,cant_new);
			
			break;
			
		case 'c':
		case 'C':
			mostrar(ptr,(cant+cant_new));
			inverso(ptr,(cant+cant_new));
			break;
			
		case 'd':
		case 'D':
		salir = 4;
			break;
			
		default:
			printf("no existe esa opcion\n");
			break;
		}
		
	} while(salir!=4);
	
	free(ptr);
	
	return 0;
}

void reservar(int *ptr,int cant){
	
	int i=0;
	
	printf("\ningrese los %d valores:\n",cant);
	for(i=0;i<cant;i++){
		
		scanf("%d",ptr+i);
		
	}
	
}
	
void agregar(int*ptr,int cant, int cant_new){
	
	int i=0;
	
	printf("\ningrese los %d valores nuevos:\n",cant_new);
	
	for(i=0;i<cant_new;i++){
		
		scanf("%d",ptr+i+cant);
		
	}
}
	
void mostrar(int*ptr,int cant){
	
	int i=0;
	printf("\nLos valores ordenados: \n");
	for(i=0;i<cant;i++){
		
		printf("%d\t",*(ptr+i));
		
	}
}
	
void inverso(int*ptr,int cant){
	
	int i=0;
	printf("\nLos valores invertidos: \n");
	for(i=cant-1;i>=0;i--){
		
		printf("%d\t",*(ptr+i));
		
	}
}
