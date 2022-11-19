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
#include "confederaciones.h"

static void listarJugadoresAlfabeticamente(eJugador jugadores[], int largoJ,
		eConfederacion confederaciones[], int largoC) {
	eJugador auxJugador;
	eConfederacion auxConfederacion;

	if (jugadores != NULL && largoJ > 0 && confederaciones != NULL
			&& largoC > 0) {
		// Ordeno las confederaciones por nombre
		for (int i = 0; i < largoC - 1; i++) {
			for (int j = 0; j < largoC; j++) {
				if (confederaciones[i].isEmpty == 0
						&& confederaciones[j].isEmpty == 0) {
					if (strcmp(confederaciones[i].nombre,
							confederaciones[j].nombre) < 0) {
						auxConfederacion = confederaciones[i];
						confederaciones[i] = confederaciones[j];
						confederaciones[j] = auxConfederacion;
					}
				}
			}
		}
		for (int i = 0; i < largoJ - 1; i++) {
			for (int j = 0; j < largoJ; j++) {
				if (jugadores[i].idConfederacion == jugadores[j].idConfederacion
						&& strcmp(jugadores[i].nombre, jugadores[j].nombre)
								< 0) {
					auxJugador = jugadores[i];
					jugadores[i] = jugadores[j];
					jugadores[j] = auxJugador;
				}
			}
		}

		mostrarJugadores(jugadores, largoJ, confederaciones, largoC);
	} else {
		printf("Error. Intente más tarde.\n");
	}
}

static int listarJugadoresPorConfederacion(eJugador jugadores[], int largo,
		int idConfederacion) {
	int retorno = -1;
	if (jugadores != NULL && largo > 0 && idConfederacion > 0) {
		for (int i = 0; i < largo; i++) {
			if (jugadores[i].isEmpty == 0
					&& jugadores[i].idConfederacion == idConfederacion) {
				printf(" - %s\n", jugadores[i].nombre);
				retorno = 0;
			}

		}

		if (retorno == -1) {
			printf(" - No tiene jugadores\n");
		}
	}
	return retorno;
}

