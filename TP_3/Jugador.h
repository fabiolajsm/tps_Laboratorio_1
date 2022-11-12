#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct {
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
} Jugador;

Jugador* jug_new(void);
Jugador* jug_newParametros(char *idStr, char *nombreCompletoStr, char *edadStr,
		char *posicionStr, char *nacionalidadStr, char *idSelccionStr);

void jug_delete(Jugador *this);

int jug_setId(Jugador *this, int id);
int jug_getId(Jugador *this, int *id);

int jug_setNombreCompleto(Jugador *this, char *nombreCompleto);
int jug_getNombreCompleto(Jugador *this, char *nombreCompleto);

int jug_setPosicion(Jugador *this, char *posicion);
int jug_getPosicion(Jugador *this, char *posicion);

int jug_setNacionalidad(Jugador *this, char *nacionalidad);
int jug_getNacionalidad(Jugador *this, char *nacionalidad);

int jug_setEdad(Jugador *this, int edad);
int jug_getEdad(Jugador *this, int *edad);

int jug_setIdSeleccion(Jugador *this, int idSeleccion);
int jug_getIdSeleccion(Jugador *this, int *idSeleccion);

int jug_compararNacionalidad(void *a, void *b);

// Listados
void controller_listarJugador(Jugador *item);
int controller_listarJugadores(LinkedList *pArrayListJugador);
int controller_listarJugadoresConvocados(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion);

// Comparaciones
int jug_compararNacionalidad(void *a, void *b);
int jug_compararEdad(void *a, void *b);
int jug_compararNombres(void *a, void *b);

#endif // jug_H_INCLUDED
