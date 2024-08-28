#include <stdio.h>
#include <ctype.h>
/*Desarrollar el ejercicio anterior con funciones. Crear una función que pase los valores a mayúsculas y una función que pase los valores a minúsculas. 
Desarrollar un programa que declare e inicialice un vector tipo char con el abecedario. Luego mostrar en pantalla el abecedario en mayuscula y minuscula,  
utilizando punteros. Nota: la función para pasar a mayúscula es toupper() y a minúsculas es tolower(). 
Ejemplo: cadena[i] = tolower(cadena[i]); En código ASCII A=65*/

void mayus(char*);
void minus(char*);

int main(  ) {
	
	char abc[26]={' '};
	char *ptr_abc = abc;	//*ptr_abc = &abc[0]
	int i=0;
	
	for(i=0;i<26;i++){
		
		abc[i]=65+i;	// En código ASCII A=65 - DECLARA EN MAYUS
		
	}
	
	minus(ptr_abc);
	mayus(ptr_abc);
	
	
	return 0;
}

void mayus(char *a){
	
	printf("\nLAS MAYUSCULAS: \n");
	
	for(int i=0;i<26;i++){
		
		printf(" %c\t",toupper(*a+i));		
		
	}
	//toupper
	
}

void minus(char *a){
	
	int i=0;
	
	printf("\n\nLAS MINUSCULAS: \n");
	
	for(i=0;i<26;i++){
		
		printf(" %c\t",tolower(*a+i));	
		
	}
	
}
