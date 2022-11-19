/*
 * jugadores.c
 *
 *  Created on: 15 oct. 2022
 *      Author: fsuarez
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "jugadores.h"
#include "confederaciones.h"
#define ERROR_TEXTO "Error. Tiene que ingresar un texto alfabético que no tenga más de 50 caracteres\n"
#define ID_NO_ENCONTRADO "Error. El ID no fue encontrado.\n"
#define NO_HAY_JUGADORES "Error. No existen jugadores.\n"
#define MODIFICACION_EXITOSA "Se modificó exitosamente.\n"
#define ID_MAXIMO 3000

void inicializarJugadores(eJugador jugadores[], int largo) {
	if (jugadores != NULL && largo > 0) {
		for (int i = 0; i < largo; i++) {
			// True 1 para "esta vacio" y false 0 para "no está vacío"
			jugadores[i].isEmpty = 1;
		}
	}
}

static int buscarPosicionVacia(eJugador jugadores[], int largo) {
	int ret = -1;
	if (jugadores != NULL && largo > 0) {
		for (int i = 0; i < largo; i++) {
			if (jugadores[i].isEmpty == 1) {
				// Si está vacío retornamos la posición del item.
				ret = i;
				break;
			}
		}
	}
	return ret;
}

static int setPosicion(char *pPosicion, int opcion) {
	int retorno = -1;
	if (pPosicion != NULL && opcion > 0) {
		switch (opcion) {
		case 1:
			strcpy(pPosicion, "Arquero");
			break;
		case 2:
			strcpy(pPosicion, "Defensa");
			break;
		case 3:
			strcpy(pPosicion, "Mediocampo");
			break;
		case 4:
			strcpy(pPosicion, "Delantero");
			break;
		}
		retorno = 0;
	}
	return retorno;
}
static int setConfederacion(int *pConfederacion, int opcion) {
	int retorno = -1;
	if (pConfederacion != NULL && opcion > 0) {
		switch (opcion) {
		case 1:
			*pConfederacion = 100;
			break;
		case 2:
			*pConfederacion = 101;
			break;
		case 3:
			*pConfederacion = 102;
			break;
		case 4:
			*pConfederacion = 103;
			break;
		case 5:
			*pConfederacion = 104;
			break;
		case 6:
			*pConfederacion = 105;
			break;
		}
		retorno = 0;
	}
	return retorno;
}

void darAltaJugador(eJugador jugadores[], int largo) {
	int posicionVacia = buscarPosicionVacia(jugadores, largo);
	eJugador auxJugador;
	static int idJugador = 1;
	int posicion;
	int confederacion;

	if (jugadores != NULL && largo > 0 && posicionVacia != -1) {
		auxJugador.id = idJugador;
		if (utn_obtenerTexto(auxJugador.nombre, 50,
				"Ingresa nombre completo:\n",
				ERROR_TEXTO, 50) == 0
				&& utn_obtenerNumero(&posicion,
						"Ingrese que posición quiere jugar:\n1. Arquero.\n2. Defensa.\n3. Mediocampo.\n4. Delantero.\n",
						"Error. Tienes que seleccionar el número de la posición que quieres jugar (opciones del 1 al 4).\n",
						1, 4) == 0
				&& utn_obtenerNumeroShort(&auxJugador.numeroCamiseta,
						"Ingrese número de camiseta:\n",
						"Error. Tiene ingresar un número del 1 al 22, en formato numérico y sin decimales.\n",
						1, 22) == 0
				&& utn_obtenerNumero(&confederacion,
						"Confederaciones disponibles:\n1. CONMEBOL\n2. UEFA\n3. AFC\n4. CAF\n5. CONCACAF\n6. OFC\n",
						"Error. Tiene que elegir la confederación con el número, ejemplo: '1 = AFC'.\n",
						1, 6) == 0
				&& utn_obtenerFlotante(&auxJugador.salario,
						"Ingrese salario:\n",
						"Error. No puede tener un salario mayor a $100.000 . Tiene ingresar el salario en formato numérico y debe ser mayor a 0.\n",
						1, 100000) == 0
				&& utn_obtenerNumeroShort(&auxJugador.aniosContrato,
						"Ingrese años de contrato:\n",
						"Error. No puede tener más de 26 o menos de 1 año de contrato. Tiene ingresar los años en formato numérico y sin decimales.\n",
						1, 26) == 0) {
			if (setPosicion(auxJugador.posicion, posicion) == 0
					&& setConfederacion(&auxJugador.idConfederacion,
							confederacion) == 0) {
				auxJugador.isEmpty = 0;
				jugadores[posicionVacia] = auxJugador;
				printf(
						"Jugador dado de alta exitosamente! Número identificador: %d.\n",
						idJugador);
				idJugador++;
			}
		} else {
			printf("Error. Intentelo más tarde.\n");
		}
	}
}

int existenJugadores(eJugador jugadores[], int largo) {
	int retorno = -1;

	if (jugadores != NULL && largo > 0) {
		for (int i = 0; i < largo; i++) {
			if (jugadores[i].isEmpty == 0) {
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int buscarJugadorPorId(eJugador jugadores[], int largo, int id) {
	int retorno = -1;

	if (jugadores != NULL && largo > 0 && id > 0) {
		for (int i = 0; i < largo; i++) {
			if (jugadores[i].isEmpty == 0 && jugadores[i].id == id) {
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

static void mostrarJugador(eJugador item, char confederacion[]) {
	printf("| %*d | %*s | %*s |     %*d | $%*.2f | %*s |         %*d |\n", -3,
			item.id, -28, item.nombre, -15, item.posicion, -8,
			item.numeroCamiseta, -11, item.salario, -13, confederacion, -8,
			item.aniosContrato);
}

void mostrarJugadores(eJugador jugadores[], int largoJ,
		eConfederacion confederaciones[], int largoC) {
	if (jugadores != NULL && largoJ > 0 && confederaciones != NULL
			&& largoC > 0) {
		printf("\t\t\t\t\t- Listado de Jugadores -\n");
		printf(
				"========================================================================================================================\n");
		printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n", -5, " ID", -30,
				"        NOMBRE", -18, " POSICIÓN", -15, " Nº CAMISETA", -14,
				" SUELDO", -16, " CONFEDERACIÓN", -2, " AÑOS de CONTRATO ");
		printf(
				"------------------------------------------------------------------------------------------------------------------------\n");
		for (int i = 0; i < largoC; i++) {
			for (int j = 0; j < largoJ; j++) {
				if ((jugadores[j].isEmpty == 0
						&& confederaciones[i].isEmpty == 0)
						&& (jugadores[j].idConfederacion
								== confederaciones[i].id)) {
					mostrarJugador(jugadores[j], confederaciones[i].nombre);
				}
			}
		}
		printf(
				"========================================================================================================================\n");
	}
}

static int listarJugadores(eJugador jugadores[], int largoJ,
		eConfederacion confederaciones[], int largoC) {
	int retorno = -1;
	eJugador pAuxJugador;

	if (jugadores != NULL && largoJ > 0
			&& existenJugadores(jugadores, largoJ) == 0) {
		for (int i = 0; i < largoJ - 1; i++) {
			for (int j = 0; j < largoJ; j++) {
				if (jugadores[i].isEmpty == 0 && jugadores[j].isEmpty == 0) {
					// Ordeno por ID de menor a mayor:
					if (jugadores[i].id < jugadores[j].id) {
						pAuxJugador = jugadores[i];
						jugadores[i] = jugadores[j];
						jugadores[j] = pAuxJugador;
					}
				}
			}
		}
		mostrarJugadores(jugadores, largoJ, confederaciones, largoC);
		retorno = 0;
	}

	return retorno;
}

void darBajaJugador(eJugador jugadores[], int largoJ,
		eConfederacion confederaciones[], int largoC) {
	int id;
	int indice;
	int esValido;
	int hayJugadores = existenJugadores(jugadores, largoJ);

	if (jugadores != NULL && largoJ > 0 && confederaciones != NULL
			&& hayJugadores == 0
			&& listarJugadores(jugadores, largoJ, confederaciones, largoC)
					== 0) {
		esValido =
				utn_obtenerNumero(&id,
						"Ingrese el ID del jugador que va a dar de baja:\n",
						"Error. El ID tiene que ser numérico, mayor a 0 y no tener decimales.\n",
						1, ID_MAXIMO);
		indice = buscarJugadorPorId(jugadores, largoJ, id);

		if (indice != -1 && esValido == 0) {
			jugadores[indice].isEmpty = 1;
			printf("Jugador dado de baja exitosamente!\n");
		} else {
			printf(ID_NO_ENCONTRADO);
		}
	} else {
		printf(NO_HAY_JUGADORES);
	}
}

static void modificarJugadorSubmenu(eJugador jugadores[], int indice) {
	int mostrarSubmenu = 1;
	int opcion;
	int posicion;
	int confederacion;

	while (mostrarSubmenu == 1) {
		utn_obtenerNumero(&opcion,
				"Seleccione que desea modificar:\n1. Nombre.\n2. Posición.\n3. Número de camiseta.\n4. Confederación.\n5. Salario.\n6. Años de contrato.\n7. Salir.\n",
				"Error. Opción inválida, opciones disponibles: 1, 2, 3 o 4.\n",
				1, 7);

		switch (opcion) {
		case 1:
			if (utn_obtenerTexto(jugadores[indice].nombre, 50,
					"Ingresa nombre:\n",
					ERROR_TEXTO, 50) == 0) {
				printf(MODIFICACION_EXITOSA);
			}
			break;
		case 2:
			if (utn_obtenerNumero(&posicion,
					"Ingrese que posición quiere jugar:\n1. Arquero.\n2. Defensa.\n3. Mediocampo.\n4. Delantero.\n",
					"Error. Tienes que seleccionar el número de la posición que quieres jugar (opciones del 1 al 4).\n",
					1, 4) == 0) {
				if (setPosicion(jugadores[indice].posicion, posicion) == 0) {
					printf(MODIFICACION_EXITOSA);
				}
			}
			break;
		case 3:
			if (utn_obtenerNumeroShort(&jugadores[indice].numeroCamiseta,
					"Ingrese número de camiseta:\n",
					"Error. Tiene ingresar un número del 1 al 22, en formato numérico y sin decimales.\n",
					0, 22) == 0) {
				printf(MODIFICACION_EXITOSA);
			}
			break;
		case 4:
			if (utn_obtenerNumero(&confederacion,
					"Confederaciones disponibles:\n1. CONMEBOL\n2. UEFA\n3. AFC\n4. CAF\n5. CONCACAF\n6. OFC\n",
					"Error. Tiene que elegir la confederación con el número, ejemplo: '1 = AFC'.\n",
					1, 6) == 0) {
				if (setConfederacion(&jugadores[indice].idConfederacion,
						confederacion) == 0) {
					printf(MODIFICACION_EXITOSA);
				}
			}
			break;
		case 5:
			if (utn_obtenerFlotante(&jugadores[indice].salario,
					"Ingrese salario:\n",
					"Error. No puede tener un salario mayor a $100.000 . Tiene ingresar el salario en formato numérico y debe ser mayor a 0.\n",
					1, 100000) == 0) {
				printf(MODIFICACION_EXITOSA);
			}
			break;
		case 6:
			if (utn_obtenerNumeroShort(&jugadores[indice].aniosContrato,
					"Ingrese años de contrato:\n",
					"Error. Tiene ingresar los años de contrato en formato numérico y sin decimales.\n",
					0, 26) == 0) {
				printf(MODIFICACION_EXITOSA);
			}
			break;
		case 7:
			mostrarSubmenu = 0;
			printf("Submenu de opciones cerrado.\n");
			break;
		}
	}
}

void modificarJugador(eJugador jugadores[], int largoJ,
		eConfederacion confederaciones[], int largoC) {
	int id;
	int indice;

	if (jugadores != NULL && largoJ > 0
			&& existenJugadores(jugadores, largoJ) == 0) {
		if (listarJugadores(jugadores, largoJ, confederaciones, largoC) == 0) {
			utn_obtenerNumero(&id,
					"Ingrese el ID del jugador que va a modificar:\n",
					"Error. El ID tiene que ser numérico, mayor a 0 y no tener decimales.\n",
					1, ID_MAXIMO);
			indice = buscarJugadorPorId(jugadores, largoJ, id);

			if (indice != -1) {
				modificarJugadorSubmenu(jugadores, indice);
			} else {
				printf(ID_NO_ENCONTRADO);
			}
		} else {
			printf("Error. Intente esta opción en otro momento.");
		}
	} else {
		printf(NO_HAY_JUGADORES);
	}
}
