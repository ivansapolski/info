/*Desarrolle un programa que cargue una pila de números enteros aleatorios.  
Luego realice un menú de opciones:
- Agregar un nodo a la pila. (cuando agrega un valor, el mismo no tiene que estar repetido en la pila)
- Borrar el último nodo de la pila.
- Imprimir pila.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
	int dato;
	struct node *next;
};

void push(struct node**,int);
void pop(struct node**);
void print(struct node*);

int main( ) {
	
	int opc=0,nro=0,i=0;
	srand(time(NULL));
	
	struct node *sp = NULL;
	
	do{
		printf("__\n1)Push \n2)Pop \n3)Print\n4)Salir\nopc: ");
		scanf("%d",&opc);
		
		switch(opc){
		case 1:
			for(i=0;i<5;i++){
				nro = rand()%10;
				push(&sp,nro);
			}
			printf("Datos cargados!\n");
			break;
			
		case 2:
			pop(&sp);
			break;
			
		case 3:
			print(sp);
			break;
		}
	} while(opc!=4);
	
	return 0;
}

void push(struct node**sp,int valor){

	struct node*temp = NULL;
	temp = *sp;
	
	while(temp != NULL){
		if(temp->dato == valor){
			return;
		}
		temp = temp->next;
	}
	
	struct node* new_node = NULL;
	new_node = (struct node*)malloc(sizeof(struct node*));

	if(new_node == NULL){
		printf("Error de almacenamiento\n");
		exit(0);
	}
	new_node->dato = valor;
	new_node->next = *sp;
	
	*sp = new_node;
}
void pop (struct node**sp){
	
	if(*sp == NULL){
		printf("Pila vacia\n");
		exit(1);
	}
	
	struct node* temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node*));

	temp = *sp;
	
	*sp = (*sp)->next;
	free(temp);
	printf("NODO ELIMINADO\n");
}
void print(struct node*sp){
	
	if(sp == NULL){
		printf("Pila vacia\n");
		exit(1);
	}
	
	struct node* temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node*));
	temp = sp;
	
	printf("La cola es: \n");
	while(temp!=NULL){
		printf("%d\n",temp->dato);
		temp = temp->next;
	}
}
