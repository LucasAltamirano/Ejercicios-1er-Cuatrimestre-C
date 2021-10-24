/*
 * Libros.h
 *
 *  Created on: 27 jun. 2021
 *      Author: Lucas
 */

#ifndef LIBROS_H_
#define LIBROS_H_
typedef struct
{



}eEditoriales;





typedef struct
{
    int id;
    char titulo[120];
    char autor[25];
    int precio;
    int editorialId;
}eLibro;

eLibro* libro_new();
eLibro* Libros_newParametros(char* idChar,char* tituloStr,char* autorStr,char* precio,char* editorial);

int libros_setId(eLibro* this,int id);

int libros_setTitulos(eLibro* this,char* titulo);

int libros_setAutor(eLibro* this,char* autor);

int libros_setPrecio(eLibro* this,int precio);

int libros_setEditorial(eLibro* this,int idEditorial);

int libros_getId(eLibro* this,int* id);

int libros_GetTitulos(eLibro* this , char* titulo);

int libros_GetAutor(eLibro* this , char* autor);

int libros_GetPrecio(eLibro* this,int* precio);

int libros_GetIdEditorial(eLibro* this,int* idEditorial);

int ordenarporAutor(void* entidad1,void* entidad2);

int aplicoDescuento(void* element);

#endif /* LIBROS_H_ */
