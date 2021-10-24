/*
 ============================================================================
 Name        : Clase.c
 Author      : Lucas Altamirano
 Desarrollar un programa que permita guardar los datos de 5 alumnos.
 Los datos a guardar para cada alumno: legajo, sexo, edad, nota1,
  nota2, promedio, apellido.
 ============================================================================
 */
// bibiliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



// funciones
void cargarArrays(char mensaje[], char imput[]);

// constantes
#define CANT_ELEMENT 2
#define msj_nombre "Ingrese un nombre : "
#define msj_apellido "Ingrese un apellido : "

int main(void) {


	setbuf(stdout,NULL);

	int i;
	char elementos [CANT_ELEMENT][20];  // dos corchetes = Matriz;
	char apellido[CANT_ELEMENT][20];
	char auxNombre[20];
	char auxApellido[20];

	for(i=0;i<CANT_ELEMENT;i++){

	 cargarArrays(msj_nombre,auxNombre);
	 cargarArrays(msj_apellido,auxApellido);
	 strcpy(elementos[i],auxNombre);
	 strcpy(apellido[i],auxApellido);


	}

	for(i=0;i<CANT_ELEMENT;i++){

	printf("nombre:%s- apellido:%s\n",elementos[i],apellido[i]);
	}


 return 0;
}

void cargarArrays(char mensaje[], char imput[])
{
	printf("%s",mensaje);
	gets(imput);
}

