#ifndef OPERACIONES_H_
#define OPERACIONES_H_

void ingresarCostos();
void cargaDeJugadores();
void calcular(float *pAfc, float *pCaf, float *pConcacaf, float *pConmebol,
		float *pUefa, float *pOfc, int *totalCostos, int *totalConAumento,
		int *aumento);
void informarResultados(float pAfc, float pCaf, float pConcacaf,
		float pConmebol, float pUefa, float pOfc, int totalCostos,
		int totalConAumento, int aumento);

#endif /* OPERACIONES_H_ */
