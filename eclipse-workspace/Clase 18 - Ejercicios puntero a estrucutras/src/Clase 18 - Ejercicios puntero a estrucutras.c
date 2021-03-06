/*
 ============================================================================
 Name        : Clase.c
 Author      : Lucas Altamirano
   Punteros a estruucturas
 ============================================================================
 */


/*


 *//*1-Utilizar aritm?tica de punteros. Realizar una funci?n que reciba un puntero a char y dos char.
La funci?n deber? reemplazar en la cadena cada ocurrencia del primer car?cter recibido, por el segundo.
Retornando la cantidad de reemplazos o -1 en caso de error. */

/*
int funcionPunteroChar(char* puntero,char uno,char dos);
int main(void)
{
	setbuf(stdout,NULL);

	char puntero[20];

	funcionPunteroChar(puntero,'a','b');

	return EXIT_SUCCESS;
}

int funcionPunteroChar(char* puntero,char uno,char dos)
{
	int i;
	int contadorReemplazos=0;

	for(i=0;i<(strlen(puntero));i++)
	{
		if(*(puntero+i)==uno)
		{
			*(puntero+i)=dos;
			contadorReemplazos++;
		}
	}
	if(contadorReemplazos==0)
	{
		contadorReemplazos=-1;
	}
	return contadorReemplazos;
}


// 2-Utilizar aritm?tica de punteros. Realizar una funci?n que reciba como par?metros un array de enteros
y un entero por referencia. La funci?n calcular? el valor m?ximo de ese array y utilizar? el valor por
referencia para retornar ese valor.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 20


int segundaFuncion(int arrayInt[], int*pPuntero);


int main(void) {
	setbuf(stdout, NULL);

				// DECLARO LAS VARIABLES PARA EL SEGUNDO EJERCICIO

	int arrayNum[4];
	int resultado;
	int i;

				//LLAMADO A LA SEGUNDA FUNCION
	for(i = 0; i < 4; i++)
	{
		printf("\nIngrese un numero: ");
		scanf("%d",&(*(arrayNum+i)));
	}
	segundaFuncion(arrayNum,&resultado);
	printf("\nEl mayor es %d",resultado);


	return EXIT_SUCCESS;
}

int segundaFuncion(int arrayInt[], int*pPuntero)
{
	int i;
	int mayor;
	int flag = 1;
	int len = 4;
	if(arrayInt != NULL && pPuntero != NULL)
	{
		for(i = 0; i < len; i++)
		{
			if(flag || *(arrayInt+i) > mayor)
			{
				mayor = *(arrayInt+i);
				*pPuntero = mayor;
				flag = 0;
			}
		}

	}
	return 0;
}



