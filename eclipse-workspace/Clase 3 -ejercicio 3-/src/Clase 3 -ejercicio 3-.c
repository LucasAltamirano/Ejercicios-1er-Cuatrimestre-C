/*
 ============================================================================

 Author      : Lucas Altamirano  Div E


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


#define 	DESCUENTO 10.0

float  RealizarDescuento(int a,float descuento); //prototipo


int main(void) {

	setbuf(stdout, NULL);

	int numero1;
	float resultado;

	printf("Ingrese un numero entre 10 y 100: ");
		scanf("%d",&numero1);
		while (numero1 < 10 || numero1 > 100)
		{

			printf("ERROR ingrese numero entre 10 y 100: ");
			scanf("%d",&numero1);

		}

	resultado= RealizarDescuento(numero1,DESCUENTO);

	printf("con el descuento queda en %.2f",resultado);


}
float  RealizarDescuento(int a,float descuento)
{
	float resultado;
	resultado=( float)a -(a*descuento/100);

	return resultado;
}


