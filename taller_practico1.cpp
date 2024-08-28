/*Carga tres vectores, cada uno con la información de hoy y los próximos 6 días.  
Tomar la primera posición para el día de hoy. Cargar el arreglo con los datos: 

Vector de lluvias (%) = 0, 0, 0, 0, 18, 45, 48 
Vector de temperaturas máximas (en grados Celsius) =21, 25, 31, 21, 28, 18, 18
Vector de velocidades de viento máximas (en km/h) =14, 11, 6, 8, 8, 11, 18, 16
Luego declara punteros para manejar los arreglos y crea las siguientes funciones:

promedioTemperaturas: Calcula y muestra el promedio de las temperaturas máximas en el período.
diaMaximaViento: Encuentra y devuelve el día con mayor viento. Luego muestra en el main.
diasRiesgoIncendio: Identifica y muestra los días en los que hay riesgo de incendio 
(temperaturas mayores a 20 grados, vientos mayores a 5 km/h y probabilidad de lluvias por debajo del 1%).*/

#include <stdio.h>
#include <iostream>
using namespace std;

void promedioTemperaturas(int*);
void diaMaximaViento(int*);
void diasRiesgoIncendio(int* ,int* ,int*);

int main(  ) {

	int Lluvias[7]={0,0,0,0,18,45,48},opc=0,salir=0;
	int *ptrLluvias=Lluvias; 
	int TempMax[7]={21,25,31,21,28,18,18};
	int *ptrTempMax=TempMax; 
	int VelVientoMax[7]={14,11,6,8,11,18,16};
	int *ptrVelVientoMax=VelVientoMax; 	
	
	printf("Ingrese \n1)Promedio de temperaturas \n2)Dia de maximo viento \n3)Dia de riesgo incendio \n4)SALIR DEL MENU \n");
	
	
	do{
	printf("\n_______\nopc: ");
	scanf("%d",&opc);
	
	switch(opc){
		
	case 1:
		
		promedioTemperaturas(ptrTempMax);
		
		break;
		
	case 2:
		
		diaMaximaViento(ptrVelVientoMax);
		
		break;
		
	case 3:
		
		diasRiesgoIncendio(ptrTempMax,ptrVelVientoMax,ptrLluvias);
		
		break;
		
	case 4:
		salir=4;
		break;
		
	default:
		
		printf("no existe esa opcion\n");
		
		break;
	}
	
	}while(salir != 4);
	return 0;
}

void promedioTemperaturas (int *a ) {

	int i=0,acum=0;
	
	for(i=0;i<7;i++){
	
	acum = acum + *(a+i);
	
	}
	printf("El promedio de las temperaturas maximas es %.2f",((float)acum/7));
}


void diaMaximaViento (int*a ) {
	
	int i=0,max=0;
	
	for(i=0;i<7;i++) {
		
		if(*(a+i) > max)
		{
			max = *(a+i);
		}
	}
	printf("El dia con mayor viento fue de %d",max);
}

//diasRiesgoIncendio: Identifica y muestra los días en los que hay riesgo de incendio 
//(temperaturas mayores a 20 grados, vientos mayores a 5 km/h y probabilidad de lluvias por debajo del 1%)
void diasRiesgoIncendio(int*a, int*b, int*c) {	
	
	int diasRiesgoIncendio=0,i=0;
	
	for(i=0;i<7;i++){
	
	if( (*(a+i)>20) && (*(b+i)>5) && (*(c+i)<1)) {
		
		printf("el dia %d tiene riesgo de icendio\n",i+1);
		diasRiesgoIncendio++;
	}
	}
	printf("\nLos dias que hay riesgo de incendio son %d",diasRiesgoIncendio);
}
