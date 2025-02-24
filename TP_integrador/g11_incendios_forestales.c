#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>  // Para usar INT_MIN

/*Diseñar y codificar un programa que sea capaz de cumplir los siguientes requerimientos:
-Cantidad de superficie afectada por provincia
-Cantidad de focos de incendio por provincia
-Listar el top 3 de las provincias mas afectadas por los incendios por cantidad de hectáreas afectadas
-Listar el top 3 de las provincias mas afectas por los incendios por cantidad de focos de incendios*/

// ESTRUCTURAS.
struct hectareas{
	int id_provincia;				// Guarda el id de cada provincia.
	float ha_afectadas;				// Guarda las hectareas afectadas por cada provincia.
	struct hectareas *siguiente_ha; // Apunta al siguiente nodo de la lista.
};
struct focos{
	char nombre_provincia[100];		// Guarda el nombre de cada provincia.
	int focos_incendios;			// Guarda los focos de incendio por cada porvincia.
	struct focos *siguiente_focos;	// Apunta al siguiente nodo de la lista.
};

// FUNCIONES - PROTOTIPOS.

	// Hectareas.
void push_ha(struct hectareas ** , FILE *);	// Funcion para cargar nodos con ha afectadas.
void print_ha(struct hectareas *);			// Funcion para imprimir lo realizado por push.

	// Focos.
void push_focos(struct focos ** , FILE *);	// Funcion para cargar nodos con focos de incendio.
void print_fo(struct focos *);				// Funcion para imprimir lo realizado por push.


int main( ) {
	
	// Punteros a estructuras.
	struct hectareas *cabeza_ha = NULL;		// Puntero a estructura de "hecatreas".
	struct focos *cabeza_fo = NULL;			// Puntero a estructura de "focos".
	
	// Abrimos "datos.csv" para lectura "r : read".
	FILE *file = fopen("datos.csv","r");
	if(file == NULL){
		printf("\n\nImposible abrir el archivo.\n\n");
		return 0;
	}
	
	// Impresion y llamado de las funciones.
	push_ha(&cabeza_ha,file);		// Se le pasa "datos.csv", crea la lista y guarda los elementos en nodos.
	printf("\n=======================================================");
	
	file = fopen("datos.csv", "r");  // Reabrimos para leer focos
	
	printf("\n\n====Focos de incendio por provincia:===================");
	push_focos(&cabeza_fo,file);	// Se le pasa "datos.csv", crea la lista y guarda los elementos en nodos.
	print_fo(cabeza_fo);			// Imprime la lista de (FOCOS) e imprime el top 3.
	printf("\n======================================================");
	
	// Cierre del "datos.csv" al finalizar su lectura.
	fclose(file);
	return 0;
}

// FUNCIONES.=======================================================================================================================

void print_top_3hect(struct hectareas *cabeza_ha) {
	struct hectareas *memoria = cabeza_ha;
	int count = 0;
	
	printf("\n\nTop 3 provincias con mayor superficie afectada:");
	while (memoria != NULL && count < 3) {
		
		switch(memoria->id_provincia){
		case 6:
			printf("\nBuenos aires: \t\t");
			break;
		case 14:
			printf("\nCordoba: \t\t");
			break;
		case 18:
			printf("\nCorrientes: \t\t");
			break;
		case 22:
			printf("\nChaco: \t\t\t");
			break;
		case 26:
			printf("\nChubut:  \t\t");
			break;
		case 30:
			printf("\nEntre rios:  \t\t");
			break;
		case 38:
			printf("\nJujuy: \t\t\t");
			break;
		case 42:
			printf("\nLa pampa: \t\t");
			break;
		case 50:
			printf("\nMendoza: \t\t");
			break;
		case 54:
			printf("\nMisiones: \t\t");
			break;
		case 58:
			printf("\nNeuquen: \t\t");
			break;
		case 62:
			printf("\nRio Negro: \t\t");
			break;
		case 66:
			printf("\nSalta: \t\t\t");
			break;
		case 70:
			printf("\nSan Juan: \t\t");
			break;
		case 82:
			printf("\nSanta Fe: \t\t");
			break;
		case 86:
			printf("\nSantigo del estero: \t");
			break;
		case 90:
			printf("\nTucuman: \t\t");
			break;
		}
		printf(" %0.1f", memoria->ha_afectadas);
		memoria = memoria->siguiente_ha;
		count++;
	}
}

