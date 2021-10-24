/*
 * employees.c
 *
 *  Created on: 15 may. 2021
 *      Author: Lucas
 */






#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Genericas.h"



#define REINTENTOS 1
//DESARROLO FUNCIONES


int initEmployees(sEmployee estructurasRecibidas[], int limiteStruct) {

	int i;
	int retorno;
	retorno = -1;
	if (estructurasRecibidas != NULL) {
		for (i = 0; i < limiteStruct; i++) {
			estructurasRecibidas[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}



int addEmployees(sEmployee estructurasRecibidas[], int espacioLibre) {

	int retorno;
	char auxName[20];
	char auxApellido[20];
	float auxSalary;
	int auxsector;
	//float sumadorSalario=0;

	inicializarCadenaCaracteres(auxName, 20);
	inicializarCadenaCaracteres(auxApellido, 20);

	retorno = -1;
	if (estructurasRecibidas != NULL) {

		utn_levantaCadenaCaracteres(auxName,
				"Ingrese Nombre del Nuevo Empleado",
				"#Error,ingrese nombre nuevamente", 20);
		strcpy(estructurasRecibidas[espacioLibre].name, auxName);

		utn_levantaCadenaCaracteres(auxApellido,
				"Ingrese Apellido del Nuevo Empleado",
				"#Error,ingrese apellido nuevamente", 20);
		strcpy(estructurasRecibidas[espacioLibre].lastName, auxApellido);

		utn_levantaDecimales(&auxSalary, "Ingrese el salario",
				"#ErrorIngrese el salario", 0, 200000);
		estructurasRecibidas[espacioLibre].salary = auxSalary;
		//*sumadorSalario= auxSalary;

		levantaEnteros(&auxsector, "Ingrese el sector",
				"Error Ingrese el sector", 1, 5, REINTENTOS);
		estructurasRecibidas[espacioLibre].sector = auxsector;
		estructurasRecibidas[espacioLibre].isEmpty = 0;

		retorno = 0;
	} //final If

	return retorno;
}
void modificacionDatos(sEmployee estructurasRecibidas[], int limitstruct) {
	int i;
	int auxIdModificar;
	int flagIdExistente;
	int confirmacionBaja;
	int campoModificar;

	char auxNuevoNombre[20];
	char auxNuevoApellido[20];
	float auxNuevoSalario;
	int auxNuevoSector;

	flagIdExistente = -1;

	if (estructurasRecibidas != NULL) {
		printf("|| Menu || Modificacion de datos del Empleado\n");
		printf("Ingrese el ID del empleado que desea modificar");
		scanf("%d", &auxIdModificar);

		for (i = 0; i < limitstruct; i++) {
			if (estructurasRecibidas[i].isEmpty != 1
					&& estructurasRecibidas[i].idEmployee == auxIdModificar) {

				flagIdExistente = 1;
				break;
;
			}

		}
		if (flagIdExistente == 1) {
			printf("Desea modificar el Id %d\n", auxIdModificar);

			getInt(&confirmacionBaja, "\n|1|Aceptar\n" "|2|Cancelar\n",
					"#Error,ingrese opcion valida", 1, 2, REINTENTOS);
			if (confirmacionBaja == 1) {

				getInt(&campoModificar, "Ingrese el campo que desea modificar\n"
						"|1|Nombre\n"
						"|2|Apellido\n"
						"|3|Salario\n"
						"|4|Sector\n ", "ingrese opcion valida", 1, 4,
						REINTENTOS);
				switch (campoModificar) {
				case 1:
					utn_levantaCadenaCaracteres(auxNuevoNombre,
							"Ingrese el nuevo nombre ",
							"#Error,intente nuevamente", 20);
					strcpy(estructurasRecibidas[i].name, auxNuevoNombre);
					break;
				case 2:
					utn_levantaCadenaCaracteres(auxNuevoApellido,
							"Ingrese el nuevo apellido ",
							"#Error,intente nuevamente", 20);
					strcpy(estructurasRecibidas[i].lastName, auxNuevoApellido);
					break;
				case 3:
					utn_levantaDecimales(&auxNuevoSalario,
							"Ingrese el nuevo Salario",
							"#Error,intente nuevamente", 1, 200000);
					estructurasRecibidas[i].salary = auxNuevoSalario;
					break;
				case 4:
					getInt(&auxNuevoSector, "Ingrese el nuevo sector",
							"#Error,intente nuevamente", 1, 5, REINTENTOS);
					estructurasRecibidas[i].sector = auxNuevoSector;
					break;

				default:
					break;
				}
			} else {
				printf("Modificacion de datos cancelado por el usuario\n");

			}
		}
	}

} //fin funcion
int removeEmployee(sEmployee estructurasRecibidas[], int limitstruct) {
	int retorno = -1;
	int idRemover;
	int i;
	int flagIdExistente;
	flagIdExistente = 0;
	int confirmacionRemover;

	if (estructurasRecibidas != NULL) {
		printf("|| Menu || Remover Empleado\n");
		printf("Ingrese el ID del empleado que desea suprimir del sistema");
		scanf("%d", &idRemover);

		for (i = 0; i < limitstruct; i++) {
			if (estructurasRecibidas[i].isEmpty != 1
					&& estructurasRecibidas[i].idEmployee == idRemover) {

				flagIdExistente = 1;
				break;
			}
		}
		if (flagIdExistente == 1) {
			printf(
					"Usted va a suprimir del sistema el ID :%d ,esta seguro de continuar?\n",
					idRemover);
			getInt(&confirmacionRemover, "|1|aceptar\n"
					"|2|cancelar\n", "#Error, ingrese opcion valida", 1, 2,
					REINTENTOS);

			if (confirmacionRemover == 1) {
				printf("Removiendo Empleado del sistema .......\n");
				estructurasRecibidas[i].isEmpty = 1;
				printf("Remocion Exitosa\n");
				volverAtras();

			} else {
				printf("Remocion cancelada por el usuario\n");
				volverAtras();
			}
		}else {
			printf("Id de empleado Inexistente ,verifique\n");
		}

	}

	return retorno;
}
void PrintOneEmployees(sEmployee estructuraRecibida)
{
	printf("%- 16d%-15s%-12s%-12.2f%d\n",estructuraRecibida.idEmployee,estructuraRecibida.lastName,estructuraRecibida.name,estructuraRecibida.salary,estructuraRecibida.sector);
}
int printEmployees(sEmployee estructurasRecibidas[],int limitstruct)
{
	int i;
	int exito=0;
	int sePuedeMostrar=1;

	for(i=0;i<limitstruct;i++)
	{
		if(estructurasRecibidas[i].isEmpty==0)
		{
			if(sePuedeMostrar)
			{
				printf("------------------DATOS DE EMPLEADOS-------------------\n");
				printf("|IdEmpleado    |apellido      |nombre     |salario    |sector\n");
				sePuedeMostrar=0;
			}
			PrintOneEmployees(estructurasRecibidas[i]);
			exito=1;
		}
	}
	return exito;
}

void sortEmployees(sEmployee estructurasRecibidas[],int limitstruct)
{
	int i;
	int j;
	sEmployee estructuraAuxiliar;

	for(i=0;i<limitstruct-1;i++)
	{
		for(j=i+1;j<limitstruct;j++)
		{
			if(estructurasRecibidas[i].isEmpty==0&&estructurasRecibidas[j].isEmpty==0)
			{
				strlwr(estructurasRecibidas[i].lastName);
				strlwr(estructurasRecibidas[j].lastName);
				if(strcmp(estructurasRecibidas[i].lastName,estructurasRecibidas[j].lastName)>0)
				{
					estructuraAuxiliar=estructurasRecibidas[i];
					estructurasRecibidas[i]=estructurasRecibidas[j];
					estructurasRecibidas[j]=estructuraAuxiliar;
				}
				else
				{
					if(strcmp(estructurasRecibidas[i].lastName,estructurasRecibidas[j].lastName)==0)
					{
						if(estructurasRecibidas[i].sector>estructurasRecibidas[j].sector)
						{
							estructuraAuxiliar=estructurasRecibidas[i];
							estructurasRecibidas[i]=estructurasRecibidas[j];
							estructurasRecibidas[j]=estructuraAuxiliar;
						}
					}
				}
			}
		}
	}
}

int eEmployeePromSalario(sEmployee estructurasRecibidas[], int limiteStruct)
{
	int retorno = -1;
	int i;
	float acumuladorSueldo=0;
	int contador=0;
	float promedioResultado=0;

	if(estructurasRecibidas!=NULL && limiteStruct>0)
	{
		for(i=0; i<limiteStruct; i++)
		{
			if(estructurasRecibidas[i].isEmpty==0)
			{
			acumuladorSueldo =acumuladorSueldo + estructurasRecibidas[i].salary;
			contador++;
			}
		}
		promedioResultado = acumuladorSueldo/contador;


		printf("La Suma total de salarios asciende a $%.2f\n"
				"El salario promedio es: %.2f\n",acumuladorSueldo, promedioResultado);

		retorno = 0;
	}
	return retorno;
}

int buscarIsEmpty(sEmployee estructurasRecibidas[], int limiteStruct) {

	int i;
	int posicionLibre;
	posicionLibre = -1;

	if (estructurasRecibidas != NULL) {
		for (i = 0; i < limiteStruct; i++) {

			if (estructurasRecibidas[i].isEmpty == 1) {
				posicionLibre = i;
				break; // inmediatamente que se localiza un espacio vacio ,
			} //le asigno el mismo(i) a posicion libre y rompo el bloque
		}
	}
	return posicionLibre;
}



