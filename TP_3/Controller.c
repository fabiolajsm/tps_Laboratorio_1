#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#define MODIFICACION_EXITOSA "Se modificó exitosamente el dato\n"
#define MAXIMO_CONVOCADOS 22

// --- Archivos ---
/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char *path,
		LinkedList *pArrayListJugador) {
	int retorno = -1;
	FILE *pArchivo = NULL;

	if (path != NULL && pArrayListJugador != NULL) {
		pArchivo = fopen(path, "r");
		if (pArchivo != NULL
				&& parserJugadorDesdeTexto(pArchivo, pArrayListJugador) == 0) {
			retorno = 0;
		}
		fclose(pArchivo);
	}

	return retorno;
}
/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char *path,
		LinkedList *pArrayListJugador) {
	int retorno = -1;
	FILE *pArchivo = NULL;

	if (path != NULL && pArrayListJugador != NULL) {
		pArchivo = fopen(path, "rb");
		if (pArchivo != NULL
				&& parser_JugadorFromBinary(pArchivo, pArrayListJugador) == 0) {
			retorno = 0;
		}
		fclose(pArchivo);
	}
	return retorno;
}

int controller_generarJugadoresDesdeBinario(char *path,
		LinkedList *pArrayListJugador) {
	int retorno = -1;
	FILE *pArchivo = NULL;
	Jugador *auxPunteroJugador = NULL;
	int id;
	char nombreCompleto[30];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	int idSeleccionIngresada;

	if (path != NULL) {
		pArchivo = fopen(path, "w");
		if (pArchivo != NULL) {

			if (utn_obtenerNumero(&idSeleccionIngresada,
					"Ingrese el ID de la confederación en donde están los jugadores que desee guardar:\n",
					"Error. El ID tiene que ser un numero entero, mayor a 0 y menor a 32.\n",
					0, 32) == 0) {
				for (int i = 0; i < ll_len(pArrayListJugador); i++) {
					auxPunteroJugador = (Jugador*) ll_get(pArrayListJugador, i);
					if (auxPunteroJugador != NULL
							&& jug_getId(auxPunteroJugador, &id)
							&& jug_getNombreCompleto(auxPunteroJugador,
									nombreCompleto)
							&& jug_getEdad(auxPunteroJugador, &edad)
							&& jug_getPosicion(auxPunteroJugador, posicion)
							&& jug_getNacionalidad(auxPunteroJugador,
									nacionalidad)
							&& jug_getIdSeleccion(auxPunteroJugador,
									&idSeleccion)) {
						if (idSeleccion > 0
								&& idSeleccionIngresada == idSeleccion) {
							if (fwrite(auxPunteroJugador, sizeof(Jugador), 1,
									pArchivo) > 0) {
								retorno = 0;
							}
						}
					}
				}
			}
			fclose(pArchivo);
		}
	}
	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char *path,
		LinkedList *pArrayListJugador) {
	int retorno = -1;
	FILE *pArchivo = NULL;
	Jugador *auxPunteroJugador = NULL;
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;

	pArchivo = fopen(path, "w");
	if (path != NULL && pArrayListJugador != NULL && pArchivo != NULL) {
		fprintf(pArchivo,
				"id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion\n");
		for (int i = 0; i < ll_len(pArrayListJugador); i++) {
			auxPunteroJugador = ll_get(pArrayListJugador, i);
			if (jug_getId(auxPunteroJugador, &id)
					&& jug_getNombreCompleto(auxPunteroJugador, nombreCompleto)
					&& jug_getEdad(auxPunteroJugador, &edad)
					&& jug_getPosicion(auxPunteroJugador, posicion)
					&& jug_getNacionalidad(auxPunteroJugador, nacionalidad)
					&& jug_getIdSeleccion(auxPunteroJugador, &idSeleccion)) {
				fprintf(pArchivo, "%d,%s,%d,%s,%s,%d\n", id, nombreCompleto,
						edad, posicion, nacionalidad, idSeleccion);
				retorno = 0;
			}
		}
		fclose(pArchivo);
	}
	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char *path,
		LinkedList *pArrayListJugador) {
	return 1;
}
/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char *path,
		LinkedList *pArrayListSeleccion) {
	int retorno = -1;
	FILE *pArchivo = fopen(path, "r");

	if (path != NULL && pArrayListSeleccion != NULL) {
		if (pArchivo != NULL
				&& parserSeleccionDesdeTexto(pArchivo, pArrayListSeleccion)
						== 0) {
			retorno = 0;
		}
		fclose(pArchivo);
	}

	return retorno;
}
/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char *path,
		LinkedList *pArrayListSeleccion) {
	int retorno = -1;
	FILE *pArchivo = NULL;
	Seleccion *auxPunteroSeleccion = NULL;
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;

	pArchivo = fopen(path, "w");
	if (path != NULL && pArrayListSeleccion != NULL && pArchivo != NULL) {
		fprintf(pArchivo, "id,pais,confederacion,convocados\n");
		for (int i = 0; i < ll_len(pArrayListSeleccion); i++) {
			auxPunteroSeleccion = ll_get(pArrayListSeleccion, i);
			if (selec_getId(auxPunteroSeleccion, &id)
					&& selec_getPais(auxPunteroSeleccion, pais)
					&& selec_getConfederacion(auxPunteroSeleccion,
							confederacion)
					&& selec_getConvocados(auxPunteroSeleccion, &convocados)) {
				fprintf(pArchivo, "%d,%s,%s,%d\n", id, pais, confederacion,
						convocados);
				retorno = 0;
			}
		}
		fclose(pArchivo);
	}
	return retorno;
}

