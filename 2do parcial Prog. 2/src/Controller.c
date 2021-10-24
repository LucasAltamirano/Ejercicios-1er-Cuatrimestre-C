#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Libros.h"
#include "parser.h"
#include "Genericas.h"

/** \brief Carga los datos de los empleados desde el archivo ingresado por el usuario (modo texto).
 *
 * \param pArrayListaLibros LinkedList*
 * \return int
 *
 */
int controller_loadFromText(LinkedList *pArrayListaLibros) {
	int E = 0;
	char archivo[25];
	ll_clear(pArrayListaLibros);

	FILE *punteroFileTexto;


	levantaArchivos(archivo, "Ingrese nombre de archivo (Datos.csv)", "Error,Verifique", 25);
	punteroFileTexto = fopen(archivo, "r");

	if (punteroFileTexto != NULL) {


		parser_LibrosFromText(punteroFileTexto, pArrayListaLibros);

		fclose(punteroFileTexto);
		E = 1;

	}
	return E;
}
/** \brief Ordena los  libros
 *
 * \param path char*
 * \param pArrayListaLibros LinkedList*
 * \return int
 *
 */
int controller_sortLibros(LinkedList *pArrayListaLibros) {
	int E=0;

	if(pArrayListaLibros!=NULL){

		if(!ll_sort(pArrayListaLibros, ordenarporAutor,1)){
			E=1;
		}
				//if(negado cunado devuelve cero;
	}

		return E;
	}
/** \brief Listar la lista de libros que recibe
 *
 * \param pArrayListaLibros LinkedList*
 * \return int
 *
 */
