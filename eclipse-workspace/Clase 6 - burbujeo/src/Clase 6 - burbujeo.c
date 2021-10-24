/*
 ============================================================================
 Name        : Clase.c
 Author      : Lucas Altamirano   1 D


 Ejercicio 6-1:

 Disponemos de dos variables numéricas (a y b).
 Realizar un algoritmo que permita el intercambio de valores de dichas variables.


 Ejercicio 6-2:Realizar un programa que permita el
 ingreso de 10 números enteros (positivos y negativos).
 Necesito generar un listado de los números positivos de manera creciente y
 negativos de manera decreciente.
 (Como máximo 4 for)Ejemplo: Listado 1 : 4, 5, 6, 10, 18, 29 Listado 2 : -1,-5,-9,-12
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int a;
	int b;
	int aux;

	a = 5;
	b = 10;   // otorgue un valor a cada variable ,

	printf("valor a %d y valor b %d \n", a, b);

	aux = a; // el valor de a ,lo guardo en el auxiliar, porque si intento pasar , a directamente pierdo el valor de b "lo pisa "
	a = b;  // paso el valor de b  hacia a , ahora ve me queda vacio ,
	b = aux;  // finalmente el valor que guarde en aux (a), se lo asigno a b;


	printf("valor a %d y valor b %d", a, b);

	return EXIT_SUCCESS;
}

