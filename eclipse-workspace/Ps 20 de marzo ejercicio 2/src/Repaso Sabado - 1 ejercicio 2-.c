/*
 ============================================================================
 Lucas Altamirano division E
 REPASO SABADO 20 DE MARZO
 EJERCICIO 2

 Ingresar 5 números. Determinar cuál es el máximo y el mínimo e indicar en
 qué orden fue ingresado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int numeroIngresado;
	int numeroMaximo;
	int numeroMinimo;
	int ordenNumeroMin;
	int ordenNumeroMax;
	int contador;

	int control;

	contador = 0;



	setbuf(stdout, NULL);

	for (control = 0; control < 5; control++) {

		printf("ingrese un numero ");
		scanf("%d", &numeroIngresado);

		contador++;

		if (control == 0 || numeroIngresado < numeroMinimo) {

			numeroMinimo = numeroIngresado;
			ordenNumeroMin = contador;

		}

		if (control == 0 || numeroIngresado > numeroMaximo) {

			numeroMaximo = numeroIngresado;
			ordenNumeroMax = contador;
		}

	} //fin del for

	//salidaDatos

	printf("el numero maximo es :%d , en la posicion  %d", numeroMaximo,ordenNumeroMax);
	printf("\nel numero minimo es :%d , en la posicion %d", numeroMinimo,ordenNumeroMin);

	return EXIT_SUCCESS;
} //fin funcion
