#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "utn.h"
#define LARGO 30

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */

int parserJugadorDesdeTexto(FILE *pArchivo, LinkedList *pArrayListJugador) {
	int retorno = -1;
	Jugador *auxPunteroJugador = NULL;
	char id[LARGO];
	char nombreCompleto[100];
	char edad[LARGO];
	char posicion[LARGO];
	char nacionalidad[LARGO];
	char idSeleccion[LARGO];
	int lecturaCaracteres;

	if (pArchivo != NULL && pArrayListJugador != NULL) {
		// lectura fantasma
		lecturaCaracteres = fscanf(pArchivo,
				"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombreCompleto,
				edad, posicion, nacionalidad, idSeleccion);

		while (feof(pArchivo) == 0) {
			// vuelvo a leer en cada vuelta
			lecturaCaracteres = fscanf(pArchivo,
					"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,
					nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
			if (lecturaCaracteres == 6) {
				auxPunteroJugador = jug_newParametros(id, nombreCompleto, edad,
						posicion, nacionalidad, idSeleccion);
				if (auxPunteroJugador != NULL
						&& ll_add(pArrayListJugador, auxPunteroJugador) == 0) {
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE *pArchivo, LinkedList *pArrayListJugador) {
	int retorno = -1;
	Jugador *pAuxJugador = jug_new();
	int cantidadElementos;
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;

	if (pArrayListJugador != NULL && pArchivo != NULL) {
		while (!feof(pArchivo)) {
			cantidadElementos = fread(pAuxJugador, sizeof(Jugador), 1,
					pArchivo);
			if (cantidadElementos == 1 && jug_getId(pAuxJugador, &id) == 1
					&& jug_getNombreCompleto(pAuxJugador, nombreCompleto) == 1
					&& jug_getEdad(pAuxJugador, &edad) == 1
					&& jug_getPosicion(pAuxJugador, posicion) == 1
					&& jug_getNacionalidad(pAuxJugador, nacionalidad) == 1
					&& jug_getIdSeleccion(pAuxJugador, &idSeleccion) == 1) {
				if (ll_add(pArrayListJugador, pAuxJugador) == 0) {
					retorno = 0;
				}
			} else {
				free(pAuxJugador);
				break;
			}
		}
	}

	return retorno;
}

/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
/*	int id;
 char pais[30];
 char confederacion[30];
 int convocados;*/
int parserSeleccionDesdeTexto(FILE *pArchivo, LinkedList *pArrayListSeleccion) {
	int retorno = -1;
	Seleccion *auxPunteroSeleccion;
	char id[LARGO];
	char pais[100];
	char confederacion[LARGO];
	char convocados[LARGO];
	int lecturaCaracteres;

	if (pArchivo != NULL && pArrayListSeleccion != NULL) {
		// leemos los caracteres
		lecturaCaracteres = fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", id,
				pais, confederacion, convocados);

		while (feof(pArchivo) == 0) {
			// vuelvo a leer en cada vuelta
			lecturaCaracteres = fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^\n]\n",
					id, pais, confederacion, convocados);
			if (lecturaCaracteres == 4) {
				auxPunteroSeleccion = selec_newParametros(id, pais,
						confederacion, convocados);
				if (auxPunteroSeleccion != NULL
						&& ll_add(pArrayListSeleccion, auxPunteroSeleccion)
								== 0) {
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}