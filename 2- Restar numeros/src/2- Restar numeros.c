/*
 ============================================================================
 Name        : 2-.c
 Author      : Lucas Altamirano
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int restarDosNumeros(int operadorA,int operadorB,int* resultado);
int main(void) {

	setbuf(stdout, NULL);

	int valorA;
	int valorB;
	int resultado;

	printf("ingrese el valor 1er operando");
	fflush(stdin);
	scanf("%d", &valorA);

	printf("ingrese el valor 2do operando");
	fflush(stdin);
	scanf("%d", &valorB);


	restarDosNumeros(valorA,valorB,&resultado);
	printf("el resultado es %d",resultado);




	return EXIT_SUCCESS;
}

int restarDosNumeros(int operadorA,int operadorB,int* resultado){
	int e=0;

	*resultado=operadorA-operadorB;

	return e;
}
