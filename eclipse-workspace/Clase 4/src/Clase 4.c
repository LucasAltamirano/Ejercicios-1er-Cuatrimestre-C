/*
 ============================================================================
 CLASE 4   EJERCICIO "MENU "  DIV 1 E

 Author      : Lucas Altamirano
 A- Hacer el menú de un programa con las siguientes opciones:
 1. Loguearse, 2. Comprar, 3. Ver mis compras, 4. Vender, 5. Salir
 B- Al menú anterior chequear que no pueda ingresar a ninguna opción si no se logueó.
 C- Al menú anterior chequear que no pueda ver sus compras, si no ingresó primero a comprar al menos una vez
 D- Cuando se ingresa a la opción vender del menú, debe abrirse otro menú que contenga:
 1. Vender 2. Hacer factura 3. Volver atrás
 E- A lo anterior sumarle que haya compras para poder vender.
 (Si compré una vez y vendí una vez no puedo ingresar a vender).
 F- Pasar las acciones de menú a funciones y llevarlas a una biblioteca

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);

	int opcion;
	//2//
	int banderaLogueo;
	//3//
	int banderaDeCompra;
	//4//
	char opcionVenta;
	//5//
	int contadorCompra;

	banderaLogueo = 0;
	banderaDeCompra = 0;
	contadorCompra = 0;

	do {
		printf("------MENU-----\n");
		printf("1- Loguearse\n");
		printf("2- Comprar\n");
		printf("3- Mis compras\n");
		printf("4- Vender\n");
		printf("5- Salir\n");
		fflush(stdin);

		scanf("%d", &opcion);

		/* Inicio del anidamiento */

		switch (opcion) {
		case 1:

			printf(" Debera  loguearse \n");
			printf("Se logueo exitosamente");
			banderaLogueo = 1;

			break;

		case 2:
			if (banderaLogueo != 1) {
				printf("Debe loguearse para empezar a operar");
			} else {
				printf("Comprar Articulos ");

				contadorCompra++;

				banderaDeCompra = 1;

			}

			break;

		case 3:
			if (banderaLogueo != 1) {
				printf("Debe loguearse para empezar a operar");
			} else {

				if (banderaDeCompra != 1) {

					printf(
							"Usted no  tiene ningun articulo Comprados,Dirijase a Opcion 2 (Comprar )");

				} else {
					printf(" Mis compras  ");
				}

			}

			break;
		case 4:
			if (banderaLogueo != 1) {
				printf("Debe loguearse para empezar a operar");

			} else {

				if (contadorCompra == 0) {
					printf(
							"No tiene articulos para vender ,dirijase a Opcion 2 (comprar articulos");

				} else {
					do {
						printf("'a'Vender ");
						printf("'b' Hacer factura");
						printf("'c' volver atras");

						fflush(stdin);
						scanf("%c", &opcionVenta);

						switch (opcionVenta) {
						case 'a':
							printf("vendiendo ");

							break;
						case 'b':
							printf("haciendo factura;  ");

							break;
							contadorCompra--; // si vendi , un producto, resto un producto del stock disponible

						} //fin switch sub menu
					} while (opcionVenta != 'c');

				} //fin else case 4

				break;
			}
		} //fin switch menu principal

	} while (opcion != 5); //fin do while principal

	printf("afuera del while");

	return 0;
} //fin programa
