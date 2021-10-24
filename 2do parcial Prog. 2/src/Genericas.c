/*
 * Genericas.c
 *
 *  Created on: 7 jun. 2021
 *      Author: Lucas
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"

/** \brief Validador de datos ,verifica si fue ingresado un  numero entero el usuario ..
 *
 * \param int resultado donde devolvera por referencia el numero si es valido
 * \param char *mensaje, mensaje indicativo
 * \param char *mensajeError mensaje indicando error
 * \param int valor minimo a ingresar
 * \param int valor maximo a ingresar
 * \return int exito (0) si no pudo validar el entero
 *  		int exito (1) si  pudo validar el entero correctamente.
 *
 */
int levantaEnteros(int *resultado, char *mensaje, char *mensajeError, int min,
		int max) {
	int aux;
	int exito = 0;
	int tipoValidado;

	if (resultado != NULL && mensaje != NULL && mensajeError != NULL
			&& min <= max) {
		do {
			printf("%s\n", mensaje);
			fflush(stdin);
			tipoValidado = scanf("%d", &aux);
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
/** \brief imprime menu generico asi mismo levanta y valida la opcion seleccionada
 *  \param int *pmenu, devolvera por puntero la opcion seleccionada
 *
 * \return void
 */
void DesplegarMenu(int *pMenu) {

	printf(
			"\n\t        |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"
			"\t	||||                      Menu Principal                           ||||\n"
			"\t	|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"
					"|1| Cargar los datos de los Libros desde el archivo Datos.csv (modo texto).\n"
					"|2| Agregar libro.\n"
					"|5| Ordenar libro.\n"
					"|6| Imprimir lista.\n"
					"|7| Aplicar descuentos.\n"
					"|5| Salir.\n");

	levantaEnteros(pMenu, "Ingrese una opcion ", "#Error,ingrese una opcion valida", 1, 7);
}
/** \brief imprime un mensaje con un recuadro distintivo
 *  \param  char* mensaje = espera un mensaje entre comillas como parametro actual
 */
void printMensaje(char *mensaje) {

	printf(
			"==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==\n"
					"" "%s" ""
					"==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==\n",
			mensaje);
}

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
/** \brief espera una cadena de caracteres , DESCRIPCION EDITORIAL  el cual sera convertido a (ID EDITORIAL)  segun corresponda.
 * \param char string , espera una cadena de caracteres
 * \param char retorna por puntero un int
 */
int convertidorDeCharEntero(char *string, int *idaCargar) {
	int E = 0;
	int i;
	int id = 0;
	char matriz[6][32] = { "Planeta", "SIGLO XXI EDITORES", "Pearson", "Minotauro",
			"SALAMANDRA", "PENGUIN BOOKS" };
	if (string != NULL) {

		for (i = 0; i < 6; i++) {
			if ((strcmp(matriz[i], string)) == 0) {
				id = i + 1;
				*idaCargar = id;
				break;
			} else {
				E = 0;
			}
		}
		E = 1;
	}
	return E;
}
/** \brief espera un entero ,(ID EDITORIAL) el cual sera convertido a DESCRIPCION EDITORIAL segun corresponda.
 * \param int enteroAconvertir , espera un entero .
 * \param char retorna por puntero un array de caracteres
 */
int convertidorDeEnteroaChar(int enteroAconvertir,char* stringConvertido){
	int E=0;
	if(enteroAconvertir>0){

		switch(enteroAconvertir){
		case 1:
			strcpy(stringConvertido,"Planeta");
				break;
		case 2:
			strcpy(stringConvertido,"SIGLO XXI EDITORES");
				break;
		case 3:
			strcpy(stringConvertido,"Pearson");
				break;
		case 4:
			strcpy(stringConvertido,"Minotauro");
				break;
		case 5:
			strcpy(stringConvertido,"SALAMANDRA");
				break;
		case 6:
			strcpy(stringConvertido,"PENGUIN BOOKS" );
				break;
		}
	}
	return E;
}

int levantaArchivos(char cadena[], char *mensaje,char *mensajeError, int largoCadena) {
	int exito = 0;

	char auxCadena[largoCadena];
	//inicializarCadenaCaracteres(auxCadena, largoCadena);

	if (cadena != NULL && mensaje != NULL && mensajeError != NULL
			&& largoCadena > 0) {
		while (exito == 0) {
			printf("%s\n", mensaje);
			fflush(stdin);
			if (fgets(auxCadena, largoCadena, stdin) != NULL) {
				exito = 1;

				auxCadena[strcspn(auxCadena, "\n")] = 0;
				strcpy(cadena, auxCadena);
			} else {
				printf("%s\n", mensajeError);
			}
		}
	}
	return exito;
}



