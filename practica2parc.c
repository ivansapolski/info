#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*Practica Parcial 2

Especificación

Diseñar y codificar un programa que permita el ingreso de las notas obtenidas de las asignaturas que ha cursado este cuatrimestre en un arreglo 5x7 de dos dimensiones. Por ejemplo:

Asignatura	|	Parcial 1	|	Parcial 2	|	Recuperatorio 1 	|	Recuperatorio 2 	|	Resultado de la cursada 	|	Final	|	
1
2
3
4
5

El programa tendría que controlar lo siguiente: 
Las notas posibles son de 1 a 10. 

Si la nota de parcial 1 es mayor o igual a 4, la columna recuperatorio 1 el valor es cero. Ídem para el caso de parcial 2.

La columna resultado de la cursada puede asumir los siguientes valores: 1-Regular 2-Libre

En el caso de que la asignatura quede libre (2) no podrá rendir final, por lo tanto la columna Final es cero.


+Luego crear un menú de opciones que muestre los siguientes datos por medio de funciones:

-Mostrar la cantidad de asignaturas regularizadas. (Función retorna valor)

-Mostrar un listado de las asignaturas que deberá recursar. (Función void)

-Mostrar el promedio de las notas finales (no contabilizar aquellas asignaturas que no se han rendido). (Retorna valor)

-Mostrar un listado completo de las asignaturas (Función void)

Nota: las notas pueden ser cargadas utilizando números aleatorios o carga manual*/





int main(  ) {

	int i=0,j=0,m[5][7]={0},fina=0,recup2=0,recup1=0,parc1=0,parc2=0;
	
	srand(time(NULL));
	
	
	for(i=0;i<5;i++){
		
		parc1=rand()%10;
		parc2=rand()%10;
		
		m[i][0]=i+1;
		m[i][1]=parc1;
		m[i][2]=parc2;
		
		if(m[i][1] >= 4){
			
			m[i][3]	= 0;
			
		}else{
			
			printf("\ningrese nota recuperatorio 1 de la asignatura %d: ",i+1);
			scanf("%d",&recup1);
			
			m[i][3] = recup1;
			
		}
		
		
		if(m[i][2] >= 4){
			
			m[i][4]	= 0;
			
		}else{
			
			printf("\ningrese nota recuperatorio 2 de la asignatura %d: ",i+1);
			scanf("%d",&recup2);
			
			m[i][4] = recup2;
			
		}
		
		
		if((m[i][1]>=4 && m[i][2]>=4 ) || (m[i][1]>=4 && m[i][4]>=4)	||	(m[i][3]>=4 && m[i][4]>=4) || (m[i][2]>=4 && m[i][3]>=4)){
			
			m[i][5]= 1;	//regular
			
		}else{
			
			m[i][5]= 2;	//libre
			
		}
		
		if(m[i][5] == 2){
			
			m[i][6] = 0;
			
		}else{
			
			printf("\ningrese la nota del final de la asignatura %d: ",i+1);
			scanf("%d",&fina);
			
			m[i][6] = fina;
			
		}
	}
	
	
	
	
	
	printf("Asig	Parc 1	Parc 2	Recup1 	Recup2 	R.curs.	Final\n");
	for(i=0;i<5;i++){
		
		for(j=0;j<7;j++){
			
			printf("%d\t",m[i][j]);
			
		}
		printf("\n");
	}
	
	return 0;
}

