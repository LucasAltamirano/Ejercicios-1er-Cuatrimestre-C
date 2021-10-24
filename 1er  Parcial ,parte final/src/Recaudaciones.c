/*
 * Recaudaciones.c
 *
 *  Created on: 20 may. 2021
 *      Author: Lucas
 */

#include "Recaudaciones.h"
#include "Particulares.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int agregarRecaudacion(sRecaudacion recaudacionesRecibidas[], int espacioLibre,
		int *asignacionID, int valorIDcontribuyente) {

	int retorno;
	int auxMes;
	int auxTipo;
	float auxImporte;

	retorno = -1;
	if (recaudacionesRecibidas != NULL) {
		utn_levantaInt(&auxMes,
				"Ingrese mes\n" "|1|Enero\n" "|2|Febrero\n" "|3|Marzo\n" "|4|Abril\n" "|5|Mayo\n" "|6|Junio\n"
						"|7|Julio\n"
						"|8|Agosto\n"
						"|9|Septiembre\n"
						"|10|Octubre\n"
						"|11|Noviembre\n"
						"|12|Diciembre\n", "ingrese una opcion valida", 1, 12);
		switch (auxMes) {

		case 1:
			strcpy(recaudacionesRecibidas[espacioLibre].mes, "Enero");
			break;
		case 2:
			strcpy(recaudacionesRecibidas[espacioLibre].mes, "Febrero");
			break;
		case 3:
			strcpy(recaudacionesRecibidas[espacioLibre].mes, "Marzo");
			break;
		case 4:
			strcpy(recaudacionesRecibidas[espacioLibre].mes, "Abril");
			break;
		case 5:
			strcpy(recaudacionesRecibidas[espacioLibre].mes, "Mayo");
			break;
		case 6:
			strcpy(recaudacionesRecibidas[espacioLibre].mes, "Junio");
			break;
		case 7:
			strcpy(recaudacionesRecibidas[espacioLibre].mes, "Julio");
			break;
		case 8:
			strcpy(recaudacionesRecibidas[espacioLibre].mes, "Agosto");
			break;
		case 9:
			strcpy(recaudacionesRecibidas[espacioLibre].mes, "Septiembre");
			break;
		case 10:
			strcpy(recaudacionesRecibidas[espacioLibre].mes, "Octubre");
			break;
		case 11:
			strcpy(recaudacionesRecibidas[espacioLibre].mes, "Noviembre");
			break;
		case 12:
			strcpy(recaudacionesRecibidas[espacioLibre].mes, "Diciembre");
			break;

		}

		utn_levantaInt(&auxTipo,
				"Ingrese tipo \n" "|1|ARBA\n" "|2|IIBB\n" "|3|GANANCIAS\n",
				"Ingrese una opcion Valida", 1, 3);
		if (auxTipo == 1) {
			strcpy(recaudacionesRecibidas[espacioLibre].tipo, "ARBA");
		}
		if (auxTipo == 2) {
			strcpy(recaudacionesRecibidas[espacioLibre].tipo, "IIBB");
		}
		if (auxTipo == 3) {
			strcpy(recaudacionesRecibidas[espacioLibre].tipo, "GANANCIAS");
		}

		utn_levantaFloat(&auxImporte, "Ingrese importe", "#Error , verifique",
				0.00, 100000.00);
		recaudacionesRecibidas[espacioLibre].idContrRecaudacion =
				valorIDcontribuyente;
		recaudacionesRecibidas[espacioLibre].importe = auxImporte;
		recaudacionesRecibidas[espacioLibre].idRecaudacion = *asignacionID;
		printf("Alta de recaudacion exitosa\n" "Bajo de Id Recaudacion:%d\n",
				*asignacionID);
		(*asignacionID)++;
		recaudacionesRecibidas[espacioLibre].isEmpty = 0;
		strcpy(recaudacionesRecibidas[espacioLibre].estado, "Nuevo");

		retorno = 0;
	} //final If

	return retorno;
}
void refinanciarRecaudacion(sRecaudacion recaudacionesRecibidas[],
		int qtyRecaudaciones, sContribuyente contribuyentesRecibidos[],
		int qtycontribuyentes) {

	int IdRValidado;
	int i, j;
	int cabeceraRecaudacion = 1;
	int cabeceraContribuyente = 1;
	int confirma;
	int valor;

	utn_levantaInt(&IdRValidado,
			"Ingrese el Id Recaudacion que desea financiar",
			"Ingrese un numero valido", 100, 999);

	for (i = 0; i < qtyRecaudaciones; i++) {
		if (recaudacionesRecibidas[i].isEmpty == 0) {

			if (recaudacionesRecibidas[i].idRecaudacion == IdRValidado
					&& cabeceraRecaudacion) {

				printf(
						"------------------DATOS DE RECAUDACION-------------------\n");
				printf("|Id  	  |Mes         |Tipo     |Importe   |Estado \n");
				cabeceraRecaudacion = 0;

				ImprimirUNArecaudacion(recaudacionesRecibidas[i]);
				valor = i;
			}
		}
		for (j = 0; j < qtycontribuyentes; j++) {

			if (recaudacionesRecibidas[i].idContrRecaudacion
					== contribuyentesRecibidos[j].idContribuyente) {

				if (cabeceraContribuyente) {
					printf(
							"------------------DATOS DE CONTRIBUYENTE-------------------\n");
					printf("|Id  	  |Apellido      |Nombre     |Cuil    \n");

					cabeceraContribuyente = 0;
					ImprimirUNContribuyente(contribuyentesRecibidos[j]);
				}

			}
		}
	}
	utn_levantaInt(&confirma, "Desea cambiar el estado a Refinanciar?\n"
			"|1|aceptar\n"
			"|2|cancelar\n", "ingrese una opcion valida", 1, 2);

	if (confirma == 1) {
		printf(" Refinanciando ... aguarde unos instantes..\n"
				"Solicitud exitosa");
		strcpy(recaudacionesRecibidas[valor].estado, "refinanciar");
		volverAtras();

	} else {
		printf("Refinanciacion .cancelada por el usuario");
		volverAtras();
	}
}
void saldarRecaudacion(sRecaudacion recaudacionesRecibidas[],
		int qtyRecaudaciones, sContribuyente contribuyentesRecibidos[],
		int qtyContribuyentes) {
	int IdRValidado;
	int i, j;
	int cabeceraRecaudacion = 1;
	int cabeceraContribuyente = 1;
	int confirma;
	int valor;
	utn_levantaInt(&IdRValidado, "Ingrese el Id Recaudacion que desea Saldar",
			"Ingrese un numero valido", 100, 999);

	for (i = 0; i < qtyRecaudaciones; i++) {
		if (recaudacionesRecibidas[i].isEmpty == 0) {

			if (recaudacionesRecibidas[i].idRecaudacion == IdRValidado
					&& cabeceraRecaudacion) {

				printf(
						"------------------DATOS DE RECAUDACION-------------------\n");
				printf("|Id  	  |Mes         |Tipo     |Importe   |Estado \n");
				cabeceraRecaudacion = 0;

				ImprimirUNArecaudacion(recaudacionesRecibidas[i]);
				valor = i;
			}
		}
		for (j = 0; j < qtyContribuyentes; j++) {

			if (recaudacionesRecibidas[i].idContrRecaudacion
					== contribuyentesRecibidos[j].idContribuyente) {

				if (cabeceraContribuyente) {
					printf(
							"------------------DATOS DE CONTRIBUYENTE-------------------\n");
					printf("|Id  	  |Apellido      |Nombre     |Cuil    \n");
					cabeceraContribuyente = 0;
					ImprimirUNContribuyente(contribuyentesRecibidos[j]);
				}

			}
		}
	}

	utn_levantaInt(&confirma, "Desea cambiar el estado a Saldado?\n"
			"|1|aceptar\n"
			"|2|cancelar\n", "ingrese una opcion valida", 1, 2);

	if (confirma == 1) {
		printf(" Saldando ... aguarde unos instantes..\n"
				"Solicitud exitosa");
		strcpy(recaudacionesRecibidas[valor].estado, "Saldado");
		volverAtras();

	} else {
		printf("operacion .cancelada por el usuario");
		volverAtras();
	}
}

