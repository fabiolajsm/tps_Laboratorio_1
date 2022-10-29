#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "jugadores.h"
#include "informes.h"
#define CANTIDAD_JUGADORES 10

int main(void) {
	int mostrarMenu = 1;
	int esOpcionValida;
	int opcion;
	int confirmacion;

	eJugador jugadores[CANTIDAD_JUGADORES];
	inicializarJugadores(jugadores, CANTIDAD_JUGADORES); // Tiene que ser hasta 3000 jugadores y hay 6 confederaciones

	while (mostrarMenu) {
		// Pedimos al usuario que ingrese una opción:
		esOpcionValida =
				utn_obtenerNumero(&opcion,
						"Seleccione una opción:\n1. ALTA DE JUGADOR.\n2. BAJA DE JUGADOR.\n3. MODIFICACIÓN DE JUGADOR.\n4. INFORMES.\n5. SALIR.\n",
						"Error. Opción inválida.\n", 1, 5);
		if (esOpcionValida == 0) {
			switch (opcion) {
			case 1:
				darAltaJugador(jugadores, CANTIDAD_JUGADORES);
				break;
			case 2:
				darBajaJugador(jugadores, CANTIDAD_JUGADORES);
				break;
			case 3:
				modificarJugador(jugadores, CANTIDAD_JUGADORES);
				break;
			case 4:
				informarDatos(jugadores, CANTIDAD_JUGADORES);
				break;
			case 5:
				if (utn_obtenerNumero(&confirmacion,
						"Seguro desea salir?\n1. Si.\n2. No.\n",
						"Error. Opción inválida, tiene que elegir un número del 1 al 2.\n",
						1, 2) == 0 && confirmacion == 1) {
					mostrarMenu = 0;
				}
				break;
			}
		}
	}
	return EXIT_SUCCESS;
}
