/*
 ============================================================================
 Name        : 9-.c
 Author      : Lucas Altamirano
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int recibidorArrays(float* arrayaimprimir[]);

int main(void) {

	float arrayFloat []={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};

	recibidorArrays(arrayFloat);


	return EXIT_SUCCESS;
}
int recibidorArrays(float	arrayaimprimir[]){
	int E=0;

	printf("%f",arrayaimprimir);

	return E;
}