/** \brief Obtiene los Ids del archivo idsGenerados.txt (modo texto).
 *
 * \param void
 * \return int
 *
 */
static int controller_obtenerIdDesdeTexto(void) {
	int retorno = -1;
	FILE *pArchivo = NULL;
	char id[10];

	pArchivo = fopen("idsGenerados.txt", "r");
	if (pArchivo != NULL) {
		while (!feof(pArchivo)) {
			fscanf(pArchivo, "%[^\n]\n", id);
		}
		retorno = atoi(id);
	}
	fclose(pArchivo);
	return retorno;
}
/** \brief Genera un nuevo ID y lo guarda en el archivo idsGenerados.txt (modo texto).
 *
 * \param void
 * \return int
 *
 */
static int controller_generarIDJugador(void) {
	int retorno = -1;
	int id = 371;
	FILE *pArchivo = NULL;
	int ultimoId;

	pArchivo = fopen("idsGenerados.txt", "a");
	if (pArchivo != NULL) {
		ultimoId = controller_obtenerIdDesdeTexto();
		if (!ultimoId) {
			fprintf(pArchivo, "%d\n", id);
			retorno = id;
		} else {
			ultimoId++;
			fprintf(pArchivo, "%d\n", ultimoId);
			retorno = ultimoId;
		}
	}

	fclose(pArchivo);
	return retorno;
}

// --- Jugadores y selecciones ---
/** \brief Alta de jugadores
 *
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
static int asignarPosicion(char *pPosicion, int opcion) {
	int retorno = -1;
	if (pPosicion != NULL && opcion > 0) {
		switch (opcion) {
		case 1:
			strcpy(pPosicion, "Arqueros");
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

int controller_agregarJugador(LinkedList *pArrayListJugador) {
	int retorno = -1;
	Jugador *auxPunteroJugador = jug_new();
	char nombreCompleto[30];
	char apellido[30];
	int edad;
	char posicion[30];
	int posicionElegida;
	char nacionalidad[30];
	int id;

	if (pArrayListJugador != NULL) {
		if (utn_obtenerTexto(nombreCompleto, 100,
				"Ingrese nombre del jugador:\n",
				"Error. El nombre no puede estar vacío o tener más de 100 caracteres y tiene que ser alfabético.\n",
				100) == 0
				&& utn_obtenerTexto(apellido, 100,
						"Ingrese apellido del jugador:\n",
						"Error. El apellido no puede estar vacío o tener más de 100 caracteres y tiene que ser alfabético.\n",
						100) == 0
				&& utn_obtenerNumero(&edad, "Ingrese edad del jugador:\n",
						"Error. La edad tiene que ser un numero entero, mayor a 10 y menor a 70.\n",
						10, 70) == 0
				&& utn_obtenerNumero(&posicionElegida,
						"Ingrese que posición quiere jugar:\n1. Arquero.\n2. Defensa.\n3. Mediocampo.\n4. Delantero.\n",
						"Error. Tienes que seleccionar el número de la posición a jugar (opciones del 1 al 4).\n",
						1, 4) == 0
				&& utn_obtenerTexto(nacionalidad, 30,
						"Ingrese nacionalidad del jugador:\n",
						"Error. La nacionalidad tener más de 30 caracteres y tiene que ser alfabético.\n",
						30) == 0) {
			id = controller_generarIDJugador();
			if (id > 370 && asignarPosicion(posicion, posicionElegida) == 0) {
				strcat(nombreCompleto, " ");
				strcat(nombreCompleto, apellido);

				if (jug_setId(auxPunteroJugador, id) == 1
						&& jug_setNombreCompleto(auxPunteroJugador,
								nombreCompleto) == 1
						&& jug_setEdad(auxPunteroJugador, edad) == 1
						&& jug_setPosicion(auxPunteroJugador, posicion) == 1
						&& jug_setNacionalidad(auxPunteroJugador, nacionalidad)
								== 1
						&& jug_setIdSeleccion(auxPunteroJugador, 0) == 1) {
					if (auxPunteroJugador != NULL
							&& ll_add(pArrayListJugador, auxPunteroJugador)
									== 0) {
						retorno = 0;
						id++;
					}
				}
			}
		}
	}

	return retorno;
}

/** \brief Obtiene el index de la posición en donde está el jugador buscándolo por su id
 *
 * \param pArrayListJugador LinkedList *
 * \param idJugador int
 * \return int
 *
 */
