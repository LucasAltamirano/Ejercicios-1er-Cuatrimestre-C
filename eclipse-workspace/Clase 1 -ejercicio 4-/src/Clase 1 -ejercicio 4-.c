/*
 ============================================================================
 Name        : Clase.c
 Author      : Lucas Altamirano division E
 clase 1 ejercicio 4
 Operadores Logicos
Aplicando el concepto de Operadores Lógicos con valores booleanos en el condicional:
Solicitar un número al usuario
Informar si el mismo es par o impar.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int numeroIngresado;

	setbuf(stdout, NULL);

	printf("ingrese un numero por favor");
	scanf("%d",&numeroIngresado);

	if(numeroIngresado%2==0){

		printf("el numero ingresado es PAR");
	}else
	{
		printf("su numero ingresado  es IMPAR");
	}


	return EXIT_SUCCESS;
}// fin de funcion
