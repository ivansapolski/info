/*Elaborar un sistema de stock, en la cual posee una pila de productos con los siguientes atributos: 
	código, nombre, cantidad, precio lista. 
Desarrollar las siguientes funciones:
- Agregar un nuevo producto.
- Borrar el último nodo de la pila.
- Mostrar el stock. 
- Descontar stock.
- Reponer stock
*/
#include <stdio.h>
#include <stdlib.h>

struct producto{
	int codigo;
	char nombre[40];
	int cantidad;
	float precio;
};

struct node{
	struct producto prod;
	struct node* next;
};

void push(struct node**);
void pop(struct node**);
void print(struct node*);
void descontar_stock(struct node*);
void reponer_stock(struct node*);

int main( ) {
	
	struct node*sp = NULL;
	
	int opc=0;
	
	do{
		
		printf("1)PUSH \n2)POP \n3)MOSTRAR STOCK \n4)DESCONTAR STOCK \n5)REPONER STOCK\n6)SALIR\n_opc:");
		scanf("%d",&opc);
		switch(opc){
		case 1:
			push(&sp);
			break;
		case 2:
			pop(&sp);
			break;
		case 3:
			print(sp);
			break;
		case 4:
			descontar_stock(sp);
			break;
		case 5:
			reponer_stock(sp);
		}
	} while(opc!=6);
	
	return 0;
}
void push(struct node**sp){
	struct node*new_node = NULL;
	new_node = (struct node*)malloc(sizeof(struct node));
	
	if(new_node==NULL){
		printf("Error de almacenamiento\n");
		exit(1);
	}
	printf("\nIngrese el codigo del producto : ");
	scanf("%d",&new_node->prod.codigo);
	printf("\nIngrese el nombre del producto : ");
	scanf(" %s",new_node->prod.nombre);
	printf("\nIngrese la cantidad del producto : ");
	scanf("%d",&new_node->prod.cantidad);
	printf("\nIngrese el precio del producto : ");
	scanf("%f",&new_node->prod.precio);
	
	new_node->next = *sp;
	*sp = new_node;
}
void pop(struct node**sp){
	
	struct node*temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	
	if(*sp == NULL){
		printf("Pila vacia\n");
		return;
	}
	temp = *sp;
	*sp = (*sp)->next;
	free(temp);
	printf("Nodo eliminado.\n");
}
void print(struct node*sp){
	
	struct node*temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = sp;
	
	printf("Stock: \n");
	printf("Codigo\t\tNombre\t\tCantidad\tPrecio\n");
	while(temp!=NULL){
		printf("%d\t\t%s\t\t%d\t\t%.2f\n",temp->prod.codigo,temp->prod.nombre,temp->prod.cantidad,temp->prod.precio);
		temp = temp->next;
	}
}
void descontar_stock(struct node*sp){
	
	int codigo=0,cantidad=0,existe=0;
	
	struct node*temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = sp;
	
	printf("\nIngrese el codigo del producto: ");
	scanf("%d",&codigo);
	
	while(temp != NULL){
		
		if(temp->prod.codigo == codigo){
			
			printf("\nIngrese la cantidad que desea descontar: ");
			scanf("%d",&cantidad);
			if(cantidad <= temp->prod.cantidad){
				temp->prod.cantidad = temp->prod.cantidad - cantidad;
				existe = 1;
			}else{
				printf("Stock insuficiente.\n");
			}
		}
		temp = temp->next;
	}
	if(existe == 0){
		printf("No se encontro el codigo\n");
	}
	
}
void reponer_stock(struct node*sp){
	
	int codigo=0,cantidad=0,existe=0;
	
	struct node*temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = sp;
	
	printf("\nIngrese el codigo del producto: ");
	scanf("%d",&codigo);
	
	while(temp != NULL){
		
		if(temp->prod.codigo == codigo){
			
			printf("\nIngrese la cantidad que desea agregar: ");
			scanf("%d",&cantidad);
			if(cantidad > 0){
				temp->prod.cantidad = temp->prod.cantidad + cantidad;
				existe = 1;
			}
		}
		temp = temp->next;
	}
	if(existe == 0){
		printf("No se encontro el codigo\n");
	}
}