static int controller_obtenerIndexPorId(LinkedList *pArrayListJugador,
		int idJugador) {
	int retorno = -1;
	int idObtenido;
	Jugador *auxPunteroJugador = NULL;

	for (int i = 0; i < ll_len(pArrayListJugador); i++) {
		auxPunteroJugador = (Jugador*) ll_get(pArrayListJugador, i);

		if (jug_getId(auxPunteroJugador, &idObtenido)) {
			if (idObtenido == idJugador) {
				retorno = ll_indexOf(pArrayListJugador, auxPunteroJugador);
				break;
			}
		}
	}

	return retorno;
}

/** \brief Edita los datos del jugador
 *
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList *pArrayListJugador) {
	int retorno = -1;
	int esOpcionValida;
	int mostrarSubmenu = 1;
	int idJugador;
	int opcion;
	int indexJugador;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	Jugador *pJugadorAModificar = NULL;

	if (pArrayListJugador != NULL
			&& controller_listarJugadores(pArrayListJugador) == 0) {
		if (utn_obtenerNumero(&idJugador,
				"Ingrese el ID del jugador que quiere modificar:\n",
				"Error. El ID tiene que ser un numero entero, mayor 0.\n", 0,
				9000) == 0) {
			indexJugador = controller_obtenerIndexPorId(pArrayListJugador,
					idJugador);

			pJugadorAModificar = ll_get(pArrayListJugador, indexJugador);
			if (pJugadorAModificar != NULL) {
				while (mostrarSubmenu == 1) {
					esOpcionValida =
							utn_obtenerNumero(&opcion,
									"Seleccione que va a modificar:\n1. Nombre\n2. Edad\n3. Posición\n4. Nacionalidad\n5. Salir\n",
									"Error. Tiene que elegir una opción del 1 y al 5.\n",
									1, 5);
					if (esOpcionValida == 0) {
						switch (opcion) {
						case 1:
							if (utn_obtenerTexto(nombreCompleto, 100,
									"Ingrese nombre completo del jugador:\n",
									"Error. El nombre no puede estar vacío o tener más de 100 caracteres y tiene que ser alfabético.\n",
									100) == 0) {
								jug_setNombreCompleto(pJugadorAModificar,
										nombreCompleto);
								printf(MODIFICACION_EXITOSA);
							}
							break;
						case 2:
							if (utn_obtenerNumero(&edad,
									"Ingrese edad del jugador:\n",
									"Error. La edad tiene que ser un numero entero, mayor a 10 y menor a 70.\n",
									10, 70) == 0) {
								jug_setEdad(pJugadorAModificar, edad);
								printf(MODIFICACION_EXITOSA);
							}
							break;
						case 3:
							if (utn_obtenerTexto(posicion, 30,
									"Ingrese posición del jugador:\n",
									"Error. La posición tener más de 30 caracteres y tiene que ser alfabético.\n",
									30) == 0) {
								jug_setPosicion(pJugadorAModificar, posicion);
								printf(MODIFICACION_EXITOSA);
							}
							break;
						case 4:
							if (utn_obtenerTexto(nacionalidad, 30,
									"Ingrese nacionalidad del jugador:\n",
									"Error. La nacionalidad tener más de 30 caracteres y tiene que ser alfabético.\n",
									30) == 0) {
								jug_setNacionalidad(pJugadorAModificar,
										nacionalidad);
								printf(MODIFICACION_EXITOSA);
							}
							break;
						case 5:
							mostrarSubmenu = 0;
							break;
						}
					}
				}
				retorno = 0;
			} else {
				printf("Error. ID de jugador no encontrado.\n");
			}
		}
	} else {
		printf(
				"Error. No se puede acceder a esta opción por el momento, intente más tarde.\n");
	}

	return retorno;
}

/** \brief Cuando se da de baja a un jugador convocado, resta el número de convocados de la selección del jugador
 *
 * \param pArrayListSeleccion LinkedList*
 * \param idSeleccion int
 * \param pSeleccion Seleccion*
 * \return int
 *
 */
