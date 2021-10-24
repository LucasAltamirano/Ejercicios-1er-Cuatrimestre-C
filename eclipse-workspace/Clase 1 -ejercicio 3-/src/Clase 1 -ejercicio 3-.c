/*
 ============================================================================

 ALTAMIRANO LUCAS DIVISION E
 EJERCICIO 3
   /// no pude colocar la library para limpiar el bufet , le puse un espacio antes de la mascara//

 c-Control de Flujo
 Pedirle al usuario su edad y su estado civil ('c'-casado, 's'-soltero, 'v'-viudo, 'd'-divorciado)
 Si ingresa una edad menor a 18 años y un estado civil distinto a "Soltero",
 mostrar el siguiente mensaje: 'Es muy pequeño para NO ser soltero.'
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int edad;
	char estadoCivil;

	setbuf(stdout, NULL);

	printf("ingrese su edad por favor ");
	scanf("%d", &edad);

	while (edad < 0 || edad > 100) {
		printf(" ERROR ingrese una edad valida");
		scanf(" %d", &edad);
	}

	printf("ingrese su estado civil  'c'-casado, 's'-soltero, 'v'-viudo, 'd'-divorciado ");

	scanf(" %c", &estadoCivil);
	while (estadoCivil != 's' && estadoCivil != 'c' && estadoCivil != 'v'&& estadoCivil != 'd') {
		printf(" ERROR ingrese su estado civil  'c'-casado, 's'-soltero, 'v'-viudo, 'd'-divorciado ");
		scanf(" %c", &estadoCivil);
	}

	if (edad<18 && estadoCivil !='s')
	{

		printf("Es muy pequeño para NO ser soltero.");
	}

			printf("\nla edad ingresada es:%d  ,y su estado civil es %c", edad,
					estadoCivil);

			return EXIT_SUCCESS;
		} // FIN DE FUNCION
