#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "utn.h"
#define ERROR_NO_HAY_CARGA "Error. No se han cargado jugadores ni selecciones.\n"

int main() {
	setbuf(stdout, NULL);
	int mostrarMenu = 1;
	int esOpcionValida;
	int opcion;
	int confirmacion;
	int hayCambios = 0;
	static int cargaronJugadores = 0;
	static int cargaronSelecciones = 0;
	static int cargaronConvocados = 0;
	LinkedList *listaJugadores = ll_newLinkedList();
	LinkedList *listaSelecciones = ll_newLinkedList();
	LinkedList *listaJugadoresConvocados = ll_newLinkedList();

	while (mostrarMenu) {
		esOpcionValida =
				utn_obtenerNumero(&opcion,
						"Seleccione una opción:\n1. CARGA DE ARCHIVOS.\n2. ALTA DE JUGADOR.\n3. MODIFICACIÓN DE JUGADOR.\n4. BAJA DE JUGADOR.\n5. LISTADOS.\n6. CONVOCAR JUGADORES.\n7. ORDENAR Y LISTAR.\n8. GENERAR ARCHIVO BINARIO.\n9. CARGAR ARCHIVO BINARIO.\n10. GUARDAR ARCHIVOS .CSV .\n11. SALIR.\n",
						"Error. Opción inválida.\n", 1, 11);
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
						hayCambios = 1;
						printf("Se dio de alta exitosamente el jugador.\n");
					}
				} else {
					printf(
							"Error. No se puede dar de alta si todavía no se han cargado jugadores ni selecciones\n");
				}
				break;
			case 3:
				if (cargaronJugadores == 1 && cargaronSelecciones == 1) {
					if (controller_editarJugador(listaJugadores) == 0) {
						hayCambios = 1;
					} else {
						printf("Error.\n");
					}
				} else {
					printf(
							"Error. No se puede modificar si no se han cargado jugadores ni selecciones\n");
				}
				break;
			case 4:
				if (cargaronJugadores == 1 && cargaronSelecciones == 1) {
					if (controller_removerJugador(listaJugadores,
							listaSelecciones) == 0) {
						hayCambios = 1;
					} else {
						printf("Error. Intente mas tarde\n");
					}
				} else {
					printf(
							"Error. No se puede dar de baja a un jugador si no se han cargado jugadores ni selecciones\n");
				}
				break;
			case 5:
				if (cargaronJugadores == 1 && cargaronSelecciones == 1) {
					controller_listados(listaJugadores, listaSelecciones);
				} else {
					printf(ERROR_NO_HAY_CARGA);
				}
				break;
			case 6:
				if (cargaronJugadores == 1 && cargaronSelecciones == 1) {
					if (controller_convocarJugadores(listaJugadores,
							listaSelecciones) == 0) {
						hayCambios = 1;
					}
				} else {
					printf(ERROR_NO_HAY_CARGA);
				}
				break;
			case 7:
				if (cargaronJugadores == 1 && cargaronSelecciones == 1) {
					if (controller_ordenarYListar(listaJugadores,
							listaSelecciones) == -1) {
						printf("Error. Intente mas tarde\n");
					}
				} else {
					printf(ERROR_NO_HAY_CARGA);
				}
				break;
			case 8:
				if (cargaronJugadores == 1 && cargaronSelecciones == 1) {
					if (controller_generarJugadoresDesdeBinario(
							"jugadoresConvocados.bin", listaJugadores) == 0) {
						cargaronConvocados++;
						printf("Archivo generado exitosamente\n");
					} else {
						printf(
								"Esta confederación no tiene jugadores convocados\n");
					}
				} else {
					printf(ERROR_NO_HAY_CARGA);
				}
				break;
			case 9:
				if (!cargaronJugadores && !cargaronSelecciones) {
					printf(ERROR_NO_HAY_CARGA);
				} else if (!cargaronConvocados) {
					printf(
							"Error. No se generó el archivo binario de jugadores convocados\n");
				} else {
					if (controller_cargarJugadoresDesdeBinario(
							"jugadoresConvocados.bin", listaJugadoresConvocados)
							== -1) {
						printf("Error no se pudo leer el archivo\n");
					} else {
						if (controller_listarJugadores(listaJugadoresConvocados)
								== -1) {
							printf(
									"Error, no se pudieron listar los jugadores convocados\n");
						}
					}
				}
				break;
			case 10:
				if (!cargaronJugadores && !cargaronSelecciones) {
					printf(ERROR_NO_HAY_CARGA);
				}
				if (hayCambios) {
					if (controller_guardarJugadoresModoTexto("jugadores.csv",
							listaJugadores) == 0
							&& controller_guardarSeleccionesModoTexto(
									"selecciones.csv", listaSelecciones) == 0) {
						hayCambios = 0;
						printf("Se guardaron exitosamente los cambios\n");
					}
				} else {
					printf(
							"No se puede volver a guardar archivos, si no se han hecho cambios\n");
				}
				break;
			case 11:
				if (hayCambios) {
					if (utn_obtenerNumero(&confirmacion,
							"Hay cambios sin guardar. Seguro desea salir?\n1. Si.\n2. No.\n",
							"Error. Opción inválida, tiene que elegir un número del 1 al 2.\n",
							1, 2) == 0 && confirmacion == 1) {
						mostrarMenu = 0;
					}
				} else {
					mostrarMenu = 0;
					printf("Hasta luego;D\n");
				}
				break;
			}
		}
	}

	return EXIT_SUCCESS;
}

