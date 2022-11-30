#ifndef PARSER_H_
#define PARSER_H_

int parserJugadorDesdeTexto(FILE *pArchivo, LinkedList *pListaJugadores);
int parserJugadorDesdeBinario(FILE *pArchivo, LinkedList *pListaJugadores);
int parserSeleccionDesdeTexto(FILE *pArchivo, LinkedList *pListaSelecciones);
int parserGuardarJugadoresFormatoTexto(FILE *pArchivo,
		LinkedList *pListaJugadores);
int parserGuardarSeleccionesFormatoTexto(FILE *pArchivo,
		LinkedList *pListaSelecciones);

#endif /* PARSER_H_ */
