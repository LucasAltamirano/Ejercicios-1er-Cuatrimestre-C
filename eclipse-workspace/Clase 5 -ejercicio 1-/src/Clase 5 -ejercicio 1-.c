/*
 ============================================================================
 Name        : Clase.c
 Author      : Lucas Altamirano
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int main(void) {

	setbuf(stdout,NULL);

		int i;
		int numeros [MAX];
		int acumulador;


		acumulador=0;

	for(i=0 ;i<MAX;i++){

		printf("ingrese 5 numeros ");
		scanf("%d", &numeros[i]);

		acumulador=acumulador + numeros[i];
	}
/*
	printf("1er numero %d\n",numeros[0]);		// una manera de mostrar los resultados ;
	printf("2do numero %d\n",numeros[1]);
	printf("3er numero %d\n",numeros[2]);
	printf("4to numero %d\n",numeros[3]);
	printf("5to numero %d\n",numeros[4]); // el lugar que ocupa en memoria  es unos menos de las itiraciones
	printf("acumulador %d\n",acumulador);

*/												// Manera optimizada de motrar los resultados
	for(i=0 ;i<5; i++){

			printf("los numeros ingresados son = %d\n", numeros[i] );


	}
	printf("acumulador %d\n",acumulador);



	return EXIT_SUCCESS;
}


