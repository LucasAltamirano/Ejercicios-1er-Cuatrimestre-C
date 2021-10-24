/*
 * UTN.Calculos.c
 *
 *  Created on: 16 abr. 2021
 *      Author: STELLA YAMMETI
 */



#include <stdio.h>
#include <stdlib.h>

int Sumar(int a, int b, int *punteroSuma) {

	int retorno;
	int suma;
	retorno = 0;

	if (punteroSuma != NULL) {
		suma = a + b;
		*punteroSuma = suma;
		retorno = 1;
	}

	return retorno;

}

int Restar(int a, int b, int *punteroResta) {
	int retorno;
	int resta;
	retorno = 0;

	if (punteroResta != NULL) {
		resta = a - b;
		*punteroResta = resta;
		retorno = 1;
	}
	return retorno;
}

int Multiplicar(int a, int b, int *punteroMutiplicacion) {

	int retorno;
	int multiplicacion;
	retorno = 0;

	if (punteroMutiplicacion != NULL) {
		multiplicacion = a * b;
		*punteroMutiplicacion = multiplicacion;
		retorno = 1;
	}
	return retorno;
}

int Dividir(int a, int b, float *punteroDivision) {

	int retorno;
	float division;
	retorno = 0;

	if (punteroDivision != NULL && b != 0) {

		division = a / (float) b;
		*punteroDivision = division;
		retorno = 1;
	}
	return retorno;
}

int Factorial(int a, int *punteroFactorial) {
	int retorno;
	int factorial;
	factorial = 1;
	retorno = 0;
	if (a >= 0 && a < 15) {
		for (int i = 1; i <= a; i++) {
			factorial = factorial * i;
		}
		*punteroFactorial = factorial;
		retorno = 1;

	}
	return retorno;
}
