/*Gestión de Reservas de Cruceros		PILA
Desarrolla un programa que permita la gestión de reservas en una empresa de cruceros utilizando el TDA pila. 
Para ello cree la/las estructura/s que necesite para almacenar la siguiente información sobre 
número de reserva (entero), nombre del pasajero (cadena), número de cabina (entero), costo por noche (decimal), cantidad de noches (entero), 
día (entero) y mes (entero) de la reserva. 

Crea un menú de opciones que se repetirá hasta que el usuario decida finalizar el programa. Este menú debe permitir la elección de opciones en letras mayúsculas 
o minúsculas y, para cada caso, llamará a las siguientes funciones:

-Registrar una nueva reserva. 
-Mostrar un listado de todas las reservas por consola y generar un archivo .txt llamado "reserva_crucero.txt", ambos en formato tabla. 
-Borrar una reserva 
-Mostrar un listado de reservas por mes en formato tabla. El mes es ingresado por el usuario
-Calcular la cantidad de reservas cuyo costo total sea mayor a 2000. 
Nota: Los datos pueden ser cargados o bien utilizar números aleatorios*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct reserva{
	int reserva;
	char nombre[20];
	int cabina;
	float precio;
	int cantidad;
	int dia;
	int mes;
};

struct node{
	struct reserva r;
	struct node *next;
};

void menu();
void push(struct node**);
void pop(struct node**);
void print(struct node*);
void listado_mes(struct node*);
void generar_archivo(struct node*);
void reservas_mayores(struct node*);

int main(  ) {
	
	struct node *head = NULL;
	char opc;
	
	do{
		menu();
		scanf(" %c",&opc);
		switch(opc){
		case 'a':
		case 'A':
			push(&head);
			break;
		case 'b':
		case 'B':
			pop(&head);
			break;
		case 'c':
		case 'C':
			print(head);
			generar_archivo(head);
			break;
			
		case 'd':
		case 'D':
			listado_mes(head);
			break;
			
		case 'e':
		case 'E':
			reservas_mayores(head);
			break;
			
		case 'S':
			opc = 's';
			break;
		}
	} while(opc != 's');
	
	return 0;
}
/*Mostrar un listado de reservas por mes en formato tabla. El mes es ingresado por el usuario
	-Calcular la cantidad de reservas cuyo costo total sea mayor a 2000. */

void reservas_mayores(struct node*head){
	
	struct node*temp = (struct node*) malloc(sizeof(struct node));
	
	if(temp == NULL){
		printf("No hay reservas registradas.\n");
		return;
	}
	temp = head;
	int total=0;
	
	printf("RESERVA \t PRECIO TOTAL\n");
	while(temp != NULL){
		
		total = (temp->r.precio) * (temp->r.cantidad);
		
		if( total >= 2000 ){
			printf("%d \t\t %d",temp->r.reserva,total);
			
		}
		
		temp = temp->next;
	}
	
}

void generar_archivo(struct node*head){
	
	struct node*temp = (struct node*) malloc(sizeof(struct node));
	
	if(temp == NULL){
		printf("No hay reservas registradas.\n");
		return;
	}
	temp = head;
	
	FILE *fp = fopen("reserva_crucero.txt","w");
	fprintf(fp,"N reserva \t Nombre \t N cabina \t Costo por noche \t Cant noches \t Dia \t Mes \n");
	while(temp!=NULL){
		
		fprintf(fp,"%d \t\t %s \t\t %d \t\t %.2f \t\t\t %d \t %d \t %d \n",
			   temp->r.reserva,temp->r.nombre,temp->r.cabina,temp->r.precio,temp->r.cantidad,temp->r.dia,temp->r.mes);
		
		temp = temp->next;
	}
	
}

void listado_mes(struct node*head){
	
	int mes=0;
	struct node*temp = (struct node*) malloc(sizeof(struct node));
	
	if(temp == NULL){
		printf("No hay reservas registradas.\n");
		return;
	}
	temp = head;
	
	printf("\nIngrese el mes que desea ver el listado: ");
	scanf("%d",&mes);
	
	printf("Listado de reservas para el mes %d:\n\n",mes);
	printf("CODIGO \t\t PRECIO \t NOCHES \n");
	while(temp!=NULL){
		
		
		if(temp->r.mes == mes){
			printf("%d \t\t %.2f \t\t %d\n",temp->r.reserva,temp->r.precio,temp->r.cantidad);
		}
		
		temp = temp->next;
	}
	
}

void print(struct node*head){
	
	struct node*temp = (struct node*) malloc(sizeof(struct node));
	
	if(temp == NULL){
		printf("No hay reservas registradas.\n");
		return;
	}
	temp = head;
	
	printf("N reserva \t Nombre \t N cabina \t Costo por noche \t Cant noches \t Dia \t Mes \n");
	while(temp!=NULL){
		
		printf("%d \t\t %s \t\t %d \t\t %.2f \t\t\t %d \t\t %d \t %d \n",
			temp->r.reserva,temp->r.nombre,temp->r.cabina,temp->r.precio,temp->r.cantidad,temp->r.dia,temp->r.mes);
		
		temp = temp->next;
	}
	
}

void pop(struct node**head){
	
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	
	if(temp == NULL){
		printf("error de almacenamiento");
		exit(1);
	}
	temp = *head;
	
	*head = (*head)->next;
	free(temp);
	printf("Reserva LIFO eliminada.\n");
}

void push(struct node**head){
	
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	if(new_node == NULL){
		printf("Pila Vacia\n");
		exit(1);
	}
	
	printf("\nIngrese el numero de reserva: ");
	scanf("%d",&new_node->r.reserva);
	printf("\nIngrese el nombre del pasajero: ");
	scanf("%s",new_node->r.nombre);
	new_node->r.cabina = rand()%50+1;
	printf("\nIngrese el costo por noche: ");
	scanf("%f",&new_node->r.precio);
	new_node->r.cantidad = rand()%10+1;
	new_node->r.dia = rand()%30+1;
	new_node->r.mes = rand()%12+1;
	
	new_node->next = *head; 
	*head = new_node;
}

void menu(){
	printf("\n--------------\n");
	printf("A)Registrar una nueva reserva \n");
	printf("B)Borrar una reserva \n");
	printf("C)Mostrar un listado de todas las reservas por consola y generar un archivo \n");
	printf("D)Mostrar un listado de reservas por mes en formato tabla. El mes es ingresado por el usuario \n");
	printf("E)Calcular la cantidad de reservas cuyo costo total sea mayor a 2000 \n");
	printf("S)Salir. \n_opc : ");
}
