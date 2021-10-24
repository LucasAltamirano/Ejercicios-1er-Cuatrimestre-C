/*
 * employees.h
 *
 *  Created on: 15 may. 2021
 *      Author: Lucas
 */

#ifndef EMPLOYEES_H_
#define EMPLOYEES_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Genericas.h"

#define REINTENTOS 1
struct {
	int idEmployee;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}typedef sEmployee;

//PROTOTIPOS FUNCIONES

int buscarIsEmpty(sEmployee estructurasRecibidas[], int limiteStruct);

int initEmployees(sEmployee estructurasRecibidas[], int limiteStruct);
int addEmployees(sEmployee estructurasRecibidas[], int espacioLibre);
void modificacionDatos(sEmployee estructurasRecibidas[], int limitstruct);
int removeEmployee(sEmployee estructurasRecibidas[], int limitstruct);
void sortEmployees(sEmployee arrayRecibido[],int tamanioArrayRecibido);
int printEmployees(sEmployee estructurasRecibidas[],int limitstruct);
void PrintOneEmployees(sEmployee estructuraRecibida);

int eEmployeePromSalario(sEmployee estructurasRecibidas[], int limiteStruct);



#endif /* EMPLOYEES_H_ */
