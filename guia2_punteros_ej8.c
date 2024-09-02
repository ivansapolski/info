#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*8.Desarrolle un programa que declare e inicialice un arreglo de 2x3 con valores aleatorios. 
Luego mostrar los valores. Utilice punteros para realizar el ejercicio.*/

void mostrar(int v[2][3]);

int main(  ) {

	int v[2][3]={0},i=0,j=0;
	
	srand(time(NULL));	
	
	for(i=0;i<2;i++){
		
		for(j=0;j<3;j++){
			
			*(*(v+i)+j) = rand()%20; //v[i][j] por punteros
			
		}
		
	}
	mostrar(v);
	return 0;
}

void mostrar(int v[2][3]){
	
	int i=0,j=0;
	
	for(i=0;i<2;i++){
		
		for(j=0;j<3;j++){
			
			printf("%d\t",*(*(v+i)+j) );
			
		}
		printf("\n");
	}
	
}
