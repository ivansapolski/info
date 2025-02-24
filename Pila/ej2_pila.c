/*Crear un programa en el cual cargue una pila de 5 números aleatoriamente (entre 1 y 10), 
luego los muestre a todos y muestre solo los valores pares.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
	int dato;
	struct node *next;
};

void push (struct node**,int);
void print_all (struct node*);
void print_pares (struct node*);

int main(  ) {
	
	srand(time(NULL));
	struct node *sp = NULL;

	int opc=0,nro=0;
	
	do{
		printf("________\n1)Push \n2)Print all \n3)Print pares \n4)Salir. \n_opc: ");
		scanf("%d",&opc);
		switch (opc) {
		case 1:
			for(int i=0;i<5;i++){
				nro = rand()%10;
				push(&sp,nro);
			}
			printf("5 valores de la pila cargados.\n");
			break;
		case 2:
			print_all(sp);
			break;
		case 3:
			print_pares(sp);
			break;
		case 4:
			printf("Saliendo..\n");
			break;
		};
	} while(opc!=4);
	
	return 0;
}

void push(struct node**sp,int valor){
	
	struct node *new_node = NULL;
	new_node = (struct node*)malloc(sizeof(struct node));
	if(new_node == NULL){
		printf("No hay almacenamiento\n");
		exit(1);
	}
	
	new_node->dato = valor;
	new_node->next = *sp;
	
	(*sp) = new_node;
}
	
void print_all(struct node*sp){
	
	struct node *temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp=sp;
	
	printf("La pila es: \n");
	while(temp != NULL){
		printf("%d\n",temp->dato);
		temp = temp->next;
	}
}
	
void print_pares(struct node*sp){
	
	struct node *temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp=sp;
	
	printf("La pila solo con los pares es: \n");
	while(temp != NULL){
		if( temp->dato %2 == 0){
			printf("%d\n",temp->dato);
		}
		temp = temp->next;
	}
}
