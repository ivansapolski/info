#include <stdio.h>

//Escribir una funci�n que intercambie el valor de dos variables enteras usando punteros. 
//La funci�n debe tener la siguiente firma: void swap(int *a, int *b).

void swap(int *a, int *b);

int main() {
	
	int a=1,b=2;
	printf("valor de a y b \n %d %d",a,b);
	
	
	swap(&a,&b);
	
	printf("\n\nvalor de a y b \n %d %d",a,b);
	
	return 0;
}

void swap(int *a, int *b){
	
	*a=3,*b=4;
	
}
