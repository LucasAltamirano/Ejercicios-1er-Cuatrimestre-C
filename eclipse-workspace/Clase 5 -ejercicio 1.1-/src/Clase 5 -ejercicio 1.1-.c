/*
 ============================================================================

 Author      : ALTAMIRANO LUCAS
 DIV 1 E

 Ejercicio array paralelo:
 de 10 empleados, cargar edad y sueldo.
 Se pide ingresar los datos consecutivamente y calcular el sueldo promedio.


 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
float Promedio(float a, int b); // protptipo

#define EMPLEADOS 3

int main(void) {

	setbuf(stdout, NULL);

	int i;
	int edad[10]; // array de tipo int  , de 10 valores
	float sueldo[10]; // array de tipo float , de 10 valores
	float acumuladorSueldo;
	float sueldoPromedio;

	acumuladorSueldo = 0;

	for (i = 0; i < EMPLEADOS; i++) {

		printf("Ingrese la edad del empleado ");
		scanf("%d", &edad[i]);
		printf("Ingrese el sueldo del empleado ");
		scanf("%f", &sueldo[i]);

		acumuladorSueldo = acumuladorSueldo + sueldo[i];

	}

	sueldoPromedio = Promedio(acumuladorSueldo, EMPLEADOS); /// implementacion define
	printf(" El sueldo promedio es =%.2f", sueldoPromedio);

	return EXIT_SUCCESS;
}

float Promedio(float a, int b) {
	float resultado;

	resultado = a / b;

	return resultado;
}

