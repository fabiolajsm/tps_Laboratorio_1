/*
 * utn.h
 *
 *  Created on: 1 nov. 2022
 *      Author: fsuarez
 */

#ifndef UTN_H_
#define UTN_H_

/**
 * @fn int utn_obtenerNumero(int*, char *, char *, int , int)
 * @brief Esta función pide un número entero, verifica que sea válido y lo guarda en la dirección de memoria pasada.
 * @param pResultado Dirección de memoria donde va a ser guardado el número después de validar.
 * @param mensaje Mensaje a mostrar cuando la función pida el número.
 * @param mensajeError Mensaje a mostrar si lo ingresado no es válido.
 * @param minimo Mínimo número a ingresar.
 * @param maximo Máximo número a ingresar.
 * @return Retorna 0 si se realizó bien la función y -1 si hubo un error.
 * */
int utn_obtenerNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo);
/**
 * @fn int utn_obtenerTexto(char*, int, char *, char *, int)
 * @brief Esta función pide un texto, verifica que sea válido y lo guarda en la dirección de memoria pasada.
 * @param pResultado Dirección de memoria donde va a guardar el texto después de validar.
 * @param mensaje Mensaje a mostrar cuando la función pida el texto.
 * @param mensajeError Mensaje a mostrar si lo ingresado no es válido.
 * @param maximo Máximo de caracteres a ingresar.
 * @return Retorna 0 si se realizó bien la función y -1 si hubo un error.
 * */
int utn_obtenerTexto(char *pResultado, int largo, char *mensaje,
		char *mensajeError, int maxCaracteres);
/**
 * @fn int utn_obtenerFlotante(float*, char *, char *, int , int)
 * @brief Esta función pide un número y puede ser decimal, verifica que sea válido y lo guarda en la dirección de memoria pasada.
 * @param pResultado Dirección de memoria donde va a ser guardado el número después de validar.
 * @param mensaje Mensaje a mostrar cuando la función pida el número.
 * @param mensajeError Mensaje a mostrar si lo ingresado no es válido.
 * @param minimo Mínimo número a ingresar.
 * @param maximo Máximo número a ingresar.
 * @return Retorna 0 si se realizó bien la función y -1 si hubo un error.
 * */
int utn_obtenerFlotante(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo);
/**
 * @fn int utn_obtenerNumeroShort(short*, char *, char *, int , int)
 * @brief Esta función pide un número de formato short, verifica que sea válido y lo guarda en la dirección de memoria pasada.
 * @param pResultado Dirección de memoria donde va a ser guardado el número después de validar.
 * @param mensaje Mensaje a mostrar cuando la función pida el número.
 * @param mensajeError Mensaje a mostrar si lo ingresado no es válido.
 * @param minimo Mínimo número a ingresar.
 * @param maximo Máximo número a ingresar.
 * @return Retorna 0 si se realizó bien la función y -1 si hubo un error.
 * */
int utn_obtenerNumeroShort(short *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo);

int esTexto(char *cadena);

#endif /* UTN_H_ */
