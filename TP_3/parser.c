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
 * \param pListaJugadores LinkedList*
 * \return int
 */

int parserJugadorDesdeTexto(FILE *pArchivo, LinkedList *pListaJugadores) {
	int retorno = -1;
	Jugador *auxPunteroJugador = NULL;
	char id[LARGO];
	char nombreCompleto[100];
	char edad[LARGO];
	char posicion[LARGO];
	char nacionalidad[LARGO];
	char idSeleccion[LARGO];
	int lecturaCaracteres;

	if (pArchivo != NULL && pListaJugadores != NULL) {
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
						&& ll_add(pListaJugadores, auxPunteroJugador) == 0) {
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
 * \param pListaJugadores LinkedList*
 * \return int
 *
 */
int parserJugadorDesdeBinario(FILE *pArchivo, LinkedList *pListaJugadores) {
	int retorno = -1;
	Jugador *pAuxJugador;
	int cantidadElementos;
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;

	if (pListaJugadores != NULL && pArchivo != NULL) {
		while (!feof(pArchivo)) {
			pAuxJugador = jug_new();
			cantidadElementos = fread(pAuxJugador, sizeof(Jugador), 1,
					pArchivo);
			if (pAuxJugador != NULL) {
				if (cantidadElementos == 1 && jug_getId(pAuxJugador, &id) == 1
						&& jug_getNombreCompleto(pAuxJugador, nombreCompleto)
								== 1 && jug_getEdad(pAuxJugador, &edad) == 1
						&& jug_getPosicion(pAuxJugador, posicion) == 1
						&& jug_getNacionalidad(pAuxJugador, nacionalidad) == 1
						&& jug_getIdSeleccion(pAuxJugador, &idSeleccion) == 1) {
					if (ll_add(pListaJugadores, pAuxJugador) == 0) {
						retorno = 0;
					} else {
						free(pAuxJugador);
						break;
					}
				}
			}
		}
	}
	return retorno;
}

/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pListaSelecciones LinkedList*
 * \return int
 *
 */
int parserSeleccionDesdeTexto(FILE *pArchivo, LinkedList *pListaSelecciones) {
	int retorno = -1;
	Seleccion *auxPunteroSeleccion;
	char id[LARGO];
	char pais[100];
	char confederacion[LARGO];
	char convocados[LARGO];
	int lecturaCaracteres;

	if (pArchivo != NULL && pListaSelecciones != NULL) {
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
						&& ll_add(pListaSelecciones, auxPunteroSeleccion)
								== 0) {
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
/** \brief Parsea los datos de los jugadores y genera un archivo en formato texto con su información
 *
 * \param path char*
 * \param pListaJugadores LinkedList*
 * \return int
 *
 */
int parserGuardarJugadoresFormatoTexto(FILE *pArchivo,
		LinkedList *pListaJugadores) {
	int retorno = -1;
	Jugador *auxPunteroJugador;
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[LARGO];
	char nacionalidad[LARGO];
	int idSeleccion;

	if (pArchivo != NULL && pListaJugadores != NULL) {
		fprintf(pArchivo,
				"id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion\n");
		for (int i = 0; i < ll_len(pListaJugadores); i++) {
			auxPunteroJugador = ll_get(pListaJugadores, i);
			if (auxPunteroJugador != NULL) {
				if (jug_getId(auxPunteroJugador, &id) == 1
						&& jug_getNombreCompleto(auxPunteroJugador,
								nombreCompleto) == 1
						&& jug_getEdad(auxPunteroJugador, &edad) == 1
						&& jug_getPosicion(auxPunteroJugador, posicion) == 1
						&& jug_getNacionalidad(auxPunteroJugador, nacionalidad)
								== 1
						&& jug_getIdSeleccion(auxPunteroJugador, &idSeleccion)
								== 1) {
					fprintf(pArchivo, "%d,%s,%d,%s,%s,%d\n", id, nombreCompleto,
							edad, posicion, nacionalidad, idSeleccion);
					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

/** \brief Parsea los datos de las selecciones y genera un archivo en formato texto con su información
 *
 * \param path char*
 * \param pListaSelecciones LinkedList*
 * \return int
 *
 */
int parserGuardarSeleccionesFormatoTexto(FILE *pArchivo,
		LinkedList *pListaSelecciones) {
	int retorno = -1;
	Seleccion *auxPunteroSeleccion = NULL;
	int id;
	char pais[LARGO];
	char confederacion[LARGO];
	int convocados;

	if (pArchivo != NULL && pListaSelecciones != NULL) {
		fprintf(pArchivo, "id,pais,confederacion,convocados\n");
		for (int i = 0; i < ll_len(pListaSelecciones); i++) {
			auxPunteroSeleccion = ll_get(pListaSelecciones, i);
			if (selec_getId(auxPunteroSeleccion, &id)
					&& selec_getPais(auxPunteroSeleccion, pais)
					&& selec_getConfederacion(auxPunteroSeleccion,
							confederacion)
					&& selec_getConvocados(auxPunteroSeleccion, &convocados)) {
				fprintf(pArchivo, "%d,%s,%s,%d\n", id, pais, confederacion,
						convocados);
				retorno = 0;
			}
		}
	}

	return retorno;
}
