/*Crear un programa con el siguiente menú de opciones: 
- Agregar un nodo a la cola.
- Borrar el primer nodo de la cola.
- Imprimir cola.
- Cantidad de nodos en la cola.
- Cantidades de letras mayúsculas y minúsculas en la cola.

El usuario cargará la cola con letras mayúsculas o minúsculas. 
Nota: Las letras en ASCII mayúsculas están entre el 65 a 90 y las minúsculas entre  97 a 122 inclusive.

*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	char letra;
	struct node*link;
};

void push(struct node**,struct node**,char);
void pop(struct node**,struct node**);
void print(struct node*);
void cant_nodos(struct node*);
void cant_min_mayus(struct node*);

int main( ) {
	
	struct node *back = NULL;
	struct node *front = NULL;
	
	int opc=0;
	char letra;
	printf("1)Agregar nodo \n2)Borrar nodo \n3)Imprimir cola \n4)Cant de nodos \n5)Cant de mayus y minusculas \n6)Salir \n");
	do{
		printf("\n_opc: ");
		scanf("%d",&opc);
		switch(opc){
		case 1:
			printf("Ingrese una letra: ");
			scanf(" %c",&letra);
			push(&front,&back,letra);
			break;
			
		case 2:
			pop(&front,&back);
			break;
			
		case 3:
			print(front);
			break;
			
		case 4:
			cant_nodos(front);
			break;
			
		case 5:
			cant_min_mayus(front);
			break;
		case 6:
			printf("Saliendo...\n");
		}
	} while(opc != 6);
	
	return 0;
}

void push(struct node**front,struct node**back,char letra){
	
	struct node *temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	
	if(temp==NULL){
		printf("error de almacenamiento\n");
		exit(0);
	}
	
	temp->letra = letra;
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
	printf("nodo eliminado \n");	
}
	
void print(struct node*front){
	struct node *temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = front;
	
	printf("La cola es: \n");
	while(temp!=NULL){
		printf("%c\t",temp->letra);
		temp = temp->link;
	}
}
	
void cant_nodos(struct node*front){		
	
	int acum=0;
	
	struct node *temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = front;
	
	
	while(temp!=NULL){
		acum++;
		temp = temp->link;
	}
	
	printf("Hay %d nodos.\n",acum);
}
	
void cant_min_mayus(struct node*front){
	
	int mayusculas=0,minusculas=0;
	
	struct node *temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = front;
	
	//Nota: Las letras en ASCII mayúsculas están entre el 65 a 90 y las minúsculas entre  97 a 122 inclusive.
	while(temp!=NULL){
		
		if(temp->letra >= 65 && temp->letra <= 90){
			mayusculas++;
		}else{
			if(temp->letra >= 97 && temp->letra <= 122){
				minusculas++;
			}
		}
		
		temp = temp->link;
	}
	printf("Hay %d MAYUSCULAS.\n",mayusculas);
	printf("Hay %d minusculas.\n",minusculas);
	
}
