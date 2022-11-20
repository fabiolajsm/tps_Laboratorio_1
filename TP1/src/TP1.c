#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "operaciones.h"
#define MENSAJE_MENU "Seleccione una opción:\n1. Ingreso de los costos de Mantenimiento.\n2. Carga de jugadores.\n3. Realizar todos los cálculos.\n4. Informar resultados.\n5. Salir.\n"

int main(void) {
	int mostrarMenu = 1;
	int ingresaronCostos = 0;
	int calculosHechos = 0;
	int seHicieronCambios = 0;
	int opcion;

	// Gastos
	int gastoHospedaje;
	int gastoComida;
	int gastoTransporte;
	int totalCostos;
	// Jugadores
	int totalArqueros = 0;
	int totalDefensores = 0;
	int totalMediocampistas = 0;
	int totalDelanteros = 0;
	float totalJugadores = 0;
	// Total confederaciones
	int totalAfc = 0;
	int totalCaf = 0;
	int totalConcacaf = 0;
	int totalConmebol = 0;
	int totalUefa = 0;
	int totalOfc = 0;
	// Resultados
	float porcentajeAfc;
	float porcentajeCaf;
	float porcentajeConcacaf;
	float porcentajeConmebol;
	float porcentajeUefa;
	float porcentajeOfc;
	int totalConAumento;
	int aumento = 0;

	while (mostrarMenu) {
		if (obtenerNumero(&opcion,
		MENSAJE_MENU, "Error. Opción inválida.\n", 1, 5, 3) == 0) {
			switch (opcion) {
			case 1:
				if (ingresarCostos(&gastoHospedaje, &gastoComida,
						&gastoTransporte) == 0) {
					ingresaronCostos = 1;
					seHicieronCambios = 1;
					printf(
							"Gastos hasta el momento:\n→ Costos de hospedaje: $%d.\n→ Costos de comida: $%d.\n→ Costos de transporte: $%d.\n",
							gastoHospedaje, gastoComida, gastoTransporte);
				} else {
					printf("Error. No se pudo ingresar el costo.\n");
				}
				break;
			case 2:
				if (cargarJugadores(&totalAfc, &totalCaf, &totalConcacaf,
						&totalConmebol, &totalUefa, &totalOfc, &totalArqueros,
						&totalDefensores, &totalMediocampistas,
						&totalDelanteros, &totalJugadores) == 0) {
					seHicieronCambios = 1;
					printf(
							"→ Arqueros: %d\n→ Defensores: %d\n→ Mediocampistas: %d\n→ Delanteros: %d\n",
							totalArqueros, totalDefensores, totalMediocampistas,
							totalDelanteros);
				} else {
					printf("Error. No se pudo cargar jugador.\n");
				}
				break;
			case 3:
				if (sePuedeCalcular(ingresaronCostos, totalJugadores)) {
					if (calcularResultados(gastoHospedaje, gastoComida,
							gastoTransporte, &totalCostos, totalJugadores,
							totalAfc, totalCaf, totalConcacaf, totalConmebol,
							totalUefa, totalOfc, &porcentajeAfc, &porcentajeCaf,
							&porcentajeConcacaf, &porcentajeConmebol,
							&porcentajeUefa, &porcentajeOfc, &totalConAumento,
							&aumento) == 0) {
						calculosHechos = 1;
						seHicieronCambios = 0;
						printf("Se realizaron exitosamente los cálculos.\n");
					} else {
						printf("No se pudieron realizar los cálculos.\n");
					}
				}
				break;
			case 4:
				if (!calculosHechos) {
					printf(
							"Error. No puede acceder a esta opción sin haber hecho los cálculos, intente yendo a la opción 3.\n");
				} else if (seHicieronCambios) {
					printf(
							"Error. Se hicieron nuevos cambios, tiene que volver a hacer los cálculos, para ingresar a esta opción.\n");
				} else {
					informarResultados(porcentajeAfc, porcentajeCaf,
							porcentajeConcacaf, porcentajeConmebol,
							porcentajeUefa, porcentajeOfc, totalCostos,
							totalAfc, totalCaf, totalConcacaf, totalConmebol,
							totalUefa, totalOfc, totalConAumento, aumento);
				}
				break;
			case 5:
				mostrarMenu = 0;
				break;
			}
		}
	}
	return EXIT_SUCCESS;
}
