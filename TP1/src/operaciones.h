#ifndef OPERACIONES_H_
#define OPERACIONES_H_

/**
 * @fn void ingresarCostos(void)
 * @brief Opción 1 del menú. Acá se ingresan todos los costos de mantenimiento.
 * @param void No recibe parámetros
 * @return No retorna nada
 * */
void ingresarCostos(void);
/**
 * @fn void cargarJugadores(void)
 * @brief Opción 2 del menú. Acá se ingresan jugadores y se selecciona camiseta, posición y confederación.
 * @param void No recibe parámetros
 * @return No retorna nada
 * */
void cargarJugadores(void);
/**
 * @fn void calcularResultados(float*, float*, float*, float*, float*, float*, int*, int*, int*)
 * @brief Opción 3 del menú. Acá se hacen todos los cálculos.
 * @param pAfc Dirección de memoria donde se va a guardar el porcentaje de jugadores del AFC.
 * @param pCaf Dirección de memoria donde se va a guardar el porcentaje de jugadores del CAF.
 * @param pConcacaf Dirección de memoria donde se va a guardar el porcentaje de jugadores del CONCACAF.
 * @param pConmebol Dirección de memoria donde se va a guardar el porcentaje de jugadores del CONMEBOL.
 * @param pUefa Dirección de memoria donde se va a guardar el porcentaje de jugadores de la UEFA.
 * @param pOfc Dirección de memoria donde se va a guardar el porcentaje de jugadores del OFC.
 * @param totalCostos Dirección de memoria donde se va a guardar el total de costos de mantenimiento.
 * @param totalConAumento Dirección de memoria donde se va a guardar el total de costos con el aumento incluido.
 * @param aumento Dirección de memoria donde se va a guardar el aumento sobre los precios.
 * @return No retorna nada
 * */
void calcularResultados(float *pAfc, float *pCaf, float *pConcacaf,
		float *pConmebol, float *pUefa, float *pOfc, int *totalCostos,
		int *totalConAumento, int *aumento);
/**
 * @fn void informarResultados(float, float, float, float, float, float, int, int, int)
 * @brief Opción 4 del menú. Acá se muestran todos los cálculos.
 * @param pAfc El porcentaje de jugadores del AFC.
 * @param pCaf El porcentaje de jugadores del CAF.
 * @param pConcacaf El porcentaje de jugadores del CONCACAF.
 * @param pConmebol El porcentaje de jugadores del CONMEBOL.
 * @param pUefa El porcentaje de jugadores de la UEFA.
 * @param pOfc El porcentaje de jugadores del OFC.
 * @param totalCostos El total de costos de mantenimiento.
 * @param totalConAumento El total de costos con el aumento incluido.
 * @param aumento El aumento sobre los precios.
 * @return No retorna nada
 * */
void informarResultados(float pAfc, float pCaf, float pConcacaf,
		float pConmebol, float pUefa, float pOfc, int totalCostos,
		int totalConAumento, int aumento);

#endif /* OPERACIONES_H_ */
