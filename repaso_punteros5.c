#include <stdio.h>
#include <math.h>

/*Escribir un programa que simule una calculadora, en donde muestre un menú de opciones con las operaciones permitidas como a. Suma, b. Resta, 
c. Multiplicación y d. División, e. elevar a una potencia, f. calcular la raíz cuadrada de un número. Luego el programa solicita que se ingrese dos números 
(tipo float) y llame a la función correspondiente para hacer el cálculo. 
Luego mostrar el resultado y preguntar si desea realizar otra operación o terminar el programa. Usar punteros para la resolución de este ejercicio.*/

void suma(float *a, float *b);
void resta(float *a, float *b);
void multiplicacion(float *a, float *b);
void division(float *a, float *b);
void potencia(float *a, float *b);
void raiz(float *a);

int main( ) {
	
	int salir=0;
	float a=0,b=0;
	char opc;
	
	do{
		printf("\n---------------------------\n");
		printf("A)SUMA \nB)RESTA \nC)MULTIPLICACION \nD)DIVISION \nE)ELEVAR A UNA POTENCIA \nF)CALCULAR RAIZ CUADRADA DE UN NUMERO \n\n");
		printf("ingrese la operacion a realizar: \n");
		scanf(" %c",&opc);
		
		switch(opc){
			
		case 'a':
		case 'A':
			printf("opcion SUMA \ningrese 2 numeros flotantes: \n");
			scanf("%f %f",&a,&b);
			suma(&a,&b);
			
			break;
			
		case 'b':
		case 'B':
			printf("opcion RESTA \ningrese 2 numeros flotantes: \n");
			scanf("%f %f",&a,&b);
			resta(&a,&b);
			
			break;	
			
		case 'c':
		case 'C':
			printf("opcion MULTIPLICACION \ningrese 2 numeros flotantes: \n");
			scanf("%f %f",&a,&b);
			multiplicacion(&a,&b);
			break;
			
		case 'd':
		case 'D':
			printf("opcion DIVISION \ningrese 2 numeros flotantes: \n");
			scanf("%f %f",&a,&b);
			
			if(b == 0){
				
				do{
					
					printf("NO SE PUEDE DIVIDIR POR 0 \nINGRESE OTRO VALOR DE B:");
					scanf("%f",&b);
					
				} while(b == 0);
				
			}
			division(&a,&b);
			
			break;
			
		case 'e':
		case 'E':
			printf("opcion POTENCIA \ningrese 2 numeros flotantes: \n");
			scanf("%f %f",&a,&b);
			potencia(&a,&b);
			break;
			
		case 'f':
		case 'F':
			printf("opcion RAIZ \ningrese 1 numero flotante: \n");
			scanf("%f",&a);
			raiz(&a);
			break;
			
		}
		printf("\nDESEA CONTINUAR?\n1)SI\t2)NO\n");
		scanf("%d",&salir);
		
	} while(salir!=2);

	
	
	return 0;
}


void suma(float *a, float *b){
	
	float c=0;	
	c =(*a)+(*b);
	printf("la suma de ambos numeros es: %.2f\n",c);
	
}
void resta(float *a, float *b){		

	float c=0;
	c =*a - *b;
	printf("la resta de ambos numeros es: %.2f\n",c);
	
}	
void multiplicacion(float *a, float *b){		
	
	float c=0;
	c =*a * *b;
	printf("la multiplicacion de ambos numeros es: %.2f\n",c);
	
}
void division (float *a,float *b){
	
	float c=0;
	
	c =*a / *b;
	printf("la division de ambos numeros es: %.2f\n",c);
	
}
void potencia(float *a, float *b){		
	
	float c=0;
	c=pow(*a,*b);
	printf("la potencia de ambos numeros es: %.2f\n",c);
	
}
void raiz(float *a){
	
	float c=0;
	c=sqrt(*a);
	printf("la raiz del numero es: %.2f\n",c);
	
}
