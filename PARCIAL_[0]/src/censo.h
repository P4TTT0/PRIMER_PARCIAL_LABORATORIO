/*
 * censo.h
 *
 *  Created on: 23 may. 2022
 *      Author: PEREZ CARDENAL PATRICIO
 */

#ifndef CENSO_H_
#define CENSO_H_

#define TAM 30
#define LEN 2000
#define VACIO 1
#define OCUPADO -1

typedef struct
{
	int idVivienda;
	char calle[25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int legajoCensista;
}sVivienda;

typedef struct
{
	int legajoCensista;
	char nombre[TAM];
	int edad;
	char telefono[10];
}sCensista;

typedef struct
{
	int tipoVivienda;
	char descripcionVivienda[TAM];
}sTipoVivienda;

/// @brief Funcion para inicializar todas las viviendas con el id VACIO (1).
///
/// @param lista Puntero a estructura de array de viviendas.
/// @param longitud Tama?o del array de viviendas.
void inicializarViviendas(sVivienda* lista, int longitud);

/// @brief Funcion para llenar los datos de una vivienda.
///
/// @param listaOpcionViviendas Puntero a estrucutra de array de los tipos de viviendas.
/// @param legajosCensista Puntero a estructura de array de los diferentes censistas.
/// @param error Puntero a variable que evalua si se han llenado todos los campos de la vivienda.
/// @return Retorna la vivienda.
sVivienda ingresarVivienda(sTipoVivienda* listaOpcionViviendas, sCensista* legajosCensista, int* error);

/// @brief Funcion para buscar un espacio VACIO (1) en el array de la lista de viviendas.
///
/// @param lista Puntero a estrucutra de array de la lista de viviendas.
/// @param longitud Tama?o del array de la lista de viviendas.
/// @return Retorna el indice en el que haya encontrado un espacio VACIO (1)
int buscarEspacioVacio(sVivienda* lista, int longitud);

/// @brief Funcion para buscar un espacio LLENO en el array de la lista de viviendas.
///
/// @param lista Puntero a estrucutra de array de la lista de viviendas.
/// @param longitud Tama?o del array de la lista de viviendas.
/// @return Retorna el indice en el que haya encontrado un espacio distinto a VACIO (1)
int buscarEspacioLleno(sVivienda* lista, int longitud);

/// @brief Funcion para cargar la vivienda anteriormente llenada dentro del array de la lista de viviendas.
///
/// @param lista Puntero a estrucutra de array de la lista de viviendas.
/// @param longitud longitud Tama?o del array de la lista de viviendas.
/// @param listaOpcionViviendas Puntero a estrucutra de array de los tipos de viviendas.
/// @param legajosCensista Puntero a estructura de array de los diferentes censistas.
/// @param error Puntero a variable que evalua si se han llenado todos los campos de la vivienda.
/// @return Retorna el indice en donde se ha cargado la vivienda.
int cargarVivienda(sVivienda* lista, int longitud, sTipoVivienda* listaOpcionViviendas, sCensista* legajosCensista, int* error);

/// @brief Funcion para relacionar el campo [TIPO VIVIENDA] de la estrucutra de viviendas con el de la estructura de tipos de viviendas.
///
/// @param indiceTipoVivienda El indice de la vivienda a relacionar.
/// @param listaOpcionViviendas Puntero a estrucutra de array de los tipos de viviendas.
/// @param longitudOpciones Tama?o del array de los tipos de viviendas.
/// @return Retorna el indice en el que ambos campos se relacionan.
int indiceTipoVivienda(int indiceTipoVivienda, sTipoVivienda* listaOpcionViviendas, int longitudOpciones);

/// @brief Funcion para relacionar el campo [LEGAJO CENSISTA] de la estrucutra de viviendas con el de la estructura de tipos de viviendas.
///
/// @param indiceLegajoCensista El indice de la vivienda a relacionar.
/// @param legajosCensista Puntero a estructura de array de los diferentes censistas.
/// @param longitudCensita Tama?o del array de los diferentes censistas
/// @return Retorna el indice en el que ambos campos se relacionan.
int indiceCensista(int indiceLegajoCensista, sCensista* legajosCensista, int longitudCensita);

/// @brief Funcion para buscar una vivienda dentro de la lista de vivienda por el [ID] del mismo.
///
/// @param lista Puntero a estructura de array de la lista de viviendas.
/// @param longitud Tama?o del array de la lista de viviendas.
/// @param id ID de la vivienda a buscar.
/// @return Retorna el indice en el que se encuentra la vivienda dentro de la lista de viviendas. | | Retorna -1 si no se haya la vivienda.
int buscarPasajeroPorId(sVivienda* lista, int longitud, int id);

/// @brief Funcion para modificar los diferentes campos de una vivienda.
///
/// @param lista Puntero a estructura de array de la lista de viviendas.
/// @param longitud Tama?o del array de la lista de viviendas.
/// @param listaOpcionViviendas Puntero a estructura de array de los tipos de viviendas.
/// @param legajosCensista Puntero a estructura de array de los diferentes censistas.
/// @return 0
int modificarVivienda(sVivienda* lista, int longitud, sTipoVivienda* listaOpcionViviendas, sCensista* legajosCensista);

/// @brief Funcion para recorrer el array de la lista de viviendas y PRINTEAR en forma de cuadro las viviendas que esten cargadas.
///
/// @param lista Puntero a estructura de array de la lista de viviendas.
/// @param longitud Tama?o del array de la lista de viviendas.
/// @param listaOpcionViviendas Puntero a estructura de array de los tipos de viviendas.
/// @param legajosCensista Puntero a estructura de array de los diferentes censistas.
/// @return 0
int listarViviendas(sVivienda* lista, int longitud, sTipoVivienda* listOpcionViviendas, sCensista* legajosCensista);

/// @brief Funcion para eliminar una vivienda dentro del array de viviendas por el [ID] del mismo.
///
/// @param lista Puntero a estructura de array de la lista de viviendas.
/// @param longitud Tama?o del array de la lista de viviendas.
/// @param listaOpcionViviendas Puntero a estructura de array de los tipos de viviendas.
/// @param legajosCensista Puntero a estructura de array de los diferentes censistas.
/// @return Retorna el indice en el que se encontraba la vivienda. | Retorna -1 si no se encuentra la vivienda.
int eliminarVivienda(sVivienda* lista, int longitud, sTipoVivienda* listaOpcionViviendas, sCensista* legajosCensista);

/// @brief Funcion para ordenar todas las viviendas de manor a mayor en relacion a sus calles y ante igualdad de calles en relacion de la cantidad de persoans.
///
/// @param lista Puntero a estructura de array de la lista de viviendas.
/// @param longitud Tama?o del array de la lista de viviendas.
/// @return 0
int ordenarViviendas(sVivienda* lista, int longitud);

/// @brief Funcion para recorrer el array de los diferentes censistas y PRINTEARLOS junto con sus datos en forma de cuadro.
///
/// @param legajosCensista Puntero a estructura de array de los diferentes censistas.
/// @param longitud Tama?o del array de los diferentes censistas
/// @return 0
int listarCensistaMasCensos(sCensista legajosCensista, sCensista* listaLegajosCensista, int longitud, sVivienda* listaViviendas, int longitudViviendas, sTipoVivienda* listaOpcionViviendas);

int listarCensistasViviendas(sCensista* legajosCensista, int longitud, sVivienda* listaViviendas, int longitudViviendas, sTipoVivienda* listaOpcionViviendas);

int contarCensosRealizados (sVivienda* lista, int longitud, int* censosRealizadosAna, int* censosRealizadosJuan, int* censosRealizadosSol);

#endif /* CENSO_H_ */
