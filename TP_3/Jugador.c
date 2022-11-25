#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "Controller.h"
#include "utn.h"

Jugador* jug_new(void) {
	Jugador *aux = NULL;
	aux = (Jugador*) malloc(sizeof(Jugador));
	return aux;
}

Jugador* jug_newParametros(char *idStr, char *nombreCompletoStr, char *edadStr,
		char *posicionStr, char *nacionalidadStr, char *idSelccionStr) {
	Jugador *auxJugador = jug_new();

	if (auxJugador != NULL) {
		if (jug_setId(auxJugador, atoi(idStr))
				&& jug_setNombreCompleto(auxJugador, nombreCompletoStr)
				&& jug_setEdad(auxJugador, atoi(edadStr))
				&& jug_setPosicion(auxJugador, posicionStr)
				&& jug_setNacionalidad(auxJugador, nacionalidadStr)
				&& jug_setIdSeleccion(auxJugador, atoi(idSelccionStr))) {
			return auxJugador;
		} else {
			free(auxJugador);
		}
	}
	return auxJugador;
}

int jug_setId(Jugador *this, int id) {
	int retorno = 0;

	if (this != NULL && id > 0) {
		this->id = id;
		retorno = 1;
	}
	return retorno;
}
int jug_getId(Jugador *this, int *id) {
	int retorno = 0;

	if (this != NULL && id != NULL) {
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}

int jug_setNombreCompleto(Jugador *this, char *nombreCompleto) {
	int retorno = 0;
	if (this != NULL) {
		strcpy(this->nombreCompleto, nombreCompleto);
		retorno = 1;
	}
	return retorno;
}
int jug_getNombreCompleto(Jugador *this, char *nombreCompleto) {
	int retorno = 0;

	if (this != NULL && nombreCompleto != NULL) {
		strcpy(nombreCompleto, this->nombreCompleto);
		retorno = 1;
	}
	return retorno;
}

int jug_setPosicion(Jugador *this, char *posicion) {
	int retorno = 0;

	if (this != NULL && posicion != NULL) {
		strcpy(this->posicion, posicion);
		retorno = 1;
	}
	return retorno;
}
int jug_getPosicion(Jugador *this, char *posicion) {
	int retorno = 0;
	if (this != NULL && posicion != NULL) {
		strcpy(posicion, this->posicion);
		retorno = 1;
	}
	return retorno;
}

int jug_setNacionalidad(Jugador *this, char *nacionalidad) {
	int retorno = 0;

	if (this != NULL && nacionalidad != NULL) {
		strcpy(this->nacionalidad, nacionalidad);
		retorno = 1;
	}
	return retorno;
}
int jug_getNacionalidad(Jugador *this, char *nacionalidad) {
	int retorno = 0;
	if (this != NULL && nacionalidad != NULL) {
		strcpy(nacionalidad, this->nacionalidad);
		retorno = 1;
	}
	return retorno;
}

int jug_setEdad(Jugador *this, int edad) {
	int retorno = 0;

	if (this != NULL && edad > 0) {
		this->edad = edad;
		retorno = 1;
	}
	return retorno;
}
int jug_getEdad(Jugador *this, int *edad) {
	int retorno = 0;
	if (this != NULL && edad != NULL) {
		*edad = this->edad;
		retorno = 1;
	}
	return retorno;
}

int jug_setIdSeleccion(Jugador *this, int idSeleccion) {
	int retorno = 0;

	if (this != NULL && idSeleccion >= 0) {
		this->idSeleccion = idSeleccion;
		retorno = 1;
	}
	return retorno;
}
int jug_getIdSeleccion(Jugador *this, int *idSeleccion) {
	int retorno = 0;

	if (this != NULL && idSeleccion != NULL) {
		*idSeleccion = this->idSeleccion;
		retorno = 1;
	}
	return retorno;
}

// Comparaciones
/** \brief Compara las nacionalidades en la lista jugadores para poder ordenarlas
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int jug_compararNacionalidad(void *a, void *b) {
	int retorno = -1;
	char nacionalidadA[30];
	char nacionalidadB[30];
	Jugador *pAuxiliarA = (Jugador*) a;
	Jugador *pAuxiliarB = (Jugador*) b;

	if (a != NULL && b != NULL) {

		if (jug_getNacionalidad(pAuxiliarA, nacionalidadA)
				&& jug_getNacionalidad(pAuxiliarB, nacionalidadB)) {
			if (strncmp(nacionalidadA, nacionalidadB, 30) > 0) {
				retorno = 1;
			}
		}
	}
	return retorno;
}
/** \brief Compara las edades en la lista jugadores para poder ordenarlas
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int jug_compararEdad(void *a, void *b) {
	int retorno = -1;
	int edadA;
	int edadB;
	Jugador *pAuxiliarA = (Jugador*) a;
	Jugador *pAuxiliarB = (Jugador*) b;

	if (a != NULL && b != NULL) {
		if (jug_getEdad(pAuxiliarA, &edadA)
				&& jug_getEdad(pAuxiliarB, &edadB)) {
			if (edadA > edadB) {
				retorno = 1;
			}
		}
	}
	return retorno;
}
/** \brief Compara los nombres en la lista jugadores para poder ordenarlos
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int jug_compararNombres(void *a, void *b) {
	int retorno = -1;
	char nombreA[30];
	char nombreB[30];
	Jugador *pAuxiliarA = (Jugador*) a;
	Jugador *pAuxiliarB = (Jugador*) b;

	if (a != NULL && b != NULL) {

		if (jug_getNacionalidad(pAuxiliarA, nombreA)
				&& jug_getNacionalidad(pAuxiliarB, nombreB)) {
			if (strncmp(nombreA, nombreB, 30) > 0) {
				retorno = 1;
			}
		}
	}
	return retorno;
}
