/*
 * Particulares.h
 *
 *  Created on: 20 may. 2021
 *      Author: Lucas
 */
#ifndef PARTICULARES_H_
#define PARTICULARES_H_



void volverAtras();
/**
 * brief;precionar tecla para volver atras:
 * de tipo void
 *
 */
void desplegarMenu();
/**
 * brief; unica funcion imprimir menu generico
 * void no recibe nada ni devulve nada
 *
 */
int utn_levantaInt(int *presultado, char *mensaje, char *mensajeError,float min, float max);
int utn_levantaFloat(float *resultado, char *mensaje, char *mensajeError,float min, float max);
int esCuit(char *cadena) ;
int utn_getCuit(char input[], char mensaje[], char eMensaje[], int reintentos);
int inicializarCadenaCaracteres(char cadenaRecibida[], int largoCadena);
int utn_levantaCadenaCaracteres(char cadena[], char *mensaje,char *mensajeError, int largoCadena);






#endif /* PARTICULARES_H_ */

