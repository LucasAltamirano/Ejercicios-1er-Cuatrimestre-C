/*
 * Libros.c
 *
 *  Created on: 27 jun. 2021
 *      Author: Lucas
 */

#include <stdio.h>
#include <stdlib.h>
#include "Genericas.h"

#include "Libros.h"
#include <string.h>

eLibro* libro_new(){
	eLibro* auxNuevo;
	auxNuevo= (eLibro*)malloc(sizeof(eLibro));
		return auxNuevo;
}
eLibro* Libros_newParametros(char* idChar,char* tituloStr,char* autorStr,char* precioStr,char* editorial){

	eLibro* aux;
	aux= (eLibro*)malloc(sizeof(eLibro));
	int idCarga=0;
	if(aux!=NULL){


		libros_setId(aux,atoi(idChar));

		libros_setTitulos(aux,tituloStr);

		libros_setAutor(aux,autorStr);

		libros_setPrecio(aux,atoi(precioStr));

		if(convertidorDeCharEntero(editorial,&idCarga)){

			libros_setEditorial(aux,idCarga);

		}else{
			printMensaje("Error en la carga de Editorial,verifique");
		}
	}
	return aux;
}

int libros_setId(eLibro* this,int id){
	int E=0;

	if(this!=NULL){
		E=1;
		this->id=id;
	}
	return E;
}

int libros_getId(eLibro* this,int* id){
	int E=0;
	if(this!=NULL&&id!=NULL){
		*id=(*this).id;
		E=1;
	}
	return E;
}

int libros_setTitulos(eLibro* this,char* titulo){
	int E=0;

	if(this !=NULL && titulo !=NULL){
		E=1;
		strcpy(this->titulo,titulo);
	}
	return E;
}

int libros_GetTitulos(eLibro* this , char* titulo){
	int E=0;
	if(this!=NULL && titulo!=NULL){

		strcpy(titulo,(*this).titulo);
	}
	return E;
}
int libros_setAutor(eLibro* this,char* autor){
	int E=0;

	if(this !=NULL && autor !=NULL){
		E=1;
		strcpy(this->autor,autor);
	}
	return E;
}
int libros_GetAutor(eLibro* this , char* autor){
	int E=0;
	if(this!=NULL && autor!=NULL){

		strcpy(autor,(*this).autor);
	}
	return E;
}
int libros_setPrecio(eLibro* this,int precio){
	int E=0;

	if(this!=NULL){
		E=1;
		this->precio=precio;
	}
	return E;
}

int libros_GetPrecio(eLibro* this,int* precio){
	int E=0;
	if(this!=NULL&& precio !=NULL){
		*precio=(*this).precio;
		E=1;
	}
	return  E;
}
int libros_setEditorial(eLibro* this,int idEntero){
	int E=0;

	if(this !=NULL && idEntero!=0){
		E=1;
		(*this).editorialId=idEntero;
	}
	return E;
}

int libros_GetIdEditorial(eLibro* this,int* idEditorial){
	int E=0;
	if(this!=NULL){
		*idEditorial=(*this).editorialId;
		E=1;
	}
	return  E;
}




int ordenarporAutor(void* entidad1,void* entidad2){

	int E=0;

	eLibro* auxEntidad1=entidad1;

	eLibro* auxEntidad2=entidad2;

	if(strcmp((*auxEntidad1).autor,(*auxEntidad2).autor)>0){
		E=1;
	}
	if(strcmp((*auxEntidad1).autor,(*auxEntidad2).autor)<0){
			E=-1;
		}
	return E;
}

		//int(*fn)(void* element)
int aplicoDescuento(void* element){
	int E=0;

	eLibro* auxLibroRecibido;
	int precioSD=0;


	if(element !=NULL){

		 auxLibroRecibido =element;
		 libros_GetPrecio(auxLibroRecibido, &precioSD);
		 if((*auxLibroRecibido).editorialId==1 && precioSD >= 300){


			libros_setPrecio(auxLibroRecibido, precioSD- (precioSD*.20));
			E=1;
		 }

		 if((*auxLibroRecibido).editorialId==2 && precioSD <= 200){

			 libros_setPrecio(auxLibroRecibido,  precioSD- (precioSD*.10));
			E=1;

		 }
	}
	return E;
}
