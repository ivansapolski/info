/*Construcción
Implementa un programa que gestione los datos de un proyecto de construcción utilizando un TDA. 
El TDA debe almacenar información sobre las diferentes tareas del proyecto, incluyendo nombre de la tarea, duración estimada (entero) y 
estado de la tarea (pendiente/terminada/retrasada). Desarrolla las siguientes funciones para:

-Agregar una nueva tarea al proyecto.
-Mostrar la lista de tareas por consola y generar un archivo txt llamado "proyecto.txt".
-Eliminar una tarea del proyecto.
-Calcular el porcentaje de avance del proyecto.
-Ordenar las tareas por duración estimada usando quicksort.
Crea un menú de opciones para que el usuario pueda realizar diferentes acciones*/
#include <stdio.h>
#include <stdlib.h>

struct proyecto{
	char nombre[50];
	int duracion;
	int estado;
};

struct node{
	struct proyecto p;
	struct node *next;
};

void menu();
void push(struct node**);
void print(struct node*);
void generar_archivo(struct node*);
void pop(struct node**);
void porcentaje(struct node*);
//void ordenar;

int main( ) {
	
	struct node*head = NULL;
	int opc=0;
	
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
			porcentaje(head);
			break;
			
		case 5:
			printf("saliendo..\n");
			break;
		}
		
	} while(opc!=5);
	
	
	return 0;
}

void generar_archivo(struct node* head){
	
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp = head;
	
	FILE *fp = fopen("proyecto.txt","w");
	
	if(fp==NULL){
		printf("error de almacenamiento");
		exit(1);
	}
	
	fprintf(fp,"NOMBRE \t\t DURACION \t ESTADO \n");
	while(temp!=NULL){
		
		fprintf(fp,"%s \t\t %d \t\t ",temp->p.nombre,temp->p.duracion);
		
		switch(temp->p.estado){
		case 1:
			fprintf(fp,"Pendiente\n");
			break;
		case 2:
			fprintf(fp,"Terminada\n");
			break;
		case 3:
			fprintf(fp,"Retrasada\n");
			break;
		}
		temp = temp->next;
	}
	
	fclose(fp);
	
}

void porcentaje(struct node* head){
	
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp = head;
	float acum=0,cont=0;
	
	while(temp != NULL){
		cont++;
		//pend term retras
		if(temp->p.estado==2){ //tarea terminada
			acum++;
		}
		temp = temp->next;
	}
	
	printf("El porcentaje de la obra es de %.2f",((float)(acum*100/cont)));
	
}

void print(struct node *head){
	
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp = head;
	
	printf("\nNOMBRE \t\t DURACION \t ESTADO DE LA TAREA\n");
	while(temp != NULL){
		
		printf("%s \t\t %d \t\t ",temp->p.nombre,temp->p.duracion);
		
		switch(temp->p.estado){
		case 1:
			printf("Pendiente\n");
			break;
		case 2:
			printf("Terminada\n");
			break;
		case 3:
			printf("Retrasada\n");
			break;
		}
		temp = temp->next;
	}
	
}

void pop(struct node **head){
	
	
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	
	if(*head == NULL){
		printf("VACIA");
		exit(0);
	}
	
	temp = *head;
	
	*head = (*head)->next;
	free(temp);
	printf("Eliminado.\n");
}

void push(struct node **head){
	
	struct node* new_node =(struct node*) malloc(sizeof(struct node));
	
	if(new_node == NULL){
		printf("error de almacenamiento\n");
		exit(1);
	}
	
	printf("\nIngrese el nombre: ");
	scanf("%s",new_node->p.nombre);
	printf("\nIngrese la duracion estimada: ");
	scanf("%d",&new_node->p.duracion);
	printf("\nIngrese el estado (1-PENDIENTE 2-TERMINADA 3-RETRASADA):");
	scanf("%d",&new_node->p.estado);
	
	new_node->next = NULL;
	
	if(*head == NULL){
		*head = new_node;
	}else{
		struct node *temp = *head;
		
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = new_node;
	}
	printf("\nServicio agregado.\n");
}

void menu(){
	
	printf("\n_________\nIngrese: \n");
	printf("1)Agregar nueva tarea al proyecto. \n");
	printf("2)Mostrar la lista de tareas por consola y generar un archivo txt. \n");
	printf("3)Eliminar una tarea del proyecto. \n");
	printf("4)Calcular el porcentaje de avance del proyecto. \n");
	printf("5)Ordenar las tareas por duración estimada usando quicksort. \n\n");
}