static int controller_restarConvocado(LinkedList *pArrayListSeleccion,
		int idSeleccion, Seleccion *pSeleccion) {
	int retorno = -1;
	int idObtenido;
	int convocados;
	int auxConvocados;
	Seleccion *auxPunteroSeleccion = NULL;

	if (idSeleccion > 0 && pArrayListSeleccion != NULL) {
		for (int i = 0; i < ll_len(pArrayListSeleccion); i++) {
			auxPunteroSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);

			if (selec_getId(auxPunteroSeleccion, &idObtenido)) {
				if (idObtenido == idSeleccion) {
					pSeleccion = auxPunteroSeleccion;
					if (pSeleccion != NULL
							&& selec_getConvocados(pSeleccion, &convocados)
									== 1) {
						auxConvocados = convocados - 1;
						if (selec_setConvocados(pSeleccion, auxConvocados)
								== 1) {
							retorno = 0;
						}
						break;
					}
				}
			}
		}
	}

	return retorno;
}
/** \brief Remueve un jugador seleccionado
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion) {
	int retorno = -1;
	int idJugadorIngresado;
	int indexJugador;
	int idJugador;
	int idSeleccionJugador;
	Jugador *pJugadorARemover = NULL;
	Seleccion *pSeleccionJugador = NULL;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL
			&& controller_listarJugadores(pArrayListJugador) == 0) {
		if (utn_obtenerNumero(&idJugadorIngresado,
				"Ingrese el ID del jugador que quiere dar de baja:\n",
				"Error. El ID tiene que ser un numero entero, mayor 0.\n", 0,
				9000) == 0) {
			indexJugador = controller_obtenerIndexPorId(pArrayListJugador,
					idJugadorIngresado);
			pJugadorARemover = ll_get(pArrayListJugador, indexJugador);

			if (pJugadorARemover != NULL
					&& jug_getId(pJugadorARemover, &idJugador) == 1
					&& idJugador == idJugadorIngresado
					&& jug_getIdSeleccion(pJugadorARemover, &idSeleccionJugador)
							== 1) {
				if (idSeleccionJugador > 0) {
					if (ll_remove(pArrayListJugador, indexJugador) == 0
							&& controller_restarConvocado(pArrayListSeleccion,
									idSeleccionJugador, pSeleccionJugador)
									== 0) {
						retorno = 0;
					}
				} else {
					if (ll_remove(pArrayListJugador, indexJugador) == 0) {
						retorno = 0;
					}
				}
			}
		} else {
			printf("Error. ID de jugador no encontrado.\n");
		}
	}

	if (retorno == 0) {
		printf("Se dio de baja exitosamente\n");
	}
	return retorno;
}

/** \brief Obtiene el index de la posición en donde está la una selección buscándola por su id
 *
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_obtenerIndexSeleccionPorId(LinkedList *pArrayListSeleccion,
		int idSeleccion) {
	int retorno = -1;
	int idObtenido;
	Seleccion *auxPunteroSeleccion = NULL;

	for (int i = 0; i < ll_len(pArrayListSeleccion); i++) {
		auxPunteroSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);

		if (selec_getId(auxPunteroSeleccion, &idObtenido)) {
			if (idObtenido == idSeleccion) {
				retorno = ll_indexOf(pArrayListSeleccion, auxPunteroSeleccion);
				break;
			}
		}
	}

	return retorno;
}
/** \brief Convocar Jugador
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
static int controller_convocarJugador(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion) {
	int retorno = -1;
	int idJugador;
	int indexJugador;
	Jugador *pJugadorAConvocar = NULL;
	Seleccion *pSeleccionElegida = NULL;
	int idSeleccionIngresada;
	int idSeleccionJugador;
	int indexSeleccion;
	int convocados;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL
			&& controller_listarSelecciones(pArrayListSeleccion) == 0) {
		if (utn_obtenerNumero(&idJugador,
				"Ingrese el ID del jugador que quiere convocar:\n",
				"Error. El ID tiene que ser un numero entero, mayor 0.\n", 1,
				9000) == 0
				&& utn_obtenerNumero(&idSeleccionIngresada,
						"Ingrese el ID de la seleccion a donde quiere convocar:\n",
						"Error. El ID tiene que ser un numero entero, mayor a 0 y menor a 32.\n",
						0, 32) == 0) {
			indexJugador = controller_obtenerIndexPorId(pArrayListJugador,
					idJugador);
			pJugadorAConvocar = ll_get(pArrayListJugador, indexJugador);
			if (pJugadorAConvocar != NULL
					&& jug_getIdSeleccion(pJugadorAConvocar,
							&idSeleccionJugador) == 1) {
				indexSeleccion = controller_obtenerIndexSeleccionPorId(
						pArrayListSeleccion, idSeleccionIngresada);
				if (idSeleccionJugador != 0) {
					printf(
							"Error. El jugador ya fue convocado por una selección\n");
				} else {
					pSeleccionElegida = ll_get(pArrayListSeleccion,
							indexSeleccion);
					if (pSeleccionElegida != NULL
							&& selec_getConvocados(pSeleccionElegida,
									&convocados) == 1) {
						convocados++;
						if (convocados <= MAXIMO_CONVOCADOS) {
							if (jug_setIdSeleccion(pJugadorAConvocar,
									idSeleccionIngresada) == 1) {
								if (selec_setConvocados(pSeleccionElegida,
										convocados)) {
									selec_getConvocados(pSeleccionElegida,
											&convocados);
									retorno = 0;
								}
							}
						} else {
							printf(
									"Error. La selección ya está completa, tiene 22 jugadores y no pueden convocarse más.\n");
						}
					}
				}
			} else {
				printf("Error. ID del jugador no encontrado\n");
			}
		}
	}

	return retorno;
}
/** \brief Revisa si existen jugadores convocados
 *
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
static int controller_hayConvocados(LinkedList *pArrayListSeleccion) {
	int retorno = 0;
	int convocados;
	Seleccion *auxPunteroSeleccion = NULL;

	if (pArrayListSeleccion != NULL) {
		for (int i = 0; i < ll_len(pArrayListSeleccion); i++) {
			auxPunteroSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
			if (selec_getConvocados(auxPunteroSeleccion, &convocados) == 1
					&& convocados > 0) {
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}
/** \brief Quita a un jugador seleccionado de la seleccion que tenía asignado
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
static int controller_quitarJugadorSeleccion(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion) {
	int retorno = -1;
	int idJugador;
	int indexJugador;
	Jugador *pJugador = NULL;
	int idSeleccionJugador;
	int indexSeleccion;
	Seleccion *pSeleccion = NULL;
	int convocados;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL
			&& controller_hayConvocados(pArrayListSeleccion) == 1) {
		if (controller_listarJugadoresConvocados(pArrayListJugador,
				pArrayListSeleccion) == 0
				&& utn_obtenerNumero(&idJugador,
						"Ingrese el ID del jugador que quiere quitar de la seleccion:\n",
						"Error. El ID tiene que ser un numero entero, mayor 0.\n",
						1, 9000) == 0) {
			indexJugador = controller_obtenerIndexPorId(pArrayListJugador,
					idJugador);
			pJugador = ll_get(pArrayListJugador, indexJugador);
			if (pJugador != NULL
					&& jug_getIdSeleccion(pJugador, &idSeleccionJugador)) {
				if (idSeleccionJugador == 0) {
					printf("El jugador ingresado no está convocado\n");
				} else {
					indexSeleccion = controller_obtenerIndexSeleccionPorId(
							pArrayListSeleccion, idSeleccionJugador);
					pSeleccion = ll_get(pArrayListSeleccion, indexSeleccion);
					if (pSeleccion != NULL
							&& selec_getConvocados(pSeleccion, &convocados)) {
						if (convocados > 0) {
							convocados--;
							if (selec_setConvocados(pSeleccion, convocados)) {
								retorno = 0;
							}
						}
					}
				}
			} else {
				printf("Error. ID del jugador no encontrado\n");
			}
		}
	} else {
		printf("Error. Ninguna selección tiene convocados\n");
	}

	return retorno;
}

/** \brief Convocar jugadores
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return void
 */
