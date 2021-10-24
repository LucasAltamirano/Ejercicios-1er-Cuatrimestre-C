/*
 * Genericas.h
 *
 *  Created on: 15 may. 2021
 *      Author: Lucas
 */

#ifndef GENERICAS_H_
#define GENERICAS_H_



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "employees.h"



void desplegarMenu();
int utn_levantaCadenaCaracteres(char cadena[], char *mensaje,char *mensajeError, int largoCadena);

int getInt(int *pResultado, char *mensaje, char *mensajeError, int min, int max,int reintentos);

int inicializarCadenaCaracteres(char cadenaRecibida[], int largoCadena);
int utn_levantaDecimales(float *resultado, char *mensaje, char *mensajeError,float min, float max);
int levantaEnteros(int *resultado, char *mensaje, char *mensajeError, int min,int max, int reintentos);
void volverAtras();


#endif /* GENERICAS_H_ */
