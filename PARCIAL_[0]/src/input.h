/*
 * input.h
 *
 *  Created on: 23 may. 2022
 *      Author: patri
 */

#ifndef INPUT_H_
#define INPUT_H_

/// @brief Funcion para validar el ingreso de unicamente caracteres.
///
/// @param string Puntero a array de caracteres.
/// @return [1] Si tiene unicamente caracteres. [0] Si encuentra numeros.
int validarCaracteres (char* string);

/// @brief Funcion para validar el ingreso de unicamente numeros.
///
/// @param numeros Puntero a array de caracteres.
/// @return [1] Si tiene unicamente numeros. [0] Si encuentra caracteres.
int validarNumeros(char* numeros);

/// @brief Funcion para pedir un entero como array de caracteres y validar que el mismo contenga unicamente numeros.
///
/// @param mensaje Array de caracteres para escribir un mensaje que aparecera en consola.
/// @return Retorna el entero transforado a INTEGER.
int pedirEntero(char mensaje[]);

#endif /* INPUT_H_ */
