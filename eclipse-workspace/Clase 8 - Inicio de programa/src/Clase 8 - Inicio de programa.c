/*
 ============================================================================
 Name        : Clase.c
 Author      : Lucas Altamirano

 Desarrollar un programa que permita guardar los datos de 5 alumnos.
 Los datos a guardar para cada alumno: legajo, sexo, edad, nota1,
  nota2, promedio, apellido.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//funciones
void limpiarArrayString(char array[][20],int limiteArrray);
void limpiarArrayEntero(int array[],int limiteArrray);
void limpiarArrayChar(char array[],int limiteArrray);
void limpiarArrayFloat(float array[],int lengArray);

//constantes
#define CANT_INGRESAR 5


int main(void) {
	setbuf(stdout,NULL);

	char apellido[CANT_INGRESAR][20];
	int legajoIngresado[CANT_INGRESAR];
	char sexoIngresado[CANT_INGRESAR];
	int edadIngresada[CANT_INGRESAR];
	int notaUno[CANT_INGRESAR];
	int notaDos[CANT_INGRESAR];
	float promedio[CANT_INGRESAR];

		// inicializo dandole un valor,asi saco la basura ram
	limpiarArrayString(apellido,CANT_INGRESAR);
	limpiarArrayEntero(legajoIngresado,CANT_INGRESAR);
	limpiarArrayChar(sexoIngresado,CANT_INGRESAR);
	limpiarArrayEntero(edadIngresada,CANT_INGRESAR);
	limpiarArrayEntero(notaUno,CANT_INGRESAR);
	limpiarArrayEntero(notaDos,CANT_INGRESAR);
	limpiarArrayFloat(promedio,CANT_INGRESAR);

		// INGRESO VALORES





	return EXIT_SUCCESS;
}


void limpiarArrayString(char array[][20],int limiteArrray){
	int i;

	for (i=0;i<limiteArrray;i++){

		strcpy(array[i]," ");
	}
}



void limpiarArrayChar(char array[],int limiteArrray){
	int i;

	for (i=0;i<limiteArrray;i++){

		array[i] = ' ';
	}
}//FIN ,funcion limpiarArrayChar

void limpiarArrayEntero(int array[],int limiteArrray ){
	int i;

		for (i=0;i<limiteArrray;i++){

			array[i] = 0;
		}
}// FIN:


void limpiarArrayFloat(float array[],int lengArray)
{
	int i;
	for (i = 0; i < lengArray;i++)
	{
		array[i] = 0;
	}
}//FIN limpiarArrayFloat()
