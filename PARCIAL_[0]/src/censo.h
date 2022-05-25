/*
 * censo.h
 *
 *  Created on: 23 may. 2022
 *      Author: PEREZ CARDENAL PATRICIO
 */

#ifndef CENSO_H_
#define CENSO_H_

#define TAM 30
#define LEN 1
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

void inicializarViviendas(sVivienda* lista, int longitud);

sVivienda ingresarVivienda(sTipoVivienda* listaOpcionViviendas, sCensista* legajosCensista);

int buscarEspacioVacio(sVivienda* lista, int longitud);

int cargarVivienda(sVivienda* lista, int longitud, sTipoVivienda* listaOpcionViviendas, sCensista* legajosCensista);

int indiceTipoVivienda(int indiceTipoVivienda, sTipoVivienda* listaOpcionViviendas, int longitudOpciones);

int indiceCensista(int indiceLegajoCensista, sCensista* legajosCensista, int longitudCensita);

#endif /* CENSO_H_ */
