#include <iostream>
using namespace std;

void pedirDatos(int *, int *); //pedir datos no usas ningun valor va el () nomas sin los int
void funpot(int*, int *);


int main( ) {

	int nro=0,potencia=0;
	pedirDatos(&nro,&potencia);
	funpot(&nro,&potencia);
	
	return 0;
}

void pedirDatos(int *nro,int *pot){
	
	printf("Ingrese un numero entero\n");
	scanf("%d",&*nro);
	printf("Ingrese la potencia a la quiera elevar el nro anterior\n");
	scanf("%d",&*pot);
	
}

void funpot(int *nro ,int* pot ){
	
	int total=1;
	for(int i=0;i<*pot;i++){
		total=total*(*nro);
	}
	printf("El total es %d",total);
}
