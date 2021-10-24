/*
 * Genericas.c
 *
 *  Created on: 15 may. 2021
 *      Author: Lucas
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>




int inicializarCadenaCaracteres(char cadenaRecibida[], int largoCadena) {
	int exito = 0;
	int i;
	if (cadenaRecibida != NULL) {
		for (i = 0; i < largoCadena; i++) {
			cadenaRecibida[i] = ' ';
		}
		exito = 1;
	}
	return exito;
}
void desplegarMenu() {
	printf("\tBIENVENIDOS AL SOFTWARE DE EMPLEADOS \n"
			"|1|Alta de Empleados\n"
			"|2|Modificar datos del Empleado\n"
			"|3|Baja de Empleado\n"
			"|4|Informar\n"
			"|5|Salir\n");
}
int getInt(int *pResultado, char *mensaje, char *mensajeError, int min, int max,
		int reintentos) {
	int aux;
	int exito = 1;
	int tipoValidado;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& min <= max && reintentos > -1) {
		do {
			printf("%s\n", mensaje);
			fflush(stdin);
			tipoValidado = scanf("%d", &aux);
			if (aux < min || aux > max || tipoValidado == 0) {
				printf("%s\n", mensajeError);
				reintentos--;
			} else {
				*pResultado = aux;
				exito = 0;
				break;
			}
		} while (reintentos > -1);
	}
	return exito;
}
int utn_levantaCadenaCaracteres(char cadena[], char *mensaje,
		char *mensajeError, int largoCadena) {
	int exito = 0;
	int i;
	char auxCadena[largoCadena];

	inicializarCadenaCaracteres(auxCadena, largoCadena);

	if (cadena != NULL && mensaje != NULL && mensajeError != NULL
			&& largoCadena > 0) {
		while (exito == 0) {
			printf("%s\n", mensaje);
			fflush(stdin);
			if (fgets(auxCadena, largoCadena, stdin) != NULL) {
				exito = 1;
				for (i = 0; i < largoCadena; i++) {
					if (isdigit(auxCadena[i])) {
						exito = 0;
						break;
					}
				}
				auxCadena[strcspn(auxCadena, "\n")] = 0;
				strcpy(cadena, auxCadena);
			} else {
				printf("%s\n", mensajeError);
			}
		}
	}
	return exito;
}
int levantaEnteros(int *resultado, char *mensaje, char *mensajeError, int min,
		int max, int reintentos) {
	int aux;
	int exito = 1;
	int tipoValidado;

	if (resultado != NULL && mensaje != NULL && mensajeError != NULL
			&& min <= max && reintentos > -1) {
		do {
			printf("%s\n", mensaje);
			fflush(stdin);
			tipoValidado = scanf("%d", &aux);
			if (aux < min || aux > max || tipoValidado == 0) {
				printf("%s\n", mensajeError);
				reintentos--;
			} else {
				*resultado = aux;
				exito = 0;
				break;
			}
		} while (reintentos > -1);
	}
	return exito;
}
int utn_levantaDecimales(float *resultado, char *mensaje, char *mensajeError,float min, float max) {
	float aux;
	int exito = 0;
	int tipoValidado;

	if (resultado != NULL && mensaje != NULL && mensajeError != NULL
			&& min <= max) {
		do {
			printf("%s\n", mensaje);
			fflush(stdin);
			tipoValidado = scanf("%f", &aux);
			if (aux < min || aux > max || tipoValidado == 0) {
				printf("%s\n", mensajeError);
				exito = 0;
			} else {
				*resultado = aux;
				exito = 1;
				break;
			}
		} while (exito == 0);
	}
	return exito;
}
void volverAtras() {
	printf("Pulse cualquier tecla para volver\n");
	fflush(stdin);
	getchar();
}

