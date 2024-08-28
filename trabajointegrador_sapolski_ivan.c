#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void cargarstock(int s[10][5]);
void mostrarStock(int s[10][5]);
int generarOrdenCompra(int s[10][5]);

int main(  ) {
	
	int stock[10][5]={0},salir=0;
	char opcion;
	srand(time(NULL));
	
	printf("++ Bienvenido a la libreria Pyme ++\n");
	
	do{
	
	printf("\ningrese: \nA)CARGAR STOCK (10 productos) \nB)MOSTRAR STOCK \nC)GENERAR ORDEN DE COMPRAS \nD)SALIR \n");
	scanf(" %c",&opcion);
	
	switch(opcion){
		
	case 'a':
	case 'A':
		
		stock[0][0]=1000;
		cargarstock(stock);
		
		break;
		
	case 'b':
	case 'B':
		
		printf("\ncodigo	p.unit	present	p.venta	stock\n");
		mostrarStock(stock);
		
		break;
		
	case 'c':
	case 'C':
		
		printf("Se piden items cuando el stock es menor a 50\n");
		printf("\n - CANTIDAD DE ITEMS A PEDIR: %d -",generarOrdenCompra(stock));
		
		break;
		
	case 'd':
	case 'D':
		
		salir=1;
		
		break;
		
		default:
		printf("No existe esa opcion\n");
		break;		
	}
	
	}while(salir!=1);
	
	return 0;
}

void cargarstock(int s[10][5]){

	int i=0,stk=0;
	
	for(i=0;i<10;i++){
		
		s[i+1][0]= s[i][0]+100;
		
		printf("\nIngrese precio unitario del prod[%d]: ",s[i][0]);
		scanf("%d",&s[i][1]);
		
		printf("Ingrese presentacion del prod [%d]: ",s[i][0]);
		scanf("%d",&s[i][2]);
		
		s[i][3] = (s[i][1]) * (s[i][2]);
		
		stk = rand()% 100; //El stock se genera de manera random
		s[i][4]= stk;
		
	}
}

void mostrarStock(int stock[10][5]){
	
	int i=0,j=0;
	
	for(i=0;i<10;i++){
		
		for(j=0;j<5;j++){
			
			printf("%d\t",stock[i][j]);
			
		}
		printf("\n");
	}
}
	
int generarOrdenCompra(int s[10][5]){
	
	int ordencompra[10][2]={0},pedir=0,i=0,j=0;
	
	for(i=0;i<10;i++){
		
		ordencompra[i][0] = s[i][0];
		
		if(s[i][4] == 0){
			
			ordencompra[i][1]=50;
			pedir++;
			
		}else{
			
			if((s[i][4] > 0) && (s[i][4] < 50)){
				
				ordencompra[i][1] = 50 - s[i][4];
				pedir++;
			}
		}
	}
	
	printf("\n****NOTA DE PEDIDO****");
	printf("\ncod.prod	cant.pedir\n");
	
	
	for(i=0;i<10;i++){
		
		for(j=0;j<2;j++){
			
			if(ordencompra[i][1] != 0){
				
				printf("%d\t\t",ordencompra[i][j]);
				
			}
		}
		if(ordencompra[i][1] != 0){
		printf("\n");
		}
	}
	
	
	return 	pedir;
}
