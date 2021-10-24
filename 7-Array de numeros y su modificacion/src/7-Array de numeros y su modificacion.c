/*
 ============================================================================
 Name        : 7-Array.c
 Author      : Lucas Altamirano
 Version     :
 Copyright   : Your copyright notice
 Description :
Solicitar al usuario 5 números, almacenar estos en un array de enteros,
permitir listarlos por pantalla indicando el máximo, el mínimo y el promedio.
Permitir Modificar el valor de cualquiera de los números cargados
 indicando el índice del mismo y su nuevo valor.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define LONGITUD 5

//prototipos

int IngresoArrays(int array[],int largo);
int ImprimoArrays(int array[],int largo);
int Promedio(int array[],int largo,float *resultado);
int valorMaximo(int array[],int largo,int *resultado);

int main(void) {
	setbuf(stdout,NULL);

	int arrayNumeros[LONGITUD];
	float promedio;
	int maximo;

	IngresoArrays(arrayNumeros,LONGITUD);
	ImprimoArrays(arrayNumeros,LONGITUD);
	Promedio(arrayNumeros, LONGITUD,&promedio);
	valorMaximo(arrayNumeros, LONGITUD,&maximo);
	return EXIT_SUCCESS;
}

int IngresoArrays(int array[],int largo){
	int E=0;
	int i;
	int auxArray;
	if(array!=NULL && largo>0){
		E=1;
		for(i=0;i<largo;i++){
			printf("Ingrese numero para posicion [%d] del arrays\n",i);
			scanf("%d",&auxArray);
			array[i]=auxArray;
		}
	}
	return E;
}

int ImprimoArrays(int array[],int largo){
	int E=0;
	int i;
	if(array!= NULL && largo>0){
			 E=1;
			for(i=0;i<largo;i++){
				printf("El numero en la posicion [%d] del arrays es:%d\n",i,array[i]);
			}
		}
	return E;
}
int Promedio(int array[],int largo,float *resultado){
	int E=0;
	int i;
	int sumadorNumeros=0;
	float auxPromedio;

	if(array!=NULL && largo>0){
		 E=1;

		for(i=0;i<largo;i++){
			sumadorNumeros=sumadorNumeros+array[i];
		}
		auxPromedio=(float)sumadorNumeros/largo;
		*resultado=auxPromedio;
		printf("El promedio es:%.2f\n",auxPromedio);
	}
	return E;
}
int valorMaximo(int array[],int largo,int *resultado){

	int E=0;
	int i;
	int maximo;
	if(array!=NULL && largo>0){
		E=1;
		maximo=array[0];
		for(i=0;i<largo;i++){
			if (array[i]>maximo)
				maximo=array[i];
		}
		*resultado=maximo;
	}
	printf("El mayor es:%d\n",maximo);
	return E;
}
