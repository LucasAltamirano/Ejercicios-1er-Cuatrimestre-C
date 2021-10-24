/*
 ============================================================================
 Name        : Trabajo.c
 Author      : Lucas Altamirano
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "employees.h"
#include "Genericas.h"



#define QTYEMPLEADOS 3
#define REINTENTOS 1


int main(void) {
	setbuf(stdout, NULL);

	sEmployee employee[QTYEMPLEADOS];
	int opcionMenu;
	int posicionLibre;
	int cargaEmpleadoExitosa;
	int asignacionIdEmployee = 2000;

	int contadorEmpleado;
	contadorEmpleado=0;


	initEmployees(employee, QTYEMPLEADOS);
	do {

		desplegarMenu();
		getInt(&opcionMenu, "Ingrese una opcion",
				"#ERROR,ingrese una  opcion valida", 1, 5, 5);

		switch (opcionMenu) {
		case 1:
			posicionLibre = buscarIsEmpty(employee, QTYEMPLEADOS);
			if (posicionLibre != -1) {
				cargaEmpleadoExitosa = addEmployees(employee, posicionLibre);
				if (cargaEmpleadoExitosa == 0) {
					employee[posicionLibre].idEmployee = asignacionIdEmployee;
					printf(
							"\nAlta de Empleado exitosa,Su numero de Identificacion de Empleado : %d\n",
							asignacionIdEmployee);
					asignacionIdEmployee++;
					contadorEmpleado++;
				} else {
					printf("Error en la carga de datos, vuelva a intentarlo");
				}
			}
			break;
		case 2:
			if(contadorEmpleado>0){
			modificacionDatos(employee, QTYEMPLEADOS);
			}
			break;
		case 3:
			if(contadorEmpleado>0){
			removeEmployee(employee, QTYEMPLEADOS);
			contadorEmpleado--;
			}else{printf("No existen empleados para remover");
			}
			break;
		case 4:
			if(contadorEmpleado>0){
				 eEmployeePromSalario(employee, QTYEMPLEADOS);
				sortEmployees(employee, QTYEMPLEADOS);
				printEmployees(employee, QTYEMPLEADOS);

			}else{
				printf("No hay empleados para Mostrar en el sistema");
			}
			break;

		}

	} while (opcionMenu != 5);

	return EXIT_SUCCESS;
}

