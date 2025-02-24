/*Gestión de propiedades	LISTA
Desarrolla un programa que permita la gestión de propiedades en venta y/o en alquiler de una inmobiliaria utilizando el TDA cola. 
Para ello cree la/las estructura/s que necesite para almacenar la siguiente información sobre 
código de propiedad (entero), m2 de terreno (decimal), m2 cubiertos (decimal), tipo operación (En venta/En alquiler), precio (decimal), 
ubicación (cadena) y el estado actual de la propiedad (Desocupada/Ocupada)

Desarrolla las siguientes funciones para: 

-Registrar una nueva propiedad. 
-Mostrar un listado de todas las propiedades por consola y generar un archivo .txt llamado "propiedades.txt", ambos en formato tabla. 
-Borrar una propiedad 
-Mostrar un listado de propiedades por tipo de operación en formato tabla.	(1Venta / 2Alquiler) 
-Calcular la cantidad de propiedades ocupadas y desocupadas. 				(1Desoc / 2 Ocup)
Crea un menú de opciones para que el usuario pueda realizar diferentes acciones antes descritas. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct propiedad{
	int codigo;
	float m_terreno;
	float m_cubiertos;
	int tipo_op;
	float precio;
	char ubicacion[30];
	int estado;
};

struct node{
	struct propiedad p;
	struct node *next;
};

void menu();
void push(struct node**);
void pop(struct node**);
void print(struct node*);
void mostrar_listado(struct node*);
void ocupado_desocupado(struct node*);
void generar_archivo(struct node*);
	
int main( ) {

	struct node* head = NULL;
	int opc=0;
	srand(time(NULL));
	
	do{
		menu();
		scanf("%d",&opc);
		switch(opc){
		case 1:
			push(&head);
			break;
			
		case 2:
			pop(&head);
			break;
			
		case 3:
			print(head);
			generar_archivo(head);
			break;
			
		case 4:
			mostrar_listado(head);
			break;
			
		case 5:
			ocupado_desocupado(head);
			break;
			
		}
		
	} while(opc!=6);
	
	return 0;
}

void generar_archivo(struct node* head){
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("error de almacenamiento");
		return;
	}
	temp = head;
	
	
	FILE *fp = fopen("propiedades.txt","w");
	
	fprintf(fp,"CODIGO\t\t M2 T\t\t\t M2 C\t\tTIPO\t\t\tPRECIO\t\tUBIC\t\t\tESTADO\n");
	while(temp!=NULL){
		fprintf(fp,"%d \t\t %.2f \t\t %.2f \t\t ",temp->p.codigo,temp->p.m_terreno,temp->p.m_cubiertos);
		switch(temp->p.tipo_op){
		case 1:
			fprintf(fp,"En venta\t\t");
			break;
		case 2:
			fprintf(fp,"En alquiler\t\t");
			break;
		}
		fprintf(fp,"%.2f \t\t %s \t\t",temp->p.precio,temp->p.ubicacion);
		switch(temp->p.estado){
		case 1:
			fprintf(fp,"Desocupada\n");
			break;
		case 2:
			fprintf(fp,"Ocupada\n");
			break;
		}
		temp = temp->next;
	}
}

void ocupado_desocupado(struct node*head){
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("error de almacenamiento");
		return;
	}
	temp = head;
	int ocupado=0,desocupado=0;
	
	while(temp!=NULL){
		if(temp->p.estado == 1){
			desocupado++;
		}else{
			ocupado++;
		}
		temp = temp->next;
	}
	printf("Hay %d viviendas ocupadas.\n",ocupado);
	printf("Y %d viviendas desocupadas.",desocupado);
}

void mostrar_listado(struct node*head){
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("error de almacenamiento");
		return;
	}
	temp = head;
	
	printf("**Lista de propiedades en venta: **\n");
	printf("CODIGO\t\t M2 T\t\t\t M2 C\n");
	while(temp != NULL){
		if(temp->p.tipo_op == 1){
			printf("%d \t\t %.2f \t\t %.2f \n",temp->p.codigo,temp->p.m_terreno,temp->p.m_cubiertos);
		}
		temp = temp->next;
	}
	temp = head;
	printf("\n**Lista de propiedades en alquiler: **\n");
	printf("CODIGO\t\t M2 T\t\t\t M2 C\n");
	while(temp != NULL){
		if(temp->p.tipo_op == 2){
			printf("%d \t\t %.2f \t\t %.2f \n",temp->p.codigo,temp->p.m_terreno,temp->p.m_cubiertos);
		}
		temp = temp->next;
	}	
	
}

void print(struct node* head){
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("error de almacenamiento");
		return;
	}
	temp = head;
	
	printf("CODIGO\t\t M2 T\t\t\t M2 C\t\tTIPO\t\t\tPRECIO\t\tUBIC\t\t\tESTADO\n");
	while(temp!=NULL){
		printf("%d \t\t %.2f \t\t %.2f \t\t ",temp->p.codigo,temp->p.m_terreno,temp->p.m_cubiertos);
		switch(temp->p.tipo_op){
		case 1:
			printf("En venta\t\t");
			break;
		case 2:
			printf("En alquiler\t\t");
			break;
		}
		printf("%.2f \t\t %s \t\t",temp->p.precio,temp->p.ubicacion);
		switch(temp->p.estado){
		case 1:
			printf("Desocupada\n");
			break;
		case 2:
			printf("Ocupada\n");
			break;
		}
		temp = temp->next;
	}
}

void pop(struct node** head){
	
	struct node* temp = *head;
	struct node* prev = NULL;
	int borrar=0;
	
	printf("\ningrese el codigo de propiedad que desea borrar: ");
	scanf("%d",&borrar);
	
	if(temp!=NULL && temp->p.codigo == borrar){
		*head = temp->next;
		free(temp);
		printf("Eliminado.\n");
		return;
	}
	
	while(temp!=NULL && temp->p.codigo != borrar){
		prev = temp;
		temp = temp->next;
	}
	if(temp == NULL){
		printf("No se encontro el numero.\n");
		return;
	}
	prev->next = temp->next;
	free(temp);
	printf("Eliminado.\n");
}

void push(struct node** head){
	
	struct node* new_node = malloc(sizeof(struct node));
	if(new_node == NULL){
		printf("error de almacenamiento\n");
		exit(1);
	}
	
	printf("\ningrese el codigo de propiedad: ");
	scanf("%d",&new_node->p.codigo);
	new_node->p.m_terreno = rand() %200 + 100;
	new_node->p.m_cubiertos = rand()%100 + 1;
	printf("Que tipo de operacion es?\n1)En venta \n2)En alquiler \n");
	scanf("%d",&new_node->p.tipo_op);
	printf("\nIngrese el precio: ");
	scanf("%f",&new_node->p.precio);
	printf("\nIngrese la ubicacion:");
	scanf("%s",new_node->p.ubicacion);
	new_node->p.estado = rand() %2+1;
	
	new_node->next = NULL;
	
	if(*head == NULL){
		*head = new_node;
	}else{
		struct node* temp = *head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = new_node;
	}
}

void menu(){
	printf("\n___\nIngrese: \n");
	printf("1)Registrar nueva propiedad. \n");
	printf("2)Borrar una propiedad. \n");
	printf("3)Mostrar un listado de todas las propiedades por consola y generar un txt .\n");
	printf("4)Mostrar un listado de propiedades por tipo de operación en formato tabla. \n");
	printf("5)Calcular la cantidad de propiedades ocupadas y desocupadas. \n");
	printf("6)SALIR. \n");
	printf("opc: ");
}
