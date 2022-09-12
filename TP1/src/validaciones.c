#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXIMO_DE_JUGADORES 22
#define MAXIMO_ARQUEROS 2
#define MAXIMO_DEFENSORES 8
#define MAXIMO_MEDIOCAMPISTAS 8
#define MAXIMO_DELANTEROS 4

int numerosCargados[MAXIMO_DE_JUGADORES] = { };
int arqueros = 0;
int defensores = 0;
int mediocampistas = 0;
int delanteros = 0;

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

	if (esNumerica(buffer) == 1) {
		*pResultado = atoi(buffer);
		ret = 1;
	}
	return ret;
}

int getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo, int intentos, int validarDisponible) {
	int ret = -1;
	int num;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL) {
		while (intentos > 0) {
			printf("%s", mensaje);
			if (getInt(&num) == 1) {
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

int camisetaDisponible(int num, char *mensajeExito, char *mensajeError) {
	int ret = 0;
	if (mensajeExito != NULL && mensajeError != NULL && num > 0) {
		for (int i = 0; i < MAXIMO_DE_JUGADORES; i++) {
			if (numerosCargados[num - 1] != num) {
				ret = 1;
				numerosCargados[num - 1] = num;
				printf("%s", mensajeExito);
				break;
			} else {
				printf("%s", mensajeError);
				break;
			}
		}
	}
	return ret;
}

int posicionDisponible(int num, char *mensajeExito, char *mensajeError) {
	int ret = 0;
	if (mensajeExito != NULL && mensajeError != NULL && num > 0) {
		switch (num) {
		case 1:
			if (arqueros < MAXIMO_ARQUEROS) {
				ret = 1;
				arqueros++;
				printf("%s", mensajeExito);
			} else {
				printf("%s", mensajeError);
			}
			break;
		case 2:
			if (defensores < MAXIMO_DEFENSORES) {
				ret = 1;
				defensores++;
				printf("%s", mensajeExito);
			} else {
				printf("%s", mensajeError);
			}
			break;
		case 3:
			if (mediocampistas < MAXIMO_MEDIOCAMPISTAS) {
				ret = 1;
				mediocampistas++;
				printf("%s", mensajeExito);
			} else {
				printf("%s", mensajeError);
			}
			break;
		case 4:
			if (delanteros < MAXIMO_DELANTEROS) {
				ret = 1;
				delanteros++;
				printf("%s", mensajeExito);
			} else {
				printf("%s", mensajeError);
			}
			break;
		}
	}
	return ret;
}

void mostrarCantidadJugadores() {
	printf(
			"→ Arqueros: %d\n→ Defensores: %d\n→ Mediocampistas: %d\n→ Delanteros: %d\n",
			arqueros, defensores, mediocampistas, delanteros);
}
