/*
 ============================================================================
 ALTAMIRANO LUCAS DIVISION E
 Practica Sabado -20 de marzo
 Ejercicio 1:

 Ingresar números enteros, hasta que el usuario lo decida. Calcular y mostrar:
 a) El promedio de los números positivos.
 b) El promedio de los números negativos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int numeroIngresado;
	int contadorPositivo;
	int contadorNegativo;
	int sumadorPositivos;
	int sumadorNegativos;
	float promedioPositivos;
	float promedioNegativos;
	char i;

	i = 's';
	contadorNegativo = 0;
	contadorPositivo = 0;
	sumadorNegativos = 0;
	sumadorPositivos = 0;

	setbuf(stdout, NULL);

	while (i == 's') {

		printf("ingrese un numero");
		scanf("%d", &numeroIngresado);

		if (numeroIngresado > 0) {
			contadorPositivo++;
			sumadorPositivos = sumadorPositivos + numeroIngresado;

		} else {
			if (numeroIngresado < 0) {
				contadorNegativo++;
				sumadorNegativos = sumadorNegativos + numeroIngresado;
			}
		}

		printf("Desea ingresar otro numero ? S/N");
		fflush(stdin);
		scanf("%c", &i);

	} // fin del while//

	if (contadorPositivo > 0) {
		promedioPositivos = sumadorPositivos / contadorPositivo;
		printf("el promedio de los positivos es ; %.2f", promedioPositivos);

	} else {

		printf("no se ingresaron numeros positivos");
	}
	if (contadorNegativo != 0) {

		promedioNegativos = sumadorNegativos / contadorNegativo;
		printf("\nel promedio de los negativos es ; %.2f", promedioNegativos);

	} else {

		printf("\nno se ingresaron numeros negativos");
	}


	return EXIT_SUCCESS;

} // fin de la funcion

