#include <stdio.h>

/*Declarar una variable de cada tipo (int, float, char), un puntero de cada tipo de variable creada y 
asignarles las direcciones de memoria de cada variable creada. Luego, modificar el valor de cada variable utilizando el puntero 
y mostrar por pantalla el nuevo valor de cada una de las variables.*/

int main(  ) {
	
	int a=1;
	float b=2.2;
	char c='A';
	
	int *pa=&a;
	float *pb=&b;
	char *pc=&c;
	
	printf("Valores antes de cambiar el valor por punteros \nA= %d , B= %.2f , C= %c  \n\n",a,b,c);
	
	//cambiando valores
	*pa=5;
	*pb=6.6;
	*pc='F';
	
	printf("nuevo valor despues de cambiar el valor por punteros \nA= %d , B= %.2f , C= %c  ",a,b,c);
	
	return 0;
}

