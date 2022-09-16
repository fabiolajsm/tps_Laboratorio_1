/*
 ============================================================================
 Alumna: Fabiola Suárez
 División E
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "operaciones.h"

int main(void) {
	int mostrarMenu = 1;
	int esOpcionValida;
	int opcion;
	// para mostrar despues:
	float pAfc;
	float pCaf;
	float pConcacaf;
	float pConmebol;
	float pUefa;
	float pOfc;
	int totalCostos;
	int totalConAumento;
	int aumento;

	while (mostrarMenu) {
		esOpcionValida =
				getNumero(&opcion,
						"Seleccione una opción:\n1. Ingreso de los costos de Mantenimiento.\n2. Carga de jugadores.\n3. Realizar todos los cálculos.\n4. Informar resultados.\n5. Salir.\n",
						"Error. Opción inválida.\n", 1, 5, 3);
		if (esOpcionValida == 0) {
			switch (opcion) {
			case 1:
				ingresarCostos();
				break;
			case 2:
				cargaDeJugadores();
				break;
			case 3:
				calcular(&pAfc, &pCaf, &pConcacaf, &pConmebol, &pUefa, &pOfc,
						&totalCostos, &totalConAumento, &aumento);

				break;
			case 4:
				informarResultados(pAfc, pCaf, pConcacaf, pConmebol, pUefa,
						pOfc, totalCostos, totalConAumento, aumento);
				break;
			case 5:
				mostrarMenu = 0;
				break;
			}
		}
	}
	return EXIT_SUCCESS;
}
