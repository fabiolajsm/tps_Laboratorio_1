#ifndef OPERACIONES_H_
#define OPERACIONES_H_

/**
 * @fn int ingresarCostos(int *pGastoH, int *pGastoC, int *pGastoT)
 * @brief Funcion para ingresar los costos de mantenimiento.
 * @param pGastoH Puntero en donde se van a guardar todos los gastos de hospedaje
 * @param pGastoC Puntero en donde se van a guardar todos los gastos de comida
 * @param pGastoT Puntero en donde se van a guardar todos los gastos de transporte
 * @return Retorna 0 si no hubo error y -1 si hubo algun error.
 * */
int ingresarCostos(int *pGastoH, int *pGastoC, int *pGastoT);
/**
 * @fn int cargarJugadores(int *pAfc, int *pCaf, int *pConcacaf, int *pConmebol,
 int *pUefa, int *pOfc, int *pArqueros, int *pDefensores,
 int *pMediocampistas, int *pDelanteros, float *pTotalJugadores)
 * @brief Opción 2 del menú. Acá se ingresan jugadores y se selecciona camiseta, posición y confederación.
 * @param pAfc Dirección de memoria donde se va a guardar el total de jugadores del AFC.
 * @param pCaf Dirección de memoria donde se va a guardar el total de jugadores del CAF.
 * @param pConcacaf Dirección de memoria donde se va a guardar el total de jugadores del CONCACAF.
 * @param pConmebol Dirección de memoria donde se va a guardar el total de jugadores del CONMEBOL.
 * @param pUefa Dirección de memoria donde se va a guardar el total de jugadores de la UEFA.
 * @param pOfc Dirección de memoria donde se va a guardar el total de jugadores del OFC.
 * @param pArqueros Dirección de memoria donde se va a guardar el total de arqueros.
 * @param pDefensores Dirección de memoria donde se va a guardar el total de defensores.
 * @param pMediocampistas Dirección de memoria donde se va a guardar el total de mediocampistas.
 * @param pDelanteros Dirección de memoria donde se va a guardar el total de delanteros.
 * @param pTotalJugadores Dirección de memoria donde se va a guardar el total de jugadores.
 * @return Retorna 0 si no hubo error y -1 si hubo algun error.
 * */
int cargarJugadores(int *pAfc, int *pCaf, int *pConcacaf, int *pConmebol,
		int *pUefa, int *pOfc, int *pArqueros, int *pDefensores,
		int *pMediocampistas, int *pDelanteros, float *pTotalJugadores);
/**
 * @fn int calcularResultados(float*, float*, float*, float*, float*, float*, int*, int*, int*)
 * @brief Opción 3 del menú. Acá se hacen todos los cálculos.
 * @param gastoHospedaje Total de los gastos de hospedaje
 * @param gastoComida Total de los gastos de comida
 * @param gastoTransporte Total de los gastos de transporte
 * @param totalCostos Dirección de memoria donde se va a guardar el total de los costos de mantenimiento
 * @param totalJugadores Cantidad de jugadores
 * @param totalAfc total de jugadores en la confederacion AFC
 * @param totalCaf total de jugadores en la confederacion CAF
 * @param totalConcacaf total de jugadores en la confederacion CONCACAF
 * @param totalConmebol total de jugadores en la confederacion CONMEBOL
 * @param totalUefa total de jugadores en la confederacion UEFA
 * @param totalOfc total de jugadores en la confederacion OFC
 * @param pAfc Dirección de memoria donde se va a guardar el porcentaje de jugadores del AFC
 * @param pCaf Dirección de memoria donde se va a guardar el porcentaje de jugadores del CAF
 * @param pConcacaf Dirección de memoria donde se va a guardar el porcentaje de jugadores del CONCACAF
 * @param pConmebol Dirección de memoria donde se va a guardar el porcentaje de jugadores del CONMEBOL
 * @param pUefa Dirección de memoria donde se va a guardar el porcentaje de jugadores de la UEFA
 * @param pOfc Dirección de memoria donde se va a guardar el porcentaje de jugadores del OFC
 * @param totalConAumento Dirección de memoria donde se va a guardar el total de costos con el aumento incluido
 * @param aumento Dirección de memoria donde se va a guardar el aumento sobre los precios
 * @return Retorna 0 si no hubo error y -1 si hubo algun error.
 * */
int calcularResultados(int gastoHospedaje, int gastoComida, int gastoTransporte,
		int *totalCostos, float totalJugadores, int totalAfc, int totalCaf,
		int totalConcacaf, int totalConmebol, int totalUefa, int totalOfc,
		float *pAfc, float *pCaf, float *pConcacaf, float *pConmebol,
		float *pUefa, float *pOfc, int *totalConAumento, int *aumento);
/**
 * @fn void informarResultados(float, float, float, float, float, float, int, int, int)
 * @brief Opción 4 del menú. Acá se muestran todos los cálculos.
 * @param pAfc El porcentaje de jugadores del AFC
 * @param pCaf El porcentaje de jugadores del CAF
 * @param pConcacaf El porcentaje de jugadores del CONCACAF
 * @param pConmebol El porcentaje de jugadores del CONMEBOL
 * @param pUefa El porcentaje de jugadores de la UEFA
 * @param pOfc El porcentaje de jugadores del OFC
 * @param totalCostos El total de costos de mantenimiento
 * @param totalAfc total de jugadores en la confederacion AFC
 * @param totalCaf total de jugadores en la confederacion CAF
 * @param totalConcacaf total de jugadores en la confederacion CONCACAF
 * @param totalConmebol total de jugadores en la confederacion CONMEBOL
 * @param totalUefa total de jugadores en la confederacion UEFA
 * @param totalOfc total de jugadores en la confederacion OFC
 * @param totalConAumento El total de costos con el aumento incluido
 * @param aumento El aumento sobre los precios.
 * @return No retorna nada, solo imprime los resultados
 * */
void informarResultados(float pAfc, float pCaf, float pConcacaf,
		float pConmebol, float pUefa, float pOfc, int totalCostos, int totalAfc,
		int totalCaf, int totalConcacaf, int totalConmebol, int totalUefa,
		int totalOfc, int totalConAumento, int aumento);
/**
 * @fn int sePuedeCalcular(int, int)
 * @brief Esta función valida si la opción tres para calcular resultados puede ser usada
 * @param ingresaronCostos Variable que indica si se han ingresado costos
 * @param totalJugadores La cantidad de jugadores que se han ingresado
 * @return Retorna 0 si no hay costos ni/o jugadores ingresados y 1 si ya fueron ingresados y se pueden realizar los cálculos.
 * */
int sePuedeCalcular(int ingresaronCostos, int totalJugadores);

#endif /* OPERACIONES_H_ */
