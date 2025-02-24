#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

void append(struct node**, int);
void mostrar_lista(struct node*);

/*Crear un programa en la cual se solicite al usuario el ingreso de 5 
valores numericos y luego muestre la lista. */

int main(  ) {
	struct node* head = NULL;
	int i=0,valor=0;
	
	printf("ingrese los 5 valores:\n");
	for(i=0;i<5;i++){
		
		scanf("%d",&valor);
		append(&head, valor);
	}
	
	mostrar_lista(head);
	
	return 0;
}

void append (struct node **head, int valor_node){
	
	struct node* new_node = NULL;
	
	//importante reservar memoria
	new_node = (struct node*)malloc(sizeof(struct node)); // Asigna memoria para el nuevo nodo
	if (new_node == NULL) {
		printf("No hay memoria disponible");
		exit(0); // Termina el programa si no hay memoria
	}
	//
	
	struct node *temp = *head;
	new_node->data = valor_node;
	new_node->next = NULL;
	
	if(*head == NULL){
		*head = new_node;
		return;
	}
	
	while(temp->next != NULL){	
		temp = temp->next;
	}//importante recorrerlo

	temp->next = new_node;
	//guardo el nuevo nodo al final de la lista
}
	
void mostrar_lista(struct node *head){
	
	struct node *temp = NULL;
	temp = head;
	
	while(temp != NULL){
		
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	
}
