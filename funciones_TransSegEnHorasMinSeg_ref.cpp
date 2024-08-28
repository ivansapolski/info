#include <iostream>
using namespace std;

//TRANSFORMAR SEGUNDOS AL EQUIVALENTE DE HORAS,MIN,SEG 

void tiempo(int , int , int , int);

int main(  ) {
	
	int totalSeg=0,horas=0,min=0,seg=0;
	
	printf("Ingrese la cantidad de segundos que quiere transformar\n\n");
	scanf("%d",&totalSeg);
	
	tiempo(totalSeg,horas,min,seg);  	
	
	return 0;	
}

void tiempo(int totalSeg, int horas, int min, int seg){
	
	horas=totalSeg/3600;
	totalSeg=totalSeg%3600; //resto que no se hizo horas
	min=totalSeg/60;
	seg=totalSeg%60;
	
	printf("La transformacion es\n HORAS: %d \n MIN: %d \n SEG: %d \n",horas,min,seg);
}