void ImprimirUNArecaudacion(sRecaudacion estructuraRecibida) {
	printf(" %-10d%-13s%-11s%-10.2f%-6s\n", estructuraRecibida.idRecaudacion,
			estructuraRecibida.mes, estructuraRecibida.tipo,
			estructuraRecibida.importe, estructuraRecibida.estado);
}
void imprimirRecaudacion(sRecaudacion recaudacionesRecibidas[],
		int qtyRecaudaciones, sContribuyente contribuyentesRecibidos[],
		int qtyContribuyentes) {
	int i, j;

	int imprimir = 1;

	for (i = 0; i < qtyRecaudaciones; i++) {
		if (recaudacionesRecibidas[i].isEmpty == 0) {
			if (!(strcmp(recaudacionesRecibidas[i].estado, "Saldado"))) {

				if (imprimir) {
					printf(
							"------------------DATOS DE RECAUDACION-------------------\n");
					printf(
							"|Id  	  |Mes         |Tipo     |Importe   |Estado \n");
					imprimir = 0;

				}
				ImprimirUNArecaudacion(recaudacionesRecibidas[i]);
			}

		}

		for (j = 0; j < qtyContribuyentes; j++) {

			if (recaudacionesRecibidas[i].idContrRecaudacion
					== contribuyentesRecibidos[j].idContribuyente) {

				if (imprimir != 1) {
					printf(
							"------------------DATOS DE CONTRIBUYENTE-------------------\n");
					printf("|Id  	  |Apellido      |Nombre     |Cuil    \n");

				}
				ImprimirUNContribuyente(contribuyentesRecibidos[j]);
			}
		}
	}

}
int buscarIsEmptyRecaudacion(sRecaudacion estructurasRecibidas[],
		int limiteStruct, int *lugarLibre) {

	int i;
	int retorno = 1;

	if (estructurasRecibidas != NULL) {
		for (i = 0; i < limiteStruct; i++) {

			if (estructurasRecibidas[i].isEmpty == 1) {
				*lugarLibre = i;

				retorno = 1;

				break;
				// inmediatamente que se localiza un espacio vacio ,
			} else {
				retorno = 0; //le asigno el mismo(i) a posicion libre y rompo el bloque
			}
		}
	}
	return retorno;
}

