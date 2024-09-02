#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Cree un programa que permita reservar memoria para arreglo de enteros 2x3. 
Luego cargar los valores de manera aleatoria. 
Realizar un menu de opciones que muestre la sumatoria, muestre todos los valores y al finalizar el programa libere la memoria.*/

void cargar(int*,int);
void mostrar(int*,int,int);
void sumatoria(int*,int);

int main(  ) {

	int fil=2,col=3,t=0;
	int *v;
	char opc;
	
	t=fil*col;
	
	srand(time(NULL));
	
	v = (int*) malloc(sizeof(int)*t);
	
	cargar(v,t);
	
	printf("\nA) INGRESE SUMATORIA \nB) MOSTRAR LOS VALORES \nS) SALIR DEL PROGRAMA \n");
	
	do{
		printf("\n___\nopc:");
		scanf(" %c",&opc);
		
		switch(opc){
			
		case 'a':
		case 'A':
			sumatoria(v,t);
			break;
			
		case 'b':
		case 'B':
			mostrar(v,t,fil);
			break;
			
		case 's':
		case 'S':
			printf("\ngracias!");
			opc='s';
			free(v);
		break;
			
		default:
			break;
			
		}
		
	} while(opc!='s');
	
	
	return 0;
}

void cargar(int* v,int total){
	
	int i=0;
	for(i=0;i<total;i++){
		
		*(v+i)  = rand()%10;
		
	}
	
}
	
void mostrar(int* v,int total,int fil){
	
	int i=0;
	for(i=0;i<total;i++){
		
		printf("%d\t",*(v+i));
		
		if( i == fil ){
			printf("\n");
		}
	}
	
}

void sumatoria(int*v,int total){
	
	int i=0,sum=0;
	for(i=0;i<total;i++){
		
		sum = sum + (*(v+i));
		
	}
	printf("\nLa sumatoria es: %d\n",sum);
}
