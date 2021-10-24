/*
 * UTN.Menu.c
 *
 *  Created on: 16 abr. 2021
 *      Author: STELLA YAMMETI
 */




#include <stdio.h>
#include <stdlib.h>
#include "UTN.Calculos.h"

void MiMenu() {

	setbuf(stdout, NULL);

	int numero1;
	int numero2;
	int sumaMenu;
	int restaMenu;
	int multiplicacionMenu;
	float divisionMenu;
	int factorialA;

	int opcion;
	int banderaNumero1;
	int banderaNumero2;
	int banderaOpcion3;
	banderaNumero1 = 0;
	banderaNumero2 = 0;
	banderaOpcion3 = 0;

	printf("\n\tMenu Calculadora \n");
	do {
		printf("\n1-Ingrese el 1er numero\n");
		printf("2-Ingrese el 2do numero\n");
		printf("3-Calcular los resultados\n");
		printf("4-Mostrar los resultados\n");
		printf("5-Salir de la calculadora");
		scanf("%d", &opcion);
		switch (opcion) {
		case 1:
			printf("\n-Ingrese el 1er numero(A)\n");
			scanf("%d", &numero1);
			printf("\t A=%d\n", numero1);
			banderaNumero1 = 1;
			break;
		case 2:
			if (banderaNumero1 == 1) {
				printf("\nIngrese el 2do numero(B)\n ");
				scanf("%d", &numero2);
				printf("\t A=%d     B=%d\n", numero1, numero2);
				banderaNumero2 = 1;
			} else {
				printf("\nIngresar el 1er Numero en opcion 1 \n");
			}
			break;
		case 3:
			if (banderaNumero1 != 1 || banderaNumero2 != 1) {
				printf(
						" Debera ingresar los dos numeros para calcular los resultados\n ");
			} else {
				printf("\nEspere un instante por favor \n");
				if (Sumar(numero1, numero2, &sumaMenu)) {
					printf("calculo de  (%d+%d) ,Operacion exitosa\n", numero1,
							numero2);
				} else {
					printf("calculo  de  (%d+%d) Operacion fallida", numero1,
							numero2);
				}
				if (Restar(numero1, numero2, &restaMenu)) {
					printf("calculo de  (%d-%d) ,Operacion exitosa\n", numero1,
							numero2);
				} else {
					printf("calculo de  (%d-%d) Operacion fallida", numero1,
							numero2);
				}
				if (Multiplicar(numero1, numero2, &multiplicacionMenu)) {
					printf("calculo de  (%d*%d) ,Operacion exitosa\n", numero1,
							numero2);
				} else {
					printf("calculo de  (%d*%d) Operacion fallida", numero1,
							numero2);
				}
				if (Dividir(numero1, numero2, &divisionMenu)) {
					printf("calculo de  (%d/%d) ,Operacion exitosa\n", numero1,
							numero2);
				} else {
					printf("calculo de (%d/%d) Syntax ERROR\n", numero1,
							numero2);
				}
				if (Factorial(numero1, &factorialA)) {
					printf("calculo Factorial de  (%d) ,Operacion exitosa\n",
							numero1);
				} else {
					printf("Syntax ERROR");
				}
			}
			banderaOpcion3 = 1;
			break;
		case 4:
			if (banderaOpcion3 != 1) {
				printf(
						"\nPara Mostrar los resultados ,primero es necesario Calcular los mismos  en Opcion #3\n");
			} else {
				printf(" El resultado de %d + %d es: %d\n", numero1, numero2,
						sumaMenu);

				printf(" El resultado de %d - %d es: %d\n", numero1, numero2,
						restaMenu);

				if (divisionMenu != 0) {
					printf(" El resultado de %d/ %d es: %.2f\n", numero1,
							numero2, divisionMenu);
				} else {
					printf(" No es posible dividir por cero\n");
				}

				printf(" El resultado de %d * %d es: %d\n", numero1, numero2,
						multiplicacionMenu);

				printf(" El resultado de Factorial A(%d)  es: %d \n", numero1,
						factorialA);
			}
			break;
		case 5:
			printf("\n Salio de la Calculadora \n");
			break;
		default:
			printf("\n Ingrese una opcion valida\n");
			break;
		}
	} while (opcion != 5);
}
