/*Crear un programa en el cual cargue una lista de 5 números aleatoriamente (entre 1 y 10), luego los muestre todos los valores. 
Finalmente borre un valor y vuelve a mostrar la lista resultante. Genere un menú de opciones para las funciones.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
	
	int dato;
	struct node *next;
	
};

void menu();
void append(struct node**,int);
void print_lista(struct node*);
void delete_node(struct node**,int);


int main(  ) {
	
	int nro=0,i=0,borrar=0,opc=0;
	srand(time(NULL));
	struct node *head = NULL;
	
	
	
	for(i=0;i<5;i++){
		
		nro = ( rand() %10 ) +1;
		append(&head,nro);
		
	}
	do{
		menu();
		printf("\n_OPC: ");
		scanf("%d",&opc);
		
		switch(opc){
			
		case 1:
			print_lista(head);
			break;
			
		case 2:
			printf("\nIngrese el valor que desea eliminar: ");
			scanf("%d",&borrar);
			delete_node(&head,borrar);
			break;
			
		case 3:
			printf("SALIENDO..");
			break;
			
		}
		
	} while(opc != 3);
	
	return 0;
}

void append(struct node**head ,int valor_nodo){
	
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	
	new_node->dato = valor_nodo;
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
}
	
void delete_node(struct node**head,int valor){
	
	struct node *temp = *head;
	struct node *prev = NULL;
	
	if(temp == NULL){
		printf("LA LISTA ESTA VACIA\n");
		return;
	}
	if( temp != NULL && temp->dato == valor ){ //si el nro esta en el primer nodo
		*head = temp->next;
		free(temp);
		printf("Valor %d fue borrado.\n",valor);
		return;
	}
	while(temp != NULL && temp->dato != valor){ //buscar el valor a borrar
		prev = temp;
		temp = temp->next;
	}
	if(temp == NULL){
		printf("NO EXISTE ESE NUMERO PARA BORRARLO\n");
		return;
	}
	prev->next = temp->next;
	free(temp);
	printf("Valor %d eliminado.",valor);	
}

	
void print_lista(struct node*head){
	
	struct node *temp = head;
	printf("Los numeros son: \n");
	while( temp != NULL ){
		
		printf("%d\t",temp->dato);
		temp = temp->next;
	}
	
	
}

void menu(){
	
	printf("\ningrese. \n1)Mostrar lista. \n2)Borrar nodo. \n3)SALIR. \n");
	
}
