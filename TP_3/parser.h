#ifndef PARSER_H_
#define PARSER_H_

int parserJugadorDesdeTexto(FILE *pArchivo, LinkedList *pArrayListJugador);
int parser_JugadorFromBinary(FILE *pFile, LinkedList *pArrayListJugador);
int parserSeleccionDesdeTexto(FILE *pArchivo, LinkedList *pArrayListSeleccion);

#endif /* PARSER_H_ */
