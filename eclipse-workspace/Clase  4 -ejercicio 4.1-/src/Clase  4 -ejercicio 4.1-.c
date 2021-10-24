/*
 ============================================================================
 clase 4 division 1 E
 Author      : Lucas Altamirano
 Ejercicio 4-1:
 Realizar un programa EN EL MAIN que permita calcular y mostrar el factorial
 de un número.
 Por ejemplo:
 5! = 5*4*3*2*1 = 120
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);

	int numeroIngresado;
	int i;
	int factorial;

	factorial=numeroIngresado;
	i=1;




	printf("Ingrese un numero ");
	scanf("%d",&numeroIngresado);


	for(i=1;i<numeroIngresado ; i++)
 {

			factorial   =factorial*i;





	}

	printf("el factorial de %d es %d",numeroIngresado, factorial);

	return EXIT_SUCCESS;
}
