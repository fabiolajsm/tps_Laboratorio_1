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
 * \param pListaJugadores LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char *path,
		LinkedList *pListaJugadores) {
	int retorno = -1;
	FILE *pArchivo = NULL;

	if (path != NULL && pListaJugadores != NULL) {
		pArchivo = fopen(path, "r");
		if (pArchivo != NULL
				&& parserJugadorDesdeTexto(pArchivo, pListaJugadores) == 0) {
			retorno = 0;
		}
		fclose(pArchivo);
	}

	return retorno;
}
/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pListaJugadores LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char *path,
		LinkedList *pListaJugadores) {
	int retorno = -1;
	FILE *pArchivo = NULL;

	if (path != NULL && pListaJugadores != NULL) {
		pArchivo = fopen(path, "rb");
		if (pArchivo != NULL
				&& parserJugadorDesdeBinario(pArchivo, pListaJugadores) == 0) {
			retorno = 0;
		}
		fclose(pArchivo);
	}
	return retorno;
}
/** \brief Carga los datos de las selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pListaSelecciones LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char *path,
		LinkedList *pListaSelecciones) {
	int retorno = -1;
	FILE *pArchivo = NULL;

	if (path != NULL && pListaSelecciones != NULL) {
		pArchivo = fopen(path, "r");
		if (pArchivo != NULL
				&& parserSeleccionDesdeTexto(pArchivo, pListaSelecciones)
						== 0) {
			retorno = 0;
		}
		fclose(pArchivo);
	}

	return retorno;
}
/** \brief Genera un nuevo archivo con los datos de los jugadores en modo binario
 *
 * \param path char*
 * \param pListaJugadores LinkedList*
 * \return int
 *
 */
