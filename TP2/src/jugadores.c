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

void darAltaJugador(eJugador jugadores[], int largo) {
	int posicionVacia = buscarPosicionVacia(jugadores, largo);
	eJugador auxJugador;
	static int idJugador = 200;

	if (jugadores != NULL && largo > 0 && posicionVacia != -1) {
		auxJugador.id = idJugador;
		utn_obtenerTexto(auxJugador.nombre, 50, "Ingresa nombre:\n",
		ERROR_TEXTO, 50);
		utn_obtenerTexto(auxJugador.posicion, 50, "Ingresa posición:\n",
		ERROR_TEXTO, 50);
		utn_obtenerNumeroShort(&auxJugador.numeroCamiseta,
				"Ingrese número de camiseta:\n",
				"Error. Tiene ingresar un número del 1 al 22, en formato numérico y sin decimales.\n",
				0, 22);
		utn_obtenerNumero(&auxJugador.idConfederacion,
				"Confederaciones disponibles:\n1. AFC\n2. CAF\n3. CONCACAF\n4. CONMEBOL\n5. UEFA\n6. OFC\n",
				"Error. Tiene que elegir la confederación con el número, ejemplo: '1 = AFC'.\n",
				1, 6);
		utn_obtenerFlotante(&auxJugador.salario, "Ingrese salario:\n",
				"Error. Tiene ingresar el salario en formato numérico y debe ser mayor a 0.\n",
				1, 2500);
		utn_obtenerNumeroShort(&auxJugador.aniosContrato,
				"Ingrese años de contrato:\n",
				"Error. Tiene ingresar los años de contrato en formato numérico y sin decimales.\n",
				0, 26);
		auxJugador.isEmpty = 0;
		jugadores[posicionVacia] = auxJugador;

		printf("Jugador dado de alta exitosamente! Número identificador: %d.\n",
				idJugador);
		idJugador++;
	}
}

static int existenJugadores(eJugador jugadores[], int largo) {
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

void darBajaJugador(eJugador jugadores[], int largo) {
	int id;
	int indice;
	int esValido;
	int hayJugadores = existenJugadores(jugadores, largo);

	if (jugadores != NULL && largo > 0 && hayJugadores == 0) {
		esValido = utn_obtenerNumero(&id,
				"Ingrese el ID del jugador que va a dar de baja:\n",
				"Error. El ID tiene que ser numérico y no tiene decimales.\n",
				1, ID_MAXIMO);
		indice = buscarJugadorPorId(jugadores, largo, id);

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

static void mostrarJugador(eJugador item) {
	char confederacion[31];
	switch (item.idConfederacion) {
	case 1:
		strcpy(confederacion, "AFC");
		break;
	case 2:
		strcpy(confederacion, "CAF");
		break;
	case 3:
		strcpy(confederacion, "CONCACAF");
		break;
	case 4:
		strcpy(confederacion, "CONMEBOL");
		break;
	case 5:
		strcpy(confederacion, "UEFA");
		break;
	case 6:
		strcpy(confederacion, "OFC");
		break;
	default:
		strcpy(confederacion, "Sin asignar");
		break;
	}
	printf("- ID Jugador: %d\n", item.id);
	printf("- Nombre: %s\n", item.nombre);
	printf("- Posición: %s\n", item.posicion);
	printf("- Numero de camiseta: %d\n", item.numeroCamiseta);
	printf("- Confederacion: %s\n", confederacion);
	printf("- Salario: $%.2f\n", item.salario);
	printf("- Años de contrato: %d\n", item.aniosContrato);
	printf("--------------\n");
}

static void mostrarJugadores(eJugador jugadores[], int largo) {
	if (jugadores != NULL && largo > 0) {
		printf("Jugadores:\n");
		for (int i = 0; i < largo; i++) {
			if (jugadores[i].isEmpty == 0) {
				mostrarJugador(jugadores[i]);
			}
		}
	}
}

static int listarJugadores(eJugador jugadores[], int largo) {
	int ret = -1;
	eJugador aux;

	if (jugadores != NULL && largo > 0
			&& existenJugadores(jugadores, largo) == 0) {
		for (int i = 0; i < largo - 1; i++) {
			for (int j = 0; j < largo; j++) {
				if (jugadores[i].isEmpty == 0 && jugadores[j].isEmpty == 0) {
					// Ordeno por ID de menor a mayor:
					if (jugadores[i].id < jugadores[j].id) {
						aux = jugadores[i];
						jugadores[i] = jugadores[j];
						jugadores[j] = aux;
					}
				}
			}
		}
		mostrarJugadores(jugadores, largo);
		ret = 0;
	}

	return ret;
}

static void modificarJugadorSubmenu(eJugador jugadores[], int indice) {
	int mostrarSubmenu = 1;
	int opcion;

	while (mostrarSubmenu == 1) {
		utn_obtenerNumero(&opcion,
				"Seleccione que desea modificar:\n1. Nombre.\n2. Posición.\n3. Número de camiseta.\n4. Confederación.\n5. Salario.\n6. Años de contrato.\n7. Salir.\n",
				"Error. Opción inválida, opciones disponibles: 1, 2, 3 o 4.\n",
				1, 7);

		switch (opcion) {
		case 1:
			utn_obtenerTexto(jugadores[indice].nombre, 50, "Ingresa nombre:\n",
			ERROR_TEXTO, 50);
			printf(MODIFICACION_EXITOSA);
			break;
		case 2:
			utn_obtenerTexto(jugadores[indice].posicion, 50,
					"Ingresa posición:\n",
					ERROR_TEXTO, 50);
			printf(MODIFICACION_EXITOSA);
			break;
		case 3:
			utn_obtenerNumeroShort(&jugadores[indice].numeroCamiseta,
					"Ingrese número de camiseta:\n",
					"Error. Tiene ingresar un número del 1 al 22, en formato numérico y sin decimales.\n",
					0, 22);
			printf(MODIFICACION_EXITOSA);
			break;
		case 4:
			utn_obtenerNumero(&jugadores[indice].idConfederacion,
					"Confederaciones disponibles:\n1. AFC\n2. CAF\n3. CONCACAF\n4. CONMEBOL\n5. UEFA\n6. OFC\n",
					"Error. Tiene que elegir la confederación con el número, ejemplo: '1 = AFC'.\n",
					1, 6);
			printf(MODIFICACION_EXITOSA);
			break;
		case 5:
			utn_obtenerFlotante(&jugadores[indice].salario,
					"Ingrese salario:\n",
					"Error. Tiene ingresar el salario en formato numérico y debe ser mayor a 0.\n",
					1, 2500);
			printf(MODIFICACION_EXITOSA);
			break;
		case 6:
			utn_obtenerNumeroShort(&jugadores[indice].aniosContrato,
					"Ingrese años de contrato:\n",
					"Error. Tiene ingresar los años de contrato en formato numérico y sin decimales.\n",
					0, 26);
			printf(MODIFICACION_EXITOSA);
			break;
		case 7:
			mostrarSubmenu = 0;
			printf("Submenu de opciones cerrado.\n");
			break;
		}
	}
}

void modificarJugador(eJugador jugadores[], int largo) {
	int id;
	int indice;

	if (jugadores != NULL && largo > 0
			&& existenJugadores(jugadores, largo) == 0) {
		if (listarJugadores(jugadores, largo) == 0) {
			utn_obtenerNumero(&id,
					"Ingrese el ID del jugador que va a modificar:\n",
					"Error. El ID tiene que ser numérico y no tiene decimales.\n",
					1, ID_MAXIMO);
			indice = buscarJugadorPorId(jugadores, largo, id);

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
