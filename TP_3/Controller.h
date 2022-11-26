#include "Jugador.h"
#include "Seleccion.h"

// Archivos
int controller_cargarJugadoresDesdeTexto(char *path,
		LinkedList *pArrayListJugador);
int controller_generarJugadoresDesdeBinario(char *path,
		LinkedList *pArrayListJugador);
int controller_cargarJugadoresDesdeBinario(char *path,
		LinkedList *pArrayListJugador);
int controller_guardarJugadoresModoTexto(char *path,
		LinkedList *pArrayListJugador);
int controller_guardarJugadoresModoBinario(char *path,
		LinkedList *pArrayListJugador);
int controller_cargarSeleccionesDesdeTexto(char *path,
		LinkedList *pArrayListSeleccion);
int controller_guardarSeleccionesModoTexto(char *path,
		LinkedList *pArrayListSeleccion);

// Jugadores y selecciones
int controller_agregarJugador(LinkedList *pArrayListJugador);
int controller_editarJugador(LinkedList *pListaJugadores,
		LinkedList *pListaSelecciones);
int controller_removerJugador(LinkedList *pListaJugadores,
		LinkedList *pListaSelecciones);
int controller_obtenerIndexSeleccionPorId(LinkedList *pArrayListSeleccion,
		int idSeleccion);
int controller_convocarJugadores(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion, LinkedList *pArrayListConvocados);
int controller_editarSeleccion(LinkedList *pArrayListSeleccion);

// Ordenados y listados
void controller_listados(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion, LinkedList *pArrayListConvocados);

int controller_listarJugadores(LinkedList *pListaJugadores,
		LinkedList *pListaSelecciones);
int controller_listarJugadoresConvocados(LinkedList *pListaJugadoresConvocados,
		LinkedList *pListaSelecciones);
int controller_listarSelecciones(LinkedList *pArrayListSeleccion);

int controller_ordenarJugadores(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion);
int controller_ordenarSelecciones(LinkedList *pArrayListSeleccion);
int controller_ordenarYListar(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion);
