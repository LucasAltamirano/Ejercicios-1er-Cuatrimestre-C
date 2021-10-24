/*
 * Contribuyentes.c
 *
 *  Created on: 20 may. 2021
 *      Author: Lucas
 */

#include "Contribuyentes.h"
#include "Particulares.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



void ImprimirUNContribuyente(sContribuyente estructuraRecibida) {
	printf(" %-10d%-15s%-12s%-10s\n", estructuraRecibida.idContribuyente,
			estructuraRecibida.apellido, estructuraRecibida.nombre,
			estructuraRecibida.cuil);
}
void imprimirContribuyentes(sContribuyente estructurasRecibidas[],
		int limitstruct, sRecaudacion recaudacionesEntrantes[],
		int qtyRecaudaciones) {
	int i, j;
	int auxIDcontribuyente;
	int auxIdRecaudacion;
	int controlRegistro;
	for (i = 0; i < limitstruct; i++) {
		if (estructurasRecibidas[i].isEmpty == 0) {
			if (auxIDcontribuyente!= estructurasRecibidas[i].idContribuyente	) {
				printf(
						"------------------DATOS DE CONTRIBUYENTE-------------------\n");
				printf("|Id  	  |Apellido      |Nombre     |Cuil    \n");


				auxIDcontribuyente= estructurasRecibidas[i].idContribuyente	;
			}
			ImprimirUNContribuyente(estructurasRecibidas[i]);

			for (j = 0; j < qtyRecaudaciones; j++) {

				if (estructurasRecibidas[i].idContribuyente== recaudacionesEntrantes[j].idContrRecaudacion) {
					if (auxIdRecaudacion!=recaudacionesEntrantes[i].idRecaudacion) {
						printf(
											"------------------DATOS DE RECAUDACION-------------------\n");
									printf("|Id  	  |Mes         |Tipo     |Importe   |Estado \n");
						auxIdRecaudacion=recaudacionesEntrantes[i].idRecaudacion;

						controlRegistro=1;
					}
					ImprimirUNArecaudacion(recaudacionesEntrantes[j]);
				}

			}
			if (controlRegistro!=1) {

				printf(
						"|||||||||||    EL CONTRIBUYENTE NO REGISTRA RECAUDACIONES    ||||||||||||||||\n");
			}
		}
	}
}
int agregarContribuyentes(sContribuyente estructurasRecibidas[],int espacioLibre,int* asignacionIdcontribuyente) {

	int retorno;
	char auxNombre[20];
	char auxApellido[20];
	char auxCuil[14];

	//float sumadorSalario=0;

	inicializarCadenaCaracteres(auxNombre, 20);
	inicializarCadenaCaracteres(auxApellido, 20);
	inicializarCadenaCaracteres(auxCuil, 14);

	retorno = 0;
	if (estructurasRecibidas != NULL) {

		utn_levantaCadenaCaracteres(auxNombre,"Ingrese Nombre del Contribuyente",
				"#Error,ingrese nombre nuevamente", 20);
			strcpy(estructurasRecibidas[espacioLibre].nombre, auxNombre);

				utn_levantaCadenaCaracteres(auxApellido,
						"Ingrese Apellido del Contribuyente",
						"#Error,ingrese apellido nuevamente", 20);

				strcpy(estructurasRecibidas[espacioLibre].apellido, auxApellido);

			if(utn_getCuit(auxCuil,
								"Ingrese Cuil,11 digitos CON sus respectivos guiones\n",
								"#error Ingrese nuevamente", 3)){
			strcpy(estructurasRecibidas[espacioLibre].cuil, auxCuil);

			estructurasRecibidas[espacioLibre].isEmpty = 0;
								estructurasRecibidas[espacioLibre].idContribuyente=*asignacionIdcontribuyente;

								printf("Alta de contribuyente exitosa\n"
														"Bajo el Id Contribuyente :%d \n",
														*asignacionIdcontribuyente);
								(*asignacionIdcontribuyente)++;
		}

		retorno = 1;
	} //final If

	return retorno;
}

