/*Crear un programa con el siguiente menú de opciones: 
- Agregar un nodo a la pila. (se deben agregar 5 valores)
- Borrar el último nodo de la pila.
- Imprimir pila.
- Tamaño de la pila
- Mostrar el último valor de la pila
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
	int dato;
	struct node *next;
};

void push(struct node**,int);
void pop(struct node**);
void print(struct node*);
void mostrar_tamano(struct node*);

int main( ) {
	struct node *sp = NULL;
	int opc=0,i=0,valor=0;
	
	do{
		printf("_____\n1)Push \n2)Pop \n3)Mostrar pila \n4)Tamano de la pila \n5)Ultimo valor de la pila \n6)Salir \n_opc:");
		scanf("%d",&opc);
		switch (opc) {
		case 1:
			for(i=0;i<5;i++){
				printf("ingrese el valor %d de la pila: ",i+1);
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
			mostrar_tamano(sp);
			break;
		case 5:
			printf("El ultimo valor es: %d\n",sp->dato);
			break;
		case 6:
			printf("Saliendo...\n");
			break;
		};
	} while(opc!=6);
	
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
	
	struct node*temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	
	if(sp==NULL){
		printf("Pila vacia\n");
		exit(0);
	}
	
	temp = *sp; //El ultimo nodo (que queremos borrar) lo guardamos en un temporal	
	*sp = (*sp)->next; //Y el siguiente al stackpointer pasa a ser el sp
	free(temp); //Borramos el anterior sp 
	printf("Nodo borrado\n");
}
	
void print(struct node*sp){
	
	struct node*temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = sp;
	
	printf("La pila es: \n");
	while(temp != NULL){
		printf("%d\n",temp->dato);
		temp = temp->next;
	}
}
	
void mostrar_tamano(struct node *sp){
	
	int acum=0;
	struct node*temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = sp;
	
	printf("La pila es: \n");
	while(temp != NULL){
		acum ++;
		temp = temp->next;
	}
	printf("Hay %d nodos.\n",acum);
}
