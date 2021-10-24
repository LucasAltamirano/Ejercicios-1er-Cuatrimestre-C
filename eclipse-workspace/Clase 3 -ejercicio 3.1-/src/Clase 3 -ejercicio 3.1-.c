/*
 ============================================================================
 Name        : 1E
 Author      : Lucas Altamirano
 b-Funciones
 - Limpie la pantalla
 - Asigne a las variables numero1 y numero2 los valores solicitados al usuario
 - Valide los mismos entre 10 y 100
 - Asigne a la variable operacion el valor solicitado al usuario
 - Valide el mismo 's'-sumar, 'r'-restar
 - Realice la operación de dichos valores a través de una función
 - Muestre el resultado por pantalla
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int OperacionResta(int a, int b); // prototipo de funcion resta
int OperacionSuma(int a, int b); // prototipo funcion suma

int main(void) {

	setbuf(stdout, NULL);

	int numero1;
	int numero2;
	char operacion;
	int resultado;

	printf("Ingrese un numero entre 10 y 100: ");
	scanf("%d", &numero1);
	while (numero1 < 10 || numero1 > 100) {

		printf("ERROR ingrese numero entre 10 y 100: ");
		scanf("%d", &numero1);

	}
	printf("Ingrese un numero entre 10 y 100: ");
	scanf("%d", &numero2);
	while (numero1 < 10 || numero1 > 100) {

		printf("ERROR ingrese numero entre 10 y 100: ");
		scanf("%d", &numero2);

	}
	printf("Ingrese  el tipo de operacion ndeseada 's'-sumar, 'r'-restar ");
															//ffflush(stdin);//si tenes windows
	fflush(stdin);											//fpurge(stdin);//si tenes MAC
    														//__fpurge(stdin);//si tenes linux , debes incluir #include <stdio_ext.h>
	scanf("%c",&operacion);

	while (operacion != 's' && operacion != 'r') {

		printf("ERROR ingrese el tipo de operacion ndeseada 's'-sumar, 'r'-restar  ");
		fflush(stdin);
		scanf("%c",&operacion);
	}
	if (operacion == 's') {

		resultado = OperacionSuma(numero1, numero2);
		printf("el resultado de la suma es ;%d", resultado);

	} else {

		resultado = OperacionResta(numero1, numero2);
		printf("el resultado de la resta es ;%d", resultado);
	}

	return EXIT_SUCCESS;
}

int OperacionSuma(int a, int b) {

	int resultadoSuma;

	resultadoSuma = a + b;

	return resultadoSuma;
}

int OperacionResta(int a, int b) {

	int resultadoResta;

	resultadoResta = a - b;
	return resultadoResta;
}

