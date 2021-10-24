/*
 * Contribuyentes.h
 *
 *  Created on: 20 may. 2021
 *      Author: Lucas
 */

#ifndef CONTRIBUYENTES_H_
#define CONTRIBUYENTES_H_


struct {
	char nombre[20];
	char apellido[20];
	char cuil[14];
	int idContribuyente;
	int isEmpty;
}typedef sContribuyente;


#include "Recaudaciones.h"


int inicializarStructContribuyente(sContribuyente estructurasRecibidas[],int limiteStruct);
/**brief Funcion encargada de dar valor 1 = vacio a cada estrucuctura
 * param sContribuyent eestructurasRecibidas,recibe las estructuras
 * param tipo int la cantidad de estructuras , paramentro par atinirear
 * return devuelve 0 si todo salio bien, caso contrario 1
 */
int buscarIsEmpty(sContribuyente estructurasRecibidas[], int limiteStruct,int *lugarLibre);
int agregarContribuyentes(sContribuyente estructurasRecibidas[],int espacioLibre,int* asignacionIdcontribuyente) ;
void ImprimirUNContribuyente(sContribuyente estructuraRecibida);
int modificarContribuyente(sContribuyente estructurasRecibidas[],int limitstruct);
int removerContribuyente(sContribuyente estructurasRecibidas[], int limitstruct);
int obteneridContribuyente(sContribuyente estructurasRecibidas[],int limitstruct, int *idVerificado) ;
void imprimirContribuyentes(sContribuyente estructurasRecibidas[],int limitstruct, sRecaudacion recaudacionesEntrantes[],int qtyRecaudaciones);



#endif /* CONTRIBUYENTES_H_ */
