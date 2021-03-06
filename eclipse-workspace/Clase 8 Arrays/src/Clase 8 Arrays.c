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

// parametros
void limpiarArrayEntero(int array[],int lengArray);
void limpiarArrayFloat(float array[],int lengArray);
void limpiarArrayChar(char array[],int lengArray);
void limparArrayString(char array[][20],int lengArray);

#define MAX 5

int main(void)
{
	setbuf(stdout,NULL);

	int legajoIngresado[MAX];
	char sexoIngresado[MAX];
	int edadesAlumnos[MAX];
	int primerNotaIngresada[MAX];
	int segundaNotaIngresada[MAX];
	float promedioNotas[MAX];
	char apellidosIngresados[MAX][20];


	//Inicializo todos los arrays
	limpiarArrayChar(sexoIngresado,MAX);
	limpiarArrayEntero(legajoIngresado,MAX);
	limpiarArrayEntero(edadesAlumnos,MAX);
	limpiarArrayEntero(primerNotaIngresada,MAX);
	limpiarArrayEntero(segundaNotaIngresada,MAX);
	limpiarArrayFloat(promedioNotas,MAX);
	limparArrayString(apellidosIngresados,MAX);



	return EXIT_SUCCESS;
}

void limpiarArrayEntero(int array[],int lengArray)
{
	int i;
	for (i = 0; i < lengArray; i++)
	{
		array[i] = 0;
	}
}//FIN limpiarArrayEntero()
void limpiarArrayFloat(float array[],int lengArray)
{
	int i;
	for (i = 0; i < lengArray;i++)
	{
		array[i] = 0;
	}
}//FIN limpiarArrayFloat()
void limpiarArrayChar(char array[],int lengArray)
{
	int i;
	for (i = 0; i < lengArray; i++)
	{
		array[i] = ' ';
	}
}//FIN limpiarArraychar()
void limparArrayString(char array[][20],int lengArray)
{
	int i;
	for (i = 0; i < lengArray; i++)
	{
		strcpy(array[i]," ");

	}
}


