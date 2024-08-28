#include <stdio.h>
#include <stdlib.h>

/*Se tiene un vector de 10 elementos con valores numéricos enteros . 
Luego crear una función que muestre los valores que están en posiciones impares, y otra función con las posiciones pares.
*/

void pares(int *);
void impares(int *);

int main(  ) {

	int v[10]={1,12,23,34,45,56,67,78,89,91};
	int *ptr=&v[0];
	
	pares(ptr);
	impares(ptr);
	
	return 0;
}

void pares(int *a){
	printf("LA POSICION PARES: \n");	
	for(int i=0;i<10;i++){
		
		if( (*a+i) % 2 == 0 ){
			
			printf("%d\t ",*(a+i));
			
		}
		
	}
	
}

void impares (int *a){
	printf("\nLA POSICION IMPARES: \n");
	for(int i=0;i<10;i++){
		
		if( (*a+i) % 2 == 0 ){
			
			
		}else{
			
			printf("%d\t",*(a+i)); //*(a+i) 	donde apunta el valor inicial + la cantidad de numeros que me tengo que desplazar //NO SUMAR A ESE NRO
			
		}
		
	}
	
	
}
