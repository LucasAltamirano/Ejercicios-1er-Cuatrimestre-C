/*============================================================================

 // Author      : Lucas Altamirano div E
 clase 1      :Ejercicio 1-2:

 ingresar 3 números y mostrar el mayor de los tres.

 ============================================================================*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	setbuf(stdout, NULL);

	int number1;
	int number2;
	int number3;



	printf("ingrese numero #1");
	scanf(" %d", &number1);
	printf("ingrese numero #2");
	scanf(" %d", &number2);
	printf("ingrese numero #3");
	scanf(" %d", &number3);

	if (number1 > number2 && number1 > number3) {
		printf("el numero mayor es numero #1 %d ", number1);

	} else {
		if (number2 > number3) {
			printf("el numero mayor es numero #2 %d ", number2);

		} else {
			printf("el numero mayor es numero #3 %d ", number3);

		}
	}

	return 0;
}
