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

// Listados
//Confederaciones: AFC, CAF, CONCACAF, CONMEBOL, UEFA.
static int controller_ObtenerConfederacion(char *pConfederacion,
		int idSeleccion) {
	int retorno = -1;
	if (pConfederacion != NULL) {
		switch (idSeleccion) {
		case 2:
		case 4:
		case 9:
		case 21:
		case 22:
		case 27:
			strcpy(pConfederacion, "AFC");
			break;
		case 7:
		case 18:
		case 23:
		case 28:
		case 31:
			strcpy(pConfederacion, "CAF");
			break;
		case 8:
		case 10:
		case 15:
		case 24:
			strcpy(pConfederacion, "CONCACAF");
			break;
		case 3:
		case 6:
		case 13:
		case 32:
			strcpy(pConfederacion, "CONMEBOL");
			break;
		case 1:
		case 5:
		case 11:
		case 12:
		case 14:
		case 16:
		case 17:
		case 19:
		case 20:
		case 25:
		case 26:
		case 29:
		case 30:
			strcpy(pConfederacion, "UEFA");
			break;
		default:
			strcpy(pConfederacion, "No esta convocado");
			break;
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Listar jugador
 *
 * \param item Jugador*
 * \return void
 *
 */
void controller_listarJugador(Jugador *item) {
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	char textoSeleccion[30];

	if (item != NULL && jug_getId(item, &id) == 1
			&& jug_getNombreCompleto(item, nombreCompleto) == 1
			&& jug_getEdad(item, &edad) == 1
			&& jug_getPosicion(item, posicion) == 1
			&& jug_getNacionalidad(item, nacionalidad) == 1
			&& jug_getIdSeleccion(item, &idSeleccion) == 1
			&& controller_ObtenerConfederacion(textoSeleccion, idSeleccion)
					== 0) {
		printf("| %*d | %*s | %*d | %*s | %*s | %*s  |\n", -3, id, -28,
				nombreCompleto, -5, edad, -24, posicion, -18, nacionalidad, -17,
				textoSeleccion);
	}
}

/** \brief Listar jugadores
 *
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList *pArrayListJugador) {
	int retorno = -1;
	int largo = ll_len(pArrayListJugador);

	if (pArrayListJugador != NULL && largo > 0) {
		printf("\t\t\t\t\t- Listado de Jugadores -\n");
		printf(
				"==================================================================================================================\n");
		printf("|%*s|%*s|%*s|%*s|%*s|%s|\n", -5, " ID", -30, " NOMBRE", -7,
				" EDAD", -27, " POSICIÓN", -20, " NACIONALIDAD",
				" SELECCIÓN          ");
		printf(
				"------------------------------------------------------------------------------------------------------------------\n");
		for (int i = 0; i < largo; i++) {
			controller_listarJugador((Jugador*) ll_get(pArrayListJugador, i));
		}
		printf(
				"==================================================================================================================\n");
		retorno = 0;
	}

	return retorno;
}

/** \brief Listar convocados
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarJugadoresConvocados(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion) {
	int retorno = -1;
	int largo = ll_len(pArrayListJugador);
	Jugador *auxPunteroJugador = NULL;
	int idSeleccion;
	int noHayJugadoresConvocados = 1;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL && largo > 0) {
		printf("\t\t\t\t\t- Jugadores convocados -\n");
		printf(
				"==================================================================================================================\n");
		printf("|%*s|%*s|%*s|%*s|%*s|%s|\n", -5, " ID", -30, " NOMBRE", -7,
				" EDAD", -27, " POSICIÓN", -20, " NACIONALIDAD",
				" SELECCIÓN          ");
		printf(
				"------------------------------------------------------------------------------------------------------------------\n");
		for (int i = 0; i < largo; i++) {
			auxPunteroJugador = (Jugador*) ll_get(pArrayListJugador, i);
			if (auxPunteroJugador != NULL
					&& jug_getIdSeleccion(auxPunteroJugador, &idSeleccion)
							== 1) {
				if (controller_obtenerIndexSeleccionPorId(pArrayListSeleccion,
						idSeleccion) != -1) {
					noHayJugadoresConvocados = 0;
					controller_listarJugador(auxPunteroJugador);
				}
			}
		}
		if (noHayJugadoresConvocados == 1) {
			printf("| No hay jugadores convocados\n");
		}
		printf(
				"==================================================================================================================\n");
		retorno = 0;
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
