/*
 ===========================================================================
 Lucas Altamirano division E
 practicas sabado
 Ejercicio 3:

 Realizar el algoritmo que permita ingresar los datos de los alumnos de una
 división de la UTN FRA, los datos solicitados son:
 Legajo
 Tipo cursada(L: &quot;libre&quot; - P: &quot;presencial&quot; – R: &quot;remota&quot;)
 Cantidad de materias( mas de cero y menos de 8)
 Sexo (F: “femenino” – M: “masculino” , O: “no binario”)
 Nota promedio (entre 0 y 10)
 Edad (validar)
 Se debe informar de existir, o informar que no existe , en el caso que
 corresponda.
 a) El Legajo del mejor promedio que femenino.
 b) El legajo del más joven de los alumnos masculinos entre los que dan libre.
 c) El promedio de nota por sexo.
 d) La edad y legajo del que cursa más materias. (Sin importar su género)
 ============================================================================
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char continuar;
	int legajoIngresado;
	char tipoCursada;
	int cantidadMaterias;
	char sexoIngresado;
	float notaPromedio;
	int edadIngresada;

	///a///
	float mejorPromedioF;
	int legajoMejorPromF;

	///b///
	int mascMasJoven;
	int legajoMasculino;

	///c///
	int contadorPromedioM;
	int contadorPromedioO;
	int contadorPromedioF;
	float sumadorPromedioM;
	float sumadorPromedioO;
	float sumadorPromedioF;
	float promedioFinalF;
	float promedioFinalM;
	float promedioFinalO;
	///d///
	int cursaMasMaterias;
	int banderaPuntoD;
	int edadPunto;
	int legajoPunto;

	continuar = 's';
	contadorPromedioM = 0;
	contadorPromedioO = 0;
	contadorPromedioF = 0;
	banderaPuntoD = 0;

	setbuf(stdout, NULL);

	while (continuar == 's') {

		//Legajo
		printf(" ingrese su numero de legajo ");
		scanf(" %d", &legajoIngresado);
		fflush( stdout);

		while (legajoIngresado < 1 || legajoIngresado > 50000000) {

			printf(" ERROR ingrese su numero de legajo ");
			fflush( stdout);
			scanf(" %d", &legajoIngresado);
		}

		//tipo cursada Tipo cursada(L: &quot;libre&quot; - P: &quot;presencial&quot; – R: &quot;remota&quot;)

		printf(
				" ingrese su Tipo cursada(L:;libre; - P: ;presencial; – R: ;remota ");
		scanf(" %c", &tipoCursada);
		while (tipoCursada != 'L' && tipoCursada != 'P' && tipoCursada != 'R') {

			printf(
					" ERROR ingrese su Tipo cursada(L:;libre; - P: ;presencial; – R: ;remota ");
			scanf(" %c", &tipoCursada);
		}
		//Cantidad de materias( mas de cero y menos de 8)

		printf("Ingrese la cantidad de materias 1-7 inclusive ");
		scanf(" %d", &cantidadMaterias);
		while (cantidadMaterias < 1 || cantidadMaterias > 7) {

			printf(
					" ERROR ingrese cantidad de materias valida 1- 7 inclusive  ");
			scanf(" %d", &cantidadMaterias);
		}
		// Sexo (F: “femenino” – M: “masculino” , O: “no binario”)
		printf("Ingrese su sexo   F: femenino – M: masculino, O: no binario ");
		scanf(" %c", &sexoIngresado);
		while (sexoIngresado != 'F' && sexoIngresado != 'M'
				&& sexoIngresado != 'O') {

			printf(
					" ERROR Ingrese su sexo   F: femenino – M: masculino, O: no binario");
			scanf(" %c", &sexoIngresado);
		}

		// Nota promedio (entre 0 y 10)

		printf("Ingrese su nota promedio de 0 a 10 inclusive  ");
		scanf(" %f", &notaPromedio);

		while (notaPromedio < 0 || notaPromedio > 10) {
			printf(" ERROR Ingrese su nota promedio de 0 a 10 inclusive ");
			scanf(" %f", &notaPromedio);

		}

		//edad validada

		printf("Ingrese su edad");
		scanf("%d", &edadIngresada);
		while (edadIngresada < 18 || edadIngresada > 90) {
			printf(" ERROR Ingrese su edad ");
			scanf(" %d", &edadIngresada);

		}
		switch (sexoIngresado) {
		case ('F'):

			contadorPromedioF++;
			sumadorPromedioF = sumadorPromedioF + notaPromedio;

			if (contadorPromedioF != 0 || notaPromedio > mejorPromedioF) {
				mejorPromedioF = notaPromedio;
				legajoMejorPromF = legajoIngresado;

			}

			break;
		case ('M'):
			contadorPromedioM++;
			sumadorPromedioM = sumadorPromedioM + notaPromedio;

			if (tipoCursada == 'L') {

				if (contadorPromedioM != 0 || edadIngresada < mascMasJoven) {
					mascMasJoven = edadIngresada;
					legajoMasculino = legajoIngresado;

				}

			}

			break;
		case ('O'):
			contadorPromedioO++;
			sumadorPromedioO = sumadorPromedioO + notaPromedio;

			if (banderaPuntoD == 0 || cantidadMaterias > cursaMasMaterias) {
				cursaMasMaterias = cantidadMaterias;
				edadPunto = edadIngresada;
				legajoPunto = legajoIngresado;
				banderaPuntoD = 1;
			}

			break;

		} // fin de switch

		printf("desea agregar  otro alumno?");
		scanf(" %c", &continuar);

	} //fin del while

	///salida de datos///

	///punto a///
	if (contadorPromedioF > 0) {

		printf(
				"El Legajo del mejor promedio  femenino es .%d , con un promedio de %2.f",
				legajoMejorPromF, mejorPromedioF);
	} else {
		printf("\nno se registro Legajo del mejor promedio  femenino");
	}

	/// punto b///
	if (contadorPromedioM > 0) {
		printf(
				"\nEl legajo del más joven de los alumnos masculinos entre los que dan libre es %d con %d años de edad",
				legajoMasculino, mascMasJoven);

	} else {
		printf(
				"\nno se registro legajo del más joven de los alumnos masculinos entre los que dan libre");

	}

	///punto c///
	if (contadorPromedioF > 0) {
		promedioFinalF = sumadorPromedioF / contadorPromedioF;
		printf("\nla nota promedio para el sexo femenino es %2.f",
				promedioFinalF);

	} else {
		printf("\nno se registraron datos para el promedio femenino ");
	}
	if (contadorPromedioM > 0) {
		promedioFinalM = sumadorPromedioM / contadorPromedioM;
		printf("\nla nota promedio para el sexo masculino es %2.f",
				promedioFinalM);

	} else {
		printf("\nno se registraron datos para el promedio masculino ");
	}
	if (contadorPromedioO > 0) {
		promedioFinalO = sumadorPromedioO / contadorPromedioO;
		printf("\nla nota promedio para el sexo binario es %2.f",
				promedioFinalO);

	} else {
		printf("\nno se registraron datos para el promedio binario");
	}

	///punto D///
	if (banderaPuntoD != 0) {
		printf("\nLa edad %d y legajo %d del que cursa más materias", edadPunto,
				legajoPunto);

	} else {
		printf("\nno se ingresaron datos Punto D");
	}
	return EXIT_SUCCESS;
} ///fin funcion
