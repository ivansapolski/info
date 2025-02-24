/*Crear un programa en el cual cargue una cola de 5 números aleatoriamente (entre 1 y 10), 
luego los muestre a todos y muestre solo los valores pares.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
	
	int dato;
	struct node *link;
	
};

void push(struct node**, struct node**,int);
//void pop(struct node**,struct node**);
void print_all(struct node*);
void print_pares(struct node*);


int main( ) {
	
	struct node*back = NULL;
	struct node*front = NULL;
	
	int opc=0,i=0,n=0;
	srand(time(NULL));
	
	printf("1)Cargar 5 numeros aleatorios \n2)Mostrar todos los valores \n3)Mostrar solo los valores pares \n4) SALIR. \n");
	do{
		printf("\n_opc: ");
		scanf("%d",&opc);
		
		switch(opc){
			
		case 1:
			for(i=0;i<5;i++){
				
				n = rand()%10;
				push(&front,&back,n);
			}
			printf("Numeros cargados.\n");
			break;
		case 2:
			print_all(front);
			break;
		case 3:
			print_pares(front);
			break;
		case 4:
			printf("saliendo.\n");
		}
	} while(opc!=4);
	
	
	return 0;
}

void push(struct node**front, struct node**back ,int valor){
	
	struct node *temp;
	temp = (struct node*) malloc(sizeof(struct node));
	
	if(temp == NULL){
		printf("Eror de almacenamiento.\n");
		exit(0);
	}
	
	temp->dato = valor;
	temp->link = NULL;
	
	if(*back == NULL){
		*back = temp;
		*front = *back;
	}else{
		(*back)->link = temp;
		*back = temp;
	}
}

void print_all(struct node*front){

	struct node *temp = NULL;
	temp = front;
	
	printf("La cola completa es: \n");
	while(temp != NULL){
		
		printf("%d\t",temp->dato);
		temp = temp->link;
	}
	
}
void print_pares(struct node*front){
	
	struct node *temp = NULL;
	temp = front;
	
	printf("La cola de los pares es: \n");
	while(temp != NULL){
		
		if((temp->dato)%2 == 0){
			printf("%d\t",temp->dato);
		}
		
		temp = temp->link;
	}
	
}
	
void pop(struct node**front,struct node**back){
	
	struct node *temp;
	temp = (struct node*) malloc(sizeof(struct node));
	
	if((*back == *front)&&(*back == NULL)){
		
		printf("cola vacia.\n");
		exit(1);
	}
	
	temp = *front;
	*front = (*front)->link;
	
	printf("Nodo eliminado.\n");
	free(temp);
}
