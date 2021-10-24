/*
 * Genericas.h
 *
 *  Created on: 7 jun. 2021
 *      Author: Lucas altamirano
 */

#ifndef GENERICAS_H_
#define GENERICAS_H_

int levantaEnteros(int *resultado, char *mensaje, char *mensajeError,int min, int max);
void DesplegarMenu(int* pMenu);
int utn_levantaCadenaCaracteres(char cadena[], char *mensaje,char *mensajeError, int largoCadena);
int inicializarCadenaCaracteres(char cadenaRecibida[], int largoCadena);

void printMensaje (char *mensaje);

int convertidorDeCharEntero(char *string,int *idcarga);
int convertidorDeEnteroaChar(int enteroAconvertir,char* stringConvertido);
int levantaArchivos(char cadena[], char *mensaje,char *mensajeError, int largoCadena);
#endif /* GENERICAS_H_ */
