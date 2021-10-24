/*
 ============================================================================
 Name        : Modelo.c
 Author      : Lucas Altamirano
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>



typedef struct{

	char calle[20];
	int  numero;
}domicilio;

typedef  struct {

	char nombre[20];
	domicilio domicilioA[50];
	int precio;

}pantallas;




int cargarStruct(pantallas estructurasRecibidas[],int espacioLibre);

int main(void) {

	do{
		printf("Menu principal Publicidad Via Publica\n"
				"--------1)Alta de pantalla:\n"
				"--------2)Modificar datos de pantalla:\n"
				"--------3)Baja de pantalla:\n"
				"--------4)Contratar una publicidad:\n"
				"--------5)Modificar condiciones de publicación:\n"
				"--------6)Cancelar contratación:\n"
				"--------7) Consulta facturación:\n"
				"--------8) Listar contrataciones:\n"
				"--------9) Listar​ ​pantallas:\n​"
				"-------10)Informar :\n​");
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

			break;
			case 3:

			break;
			case 4:

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
