/*
 ============================================================================
 Name        : Clase.c
 Author      : Lucas Altamirano
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Genericas.h"

#define ORQUESTAS 3
#define MUSICOS 3
#define INSTRUMENTOS 3
#define REINTENTOS 3
typedef struct{

	int idTipoOrquesta;
	char tipoOrquesta;
	int isEmpty;

}eTipoOrquesta;

typedef struct{

	int IdOrquesta;
	char nombreOrquesta[20];
	char lugarOrgquesta[20];
	int idTipoORquesta;
	int isEmpty;

}eOrquesta;

typedef struct{
	int idOrquesta;
	char nomnbre[20];
	char apellido[20];
	int edad;

	int idInstrumento;
	int isEmpty;

}eMusico;

typedef struct{
	int idMusico;
	char nomnbre[20];
	int idTipoInstrumento;
	int isEmpty;

}eInstrumentos;

typedef struct{
	int idTipoInstrumento;
	char descripcion[20];
	int isEmpty;

}eTipoInstrumento;

//funciones
void desplegarMenu(void);
int inicializarStructOrquesta(eOrquesta estructurasRecibidas[],int limiteStruct);
int inicializarStructInstrumento(eInstrumentos estructurasRecibidas[],int limiteStruct);
int inicializarStructMusico(eMusico estructurasRecibidas[],int limiteStruct);


int main(void) {

	setbuf (stdout,NULL);

	eOrquesta orquestas[ORQUESTAS];
	eTipoOrquesta tipoOrquesta[3]={{1,"Sinfonica",0},{2,"Filarmonica",0},{3,"Camara"},0};
	eMusico musicos [MUSICOS];
	eInstrumentos instrumentos[INSTRUMENTOS];
	eTipoInstrumento tipoIntrumentos[4]={{1,"Cuerdas",0},{2,"Viento-madera",0},{3,"Viento-metal",0},{4,"Percusion",0}};

	 int idOrquesta=0;
	 int idMusico=0;
	 int idInstrumentos=0;
	 int opcionMenu;
	 int posLibre;
	 int asignagcionId=1000;

	inicializarStructOrquesta(orquestas, ORQUESTAS);
	inicializarStructMusico(musicos, MUSICOS);
	inicializarStructInstrumento(instrumentos,INSTRUMENTOS);

	do{
		desplegarMenu()
	if(levantaEnteros(&opcionMenu,"Ingrese una Opcion", "#Error, ingrese una opcion valida", 1, 9, REINTENTOS)){

			switch(opcionMenu)
			{
			case 1:
				posLibre=buscarLibreOrquesta(orquestas,ORQUESTAS);
					if(posLibre!=-1)
					{
						if(cargaDatosOrquesta(orquestas,posLibre))
						{
							orquestas[posLibre].idOrquesta=idOrquestas;
							idOrquestas++;
							printf("Pulse cualquiera tecla para volver\n");
							fflush(stdin);
							getchar();
						}
						else
						{
							printf("Algo fallo en la carga de datos\n");
							printf("Pulse cualquiera tecla para volver\n");
							fflush(stdin);
							getchar();
						}
					}
					else
					{
						printf("No hay lugar disponible, elimine al menos uno\n");
						printf("Pulse cualquiera tecla para volver\n");
						fflush(stdin);
						getchar();
					}



					break;
				case 2:

					break;
				case 3:

					break;
				case 4:

				break;
				case 5:
					break;
				case 6:
					break;
				case 7:
					break;
				case 8:
					break;
				case 9:
					break;
				default:
					printf("saliendo...");
				break;




			}
	}

	}while(opcionMenu!=9);






	return EXIT_SUCCESS;
}
int inicializarStructOrquesta(eOrquesta estructurasRecibidas[],int limiteStruct){

	int i;
	int retorno;
	retorno=-1;
	if(estructurasRecibidas!=NULL){
		for(i=0;i<limiteStruct;i++){
			estructurasRecibidas[i].isEmpty=1;
		}
		retorno =0;
	}
	return retorno;
}
int inicializarStructMusico(eMusico estructurasRecibidas[],int limiteStruct){

	int i;
	int retorno;
	retorno=-1;
	if(estructurasRecibidas!=NULL){
		for(i=0;i<limiteStruct;i++){
			estructurasRecibidas[i].isEmpty=1;
		}
		retorno =0;
	}
	return retorno;
}
int inicializarStructInstrumento(eInstrumentos estructurasRecibidas[],int limiteStruct){

	int i;
	int retorno;
	retorno=-1;
	if(estructurasRecibidas!=NULL){
		for(i=0;i<limiteStruct;i++){
			estructurasRecibidas[i].isEmpty=1;
		}
		retorno =0;
	}
	return retorno;
}

int cargarStruct(eOrquesta estructurasRecibidas[],int espacioLibre){

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

		PromedioAlumno(estructurasRecibidas,espacioLibre);
		estructurasRecibidas[espacioLibre].estaVacio=0;
		retorno=0;
	}//final If


	return retorno;
}
void desplegarMenu(void){
	printf ("BIENVENIDOS AL MENU PRINCIPAL\n"
			"1-Agregar Orquesta\n"
			"2-Eliminar Orquesta:\n"
			"3-Imprimir Orquestas\n"
			"4-Agregar Músico:\n"
			"5-Modificar Músico\n"
			"6-Eliminar Músico\n"
			"7-Imprimir Músicos\n"
			"8-Agregar Instrumento\n"
			"9-Salir\n");
}
