/*
 * confederaciones.h
 *
 *  Created on: 29 oct. 2022
 *      Author: fsuarez
 */

#ifndef CONFEDERACIONES_H_
#define CONFEDERACIONES_H_
#define LARGO 50

typedef struct {
	int id;
	char nombre[LARGO];
	char region[LARGO];
	int anioCreacion;
	int isEmpty;
} eConfederacion;

/**
 * @fn void inicializarConfederaciones(eConfederacion[], int)
 * @brief Esta función inicializa la data del array de confederaciones, con los valores que tenemos por defecto:
 * { "CONMEBOL", "UEFA", "AFC", "CAF", "CONCACAF", "OFC" }
 * @param confederaciones Dirección de memoria de la variable a inicializar.
 * @param largo Largo de la variable a inicializar.
 * @return void
 * */
void inicializarConfederaciones(eConfederacion confederaciones[], int largo);
/**
 * @fn void darAltaConfederacion(eConfederacion[], int)
 * @brief Esta función da de alta a una nueva confederación.
 * @param confederaciones Dirección de memoria de la variable en donde se va a guardar la nueva confederación.
 * @param largo Largo de la variable confederaciones.
 * @return void
 * */
void darAltaConfederacion(eConfederacion confederaciones[], int largo);
/**
 * @fn void darBajaConfederacion(eConfederacion[], int)
 * @brief Esta función pide el ID de una confederación y si la encuentra la da de baja.
 * @param confederaciones Variable que contiene las confederaciones.
 * @param largo Largo de la variable confederaciones.
 * @return void
 * */
void darBajaConfederacion(eConfederacion confederaciones[], int largo);
/**
 * @fn void modificarJugador(eConfederacion[], int)
 * @brief Esta función lista todas las confederaciones, pide el ID de una confederación y si la encuentra muestra un submenu que permite modificar todos sus datos.
 * @param confederaciones Variable que contiene las confederaciones existentes.
 * @param largo Largo de la variable confederaciones.
 * @return void
 * */
void modificarConfederacion(eConfederacion confederaciones[], int largo);

#endif /* CONFEDERACIONES_H_ */
