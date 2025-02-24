/*Desarrollar un programa que cree una cola de vehículos que pasan por un peaje, 
en la cual se deben registrar patente, cantidad de ejes, precio, dirección. 

El precio es según la cantidad de ejes. 
(1 eje = $100, 2 ejes = $150, 3 ejes = $200 y 4 ejes o más $300). 
La dirección es a la que se dirige el vehículo, en este caso puede ser de 
Norte a Sur (NS) o Sur a Norte (SN). Luego, arme un menú de opciones que muestre lo siguiente: 
- Agregar un vehiculo a la cola
- Borrar el primer nodo de la cola.
- Mostrar todos los vehículos. 
- Mostrar los vehículos por dirección.
. Mostrar los vehículos por ejes.
*/

#include <stdio.h>
#include <stdlib.h>

struct autoo{
	int patente;
	int cantidad;
	int precio;
	char direccion[3];
};

struct node{
	struct autoo a;
	struct node*link;
};

void push(struct node**front,struct node**back){
	struct node *temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	
	if(temp == NULL){
		printf("no hay almacenamiento");
		exit(1);
	}
	printf("ingrese la patente: ");
	scanf("%d",&temp->a.patente);
	printf("ingrese la cantidad de ejes: ");
	scanf("%d",&temp->a.cantidad);
	
	switch(temp->a.cantidad){
	case 1:
		temp->a.precio = 100;
		break;
	case 2:
		temp->a.precio = 150;
		break;
	case 3:
		temp->a.precio = 200;
		break;
	default:
		temp->a.precio = 300;
		break;
	}
	printf("Ingrese direccion [SN] o [NS]:");
	scanf("%s",temp->a.direccion);
	
	if(*back == NULL){
		*back = temp;
		*front = *back;
	}else{
		(*back)->link = temp;
		*back = temp;
	}	
}
	
void pop(struct node**front,struct node**back){
	
	struct node *temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp=*front;
	
	if(*back == NULL){
		printf("cola vacia\n");
		exit(0);
	}
	
	*front = (*front)->link;
	free(temp);
	printf("Nodo eliminado\n");
}
	
void print_all(struct node*front){
	
	struct node *temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp=front;
	temp->link = NULL;
	printf("Patente\t\tCant ejes\tPrecio\t\tDireccion\n");
	
	while(temp != NULL){
		printf("%d\t\t %d\t\t %d\t\t %s\n",temp->a.patente,temp->a.cantidad,temp->a.precio,temp->a.direccion);
		temp = temp->link;
	}
	
}

int main(  ) {

	struct node *front = NULL;
	struct node *back = NULL; 
	
	int opc;
	
	do{
		printf("\n___\n1)Push\n2)Pop\n3)Print all\n4)Mostrar por direccion\n5)Mostrar por ejes\n___\n");
		scanf("%d",&opc);
		switch (opc) {
		case 1:
			push(&front,&back);
			break;
		case 2:
			pop(&front,&back);
			break;
		case 3:
			print_all(front);
			break;
			
		case 4:
			printf("saliendo\n");
			break;
			
		};
	} while(opc!=4);
	
	
	
	return 0;
}

