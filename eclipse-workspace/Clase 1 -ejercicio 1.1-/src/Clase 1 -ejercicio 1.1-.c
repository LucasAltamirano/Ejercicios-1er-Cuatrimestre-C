/*
 ============================================================================

 Author      : Lucas Altamirano division E

 clase 1


 Ejercicio 1-1: Ingresar dos números enteros,
  sumarlos y mostrar el resultado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);// SIEMPRE!!!!
	int number1;
	int number2;
	float resultado;



	printf("ingrese numero 1 ");
	scanf("%d",&number1);

	printf("ingrese numero 2 ");
	scanf(" %d",&number2);

	resultado=(float)number1/number2;

	printf("resultado final; %.2f",resultado);

	return EXIT_SUCCESS;
}
