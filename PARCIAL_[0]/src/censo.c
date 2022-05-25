/*
 * censo.c
 *
 *  Created on: 23 may. 2022
 *      Author: PEREZ CARDENAL PATRICIO
 */
#include <stdio.h>
#include <stdlib.h>
#include "desarrollo.h"
#include "censo.h"
#include "input.h"

void inicializarViviendas(sVivienda* lista, int longitud)
{
	int i;

	for (i = 0; i < longitud; i++)
	{
		(*(lista + i)).idVivienda = VACIO;
	}
}

sVivienda ingresarVivienda(sTipoVivienda* listaOpcionViviendas, sCensista* legajosCensista)
{
	sVivienda unaVivienda;

	unaVivienda.cantidadPersonas = 0;
	unaVivienda.cantidadHabitaciones = 0;
	unaVivienda.tipoVivienda = 0;
	unaVivienda.legajoCensista = 0;

	int opcion;
	int validacion;
	int banderaCalle;
	int banderaCantidadPersonas;
	int banderaCantidadHabitaciones;
	int banderaTipoVivienda;
	int banderaLegajoCensista;
	int bandera;
	int indiceOpcionVivienda;
	int indiceNombreCensista;

	opcion = 0;
	validacion = 0;

	clear();
	do
	{
		clear();
		printf("|[> 1 <] --| INGRESAR VIVIENDA <|\n\n"
				"|[1] >- | INGRESAR CALLE <[%s]|\n"
				"|[2] >- | INGRESAR CANTIDAD DE PERSONAS <[%d]|\n"
				"|[3] >- | INGRESAR CANTIDAD DE HABITACIONES <[%d]|\n"
				"|[4] >- | INGRESAR TIPO DE VIVIENDA <[%d]|\n"
				"|[5] >- | INGRESAR LEGAJO DE CENSISTA <[%d]|\n"
				"|[6] >- | SALIR Y GUARDAR <|\n\n"
			    "|[INGRESE LA OPCION]<|:"
				, unaVivienda.calle
				, unaVivienda.cantidadPersonas
				, unaVivienda.cantidadHabitaciones
				, unaVivienda.tipoVivienda
				, unaVivienda.legajoCensista);

		fflush(stdin);
		scanf("%d", &opcion);

		switch (opcion)
		{
			case 1:
				clear();
				printf("|[> 1 <] --| INGRESAR CALLE <|\n\n"
					   "|[INGRESE LA CALLE]<|:\n");
				fflush(stdin);
				gets(unaVivienda.calle);
				validacion = validarCaracteres(unaVivienda.calle);

				while (validacion == 0)
				{
					clear();
					printf("|[> 1 <] --| INGRESAR CALLE <|\n\n"
						   "|<ERROR>| (Escriba unicamente caracteres)\n"
						   "|[INGRESE LA CALLE]<|:\n");
					fflush(stdin);
					gets(unaVivienda.calle);
					validacion = validarCaracteres(unaVivienda.calle);
				}
				banderaCalle = 1;
			break;

			case 2:
				clear();
				unaVivienda.cantidadPersonas = pedirEntero("|[> 2 <] --| INGRESAR CANTIDAD DE PERSONAS <|\n\n"
						    								"|[INGRESE LA CANTIDAD DE PERSONAS] (1 - 30) <|:\n");
				while (unaVivienda.cantidadPersonas < 1 || unaVivienda.cantidadPersonas > 30)
				{
					clear();
					unaVivienda.cantidadPersonas = pedirEntero("|[> 2 <] --| INGRESAR CANTIDAD DE PERSONAS <|\n\n"
																"|<ERROR>| (Ingrese una cantidad valida)\n"
																"|[INGRESE LA CANTIDAD DE PERSONAS] (1 - 30) <|:\n");

				}
				banderaCantidadPersonas = 1;
			break;

			case 3:
				clear();
				unaVivienda.cantidadHabitaciones = pedirEntero("|[> 3 <] --| INGRESAR CANTIDAD DE HABITACIONES <|\n\n"
															   "|[INGRESE LA CANTIDAD DE HABITACIONES] (1 - 25) <|:\n");
				while (unaVivienda.cantidadHabitaciones < 1 || unaVivienda.cantidadHabitaciones > 25)
				{
					clear();
					unaVivienda.cantidadHabitaciones = pedirEntero("|[> 3 <] --| INGRESAR CANTIDAD DE HABITACIONES <|\n\n"
																   "|<ERROR>| (Ingrese una cantidad valida)\n"
																   "|[INGRESE LA CANTIDAD DE HABITACIONES] (1 - 25) <|:\n");
				}
				banderaCantidadHabitaciones = 1;
			break;

			case 4:
				clear();
				unaVivienda.tipoVivienda = pedirEntero("|[> 4 <] --| INGRESAR TIPO DE VIVIENDA <|\n\n"
													   "|[1] | Casa |\n"
													   "|[2] | Departamento |\n"
													   "|[3] | Casilla |\n"
													   "|[4] | Rancho |\n\n"
													   "|[INGRESE EL TIPO DE VIVIENDA]<|:\n");
				while (unaVivienda.tipoVivienda < 1 || unaVivienda.tipoVivienda > 4)
				{
					clear();
					unaVivienda.tipoVivienda = pedirEntero("|[> 4 <] --| INGRESAR TIPO DE VIVIENDA <|\n\n"
														   "|<ERROR>| (Elija un tipo de vivienda existente)\n"
														   "|[1] | Casa |\n"
														   "|[2] | Departamento |\n"
														   "|[3] | Casilla |\n"
														   "|[4] | Rancho |\n\n"
														   "|[INGRESE EL TIPO DE VIVIENDA]<|:\n");

				}
				banderaTipoVivienda = 1;
			break;

			case 5:
				clear();
				unaVivienda.legajoCensista = pedirEntero("|[> 5 <] --| INGRESAR LEGAJO CENSISTA <|\n\n"
													   "|[100] | Ana |\n"
													   "|[101] | Juan |\n"
													   "|[102] | Sol |\n\n"
													   "|[INGRESE EL LEGAJO DEL CENSISTA]<|:\n");
				while (unaVivienda.legajoCensista < 100 || unaVivienda.legajoCensista > 102)
				{
					clear();
					unaVivienda.legajoCensista = pedirEntero("|[> 5 <] --| INGRESAR LEGAJO CENSISTA <|\n\n"
														   "|<ERROR>| (Elija un censista existente)\n"
														   "|[1] | [100] - Ana |\n"
														   "|[2] | [101] - Juan |\n"
														   "|[3] | [102] - Sol |\n\n"
														   "|[INGRESE EL LEGAJO DEL CENSISTA]<|:\n");
				}
				banderaLegajoCensista = 1;
			break;

			case 6:
				bandera = banderaCalle + banderaCantidadPersonas + banderaCantidadHabitaciones + banderaTipoVivienda + banderaLegajoCensista;

				if (bandera == 5)
				{
					indiceOpcionVivienda = indiceTipoVivienda(unaVivienda.tipoVivienda, listaOpcionViviendas, 4);
					indiceNombreCensista = indiceCensista(unaVivienda.legajoCensista, legajosCensista, 3);
					clear();
					unaVivienda.idVivienda = generarId();
					printf("|<------   | - GUARDADO CON EXITO - |   ------>|\n\n");
					printf("=====================================================================================================\n"
							"||ID     ||CALLE              ||PERSONAS  ||HABITACIONES  ||TIPO DE VIVIENDA    ||LEGAJO CENSISTA  ||\n"
							"=====================================================================================================\n"
							"||%-7d||%-19s||%-10d||%-14d||%-20s||%d | %-11s||\n"
							, unaVivienda.idVivienda
							, unaVivienda.calle
							, unaVivienda.cantidadPersonas
							, unaVivienda.cantidadHabitaciones
							, (*(listaOpcionViviendas + indiceOpcionVivienda)).descripcionVivienda
							, unaVivienda.legajoCensista
							, (*(legajosCensista + indiceNombreCensista)).nombre);
					printf("=====================================================================================================\n");
					system("pause");
				}
				else
				{
					clear();
					printf("|[> ERROR <] --| No se pudo guardar (FALTAN DATOS) <|\n\n");
					system("pause");
				}
			break;
			default:
				clear();
				printf("|<------   | - OPCION INVALIDA - |   ------>|\n\n");
				system("pause");
			break;
		}
	}while (opcion != 6);

	return unaVivienda;
}

