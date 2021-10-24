/*
 ============================================================================
 Name        : Clase.c
 Author      : Lucas Altamirano
 Ejercicio 7-1:Pedirle al usuario su nombre y apellido (en variables separadas, una para el nombre y otra para el apellido).
 Ninguna de las dos variables se puede modificar.
 Debemos lograr guardar en una tercer variable el apellido y el nombre con el siguiente formato:Por ejemplo:
  Si el nombre es juan ignacio y el apellido es gOmEz, la salida debería ser:Gomez, Juan Ignacio


 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	setbuf(stdout,NULL);
	char nombre[15];
	char apellido[15];
	char pruebagets[22];
	char fgetsprueba[10];
	char funcionAtoi[50];
	int charpasadoaINT;
	int sumafinal;

	printf("ingrese su nombre");
	scanf("%s",nombre);

	printf("ingrese su apellido");
	fflush(stdin);
	scanf("%s",apellido);
strcat(nombre," ");
strcat(nombre,apellido);
	printf("texto a mostrar  %s \n",nombre);

	printf("ingrese prueba de gets");
	fflush(stdin);
	gets(pruebagets);
	printf("texto a preuba gets  %s \n",pruebagets);


	printf("vamos a probar la funcion fgets ");
	fgets(fgetsprueba,50,stdin);
	printf("LA PRUEBA DE LA FUNCION F GETS  %s ",fgetsprueba);

	printf("vamos a probar la funcion atoi para convertir el tipo char , a tipo int  ");

	fgets(funcionAtoi,50,stdin);

	charpasadoaINT=atoi(funcionAtoi);
	sumafinal=charpasadoaINT+ 5;

	printf("texto a preuba gets  %d \n",charpasadoaINT);
	sumafinal=charpasadoaINT+ 5;
	printf("suma final aes  a preuba gets  %d \n",sumafinal);


		printf("resultado final   %s %s ",apellido,nombre);


	return EXIT_SUCCESS;
}
