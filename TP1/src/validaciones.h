#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/**
 * @fn int obtenerNumero(int*, char *, char *, int , int , int)
 * @brief Esta función pide un número entero y verifica que sea válido.
 * @param pResultado Dirección de memoria donde va a ser guardado el número después de validar.
 * @param mensaje Mensaje a mostrar cuando la función pida el número.
 * @param mensajeError Mensaje a mostrar si lo ingresado no es válido.
 * @param minimo Mínimo número a ingresar.
 * @param maximo Máximo número a ingresar.
 * @param intentos Número de intentos para que ingrese un número válido.
 * @return Retorna 0 si se realizó bien la función y -1 si hubo un error.
 * */
int obtenerNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int intentos);
/**
 * @fn int camisetaDisponible(int, char *, char *)
 * @brief Esta función selecciona un número de camiseta y valida que no se repitan los números ya escojidos.
 * @param num Número de camiseta ingresado.
 * @param mensaje Mensaje a mostrar si el número de camiseta fue seleccionado exitosamente.
 * @param mensajeError Mensaje a mostrar si el número de camiseta no está disponible.
 * @return Retorna 1 si está disponible la camiseta y 0 si ya fue seleccionada.
 * */
int camisetaDisponible(int num, char *mensajeExito, char *mensajeError);
/**
 * @fn int posicionDisponible(int, char *, char *)
 * @brief Esta función valida que la posición seleccionada para jugar tenga cupos disponibles.
 * @param num Es la posición a jugar ingresada.
 * @param mensaje Mensaje a mostrar si la posición fue seleccionada exitosamente.
 * @param mensajeError Mensaje a mostrar si no está disponible la posición seleccionada.
 * @return Retorna 1 si está disponible la camiseta y 0 si ya fue seleccionada.
 * */
int posicionDisponible(int num, char *mensajeExito, char *mensajeError);
/**
 * @fn void mostrarCantidadJugadores(void)
 * @brief Esta función muestra la cantidad de jugadores que hay en cada posición.
 * @param void No recibe parámetros.
 * @return No retorna nada, sólo imprime el resultado.
 * */
void mostrarCantidadJugadores(void);
/**
 * @fn float divisionDecimales(float, float)
 * @brief Esta función divide dos numeros decimales.
 * @param numA Número a usar como numerador.
 * @param numB Número a usar como denominador.
 * @return Retorna -1 si hay error y el denominador es 0, y si es válido, la división entre los números.
 * */
float divisionDecimales(float numA, float numB);
/**
 * @fn int sePuedeCalcular(int, int)
 * @brief Esta función valida si la opción tres para calcular puede ser usada.
 * @param costos La suma de los costos de mantenimiento.
 * @param jugadoresIngresados La cantidad de jugadores que se han ingresado.
 * @return Retorna 0 si no hay costos ni/o jugadores ingresados y 1 si ya fueron ingresados y se pueden realizar los cálculos.
 * */
int sePuedeCalcular(int costos, int jugadoresIngresados);

#endif /* VALIDACIONES_H_ */
