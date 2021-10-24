/*
 ============================================================================
 Name        : 1er.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Recaudaciones.h"
#include "Contribuyentes.h"
#include "Particulares.h"

// DEFINE
#define QTYCONTRIBUYENTES 50
#define QTYRECAUDACIONES 50

int main(void) {
	setbuf(stdout, NULL);

	int opcionMenu;
	int espacioLibre;
	int asigdContribuyente;
	asigdContribuyente = 1000;

	int espacioLibreRecaudacion;
	int IdContribuyenteValidado;
	int asignoIdRecaudacion;
	asignoIdRecaudacion = 100;

	sContribuyente contribuyente[QTYCONTRIBUYENTES];
	inicializarStructContribuyente(contribuyente, QTYCONTRIBUYENTES);
	sRecaudacion recaudacion[QTYRECAUDACIONES];
	inicializarStructRecaudacion(recaudacion, QTYRECAUDACIONES);
	do {

		desplegarMenu();
		if (utn_levantaInt(&opcionMenu, " ", "#Error,Ingrese una opcion valida",
				1, 10)) {
			switch (opcionMenu) {
			case 1:
				if (buscarIsEmpty(contribuyente, QTYCONTRIBUYENTES,&espacioLibre)) {
					if (!(agregarContribuyentes(contribuyente, espacioLibre,
							&asigdContribuyente))) {
						printf("#Error, en la carga de datos verifique");
					}
				} else {
					printf(
							"No hay espacio disponible, elimine algun contribuyente");
				}
				break;
			case 2:
				if (!(modificarContribuyente(contribuyente, QTYCONTRIBUYENTES))) {
					printf("#Error, en la Modificacion de datos verifique");
				}
				break;
			case 3:
				if (!(removerContribuyente(contribuyente, QTYCONTRIBUYENTES))) {
					printf("#Error, en la remosion de datos verifique");
				}
				break;
			case 4:
				if (!(obteneridContribuyente(contribuyente, QTYCONTRIBUYENTES,
						&IdContribuyenteValidado))) {

					if (buscarIsEmptyRecaudacion(recaudacion, QTYRECAUDACIONES,
							&espacioLibreRecaudacion)) {

						agregarRecaudacion(recaudacion, espacioLibreRecaudacion,
								&asignoIdRecaudacion, IdContribuyenteValidado);
					} else {
						printf(
								"No hay espacio disponible, elimine alguna Recaudacion");
					}
				}
				break;
			case 5:
				refinanciarRecaudacion(recaudacion, QTYRECAUDACIONES,contribuyente, QTYCONTRIBUYENTES);
				break;
			case 6:
				saldarRecaudacion(recaudacion, QTYRECAUDACIONES, contribuyente,QTYCONTRIBUYENTES);
				break;
			case 7:
				imprimirContribuyentes(contribuyente, QTYCONTRIBUYENTES,recaudacion, QTYRECAUDACIONES);
				break;
			case 8:
				imprimirRecaudacion(recaudacion, QTYRECAUDACIONES,contribuyente, QTYCONTRIBUYENTES);

				break;
			case 9:
				recaudacionesSuperiores(recaudacion, QTYRECAUDACIONES,contribuyente, QTYCONTRIBUYENTES);
				abonofebrero(recaudacion, QTYRECAUDACIONES, contribuyente,QTYCONTRIBUYENTES);
				break;

			case 10:
				printf(" Saliendo ....");
				break;

			} //fin llave switch

		} //FIN LLAVE VALIDACION MENU

	} while (opcionMenu != 10);

	return EXIT_SUCCESS;
} //llave final main