int controller_convocarJugadores(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion) {
	int retorno = -1;
	int mostrarSubmenu = 1;
	int esOpcionValida;
	int opcion;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL) {
		while (mostrarSubmenu == 1) {
			esOpcionValida =
					utn_obtenerNumero(&opcion,
							"Seleccione una opción:\n1. Convocar jugador\n2. Quitar jugador de la selección\n3. Salir\n",
							"Error. Tiene que elegir una opción del 1 y al 3.\n",
							1, 3);
			if (esOpcionValida == 0) {
				switch (opcion) {
				case 1:
					if (controller_convocarJugador(pArrayListJugador,
							pArrayListSeleccion) == 0) {
						printf("Jugador convocado exitosamente\n");
					}
					break;
				case 2:
					if (controller_quitarJugadorSeleccion(pArrayListJugador,
							pArrayListSeleccion) == 0) {
						printf(
								"Jugador quitado de la selección exitosamente\n");
					}
					break;
				case 3:
					mostrarSubmenu = 0;
					break;
				}
				retorno = 0;
			}
		}
	}
	return retorno;
}

/** \brief Edita la selección
 *
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList *pArrayListSeleccion) {
	return 1;
}

// --- Ordenados y listados ---

/** \brief Listados
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return void
 */
void controller_listados(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion) {
	int mostrarSubmenu = 1;
	int esOpcionValida;
	int opcion;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL) {
		while (mostrarSubmenu == 1) {
			esOpcionValida =
					utn_obtenerNumero(&opcion,
							"Seleccione listado a ver:\n1. Jugadores\n2. Selecciones\n3. Jugadores convocados\n4. Salir\n",
							"Error. Tiene que elegir una opción del 1 y al 4.\n",
							1, 4);

			if (esOpcionValida == 0) {
				switch (opcion) {
				case 1:
					controller_listarJugadores(pArrayListJugador);
					break;
				case 2:
					controller_listarSelecciones(pArrayListSeleccion);
					break;
				case 3:
					controller_listarJugadoresConvocados(pArrayListJugador,
							pArrayListSeleccion);
					break;
				case 4:
					mostrarSubmenu = 0;
					break;
				}
			}
		}
	}
}

