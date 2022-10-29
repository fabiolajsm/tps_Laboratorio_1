/*
 * jugadores.h
 *
 *  Created on: 15 oct. 2022
 *      Author: fsuarez
 */

#ifndef JUGADORES_H_
#define JUGADORES_H_
#define LARGO 50

typedef struct {
	int id;
	char nombre[LARGO];
	char region[LARGO];
	int anioCreacion;
} eConfederacion;

typedef struct {
	int id;
	char nombre[LARGO];
	char posicion[LARGO];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
} eJugador;

/**
 * @fn void inicializarJugadores(eJugador[], int)
 * @brief Esta función inicializa la data del array de jugadores, poniendo todos los "isEmpty" en 1, para indicar que si está vacío.
 * @param jugadores Dirección de memoria de la variable a inicializar.
 * @param largo Largo de la variable a inicializar.
 * @return void
 * */
void inicializarJugadores(eJugador jugadores[], int largo);
/**
 * @fn void darAltaJugador(eArticulo[], int)
 * @brief Esta función da de alta a un jugador.
 * @param jugadores Dirección de memoria de la variable en donde se va a guardar cada jugador.
 * @param largo Largo de la variable jugadores.
 * @return void
 * */
void darAltaJugador(eJugador jugadores[], int largo);
/**
 * @fn void darBajaJugador(eJugador[], int)
 * @brief Esta función pide el ID de un jugador y si lo encuentra lo da de baja.
 * @param jugadores Variable que contiene los jugadores.
 * @param largo Largo de la variable jugadores.
 * @return void
 * */
void darBajaJugador(eJugador jugadores[], int largo);
/**
 * @fn void modificarJugador(eJugador[], int)
 * @brief Esta función lista todos los jugadores y pide el ID de un jugador, si lo encuentra muestra un submenu que permite modificar todos sus datos.
 * @param jugadores Variable que contiene los jugadores.
 * @param largo Largo de la variable jugadores.
 * @return void
 * */
void modificarJugador(eJugador jugadores[], int largo);
/**
 * @fn int existenJugadores(eJugador[], int)
 * @brief Esta función verifica que existan jugadores cargados.
 * @param jugadores Variable que contiene los jugadores.
 * @param largo Largo de la variable jugadores.
 * @return retorna 1 si hay jugadores y 0 si no.
 * */
int existenJugadores(eJugador jugadores[], int largo);
/**
 * @fn void mostrarJugadores(eJugador[], int)
 * @brief Esta función imprime por consola la variable jugadores mostrándolos en una tabla.
 * @param jugadores Variable que contiene los jugadores.
 * @param largo Largo de la variable jugadores.
 * @return void.
 * */
void mostrarJugadores(eJugador jugadores[], int largo);

#endif /* JUGADORES_H_ */
