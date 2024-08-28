#include <iostream>
#include <time.h>

/*Escriba un programa que ayudará a un alumno a aprender a multiplicar. Utilice la función srand para generar dos números enteros positivos de un dígito. 
A continuación deberá escribir una pregunta en pantalla, por ejemplo:

¿Cuanto es 6 veces 7?, luego escribe la respuesta el alumno. Las operaciones y resultados son almacenados en una matriz de 4 columnas y 5 filas.

Multiplicando	|	Multiplicador 	|	Producto Alumno	|		|	Producto Correcto			|
	6					7			(ingresado por el usuario)		(calculado por el programa)


Al finalizar las 5 preguntas, se verifican y se muestran en pantalla los resultados obtenidos. En caso de que el alumno cometió un error, mostrar el resultado 
correcto. 
Por último, calcular cuántas preguntas respondió correctamente el alumno, dependiendo la cantidad de respuestas correcta escribir el siguiente mensaje:
5 respuestas correctas. ¡Felicitaciones!
Entre 3 y 4. ¡Bien!, Vas por buen camino.
2 o menos respuestas correctas. Hay que practicar más. */






int main(int argc, char *argv[]) {
	
	int i=0,j=0,n1=0,n2=0,rta_alumno=0,p[5][4]={0},correctas=0;
	
	srand(time(NULL));
	
	
	//5 veces
	
	for(i=0;i<5;i++){
	
	
	n1=rand()%10;
	n2=rand()%10;
	
	printf("\n%d) Cuanto es %d veces %d\n",i+1,n1,n2);
	
	printf("respuesta: ");
	scanf("%d",&rta_alumno);	//rta alumno
	
	p[i][0]	=	n1;
	p[i][1]	=	n2;
	p[i][2]	=	rta_alumno;
	p[i][3]	=	n1*n2;
	
}
	
	for(i=0;i<5;i++){
		for(j=0;j<4;j++){
			
			printf("%d\t",p[i][j]);	//mostrar vector
			
		}
		printf("\n");
	}
	
	/*5 respuestas correctas. ¡Felicitaciones!
		Entre 3 y 4. ¡Bien!, Vas por buen camino.
		2 o menos respuestas correctas. Hay que practicar más. */
		

	
	for(i=0;i<5;i++){
		
			
			if(p[i][2] == p[i][3]){
				
				correctas++;
				
			}else{
				
				printf("\n%d) INCORRECTO! el resultado es %d",i+1,p[i][3]);
				
			}
		
	}
	
	
	printf("\n\n********************************\n");
	
	if(correctas == 5){
		
		printf("\n5 respuestas correctas. ¡Felicitaciones!");
		
	}else{
		
		if(correctas >= 3){
			
			printf("\nEntre 3 y 4. ¡Bien!, Vas por buen camino.");
			
		}else{
			
			if(correctas >= 0){
				
				printf("\n2 o menos respuestas correctas. Hay que practicar más.");
				
			}
		}
	}
	
	
	return 0;
}

