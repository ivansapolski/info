/*Crear un programa que muestre un menu de opciones que admite mayuscula y minuscula. 
Para el caso a llamara a una funcion en la cual permite el ingreso de valores numericos. 
Para el caso b llamara una funcion que muestre la lista y para el caso c llamara una 
funcion que calcule y retorne el promedio de los valores de la lista.  */
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
	
};

void menu();
void append(struct node**,int);
void print_list(struct node*);
float calcular_promedio(struct node*);

int main( ) {
	struct node* head = NULL;
	char opc;
	int valor=0;
	
	menu();
	do{
		printf("\n___opc:");
		scanf(" %c",&opc);
		
		switch(opc){
			
		case 'a':
		case 'A':
			printf("Ingrese un valor numerico: \n");
			scanf("%d",&valor);
			append(&head,valor);
			break;
			
		case 'b':
		case 'B':
			print_list(head);
			break;
			
		case 'c':
		case 'C':
			
			if(calcular_promedio(head) == -1){
				printf("-Error al imprimir la lista-\n");
			}else{
				printf("El promedio es: %.2f \n",calcular_promedio(head));
			}
			
			break;
			
		case 'd':
		case 'D':
			printf("saliendo..\n");
			opc = 'd';
			break;
			
		}
		
	} while(opc != 'd');
	
	
	
	return 0;
}

void menu(){
	
	printf("\n**MENU**. \n");
	printf("A. Llamar funcion que permite ingreso de valores numericos \n");
	printf("B. Llamar funcion que muestre la lista \n");
	printf("C. Llamar funcion que calcule y retorne el promedio de los valores de la lista \n");
	printf("D. Salir \n");
	
}
void append(struct node**head,int node_data){
	
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = node_data;
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
	
float calcular_promedio(struct node* head){
	
	if(head == NULL){
		return -1;
	}
	
	struct node *temp = head;
	int acum=0,cont=0;
	
	while(temp != NULL){
		
		acum = acum + temp->data;
		cont++;
		temp = temp->next;
		
	}
	return (float) acum/cont;
}
	
void print_list(struct node* head){
	
	if( head == NULL){
		printf("La lista esta vacia.\n");
		return;
	}
	
	struct node *temp = head;
	printf("Lista de valores: \n");
	while(temp != NULL){
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	
}
