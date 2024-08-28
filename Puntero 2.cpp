#include <iostream>
using namespace std;
//PUNTEROS EN C:
//(2) APLICACIONES Y EJEMPLOS:

/*ESCRIBIR UNA FUNCION QUE RECIBE UN PUNTERO A ENTERO (int *) Y UN VALOR A ENTERO. 
LA FUNCION IMPRIME LA DIRECCION DE MEMORIA DE ESA VARIABLE, SU VALOR ACTUAL Y LO 
REEMPLAZA POR EL QUE SE PASA COMO ARGUMENTO. Comprobar su correcto funcionamiento 
void modificaVar (int*p, int valor);
*/
void modificaVar(int *,int );

int main( ) {

	int variable=10;
	
	modificaVar(&variable,20);
	
	printf("\n Variable = %d \n",variable);
	
	return 0;
}

void modificaVar(int *p, int valor){
	
printf("\n La direccion de memoria es %p \n",p);	//Imprimir la direccion de memoria de la variable
printf("\n El valor actual de la variable es %d \n",*p); //Imprimir el valor actual de la variable cuya direccion se pasa
*p=valor; //Modifiquemos el valor de la variable reemplazandolo por valor
	
}