void push_ha(struct hectareas **cabeza_ha, FILE *file){
	
	// Estructura provisoria para luego cargar en nodos-lista.
	struct Provincia{
		int provincia_id;
		float sup_afectada;
	};
	struct Provincia provincias[100];
	int count = 0;
	// Leer el archivo y procesar los datos.
	char line[256];
	fgets(line, sizeof(line), file); // Saltar la cabecera.
	
	while (fgets(line, sizeof(line), file)) {
		int pais_id, provincia_id,  anio_inicial;
		double sup_afectada;
		sscanf(line, "%d;%*[^;];%d;%*[^;];%*[^;];%*[^;];%lf;%*[^;];%*d;%d",&pais_id, &provincia_id, &sup_afectada, &anio_inicial);
		
		int found = 0;
		for (int i = 0; i < count; i++) {
			if (provincias[i].provincia_id == provincia_id) {
				provincias[i].sup_afectada += sup_afectada;
				found = 1;
				break;
			}
		}
		// Si no se encontró, agregar nueva provincia.
		if (!found && count < 100) {
			provincias[count].provincia_id = provincia_id;
			provincias[count].sup_afectada = sup_afectada;
			count++;
		}
	}
	// Carga de los datos en NODOS.
	for(int i=0 ; i<count ; i ++){
		struct hectareas *memoria = (struct hectareas*)malloc(sizeof(struct hectareas));
		struct hectareas *ultimo = *cabeza_ha;
		
		memoria -> id_provincia = provincias[i].provincia_id;
		memoria -> ha_afectadas = provincias[i].sup_afectada;
		memoria -> siguiente_ha = NULL;
		if(*cabeza_ha == NULL){
			*cabeza_ha = memoria;
		}else{
			while(ultimo->siguiente_ha != NULL){
				ultimo = ultimo->siguiente_ha;
			}
			ultimo->siguiente_ha = memoria;
		}
	}
	// Ordenar la lista enlazada por sup_afectada
	struct hectareas *sorted = NULL;
	
	for (int i = 0; i < count; i++) {
		struct hectareas *memoria = (struct hectareas *)malloc(sizeof(struct hectareas));
		memoria->id_provincia = provincias[i].provincia_id;
		memoria->ha_afectadas = provincias[i].sup_afectada;
		memoria->siguiente_ha = sorted;
		sorted = memoria;
	}
	// Ordenar la lista enlazada por ha_afectadas
	struct hectareas *current = sorted, *next = NULL;
	while (current != NULL) {
		next = current->siguiente_ha;
		struct hectareas *prev = NULL, *temp = sorted;
		while (temp != NULL && temp->ha_afectadas >= current->ha_afectadas) {
			prev = temp;
			temp = temp->siguiente_ha;
		}
		current->siguiente_ha = temp;
		if (prev == NULL) {
			sorted = current;
		} else {
			prev->siguiente_ha = current;
		}
		current = next;
	}
	print_ha(*cabeza_ha);
	// Mostrar top 3
	print_top_3hect(sorted);
}
	
void print_ha(struct hectareas *cabeza_ha){
	
	struct hectareas *memoria = cabeza_ha; 	
	printf("\n====Hectareas afectadas por provincia:========================");
	while(memoria != NULL){
		
		switch(memoria->id_provincia){			
		case 6:
			printf("\nBuenos aires: \t\t");
			break;
		case 14:
			printf("\nCordoba: \t\t");
			break;
		case 18:
			printf("\nCorrientes: \t\t");
			break;
		case 22:
			printf("\nChaco: \t\t\t");
			break;
		case 26:
			printf("\nChubut:  \t\t");
			break;
		case 30:
			printf("\nEntre rios:  \t\t");
			break;
		case 38:
			printf("\nJujuy: \t\t\t");
			break;
		case 42:
			printf("\nLa pampa: \t\t");
			break;
		case 50:
			printf("\nMendoza: \t\t");
			break;
		case 54:
			printf("\nMisiones: \t\t");
			break;
		case 58:
			printf("\nNeuquen: \t\t");
			break;
		case 62:
			printf("\nRio Negro: \t\t");
			break;
		case 66:
			printf("\nSalta: \t\t\t");
			break;
		case 70:
			printf("\nSan Juan: \t\t");
			break;
		case 82:
			printf("\nSanta Fe: \t\t");
			break;
		case 86:
			printf("\nSantigo del estero: \t");
			break;
		case 90:
			printf("\nTucuman: \t\t");
			break;
		}
		printf("%0.1f",memoria->ha_afectadas);	
		memoria = memoria->siguiente_ha;	
	}
}
	
