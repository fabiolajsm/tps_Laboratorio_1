#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#define GASTO_MAXIMO 1000000
#define ERROR_COSTO_INVALIDO "Error. No puede ingresar un gasto mayor a $1.000.000. Tiene que ser un gasto mayor a 0, numérico y sin decimales.\n"
#define CIEN 100
#define MAXIMO_ARQUEROS 2
#define MAXIMO_DEFENSORES 8
#define MAXIMO_MEDIOCAMPISTAS 8
#define MAXIMO_DELANTEROS 4
#define MAXIMO_DE_JUGADORES 22

int ingresarCostos(int *pGastoH, int *pGastoC, int *pGastoT) {
	int retorno = -1;
	int opcion;
	int gastoH;
	int gastoC;
	int gastoT;
	static int hospedaje = 0;
	static int comida = 0;
	static int transporte = 0;

	if (pGastoH == NULL && pGastoC == NULL && pGastoT == NULL)
		return -1;

	if (obtenerNumero(&opcion,
			"Elija que gasto desea ingresar:\n1) Costo de hospedaje.\n2) Costo de comida.\n3) Costo de transporte.\n",
			"Error. Opción inválida.\n", 1, 3, 3) == 0) {
		switch (opcion) {
		case 1:
			if (obtenerNumero(&gastoH, "Ingrese gasto del hospedaje:\n",
			ERROR_COSTO_INVALIDO, 1, GASTO_MAXIMO, 3) == 0) {
				retorno = 0;
				hospedaje += gastoH;
			} else {
				retorno = -1;
			}
			break;
		case 2:
			if (obtenerNumero(&gastoC, "Ingrese gasto de la comida:\n",
			ERROR_COSTO_INVALIDO, 1, GASTO_MAXIMO, 3) == 0) {
				retorno = 0;
				comida += gastoC;
			} else {
				retorno = -1;
			}
			break;
		case 3:
			if (obtenerNumero(&gastoT, "Ingrese gasto del transporte:\n",
			ERROR_COSTO_INVALIDO, 1, GASTO_MAXIMO, 3) == 0) {
				retorno = 0;
				transporte += gastoT;
			} else {
				retorno = -1;
			}
			break;
		}
		*pGastoH = hospedaje;
		*pGastoC = comida;
		*pGastoT = transporte;
	}
	return retorno;
}

