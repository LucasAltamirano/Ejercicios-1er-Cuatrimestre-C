/*
 * Particulares.c
 *
 *  Created on: 20 may. 2021
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
int utn_levantaCadenaCaracteres(char cadena[], char *mensaje,
		char *mensajeError, int largoCadena) {
	int exito = 1;
	int i;
	char auxCadena[largoCadena];

	inicializarCadenaCaracteres(auxCadena, largoCadena);

	if (cadena != NULL && mensaje != NULL && mensajeError != NULL
			&& largoCadena > 0) {
		while (exito == 1) {
			printf("%s\n", mensaje);
			fflush(stdin);
			if (fgets(auxCadena, largoCadena, stdin) != NULL) {
				exito = 0;
				for (i = 0; i < largoCadena; i++) {
					if (isdigit(auxCadena[i])) {
						exito = 1;
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

int esCuit(char *cadena) {
	int ret;
	int i;
	int contadorDigito = 0;
	int contadorGuion = 0;

	if (cadena != NULL) {
		for (i = 0; cadena[i] != '\0'; i++) {
			if (isdigit(cadena[i]) != 0) {
				contadorDigito++;
			} else {
				if (cadena[i] == '-') {
					contadorGuion++;
				} else {
					ret = -1;
					break;
				}
			}
		}
		if (contadorDigito == 11 && contadorGuion == 2) {
			ret = 0;
		}
	}
	return ret;
}
int utn_getCuit(char input[], char mensaje[], char eMensaje[], int reintentos) {
	int ret;
	char buffer[14];
	int i;
	int aux;

	if (input != NULL && mensaje != NULL && eMensaje != NULL
			&& reintentos > 0) {
		for (i = reintentos; i > 0; i--) {
			printf("%s", mensaje); //Se le pide el tipo de dato a ingresar al usuario
			fflush(stdin);
			fgets(buffer, 14, stdin);
			aux = esCuit(buffer);
			if (aux == 0) {
				if (buffer[2] == '-' && buffer[11] == '-') {
					strcpy(input, buffer);
					ret = 1;
					break;
				}
			} else {
				printf("\n %s\n", eMensaje);
			}
		}
	}
	if (reintentos == 0) {
		ret = 0;
	}
	return ret;
}
void volverAtras() {
	printf("Pulse cualquier tecla para volver\n");
	fflush(stdin);
	getchar();
}

int utn_levantaFloat(float *resultado, char *mensaje, char *mensajeError,
		float min, float max) {
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





void desplegarMenu() {
	printf("\tSoftware Administrador de Contribuyentes\n"
			"|1|Alta de Contribuyente\n"
			"|2|Modificar datos del contribuyente\n"
			"|3|Baja de contribuyente\n"
			"|4|Recaudacion\n"
			"|5|Refinanciar Recaudacion\n"
			"|6|Saldar Recaudacion\n"
			"|7|Imprimir Contribuyentes\n"
			"|8|Imprimir Recaudacion\n"
			"|9|Informes\n"
			"|10|Salir del Administrador");
}
int utn_levantaInt(int *presultado, char *mensaje, char *mensajeError,
		float min, float max) {
	int aux;
	int exito = 0;
	int tipoValidado;

	if (presultado != NULL && mensaje != NULL && mensajeError != NULL
			&& min <= max) {
		do {
			printf("%s\n", mensaje);
			fflush(stdin);
			tipoValidado = scanf("%d", &aux);
			if (aux < min || aux > max || tipoValidado == 0) {
				printf("%s\n", mensajeError);
				exito = 0;
			} else {
				*presultado = aux;
				exito = 1;
				break;
			}
		} while (exito == 0);
	}
	return exito;
}
