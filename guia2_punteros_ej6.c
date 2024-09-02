#include <stdio.h>

/*Se desea cargar en un vector los saldos de proveedores. La cantidad de saldos es ingresada por el usuario (máximo 10). 
La carga finaliza con un saldo menor o igual a cero. Además, desarrolle las siguientes funciones para mostrar:
a. Cantidad de saldos cargados.		/cont

b. Promedio de saldos.	/prom=acum/cont
c. Cantidad de saldos menores al promedio. saldo[i] > prom
d. Cantidad de saldos mayores al promedio.	saldo i < prom
e. Calcular cuánto fue lo recaudado en el mes.	acum
Cada ítem es una función. Para recorrer el vector utilice punteros.
*/

//void saldoscargados(int *);

int main( ) {
	
	int saldos[10]={0},i=0,cont=0,acum=0,menores=0,mayores=0,salir=0;
	int *ptr = &saldos[0];
	float prom=0;
	char opc;
	
	printf("Maximo 10 saldos | Presione '0' para dejar de cargar \n");
	
	for(i=0;i<10;i++){
		
		printf("ingrese el saldo del %d proveedor: ",i+1);
		scanf("%d",&saldos[i]);
		
		if(saldos[i] <= 0){
			break;
		}
		cont++;
		acum=acum+saldos[i];
		
	}
	prom = (acum/(float)cont);
	
	
	for(i=0;i<cont;i++){
		
		if( *(ptr+i) > 0){
			printf("%d\t",*(ptr+i));		//mostrar saldos cargados
		}
	}
	
	
	printf("\n---ingrese---\na. Cantidad de saldos cargados.\nb. Promedio de saldos.\nc. Cantidad de saldos menores al promedio\nd. Cantidad de saldos mayores al promedio\ne. Calcular cuánto fue lo recaudado en el mes.\ncualquier otra letra lo sacal del menu \n");
	do{
	printf("-----\nopc: \n");
	scanf(" %c",&opc);

	switch(opc){
		
	case 'a':
	case 'A':
		printf("la cantidad de saldos cargados fueron: %d\n",cont);
		break;
	
	case 'b':
	case 'B':
		printf("el promedio de saldos es: %.2f\n",prom);
		break;
		
	case 'c':
	case 'C':
		printf("cantidad de saldos menores al promedio: ");
		
		for(i=0;i<cont;i++){
			
			if (saldos[i] < prom){
				menores++;
			}
		}
		printf("%d \n",menores);
		break;
		
	case 'd':
	case 'D':
		printf("cantidad de saldos mayores al promedio: ");
		for(i=0;i<cont;i++){
			
			if (saldos[i] >= prom){
				mayores++;
			}
		}
		printf("%d \n",mayores);
		break;
		
	case 'e':
	case 'E':
		printf("lo recaudado en el mes fue: %d \n",acum);
		break;
		
	default:
		salir = 4;
		printf("gracias! \n");
		break;
	}
	
	}while(salir != 4);
	return 0;
}
