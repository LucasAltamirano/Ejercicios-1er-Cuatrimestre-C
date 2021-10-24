/*
 ============================================================================
 Name        : Clase.c
 : Lucas Altamirano
 Ejercicio 2-1:
 Ingresar 5 números enteros calcular y mostrar el promedio de los números. Probar la
 aplicación con distintos valores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define porc 5

int main(void) {

	int numero;
	int sumaNumero;

	int control;
	float porcentajeFinal;

	control = 0;
	sumaNumero = 0;


	setbuf(stdout, NULL);

	for (control = 0; control < 5; control++) {

		printf(" ingrese 5 numeros");
			fflush(stdin);
			scanf("%d",&numero);


		sumaNumero = sumaNumero + numero;
	}

	porcentajeFinal=(float)sumaNumero/porc;


	printf("el resultado final es %.2f", porcentajeFinal);

	return EXIT_SUCCESS;
}
