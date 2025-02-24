/*Crear un programa con el siguiente menú de opciones: 
- Agregar un nodo a la pila. (se deben agregar 5 valores)
- Borrar el último nodo de la pila.
- Imprimir pila.
- Suma de los valores de la pila
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int dato;
	struct node*next;
};

void push(struct node**,int);
void pop(struct node**);
void print(struct node*);
void sumatoria(struct node*);

int main( ) {

	struct node* sp = NULL;
	
	int opc=0,valor=0;
	
	do{
		printf("________\n1)Push \n2)Pop \n3)Print \n4)Suma valores de la pila \n5)Salir. \n_opc: ");
		scanf("%d",&opc);
		switch (opc) {
		case 1:
			for (int i=0;i<5;i++){
				printf("\nIngrese el %d valor : ",i+1);
				scanf("%d",&valor);
				push(&sp,valor);
			}
			break;
		case 2:
			pop(&sp);
			break;
		case 3:
			print(sp);
			break;
			
		case 4:
			sumatoria(sp);
			break;
			
		case 5:
			
			break;
			
		};
	} while(opc!=5);
	
	return 0;
}

void push(struct node**sp,int valor){
	
	struct node *new_node = NULL;
	new_node = (struct node*)malloc(sizeof(struct node));
	
	if(new_node == NULL){
		printf("Error de almacenamiento\n");
		exit(0);
	}
	
	new_node->dato = valor;
	new_node->next = *sp;

	*sp = new_node;
}

void pop(struct node**sp){
	
	struct node *temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	
	if(*sp==NULL){
		printf("Pila vacia.\n");
	}
	
	temp = *sp;
	*sp = (*sp)->next;
	free(temp);
	printf("Nodo eliminado.\n");
}

void print(struct node*sp){

	struct node *temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = sp;
	
	printf("La pila es: \n");
	while( temp != NULL ){
		printf("%d\n",temp->dato);
		temp = temp->next;
	}
	
}
	
void sumatoria(struct node*sp){	
	
	int acum=0;
	
	struct node *temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = sp;

	while( temp != NULL ){
		acum += temp->dato;
		temp = temp->next;
	}	
	
	printf("La suma de la pila es: %d\n",acum);

}
