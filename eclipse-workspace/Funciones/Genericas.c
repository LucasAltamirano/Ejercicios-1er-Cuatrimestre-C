/*
 * Genericas.c
 *
 *  Created on: 9 may. 2021
 *      Author: Lucas
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Genericas.h"


int levantaEnteros(int* resultado,char* mensaje,char* mensajeError,int min,int max,int reintentos)
{
	int aux;
	int exito=1;
	int tipoValidado;

	if(resultado!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&min<=max&&reintentos>-1)
	{
		do{
			printf("%s\n",mensaje);
			fflush(stdin);
			tipoValidado=scanf("%d",&aux);
			if(aux<min||aux>max||tipoValidado==0)
			{
				printf("%s\n",mensajeError);
				reintentos--;
			}
			else
			{
				*resultado=aux;
				exito=0;
				break;
			}
		}while(reintentos>-1);
	}
	return exito;
}

int inicializarStruct( estructurasRecibidas[],int limiteStruct){

	int i;
	int retorno;
	retorno=-1;
	if(estructurasRecibidas!=NULL){
		for(i=0;i<limiteStruct;i++){
			estructurasRecibidas[i].estaVacio=1;
		}
		retorno =0;
	}
	return retorno;
}

int cargarStruct(struct estructurasRecibidas[],int espacioLibre){

	int retorno;
	char auxSexo;
	int auxEdad;
	int auxNotaUno;
	int auxNotaDos;
	char auxApellido[20];

	retorno=-1;
	if(estructurasRecibidas!=NULL){
		printf("Ingrese el sexo 'f' o 'm' \n");
		fflush(stdin);
		scanf("%c",&auxSexo);
		while(auxSexo!='f' && auxSexo!='m'){
			printf("#Error,Ingrese el sexo 'f' o 'm' \n");
			fflush(stdin);
			scanf("%c",&auxSexo);
		}
		estructurasRecibidas[espacioLibre].sexo=auxSexo;
		printf("Ingrese Edad\n");
		fflush(stdin);
		scanf("%d",&auxEdad);
		while(auxEdad<18 || auxEdad>90){
			printf("#Error,Ingrese una edad valida ,de 18 hasta 90 años de edad\n");
			fflush(stdin);
			scanf("%d",&auxEdad);
		}
		estructurasRecibidas[espacioLibre].edad=auxEdad;
		printf("Ingrese la primer nota\n");
		fflush(stdin);
		scanf("%d",&auxNotaUno);
		while(auxNotaUno<1 || auxNotaUno>10){
			printf("#Error,Ingrese una nota del 1 al 10\n");
			fflush(stdin);
			scanf("%d",&auxNotaUno);
		}
		estructurasRecibidas[espacioLibre].notaUno=auxNotaUno;
		printf("Ingrese la segunda nota\n");
		fflush(stdin);
		scanf("%d",&auxNotaDos);
		while(auxNotaDos<1 || auxNotaDos>10){
			printf("#Error,Ingrese una nota del 1 al 10\n");
			fflush(stdin);
			scanf("%d",&auxNotaDos);
		}
		estructurasRecibidas[espacioLibre].notaDos=auxNotaDos;
		printf("Ingrese el apellido\n");
		fflush(stdin);
		fgets(auxApellido,20,stdin);
		strncpy(estructurasRecibidas[espacioLibre].apellido,auxApellido,sizeof(estructurasRecibidas[espacioLibre].apellido));
}

	int buscarVacio(int estructurasRecibidas,int limiteStruct ){

		int i;
		int posicionLibre;
		posicionLibre=-1;

		if(estructurasRecibidas!=NULL){
			for(i=0;i<limiteStruct;i++){

				if(estructurasRecibidas[i].estaVacio==1){
					posicionLibre=i;
					break;// inmediatamente que se localiza un espacio vacio ,
				}//le asigno el mismo(i) a posicion libre y rompo el bloque
			}
		}
		return posicionLibre;
	}