int controller_ListLibros(LinkedList *pArrayListaLibros){
	int E=0;
	int largoDeLista;
	int i;
	// auxiliares impresiones
	int imprId;
	char imprTitulo[128];
	char imprAutor[128];
	int imprPrecio;
	char imprEditorial[128];

	int idConvertir;

	if(pArrayListaLibros!=NULL){

		largoDeLista=ll_len(pArrayListaLibros);
		if(largoDeLista>0){
			E=1;
printf(
			"\n\t        |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"
						"\t	||||                      Mi Bibilioteca                           ||||\n"
						"\t	|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
			printf("\n|%s|%50s |%16s | %s |%18s |","ID"," TITULO  "
					"                    "," AUTOR     "," PRECIO ","EDITORIAL    ");
			for (i = 0; i < largoDeLista; i++) {
							eLibro* auxPrintLibros = ll_get(pArrayListaLibros, i);

							libros_getId(auxPrintLibros,& imprId);
							libros_GetTitulos(auxPrintLibros, imprTitulo);
							libros_GetAutor(auxPrintLibros, imprAutor);
							libros_GetPrecio(auxPrintLibros, &imprPrecio);
							libros_GetIdEditorial(auxPrintLibros, &idConvertir);
							convertidorDeEnteroaChar(idConvertir, imprEditorial);
							printf("\n|%2d|%50s |%16s | %8d |%18s |",imprId,imprTitulo,imprAutor,imprPrecio,imprEditorial);
				}
		}
	}
	return E;
}
/** \brief Guarda los datos de los libros en el archivo mapeado.csv (modo texto).el cual es harcodeado.
 * abriendolo en modo w , para porteriormente cerrar dicho archivo
 *
 * \param path char*
 * \param pArrayListaLibros LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListaLibros) {

		FILE *punteroFileTexto;
		eLibro *punteroBuffer;
		int cantNodos;
		int i;
		int bufferId;
		char bufferTitulo[128];
		char bufferAutor[128];
		int bufferPrecio;
		int bufferidEditorial;
		char auxDescripcion[128];

		int E = 0;

		punteroFileTexto = fopen(path, "w");
		cantNodos = ll_len(pArrayListaLibros);

		if (punteroFileTexto != NULL
				&& cantNodos > 0&& pArrayListaLibros!=NULL && path!=NULL) {
			E = 1;
			fprintf(punteroFileTexto, "Id,Titulo,Autor,Precio,IdEditorial\n");
			for (i = 0; i < cantNodos; i++) {

				punteroBuffer = ll_get(pArrayListaLibros, i);

				libros_getId(punteroBuffer, &bufferId);
				libros_GetTitulos(punteroBuffer, bufferTitulo);
				libros_GetAutor(punteroBuffer, bufferAutor);
				libros_GetPrecio(punteroBuffer,&bufferPrecio);
				libros_GetIdEditorial(punteroBuffer,&bufferidEditorial);
				convertidorDeEnteroaChar(bufferidEditorial,auxDescripcion);

				fprintf(punteroFileTexto,"%d,%s,%s,%d,%s\n",bufferId,bufferTitulo,bufferAutor,bufferPrecio,auxDescripcion);

			}
			fclose(punteroFileTexto);
		}
		return E;
	}
/** \brief crea una nueva copia los datos de los libros en el archivo mapeado.csv (modo texto).
 * con los descuentos splicados segun las indicaciones del cliente
 * abriendolo en modo w , para porteriormente cerrar dicho archivo
 *
 * \param path char*
 * \param pArrayListaLibros LinkedList*
 * \return int
 *
 */
int controller_llmap(LinkedList* pArrayListaLibros){
	int E=0;
	LinkedList* devolucionMap;
	if(pArrayListaLibros!=NULL){

		devolucionMap=ll_map(pArrayListaLibros, aplicoDescuento);
		controller_saveAsText("mapeado.csv", devolucionMap);
		E=1;
	}
		free(devolucionMap);

	return E;
}

/** \brief Alta de empleados
 *
 * \param
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addLibro(LinkedList *pArrayListaLibros) {
	int E;
	eLibro *pLibro;
	eLibro *dmUltimoLibro;
	int longitud;
	int retornoId;
	int idMayor=0;
	int i;
	char auxTitulo[128] = " ";
	char auxAutor[128] = " ";
	int auxPrecio = 0;
	int auxIdEditorial=0;


	if (pArrayListaLibros != NULL) {

		pLibro = libro_new();
		if (pLibro != NULL) {
			E=1;
			longitud = ll_len(pArrayListaLibros);

			for (i = 0; i < longitud; i++) {

				dmUltimoLibro = ll_get(pArrayListaLibros, i);
				libros_getId(dmUltimoLibro, &retornoId);
				if (i == 0 || retornoId > idMayor) {

					idMayor = retornoId;
				}
			}
			idMayor++;
			libros_setId(pLibro, idMayor);

			utn_levantaCadenaCaracteres(auxTitulo,
					"Ingrese Titulo del nuevo libro", "#Error,verifique",128);
			libros_setTitulos(pLibro, auxTitulo);

			utn_levantaCadenaCaracteres(auxAutor,
					"Ingrese Autor del nuevo libro", "#Error,verifique",128);
			libros_setAutor(pLibro, auxAutor);


			levantaEnteros(&auxPrecio,
					"Ingrese precio del nuevo libro",
					"#Error,verifique", 1, 100000);
			libros_setPrecio(pLibro, auxPrecio);

			levantaEnteros(&auxIdEditorial, "Ingrese el id de la Editorial correspondiente al nuevo libro\n"
					"|1|-PLANETA\n"
					"|2|-SIGLO XXI EDITORES\n"
					"|3|-PEARSON\n"
					"|4|-MINOTAURO\n"
					"|5|-SALAMANDRA\n"
					"|6|-PENGUIN BOOKS\n",
					"#Opcion invalida veriifique,verifique", 1, 6);
			libros_setEditorial(pLibro, auxIdEditorial);
			ll_add(pArrayListaLibros, (eLibro*) pLibro);
		}
	}

	return E;
}

int controller_editEmployee(LinkedList *pArrayListaLibros) {

	eLibro *auxModificacionLibro;
	int E;
	int cantidadNodos;
	int i;
	int cantidadId;

	char auxModTitulo[128];
	int auxModAutor[25];
	int auxSueldoModificacion;

	int idReferencia;
	int idModificar;
	int flagIdCoincide = 0;
	int datomodificar;

	int confirma;

	if (pArrayListaLibros == NULL) {

		printf("#Error,verifique nuevamente");
		system("pause");
	} else {

		cantidadNodos = ll_len(pArrayListaLibros);

		for (i = 0; i < cantidadNodos; i++) {

			auxModificacionLibro = ll_get(pArrayListaLibros, i);
			employee_getId(auxModificacionLibro, &cantidadId);
			if (i == 0 || cantidadId > idReferencia) {

				idReferencia = cantidadId;
			}
		}
		printf("|||Modificacion de libro por Id|||\n");
		levantaEnteros(&idModificar, "Ingrese el Id que desea Modificar",
				"ingrese un id valido", 1, idReferencia);

		if (pArrayListaLibros != NULL && cantidadNodos > 0&& idModificar > 0) {
				E=1;
			for (i = 0; i < cantidadNodos; i++) {
				auxModificacionLibro = ll_get(pArrayListaLibros, i);
				if ((*auxModificacionLibro).id == idModificar) {
					flagIdCoincide = 1;
					break;
				}

			}
		}
		if (flagIdCoincide != 1) {
			printf("#Error,Id inexistente verifique\n");
		} else {

			printf(
						"\n\t        |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"
									"\t	||||                      Mi Bibilioteca                           ||||\n"
									"\t	|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
						printf("\n|%s|%50s |%16s | %s |%18s |","ID"," TITULO  "
								"                    "," AUTOR     "," PRECIO ","EDITORIAL    ");

						//printf("\n|%2d|%50s |%16s | %8d |%18s |"
		//	printf(" %-15d%-13s%-17d%-17d\n", (*auxModificacionLibro).id,
				/*	(*auxModificacionLibro).nombre,
					(*auxModificacionLibro).horasTrabajadas,
					(*auxModificacionLibro).sueldo);
*/
			levantaEnteros(&datomodificar,
					"Ingrese el campo que desea modificar\n"
							"|1|Titulo\n"
							"|2|Autor\n"
							"|3|Precio\n"
							"|4|Editorial\n"
							"|5|Cancelar modificacion de datos\n",
					"#Error,ingrese opcion valida", 1, 5);

			switch (datomodificar) {
			case 1:
				utn_levantaCadenaCaracteres(auxModTitulo,"Ingrese el titulo a modificar ", "#Error,verifique", 128);
				printf("Titulo Ingresado:%s\n",auxModTitulo);
				levantaEnteros(&confirma,"Desea guardar los cambios?\n"
						"|1|Aceptar\n"
						"|2|Cancelar\n", "#Error,ingrese opcion valida", 1, 2);
				if(employee_setNombre(auxModificacionLibro,
						auxModTitulo))
				{printRecuadro("Datos guardados Exitosamente!\n");
				}else{
					printRecuadro("Cancelado por el usuario\n");
							system("pause");

				}
				break;
			case 2:

				utn_levantaCadenaCaracteres(auxModAutor, "Ingrese el autor a modificar ", "#Error,verifique", 25);
				printf("autor Ingresado:%s\n",auxModAutor);



				break;

			case 2:
				levantaEnteros(&auxHsTrabajada/sModificacion,
						"Ingrese Horas trabajadas del nuevo empleado",
						"#Error,verifique", 1, 500);
				printf("Hs trabajadas Ingresadas:%d\n",auxHsTrabajadasModificacion);
				levantaEnteros(&confirma,"Desea guardar los cambios?\n"
										"|1|Aceptar\n"
										"|2|Cancelar\n", "#Error,ingrese opcion valida", 1, 2);
				if(employee_setHorasTrabajadas(auxModificacionLibro,
						auxHsTrabajadasModificacion)){
					printRecuadro("Datos guardados Exitosamente!\n");
									}else{
										printRecuadro("Cancelado por el usuario\n");
												system("pause");
				}
				break;
			case 3:
				levantaEnteros(&auxSueldoModificacion,
						"Ingrese sueldo del nuevo empleado", "#Error,verifique",
						1000, 500000);
				printf("nuevo sueldo Ingresado:%d\n",auxSueldoModificacion);
				levantaEnteros(&confirma,"Desea guardar los cambios?\n"
														"|1|Aceptar\n"
														"|2|Cancelar\n", "#Error,ingrese opcion valida", 1, 2);

				if(employee_setSueldo(auxModificacionLibro,
						auxSueldoModificacion)){
					printRecuadro("Datos guardados Exitosamente!\n");
				}else{
					printRecuadro("Cancelado por el usuario\n");
							system("pause");
				}

				break;
			case 4:

				break;
			case 5:
				printf("Modificacion de datos cancelado por el usuario\n");
				system("pause");
				break;

			}
		}
	}
	return E;
}