int buscarEspacioVacio(sVivienda* lista, int longitud)
{
	int indice;
	int i;

	indice = OCUPADO;

	for (i = 0; i < longitud; i++)
	{
		if ((*(lista + i)).idVivienda == VACIO)
		{
			indice = i;
			break;
		}
	}
	return indice;
}

int cargarVivienda(sVivienda* lista, int longitud, sTipoVivienda* listaOpcionViviendas, sCensista* legajosCensista)
{
	int indice;

	indice = buscarEspacioVacio(lista, longitud);

	if (indice != OCUPADO)
	{
		(*(lista + indice)) = ingresarVivienda(listaOpcionViviendas, legajosCensista);
	}

	return indice;
}

int indiceTipoVivienda(int indiceTipoVivienda, sTipoVivienda* listaOpcionViviendas, int longitudOpciones)
{
	int indice;
	int i;

	for (i = 0; i < longitudOpciones; i++)
	{
		if (indiceTipoVivienda == (*(listaOpcionViviendas + i)).tipoVivienda)
		{
			indice = i;
			break;
		}
	}

	return indice;
}

int indiceCensista(int indiceLegajoCensista, sCensista* legajosCensista, int longitudCensita)
{
	int indice;
		int i;

		for (i = 0; i < longitudCensita; i++)
		{
			if (indiceLegajoCensista == (*(legajosCensista + i)).legajoCensista)
			{
				indice = i;
				break;
			}
		}

		return indice;
}
