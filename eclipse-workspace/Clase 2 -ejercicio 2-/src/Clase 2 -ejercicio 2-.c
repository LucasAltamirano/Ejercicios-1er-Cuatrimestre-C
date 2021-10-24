/*
 ============================================================================
ALTAMIRANO LUCAS DIVISION E


Ejercicio 2-2:
Ingresar 10 números enteros, distintos de cero. Mostrar:
a. Cantidad de pares e impares.
b. El menor número ingresado.
c. De los pares el mayor número ingresado.
d. Suma de los positivos.
e. Producto de los negativos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {

	setbuf(stdout,NULL);
	int numeroIngresado;
	int contadorPares;
	int contadorImpares;
	int minimoNumero;
	int sumaPositivos;
	int productoNegativos;
	int banderaNegativo;
	int i;

	contadorPares= 0;
	contadorImpares=0;
	sumaPositivos =0;
	productoNegativos = 1;
	banderaNegativo = 0;




	for(i=0;i<10;i++){

		printf("Ingrese un numero;");
		scanf("%d",&numeroIngresado);
		while(numeroIngresado==0)
		{
			printf("ERROR ! reingrese un numero distinto de 0");
			scanf("%d",&numeroIngresado);
		}

		if(numeroIngresado%2==0)
		{
			contadorPares++;
		}
		else
		{
			contadorImpares++;
		}

		//b el menor numero ingresado;
		if(i==0 || numeroIngresado<minimoNumero)
		{
			minimoNumero = numeroIngresado;
		}
		/*if(i==0){
			minimoNumero = numeroIngresado;
		}
		else
		{
			if(numeroIngresado<minimoNumero)
			{
				minimoNumero = numeroIngresado;
			}
		}
		*/
		//// punto c // suma de los positivos.
		if(numeroIngresado>0)
		{
			sumaPositivos = sumaPositivos + numeroIngresado;
		}
		else
		{
			productoNegativos = productoNegativos * numeroIngresado;
			banderaNegativo = 1;
		}


	}//fin del for


	//salida a.///
	printf("cantidad de pares ;%d \ncantidad de impares;%d \n", contadorPares , contadorImpares);
	//salida b.
	printf("minimo numero es ;%d\n", minimoNumero);
	//salida c //// punto c // suma de los positivos.
	printf("la suma de los positivos ; %d\n" ,sumaPositivos);
	//punto d
	if(banderaNegativo!=0)
	{
		printf("el producto de los negativos es %d", productoNegativos);
	}
	else
	{
		printf("no se ingresaron datos negativos");
	}


}// fin de la funcion
