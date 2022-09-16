#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "operaciones.h"

int main(void) {
	int mostrarMenu = 1;
	int esOpcionValida;
	int opcion;
	float porcentajeAfc;
	float porcentajeCaf;
	float porcentajeConcacaf;
	float porcentajeConmebol;
	float porcentajeUefa;
	float porcentajeOfc;
	int totalCostos;
	int totalConAumento;
	int aumento = 0;

	while (mostrarMenu) {
		esOpcionValida =
				obtenerNumero(&opcion,
						"Seleccione una opción:\n1. Ingreso de los costos de Mantenimiento.\n2. Carga de jugadores.\n3. Realizar todos los cálculos.\n4. Informar resultados.\n5. Salir.\n",
						"Error. Opción inválida.\n", 1, 5, 3);
		if (esOpcionValida == 0) {
			switch (opcion) {
			case 1:
				ingresarCostos();
				break;
			case 2:
				cargarJugadores();
				break;
			case 3:
				calcularResultados(&porcentajeAfc, &porcentajeCaf,
						&porcentajeConcacaf, &porcentajeConmebol,
						&porcentajeUefa, &porcentajeOfc, &totalCostos,
						&totalConAumento, &aumento);
				break;
			case 4:
				informarResultados(porcentajeAfc, porcentajeCaf,
						porcentajeConcacaf, porcentajeConmebol, porcentajeUefa,
						porcentajeOfc, totalCostos, totalConAumento, aumento);
				break;
			case 5:
				mostrarMenu = 0;
				break;
			}
		}
	}
	return EXIT_SUCCESS;
}
