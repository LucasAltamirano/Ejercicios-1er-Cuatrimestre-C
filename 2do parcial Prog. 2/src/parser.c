#include <stdio.h>
#include <stdlib.h>
#include "Libros.h"
#include "LinkedList.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_LibrosFromText(FILE* pFile , LinkedList* pArrayListaLibros){
	eLibro* punteroLibros=NULL;
	int E=0;
	char buffer [5] [128];
	int contador=0;

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3),*(buffer+4));

	while(!feof(pFile)){

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3),*(buffer+4));

		punteroLibros=Libros_newParametros(*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3),*(buffer+4));

		if(punteroLibros!=NULL){
			E=1;
			ll_add(pArrayListaLibros,punteroLibros);
			contador++;
		}
	}

	printf("La lista de Libros cargada asciende a: %d Libros\n",contador);
    return E;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