/** \brief Ordenar jugadores
 *
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList *pArrayListJugador) {
	int retorno = -1;
	int opcion;
	int listaOrdenada;

	if (pArrayListJugador != NULL
			&& utn_obtenerNumero(&opcion,
					"Ordenar jugadores:\n1. Por nacionalidad.\n2. Por edad.\n3. Por nombre.\n",
					"Error. Opción inválida, tiene que ser un número del 1 al 3.\n",
					1, 3) == 0) {
		// por preferencia ordené de forma ascendente
		// si queremos descendente ponemos un 0 en vez del 1
		switch (opcion) {
		case 1:
			listaOrdenada = ll_sort(pArrayListJugador, jug_compararNacionalidad,
					1);
			break;
		case 2:
			listaOrdenada = ll_sort(pArrayListJugador, jug_compararEdad, 1);
			break;
		case 3:
			listaOrdenada = ll_sort(pArrayListJugador, jug_compararNombres, 1);
			break;
		}
		if (listaOrdenada == 0
				&& controller_listarJugadores(pArrayListJugador) == 0) {
			retorno = 0;
		}
	}

	return retorno;
}

/** \brief Ordenar selecciones
 *
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList *pArrayListSeleccion) {
	int retorno = -1;

	if (pArrayListSeleccion != NULL) {
		if (ll_sort(pArrayListSeleccion, selec_compararConfederaciones, 1)
				== 0) {
			if (controller_listarSelecciones(pArrayListSeleccion) == 0) {
				retorno = 0;
			}
		}
	}
	return retorno;
}

/** \brief Ordenar y listar según la opción elegida
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarYListar(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion) {
	int retorno = -1;
	int opcion;

	if (pArrayListJugador != NULL
			&& utn_obtenerNumero(&opcion,
					"Ordenar y listar:\n1. Jugadores.\n2. Selecciones por confederación.\n",
					"Error. Opción inválida, tiene que ser un número del 1 al 2.\n",
					1, 3) == 0) {
		switch (opcion) {
		case 1:
			if (controller_ordenarJugadores(pArrayListJugador) == -1) {
				printf("Error.\n");
			}
			break;
		case 2:
			if (controller_ordenarSelecciones(pArrayListSeleccion) == -1) {
				printf("Error.\n");
			}
			break;
		}
		retorno = 0;
	}

	return retorno;
}
