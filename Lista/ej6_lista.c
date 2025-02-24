/*Crear un programa que cree una lista de productos, para ello utilice una estructura llamada producto con los atributos código, nombre, cantidad y precio. 
Luego genere un menú de opciones en la cual llame a las siguientes funciones:
-Agregar producto.
-Mostrar lista de productos
-Borre un producto por código de producto.
-Mostrar una lista de los productos sin stock.
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	struct producto prod;
	struct node *next;
};

struct producto{
	int codigo;
	char nombre[20];
	int cantidad;
	float precio;
};

void menu();
void append(struct node**); //agregar producto
void print_lista(struct node*);
void borrar_producto(struct node**);
void sin_stock(struct node*);

int main( ) {

	char opc;
	
	struct node *head = NULL;
	
	do{
		menu();
		printf("\n_opc:");
		scanf(" %c",&opc);
		
		switch(opc){
			
		case 'a':
		case 'A':
			append(&head);
			break;
			
		case 'b':
		case 'B':
			print_lista(head);
			break;
			
		case 'c':
		case 'C':
			borrar_producto(&head);
			break;
			
		case 'd':
		case 'D':
			sin_stock(head);
			break;
			
		case 'S':
			opc = 's';
			printf("saliendo...\n");
			
		}
	} while(opc != 's');
	
	return 0;
}

void sin_stock(struct node*head){
	
	if( head == NULL){
		printf("error\n");
		exit(1);
	}
	
	int stock=0;
	struct node*temp = head;
	
	printf("Producto sin stock:\n");
	printf("codigo\tnombre\tcant\tprecio\n");
	while(temp != NULL){
		
		if( temp->prod.cantidad == 0 ){
			printf("%d\t%s\t%d\t%.1f\n",temp->prod.codigo,temp->prod.nombre,temp->prod.cantidad,temp->prod.precio);
			stock = 1;
		}
		temp = temp->next;
	}
	
	if( stock == 0 ){
		printf("No hay productos sin stock\n");
	}
	
}

void borrar_producto(struct node**head){
	
	struct node *temp = *head;
	struct node *prev = NULL;
	
	int codigo=0;
	printf("\ningrese el codigo que desea borrar: ");
	scanf("%d",&codigo);
	if(temp == NULL){
		printf("ERROR\n");
		exit(1);
	}
	if( temp != NULL && temp->prod.codigo == codigo){ //Si el codigo esta en la primera iteracion
		*head = temp->next;
		free(temp);
		printf("El numero %d fue borrado.\n",codigo);
		return;
	}
	
	while(temp != NULL && temp->prod.codigo != codigo){ //recorro las listas hasta encontrar el codigo
		prev = temp;
		temp = temp->next;
	}
	if(temp == NULL){
		printf("NO SE ENCONTRO ESE CODIGO\n");
		return;
	}
	
	prev->next = temp->next;	//el siguiente del que borramos lo unicos con el next del anterior (primero prev->) dsps temp->
	free(temp);				//borramos el codigo
	printf("\nProducto con codigo %d eliminado.\n", codigo);
}


void append(struct node**head){ //LISTA
	
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	
	if( new_node == NULL ){
		printf("no hay almacenamiento.\n");
		exit(1);
	}
	
	printf("* Ingrese los datos del producto * ");
	printf("\nIngrese el codigo: ");
	scanf("%d",&new_node->prod.codigo);
	printf("\nIngrese el nombre: ");
	scanf("%s",new_node->prod.nombre);
	printf("\nIngrese la cantidad: ");
	scanf("%d",&new_node->prod.cantidad);
	printf("\nIngrese el precio: \n");
	scanf("%f",&new_node->prod.precio);
	
	new_node->next = NULL;
	
	if(*head == NULL){
		*head = new_node;
	}else{
		struct node *temp = *head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = new_node;
	}
	printf("producto agregado.\n");
}

void print_lista(struct node*head){
	
	struct node*temp = head;
	
	if(head == NULL){
		printf("error!\n");
		exit (1);
	}
	
	printf("Lista de productos: \n");
	printf("codigo\tnombre\tcant\tprecio\n");
	while(temp != NULL){
		printf("%d\t%s\t%d\t%.1f\n",temp->prod.codigo,temp->prod.nombre,temp->prod.cantidad,temp->prod.precio);
		temp = temp->next;
	}
}
	
	
void menu(){
	
	printf("-a)Agregar producto.\n");
	printf("-b)Mostrar lista de productos\n");
	printf("-c)Borre un producto por código de producto.\n");
	printf("-d)Mostrar una lista de los productos sin stock.\n");	
	printf("-s)Salir.\n");
}
