/*
 * validaciones.c
 *
 *  Created on: 11 sep. 2022
 *      Author: fsuarez
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int esNumerica(char cadena[]) {
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if (cadena[i] < '0' || cadena[i] > '9') {
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

static int getInt(int *pResultado) {
	int ret = -1;
	char buffer[1024];

	fgets(buffer, sizeof(buffer), stdin);
	buffer[strlen(buffer) - 1] = '\0';

	if (esNumerica(buffer)) {
		*pResultado = atoi(buffer);
		ret = 1;
	}
	return ret;
}

int getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int intentos) {
	int ret = -1;
	int num;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL) {
		while (intentos > 0) {
			printf("%s", mensaje);
			if (getInt(&num)) {
				if (num <= maximo && num >= minimo) {
					*pResultado = num;
					ret = 0;
					break;
				}
			}
			intentos--;
			printf("%s", mensajeError);
		}
	}
	return ret;
}
