/*
 * Genericas.h
 *
 *  Created on: 9 may. 2021
 *      Author: Lucas
 */

#ifndef GENERICAS_H_
#define GENERICAS_H_

int levantaEnteros(int* resultado,char* mensaje,char* mensajeError,int min,int max,int reintentos);
/**
 *
 *
 */
int inicializarStruct(int estructurasRecibidas[],int limiteStruct);
/**brief  inicializa todos  los campos isEmpty de el struct  en 1, (libre)
* \param estructurasRecibidas el puntero al primer array
* \param int limiteStruct ,cantidad de struct a recorrer;
* \returna -1 , si algo salio mal, o 0(cero) si salio todo ok
*/

int cargarStruct(struct estructurasRecibidas[],int espacioLibre);
int buscarVacio(int estructurasRecibidas[],int limiteStruct );

#endif /* GENERICAS_H_ */
