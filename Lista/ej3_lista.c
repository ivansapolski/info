#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Crear un programa en el cual solicite al usuario la cantidad de números aleatorios a cargar en la lista. 
Los valores aleatorios deben ser entre el 1 y el 100. 
Luego cree un menú de opciones en la cual la opción a muestra la lista de valores, la opción b calcula y muestra solo aquellos valores múltiples de 5 */

struct node{
	int dato;
	struct node *next;
};

void append (struct node**, int);
void menu();
void print_lista(struct node*);
void multiplos5(struct node* );

int main(  ) {

	struct node* head= NULL;
	int nro=0,repetidor=0,opc=0,i=0;
	srand(time(NULL));
	
	printf("\nIngrese la cantidad de veces que desea generar un numero aleatorio: ");
	scanf("%d",&repetidor);
	
	for(i=0;i<repetidor;i++){
		
		nro = (rand()%100)+1;
		append(&head,nro);
		
	}
	
	
	do{
		menu();
		scanf("%d",&opc);
		switch(opc){
		case 1:
			print_lista(head);
			break;
			
		case 2:
			multiplos5(head);
			break;
			
		case 3:
			
			printf("SALIENDO\n");
		}
		
	} while(opc != 3);
	
	return 0;
}

void append (struct node**head, int dato_nodo){
	
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->dato = dato_nodo;
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
	
	if(head == NULL){
		printf("No hay elementos.\n");
		return;
	}
	
	struct node *temp = head;
	printf("\nLista de valores: ");
	while(temp != NULL){
		printf("%d ",temp->dato);
		temp = temp->next;
	}
	
}

void multiplos5(struct node*head ){
	
	int existe=0;
	
	if(head == NULL){
		printf("No hay elementos.\n");
	}
	
	struct node *temp = head;
	printf("\nLista de valores multiplos de 5: ");
	while(temp != NULL){
		if((temp->dato % 5) == 0){
			printf("%d\t",temp->dato);
			existe = 1;
		}
		temp = temp->next;
	}
	
	if( existe == 0 ){
		printf("NO EXISTEN VALORES MULTIPLOS DE 5.\n");
	}
	
}
	
void menu(){
	
	printf("\n1)MOSTRAR LISTA DE VALORES \n2)CALCULA Y MUESTRA SOLO AQUELLOS VALORES MULTIPLOS DE 5 \n3)SALIR DEL MENU\n");
	
}
