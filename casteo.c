#include <stdio.h>

//Escribir un programa que declare e inicialice una variable float n=5/2. Luego imprima el resultado de la división, la misma debería ser 2,5.

int main( ) {
	
	//CASTEO
	float n=5/2  ;
	int n1=2,n2=0,n3=0;
	
	printf("nro es: %.2f",n);
	
	//Cargar las 3 notas de un alumno como valores enteros. Luego mostrar el promedio teniendo en cuenta si tiene parte decimal.
	
	printf("\n-----------------\ningrese 3 notas\n");
	
	printf("\nnota 1: ");
	scanf("%d",&n1);
	printf("\nnota 2: ");
	scanf("%d",&n2);
	printf("\nnota 3: ");
	scanf("%d",&n3);
	
	printf("el promedio es %.2f \n++++++++++++\n",((n1+n2+n3)/3.0));
	
	return 0;
}

