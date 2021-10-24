/*
 ============================================================================

 Author      : Lucas Altamirano
 Ejercicio 3-1:
 Crear una función que permita determinar si un número es par o no.
 La función retorna 1 en caso afirmativo y 0 en caso contrario. Probar en el main.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int NumeroParImpar(int a); // Prototipo funcion numero par o impar .

int main(void) {
	setbuf(stdout, NULL);

	int numero1;
	int verificacion;

	printf("ingrese el numero ");

	scanf("%d", &numero1);

	verificacion = NumeroParImpar(numero1);

	if (verificacion == 1) {

		printf("El numero ingresado es PAR");
	} else {
		printf("el numero ingresado es IMPAR");
	}

	return EXIT_SUCCESS;
}

int NumeroParImpar(int a) {

	int resultado;

	if (a % 2 == 0) {

		resultado = 1;

		//'1'  numero par

	} else {
		resultado = 0;
		//'0'  numero impar

	}

	return resultado;
}

