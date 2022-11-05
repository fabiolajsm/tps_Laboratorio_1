#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "utn.h"

int main() {
	setbuf(stdout, NULL);
	int mostrarMenu = 1;
	int esOpcionValida;
	int opcion;
	int confirmacion;
	static int cargaronJugadores = 0;
	static int cargaronSelecciones = 0;
	LinkedList *listaJugadores = ll_newLinkedList();
	LinkedList *listaSelecciones = ll_newLinkedList();
	/*			controller_cargarJugadoresDesdeTexto("jugadores.csv",
	 listaJugadores);*/
	while (mostrarMenu) {
		esOpcionValida =
				utn_obtenerNumero(&opcion,
						"Seleccione una opción:\n1. CARGA DE ARCHIVOS.\n2. ALTA DE JUGADOR.\n3. MODIFICACIÓN DE JUGADOR.\n4. BAJA DE JUGADOR.\n5. LISTADOS.\n6. CONVOCAR JUGADORES.\n7. ORDENAR Y LISTAR.\n8. SALIR.\n",
						"Error. Opción inválida.\n", 1, 8);
		if (esOpcionValida == 0) {
			switch (opcion) {
			case 1:
				if (cargaronJugadores == 1 && cargaronSelecciones == 1) {
					printf("Ya se cargaron los archivos.\n");
				} else {
					if (controller_cargarJugadoresDesdeTexto("jugadores.csv",
							listaJugadores) == 0
							&& controller_cargarSeleccionesDesdeTexto(
									"selecciones.csv", listaSelecciones) == 0) {
						cargaronJugadores = 1;
						cargaronSelecciones = 1;
						printf("Se han cargado exitosamente los archivos.\n");
					} else {
						printf("Error. No se pudieron cargar los archivos.\n");
					}
				}
				break;
			case 2:
				if (cargaronJugadores == 1 && cargaronSelecciones == 1) {
					if (controller_agregarJugador(listaJugadores) == -1) {
						printf("Error, no se pudo dar de alta a el jugador.\n");
					} else {
						printf("Se dio de alta exitosamente el jugador.\n");
					}
				} else {
					printf(
							"Error. No se puede dar de alta si todavía no se han cargado jugadores ni selecciones\n");
				}
				break;
			case 3:
				if (cargaronJugadores == 1 && cargaronSelecciones == 1) {
					controller_editarJugador(listaJugadores);
				} else {
					printf(
							"Error. No se puede modificar si no se han cargado jugadores ni selecciones\n");
				}
				break;
			case 4:
				if (cargaronJugadores == 1 && cargaronSelecciones == 1) {
					controller_removerJugador(listaJugadores, listaSelecciones);
				} else {
					printf(
							"Error. No se puede dar de baja a un jugador si no se han cargado jugadores ni selecciones\n");
				}
				break;
			case 5:
				if (cargaronJugadores == 1 && cargaronSelecciones == 1) {
					controller_listados(listaJugadores, listaSelecciones);
				} else {
					printf(
							"Error. No se han cargado jugadores ni selecciones.\n");
				}
				break;
			case 6:
				if (cargaronJugadores == 1 && cargaronSelecciones == 1) {
					controller_convocarJugadores(listaJugadores,
							listaSelecciones);
				} else {
					printf(
							"Error. No se han cargado jugadores ni selecciones.\n");
				}
				break;
			case 7:
				if (cargaronJugadores == 1 && cargaronSelecciones == 1) {
					controller_ordenarYListar(listaJugadores,
							listaSelecciones);
				} else {
					printf(
							"Error. No se han cargado jugadores ni selecciones.\n");
				}
				break;
			case 8:
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

