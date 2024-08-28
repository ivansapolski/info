#include <stdio.h>

int main(  ) {

	/*Desarrolle un programa que declare e inicialice un vector de 5 valores 
	(4.5,8,2.3,1.1,3). Luego, se pide que calcule y muestre la sumatoria y el promedio. Utilice punteros para realizar el ejercicio.*/
	
	int i=0;
	float sumatoria=0,prom=0;
	float v[5]={4.5,8,2.3,1.1,3};
	float *ptr = v;

	
	printf("Los valores del vector son:\t");
	for(i=0;i<5;i++){
		
		printf("%.2f\t",*(ptr+i));	//printf("%.2f\t", v[i] ); sin puntero
		
	}

	float *ptrsum=&sumatoria,*ptrprom=&prom;
	for(i=0;i<5;i++){
		
		*ptrsum = *ptrsum + *(ptr+i);		//sumatoria = sumatoria + v[i];
		
	}
	
	printf("\n La suma de los nros es: %.2f",*ptrsum); 		//printf("\n La suma de los nros es: %.2f",sumatoria); 
	*ptrprom = *ptrsum /(float)5;									//prom = sumatoria /(float)5;		
	printf("\n El promedio es: %.2f",*ptrprom);						//printf("\n El promedio es: %.2f",prom);	
	
	return 0;
}

