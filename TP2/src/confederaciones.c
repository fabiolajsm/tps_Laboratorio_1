/*
 * confederaciones.c
 *
 *  Created on: 29 oct. 2022
 *      Author: fsuarez
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "confederaciones.h"
#define ERROR_TEXTO "Error. Tiene que ingresar un texto alfabético que no tenga más de 50 caracteres\n"
#define ID_NO_ENCONTRADO "Error. El ID no fue encontrado.\n"
#define MODIFICACION_EXITOSA "Se modificó exitosamente.\n"

void inicializarConfederaciones(eConfederacion confederaciones[], int largo) {
	if (confederaciones != NULL && largo > 0) {
		for (int i = 0; i < largo; i++) {
			// True 1 para "esta vacio" y false 0 para "no está vacío"
			confederaciones[i].isEmpty = 1;
		}
	}
}

void darAltaConfederacion(eConfederacion confederaciones[], int largo) {
	eConfederacion aux;
	static int id = 1;

	if (confederaciones != NULL && largo > 0) {
		aux.id = id;
		if (utn_obtenerTexto(aux.nombre, 50, "Ingresa nombre:\n",
		ERROR_TEXTO, 50) == 0
				&& utn_obtenerTexto(aux.region, 50, "Ingresa región:\n",
				ERROR_TEXTO, 50) == 0
				&& utn_obtenerNumero(&aux.anioCreacion,
						"Ingrese año de creación:\n",
						"Error. No puede ser mayor al año actual (2022) ni menor a 0. Tiene ingresar los años en formato numérico y sin decimales.\n",
						1, 2023) == 0) {
			aux.isEmpty = 0;
			confederaciones[id] = aux;
			printf(
					"Confederacion dada de alta exitosamente! Número identificador: %d.\n",
					id);
			id++;
		} else {
			printf("Error. Intentelo más tarde.\n");
		}
	}
}

static int buscarPorId(eConfederacion confederaciones[], int largo, int id) {
	int retorno = -1;

	if (confederaciones != NULL && largo > 0 && id > 0) {
		for (int i = 0; i < largo; i++) {
			if (confederaciones[i].isEmpty == 0
					&& confederaciones[i].id == id) {
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

void darBajaConfederacion(eConfederacion confederaciones[], int largo) {
	int id;
	int indice;
	int esValido;

	if (confederaciones != NULL && largo > 0) {
		esValido =
				utn_obtenerNumero(&id,
						"Ingrese el ID de la confederacion que va a dar de baja:\n",
						"Error. El ID tiene que ser numérico, mayor a 0 y no tener decimales.\n",
						1, 50);
		indice = buscarPorId(confederaciones, largo, id);

		if (indice != -1 && esValido == 0) {
			confederaciones[indice].isEmpty = 1;
			printf("Jugador dado de baja exitosamente!\n");
		} else {
			printf(ID_NO_ENCONTRADO);
		}
	}
}

static void modificarSubmenu(eConfederacion confederaciones[], int largo,
		int indice) {
	int mostrarSubmenu = 1;
	int opcion;

	while (mostrarSubmenu == 1) {
		utn_obtenerNumero(&opcion,
				"Seleccione que desea modificar:\n1. Nombre.\n2. Region.\n3. Año de creacion.\n4. Salir.\n",
				"Error. Opción inválida, opciones disponibles: 1, 2, 3 o 4.\n",
				1, 4);

		switch (opcion) {
		case 1:
			utn_obtenerTexto(confederaciones[indice].nombre, 50,
					"Ingresa nombre:\n",
					ERROR_TEXTO, 50);
			printf(MODIFICACION_EXITOSA);
			break;
		case 2:
			utn_obtenerTexto(confederaciones[indice].region, 50,
					"Ingresa region:\n",
					ERROR_TEXTO, 50);
			printf(MODIFICACION_EXITOSA);
			break;
		case 3:
			utn_obtenerNumero(&confederaciones[indice].anioCreacion,
					"Ingrese año de creación:\n",
					"Error. No puede ser mayor al año actual (2022) ni menor a 0. Tiene ingresar los años en formato numérico y sin decimales.\n",
					1, 2023);
			printf(MODIFICACION_EXITOSA);
			break;
		case 4:
			mostrarSubmenu = 0;
			printf("Submenu de opciones cerrado.\n");
			break;
		}
	}
}

void modificarConfederacion(eConfederacion confederaciones[], int largo) {
	int id;
	int indice;

	if (confederaciones != NULL && largo > 0) {
		utn_obtenerNumero(&id,
				"Ingrese el ID de la confederacion que va a modificar:\n",
				"Error. El ID tiene que ser numérico, mayor a 0 y no tener decimales.\n",
				1, 50);
		indice = buscarPorId(confederaciones, largo, id);

		if (indice != -1) {
			modificarSubmenu(confederaciones, largo, indice);
		} else {
			printf(ID_NO_ENCONTRADO);
		}
	} else {
		printf("Error");
	}
}
