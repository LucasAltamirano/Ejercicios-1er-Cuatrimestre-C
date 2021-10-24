/*
 ============================================================================
 Name        : proyecto.c
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
#define CANTIDAD 5
#define REINTENTOS 2
typedef  struct {
	int legajo;
	char sexo;
	int edad;
	int notaUno;
	int notaDos;
	float promedio;
	char apellido[20];
	int estaVacio;
}eAlumnos;


//prototipos funciones
int inicializarStruct(eAlumnos estructurasRecibidas[],int limiteStruct);
void desplegarMenu();
int getInt(int* pResultado,char* mensaje,char*  mensajeError,int min,int max,int reintentos);
int buscarIsEmpty(eAlumnos estructurasRecibidas[],int limiteStruct );
void PromedioAlumno(eAlumnos estructurasRecibidas[],int espacioLibre);
int cargarStruct(eAlumnos estructurasRecibidas[],int espacioLibre);
void listarEstructuraEntera(eAlumnos estructurasRecibidas[],int limiteStruct);
void listarEnSingular(eAlumnos estructuraRecibida);
void bajaEstructura(eAlumnos estructurasRecibidas[], int limiteStruct);
void modificarEstructura(eAlumnos estructurasRecibidas[], int limiteStruct);





int main(void)
{
	setbuf(stdout,NULL);

		eAlumnos alumnos[CANTIDAD];
		int opcionMenu;
		int posicionLibre;
		int AsignacionLegajo;
		AsignacionLegajo=1000;


	inicializarStruct(alumnos, CANTIDAD);
	do{
	desplegarMenu();
	getInt(&opcionMenu, "Ingrese una opcion "," #Error,Ingrese una opcion valida", 1, 6, REINTENTOS);

	switch(opcionMenu){

		case 1:
			posicionLibre=buscarIsEmpty(alumnos,CANTIDAD);
			if(posicionLibre!=-1){
				cargarStruct(alumnos, posicionLibre);
				alumnos[posicionLibre].legajo=AsignacionLegajo;
				AsignacionLegajo++;
				printf("Alta registrada con exito\n");
				printf("Pulse cualquiera tecla para volver\n");
				fflush(stdin);
				getchar();
			}else{
				printf("No hay posiciones libres para cargar Alumnos, debera eliminar una posicion\n");
				printf("Pulse cualquiera tecla para volver\n");
				fflush(stdin);
				getchar();
			}

		break;
		case 2:
			listarEstructuraEntera(alumnos, CANTIDAD);

		break;
		case 3:
			bajaEstructura(alumnos, CANTIDAD);
		break;
		case 4:
			modificarEstructura(alumnos, CANTIDAD);

		break;
		case 5:
		break;
		default:
			printf("saliendo...");
		break;


	}//Fin switch Menu principal
	} while (opcionMenu!=6);


return EXIT_SUCCESS;
}




// desarrollo de funciones


int inicializarStruct(eAlumnos estructurasRecibidas[],int limiteStruct){

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
void desplegarMenu(void)
{
	printf ("BIENVENIDOS AL MENU PRINCIPAL\n"
	"1-Alta de alumno\n"
	"2-Listar alumno\n"
	"3-Baja alumno\n"
	"4-Modificar\n"
	"5-Ordenar\n"
	"6-Salir\n");
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

int buscarIsEmpty(eAlumnos estructurasRecibidas[],int limiteStruct ){

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
int cargarStruct(eAlumnos estructurasRecibidas[],int espacioLibre){

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
void PromedioAlumno(eAlumnos estructurasRecibidas[],int espacioLibre){

	float notaUnoFuncion;
	float notaDosFuncion;
	float promedioFuncion;

	notaUnoFuncion=estructurasRecibidas[espacioLibre].notaUno;
	notaDosFuncion=estructurasRecibidas[espacioLibre].notaDos;

	promedioFuncion=((notaUnoFuncion+notaDosFuncion)/2);
	estructurasRecibidas[espacioLibre].promedio=promedioFuncion;
}

void listarEstructuraEntera(eAlumnos estructurasRecibidas[],int limiteStruct){
	int mostrarUnaVez=-1;
	int i;
	for(i=0;i<limiteStruct;i++){
		if(estructurasRecibidas[i].estaVacio==0){
			if(mostrarUnaVez==-1){
				printf("Legajo   Sexo      Edad     Nota 1     Nota 2    Promedio  Apellido\n");
				mostrarUnaVez=0;
			}
			listarEnSingular(estructurasRecibidas[i]); // observar la diferencia entre Estructuras y estructura que llame mi funcon listar alumno
		}
	}
	if(mostrarUnaVez==-1){
		printf("No existen datos en el sistema\n");
	}
	printf("Pulse cualquiera tecla para volver\n");
	fflush(stdin);
	getchar();
}//FIN.funcion listasAlumnos
void listarEnSingular(eAlumnos estructuraRecibida){


	printf("%-10d%-10c%-10d%-10d%-10d%-10.2f%s",estructuraRecibida.legajo,estructuraRecibida.sexo,estructuraRecibida.edad,estructuraRecibida.notaUno,estructuraRecibida.notaDos,estructuraRecibida.promedio,estructuraRecibida.apellido);

}

void bajaEstructura(eAlumnos estructurasRecibidas[], int limiteStruct){

	int legajoBaja;
	int i;
	int flagLegajoExistente=-1;
	int confirmaBaja;
	if(estructurasRecibidas!=NULL){
	printf(" Ingrese el numero de Legajo que desea dar de baja");
	fflush(stdin);
	scanf("%d",&legajoBaja);

	for(i=0;i<limiteStruct;i++){
	if(legajoBaja==estructurasRecibidas[i].legajo&&estructurasRecibidas[i].estaVacio==0){
			flagLegajoExistente=0;
			break;
		}
	}
	if(flagLegajoExistente ==0){
		printf("Se dara de baja el legajo %d,presione 1 para continuar o 0 para cancelar\n",legajoBaja);

		listarEnSingular(estructurasRecibidas[i]);
		fflush(stdin);
		scanf("%d",&confirmaBaja);
		while(confirmaBaja !=0 && confirmaBaja!=1){
			printf("Ingrese una opcion valida,presione 1 para continuar o 0 para cancelar\n");
			fflush(stdin);
			scanf("%d",&confirmaBaja);
		}
		if(confirmaBaja==1){
			estructurasRecibidas[i].estaVacio=1;
			printf("Legajo fue dado de baja ,de manera exitosa\n");
			printf("Pulse cualquiera tecla para volver\n");
			fflush(stdin);
			getchar();
		}else{
			printf("Baja de legajo cancelado por el usuario\n");
			printf("Pulse cualquiera tecla para volver\n");
			fflush(stdin);
			getchar();

		}
		}
	}else{
		printf("Legajo inexistente/invalido \n");
		printf("Pulse cualquiera tecla para volver\n");
		fflush(stdin);
		getchar();
	}

	}

	void modificarEstructura(eAlumnos estructurasRecibidas[], int limiteStruct)
	{

			int legajoModificar;
			int legajoExistente=0;
			int campoModificar;
			int i;

			printf("Bienvenido a Menu Modificar\n");
			printf("Ingrese legajo a modificar\n");
			scanf("%d",&legajoModificar);
			for(i=0;i<limiteStruct;i++)
			{
				if(legajoModificar==estructurasRecibidas[i].legajo&&estructurasRecibidas[i].estaVacio==0)
				{
					legajoExistente=1;
					break;
				}
			}
			if(legajoExistente)
			{
				printf("¿Que campo desea modificar?\n");
				printf("sexo=1\nedad=2\nnotaUno=3\nnotaDos=4\npromedio=5\napellido=6\n");
				scanf("%d",&campoModificar);
				while(campoModificar<1||campoModificar>6)
				{
					printf("ERROR,CAMPO INVALIDO ¿Que campo desea modificar?\n");
					printf("sexo=1\nedad=2\nnotaUno=3\nnotaDos=4\napellido=5\n");
					scanf("%d",&campoModificar);
				}
				switch(campoModificar)
				{
					case 1:
						printf("Reingrese sexo\n");
						fflush(stdin);
						scanf("%c",&estructurasRecibidas[i].sexo);
					break;
					case 2:
						printf("Reingrese edad\n");
						scanf("%d",&estructurasRecibidas[i].edad);
					break;
					case 3:
						printf("Reingrese nota Uno\n");
						scanf("%d",&estructurasRecibidas[i].notaUno);
						PromedioAlumno(estructurasRecibidas,i);
					break;
					case 4:
						printf("Reingrese nota Dos\n");
						scanf("%d",&estructurasRecibidas[i].notaDos);
						PromedioAlumno(estructurasRecibidas,i);
					break;
					case 5:
						printf("Reingrese apellido\n");
						fflush(stdin);
						fgets (estructurasRecibidas[i].apellido,19,stdin);
					break;
				}
			}
			else
			{
				printf("ERROR,usted no ha ingresado legajo valido, verifique y reingrese\n");
				printf("Pulse cualquiera tecla para volver\n");
				fflush(stdin);
				getchar();
			}
		}

