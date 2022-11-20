/*
 * informes.h
 *
 *  Created on: 29 oct. 2022
 *      Author: fsuarez
 */

#ifndef INFORMES_H_
#define INFORMES_H_

/**
 * @fn void informarDatos(eJugador[], int)
 * @brief Esta función muestra un submenu que permite elegir de que manera mostrar por consola los datos de los jugadores y los datos de sus confederaciones.
 * @param jugadores Variable que contiene los jugadores.
 * @param confederaciones Variable que contiene las confederaciones existentes.
 * @param largoJ Largo de la variable jugadores.
 * @param largoC Largo de la variable confederaciones.
 * @return void
 * */
void informarDatos(eJugador jugadores[], eConfederacion confederaciones[],
		int largoJ, int largoC);

#endif /* INFORMES_H_ */
