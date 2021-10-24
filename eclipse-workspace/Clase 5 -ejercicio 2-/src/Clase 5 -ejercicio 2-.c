/*
 ============================================================================
 Name        : Clase.c
 Author      : Lucas Altamirano

 Ejercicio 5-2:Pedir el ingreso de 10 números enteros entre -1000 y 1000.
 Determinar:Cantidad de positivos y negativos.
 Sumatoria de los pares.El mayor de los impares.Listado de los números ingresados.
 Listado de los números pares.Listado de los números de las posiciones impares.
 Se deberán utilizar funciones y vectores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define numerosPedidos 10
void cargarDatosArray(int arrayRecibido[],int tamanioArrayRecibido);
void contadorDePositivosNegativos(int arrayRecibido[],int tamanioArrayRecibido,int* contPosiDev,int* contNegaDev);
void sumadorDePares(int arrayRecibido[],int tamanioArrayRecibido,int* acumuladorDev);
void mayorImparEncontrado(int arrayRecibido[],int tamanioArrayRecibido,int* mayorImparEncontrado);
void mostradorDeEnterosCargados(int arrayRecibido[],int tamanioArrayRecibido);
void mostradorDeParesEnterosCargados(int arrayRecibido[],int tamanioArrayRecibido);
void mostradorEnterosEnPosImpar(int arrayRecibido[],int tamanioArrayRecibido);

int main(void)
{
	setbuf(stdout,NULL);

	int numeros[numerosPedidos];
	int contadorPositivos;
	int contadorNegativos;
	int totalPares;
	int mayorDeLosImpares;

	cargarDatosArray(numeros,numerosPedidos);
	contadorDePositivosNegativos(numeros,numerosPedidos,&contadorPositivos,&contadorNegativos);
	sumadorDePares(numeros,numerosPedidos,&totalPares);
	mayorImparEncontrado(numeros,numerosPedidos,&mayorDeLosImpares);
	mostradorDeEnterosCargados(numeros,numerosPedidos);
	mostradorDeParesEnterosCargados(numeros,numerosPedidos);
	mostradorEnterosEnPosImpar(numeros,numerosPedidos);
	printf("El total de positivos es %d y de negativos es %d\n",contadorPositivos,contadorNegativos);
	printf("La suma de los pares es %d\n",totalPares);
	printf("El mayor de los impares es %d\n",mayorDeLosImpares);

	return EXIT_SUCCESS;
}
void cargarDatosArray(int arrayRecibido[],int tamanioArrayRecibido)
{
	int numeroCargadoAux;
	int i;

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		printf("Se le pediran 10 numeros,ingrese numero entre -1000 y 1000\n");
		scanf("%d",&numeroCargadoAux);
		while(numeroCargadoAux>1000||numeroCargadoAux<-1000)
		{
			printf("ERROR,Se le pediran 10 numeros,ingrese numero entre -1000 y 1000\n");
			scanf("%d",&numeroCargadoAux);
		}
		arrayRecibido[i]=numeroCargadoAux;
	}
}

void contadorDePositivosNegativos(int arrayRecibido[],int tamanioArrayRecibido,int* contPosiDev,int* contNegaDev)
{
	int i;
	int numeroCargadoAux;
	int contadorPositivos=0;
	int contadorNegativos=0;

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		numeroCargadoAux=arrayRecibido[i];
		if(numeroCargadoAux>0)
		{
			contadorPositivos++;
		}
		else
		{
			if(numeroCargadoAux<0)
			{
				contadorNegativos++;
			}
		}
	}
	*contPosiDev=contadorPositivos;
	*contNegaDev=contadorNegativos;
}

void sumadorDePares(int arrayRecibido[],int tamanioArrayRecibido,int* acumuladorDev)
{
	int i;
	int numeroCargadoAux;
	int acumuladorPares=0;

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		numeroCargadoAux=arrayRecibido[i];
		if(numeroCargadoAux%2==0)
		{
			acumuladorPares=acumuladorPares+numeroCargadoAux;
		}
	}
	*acumuladorDev=acumuladorPares;
}

void mayorImparEncontrado(int arrayRecibido[],int tamanioArrayRecibido,int* mayorImparEncontrado)
{
	int i;
	int numeroCargadoAux;
	int mayorDeLosImpares;
	int banderaMayorImpares=1;

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		numeroCargadoAux=arrayRecibido[i];
		if(numeroCargadoAux%2!=0)
		{
			if(banderaMayorImpares||numeroCargadoAux>mayorDeLosImpares)
			{
				mayorDeLosImpares=numeroCargadoAux;
				banderaMayorImpares=0;
			}
		}
	}
	*mayorImparEncontrado=mayorDeLosImpares;
}

void mostradorDeEnterosCargados(int arrayRecibido[],int tamanioArrayRecibido)
{
	int i;

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		printf("El numero cargado en posicion %d es: %d\n",i,arrayRecibido[i]);
	}
}

void mostradorDeParesEnterosCargados(int arrayRecibido[],int tamanioArrayRecibido)
{
	int i;
	int numeroCargadoAux;

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		numeroCargadoAux=arrayRecibido[i];
		if(numeroCargadoAux%2==0)
		{
			printf("El numero par cargado en posicion %d es: %d\n",i,numeroCargadoAux);
		}
	}
}

void mostradorEnterosEnPosImpar(int arrayRecibido[],int tamanioArrayRecibido)
{
	int i;
	int numeroCargadoAux;

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		numeroCargadoAux=arrayRecibido[i];
		if(i%2!=0)
		{
			printf("El numero cargado en posicion impar %d es: %d\n",i,numeroCargadoAux);
		}
	}
}



