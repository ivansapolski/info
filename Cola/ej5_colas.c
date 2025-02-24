/*Desarrolle un programa que cargue una cola de números enteros aleatorios. Luego realice un menú de opciones:
- Agregar un nodo a la cola. (cuando agrega un valor, el mismo no tiene que estar repetido en la cola)
- Borrar el primer nodo de la cola.
- Imprimir cola.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
	int dato;
	struct node *link;
};

void push(struct node**,struct node**,int);
void pop(struct node**,struct node**);
void print(struct node*);
int chek_rep(struct node*,int);

int main( ) {
	
	struct node* front = NULL;
	struct node* back = NULL;
	
	srand(time(NULL));
	
	int nro=0,opc=0,existe=0;
	
	printf("1)Agregar un nodo a la cola. \n2)Borrar un nodo \n3)Imprimir la cola \n4) SALIR. \n");
	do{
		printf("\n_opc: ");
		scanf("%d",&opc);
		
		switch(opc){
			
		case 1:
			
			do{
				printf("Ingrese el numero que desea agregar: ");
				scanf("%d",&nro);
				existe = chek_rep(front,nro);
				
				if(existe == 5){
					printf("ya existe ese nro \n-intente con otro.\n");
				}else{
					push(&front,&back,nro);
					printf("Numero %d cargado\n",nro);
				}
				
			} while(existe == 5);
			
			break;
		case 2:
			pop(&front,&back);
			break;
		case 3:
			print(front);
			break;
		case 4:
			printf("saliendo.\n");
		}
	} while(opc!=4);
	
	
	return 0;
}

void push(struct node**front,struct node**back,int nro){
	
	struct node *temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	
	if(temp == NULL){
		printf("Error de almacenamiento\n");
		exit(1);
	}
	
	temp->dato = nro;
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
	temp = (struct node*)malloc(sizeof(struct node));
	
	if(*back == NULL){
		printf("cola vacia\n");
		exit(1);
	}
	
	temp = *front;
	*front = (*front)->link;
	free(temp);
	printf("nodo eliminado\n");
	
}
void print(struct node*front){
	
	struct node *temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = front;
	
	printf("La cola es : \n");
	while(temp != NULL){
		printf("%d\t",temp->dato);
		temp = temp->link;
	}
	
}

int chek_rep(struct node*front,int nro){
	
	struct node *temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = front;
	
	while(temp != NULL){
		if( temp->dato == nro ){
			return 5;
		}
		temp = temp->link;
	}
	return 0;
}
