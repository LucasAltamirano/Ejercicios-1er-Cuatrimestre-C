/*
 * Recaudaciones.h
 *
 *  Created on: 20 may. 2021
 *      Author: Lucas
 */

#ifndef RECAUDACIONES_H_
#define RECAUDACIONES_H_

struct {

	int idContrRecaudacion;
	int idRecaudacion;
	char mes[20];
	char  tipo[10];
	float importe;
	int isEmpty;
	char estado[20];
}typedef sRecaudacion;

#include "Contribuyentes.h"

void ImprimirUNArecaudacion(sRecaudacion estructuraRecibida);
void imprimirRecaudacion(sRecaudacion recaudacionesRecibidas[], int qtyRecaudaciones,sContribuyente contribuyentesRecibidos[],int qtyContribuyentes) ;
int agregarRecaudacion(sRecaudacion estructurasRecibidas[], int espacioLibre,int *asignacionID, int valorIDcontribuyente);
void refinanciarRecaudacion(sRecaudacion estructurasRecibidas[], int limitstruct,sContribuyente contribuyentesEntrantes[],int qtycontribuyentes);
void saldarRecaudacion(sRecaudacion estructurasRecibidas[], int limitstruct,sContribuyente contribuyentesEntrantes[],int qtycontribuyentes);
int inicializarStructRecaudacion(sRecaudacion estructurasRecibidas[],int limiteStruct);
/**brief Funcion encargada de dar valor 1 = vacio a cada estrucuctura
 * param sRecaudacion eestructurasRecibidas,recibe las estructuras
 * param tipo int la cantidad de estructuras , paramentro par atinirear
 * return devuelve 0 si todo salio bien, caso contrario 1
 */
void recaudacionesSuperiores(sRecaudacion recaudacionesRecibidas[], int qtyRecaudaciones,sContribuyente contribuyentesRecibidos[],int qtyContribuyentes);
void abonofebrero(sRecaudacion recaudacionesRecibidas[], int qtyRecaudaciones,sContribuyente contribuyentesRecibidos[],int qtyContribuyentes) ;

int buscarIsEmptyRecaudacion(sRecaudacion estructurasRecibidas[],int limiteStruct, int *lugarLibre);








#endif /* RECAUDACIONES_H_ */
