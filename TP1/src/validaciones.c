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

int obtenerNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int intentos, int validarDisponible) {
	int ret = -1;
	int num;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL) {
		while (intentos > 0) {
			printf("%s", mensaje);
			if (obtenerInt(&num) == 0) {
				if (num <= maximo && num >= minimo) {
					*pResultado = num;
					ret = 0;
					break;
				}
			}
			intentos--;
			if (intentos < 1) {
				printf("Error. Intentos acabados, intente mas tarde.\n");
			} else {
				printf("%s", mensajeError);
			}
		}
	}
	return ret;
}
