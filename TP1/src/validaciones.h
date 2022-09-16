#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int obtenerNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int intentos);
int camisetaDisponible(int num, char *mensajeExito, char *mensajeError);
int posicionDisponible(int num, char *mensajeExito, char *mensajeError);
void mostrarCantidadJugadores(void);
float divisionDecimales(float numA, float numB);
int esOpcionDisponible(int totalCostos, int jugadoresIngresados);

#endif /* VALIDACIONES_H_ */
