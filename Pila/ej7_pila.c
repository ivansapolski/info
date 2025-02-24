/*Desarrollar un programa que cree una pila de vehículos que pasan por un peaje, en la cual se deben registrar 
patente, cantidad de ejes, precio, dirección. 
El precio es según la cantidad de ejes. 
(1 eje = $100, 2 ejes = $150, 3 ejes = $200 y 4 ejes o más $300). 
La dirección es a la que se dirige el vehículo, en este caso puede ser de Norte 
a Sur (NS) o Sur a Norte (SN). 

Luego, arme un menú de opciones que muestre lo siguiente: 
- Agregar un vehiculo a la pila
- Borrar el último nodo de la pila.
- Mostrar todos los vehículos. 
- Mostrar los vehículos por dirección.
. Mostrar los vehículos por ejes.
*/
#include <stdio.h>
#include <stdlib.h>

struct vehiculo{
	int patente;
	int ejes;
	int precio;
	char direccion[5];
};

struct node{
	struct vehiculo v;
	struct node* next;
};

void push(struct node**);
void pop(struct node**);
void print_all(struct node*);
void print_direccion(struct node*);
void print_ejes(struct node*);

int main( ) {
	
	struct node*sp = NULL;
	int opc=0;
	
	do{
		printf("1)Push \n2)Pop \n3)Print all\n4)Mostrar por ejes\n6)Salir\n_opc:");
		scanf("%d",&opc);
		switch(opc){
		case 1:
			push(&sp);
			break;
		case 2:
			pop(&sp);
			break;
		case 3:
			print_all(sp);
			break;
		case 4:
			print_ejes(sp);
			break;
		}
	} while(opc!=6);
	
	return 0;
}

void push(struct node**sp){
	
	struct node* new_node = NULL;
	new_node = (struct node*)malloc(sizeof(struct node));
	if(new_node==NULL){
		printf("Error de almacenamiento\n");
		exit(0);
	}
	printf("\nIngrese la patente del vehiculo: ");
	scanf("%d",&new_node->v.patente);
	printf("\nIngrese el numero de ejes del vehiculo: ");
	scanf("%d",&new_node->v.ejes);
	switch(new_node->v.ejes){
	case 1:
		new_node->v.precio = 100;
		break;
	case 2:
		new_node->v.precio = 150;
		break;
	case 3:
		new_node->v.precio = 200;
		break;
	default:
		new_node->v.precio = 300;
		new_node->v.ejes = 4;
		break;
	}
	printf("\nIngrese la direccion en la que se dirige el vehiculo: [NS] o [SN]\n");
	scanf(" %s",new_node->v.direccion);
	
	new_node->next = *sp;
	*sp = new_node;
}
void pop(struct node**sp){
	
	struct node* temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	
	if(temp == NULL){
		printf("Error de almacenamiento\n");
		exit(0);
	}
	temp = *sp;
	
	*sp = (*sp)->next;
	free(temp);
	printf("Nodo eliminado.\n");
}
void print_all(struct node*sp){
	
	struct node* temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	
	temp = sp;
	
	printf("\nPatente\t\tNro de ejes\tPrecio\t\tDireccion \n");
	while(temp != NULL){
		printf("%d\t\t%d\t\t%d\t\t%s\n",temp->v.patente,temp->v.ejes,temp->v.precio,temp->v.direccion);
		temp = temp->next;
	}
}

void print_ejes(struct node*sp){
	
	struct node* temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	
	temp = sp;
	
	printf("\nEjes: \n");
	
	printf("\nVehiculos con 1 eje: ");
	while(temp != NULL){
		if(temp->v.ejes == 1){
			printf("%d\t",temp->v.patente);
		}
		temp = temp->next;
	}
	temp=sp;
	
	printf("\nVehiculos con 2 ejes: ");
	while(temp != NULL){
		
		if(temp->v.ejes == 2){
			printf("%d\t",temp->v.patente);
		}
		temp = temp->next;
	}
	temp=sp;
	
	printf("\nVehiculos con 3 ejes: ");
	while(temp != NULL){
		if(temp->v.ejes == 3){
			printf("%d\t",temp->v.patente);
		}
		temp = temp->next;
	}
	temp=sp;
	
	printf("\nVehiculos con 4 ejes: ");
	while(temp != NULL){
		if(temp->v.ejes == 4){
			printf("%d\t",temp->v.patente);
		}
		temp = temp->next;
	}
	printf("\n");
}
