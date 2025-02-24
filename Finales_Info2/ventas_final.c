/*Registro de Ventas		COLA
Desarrolla un programa que permita la gestión de registro de ventas en una tienda de electronica de este año utilizando el TDA lista. 
Para ello cree la/las estructura/s que necesite para almacenar la siguiente información sobre 
código de producto (entero), nombre de producto (cadena), cantidad vendida, precio unitario, día y mes. 

Desarrolla las siguientes funciones para: 
-Registrar una nueva venta.
-Mostrar un listado de todas las ventas por consola y generar un archivo .txt llamado "ventas.txt", ambos en formato tabla. 
-Borrar una venta 
-Mostrar un listado de ventas por mes en formato tabla. 
-Calcular la cantidad de ventas mayores a 1000. 
Crea un menú de opciones para que el usuario pueda realizar diferentes acciones antes descritas*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ventas{
	int codigo;
	char nombre[20];
	int vendido;
	float precio;
	int dia;
	int mes;
};
struct node{
	struct ventas v;
	struct node *next;
};

void menu();
void push(struct node**,struct node**);
void pop(struct node**,struct node**);
void print(struct node*);
void listado_ventas(struct node*);
void ventas_mil(struct node*);
void generar_archivo(struct node*);
	
int main(  ) {
	
	struct node *front = NULL;
	struct node *back = NULL;
	srand(time(NULL));
	int opc=0;
	
	do{
		menu();
		scanf("%d",&opc);
		switch(opc){
		case 1:
			push(&front,&back);
			break;
		case 2:
			print(front);
			generar_archivo(front);
			break;
		case 3:
			pop(&front,&back);
			break;
		case 4:
			listado_ventas(front);
			break;
		case 5:
			ventas_mil(front);
			break;
		}
	} while(opc!=6);
	
	return 0;
}

void generar_archivo(struct node*front){
	
	struct node* temp = (struct node* )malloc(sizeof(struct node));
	temp=front;
	FILE *fp = fopen("ventas.txt","w");
	
	fprintf(fp,"CODIGO \t\t NOMBRE \t C.VENDIDA \t P.UNIT \t DIA \t MES \n");
	while(temp!=NULL){
		fprintf(fp,"%d \t\t %s \t\t %d \t\t %.2f \t %d \t %d \n",temp->v.codigo,temp->v.nombre,temp->v.vendido,temp->v.precio,temp->v.dia,temp->v.mes);
		temp = temp->next;
	}
	
}

void ventas_mil(struct node* front){
	
	struct node* temp = (struct node* )malloc(sizeof(struct node));
	temp=front;
	int cont=0;
	
	while(temp!=NULL){
		
		if(temp->v.vendido >= 1000){
			cont++;
		}
		
		temp=temp->next;
	}
	printf("\n-Fueron %d los productos que superaron las 1000 ventas.\n",cont);
}

void listado_ventas(struct node*front){
	
	struct node* temp = (struct node* )malloc(sizeof(struct node));
	temp=front;
	
	int mes1=0,mes2=0,mes3=0,mes4=0,mes5=0,mes6=0,mes7=0,mes8=0,mes9=0,mes10=0,mes11=0,mes12=0;
	
	printf("**LISTADO DE VENTAS**\n");
	
	while(temp!=NULL){
		
		switch(temp->v.mes){
		case 1:
			mes1=1;
			break;
		case 2:
			mes2=1;
			break;
		case 3:
			mes3=1;
			break;
		case 4:
			mes4=1;
			break;
		case 5:
			mes5=1;
		case 6:
			mes6=1;
			break;
		case 7:
			mes7=1;
			break;
		case 8:
			mes8=1;
			break;
		case 9:
			mes9=1;
			break;
		case 10:
			mes10=1;
			break;
		case 11:
			mes11=1;
			break;
		case 12:
			mes12=1;
			break;
		}
		temp = temp->next;
	}
	
	if(mes1 == 1){
		temp = front;
		printf("En enero las ventas fueron: \nCODIGO\t\tC. VENDIDA\n");
		while(temp!=NULL){
			if(temp->v.mes==1){
				printf("%d \t\t %d\n",temp->v.codigo,temp->v.vendido);
			}
			temp = temp->next;
		}
	}
	if(mes2 == 1){
		temp = front;
		printf("En Febrero las ventas fueron: \nCODIGO\t\tC. VENDIDA\n");
		while(temp!=NULL){
			if(temp->v.mes==2){
				printf("%d \t\t %d\n",temp->v.codigo,temp->v.vendido);
			}
			temp = temp->next;
		}
	}
	if(mes3 == 1){
		temp = front;
		printf("En Marzo las ventas fueron: \nCODIGO\t\tC. VENDIDA\n");
		while(temp!=NULL){
			if(temp->v.mes==3){
				printf("%d \t\t %d\n",temp->v.codigo,temp->v.vendido);
			}
			temp = temp->next;
		}
	}
	if(mes4 == 1){
		temp = front;
		printf("En Abril las ventas fueron: \nCODIGO\t\tC. VENDIDA\n");
		while(temp!=NULL){
			if(temp->v.mes==4){
				printf("%d \t\t %d\n",temp->v.codigo,temp->v.vendido);
			}
			temp = temp->next;
		}
	}
	if(mes5 == 1){
		temp = front;
		printf("En Mayo las ventas fueron: \nCODIGO\t\tC. VENDIDA\n");
		while(temp!=NULL){
			if(temp->v.mes==5){
				printf("%d \t\t %d\n",temp->v.codigo,temp->v.vendido);
			}
			temp = temp->next;
		}
	}
	if(mes6 == 1){
		temp = front;
		printf("En Junio las ventas fueron: \nCODIGO\t\tC. VENDIDA\n");
		while(temp!=NULL){
			if(temp->v.mes==6){
				printf("%d \t\t %d\n",temp->v.codigo,temp->v.vendido);
			}
			temp = temp->next;
		}
	}
	if(mes7 == 1){
		temp = front;
		printf("En Julio las ventas fueron: \nCODIGO\t\tC. VENDIDA\n");
		while(temp!=NULL){
			if(temp->v.mes==7){
				printf("%d \t\t %d\n",temp->v.codigo,temp->v.vendido);
			}
			temp = temp->next;
		}
	}
	if(mes8 == 1){
		temp = front;
		printf("En Agosto las ventas fueron: \nCODIGO\t\tC. VENDIDA\n");
		while(temp!=NULL){
			if(temp->v.mes==8){
				printf("%d \t\t %d\n",temp->v.codigo,temp->v.vendido);
			}
			temp = temp->next;
		}
	}if(mes9 == 1){
		temp = front;
		printf("En Septiembre las ventas fueron: \nCODIGO\t\tC. VENDIDA\n");
		while(temp!=NULL){
			if(temp->v.mes==9){
				printf("%d \t\t %d\n",temp->v.codigo,temp->v.vendido);
			}
			temp = temp->next;
		}
	}if(mes10 == 1){
		temp = front;
		printf("En Octubre las ventas fueron: \nCODIGO\t\tC. VENDIDA\n");
		while(temp!=NULL){
			if(temp->v.mes==10){
				printf("%d \t\t %d\n",temp->v.codigo,temp->v.vendido);
			}
			temp = temp->next;
		}
	}if(mes11 == 1){
		temp = front;
		printf("En Noviembre las ventas fueron: \nCODIGO\t\tC. VENDIDA\n");
		while(temp!=NULL){
			if(temp->v.mes==11){
				printf("%d \t\t %d\n",temp->v.codigo,temp->v.vendido);
			}
			temp = temp->next;
		}
	}if(mes12 == 1){
		temp = front;
		printf("En Diciembre las ventas fueron: \nCODIGO\t\tC. VENDIDA\n");
		while(temp!=NULL){
			if(temp->v.mes==12){
				printf("%d \t\t %d\n",temp->v.codigo,temp->v.vendido);
			}
			temp = temp->next;
		}
	}
	
	
}

void print(struct node*front){
	
	struct node* temp = (struct node* )malloc(sizeof(struct node));
	temp=front;
	/*código de producto (entero), nombre de producto (cadena), cantidad vendida, precio unitario, día y mes.*/
	printf("CODIGO \t\t NOMBRE \t C.VENDIDA \t P.UNIT \t DIA \t MES \n");
	while(temp!=NULL){
		printf("%d \t\t %s \t\t %d \t\t %.2f \t %d \t %d \n",temp->v.codigo,temp->v.nombre,temp->v.vendido,temp->v.precio,temp->v.dia,temp->v.mes);
		temp = temp->next;
	}
	
}

