/*
 * validaciones.h
 *
 *  Created on: 11 sep. 2022
 *      Author: fsuarez
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo, int intentos);
int camisetaDisponible(int num, char *mensajeExito, char *mensajeError);
int posicionDisponible(int num, char *mensajeExito, char *mensajeError);
//esto no es validacion deberia sacarlo de aqui
void mostrarCantidadJugadores();

#endif /* VALIDACIONES_H_ */
