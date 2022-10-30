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

void darAltaConfederacion(eConfederacion confederaciones[], int largo);
void darBajaConfederacion(eConfederacion confederaciones[], int largo);
void modificarConfederacion(eConfederacion confederaciones[], int largo);

#endif /* CONFEDERACIONES_H_ */
