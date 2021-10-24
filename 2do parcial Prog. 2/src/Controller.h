/*
 * Controller.h
 *
 *  Created on: 27 jun. 2021
 *      Author: Lucas
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_


int controller_loadFromText(LinkedList *pArrayListaLibros);

int controller_sortLibros(LinkedList *pArrayListaLibros) ;

int controller_ListLibros(LinkedList *pArrayListaLibros);

int controller_llmap(LinkedList* pArrayListaLibros);

int controller_saveAsText(char *path, LinkedList *pArrayListaLibros);

int controller_addLibro(LinkedList *pArrayListaLibros);

#endif /* CONTROLLER_H_ */
