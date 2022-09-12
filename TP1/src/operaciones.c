#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#define GASTO_MAXIMO 1000000000

int hospedaje = 0;
int comida = 0;
int transporte = 0;

void ingresarCostos() {
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
					1, GASTO_MAXIMO, 3);
			hospedaje += gastoH;
			break;
		case 2:
			getNumero(&gastoC, "Ingrese gasto de la comida:\n",
					"Error. Tiene que ser un gasto mayor a 0, numérico y sin decimales.\n",
					1, GASTO_MAXIMO, 3);
			comida += gastoC;
			break;
		case 3:
			getNumero(&gastoT, "Ingrese gasto del transporte:\n",
					"Error. Tiene que ser un gasto mayor a 0, numérico y sin decimales.\n",
					1, GASTO_MAXIMO, 3);
			transporte += gastoT;
			break;
		}
	}
	printf(
			"Gastos hasta el momento:\n→ Costos de hospedaje: $%d.\n→ Costos de comida: $%d.\n→ Costos de transporte: $%d.\n",
			hospedaje, comida, transporte);
}

void cargaDeJugadores() {
	int esCamisetaValida = 0;
	int esPosicionValida = 0;
	int numeroCamiseta = 0;
	int posicion = 0;
	int confederacion;

	while (!esCamisetaValida) {
		getNumero(&numeroCamiseta, "Ingrese número de camiseta:\n",
				"Error. Tiene que ser un número, del 1 al 22.\n", 1, 22, 22);
		esCamisetaValida =
				camisetaDisponible(numeroCamiseta,
						"Número de camiseta seleccionada exitosamente.\n",
						"Error. Número de camiseta no disponible, pruebe con otro número.\n");
	}
	while (!esPosicionValida) {
		getNumero(&posicion,
				"Ingrese que posición quiere jugar:\n1. Arquero.\n2. Defensa.\n3. Mediocampo.\n4. Delantero.\n",
				"Error. Tienes que seleccionar el número de la posición que quieres jugar (opciones del 1 al 4).\n",
				1, 4, 3);
		esPosicionValida =
				posicionDisponible(posicion,
						"Posición seleccionada exitosamente.\n",
						"Error. La posición que elegiste no tiene cupos, vuelve a intentarlo seleccionando otra.\n");
	}
	getNumero(&confederacion,
			"Selecciona el número de la confederación donde quieres jugar:\n1. AFC en Asia.\n2. CAF en África.\n3. CONCACAF en zona del Norte.\n4. CONMEBOL en Sudamérica.\n5. UEFA en Europa.\n6. OFC en Oceanía.\n",
			"Error. Tienes que seleccionar la confederación con un número disponible en las opciones(opciones del 1 al 6).\n",
			1, 6, 3);

	mostrarCantidadJugadores();
}

