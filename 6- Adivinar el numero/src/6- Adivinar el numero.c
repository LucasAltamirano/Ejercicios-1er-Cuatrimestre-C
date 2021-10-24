/*
 ============================================================================
 Name        : 6-.c
 Author      : Lucas Altamirano
 Version     :
 Copyright   : Your copyright notice
 Description :
Diseñar un programa para jugar a adivinar un número entre 0 y 100.
 El juego tiene que dar pistas de si el número introducido por el jugador está por encima
 o por debajo.
 El juego termina cuando se adivina el número o se decide terminar de jugar ingresando un número negativo.
 Permitir jugar tantas veces como lo desee el jugador y al salir mostrar su mejor puntuación.
 Utilizar la biblioteca del ejercicio #001.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	int adivinarX;
	int numeroIngresado;
	int flagSalida=-1;

	printf("\t||||||||| ADIVINA EL NUMERO |||||||||\n");
	printf("para comenzar a jugar debes ingresar un numero positivo entre 1 y 50\n");
	printf("para terminar el juego deberas presionar el 0(cero)\n");
	printf("-Ingresa el numero a adivinar");
	scanf("%d",&adivinarX);
	while(adivinarX==0 || adivinarX>50){
		printf("-Ingresa el numero a adivinar distinto de cero ,entre 1 -50 ");
		scanf("%d",&adivinarX);
	}
	printf("-Ahora adivina el numero");
	scanf("%d",&numeroIngresado);

	do{

		if(numeroIngresado==adivinarX){
			printf("Adivinaste!!!");
			flagSalida=1;
		}
		if (numeroIngresado>adivinarX){
			printf("el numero para adivinar es menor\n");
			printf("-Intenta nuevamente adivinar el numero ");
				scanf("%d",&numeroIngresado);
		}
		if (numeroIngresado<adivinarX){
				printf("el numero para adivinar es mayor\n");
				printf("-Intenta nuevamente adivinar el numero ");
					scanf("%d",&numeroIngresado);
				}
	}while(numeroIngresado!=0 && flagSalida!=1);
		printf("Fin del juego");

	return EXIT_SUCCESS;
}
