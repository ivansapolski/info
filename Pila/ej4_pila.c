/*Crear un programa con el siguiente menú de opciones: 
- Agregar un nodo a la pila.
- Borrar el último nodo de la pila.
- Imprimir pila.
- Cantidad de nodos en la pila.
- Cantidades de letras mayúsculas y minúsculas en la pila.

El usuario cargará la pila con letras mayúsculas o minúsculas. 
Nota: Las letras en ASCII mayúsculas están entre el 65 a 90 y las minúsculas entre  97 a 122 inclusive */

#include <stdio.h>
#include <stdlib.h>

struct node{
	char letra;
	struct node *next;
};

void push(struct node**,char);
void pop(struct node**);
void print(struct node*);
void cant_nodos(struct node*);
void cant_mayus(struct node*);

int main(  ) {
	
	struct node*sp = NULL;
	int opc;
	char letra;
	
	do{
		printf("1)Push \n2)Pop \n3)Mostrar toda la pila\n4)Cantidad de nodos\n5)Cantidad de mayusculas y minusculas\n6)Salir\n_opc:");
		scanf("%d",&opc);
		switch (opc) {
		case 1:
			printf("Ingrese la letra: ");
			scanf(" %c",&letra);
			push(&sp,letra);
			break;
		case 2:
			pop(&sp);
			break;
		case 3:
			print(sp);
			break;
		case 4:
			cant_nodos(sp);
			break;
		case 5:
			cant_mayus(sp);
			break;
		};
	} while(opc!=6);
	
	return 0;
}

void push(struct node**sp,char letra){
	
	struct node* new_node = NULL;
	new_node = (struct node*)malloc(sizeof(struct node));
	
	if(new_node == NULL){
		printf("No hay almacenamiento\n");
		exit(0);
	}
	new_node->letra = letra;
	new_node->next = *sp;
	*sp = new_node;
}

void pop(struct node**sp){
	
	struct node* temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	if(temp == NULL){
		printf("Error de almacenamiento\n");
		exit(0);
	}
	temp = *sp;
	
	*sp = (*sp)->next;
	
	free(temp);
	printf("nodo eliminado\n");
}
	
void print(struct node*sp){
	
	struct node* temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("Error de almacenamiento\n");
		exit(0);
	}
	temp = sp;
	
	printf("Pila de nodos: \n");
	while(temp != NULL){
		printf("%c\n",temp->letra);
		temp = temp->next;
	}	
}

void cant_nodos(struct node*sp){
	
	int cantidad=0;
	
	struct node* temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("Error de almacenamiento\n");
		exit(0);
	}
	
	temp = sp;
	
	printf("Cantidad de nodos: \n");
	while(temp != NULL){
		cantidad++;
		temp = temp->next;
	}
	printf("Hay %d nodos\n",cantidad);
}
//Las letras en ASCII mayúsculas están entre el 65 a 90 y las minúsculas entre  97 a 122 inclusive
void cant_mayus(struct node*sp){
	
	int mayusculas=0,minusculas=0;
	
	struct node* temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("Error de almacenamiento\n");
		exit(0);
	}
	temp = sp;
	
	while(temp != NULL){
		if(temp->letra >= 65 && temp->letra <= 90){
			mayusculas++;
		}else{
			if(temp->letra >= 97 && temp->letra <= 122){
				minusculas++;
			}
		}
		temp = temp->next;
	}
	printf("Hay %d MAYUSCULAS\n",mayusculas);
	printf("Hay %d minusculas\n",minusculas);
}
