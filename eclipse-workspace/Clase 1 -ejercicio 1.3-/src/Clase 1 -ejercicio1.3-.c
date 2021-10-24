/*============================================================================

 // Author      : Lucas Altamirano div E
 clase 1      :Ejercicio 1-3:

 ingresar 3 números y mostrar el número del medio, sólo si existe.
 En caso de que no exista también informarlo.
 ============================================================================*/

#include <stdio.h>

int main()

{
	setbuf(stdout, NULL);
	int num1;
	int num2;
	int num3;

	printf("\nIngrese un numero ");
	scanf("%d", &num1);

	printf("\nIngrese otro numero ");
	scanf("%d", &num2);

	printf("\nIngrese otro numero ");
	scanf("%d", &num3);

	if ((num1 > num2 && num1 < num3) || (num1 < num2 && num1 > num3)) {
		printf("El numero del medio es %d", num1);
	} else if ((num2 > num1 && num2 < num3) || (num2 < num1 && num2 > num3)) {
		printf("El numero del medio es %d", num2);
	} else if ((num3 > num1 && num3 < num2) || (num3 < num1 && num3 > num2)) {
		printf("El numero del medio es %d", num3);
	} else {
		printf("No hay numero del medio");
	}

	return 0;
}
