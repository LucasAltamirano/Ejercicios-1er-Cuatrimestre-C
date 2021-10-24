/*
 ============================================================================

 ESTELLA YAMMETTI


 Hacer una calculadora. Para ello el programa iniciará
 y contará con un menú de opciones:
 1. Ingresar 1er operando (A=x)
 2. Ingresar 2do operando (B=y)
 3. Calcular todas las operaciones
 a) Calcular la suma (A+B)
 b) Calcular la resta (A-B)
 c) Calcular la division (A/B)
 d) Calcular la multiplicacion (A*B)
 e) Calcular el factorial (A!)
 4. Informar resultados
 a) “El resultado de A+B es: r”
 b) “El resultado de A-B es: r”
 c) “El resultado de A/B es: r” o “No es posible dividir por cero”
 d) “El resultado de A*B es: r”
 e) “El factorial de A es: r1 y El factorial de B es: r2”
 5. Salir
 • Todas las funciones matemáticas del menú se deberán
  realizar en una biblioteca aparte,
 que contenga las funciones para realizar
 las cinco operaciones.
 • En el menú deberán aparecer
 los valores actuales cargados en los operandos A y B
 (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
 • Deberán contemplarse los casos de error (división por cero, etc)
 • Documentar todas las funciones

 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int Sumar(int a, int b, int *punteroSuma);
int Restar(int a, int b, int *punteroResta);
int Multiplicar(int a, int b, int *punteroMutiplicacion);
int Dividir(int a, int b, float *punteroDivision);
int Factorial(int a, int *punteroFactorialA);

void MiMenu();

int main(void) {
	setbuf(stdout, NULL);
	MiMenu();
	return EXIT_SUCCESS;

}


int Sumar(int a, int b, int *punteroSuma) {

	int retorno;
	int suma ;
	retorno = 0;

	if (punteroSuma != NULL) {
		suma = a + b;
		*punteroSuma = suma;
		retorno = 1;
	}

	return retorno;

}

int Restar(int a, int b, int *punteroResta) {
	int retorno;
	int resta;
	retorno = 0;

	if (punteroResta != NULL) {
		resta = a - b;
		*punteroResta = resta;
		retorno = 1;
	}
	return retorno;
}

int Multiplicar(int a, int b, int *punteroMutiplicacion) {

	int retorno;
	int multiplicacion;
	retorno = 0;

	if (punteroMutiplicacion != NULL) {
		multiplicacion = a * b;
		*punteroMutiplicacion = multiplicacion;
		retorno = 1;
	}
	return retorno;
}

int Dividir(int a, int b, float *punteroDivision) {

	int retorno;
	int division;
	retorno = 0;

	if (punteroDivision != NULL && b != 0) {

		division =  a /(float) b;
		*punteroDivision = division;
		retorno = 1;
	}
	return retorno;
}


int Factorial(int a,int *punteroFactorial) {
	int retorno;
	int factorial;
	factorial=1;
	retorno = 0;
	if(a>=0 && a<15)
			{
			    for(int i=1; i<=a; i++)
			    {
			        factorial=factorial*i;
			    }
			    *punteroFactorial=factorial;
			    retorno=1;

			}
	return retorno;
		}


void MiMenu() {

	setbuf(stdout, NULL);


	int numero1;
	int numero2;
	int sumaMenu;
	int restaMenu;
	int multiplicacionMenu;
	float divisionMenu;
	int factorialA;


	int opcion;
	int banderaNumero1;
	int banderaNumero2;
	int banderaOpcion3;
	banderaNumero1 = 0;
	banderaNumero2 = 0;
	banderaOpcion3 = 0;

	printf("\n\tLa calculadora esta lista para operar\n");
	do {

		printf("\n1-Ingrese el 1er numero\n");
		printf("2-IIngrese el 2do numero\n");
		printf("3-Calcular los resultados\n");
		printf("4-Mostrar  los resultados\n");
		printf("5-Salir de  la calculadora");

		scanf("%d", &opcion);
		switch (opcion) {
		case 1:

			printf("\nIngrese el 1er Operando (A)\n");
			scanf("%d", &numero1);
			printf("\t A=%d\n", numero1);
			banderaNumero1 = 1;
			break;

		case 2:
			if (banderaNumero1 == 1) {
				printf("\nIngrese el 2do Operando (B)\n ");
				scanf("%d", &numero2);
				printf("\t A=%d     B=%d\n", numero1, numero2);
				banderaNumero2 = 1;
			} else {
				printf(
						"\n Primero tiene que ingresar el 1er (A) Operando en opcion 1 \n");
			}

			break;

		case 3:
			if (banderaNumero1 != 1 && banderaNumero2 != 1) {
				printf(
						" Debera ingresar los dos operadores para comenzar a operar\n ");
			} else {

				printf("\n.Calculando.......\n");
				if (Sumar(numero1, numero2, &sumaMenu)) {

					printf("calculo de  (%d+%d) ,Operacion exitosa\n", numero1, numero2);
				} else {
					printf("calculo  de  (%d+%d) Operacion fallida", numero1, numero2);
				}

				if (Restar(numero1, numero2, &restaMenu)) {
					printf("calculo de  (%d-%d) ,Operacion exitosa\n", numero1, numero2);
				} else {
					printf("calculo de  (%d-%d) Operacion fallida", numero1, numero2);
				}

				if (Multiplicar(numero1, numero2, &multiplicacionMenu)) {

					printf("calculo de  (%d*%d) ,Operacion exitosa\n", numero1, numero2);
				} else {
					printf("calculo de  (%d*%d) Operacion fallida", numero1, numero2);
				}

				if (Dividir(numero1, numero2, &divisionMenu)) {

					printf("calculo de  (%d/%d) ,Operacion exitosa\n", numero1, numero2);
				} else {
					printf("(%d/%d) Syntax ERROR", numero1, numero2);
				}

				if (Factorial(numero1, &factorialA)) {
					printf("calculo Factorial de  (%d) ,Operacion exitosa\n",
							numero1);
				} else {
					printf("Syntax ERROR");

				}



			}

			banderaOpcion3 = 1;

			break;

		case 4:
			if (banderaOpcion3 != 1) {
				printf(
						"\nPara Mostrar los resultados ,primero es necesario Calcular los mismos  en Opcion #3\n");
			}

			else {
				printf(" El resultado de %d + %d es: %d\n", numero1, numero2, sumaMenu);

				printf(" El resultado de %d - %d es: %d\n", numero1, numero2, restaMenu);

				if (divisionMenu != 0) {
					printf(" El resultado de %d/ %d es: %.2f\n", numero1, numero2,
							divisionMenu);
				} else {
					printf("No es posible dividir por cero:/<0>\n");
				}

				printf(" El resultado de %d * %d es: %d\n", numero1, numero2,
						multiplicacionMenu);

				printf(
						" El resultado de Factorial A(%d)  es: %d \n",
						numero1, factorialA);

			}

			break;

		case 5:
			printf("\n Salio de la Calculadora \n");
			break;

		default:

			printf("\n Ingrese una opcion valida\n");

			break;

		}

	} while (opcion != 5);
}
