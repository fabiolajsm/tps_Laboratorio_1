/*
 * operaciones.c
 *
 *  Created on: 11 sep. 2022
 *      Author: fsuarez
 */
#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

/*OPCION 1
 * El usuario podrá elegir qué gasto desea ingresar.
 El programa deberá informar el monto de cada gasto que se haya cargado hasta el momento*/
int hospedaje = 0;
int comida = 0;
int transporte = 0;

int ingresarCostos() {
	int opcion;
	int esOpcionValida;
	int gastoH;
	int gastoC;
	int gastoT;

	esOpcionValida =
			getNumero(&opcion,
					"Elija que gasto desea ingresar:\n1) Costo de hospedaje.\n2) Costo de comida.\n3) Costo de transporte.\n",
					"Error. Opción inválida.\n", 1, 3, 3);
	if (esOpcionValida == 0) {
		switch (opcion) {
		case 1:
			getNumero(&gastoH, "Ingrese gasto del hospedaje:\n",
					"Error. Tiene que ser un gasto mayor a 0, numérico y sin decimales.\n",
					1, 1000000000, 3);
			hospedaje += gastoH;
			break;
		case 2:
			getNumero(&gastoC, "Ingrese gasto de la comida:\n",
					"Error. Tiene que ser un gasto mayor a 0, numérico y sin decimales.\n",
					1, 1000000000, 3);
			comida += gastoC;
			break;
		case 3:
			getNumero(&gastoT, "Ingrese gasto del transporte:\n",
					"Error. Tiene que ser un gasto mayor a 0, numérico y sin decimales.\n",
					1, 1000000000, 3);
			transporte += gastoT;
			break;
		}
	}
	printf(
			"Gastos hasta el momento:\n→ Costos de hospedaje: %d.\n→ Costos de comida: %d.\n→ Costos de transporte: %d.\n",
			hospedaje, comida, transporte);
	return 0;
}
