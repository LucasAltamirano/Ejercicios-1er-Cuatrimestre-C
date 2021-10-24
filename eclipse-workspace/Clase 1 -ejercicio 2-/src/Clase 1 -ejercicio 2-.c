/*
 ============================================================================

 Lucas Altamirano DIVISION E
b-Entrada/salida
Pedir el sueldo al usuario. Sumarle
 un 10% e informarle cuál será su sueldo con aumento.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float sueldoIngresado;
	float sueldoFinal;
	setbuf(stdout,NULL);

	printf("ingrese su sueldo por favor ");
	scanf("%f",&sueldoIngresado);

	sueldoFinal =(float)sueldoIngresado+ (sueldoIngresado *10/100);


	printf("el sueldo con aumento es de $ %.2f",sueldoFinal);





	return EXIT_SUCCESS;
}// FIN  DE FUNCION
