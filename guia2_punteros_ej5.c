#include <stdio.h>


/*Realice un programa que permita cargar 10 números enteros en un vector. 
Luego utilizando punteros calcule el promedio de ellos. 
Finalmente mostrar todos los valores y su promedio utilizando punteros.*/


int main( ) {
	
	int v[10]={0};
	int *ptr=&v[0];
	float prom=0;
	
	for(int i=0;i<10;i++){
		
		printf("ingrese el valor de la posicion {%d}: ",i+1);
		scanf("%d",&v[i]);
		
	}
	
	for(int i=0;i<10;i++){
		
		prom = prom + *(ptr+i);
		
	}
	printf("\nEl promedio de los valores es: %.2f",(prom/(float)10));
	
	printf("\n\ntodos los valores: \n");
	
	for(int i=0;i<10;i++){
		
		printf("%d\t",*(ptr+i));
		
	}
	return 0;
}

