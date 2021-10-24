/*
 ============================================================================
 Name        : 4-.c
 Author      : Lucas Altamirano
 Version     :
 Copyright   : Your copyright notice
 Description :

- Solicite al usuario 10 números
- Calcule cuántos son negativos y cuantos son positivos
- Muestre por pantalla la cantidad de negativos y la cantidad de positivos
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void contador (int* vector ,int longitud, int* negativos, int* positivos);

int main(void) {

	setbuf(stdout, NULL);
	int vectorDeNumeros[10];
	int i;
	int contadorPositivos;
	int contadorNegativos;



	for(i=0;i<10;i++){

		printf("Ingrese numero [%d]",i+1);
		scanf("%d",&vectorDeNumeros[i]);

	}


	for(i=0;i<10;i++){
		printf("numero ingresados[%d]\n",vectorDeNumeros[i]);
	}

contador(vectorDeNumeros, 10, &contadorNegativos, &contadorPositivos);

printf("total numeros Negativos [%d]\n"
		"total numeros Positivos [%d]\n",contadorNegativos,contadorPositivos);

	return EXIT_SUCCESS;
}
 void contador (int* vector ,int longitud, int* negativos, int* positivos){

	 int i;
	 int contadorNeg=0;
	 int contadorPos=0;

	 if(vector!=NULL){

		 for(i=0;i<10;i++){
		 		if(vector[i]>0){
		 			printf("Positivo:%d\n",vector[i]);
		 			contadorPos++;
		 		}else{
		 			printf("Negativos:%d\n",vector[i]);
		 			contadorNeg++;
		 		}
		 	}
	 }
	 *positivos=contadorNeg;
	 *negativos=contadorPos;
 }
