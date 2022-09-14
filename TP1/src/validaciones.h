#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo, int intentos);
int camisetaDisponible(int num, char *mensajeExito, char *mensajeError);
int posicionDisponible(int num, char *mensajeExito, char *mensajeError);
void mostrarCantidadJugadores();
float divisionDecimales(float numA, float numB);
int esOpcionDisponible(int mantenimiento, int jugadores);

#endif /* VALIDACIONES_H_ */
