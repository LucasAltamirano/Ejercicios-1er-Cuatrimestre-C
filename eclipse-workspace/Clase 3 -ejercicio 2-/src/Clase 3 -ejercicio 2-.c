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

int Sumando(int a,int b);//prototipo
							/// los valores que le van a usarse en las  funciones ,
								///independientementte de las declaradas abajo,
						/// posteriormente, desarrollo la funcion en si;


int main(void) {
	setbuf(stdout,NULL);  // setbuff SIEMPRE ,inmediatamente de bajo del main

	int number1;
	int number2;
	int resultado;



	printf("ingrese number1");
	scanf("%d" ,&number1);
	printf("ingrese number 2");
	scanf("%d" ,&number2);

	resultado=Sumando(number1,number2);   // la funcion ( las variables que voy a usar )

	printf("la suma total es :%d",resultado);



	return EXIT_SUCCESS;
}

int Sumando(int a,int b)//
							/// los valores que le van a usarse en las  funciones ,
								///independientementte de las declaradas abajo,
{								/// posteriormente, desarrollo la funcion en si;
	int valor;

	valor=  a +  b + 100 ;

	return valor;	 // el valor de return , va a saltar al int, de SUMANDO
}