void pop(struct node**front,struct node**back){
	
	struct node* temp = (struct node* )malloc(sizeof(struct node));
	temp=*front;
	
	if(*back == NULL){
		printf("Cola vacia.\n");
		return;
	}
	
	*front = (*front)->next;
	free(temp);
	printf("Eliminado.");
}

void push(struct node**front,struct node**back){
	
	struct node* new_node = (struct node* )malloc(sizeof(struct node));
	
	if(new_node == NULL){
		printf("Error de almacenamiento.\n");
		exit(1);
	}
	
	printf("\ningrese codigo del producto: ");
	scanf("%d",&new_node->v.codigo);
	printf("\ningrese el nombre del producto: ");
	scanf("%s",new_node->v.nombre);
	new_node->v.vendido = rand()%5000+0;
	new_node->v.precio = rand()%500+100;
	new_node->v.dia = rand()%30+1;
	new_node->v.mes = rand()%12+1;
	
	new_node->next = NULL;
	
	if(*back == NULL){
		*back = new_node;
		*front = *back;
	}else{
		(*back)->next = new_node;
		*back = new_node;
	}
}

void menu(){
	printf("\n_____\nIngrese: \n");
	printf("1)Registrar una nueva venta \n");
	printf("2)Mostrar un listado de todas las ventas por consola y generar un txt \n");
	printf("3)Borrar una venta \n");
	printf("4)Mostrar un listado de ventas por mes en formato tabla \n");
	printf("5)Calcular la cantidad de ventas mayores a 1000 \n");
	printf("6)Salir. \nopc: ");
}
	
	
	
