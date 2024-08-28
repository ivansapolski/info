#include <stdio.h>

/*Escribir una función que reciba dos números enteros por valor y los reste, y 
otra función que reciba dos punteros a enteros y los reste utilizando de punteros. 
Luego, desde el programa principal, solicitar al usuario que ingrese dos números enteros, 
llamar a ambas funciones para restarlos e imprimir el resultado obtenido en cada caso.*/

void func_valor(int,int);
void func_punt(int*, int*);

int main(  ) {

	int a=0,b=0;
//	int *pa=&a,*pb=&b;
	
	printf("ingrese dos numeros enteros \na:");
	scanf("%d",&a);
	printf("b:");
	scanf("%d",&b);
	func_valor(a,b);
	//
	
	printf("\ningrese dos numeros enteros \na:");
	scanf("%d",&a);
	printf("b:");
	scanf("%d",&b);
	func_punt(&a,&b);

	printf("\nconfirmacion: la resta por punteros es %d",(a-b));
	return 0;
}

void func_valor(int a,int b){
	
	int resta=0;
	
	resta=a-b;
	
	printf("la resta es %d",resta);
	
}
	
void func_punt(int *a, int *b){
	
	int resta=0;
	
	resta= *a - *b;
	
	printf("la resta por punteros es %d",resta);
}