int controller_generarJugadoresDesdeBinario(char *path,
		LinkedList *pListaJugadores) {
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

	if (path != NULL && pListaJugadores != NULL) {
		pArchivo = fopen(path, "w");
		if (pArchivo != NULL) {
			if (utn_obtenerNumero(&idSeleccionIngresada,
					"Ingrese el ID de la confederación en donde están los jugadores que desee guardar:\n",
					"Error. El ID tiene que ser un numero entero, mayor a 0 y menor a 32.\n",
					0, 32) == 0) {
				for (int i = 0; i < ll_len(pListaJugadores); i++) {
					auxPunteroJugador = (Jugador*) ll_get(pListaJugadores, i);
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
	if (retorno == -1) {
		printf("Esta confederacion, no tiene jugadores convocados\n");
	}
	return retorno;
}
/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pListaJugadores LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char *path,
		LinkedList *pListaJugadores) {
	int retorno = -1;
	FILE *pArchivo = NULL;

	if (path != NULL && pListaJugadores != NULL) {
		pArchivo = fopen(path, "w");
		if (pArchivo != NULL
				&& parserGuardarJugadoresFormatoTexto(pArchivo, pListaJugadores)
						== 0) {
			retorno = 0;
		}
		fclose(pArchivo);
	}
	return retorno;
}
/** \brief Guarda los datos de los jugadores en un archivo binario
 *
 * \param path char*
 * \param pListaJugadores LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char *path,
		LinkedList *pListaJugadores) {
	int retorno = -1;
	FILE *pArchivo;
	Jugador *pAuxJugador;

	if (path != NULL && pListaJugadores != NULL) {
		pArchivo = fopen(path, "wb");
		if (pArchivo != NULL) {
			for (int i = 0; i < ll_len(pListaJugadores); i++) {
				pAuxJugador = ll_get(pListaJugadores, i);
				if (pAuxJugador != NULL) {
					fwrite(pAuxJugador, sizeof(Jugador), 1, pArchivo);
				}
			}
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pListaSelecciones LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char *path,
		LinkedList *pListaSelecciones) {
	int retorno = -1;
	FILE *pArchivo = NULL;

	if (path != NULL && pListaSelecciones != NULL) {
		pArchivo = fopen(path, "w");
		if (pArchivo != NULL
				&& parserGuardarSeleccionesFormatoTexto(pArchivo,
						pListaSelecciones) == 0) {
			retorno = 0;
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

// --- Listados ---
/** \brief Listar jugador
 *
 * \param item Jugador*
 * \param confederacion char*
 * \return void
 *
 */
static void controller_listarJugador(Jugador *item, char *confederacion) {
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;

	if (item != NULL && confederacion != NULL && jug_getId(item, &id) == 1
			&& jug_getNombreCompleto(item, nombreCompleto) == 1
			&& jug_getEdad(item, &edad) == 1
			&& jug_getPosicion(item, posicion) == 1
			&& jug_getNacionalidad(item, nacionalidad) == 1
			&& jug_getIdSeleccion(item, &idSeleccion) == 1) {
		printf("| %*d | %*s | %*d | %*s | %*s | %*s  |\n", -3, id, -28,
				nombreCompleto, -5, edad, -24, posicion, -18, nacionalidad, -17,
				confederacion);
	}
}
/** \brief Listar jugadores
 *
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList *pListaJugadores,
		LinkedList *pListaSelecciones) {
	int retorno = -1;
	Jugador *pAuxJugador = NULL;
	int indexJugador;
	int idSeleccionJugador;
	Seleccion *pAuxSeleccion = NULL;
	int indexSeleccion;
	int idSeleccion;
	char confederacion[30];

	if (pListaJugadores != NULL && pListaSelecciones) {
		printf("\t\t\t\t\t- Listado de Jugadores -\n");
		printf(
				"==================================================================================================================\n");
		printf("|%*s|%*s|%*s|%*s|%*s|%s|\n", -5, " ID", -30, " NOMBRE", -7,
				" EDAD", -27, " POSICIÓN", -20, " NACIONALIDAD",
				" SELECCIÓN          ");
		printf(
				"------------------------------------------------------------------------------------------------------------------\n");
		for (int i = 0; i <= ll_len(pListaJugadores); i++) {
			strcpy(confederacion, "No esta convocado");
			indexJugador = controller_obtenerIndexPorId(pListaJugadores, i);
			pAuxJugador = (Jugador*) ll_get(pListaJugadores, indexJugador);
			if (pAuxJugador != NULL
					&& jug_getIdSeleccion(pAuxJugador, &idSeleccionJugador)) {
				if (idSeleccionJugador != 0) {
					for (int j = 0; j <= ll_len(pListaSelecciones); j++) {
						indexSeleccion = controller_obtenerIndexSeleccionPorId(
								pListaSelecciones, j);
						pAuxSeleccion = (Seleccion*) ll_get(pListaSelecciones,
								indexSeleccion);
						if (pAuxSeleccion != NULL
								&& selec_getId(pAuxSeleccion, &idSeleccion)) {
							if (idSeleccion == idSeleccionJugador) {
								selec_getConfederacion(pAuxSeleccion,
										confederacion);
								break;
							}
						}
					}
				}
				controller_listarJugador(pAuxJugador, confederacion);
				retorno = 0;
			}
		}
		printf(
				"==================================================================================================================\n");
	}

	return retorno;
}

/** \brief Listar convocados
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarJugadoresConvocados(LinkedList *pListaJugadoresConvocados,
		LinkedList *pListaSelecciones) {
	int retorno = -1;
	Jugador *pAuxJugador = NULL;
	int indexJugador;
	int idSeleccionJugador;
	Seleccion *pAuxSeleccion = NULL;
	int indexSeleccion;
	int idSeleccion;
	char confederacion[30];

	if (ll_isEmpty(pListaJugadoresConvocados) == 1) {
		printf("No hay jugadores convocados\n");
		return -1;
	} else {
		if (pListaJugadoresConvocados != NULL && pListaSelecciones) {
			printf("\t\t\t\t\t- Jugadores Convocados -\n");
			printf(
					"==================================================================================================================\n");
			printf("|%*s|%*s|%*s|%*s|%*s|%s|\n", -5, " ID", -30, " NOMBRE", -7,
					" EDAD", -27, " POSICIÓN", -20, " NACIONALIDAD",
					" SELECCIÓN          ");
			printf(
					"------------------------------------------------------------------------------------------------------------------\n");
			for (int i = 0; i <= ll_len(pListaJugadoresConvocados); i++) {
				strcpy(confederacion, "No esta convocado");
				indexJugador = controller_obtenerIndexPorId(
						pListaJugadoresConvocados, i);
				pAuxJugador = (Jugador*) ll_get(pListaJugadoresConvocados,
						indexJugador);
				if (pAuxJugador != NULL
						&& jug_getIdSeleccion(pAuxJugador,
								&idSeleccionJugador)) {
					if (idSeleccionJugador != 0) {
						for (int j = 0; j <= ll_len(pListaSelecciones); j++) {
							indexSeleccion =
									controller_obtenerIndexSeleccionPorId(
											pListaSelecciones, j);
							pAuxSeleccion = (Seleccion*) ll_get(
									pListaSelecciones, indexSeleccion);
							if (pAuxSeleccion != NULL
									&& selec_getId(pAuxSeleccion,
											&idSeleccion)) {
								if (idSeleccion == idSeleccionJugador) {
									selec_getConfederacion(pAuxSeleccion,
											confederacion);
									break;
								}
							}
						}
					}
					controller_listarJugador(pAuxJugador, confederacion);
				}
			}
			printf(
					"==================================================================================================================\n");
			retorno = 0;
		}
	}

	return retorno;
}
/** \brief Listar seleccion
 *
 * \param item Seleccion*
 * \return void
 *
 */
static void controller_listarSeleccion(Seleccion *item) {
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;

	if (item != NULL && selec_getId(item, &id) == 1
			&& selec_getPais(item, pais) == 1
			&& selec_getConfederacion(item, confederacion) == 1
			&& selec_getConvocados(item, &convocados) == 1) {
		printf("| %*d | %*s | %*s |       %*d |\n", -3, id, -17, pais, -13,
				confederacion, -6, convocados);
	}
}

/** \brief Listar selecciones
 *
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList *pArrayListSeleccion) {
	int retorno = -1;
	int largo = ll_len(pArrayListSeleccion);

	if (pArrayListSeleccion != NULL && largo > 0) {
		printf("\t\t- Listado de Selecciones -\n");
		printf("==========================================================\n");
		printf("|%*s|%*s|%*s|%*s|\n", -5, " ID", -20, " PAÍS", -7,
				" CONFEDERACIÓN ", -14, " CONVOCADOS");
		printf("---------------------------------------------------------\n");
		for (int i = 0; i < largo; i++) {
			controller_listarSeleccion(
					(Seleccion*) ll_get(pArrayListSeleccion, i));
		}
		printf("==========================================================\n");
		retorno = 0;
	}

	return retorno;
}

// --- Jugadores y selecciones ---
static int asignarPosicion(char *pPosicion, int opcion) {
	int retorno = -1;
	if (pPosicion != NULL && opcion > 0) {
		switch (opcion) {
		case 1:
			strcpy(pPosicion, "Portero");
			break;
		case 2:
			strcpy(pPosicion, "Defensa central");
			break;
		case 3:
			strcpy(pPosicion, "Lateral izquierdo");
			break;
		case 4:
			strcpy(pPosicion, "Lateral derecho");
			break;
		case 5:
			strcpy(pPosicion, "Pivote");
			break;
		case 6:
			strcpy(pPosicion, "Mediocentro");
			break;
		case 7:
			strcpy(pPosicion, "Mediocentro ofensivo");
			break;
		case 8:
			strcpy(pPosicion, "Extremo izquierdo");
			break;
		case 9:
			strcpy(pPosicion, "Extremo derecho");
			break;
		case 10:
			strcpy(pPosicion, "Mediapunta");
			break;
		case 11:
			strcpy(pPosicion, "Delantero centro");
			break;
		case 12:
			strcpy(pPosicion, "Interior derecho");
			break;
		default:
			retorno = -1;
			break;
		}
		retorno = 0;
	}
	return retorno;
}
static int asignarNacionalidad(char *pNacionalidad, int opcion) {
	int retorno = -1;
	if (pNacionalidad != NULL && opcion > 0) {
		switch (opcion) {
		case 1:
			strcpy(pNacionalidad, "Argentino");
			break;
		case 2:
			strcpy(pNacionalidad, "Brasilero");
			break;
		case 3:
			strcpy(pNacionalidad, "Uruguayo");
			break;
		case 4:
			strcpy(pNacionalidad, "Portugues");
			break;
		case 5:
			strcpy(pNacionalidad, "Ingles");
			break;
		case 6:
			strcpy(pNacionalidad, "Aleman");
			break;
		case 7:
			strcpy(pNacionalidad, "Mexicano");
			break;
		case 8:
			strcpy(pNacionalidad, "Estado Unidense");
			break;
		case 9:
			strcpy(pNacionalidad, "Camerunes");
			break;
		case 10:
			strcpy(pNacionalidad, "Senegales");
			break;
		case 11:
			strcpy(pNacionalidad, "Australiano");
			break;
		case 12:
			strcpy(pNacionalidad, "Qatari");
			break;
		default:
			retorno = -1;
			break;
		}
		retorno = 0;
	}
	return retorno;
}
/** \brief Alta de jugadores
 *
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList *pArrayListJugador) {
	int retorno = -1;
	Jugador *auxPunteroJugador = jug_new();
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	int posicionElegida;
	char nacionalidad[30];
	int nacionalidadElegida;
	int id;

	if (pArrayListJugador != NULL) {
		if (utn_obtenerTexto(nombreCompleto, 100,
				"Ingrese nombre completo del jugador:\n",
				"Error. El nombre no puede estar vacío o tener más de 100 caracteres y tiene que ser alfabético.\n",
				100) == 0
				&& utn_obtenerNumero(&edad, "Ingrese edad del jugador:\n",
						"Error. La edad tiene que ser un numero entero, mayor a 10 y menor a 70.\n",
						10, 70) == 0
				&& utn_obtenerNumero(&posicionElegida,
						"Ingrese que posición quiere jugar:\n1. Portero.\n2. Defensa central.\n3. Lateral izquierdo.\n4. Lateral derecho.\n5. Pivote.\n6. Mediocentro.\n7. Mediocentro ofensivo.\n8. Extremo izquierdo.\n9. Extremo derecho.\n10. Mediapunta.\n11. Delantero centro.\n12. Interior derecho.\n",
						"Error. Tienes que seleccionar el número de la posición a jugar (opciones del 1 al 12).\n",
						1, 12) == 0
				&& utn_obtenerNumero(&nacionalidadElegida,
						"Ingrese nacionalidad del jugador:\n1. Argentino.\n2. Brasilero.\n3. Uruguayo.\n4. Portugues.\n5. Ingles.\n6. Aleman.\n7. Mexicano.\n8. Estado Unidense.\n9. Camerunes.\n10. Senegales.\n11. Australiano.\n12. Qatari.\n",
						"Error. Tienes que seleccionar el número de la nacionalidad correspondiente (opciones del 1 al 12).\n",
						1, 30) == 0) {
			id = controller_generarIDJugador();
			if (id > 370 && asignarPosicion(posicion, posicionElegida) == 0
					&& asignarNacionalidad(nacionalidad, nacionalidadElegida)
							== 0) {
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

/** \brief Edita los datos del jugador
 *
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList *pListaJugadores,
		LinkedList *pListaSelecciones) {
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

	if (pListaJugadores != NULL && pListaSelecciones != NULL
			&& controller_listarJugadores(pListaJugadores, pListaSelecciones)
					== 0) {
		if (utn_obtenerNumero(&idJugador,
				"Ingrese el ID del jugador que quiere modificar:\n",
				"Error. El ID tiene que ser un numero entero, mayor 0.\n", 0,
				9000) == 0) {
			indexJugador = controller_obtenerIndexPorId(pListaJugadores,
					idJugador);

			pJugadorAModificar = ll_get(pListaJugadores, indexJugador);
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
int controller_removerJugador(LinkedList *pListaJugadores,
		LinkedList *pListaSelecciones) {
	int retorno = -1;
	int idJugadorIngresado;
	int indexJugador;
	int idJugador;
	int idSeleccionJugador;
	int confirmacion;
	Jugador *pJugadorARemover = NULL;
	Seleccion *pSeleccionJugador = NULL;

	if (pListaJugadores != NULL && pListaSelecciones != NULL
			&& controller_listarJugadores(pListaJugadores, pListaSelecciones)
					== 0) {
		if (utn_obtenerNumero(&idJugadorIngresado,
				"Ingrese el ID del jugador que quiere dar de baja:\n",
				"Error. El ID tiene que ser un numero entero, mayor 0.\n", 0,
				9000) == 0) {
			indexJugador = controller_obtenerIndexPorId(pListaJugadores,
					idJugadorIngresado);
			pJugadorARemover = ll_get(pListaJugadores, indexJugador);

			if (pJugadorARemover != NULL) {
				if (jug_getId(pJugadorARemover, &idJugador) == 1
						&& idJugador == idJugadorIngresado
						&& jug_getIdSeleccion(pJugadorARemover,
								&idSeleccionJugador) == 1) {
					if (idSeleccionJugador > 0) {
						if (utn_obtenerNumero(&confirmacion,
								"Este jugador está convocado en una selección. Seguro desea eliminarlo?\n1. Si.\n2. No.\n",
								"Error. Opción inválida, tiene que elegir un número del 1 al 2.\n",
								1, 2) == 0 && confirmacion == 1) {
							if (ll_remove(pListaJugadores, indexJugador) == 0
									&& controller_restarConvocado(
											pListaSelecciones,
											idSeleccionJugador,
											pSeleccionJugador) == 0) {
								retorno = 0;
							}
						}
					} else {
						if (ll_remove(pListaJugadores, indexJugador) == 0) {
							retorno = 0;
						}
					}
				}
			} else {
				printf("Error. ID de jugador no encontrado.\n");
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
		LinkedList *pArrayListSeleccion, LinkedList *pArrayListConvocados) {
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
			&& pArrayListConvocados != NULL) {
		if (controller_listarJugadores(pArrayListJugador, pArrayListSeleccion)
				== 0
				&& utn_obtenerNumero(&idJugador,
						"Ingrese el ID del jugador que quiere convocar:\n",
						"Error. El ID tiene que ser un numero entero, mayor 0 y menor a 9000.\n",
						1, 9000) == 0) {
			indexJugador = controller_obtenerIndexPorId(pArrayListJugador,
					idJugador);
			pJugadorAConvocar = ll_get(pArrayListJugador, indexJugador);
			// Verifico que el jugador exista
			if (pJugadorAConvocar != NULL) {
				if (jug_getIdSeleccion(pJugadorAConvocar, &idSeleccionJugador)
						== 1) {
					if (idSeleccionJugador != 0) {
						printf(
								"Error. El jugador ya fue convocado por una selección\n");
					} else {
						if (controller_listarSelecciones(pArrayListSeleccion)
								== 0
								&& utn_obtenerNumero(&idSeleccionIngresada,
										"Ingrese el ID de la seleccion a donde quiere convocar:\n",
										"Error. El ID tiene que ser un numero entero, mayor a 0 y menor a 33.\n",
										1, 32) == 0) {
							indexSeleccion =
									controller_obtenerIndexSeleccionPorId(
											pArrayListSeleccion,
											idSeleccionIngresada);
							pSeleccionElegida = ll_get(pArrayListSeleccion,
									indexSeleccion);
							// Verifico que la selección exista
							if (pSeleccionElegida != NULL
									&& selec_getConvocados(pSeleccionElegida,
											&convocados) == 1) {
								convocados++;
								if (convocados <= MAXIMO_CONVOCADOS) {
									if (jug_setIdSeleccion(pJugadorAConvocar,
											idSeleccionIngresada)
											&& selec_setConvocados(
													pSeleccionElegida,
													convocados)) {
										if (ll_add(pArrayListConvocados,
												pJugadorAConvocar) == 0) {
											retorno = 0;
										}
									}
								} else {
									printf(
											"Error. No se puede convocar mas jugadores a esta selección, ya está completa y tiene 22 jugadores.\n");
								}
							} else {
								printf("Error. Selección no encontrada\n");
							}
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
/** \brief Quita a un jugador seleccionado de la seleccion que tenía asignado
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
static int controller_quitarJugadorSeleccion(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion, LinkedList *pArrayListConvocados) {
	int retorno = -1;
	int idJugador;
	int indexJugador;
	Jugador *pJugador = NULL;
	int idSeleccionJugador;
	int indexSeleccion;
	Seleccion *pSeleccion = NULL;
	int convocados;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL
			&& pArrayListConvocados != NULL
			&& controller_listarJugadoresConvocados(pArrayListConvocados,
					pArrayListSeleccion) == 0) {
		if (utn_obtenerNumero(&idJugador,
				"Ingrese el ID del jugador que quiere quitar de la seleccion:\n",
				"Error. El ID tiene que ser un numero entero, mayor 0.\n", 1,
				9000) == 0) {
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
							if (selec_setConvocados(pSeleccion, convocados)
									&& jug_setIdSeleccion(pJugador, 0)
									&& ll_remove(pArrayListConvocados,
											indexJugador) == 0) {
								retorno = 0;
							}
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

/** \brief Convocar jugadores
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return void
 */
int controller_convocarJugadores(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion, LinkedList *pArrayListConvocados) {
	int retorno = -1;
	int mostrarSubmenu = 1;
	int esOpcionValida;
	int opcion;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL
			&& pArrayListConvocados != NULL) {
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
							pArrayListSeleccion, pArrayListConvocados) == 0) {
						printf("Jugador convocado exitosamente\n");
					}
					break;
				case 2:
					if (controller_quitarJugadorSeleccion(pArrayListJugador,
							pArrayListSeleccion, pArrayListConvocados) == 0) {
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
		LinkedList *pArrayListSeleccion, LinkedList *pArrayListConvocados) {
	int mostrarSubmenu = 1;
	int esOpcionValida;
	int opcion;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL
			&& pArrayListConvocados != NULL) {
		while (mostrarSubmenu == 1) {
			esOpcionValida =
					utn_obtenerNumero(&opcion,
							"Seleccione listado a ver:\n1. Jugadores\n2. Selecciones\n3. Jugadores convocados\n4. Salir\n",
							"Error. Tiene que elegir una opción del 1 y al 4.\n",
							1, 4);
			if (esOpcionValida == 0) {
				switch (opcion) {
				case 1:
					if (controller_listarJugadores(pArrayListJugador,
							pArrayListSeleccion) == -1) {
						printf("No se pudieron listar jugadores\n");
					}
					break;
				case 2:
					if (controller_listarSelecciones(pArrayListSeleccion)
							== -1) {
						printf("No se pudieron listar selecciones\n");
					}
					break;
				case 3:
					if (controller_listarJugadoresConvocados(
							pArrayListConvocados, pArrayListSeleccion) == -1) {
						printf("No se pudieron listar jugadores convocados\n");
					}
					break;
				case 4:
					mostrarSubmenu = 0;
					break;
				}
			}
		}
	}
}

static int seleccionarOrden() {
	int ordenElegido = 1;
	if (utn_obtenerNumero(&ordenElegido,
			"Mostrar de forma:\n1. Ascendente.\n2. Descendente.\n",
			"Error. Opción inválida, tiene que ser 1 o 2.\n", 1, 2) == 0) {
		if (ordenElegido == 2) {
			ordenElegido = 0;
		}
	}
	return ordenElegido;
}

/** \brief Ordenar jugadores
 *
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion) {
	int retorno = -1;
	int opcion;
	int listaOrdenada;
	int mostrarSubmenu = 1;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL) {
		while (mostrarSubmenu) {
			if (utn_obtenerNumero(&opcion,
					"Ordenar jugadores:\n1. Por nacionalidad.\n2. Por edad.\n3. Por nombre.\n4. Salir.\n",
					"Error. Opción inválida, tiene que ser un número del 1 al 4.\n",
					1, 4) == 0) {
				// si queremos mostar en orden descendente ponemos un 0 y si queremos mostrar en forma ascendente ponemos 1
				switch (opcion) {
				case 1:
					listaOrdenada = ll_sort(pArrayListJugador,
							jug_compararNacionalidad, seleccionarOrden());
					break;
				case 2:
					listaOrdenada = ll_sort(pArrayListJugador, jug_compararEdad,
							seleccionarOrden());
					break;
				case 3:
					listaOrdenada = ll_sort(pArrayListJugador,
							jug_compararNombres, seleccionarOrden());
					break;
				case 4:
					printf("Submenú ordenar jugadores cerrado\n");
					mostrarSubmenu = 0;
					break;
				}
				if (listaOrdenada == 0
						&& controller_listarJugadores(pArrayListJugador,
								pArrayListSeleccion) == 0) {
					retorno = 0;
				}
			}
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
		if (ll_sort(pArrayListSeleccion, selec_compararConfederaciones,
				seleccionarOrden()) == 0) {
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
	int mostrarSubmenu = 1;

	if (pArrayListJugador != NULL) {
		while (mostrarSubmenu) {
			if (utn_obtenerNumero(&opcion,
					"Ordenar y listar:\n1. Jugadores.\n2. Selecciones por confederación.\n3. Salir.\n",
					"Error. Opción inválida, tiene que ser un número del 1 al 2.\n",
					1, 3) == 0) {
				switch (opcion) {
				case 1:
					if (controller_ordenarJugadores(pArrayListJugador,
							pArrayListSeleccion) == -1) {
						printf("Error.\n");
					}
					break;
				case 2:
					if (controller_ordenarSelecciones(pArrayListSeleccion)
							== -1) {
						printf("Error.\n");
					}
					break;
				case 3:
					printf("Submenú ordenar y listar cerrado\n");
					mostrarSubmenu = 0;
					break;
				}
			}
			retorno = 0;
		}
	}

	return retorno;
}
