/*
 ============================================================================
 Name        : 3-Restar.c
 Author      : Lucas Altamirano
 Version     :
 Copyright   : Your copyright notice
 Description :

- Limpie la pantalla
- Solicite dos valores numéricos al usuario distintos de cero *
- Asigne a las variables numero1 y numero2 los valores obtenidos
- Realice la resta de dichas variables
- Muestre el resultado por pantalla
- Muestre por pantalla la leyenda "Resultado positivo" en caso de ser mayor *
- Muestre por pantalla la leyenda "Resultado negativo" si es menor que cero *
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int restarDosNumeros(int operadorA,int operadorB,int* resultado,int* flag);

int main(void) {

	setbuf(stdout, NULL);

	int numero1;
	int numero2;
	int resultado;
	int flagIndicativo=0;

	printf("Ingrese un numero distinto de cero ");
	scanf("%d",&numero1);
	while (numero1==0) {
			printf("#Error,ingrese un numero distinto de cero");
			scanf(" %d",&numero1);
		}

	printf("Ingrese un numero distinto de cero ");
		scanf("%d",&numero2);
		while (numero2==0) {
				printf("#Error,ingrese un numero distinto de cero");
				scanf(" %d",&numero2);
			}

restarDosNumeros(numero1, numero2, &resultado, &flagIndicativo);

		if(flagIndicativo==0){
			printf("Resultado negativo (menor a cero)\n");
		}else{
			printf("Resultado positivo (mayor a cero)\n");
		}
printf("el resultado es %d",resultado);

	return EXIT_SUCCESS;
}
int restarDosNumeros(int operadorA,int operadorB,int* resultado,int* flag){
	int e=0;
	int auxFlag=0;
	int auxResultado;
	auxResultado=operadorA-operadorB;
	*resultado=auxResultado;

	if(auxResultado>0){
		auxFlag=1;
		*flag=auxFlag;
	}

	return e;
}
