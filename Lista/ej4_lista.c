/*
Crear un programa que cargue 10 letras mayúsculas de manera aleatoria, 
luego crear dos funciones una que muestre y cuente las vocales y otra que muestre y cuente las consonantes de la lista.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
	
	char letra;
	struct node *next;
	
};

void append(struct node **, char );
void print_lista(struct node*);
void mostrar_vocales(struct node*);
void mostrar_consonantes(struct node*);

int main( ) {

	struct node* head = NULL;
	srand(time(NULL));
	int i=0,opc=0;
	
	printf("ingrese \n1)Mostrar vocales \n2)Mostrar consonantes \n3)Mostrar todas las letras \n4)SALIR \n");
	for(i=0;i<10;i++){
		
		char letra = (rand()%26) + 'A';
		append(&head,letra);
	}
	
	do{
		printf("__opc : ");
		scanf("%d",&opc);
		
		switch(opc){
			
		case 1:
			mostrar_vocales(head);
			break;
			
		case 2:
			mostrar_consonantes(head);
			break;
			
		case 3:
			print_lista(head);
			break;
			
		case 4:
			printf("SALIENDO\n");
			break;
		}
		
	} while(opc != 4);
	
	
	return 0;
}

void append(struct node **head, char letra ){
	
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->letra = letra;
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
	
void print_lista(struct node*head){
	
	struct node *temp = head;
	printf("todas las letras: \n");
	while(temp != NULL){
		printf(" %c",temp->letra);
		temp = temp->next;
	}
	printf("\n\n");
	
}
	

	
void mostrar_vocales(struct node*head){
	
	int cont=0;
	struct node *temp = head;
	
	while(temp != NULL){
		
		if(temp->letra == 'A' || temp->letra == 'E' || temp->letra == 'I' || temp->letra == 'O' || temp->letra == 'U' ){
			printf(" %c\t",temp->letra);
			cont++;
		}
		
		temp = temp->next;
	}
	printf("\nHAY %d VOCALES.\n\n",cont);
	
}


void mostrar_consonantes(struct node*head){
	
	int cont=0;
	
	struct node *temp = head;
	
	while(temp != NULL){
		
		if(temp->letra != 'A' && temp->letra != 'E' && temp->letra != 'I' && temp->letra != 'O' && temp->letra != 'U' ){
			printf(" %c\t",temp->letra);
			cont++;
		}
		
		temp = temp->next;
	}
	printf("\nHAY %d CONSONANTES. \n\n",cont);
	
	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
