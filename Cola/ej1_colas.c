/* Crear un programa con el siguiente menu de opciones: 
- Agregar un nodo a la cola. (se deben agregar 5 valores)
- Borrar el primer nodo de la cola.
- Imprimir cola.
- Suma de los valores de la cola. */

#include <stdio.h>
#include <stdlib.h>

struct node{
	int date;
	struct node *link;
};

void menu();
void push(struct node**,struct node**,int valor);
void pop(struct node**,struct node**);
void print_cola(struct node*);
void sumatoria(struct node*);

int main(  ) {

	struct node*back = NULL;
	struct node*front = NULL;
	
	int valor=0,opc=0;
	
	do{
		menu();
		printf("\n_opc: ");
		scanf("%d",&opc);
		
		switch(opc){
			
		case 1:
			for(int i=0;i<5;i++){
				printf("Ingrese el %d valor que desea agregar: ",i+1);
				scanf("%d",&valor);
				push(&front,&back,valor);
			}
			
			break;
			
		case 2:
			pop(&front,&back);
			break;
			
		case 3:
			print_cola(front);
			break;
			
		case 4:
			sumatoria(front);
			break;
			
		case 5:
			printf("Saliendo.");
			break;
			
		}
		
	} while((opc>0 && opc<6) && (opc!= 5));
	
	
	return 0;
}

void menu(){
	
	printf("____________________________\nIngrese:\n");
	printf("1)Agregar nodo a la cola.\n");
	printf("2)Borrar el primer nodo de la cola.\n");
	printf("3)Imprimir la cola.\n");
	printf("4)Suma de los valores.\n");
	printf("5)Salir.\n");
	
}
	
void push(struct node**front,struct node**back, int valor){	
	
	struct node* temp;
	temp = (struct node*) malloc(sizeof(struct node));
	
	if(temp == NULL){
		printf("No hay almacenamiento.\n");
		exit(1);
	}
	
	
	
	temp->date = valor;
	temp->link = NULL;
	
	if(*back == NULL){
		*back = temp;
		*front = *back;
	}else{
		(*back)->link = temp;
		*back = temp;
	}
}
	
void pop(struct node**front, struct node**back){
	
	struct node *temp;
	temp = (struct node*) malloc(sizeof(struct node));
	
	if((*front == *back) && (*back==NULL)){
		printf("COLA VACIA\n");
		exit(0);
	}
	
	temp = *front;
	*front = (*front)->link;
	
	if(*back == temp){
		*back = (*back)->link;
	}
	
	printf("Primer nodo eliminado.\n");
	free(temp);
	
}

void print_cola(struct node*front){ //front porque empieza del primero
	
	struct node *temp = NULL;
	temp = front;
	
	
	printf("La cola es: \n");
	while(temp!=NULL){
		printf("%d\n",temp->date);
		temp = temp->link;
	}
}
	
void sumatoria(struct node*front){
	
	int acum=0;
	struct node*temp = NULL;
	temp = front;
	
	while(temp!=NULL){
		acum = acum + temp->date;
		temp = temp->link;
	}
	printf("LA SUMATORIA ES: %d\n",acum);
}
