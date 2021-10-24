/*
 ============================================================================
 Name        : 8-.c
 Author      : Lucas Altamirano
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int convertidorDeCharEntero(char *string,int* retornoId);



int main(void) {

	char string []={"SIGLO XXI EDITORES""SIGLO XXI EDITORES"};

	int idCarga=0;
	convertidorDeCharEntero(string,&idCarga);

	printf("resultado del %d",idCarga);

	return EXIT_SUCCESS;
}


int convertidorDeCharEntero(char* string,int* retornoId){

	int E=0;
	int i;
	int id=0;

	char *matrix []={"Planeta","SIGLO XXI EDITORES","Pearson","Minotauro","SALAMANDRA","PENGUIN BOOKS"};

if(string!=NULL&&retornoId!=NULL){

for (i=0;i<7;i++)
{
	if((strcmp(matrix[i],string))==0){
		id=i+1;
		*retornoId=id;
		break;
	}
}

}

return E;
}
