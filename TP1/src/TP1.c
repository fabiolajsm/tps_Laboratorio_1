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
	float pAFC;
	float pCAF;
	float pCONCACAF;
	float pCONMEBOL;
	float pUEFA;
	float pOFC;

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
				calcular(&pAFC, &pCAF, &pCONCACAF, &pCONMEBOL, &pUEFA, &pOFC);
				/*printf(
						"→ pAFC: %f.\n→ pCAF: %f.\n→ pCONCACAF: %f.\n→ pCONMEBOL: %f.\n→ pUEFA: %f.\n→ pOFC: %f.\n",
						pAFC, pCAF, pCONCACAF, pCONMEBOL, pUEFA, pOFC);*/
				break;
			case 4:
				printf("4");
				break;
			case 5:
				mostrarMenu = 0;
				break;
			}
		}
	}
	return EXIT_SUCCESS;
}
