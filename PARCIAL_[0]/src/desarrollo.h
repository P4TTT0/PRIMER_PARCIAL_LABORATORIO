/*
 * desarrollo.h
 *
 *  Created on: 23 may. 2022
 *      Author: PEREZ CARDENAL PATRICIO
 */

#ifndef DESARROLLO_H_
#define DESARROLLO_H_

/// @brief Funcion para generar un [ID] incremental.
///
/// @return retorna el [ID] generado.
int generarId();

/// @brief Funcion estetica para terminar muchas lineas y que de esta manera simule el ("clear");
///
void clear();

/// @brief Funcion para simular una barra de carga con un porcentaje en el medio de la misma.
///
void animacionApagado();

/// @brief Funcion para simular una barra de carga.
///
void animacionCargando();

#endif /* DESARROLLO_H_ */
