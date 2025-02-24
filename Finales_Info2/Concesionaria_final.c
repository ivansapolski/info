/*Concesionaria
Crea un programa para gestionar un inventario de automóviles utilizando un TDA. El TDA debe contener información sobre cada automóvil, 
incluyendo modelo, stock (entero), y precio (decimal). Desarrollar las siguientes funciones para:

-Agregar un nuevo modelo de automóvil al inventario.
-Mostrar el inventario por consola y generar un archivo txt llamado "inventario.txt".
-Eliminar un modelo de automóvil del inventario.
-Calcular el valor total del inventario.
-Ordenar de manera por stock de menor a mayor los modelos disponibles en el inventario usando quicksort
Diseña un menú de opciones para que el usuario pueda interactuar con el programa.*/
#include <stdio.h>
#include <stdlib.h>

struct concesionaria{
	char modelo[20];
	int stock;
	float precio;
};

struct node{
	struct concesionaria c;
	struct node *next;
};

void menu();
void push(struct node**);
void pop(struct node**);
void print(struct node*);
void valor(struct node*);
void generar_archivo(struct node*);

int main( ) {
	
	int opc=0;
	struct node*head = NULL;
	do{
		menu();
		scanf("%d",&opc);
		switch(opc){
		case 1:
			push(&head);
			break;
			
		case 2:
			print(head);
			generar_archivo(head);
			break;
			
		case 3:
			pop(&head);
			break;
			
		case 4:
			valor(head);
			break;
			
		case 5:
			printf("saliendo..");
		}
	} while(opc!=5);
	
	return 0;
}

void generar_archivo(struct node*head){
	
	FILE *fp = fopen("inventario.txt","w");
	
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp = head;
	
	fprintf(fp,"MODELO \t\t\t STOCK \t\t PRECIO \n");
	while(temp!=NULL){
		fprintf(fp,"%s \t\t\t %d \t\t %.2f \n",temp->c.modelo,temp->c.stock,temp->c.precio);
		temp = temp->next;
	}
}

void valor(struct node*head){
	
	float acum=0;
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp = head;
	
	while(temp!=NULL){
		acum += temp->c.precio;
		temp = temp->next;
	}
	printf("EL TOTAL ES %.2f \n",acum);
}

void print(struct node*head){
	
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp = head;
	
	printf("MODELO \t\t\t STOCK \t\t PRECIO \n");
	while(temp!=NULL){
		printf("%s \t\t\t %d \t\t %.2f \n",temp->c.modelo,temp->c.stock,temp->c.precio);
		temp = temp->next;
	}
}

void pop(struct node **head){
	
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp = *head;
	
	*head = (*head)->next;
	free(temp);
	printf("Eliminado?\n");
}

void push(struct node **head){
	
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	
	if(new_node == NULL){
		printf("error de almacenamiento\n");
		exit(0);
	}	
	
	printf("ingrese modelo: ");
	scanf("%s",new_node->c.modelo);
	printf("\ningrese stock: ");
	scanf("%d",&new_node->c.stock);
	printf("\ningrese precio: ");
	scanf("%f",&new_node->c.precio);
	
	new_node->next = NULL;
	
	if(*head==NULL){
		*head = new_node;
	}else{
		struct node* temp = *head;
		
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = new_node;
	}
	printf("vehiculo ingresado.\n");
}
void menu(){
	
	printf("____\nIngrese \n");
	printf("1)Agregar un nuevo automovil. \n");
	printf("2)Mostrar el inventario por consola y generar un archivo txt llamado Inventario. \n");
	printf("3)Eliminar un modelo de automóvil del inventario. \n");
	printf("4)Calcular el valor total del inventario. \n");
	
}
