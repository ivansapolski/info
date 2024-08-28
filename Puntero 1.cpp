#include <iostream>
using namespace std;
//PUNTEROS EN C:
//(1) SINTAXIS Y EJEMPLO BASICO: 

int main(int argc, char *argv[]) {
	
	int variable=5;		//CREO UNA VARIABLE Y UN PUNTERO
	int * puntero;		// EL PUNTERO NO ESTA INICIALIZADO
	
	puntero = &variable;	
	
	printf("variable = %d\n",variable);
	printf("*puntero = %d\n",*puntero); // * SIGNIFICA EL CONTENIDO DE LO APUNTADO POR ; LO MISMO QUE variable
										// SI NO TUVIERA EL * SI IMPRIME X1004 LA DIRECC MEMORIA 
	
	*puntero = *puntero+1;
	
	printf("variable = %d\n",variable);
	printf("*puntero = %d\n",*puntero);
	
	return 0;
}

