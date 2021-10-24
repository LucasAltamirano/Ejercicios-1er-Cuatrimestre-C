/*
 ============================================================================
 Name        : 5-Ingreso.c
 Author      : Lucas Altamirano
 Version     :
 Copyright   : Your copyright notice
 Description :
Ejercicio:
Realizar un programa que solicite cinco números e
imprima por pantalla el promedio, el máximo y el mínimo.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CANT 5
int Promedio (int* vector,int cantidad ,float* resultado);
int BuscoMayor(int* vector,int cantidad ,int* resultado);
int BuscoMenor(int* vector,int cantidad ,int* resultado);

int main(void) {

	setbuf(stdout,NULL);
	int numeros[CANT];
	int i;
	float promedioR;
	int numeroMayor;
	int numeroMenor;

		printf("Debera ingresar 5 numeros :\n");
	for(i=0;i<CANT;i++){
		printf("Ingrese numero [%d]",i+1);
		scanf("%d",&numeros[i]);
	}
	Promedio(numeros,CANT,&promedioR);
	printf("el promedio es %.2f\n",promedioR);

	BuscoMayor(numeros,CANT,&numeroMayor);
	printf("el mayor es %d\n",numeroMayor);

	BuscoMenor(numeros, CANT,&numeroMenor);
	printf("el menor es %d\n",numeroMenor);

	return EXIT_SUCCESS;
}

int Promedio (int* vector,int cantidad ,float* resultado){

	int E=0;
	int i;
	int sumadorVector=0;
	float auxResultado;

	if(vector!=NULL && cantidad>0){
		E=1;
		for (i=0;i<cantidad;i++){
			sumadorVector=sumadorVector+vector[i];
		}
	}
	auxResultado=(float) sumadorVector/cantidad;
	*resultado=auxResultado;

	return E;
}
int BuscoMayor(int* vector,int cantidad ,int* resultado){
	int E=0;
	int i;
	int mayor;

	if(vector!=NULL && cantidad>0){
		E=1;
		mayor=vector[0];
		for (i=0;i<cantidad;i++){

			if(vector[i]>mayor){
				mayor=vector[i];
			}
			*resultado=mayor;
		}
	}
	return E;
}

int BuscoMenor(int* vector,int cantidad ,int* resultado){
		int E=0;
		int i;
		int menor;

		if(vector!=NULL && cantidad>0){
			E=1;
			menor=vector[0];
			for (i=0;i<cantidad;i++){

				if(vector[i]<menor){
					menor=vector[i];
				}
				*resultado=menor;
			}
		}
return E;
}
