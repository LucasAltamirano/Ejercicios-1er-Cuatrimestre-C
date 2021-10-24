/*
 ============================================================================
 Name        : Clase.c
 Author      : Lucas Altamirano
Desarrollar un programa que permita guardar los datos de 5 alumnos.
 Los datos a guardar para cada alumno: legajo, sexo, edad, nota1, nota2, promedio, apellido.
  Se debe utilizar estructuras, permitiendo al usuario trabajar con los datos a través de un ABM.
Hacer con estructuras - Crear un menú

Crear funciones para: *
1-Menú e Inicialización
2-Alta
3-Listar
4-Baja
5-Modificar
6-Ordenar
7-Agregar autoincremental para el número de legajo:
 el legajo comienza en 1000, se incrementa solo (NO lo ingresa el usuario),
 si doy de baja no altera la numeración, el siguiente alta deberá respetar la numeración correlativa del autoincremental.
 (Ej alta leg 1000, alta leg 1001, alta legajo 1002, baja leg 1002, alta leg 1003)

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Genericas.h"


//define
#define CANTIDAD 5

typedef  struct {
	int legajo;
	char sexo;
	int edad;
	int notaUno;
	int notaDos;
	float promedio;
	char apellido[20];
	int estaVacio;
}datosAlumnos;

//funciones
int inicializarStruct(datosAlumnos estructurasRecibidas[],int limiteStruct);
int buscarVacio(datosAlumnos estructurasRecibidas[],int limiteStruct );
int cargarStruct(datosAlumnos estructurasRecibidas[],int espacioLibre);
void PromedioAlumno(datosAlumnos estructurasRecibidas[],int espacioLibre);
void listarAlumnos(datosAlumnos estructurasRecibidas[],int limiteStruct);
void listarAlumno(datosAlumnos estructuraRecibida);
void bajaAlumno(datosAlumnos estructurasRecibidas[], int limiteStruct);
void modificarStruct(datosAlumnos estructurasRecibidas[],int limiteStruct);
void PromedioAlumno(datosAlumnos estructurasRecibidas[],int espacioLibre);





int main(void)
{
	setbuf(stdout,NULL);

	datosAlumnos alumnos[CANTIDAD];
	int opcionMenu;
	int esNumero;
	int posLibre;
	int AsignacionLegajo;
	AsignacionLegajo=1000;



	inicializarStruct(alumnos,CANTIDAD);// Le asigno 1 (esta vacio) a todos los  isEmpty de cada array.
	do{
	printf("Menu principal Ingreso de Alumnos\n"
			"--------1-Alta de alumno\n"
			"--------2-Listar alumno\n"
			"--------3-Baja alumno\n"
			"--------4-Modificar\n"
			"--------5-Ordenar\n"
			"--------6-Salir\n");
	fflush(stdin);

	esNumero=scanf("%d",&opcionMenu);
	while(opcionMenu<1 || opcionMenu>6 || esNumero==0){
		printf("#Error,ingrese una opcion valida\n");
		fflush(stdin);
		esNumero=scanf("%d",&opcionMenu);
	}

	switch(opcionMenu){

		case 1:
			posLibre=buscarVacio(alumnos,CANTIDAD);
			if(posLibre!=-1){
				cargarStruct(alumnos, posLibre);
				alumnos[posLibre].legajo=AsignacionLegajo;
				AsignacionLegajo++;
				printf("Alta registrada con exito\n");

				printf("Pulse cualquiera tecla para volver\n");
				fflush(stdin);
				getchar();
			}else{
				printf("No hay posiciones libres para cargar Alumnos, debera eliminar una posicion\n");
				printf("Pulse cualquiera tecla para volver\n");
				fflush(stdin);
				getchar();
			}

		break;
		case 2:
			listarAlumnos(alumnos, CANTIDAD);
		break;
		case 3:
			bajaAlumno(alumnos, CANTIDAD);
		break;
		case 4:
			modificarStruct(alumnos , CANTIDAD);

		break;
		case 5:
		break;
		default:
			printf("saliendo...");
		break;


	}//Fin switch Menu principal
	} while (opcionMenu!=6);


return EXIT_SUCCESS;
}


int inicializarStruct(datosAlumnos estructurasRecibidas[],int limiteStruct){

	int i;
	int retorno;
	retorno=-1;
	if(estructurasRecibidas!=NULL){
		for(i=0;i<limiteStruct;i++){
			estructurasRecibidas[i].estaVacio=1;
		}
		retorno =0;
	}
	return retorno;
}
int buscarVacio(datosAlumnos estructurasRecibidas[],int limiteStruct ){

	int i;
	int posicionLibre;
	posicionLibre=-1;

	if(estructurasRecibidas!=NULL){
		for(i=0;i<limiteStruct;i++){

			if(estructurasRecibidas[i].estaVacio==1){
				posicionLibre=i;
				break;// inmediatamente que se localiza un espacio vacio ,
			}//le asigno el mismo(i) a posicion libre y rompo el bloque
		}
	}
	return posicionLibre;
}

int cargarStruct(datosAlumnos estructurasRecibidas[],int espacioLibre){

	int retorno;
	char auxSexo;
	int auxEdad;
	int auxNotaUno;
	int auxNotaDos;
	char auxApellido[20];

	retorno=-1;
	if(estructurasRecibidas!=NULL){
		printf("Ingrese el sexo 'f' o 'm' \n");
		fflush(stdin);
		scanf("%c",&auxSexo);
		while(auxSexo!='f' && auxSexo!='m'){
			printf("#Error,Ingrese el sexo 'f' o 'm' \n");
			fflush(stdin);
			scanf("%c",&auxSexo);
		}
		estructurasRecibidas[espacioLibre].sexo=auxSexo;
		printf("Ingrese Edad\n");
		fflush(stdin);
		scanf("%d",&auxEdad);
		while(auxEdad<18 || auxEdad>90){
			printf("#Error,Ingrese una edad valida ,de 18 hasta 90 años de edad\n");
			fflush(stdin);
			scanf("%d",&auxEdad);
		}
		estructurasRecibidas[espacioLibre].edad=auxEdad;
		printf("Ingrese la primer nota\n");
		fflush(stdin);
		scanf("%d",&auxNotaUno);
		while(auxNotaUno<1 || auxNotaUno>10){
			printf("#Error,Ingrese una nota del 1 al 10\n");
			fflush(stdin);
			scanf("%d",&auxNotaUno);
		}
		estructurasRecibidas[espacioLibre].notaUno=auxNotaUno;
		printf("Ingrese la segunda nota\n");
		fflush(stdin);
		scanf("%d",&auxNotaDos);
		while(auxNotaDos<1 || auxNotaDos>10){
			printf("#Error,Ingrese una nota del 1 al 10\n");
			fflush(stdin);
			scanf("%d",&auxNotaDos);
		}
		estructurasRecibidas[espacioLibre].notaDos=auxNotaDos;
		printf("Ingrese el apellido\n");
		fflush(stdin);
		fgets(auxApellido,20,stdin);
		strncpy(estructurasRecibidas[espacioLibre].apellido,auxApellido,sizeof(estructurasRecibidas[espacioLibre].apellido));

		PromedioAlumno(estructurasRecibidas,espacioLibre);
		estructurasRecibidas[espacioLibre].estaVacio=0;
		retorno=0;
	}//final If


	return retorno;
}

void PromedioAlumno(datosAlumnos estructurasRecibidas[],int espacioLibre){

	float notaUnoFuncion;
	float notaDosFuncion;
	float promedioFuncion;

	notaUnoFuncion=estructurasRecibidas[espacioLibre].notaUno;
	notaDosFuncion=estructurasRecibidas[espacioLibre].notaDos;

	promedioFuncion=((notaUnoFuncion+notaDosFuncion)/2);
	estructurasRecibidas[espacioLibre].promedio=promedioFuncion;
}
void listarAlumnos(datosAlumnos estructurasRecibidas[],int limiteStruct){
	int mostrarUnaVez=-1;
	int i;
	for(i=0;i<limiteStruct;i++){
		if(estructurasRecibidas[i].estaVacio==0){
			if(mostrarUnaVez==-1){
				printf("Legajo    Sexo    Edad     Nota 1     Nota 2     Promedio  Apellido\n");
				mostrarUnaVez=0;
			}
			listarAlumno(estructurasRecibidas[i]); // observar la diferencia entre Estructuras y estructura que llame mi funcon listar alumno
		}
	}
	if(mostrarUnaVez==-1){
		printf("No existen datos en el sistema\n");
	}
	printf("Pulse cualquiera tecla para volver\n");
	fflush(stdin);
	getchar();
}//FIN.funcion listasAlumnos
void listarAlumno(datosAlumnos estructuraRecibida){


	printf("%-10d%-8c%-9d%-11d%-11d%-10.2f%s",estructuraRecibida.legajo,estructuraRecibida.sexo,estructuraRecibida.edad,estructuraRecibida.notaUno,estructuraRecibida.notaDos,estructuraRecibida.promedio,estructuraRecibida.apellido);

}
void bajaAlumno(datosAlumnos estructurasRecibidas[], int limiteStruct){

	int legajoBaja;
	int i;
	int flagLegajoExistente=-1;
	int confirmaBaja;
	if(estructurasRecibidas!=NULL){
	printf(" Ingrese Legajo que desea dar de baja");
	fflush(stdin);
	scanf("%d",&legajoBaja);

	for(i=0;i<limiteStruct;i++){
	if(legajoBaja==estructurasRecibidas[i].legajo&&estructurasRecibidas[i].estaVacio==0){
			flagLegajoExistente=0;
			break;
		}
	}
	if(flagLegajoExistente ==0){
		printf("Se dara de baja el legajo %d,presione 1 para continuar o 0 para cancelar\n",legajoBaja);

		listarAlumno(estructurasRecibidas[i]);
		fflush(stdin);
		scanf("%d",&confirmaBaja);
		while(confirmaBaja !=0 && confirmaBaja!=1){
			printf("Ingrese una opcion valida,presione 1 para continuar o 0 para cancelar\n");
			fflush(stdin);
			scanf("%d",&confirmaBaja);
		}
		if(confirmaBaja==1){
			estructurasRecibidas[i].estaVacio=1;
			printf("Legajo fue dado de baja ,de manera exitosa\n");
			printf("Pulse cualquiera tecla para volver\n");
			fflush(stdin);
			getchar();
		}else{
			printf("Baja de legajo cancelado por el usuario\n");
			printf("Pulse cualquiera tecla para volver\n");
			fflush(stdin);
			getchar();

		}
		}
	}else{
		printf("Legajo inexistente/invalido \n");
		printf("Pulse cualquiera tecla para volver\n");
		fflush(stdin);
		getchar();
	}

	}
void modificarStruct(datosAlumnos estructurasRecibidas[],int limiteStruct){

	int modificarDato;

	printf("Modificar Datos --> Ingrese el dato que desea modificar ");
	printf("1:Sexo -2:Edad -3:Nota Uno-4:Nota Dos-5:Apellido");
	scanf("%d",&modificarDato);

	while(modificarDato<-1 || modificarDato>5){
		printf("Modificar Datos --> Ingrese el dato que desea modificar\n ");
		printf(" ");
		scanf("%d",&modificarDato);
	}

	if(estructurasRecibidas!=NULL){

	}

}//FIN funcion modificarStruct


void PromedioAlumno(datosAlumnos estructurasRecibidas[],int espacioLibre){

	float notaUnoFuncion;
	float notaDosFuncion;
	float promedioFuncion;

	notaUnoFuncion=estructurasRecibidas[espacioLibre].notaUno;
	notaDosFuncion=estructurasRecibidas[espacioLibre].notaDos;

	promedioFuncion=((notaUnoFuncion+notaDosFuncion)/2);
	estructurasRecibidas[espacioLibre].promedio=promedioFuncion;
}