static void listarConfederacionesYSusJugadores(eJugador jugadores[],
		eConfederacion confederaciones[], int largoJ, int largoC) {
	if (jugadores != NULL && confederaciones != NULL && largoJ > 0
			&& largoC > 0) {
		for (int i = 0; i < largoC; i++) {
			if (confederaciones[i].isEmpty == 0) {
				printf("-> %s\n", confederaciones[i].nombre);
				listarJugadoresPorConfederacion(jugadores, largoJ,
						confederaciones[i].id);
			}
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
			if (jugadores[i].isEmpty == 0) {
				totalJugadores++;
				totalSalarios = totalSalarios + jugadores[i].salario;
			}
		}
		promedio = totalSalarios / totalJugadores;
		for (int i = 0; i < largo; i++) {
			if (jugadores[i].isEmpty == 0 && jugadores[i].salario > promedio) {
				jugadoresArribaDelPromedio++;
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

static int sumarAniosContratoPorConfederacion(eJugador jugadores[], int largo,
		int idConfederacion) {
	int contador = 0;

	if (jugadores != NULL && largo > 0 && idConfederacion > 0) {
		for (int i = 0; i < largo; i++) {
			if (jugadores[i].isEmpty == 0
					&& jugadores[i].idConfederacion == idConfederacion) {
				contador = contador + jugadores[i].aniosContrato;
			}
		}
	}
	return contador;
}

static void informarMasAniosDeContrato(eJugador jugadores[],
		eConfederacion confederaciones[], int largoJ, int largoC) {
	eAniosContrato auxAniosContrato;
	eAniosContrato mayor;
	mayor.aniosContrato = 0;

	if (jugadores != NULL && largoJ > 0 && confederaciones != NULL
			&& largoC > 0) {
		for (int i = 0; i < largoC; i++) {
			if (confederaciones[i].isEmpty == 0) {
				auxAniosContrato.idConfederacion = confederaciones[i].id;
				auxAniosContrato.aniosContrato =
						sumarAniosContratoPorConfederacion(jugadores, largoJ,
								confederaciones[i].id);
				strcpy(auxAniosContrato.nombre, confederaciones[i].nombre);
				if (auxAniosContrato.aniosContrato > mayor.aniosContrato) {
					mayor = auxAniosContrato;
				}
			}

		}

		printf(
				"- Confederación con más años de contrato es %s con %d años de contrato\n",
				mayor.nombre, mayor.aniosContrato);
	} else {
		printf("Error. Intente más tarde.\n");
	}
}

static int sumarJugadoresPorConfederacion(eJugador jugadores[], int largo,
		int idConfederacion) {
	int contador = 0;

	if (jugadores != NULL && largo > 0 && idConfederacion > 0) {
		for (int i = 0; i < largo; i++) {
			if (jugadores[i].isEmpty == 0
					&& jugadores[i].idConfederacion == idConfederacion) {
				contador++;
			}
		}
	}
	return contador;
}

static void informarPorcentajePorConfederacion(eJugador jugadores[],
		eConfederacion confederaciones[], int largoJ, int largoC) {
	float totalJugadores = 0;
	float totalPorConfederacion;

	if (jugadores != NULL && largoJ > 0 && confederaciones != NULL
			&& largoC > 0) {
		for (int i = 0; i < largoJ; i++) {
			if (jugadores[i].isEmpty == 0) {
				totalJugadores++;
			}
		}

		for (int i = 0; i < largoC; i++) {
			if (confederaciones[i].isEmpty == 0) {
				totalPorConfederacion = sumarJugadoresPorConfederacion(
						jugadores, largoJ, confederaciones[i].id);
				printf("- Porcentaje %s: %.2f\n", confederaciones[i].nombre,
						(totalPorConfederacion / totalJugadores) * 100);
			}
		}
	}
}

static void mostrarJugadoresPorRegion(eJugador jugadores[], int largo,
		int idRegion) {
	if (jugadores != NULL && largo > 0 && idRegion > 0) {
		for (int i = 0; i < largo; i++) {
			if (jugadores[i].isEmpty == 0) {
				if (jugadores[i].idConfederacion == idRegion) {
					printf("- %s.\n", jugadores[i].nombre);
				}
			}
		}
	}
}

static void informarRegion(eJugador jugadores[],
		eConfederacion confederaciones[], int largoJ, int largoC) {
	int jugadoresPorConfederacion;
	int mayor = 0;
	eConfederacion auxConfederacion;

	if (jugadores != NULL && largoJ > 0 && confederaciones != NULL
			&& largoC > 0) {
		for (int i = 0; i < largoC; i++) {
			if (confederaciones[i].isEmpty == 0) {
				jugadoresPorConfederacion = sumarJugadoresPorConfederacion(
						jugadores, largoJ, confederaciones[i].id);
				if (jugadoresPorConfederacion > mayor) {
					mayor = jugadoresPorConfederacion;
					auxConfederacion = confederaciones[i];
				}
			}
		}
		printf("- La región con más jugadores es: %s, y sus jugadores son:\n",
				auxConfederacion.region);
		mostrarJugadoresPorRegion(jugadores, largoJ, auxConfederacion.id);
	}
}

void informarDatos(eJugador jugadores[], eConfederacion confederaciones[],
		int largoJ, int largoC) {
	int hayJugadores = existenJugadores(jugadores, largoJ);
	int opcion;
	int esOpcionValida;
	int mostrarSubmenu = 1;

	if (jugadores != NULL && confederaciones != NULL && largoJ > 0 && largoC > 0
			&& hayJugadores == 0) {
		while (mostrarSubmenu) {
			// Pedimos al usuario que ingrese una opción:
			esOpcionValida =
					utn_obtenerNumero(&opcion,
							"Seleccione una opción:\n1. Listado de jugadores ordenados alfabéticamente por nombre de confederación.\n2. Listado de confederaciones con sus jugadores.\n3. Total y promedio de todos los salarios y cuántos de los jugadores cobran más del salario promedio.\n4. Confederación con mayor cantidad de años de contrato.\n5. Porcentaje de jugadores por cada confederación.\n6. Región con más jugadores y sus integrantes.\n7. Salir.\n",
							"Error. Opción inválida.\n", 1, 7);
			if (esOpcionValida == 0) {
				switch (opcion) {
				case 1:
					listarJugadoresAlfabeticamente(jugadores, largoJ,
							confederaciones, largoC);
					break;
				case 2:
					listarConfederacionesYSusJugadores(jugadores,
							confederaciones, largoJ, largoC);
					break;
				case 3:
					informarSalarios(jugadores, largoJ);
					break;
				case 4:
					informarMasAniosDeContrato(jugadores, confederaciones,
							largoJ, largoC);
					break;
				case 5:
					informarPorcentajePorConfederacion(jugadores,
							confederaciones, largoJ, largoC);
					break;
				case 6:
					informarRegion(jugadores, confederaciones, largoJ, largoC);
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
