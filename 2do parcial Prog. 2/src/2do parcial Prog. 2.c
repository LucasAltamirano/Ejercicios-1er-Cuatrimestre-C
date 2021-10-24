/*
 ============================================================================
 Name        : .c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Genericas.h"
#include "Controller.h"
#include "parser.h"
#include "Libros.h"

#define TEXTO  "Datos.csv"

int main(void) {

	setbuf(stdout,NULL);
	int opcion;
	int flagSeguimiento;

		opcion=0;
		flagSeguimiento=0;
	LinkedList* listaLibros= ll_newLinkedList();

	if(listaLibros!=NULL){

	do {

		DesplegarMenu(&opcion);

		switch(opcion){

		case 1:

			if(controller_loadFromText(listaLibros)){
				printMensaje("carga Exitosa\n");
				flagSeguimiento=1;
			}else{
				printMensaje("carga fallo\n");
			}
			break;

		case 2:
				controller_addLibro(listaLibros);
					break;
		case 3:

					break;
		case 4:

					break;
		case 5:
			if(flagSeguimiento==1){
				if(controller_sortLibros(listaLibros)){
								printMensaje("Ordenamiento Exitoso\n");
							}else{
								printMensaje("Ordenamiento Fallo,verifique\n");
							}
			}else{
				printMensaje("Nada para ordenar\n");
			}

			break;

		case 6:
			if(flagSeguimiento==1){
			if(!controller_ListLibros(listaLibros)){
				system("pause");
			}
			}else{
				printMensaje("Nada para listar\n");
			}
			break;
		case 7:

			if(flagSeguimiento==1){

			if(controller_llmap(listaLibros)){
				printMensaje("Descuentos aplicados y guardado en \"mapeado.csv\"\n");
			}else{
				printMensaje("Error,verifique\n");
			}
			}else{
				printMensaje("Nada para mappear\n");
			}
			break;
		}


	}while (opcion != 8);

 }
	printMensaje("Saliendo del sistema..\n");
			ll_deleteLinkedList(listaLibros);

	return 0;
}