int inicializarStructRecaudacion(sRecaudacion estructurasRecibidas[],
		int limiteStruct) {

	int i;
	int retorno;
	retorno = -1;
	if (estructurasRecibidas != NULL) {
		for (i = 0; i < limiteStruct; i++) {
			estructurasRecibidas[i].isEmpty = 1;
			retorno = 0;
		}

	}

	return retorno;
}
void abonofebrero(sRecaudacion recaudacionesRecibidas[], int qtyRecaudaciones,
		sContribuyente contribuyentesRecibidos[], int qtyContribuyentes) {
	int i, j;

	int flagExiste = 1;

	for (i = 0; i < qtyRecaudaciones; i++) {
		if (recaudacionesRecibidas[i].isEmpty == 0) {
			if (!(strcmp(recaudacionesRecibidas[i].estado, "Saldado"))) {
				if (!(strcmp(recaudacionesRecibidas[i].estado, "Febrero"))) {

					if (flagExiste) {
						printf(
								"------------------DATOS DE RECAUDACION-------------------\n");
						printf(
								"|Id  	  |Mes         |Tipo     |Importe   |Estado \n");
						flagExiste = 0;
						ImprimirUNArecaudacion(recaudacionesRecibidas[i]);
					}
				}
			}

		}

		for (j = 0; j < qtyContribuyentes; j++) {

			if (recaudacionesRecibidas[i].idContrRecaudacion
					== contribuyentesRecibidos[j].idContribuyente) {

				if (flagExiste != 1) {
					printf(
							"------------------DATOS DE CONTRIBUYENTE-------------------\n");
					printf("|Id  	  |Apellido      |Nombre     |Cuil    \n");
					flagExiste = 0;
					ImprimirUNContribuyente(contribuyentesRecibidos[j]);
				}

			}
		}
	}
	if (flagExiste == 1) {
		printf("no existe liquidaciones en febrero\n");
	}

}

void recaudacionesSuperiores(sRecaudacion recaudacionesRecibidas[],
		int qtyRecaudaciones, sContribuyente contribuyentesRecibidos[],
		int qtyContribuyentes) {
	int i, j;

	int bandera = 1;
	int cabeceraContribuyente = 1;

	for (i = 0; i < qtyRecaudaciones; i++) {
		if (recaudacionesRecibidas[i].isEmpty == 0) {
			if (!(strcmp(recaudacionesRecibidas[i].estado, "Saldado"))) {
				if (recaudacionesRecibidas[i].importe > 1000.00) {

					if (bandera) {
						printf(
								"------------------DATOS DE RECAUDACION-------------------\n");
						printf(
								"|Id  	  |Mes         |Tipo     |Importe   |Estado \n");
						bandera = 0;
						ImprimirUNArecaudacion(recaudacionesRecibidas[i]);
					}
				}
			}

		}

		for (j = 0; j < qtyContribuyentes; j++) {

			if (recaudacionesRecibidas[i].idContrRecaudacion
					== contribuyentesRecibidos[j].idContribuyente) {

				if (cabeceraContribuyente) {
					printf(
							"------------------DATOS DE CONTRIBUYENTE-------------------\n");
					printf("|Id  	  |Apellido      |Nombre     |Cuil    \n");
					cabeceraContribuyente = 0;
					ImprimirUNContribuyente(contribuyentesRecibidos[j]);
				}

			}
		}
	}
	if (bandera == 1) {
		printf("no existe recaudacion mayor a 1000\n");
	}

}

