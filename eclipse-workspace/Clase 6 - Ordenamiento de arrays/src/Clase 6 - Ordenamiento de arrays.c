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

#define EMPLEADOS 5

void cargarArraysSecuencial(int pArray[], int pArrayLimite);
void ContadorPositivosNegativos(int pArray[], int pArrayLimite, int *positivos,int *negativos);
void MuestroPares(int pArray[], int pArrayLimite);
void MuestroImpares(int pArray[], int pArrayLimite);
void printfArrays(int pArray[], int pArrayLimite);
void SumadorPares(int pArray[], int pArrayLimite, int *DevNumerosPares);

int main(void) {



	int ArraysEdades[EMPLEADOS] = { 2, 4, 6, 8, 10 };
	int totalPares;
	int totalPositivos;
	int totalNegativos;

	cargarArraysSecuencial(ArraysEdades, EMPLEADOS);
	ContadorPositivosNegativos(ArraysEdades, EMPLEADOS, &totalPositivos,&totalNegativos);
	SumadorPares(ArraysEdades, EMPLEADOS, &totalPares);
	MuestroPares(ArraysEdades, EMPLEADOS);
	MuestroImpares(ArraysEdades, EMPLEADOS);
	printfArrays(ArraysEdades, EMPLEADOS);
	printf("Cantidad de positivos:%d y negativos %d\n", totalPositivos,totalNegativos);
	printf("el total de pares es :%d", totalPares);

	return EXIT_SUCCESS;
} // llave final de Main

void cargarArraysSecuencial(int pArray[], int pArrayLimite) {

	int i;
	int datoCargado;
	printf("CARGA DE DATOS MANERA SECUENCIAL  \n");
	for (i = 0; i < pArrayLimite; i++) {

		printf("Ingrese  valor para posicion %d", i);
		scanf("%d", &datoCargado);

		pArray[i] = datoCargado;
	}
}
void printfArrays(int pArray[], int pArrayLimite) {

	int i;

	for (i = 0; i < pArrayLimite; i++) {

		printf(" posicion:%d -  valor:%d \n", i, pArray[i]);

	}

}
void SumadorPares(int pArray[], int pArrayLimite, int *DevNumerosPares) {

	int i;
	int numeroCargadoAux;
	int sumadorPares;
	sumadorPares = 0;

	for (i = 0; i < pArrayLimite; i++) {

		numeroCargadoAux = pArray[i];

		if (numeroCargadoAux % 2 == 0) {

			sumadorPares = sumadorPares + numeroCargadoAux;

		}

		*DevNumerosPares = sumadorPares;

	}
}
void ContadorPositivosNegativos(int pArray[], int pArrayLimite, int *positivos,
		int *negativos) {
	int i;
	int numeroCargadoAux;
	int contadorPositivos;
	int contadorNegativos;

	contadorPositivos = 0;
	contadorNegativos = 0;

	for (i = 0; i < pArrayLimite; i++) {

		numeroCargadoAux = pArray[i];

		if (numeroCargadoAux > 0) {

			contadorPositivos++;
		} else {
			contadorNegativos++;
		}

		*positivos = contadorPositivos;
		*negativos = contadorNegativos;

	}

}
void MuestroPares(int pArray[], int pArrayLimite) {

		int i;
		int numeroCargadoAux;

		for (i = 0; i < pArrayLimite; i++) {

			numeroCargadoAux = pArray[i];

			if (numeroCargadoAux % 2 == 0) {

				printf("NUMERO PAR : posicion :%d - valor :%d \n", i,
						numeroCargadoAux);

			}
		}
}
void MuestroImpares(int pArray[], int pArrayLimite) {

	int i;
	int numeroCargadoAux;

			for (i = 0; i < pArrayLimite; i++) {

				numeroCargadoAux = pArray[i];

				if (numeroCargadoAux % 2 !=0) {

					printf("NUMERO IMPAR : posicion :%d - valor :%d \n", i,
							numeroCargadoAux);

				}
			}


}
