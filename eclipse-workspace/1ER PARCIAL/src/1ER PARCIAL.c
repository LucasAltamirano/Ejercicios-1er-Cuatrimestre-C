/*/*
 ============================================================================
 Name        : 1ER.c
 Author      : Lucas Altamirano
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

//define
#define REINTENTOS 2
#define CANTIDAD 3
typedef  struct {
	int	idContribuyente;
	int cuil;
	char apellido[20];
	char nombre[20];
	int estaVacio;
}eContribuyentes;

//prototipos
int inicializarStruct(eContribuyentes estructurasRecibidas[],int limiteStruct);
void desplegarMenu();
int getInt(int* pResultado,char* mensaje,char*  mensajeError,int min,int max,int reintentos);
int buscarIsEmpty(eContribuyentes estructurasRecibidas[],int limiteStruct );
int cargarStruct(eContribuyentes estructurasRecibidas[],int espacioLibre);
int utn_getString(char* arrayString, int limite,char* msg,char* msgError);
void modificarEstructura(eContribuyentes estructurasRecibidas[], int limiteStruct);

int main(void)
{
	setbuf(stdout,NULL);

		eContribuyentes contribuyentes[CANTIDAD];
		int opcionMenu;
		int posicionLibre;




	inicializarStruct(contribuyentes, CANTIDAD);
	do{
	desplegarMenu();
	getInt(&opcionMenu, "Ingrese una opcion "," #Error,Ingrese una opcion valida", 1, 6, REINTENTOS);

	switch(opcionMenu){

		case 1:
			posicionLibre=buscarIsEmpty(contribuyentes,CANTIDAD);
			if(posicionLibre!=-1){
				cargarStruct(contribuyentes, posicionLibre);


				printf("Alta registrada con exito\n");
				printf("Pulse cualquiera tecla para volver\n");
				fflush(stdin);
				getchar();
			}else{
				printf("No hay posiciones libres para cargar Contribuyentes, debera eliminar una posicion\n");
				printf("Pulse cualquiera tecla para volver\n");
				fflush(stdin);
				getchar();
			}

		break;
		case 2:
			 modificarEstructura(contribuyentes,CANTIDAD);

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

		default:
			printf("saliendo...");
		break;


	}//Fin switch Menu principal
	} while (opcionMenu!=6);


return EXIT_SUCCESS;
}


int inicializarStruct(eContribuyentes estructurasRecibidas[],int limiteStruct){

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


void desplegarMenu(void){
	printf ("BIENVENIDOS AL MENU PRINCIPAL\n"
			"1-Alta de Contribuyente:\n"
			"2-Modificar datos del contribuyente:\n"
			"3-Baja de contribuyente\n"
			"4-Recaudación:\n"
			"5-Refinanciar Recaudación\n"
			"6-Saldar Recaudación\n"
			"7-Imprimir Contribuyentes\n"
			"8-Imprimir Recaudación\n"
			"9-Salir\n");
}
int getInt(int* pResultado,char* mensaje,char* mensajeError,int min,int max,int reintentos)
{
	int aux;
	int exito=1;
	int tipoValidado;

	if(pResultado!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&min<=max&&reintentos>-1)
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
				*pResultado=aux;
				exito=0;
				break;
			}
		}while(reintentos>-1);
	}
	return exito;
}

int buscarIsEmpty(eContribuyentes estructurasRecibidas[],int limiteStruct ){

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
int cargarStruct(eContribuyentes estructurasRecibidas[],int espacioLibre){

	int retorno;
	char auxCuil[20];
	char auxNombre[20];
	char auxApellido[20];
	int auxIdcontribuyente;
	auxIdcontribuyente=1000;

	retorno=-1;
	if(estructurasRecibidas!=NULL){
		printf("Ingrese el Nombre\n");
				fflush(stdin);
				fgets(auxNombre,20,stdin);
				strncpy(estructurasRecibidas[espacioLibre].nombre,auxNombre,sizeof(estructurasRecibidas[espacioLibre].nombre));

		printf("Ingrese el apellido\n");
				fflush(stdin);
				fgets(auxApellido,20,stdin);
				strncpy(estructurasRecibidas[espacioLibre].apellido,auxApellido,sizeof(estructurasRecibidas[espacioLibre].apellido));

		utn_getString(auxCuil, 13, "Ingrese el cuil","#Error ingrese cuil correcto");

		estructurasRecibidas[espacioLibre].idContribuyente=auxIdcontribuyente;
		auxIdcontribuyente++;

		retorno=0;
	}//final If



	return retorno;
}

int utn_getString(char* arrayString, int limite,char* msg,char* msgError)
{
    int retorno=-1;
    printf(msg);
    char auxString[limite];
    fgets(auxString,limite,stdin);
    fflush(stdin);

    if (auxString!= NULL)
    {
        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        strncpy(arrayString,auxString,limite);
        retorno=0;
    }
    else
    {
        printf(msgError);
    }
    return retorno;

}
void modificarEstructura(eContribuyentes estructurasRecibidas[], int limiteStruct){
	{

			int idContribuyenteModificar;
			int legajoExistente=0;
			int campoModificar;
			int i;

			printf("Bienvenido a Menu Modificar\n");
			printf("Ingrese legajo a modificar\n");
			scanf("%d",&idContribuyenteModificar);
			for(i=0;i<limiteStruct;i++)
			{
				if(idContribuyenteModificar==estructurasRecibidas[i].idContribuyente&&estructurasRecibidas[i].estaVacio==0)
				{
					legajoExistente=1;
					break;
				}
			}
			if(legajoExistente==1)
			{
				printf("¿Que campo desea modificar?\n");
				printf("Nombre=1\n Apellido=2\n cuil=3\n");
				scanf("%d",&campoModificar);
				while(campoModificar<1||campoModificar>3)
				{
					printf("ERROR,CAMPO INVALIDO ¿Que campo desea modificar?\n");
					printf("Nombre=1\n Apellido=2\n cuil=3\n");
					scanf("%d",&campoModificar);
				}
				switch(campoModificar)
				{
					case 1:
						printf("Reingrese nombre\n");
						fflush(stdin);
						scanf("%c",estructurasRecibidas[i].nombre);
					break;
					case 2:
						printf("Reingrese apellido\n");
						scanf("%c",estructurasRecibidas[i].apellido);
					break;
					case 3:
						printf("Reingrese cuil\n");
						scanf("%d",&estructurasRecibidas[i].cuil);

					break;

				}
			}
			else
			{
				printf("ERROR,usted no ha ingresado iD CONTRIBUYENTE valido, verifique y reingrese\n");
				printf("Pulse cualquiera tecla para volver\n");
				fflush(stdin);
				getchar();
			}
		}

}
