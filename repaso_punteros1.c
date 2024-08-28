#include <stdio.h>

int main(  ) {
	
	//PUNTEROS
	/*Escribir un programa que declare una variable de cada tipo (int, float, char), un puntero de cada tipo de la variable creada, 
	inicialice la variable e inicialice el puntero para que apunte a las variables creadas. Luego que imprima por pantalla para cada tipo lo siguiente: 
	-La dirección de memoria de la variable.
	-El valor que almacena la variable.
	-El valor del puntero.
	-El valor al que apunta el puntero.
	*/
	
	int a=5;
	float b=2.02;
	char c='F';
	
	int *pa=&a;
	float *pb=&b;
	char *pc=&c;
	
	//pa=&a;
	printf("La direccion de memoria de A es: %p \n",&a);
	printf("Valor que almacena A es: %d \n",a);
	printf("Valor del puntero A es: %p \n",pa);
	printf("Valor al que apunta el puntero A es: %d \n",*pa);
	
	//pb=&b;
	printf("\nLa direccion de memoria de B es: %x \n",&b);
	printf("Valor que almacena B es: %.2f \n",b);
	printf("Valor del puntero B es: %x \n",pb);
	printf("Valor al que apunta el puntero B es: %.2f \n",*pb);
	
	//pc=&c;
	printf("\nLa direccion de memoria de C es: %x \n",&c);
	printf("Valor que almacena C es: %c \n",c);
	printf("Valor del puntero C es: %x \n",pc);
	printf("Valor al que apunta el puntero C es: %c \n",*pc);
	
	return 0;
}

