/*
 * utn.c
 *
 *  Created on: 15 oct. 2022
 *      Author: fsuarez
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int esNumero(char cadena[]) {
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

static int obtenerInt(int *pResultado) {
	int ret = -1;
	char buffer[1024];

	fgets(buffer, sizeof(buffer), stdin);
	buffer[strlen(buffer) - 1] = '\0';

	if (esNumero(buffer) == 1) {
		*pResultado = atoi(buffer);
		ret = 0;
	}
	return ret;
}

int utn_obtenerNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo) {
	int ret = -1;
	int num;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL) {
		while (ret == -1) {
			printf("%s", mensaje);
			if (obtenerInt(&num) == 0) {
				if (num <= maximo && num >= minimo) {
					*pResultado = num;
					ret = 0;
					break;
				}
			}
			printf("%s", mensajeError);
		}
	}
	return ret;
}

static int obtenerShort(short *pResultado) {
	int ret = -1;
	char buffer[1024];

	fgets(buffer, sizeof(buffer), stdin);
	buffer[strlen(buffer) - 1] = '\0';

	if (esNumero(buffer) == 1) {
		*pResultado = atoi(buffer);
		ret = 0;
	}
	return ret;
}

int utn_obtenerNumeroShort(short *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo) {
	int ret = -1;
	short num;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL) {
		while (ret == -1) {
			printf("%s", mensaje);
			if (obtenerShort(&num) == 0) {
				if (num <= maximo && num >= minimo) {
					*pResultado = num;
					ret = 0;
					break;
				}
			}
			printf("%s", mensajeError);
		}
	}
	return ret;
}

static int esTexto(char *cadena) {
	if (cadena == NULL || strlen(cadena) < 1)
		return 0;

	for (int i = 0; cadena[i] != '\0'; i++) {
		if ((cadena[i] < 'A' || cadena[i] > 'Z')
				&& (cadena[i] < 'a' || cadena[i] > 'z') && cadena[i] != ' ') {
			// Acá no es texto
			return 0;
		}
	}

	return 1;
}

static int obtenerString(char *pResultado, int longitud) {
	int retorno = -1;
	char buffer[1024];
	fgets(buffer, sizeof(buffer), stdin);

	if (pResultado != NULL && longitud > 0) {
		if (buffer[strnlen(buffer, sizeof(buffer)) - 1] == '\n') {
			buffer[strnlen(buffer, sizeof(buffer)) - 1] = '\0';
		}
		if (strnlen(buffer, sizeof(buffer)) <= longitud && esTexto(buffer)) {
			strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
	}
	return retorno;
}

int utn_obtenerTexto(char *pResultado, int largo, char *mensaje,
		char *mensajeError, int maxCaracteres) {
	int retorno = -1;
	int esTextoValido = 0;
	char auxTexto[1024];

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL) {
		while (esTextoValido == 0) {
			printf("%s", mensaje);
			if (obtenerString(auxTexto, sizeof(auxTexto)) == 0
					&& strnlen(auxTexto, sizeof(auxTexto)) <= maxCaracteres) {
				strncpy(pResultado, auxTexto, largo);
				esTextoValido = 1;
				retorno = 0;
				break;

			}
			printf("%s", mensajeError);
		}
	}
	return retorno;
}

static int esFlotante(char cadena[]) {
	int retorno = 1;
	int i = 0;
	int cantidadPuntos = 0;

	if (cadena == NULL || strlen(cadena) < 1)
		return 0;

	while (cadena[i] != '\0') {
		if (cadena[i] == '.' && cantidadPuntos < 1) {
			cantidadPuntos++;
		} else {
			if (cadena[i] < '0' || cadena[i] > '9' || cantidadPuntos > 1) {
				retorno = 0;
				break;
			}
		}
		i++;
	}
	return retorno;
}

static int obtenerFloat(float *pResultado) {
	int ret = -1;
	char buffer[1024];

	fgets(buffer, sizeof(buffer), stdin);
	buffer[strlen(buffer) - 1] = '\0';

	if (esFlotante(buffer) == 1) {
		*pResultado = atof(buffer);
		ret = 0;
	}
	return ret;
}

int utn_obtenerFlotante(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo) {
	int ret = -1;
	float num;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL) {
		while (ret == -1) {
			printf("%s", mensaje);
			if (obtenerFloat(&num) == 0) {
				if (num <= maximo && num >= minimo) {
					*pResultado = num;
					ret = 0;
					break;
				}
			}
			printf("%s", mensajeError);
		}
	}
	return ret;
}
