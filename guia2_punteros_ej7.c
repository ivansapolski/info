#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*7.Desarrolle un programa que declare e inicialice un vector de 5 valores aleatorios. 
Luego, crear 3 funciones que permitan hallar el valor máximo, mínimo y la sumatoria de ellos. 
Finalmente mostrar los resultados. Utilice punteros para realizar el ejercicio*/

void maximo(int*);
void minimo(int*);
void sumatoria(int*);

int main( ) {

	int v[5]={0},i=0,salir=0;
	int *ptr=&v[0];
	char opc;
	
	srand(time(NULL));
	
	for(i=0;i<5;i++){
		
		v[i] = rand()%10;
	}
	
	for(i=0;i<5;i++){
		
		printf("%d\t",v[i]);
	}

	printf("\nIngrese \na.Maximo \nb.Minimo  \nc.Sumatoria \n*Cualquier otra letra lo saca del menu* \n");
	
	do{
		
		printf("-----\nopc: ");
		scanf(" %c",&opc);
		
		switch(opc){
			
		case 'a':
		case 'A':
			maximo(ptr);
			break;
			
		case 'b':
		case 'B':
			minimo(ptr);
			break;
			
		case 'c':
		case 'C':
			sumatoria(ptr);
			break;
			
		default:
			
			printf("gracias!");
			salir=4;
			break;
			
		}
		
	} while(salir!=4);
	
	
	return 0;
}

void maximo(int*v){
	
	int i=0,maximo=0;
	
	for(i=0;i<5;i++){
		
		if(i==0){
			
			maximo = v[0];
			
		}
		if( v[i] > maximo ){
			
			maximo = v[i];
			
		}
		
	}
	printf("el maximo es %d \n",maximo);
	
}

void minimo(int*v){
	
	int i=0,minimo=0;
	
	for(i=0;i<5;i++){
		
		if(i==0){
			
			minimo= v[0];
			
		}
		if( v[i] < minimo ){
			
			minimo = v[i];
			
		}
		
	}
	printf("el minimo es %d \n",minimo);
}

void sumatoria(int*v){
	
	int i=0,acum=0;
	
	for(i=0;i<5;i++){
		
		acum = acum + v[i];
		
	}
	printf("La sumatoria de los valores del vector es %d \n",acum);
}
