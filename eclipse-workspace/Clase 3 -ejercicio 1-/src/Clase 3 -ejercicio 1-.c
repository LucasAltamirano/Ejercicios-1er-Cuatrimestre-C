/*
 ============================================================================
 Name        : Clase.c
 Author      : Lucas Altamirano
 -Funciones
 - Limpie la pantalla
 - Asigne a la variable numero1 un valor solicitado al usuario
 - Valide el mismo entre 10 y 100
 - Realice un descuento del 5% a dicho valor a través de una función llamada realizarDescuento()
 - Muestre el resultado por pantalla
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int HolaMundo();//prototipo
/*{

	printf(" hola mundo interior funcion\n");
	return  EXIT_SUCCESS;
}

*/
int main(void) {

	setbuf(stdout,NULL);

	int resultado;

	resultado = HolaMundo();
	printf("%d",resultado);

	//printf("hola mundo MAIN ;%d",resultado); // verificar como me modifica todo el msj cunado invoco la funcion

	return EXIT_SUCCESS;
}

int HolaMundo()//prototipo
{

	printf(" hola mundo interior funcion si");

	return EXIT_SUCCESS;

}

