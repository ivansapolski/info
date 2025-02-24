/*Elaborar un sistema de stock, en la cual posee una cola de productos con los siguientes atributos: 
	código, nombre, cantidad, precio lista. 

Desarrollar las siguientes funciones:
- Agregar un nuevo producto.
- Borrar el primer nodo de la cola.
- Mostrar el stock. 
- Descontar stock.
- Reponer stock.
*/

#include <stdio.h>
#include <stdlib.h>

struct productos{
	int codigo;
	char nombre[20];
	int cantidad;
	int precio;
};

struct node{
	struct productos prod;
	struct node *link;
};

void push(struct node**,struct node**);
void pop(struct node**,struct node**);
void print(struct node*);
void descontar_stock(struct node*);
void reponer_stock(struct node*);


int main( ) {
	
	struct node* front= NULL;
	struct node *back = NULL;
	
	int opc=0;
	
	do{
		printf("1)Push \n2)Pop \n3)Mostrar stock \n4)Descontar stock \n5)Reponer stock \n6)Salir \n_opc: ");
		scanf("%d",&opc);
		switch (opc) {
		case 1:
			push(&front,&back);
			break;
		case 2:
			pop(&front,&back);
			break;
		case 3:
			print(front);
			break;
			
		case 4:
			descontar_stock(front);
			break;
			
		case 5:
			reponer_stock(front);
			break;
			
		case 6:
			printf("saliendo.\n");
			break;
		default:
			printf("No existe esa opc\n");
		};
	} while(opc != 6);
	
	
	return 0;
}

void push(struct node**front,struct node**back){

	struct node *temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	
	if(temp == NULL){
		printf("No hay almacenamiento.\n");
		exit(1);
	}
	
	temp->link = NULL;
	
	printf("\nIngrese el codigo del producto: ");
	scanf("%d",&temp->prod.codigo);
	printf("\nIngrese el nombre del producto: ");
	scanf("%s",temp->prod.nombre);
	printf("\nIngrese la cantidad del producto: ");
	scanf("%d",&temp->prod.cantidad);
	printf("\nIngrese el precio del producto: ");
	scanf("%d",&temp->prod.precio);	
	
	if( *back == NULL ){
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
	
	if( *back == NULL){
		printf("cola vacia\n");
		exit(1);
	}

	temp = *front;
	*front = (*front)->link;
	free(temp);
	printf("Nodo eliminado\n");
	
}
void print(struct node*front){
	
	struct node *temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	
	temp = front;
	
	printf("El stock disponible es : \n");
	printf("Cod\tNombre\tCant\tPrecio\n");
	while (temp != NULL){
		printf("%d\t%s\t%d\t%d\n",temp->prod.codigo,temp->prod.nombre,temp->prod.cantidad,temp->prod.precio);
		temp = temp->link;
	}
	
}
void descontar_stock(struct node*front){
	
	int code=0,stock=0,existe=0;
	
	struct node *temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = front;
	
	printf("Ingrese el codigo del producto que desea descontar: ");
	scanf("%d",&code);
	
	while (temp != NULL){
		
		if(code == temp->prod.codigo){
			
			printf("Ingrese cuantos desea descontar: ");
			scanf("%d",&stock);
			if( temp->prod.cantidad >= stock ){
				temp->prod.cantidad = temp->prod.cantidad - stock;
				printf("Stock actualizado.\n");
				existe = 1;
			}else{
				printf("No hay suficiente stock.\n");
				existe = 1;
			}
		}
		temp = temp->link;
	}
	if(existe == 0){
		printf("No se encontro el codigo ingresado\n");
	}
}
void reponer_stock(struct node*front){
	
	int code=0,stock=0,existe=0;
	
	struct node *temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = front;
	
	printf("Ingrese el codigo del producto que desea reponer: ");
	scanf("%d",&code);
	
	while (temp != NULL){
		
		if(code == temp->prod.codigo){
			
			printf("Ingrese cuantos desea reponer: ");
			scanf("%d",&stock);
			existe = 1;
			if( stock > 0 ){
				temp->prod.cantidad = temp->prod.cantidad + stock;
				printf("Stock actualizado.\n");
			}
		}
		temp = temp->link;
	}
	if(existe == 0){
		printf("No se encontro el codigo.\n");
	}
}
