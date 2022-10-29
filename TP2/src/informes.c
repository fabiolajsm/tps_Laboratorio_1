/*
 * informes.c
 *
 *  Created on: 29 oct. 2022
 *      Author: fsuarez
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "jugadores.h"

static void listarJugadoresAlfabeticamente(eJugador jugadores[], int largo) {
	eJugador aux;

	if (jugadores != NULL && largo > 0) {
		for (int i = 0; i < largo - 1; i++) {
			for (int j = 0; j < largo; j++) {
				if (jugadores[i].isEmpty == 0 && jugadores[j].isEmpty == 0) {
					// Primero ordeno por confederacion de menor a mayor:
					if (jugadores[i].idConfederacion
							< jugadores[j].idConfederacion) {
						aux = jugadores[i];
						jugadores[i] = jugadores[j];
						jugadores[j] = aux;
					}
					// Si tiene ID 5 sabemos que tiene que ir de último
					if (jugadores[j].idConfederacion == 5) {
						aux = jugadores[i];
						jugadores[i] = jugadores[j];
						jugadores[j] = aux;
					}
					// Si son de la misma confederación, ordenamos por nombre:
					if (jugadores[i].idConfederacion
							== jugadores[j].idConfederacion
							&& strcmp(jugadores[i].nombre, jugadores[j].nombre)
									< 0) {
						aux = jugadores[i];
						jugadores[i] = jugadores[j];
						jugadores[j] = aux;
					}
				}
			}
		}
		mostrarJugadores(jugadores, largo);
	} else {
		printf("Error. Intente más tarde.\n");
	}
}

static int obtenerConfederacion(char *pResultado, int idConfederacion) {
	int retorno = -1;

	if (pResultado != NULL && idConfederacion > 0) {
		switch (idConfederacion) {
		case 1:
			strcpy(pResultado, "AFC");
			retorno = 1;
			break;
		case 2:
			strcpy(pResultado, "CAF");
			retorno = 2;
			break;
		case 3:
			strcpy(pResultado, "CONCACAF");
			retorno = 3;
			break;
		case 4:
			strcpy(pResultado, "CONMEBOL");
			retorno = 4;
			break;
		case 5:
			strcpy(pResultado, "UEFA");
			retorno = 5;
			break;
		case 6:
			strcpy(pResultado, "OFC");
			retorno = 6;
			break;
		}
	}
	return retorno;
}

static void listarConfederacionesYSusJugadores(eJugador jugadores[], int largo) {
	char confederacion[31];
	int contador = 1;
	int tieneJugadores = 0;

	if (jugadores != NULL && largo > 0) {
		while (contador < 7) {
			tieneJugadores = 0;
			obtenerConfederacion(confederacion, contador);
			printf("Jugadores de %s:\n", confederacion);
			for (int i = 0; i < largo; i++) {
				if (jugadores[i].isEmpty == 0
						&& jugadores[i].idConfederacion == contador) {
					printf("- %s.\n", jugadores[i].nombre);
					tieneJugadores = 1;
				}
			}
			if (tieneJugadores == 0) {
				printf("- No tiene jugadores.\n");
			}
			contador++;
		}
	} else {
		printf("Error. Intente más tarde.\n");
	}
}

static void informarSalarios(eJugador jugadores[], int largo) {
	float totalSalarios = 0;
	float totalJugadores = 0;
	float promedio = 0;
	int jugadoresArribaDelPromedio = 0;

	if (jugadores != NULL && largo > 0) {
		for (int i = 0; i < largo; i++) {
			if (jugadores[i].salario > 0 && jugadores[i].isEmpty == 0) {
				totalJugadores++;
				totalSalarios = totalSalarios + jugadores[i].salario;
				promedio = totalSalarios / totalJugadores;
				if (jugadores[i].salario > promedio) {
					jugadoresArribaDelPromedio++;
				}
			}
		}

		printf("- Total de salarios: $%.2f\n", totalSalarios);
		printf("- Promedio de todos los salarios: $%.2f\n", promedio);
		printf(
				"- Cantidad de jugadores que cobran más que el salario promedio: %d\n",
				jugadoresArribaDelPromedio);
	} else {
		printf("Error. Intente más tarde.\n");
	}
}

static void informarMasAniosDeContrato(eJugador jugadores[], int largo) {
	int idMayor = 0;
	char confederacion[31];

	if (jugadores != NULL && largo > 0) {
		for (int i = 0; i < largo; i++) {
			if (jugadores[i].isEmpty == 0) {
				if (jugadores[i].idConfederacion > idMayor) {
					idMayor = jugadores[i].idConfederacion;
					obtenerConfederacion(confederacion, idMayor);
				}
			}
		}
		printf("- Confederación con más años de contrato: %s\n", confederacion);
	} else {
		printf("Error. Intente más tarde.\n");
	}
}

static void informarPorcentajePorConfederacion(eJugador jugadores[], int largo) {
	float totalJugadores = 0;
	float afc = 0;
	float caf = 0;
	float concacaf = 0;
	float conmebol = 0;
	float uefa = 0;
	float ofc = 0;

	if (jugadores != NULL && largo > 0) {
		for (int i = 0; i < largo; i++) {
			if (jugadores[i].isEmpty == 0) {
				totalJugadores++;
				switch (jugadores[i].idConfederacion) {
				case 1:
					afc++;
					break;
				case 2:
					caf++;
					break;
				case 3:
					concacaf++;
					break;
				case 4:
					conmebol++;
					break;
				case 5:
					uefa++;
					break;
				case 6:
					ofc++;
					break;
				}
			}
		}
		printf("- Porcentaje AFC: %.2f\n", afc / totalJugadores);
		printf("- Porcentaje CAF: %.2f\n", caf / totalJugadores);
		printf("- Porcentaje CONCACAF: %.2f\n", concacaf / totalJugadores);
		printf("- Porcentaje CONMEBOL: %.2f\n", conmebol / totalJugadores);
		printf("- Porcentaje UEFA: %.2f\n", uefa / totalJugadores);
		printf("- Porcentaje OFC: %.2f\n", ofc / totalJugadores);
	}
}

void informarDatos(eJugador jugadores[], int largo) {
	int hayJugadores = existenJugadores(jugadores, largo);
	int opcion;
	int esOpcionValida;
	int mostrarSubmenu = 1;

	if (jugadores != NULL && largo > 0 && hayJugadores == 0) {
		while (mostrarSubmenu) {
			// Pedimos al usuario que ingrese una opción:
			esOpcionValida =
					utn_obtenerNumero(&opcion,
							"Seleccione una opción:\n1. Listado de jugadores alfabéticamente.\n2. Listado de confederaciones con sus jugadores.\n3. Total y promedio de todos los salarios y cuántos de los jugadores cobran más del salario promedio.\n4. Confederación con mayor cantidad de años de contrato.\n5. Porcentaje de jugadores por cada confederación.\n6. Región con más jugadores y sus integrantes.\n7. Salir.\n",
							"Error. Opción inválida.\n", 1, 7);
			if (esOpcionValida == 0) {
				switch (opcion) {
				case 1:
					listarJugadoresAlfabeticamente(jugadores, largo);
					break;
				case 2:
					listarConfederacionesYSusJugadores(jugadores, largo);
					break;
				case 3:
					informarSalarios(jugadores, largo);
					break;
				case 4:
					informarMasAniosDeContrato(jugadores, largo);
					break;
				case 5:
					informarPorcentajePorConfederacion(jugadores, largo);
					break;
				case 6:
					printf("6\n");
					break;
				case 7:
					mostrarSubmenu = 0;
					break;
				}
			}
		}
	} else {
		printf("Error. No existen jugadores.\n");
	}
}