static int agregarConfederacion(int opcion, int *pAfc, int *pCaf,
		int *pConcacaf, int *pConmebol, int *pUefa, int *pOfc) {
	int retorno = -1;
	static float afc = 0;
	static float caf = 0;
	static float concacaf = 0;
	static float conmebol = 0;
	static float uefa = 0;
	static float ofc = 0;

	if ((opcion > 0) && pAfc != NULL && pCaf != NULL && pConcacaf != NULL
			&& pConmebol != NULL && pUefa != NULL && pOfc != NULL) {
		switch (opcion) {
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
		*pAfc = afc;
		*pCaf = caf;
		*pConcacaf = concacaf;
		*pConmebol = conmebol;
		*pUefa = uefa;
		*pOfc = ofc;
		retorno = 0;
	}
	return retorno;
}

static int posicionDisponible(int posicionElegida, char *mensajeExito,
		char *mensajeError, int *pArqueros, int *pDefensores,
		int *pMediocampistas, int *pDelanteros) {
	int retorno = 0;
	static int arqueros = 0;
	static int defensores = 0;
	static int mediocampistas = 0;
	static int delanteros = 0;

	if ((posicionElegida > 0) && mensajeExito != NULL && mensajeError != NULL
			&& pArqueros != NULL && pDefensores != NULL
			&& pMediocampistas != NULL && pDelanteros != NULL) {
		switch (posicionElegida) {
		case 1:
			if (arqueros < MAXIMO_ARQUEROS) {
				retorno = 1;
				arqueros++;
			}
			break;
		case 2:
			if (defensores < MAXIMO_DEFENSORES) {
				retorno = 1;
				defensores++;
			}
			break;
		case 3:
			if (mediocampistas < MAXIMO_MEDIOCAMPISTAS) {
				retorno = 1;
				mediocampistas++;
			}
			break;
		case 4:
			if (delanteros < MAXIMO_DELANTEROS) {
				retorno = 1;
				delanteros++;
			}
			break;
		}
		if (retorno == 1) {
			*pArqueros = arqueros;
			*pDefensores = defensores;
			*pMediocampistas = mediocampistas;
			*pDelanteros = delanteros;
			printf("%s", mensajeExito);
		} else {
			printf("%s", mensajeError);
		}
	}

	return retorno;
}

int cargarJugadores(int *pAfc, int *pCaf, int *pConcacaf, int *pConmebol,
		int *pUefa, int *pOfc, int *pArqueros, int *pDefensores,
		int *pMediocampistas, int *pDelanteros, float *pTotalJugadores) {
	int retorno = -1;
	int numeroCamiseta = 0;
	int esPosicionValida = 0;
	int posicion = 0;
	int confederacion;
	static float totalJugadores = 0;

	if (pAfc != NULL && pCaf != NULL && pConcacaf != NULL && pConmebol != NULL
			&& pUefa != NULL && pOfc != NULL && pArqueros != NULL
			&& pDefensores != NULL && pMediocampistas != NULL
			&& pDelanteros != NULL && pTotalJugadores != NULL) {
		if (totalJugadores == MAXIMO_DE_JUGADORES) {
			printf(
					"Error, el equipo está completo y no se pueden cargar mas jugadores. Jugadores en total: %.2f\n",
					totalJugadores);
			return -1;
		}
		if (obtenerNumero(&numeroCamiseta, "Ingrese número de camiseta:\n",
				"Error. Tiene que ser un número, del 1 al 22.\n", 1, 22, 30)
				== 0) {
			while (!esPosicionValida) {
				obtenerNumero(&posicion,
						"Ingrese que posición quiere jugar:\n1. Arquero.\n2. Defensa.\n3. Mediocampo.\n4. Delantero.\n",
						"Error. Tienes que seleccionar el número de la posición que quieres jugar (opciones del 1 al 4).\n",
						1, 4, 3);
				esPosicionValida =
						posicionDisponible(posicion,
								"Posición seleccionada exitosamente.\n",
								"Error. La posición que elegiste no tiene cupos, vuelve a intentarlo seleccionando otra.\n",
								pArqueros, pDefensores, pMediocampistas,
								pDelanteros);
			}

			if (esPosicionValida == 1) {
				if (obtenerNumero(&confederacion,
						"Selecciona el número de la confederación donde quieres jugar:\n1. AFC en Asia.\n2. CAF en África.\n3. CONCACAF en zona del Norte.\n4. CONMEBOL en Sudamérica.\n5. UEFA en Europa.\n6. OFC en Oceanía.\n",
						"Error. Tienes que seleccionar la confederación con un número disponible en las opciones(opciones del 1 al 6).\n",
						1, 6, 10) == 0) {
					if (agregarConfederacion(confederacion, pAfc, pCaf,
							pConcacaf, pConmebol, pUefa, pOfc) == 0) {
						totalJugadores++;
						*pTotalJugadores = totalJugadores;
						retorno = 0;
					}
				}
			}
		}
	}

	return retorno;
}

int sePuedeCalcular(int ingresaronCostos, int totalJugadores) {
	int ret = 0;

	if (ingresaronCostos < 1 && totalJugadores < 1) {
		printf(
				"Error. No hay costos de mantenimiento ni jugadores ingresados. Intente yendo a la opción 1 y 2.\n");
	} else if (ingresaronCostos < 1) {
		printf(
				"Error. No hay costos de mantenimiento ingresados. Intente yendo a la opción 1.\n");
	} else if (totalJugadores < 1) {
		printf(
				"Error. No hay jugadores ingresados. Intente yendo a la opción 2.\n");
	} else {
		ret = 1;
	}
	return ret;
}

static float divisionDecimales(float numA, float numB) {
	if (numB == 0) {
		return -1;
	}
	return numA / numB;
}

int calcularResultados(int gastoHospedaje, int gastoComida, int gastoTransporte,
		int *totalCostos, float totalJugadores, int totalAfc, int totalCaf,
		int totalConcacaf, int totalConmebol, int totalUefa, int totalOfc,
		float *pAfc, float *pCaf, float *pConcacaf, float *pConmebol,
		float *pUefa, float *pOfc, int *totalConAumento, int *aumento) {
	int retorno = -1;
	int costos;

	if (totalCostos != NULL
			&& totalJugadores
					> 0&& pAfc != NULL && pCaf != NULL && pConcacaf != NULL && pConmebol != NULL
					&& pUefa != NULL && pOfc != NULL
					&& totalConAumento != NULL && aumento != NULL) {
		// Seteo los costos
		costos = gastoHospedaje + gastoComida + gastoTransporte;
		*totalCostos = costos;

		// Calculo y seteo los porcentajes de las confederaciones
		*pAfc = divisionDecimales(totalAfc, totalJugadores) * CIEN;
		*pCaf = divisionDecimales(totalCaf, totalJugadores) * CIEN;
		*pConcacaf = divisionDecimales(totalConcacaf, totalJugadores) * CIEN;
		*pConmebol = divisionDecimales(totalConmebol, totalJugadores) * CIEN;
		*pUefa = divisionDecimales(totalUefa, totalJugadores) * CIEN;
		*pOfc = divisionDecimales(totalOfc, totalJugadores) * CIEN;

		if (totalUefa > totalAfc && totalUefa > totalCaf
				&& totalUefa > totalConcacaf && totalUefa > totalConmebol
				&& totalUefa > totalOfc) {
			*aumento = costos * 0.35;
			*totalConAumento = costos * 1.35;
		}
		retorno = 0;
	}
	return retorno;
}

void informarResultados(float pAfc, float pCaf, float pConcacaf,
		float pConmebol, float pUefa, float pOfc, int totalCostos, int totalAfc,
		int totalCaf, int totalConcacaf, int totalConmebol, int totalUefa,
		int totalOfc, int totalConAumento, int aumento) {
	printf(
			"Porcentaje Uefa %.2f\nPorcentaje Conmebol %.2f\nPorcentaje Concacaf %.2f\nPorcentaje Afc %.2f\nPorcentaje Ofc %.2f\nPorcentaje Caf %.2f\n",
			pUefa, pConmebol, pConcacaf, pAfc, pOfc, pCaf);
	if (aumento != 0 && totalUefa > totalAfc && totalUefa > totalCaf
			&& totalUefa > totalConcacaf && totalUefa > totalConmebol
			&& totalUefa > totalOfc) {
		printf(
				"El costo de mantenimiento era de $%d y recibió un aumento de $%d, su nuevo valor es de: $%d\n",
				totalCostos, aumento, totalConAumento);
	} else {
		printf("El costo de mantenimiento es de $%d.\n", totalCostos);
	}
}