void push_focos(struct focos **cabeza_fo, FILE *file){
	// Estructura provisoria para luego cargar en nodos-lista.
	struct Provincia{
		char provincia[100];
		int cant_focos;
	};
	char line[500]; 					// Carga todas las lineas de "datos.csv".
	struct Provincia provincias[100];
	int num_provincias = 0;
	fgets(line, sizeof(line), file);	// Leer la primera línea (encabezados)
	
	// Leer cada línea del archivo y aignarla a la estructura "Provincias".
	while (fgets(line, sizeof(line), file)) {
		
		char *token;
		char provincia[100] = {0};
		int cant_focos = 0;
		
		// Leer y saltar columnas innecesarias para llegar a "provincia"
		token = strtok(line, ";"); // pais_id
		if (token == NULL) continue;
		
		token = strtok(NULL, ";"); // pais
		token = strtok(NULL, ";"); // provincia_id
		token = strtok(NULL, ";"); // provincia
		
		if (token != NULL) {
			strncpy(provincia, token, sizeof(provincia) - 1); // asegurar final nulo
			provincia[sizeof(provincia) - 1] = '\0';
		}
		
		// Saltar columnas adicionales hasta "cant_focos"
		token = strtok(NULL, ";"); // departamento_id
		token = strtok(NULL, ";"); // departamento
		token = strtok(NULL, ";"); // sup_afectada
		token = strtok(NULL, ";"); // uni_med_id
		token = strtok(NULL, ";"); // cant_focos
		
		if (token != NULL) {
			cant_focos = atoi(token);
		}
		
		// Buscar si la provincia ya está en el arreglo
		int found = 0;
		for (int i = 0; i < num_provincias; i++) {
			
			if (strcmp(provincias[i].provincia, provincia) == 0) {
				provincias[i].cant_focos += cant_focos;
				found = 1;
				break;
			}
		}
		
		// Si la provincia no está en el arreglo, agregarla
		if (!found && num_provincias < 100) {
			
			strncpy(provincias[num_provincias].provincia, provincia, sizeof(provincias[num_provincias].provincia) - 1);
			provincias[num_provincias].provincia[sizeof(provincias[num_provincias].provincia) - 1] = '\0';
			provincias[num_provincias].cant_focos = cant_focos;
			num_provincias++;
		}
	}
	
	// Carga de los datos en NODOS.
	for(int i=0 ; i< num_provincias-1 ; i++){
		
		struct focos *memoria = (struct focos *)malloc(sizeof(struct focos ));
		struct focos *ultimo = *cabeza_fo;
		
		strcpy(memoria->nombre_provincia, provincias[i].provincia);
		memoria->focos_incendios = provincias[i].cant_focos;
		memoria->siguiente_focos = NULL;
		
		if (*cabeza_fo == NULL) {
			*cabeza_fo = memoria;
		} else {
			
			while (ultimo->siguiente_focos != NULL) {
				ultimo = ultimo->siguiente_focos;
			}
			
			// Enlazar el nuevo nodo al final de la lista
			ultimo->siguiente_focos = memoria;
		}
	}
}
void print_fo(struct focos *cabeza_fo){
	
	// Puntero al primer elemento de la lista.
	struct focos *memoria = cabeza_fo; // cabeza_fo apunta al primer elemento de la lista.
	
	// Impresion de la lista (FOCOS DE INCENDIO) .
	while(memoria != NULL){
		
		printf("\n-%s: %d",memoria->nombre_provincia,memoria->focos_incendios);	// Impresion.
		
		memoria = memoria->siguiente_focos;		// Memoria avanza en la lista hasta llegar a NULL.
	}
	// TOP 3 DE FOCOS.
	memoria = cabeza_fo;	// Volvemos "memoria" a la cabeza para comparar.
	
	int max1 = INT_MIN, max2 = INT_MIN, max3 =  INT_MIN;	// Variables para almacenar el top3 .
	char nom1[100] = "", nom2[100] = "", nom3[100] = ""; 		// Variables para guardar el nombre del foco.
	
	// Recorre la lista y encuentra el top 3.
	while (memoria != NULL) {
		
		if (memoria->focos_incendios > max1) {
			
			max3 = max2;
			strcpy(nom3, nom2);
				
			max2 = max1;
			strcpy(nom2, nom1);
			
			max1 = memoria->focos_incendios;
			strcpy(nom1, memoria->nombre_provincia);
			
		} else if (memoria->focos_incendios > max2) {
			
			max3 = max2;
			strcpy(nom3, nom2);
			
			max2 = memoria->focos_incendios;
			strcpy(nom2, memoria->nombre_provincia);
			
		} else if (memoria->focos_incendios > max3) {
			
			max3 = memoria->focos_incendios;
			strcpy(nom3, memoria->nombre_provincia);
			
		}
		
		memoria = memoria->siguiente_focos;	// Memoria avanza en la lista hasta llegar a NULL.
		
	}
	printf("\n\nTop 1: %s - %d \nTop 2: %s - %d\nTop 3: %s - %d",nom1,max1,nom2,max2,nom3,max3); // Imprime el top 3.
}
