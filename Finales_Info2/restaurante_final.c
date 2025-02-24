/*Restaurante
Desarrolla un programa para gestionar los datos de un restaurante mediante un TDA. 
El TDA debe contener la información de los platos disponibles, incluyendo nombre del plato, 
cantidad de platos disponibles (entero), cantidad de platos vendidos (entero) y precio (decimal). 

Implementa las siguientes funciones para:

-Insertar un nuevo plato en el menú.
-Mostrar el menú por consola y generar un archivo txt llamado "menu.txt".
-Eliminar un plato del menú.
-Calcular la recaudación total de los platos vendidos.
-Ordenar los platos por precio usando quicksort.(recursividad).
Además, crea un menú de opciones para que el usuario pueda interactuar con el programa*/
#include <stdio.h>
#include <stdlib.h>

struct plato{
	char nombre[20];
	int cantidad_disponibles;
	int cantidad_vendidos;
	float precio;
};

struct node{
	struct plato p;
	struct node *next;
};

void push(struct node**);
void pop(struct node**);
void print(struct node*);
void recaudacion(struct node*);
void generar_archivo(struct node*);

int main( ) {
	
	struct node*sp = NULL;
	int opc=0;
	
	do{
		printf("\n1)Insertar nuevo plato al menu \n2)Eliminar un plato del menu \n3)Mostrar platos \n4)Mostrar lo recaudado \n5)Salir \n_opc: ");
		scanf("%d",&opc);
		switch(opc){
		case 1:
			push(&sp);
			break;
			
		case 2:
			pop(&sp);
			break;
		case 3:
			print(sp);
			generar_archivo(sp);
			break;
			
		case 4:
			recaudacion(sp);
		}
		
	} while(opc!=5);
	
	return 0;
}

void push(struct node**sp){
	
	struct node*new_node = malloc(sizeof(struct node));
	
	if(new_node==NULL){
		printf("Error de almacenamiento\n");
		exit(0);
	}
	
	printf("\nIngrese el nombre del plato: ");
	scanf(" %s",new_node->p.nombre);
	printf("\nIngrese la cantidad de platos disponibles: ");
	scanf("%d",&new_node->p.cantidad_disponibles);
	printf("\nIngrese la cantidad de platos vendidos: ");
	scanf("%d",&new_node->p.cantidad_vendidos);
	printf("\nIngrese el precio del plato: ");
	scanf("%f",&new_node->p.precio);
	
	new_node->next = *sp;
	*sp = new_node;
}
void pop(struct node**sp){
	
	struct node*temp = malloc(sizeof(struct node));
	
	if(*sp==NULL){
		printf("Pila vacia\n");
		exit(1);
	}
	
	temp = *sp;
	*sp = (*sp)->next;
	free(temp);
	printf("Nodo borrado\n");
}
void print(struct node*sp){
	
	struct node*temp = malloc(sizeof(struct node));
	temp = sp;
	
	printf("Cola de platos: \n");
	printf("Nombre del plato\tCantidad disponible\tCantidad vendida\tPrecio del plato \n");
	while(temp != NULL){
		printf("%s\t\t\t%d\t\t\t%d\t\t\t%.2f\n",temp->p.nombre,temp->p.cantidad_disponibles,temp->p.cantidad_vendidos,temp->p.precio);
		temp = temp->next;
	}
}
	
void recaudacion(struct node *sp){
	
	struct node*temp = malloc(sizeof(struct node));
	temp = sp;
	float acum=0;
	
	while(temp != NULL){
		
		acum = acum + (temp->p.precio * temp->p.cantidad_vendidos);
		
		temp = temp->next;
	}
	printf("Lo recaudado en total es %.2f \n",acum);
}
	
void generar_archivo(struct node *sp){
	
	struct node* temp = malloc(sizeof(struct node));
	temp = sp;
	
	FILE *fp = fopen("menu.txt", "w");
	
	if(fp == NULL){
		printf("El archivo no ha podido ser creado.\n");
		exit(1);
	}
	
	fprintf(fp,"Nombre del plato \t\t Cant Disponible \t\t Cant Vendida \t\t Precio del plato \n");
	
	while(temp != NULL){
		
		fprintf(fp,"%s \t\t\t\t %d \t\t\t\t %d \t\t\t\t %.2f \n",temp->p.nombre,temp->p.cantidad_disponibles,temp->p.cantidad_vendidos,temp->p.precio);
		
		temp = temp->next;
		
	}
	fclose(fp);
	printf(" \nEl menu se ah guardado en menu.txt \n");
	
}
