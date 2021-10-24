/*
 ============================================================================
 Name        : Clase.c
 Author      : Lucas Altamirano



 SWAPEO

 Ejercicio 6-1:

 Disponemos de dos variables numéricas (a y b).
 Realizar un algoritmo que permita el intercambio de valores de dichas variables.


 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int Swapeo(int *a, int *b); //prototipo

int main(void) {

	int numero1;
	int numero2;

	numero1 = 10;
	numero2 = 25;

	printf("el valor numero 1 ;%d", numero1);
	printf(" y el valor numero 2; %d\n", numero2);

	Swapeo(&numero1, &numero2);

	printf("el valor numero1 ; %d", numero1);
	printf("y el valor numero 2; %d", numero2);

	return EXIT_SUCCESS;
}

int Swapeo(int *a, int *b) {
	int aux;

	aux = *a;
	*a = *b;
	*b = aux;

	return 0;
}