int modificarContribuyente(sContribuyente estructurasRecibidas[],
		int limitstruct) {
	int e;
	int i;


	int auxIdModificar;
	int flagIdExistente;

	int campoModificar;

	char auxNuevoNombre[20];
	char auxNuevoApellido[20];
	char auxNuevoCuil[14];
	flagIdExistente = -1;
	if (estructurasRecibidas != NULL) {
		printf("|| Menu || Modificacion de datos del Contribuyente\n");
		utn_levantaInt(&auxIdModificar,
				" Ingrese Id del contribuyente que desea modificar ",
				" Id Erroneo y/o inexistente verifique○\n", 1000, 9999);

		for (i = 0; i < limitstruct; i++) {
			if (estructurasRecibidas[i].isEmpty != 1
					&& estructurasRecibidas[i].idContribuyente
							== auxIdModificar) {

				flagIdExistente = 1;
				break;
			}else {
				printf("Id Erroneo y/o inexistente verifique");
				e = 0;
			}
		}
		if (flagIdExistente == 1) {
			e = 1;
			printf(" Modificacion de id |%d|\n", auxIdModificar);
			utn_levantaInt(&campoModificar,
					"Ingrese el campo que desa modificar;\n"
							"|1|-Nombre del contribuyente\n"
							"|2|-Apellido del contribuyente\n"
							"|3|-Cuil del contribuyente",
					"Ingrese uuna opcion valida", 1, 3);
			switch (campoModificar) {
			case 1:

				utn_levantaCadenaCaracteres(auxNuevoNombre,
						"Ingrese nuevo Nombre del Contribuyente",
						"#Error,ingrese nombre nuevamente", 20);
				strcpy(estructurasRecibidas[i].nombre, auxNuevoNombre);
				break;
			case 2:
				utn_levantaCadenaCaracteres(auxNuevoNombre,
						"Ingrese nuevo Apellido del Contribuyente",
						"#Error,ingrese apellido nuevamente", 20);
				strcpy(estructurasRecibidas[i].nombre, auxNuevoApellido);
				break;

			case 3:
				utn_getCuit(auxNuevoCuil,
						"Ingrese Cuil,11 digitos CON sus respectivos guiones\n",
						"#error Ingrese nuevamente", 3);
				strcpy(estructurasRecibidas[i].cuil, auxNuevoCuil);

				break;
			}
		}
	}

	return e;

}
int removerContribuyente(sContribuyente estructurasRecibidas[], int limitstruct) {

	int e = -1;
	int idRemover;
	int i;
	int flagIdExistente;
	flagIdExistente = 0;
	int confirmacionRemover;

	if (estructurasRecibidas != NULL) {
		printf("|| Menu || Remover Contribuyente\n");
		printf(
				"Ingrese el ID del Contribuyente que desea suprimir del sistema\n	");
		scanf("%d", &idRemover);

		for (i = 0; i < limitstruct; i++) {
			if (estructurasRecibidas[i].isEmpty != 1
					&& estructurasRecibidas[i].idContribuyente == idRemover) {

				flagIdExistente = 1;
				break;
			}
		}
		if (flagIdExistente == 1) {
			printf(
					"Usted va a suprimir del sistema el ID :%d ,esta seguro de continuar?\n",
					idRemover);
			utn_levantaInt(&confirmacionRemover, "|1|aceptar\n"
					"|2|cancelar\n", "#Error, ingrese opcion valida", 1, 2);

			if (confirmacionRemover == 1) {
				printf("Removiendo Contribuyente del sistema .......\n");
				estructurasRecibidas[i].isEmpty = 1;
				printf("Remocion Exitosa\n");
				volverAtras();
				e=1;
			} else {
				printf("Remocion cancelada por el usuario\n");
				volverAtras();
			}
		} else {
			printf("Id de Contribuyente Inexistente ,verifique\n");
			e=0;
		}

	}

	return e;
}
int obteneridContribuyente(sContribuyente estructurasRecibidas[],int limitstruct, int *idVerificado) {

	int i;
	int flagIdExistente = 1;
	int idVerificar;

	utn_levantaInt(&idVerificar, "ingrese el Id del Contribuyente ",
			"#Error ,intente nuevamente", 1000, 9999);
	for (i = 0; i < limitstruct; i++) {
		if (estructurasRecibidas[i].isEmpty != 1
				&& estructurasRecibidas[i].idContribuyente == idVerificar) {

			*idVerificado = idVerificar;
			flagIdExistente = 0;
			break;
		}else{
			printf("Id inexistente verifique");
		}

	}

	return flagIdExistente;

}
int buscarIsEmpty(sContribuyente estructurasRecibidas[], int limiteStruct,
		int *lugarLibre) {

	int i;
	int retorno ;

	if (estructurasRecibidas != NULL) {
		for (i = 0; i < limiteStruct; i++) {

			if (estructurasRecibidas[i].isEmpty == 1) {
				*lugarLibre = i;

				retorno = 1;

				break;
				// inmediatamente que se localiza un espacio vacio ,
			} //le asigno el mismo(i) a posicion libre y rompo el bloque
		}
	}else{
		retorno = 0;
	}
	return retorno;
}

int inicializarStructContribuyente(sContribuyente estructurasRecibidas[],
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

