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

#endif /* VALIDACIONES_H_ */
