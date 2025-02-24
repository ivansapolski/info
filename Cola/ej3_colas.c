/*Desarrolle un programa que cargue una cola de números enteros aleatorios y muestre. 
Luego arme una función que muestre el tamaño de la cola y otra función que muestre el valor del frente de la cola.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
	int dato;
	struct node *link;
};

void push(struct node**,struct node**,int);
void pop(struct node**,struct node**);
int tamano(struct node*);
void print(struct node*);

int main( ) {

	struct node *back = NULL;
	struct node *front = NULL;
	
	int opc=0,nro=0,v=0;
	srand(time(NULL));
	
	printf("1)Generar numeros aleatorios \n2)Borrar un nodo \n3)Tamano de la cola \n4)Valor del front \n5)Salir \n");
	do{
		printf("\n_opc: ");
		scanf("%d",&opc);
		switch (opc){
			
		case 1:
			
			v = rand()%5;
			
			for(int i=0;i<v;i++){
				nro = rand()%50;
				push(&front,&back,nro);
			}
			printf("Numeros generados\n");
			print(front);
			break;
			
		case 2:
			pop(&front,&back);
			break;
			
		case 3:
			printf("el tamano de la cola es de %d nodes.\n",tamano(front));
			break;
		case 4:
			printf("el valor del front es: %d \n",front->dato);
			break;
			
		case 5:
			printf("saliendo.\n");
		}
		
		
	} while(opc!=5);
	
	
	return 0;
}

void push(struct node**front, struct node**back, int valor){
	
	struct node *temp = NULL;
	temp = (struct node*) malloc(sizeof(struct node));
	
	if(temp == NULL){
		printf("no hay suficiente espacio.\n");
		exit(1);
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

void pop(struct node**front,struct node**back){
	
	struct node *temp = NULL;
	temp = (struct node*) malloc(sizeof(struct node));
	
	if((*back == *front)&&(*back == NULL)){
		printf("cola vacia\n");
		exit(0);
	}
	
	temp = *front;
	*front = (*front)->link;
	free(temp);
	printf("Nodo eliminado.\n");
	
}

int tamano(struct node*front){
	
	int cont=0;
	
	struct node *temp = NULL;
	temp = (struct node*) malloc(sizeof(struct node));
	
	temp = front;
	
	while( temp != NULL ){
		
		cont++;
		temp = temp->link;
	}
	return cont;
}
	
void print(struct node*front){
	
	struct node *temp = NULL;
	temp = (struct node*) malloc(sizeof(struct node));
	
	temp = front;
	
	printf("La cola es: \n");
	while (temp != NULL){
		printf("%d\t",temp->dato);
		temp = temp->link;
	}
	
}
