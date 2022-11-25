#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "Controller.h"
#include "utn.h"

Seleccion* selec_new() {
	Seleccion *aux = NULL;
	aux = (Seleccion*) malloc(sizeof(Seleccion));
	return aux;
}

Seleccion* selec_newParametros(char *idStr, char *paisStr,
		char *confederacionStr, char *convocadosStr) {
	Seleccion *auxSeleccion = selec_new();
	int id = atoi(idStr);
	int convocados = atoi(convocadosStr);

	if (auxSeleccion != NULL) {
		if (id > 0 && paisStr != NULL && esTexto(paisStr)
				&& confederacionStr != NULL && esTexto(confederacionStr)
				&& convocados >= 0) {
			auxSeleccion->id = id;
			strcpy(auxSeleccion->pais, paisStr);
			strcpy(auxSeleccion->confederacion, confederacionStr);
			auxSeleccion->convocados = convocados;
			return auxSeleccion;
		} else {
			free(auxSeleccion);
		}
	}
	return auxSeleccion;
}

int selec_getId(Seleccion *this, int *id) {
	int retorno = 0;

	if (this != NULL && id != NULL) {
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}
int selec_getPais(Seleccion *this, char *pais) {
	int retorno = 0;

	if (this != NULL && pais != NULL) {
		strcpy(pais, this->pais);
		retorno = 1;
	}
	return retorno;
}
int selec_getConfederacion(Seleccion *this, char *confederacion) {
	int retorno = 0;

	if (this != NULL && confederacion) {
		strcpy(confederacion, this->confederacion);
		retorno = 1;
	}
	return retorno;
}

int selec_setConvocados(Seleccion *this, int convocados) {
	int retorno = 0;

	if (this != NULL && convocados >= 0) {
		this->convocados = convocados;
		retorno = 1;
	}

	return retorno;
}
int selec_getConvocados(Seleccion *this, int *convocados) {
	int retorno = 0;
	if (this != NULL && convocados != NULL) {
		*convocados = this->convocados;
		retorno = 1;
	}
	return retorno;
}

/** \brief Compara las confederaciones en la lista de selecciones para poder ordenarlas
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int selec_compararConfederaciones(void *a, void *b) {
	int retorno = -1;
	char confederacionA[30];
	char confederacionB[30];
	Seleccion *pAuxiliarA = (Seleccion*) a;
	Seleccion *pAuxiliarB = (Seleccion*) b;

	if (a != NULL && b != NULL) {

		if (selec_getConfederacion(pAuxiliarA, confederacionA)
				&& selec_getConfederacion(pAuxiliarB, confederacionB)) {
			if (strncmp(confederacionA, confederacionB, 30) > 0) {
				retorno = 1;
			} else {
				retorno = 0;
			}
		}
	}
	return retorno;
}
