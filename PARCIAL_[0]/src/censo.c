/*
 * censo.c
 *
 *  Created on: 23 may. 2022
 *      Author: PEREZ CARDENAL PATRICIO
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

sVivienda ingresarVivienda(sTipoVivienda* listaOpcionViviendas, sCensista* legajosCensista, int* error)
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
	int indiceOpcionVivienda;
	int indiceNombreCensista;
	int bandera;

	opcion = 0;
	validacion = 0;
	banderaCalle = 0;
	banderaCantidadPersonas = 0;
	banderaCantidadHabitaciones = 0;
	banderaTipoVivienda = 0;
	banderaLegajoCensista = 0;
	bandera = 0;
	*error= 0;

	clear();
	do
	{
		clear();
		printf("|[> 1 <] --| INGRESAR VIVIENDA <|\n\n");

		if (banderaCalle == 0)
		{
			printf("|[1] >- | INGRESAR CALLE <[]|\n");
		}
		else
		{
			printf("|[1] >- | INGRESAR CALLE <[%s]|\n"
					, unaVivienda.calle);
		}

		printf("|[2] >- | INGRESAR CANTIDAD DE PERSONAS <[%d]|\n"
				"|[3] >- | INGRESAR CANTIDAD DE HABITACIONES <[%d]|\n"
				"|[4] >- | INGRESAR TIPO DE VIVIENDA <[%d]|\n"
				"|[5] >- | INGRESAR LEGAJO DE CENSISTA <[%d]|\n"
				"|[6] >- | SALIR Y GUARDAR <|\n\n"
			    "|[INGRESE LA OPCION]<|:"
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
														   "|[100] - Ana |\n"
														   "|[101] - Juan |\n"
														   "|[102] - Sol |\n\n"
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
					animacionCargando();
					clear();
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
					*error = 1;
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

int buscarEspacioLleno(sVivienda* lista, int longitud)
{
	int indice;
		int i;

		indice = VACIO;

		for (i = 0; i < longitud; i++)
		{
			if ((*(lista + i)).idVivienda != VACIO)
			{
				indice = i;
				break;
			}
		}
		return indice;
}

int cargarVivienda(sVivienda* lista, int longitud, sTipoVivienda* listaOpcionViviendas, sCensista* legajosCensista, int* error)
{
	int indice;
	sVivienda vivienda;

	indice = buscarEspacioVacio(lista, longitud);

	vivienda = ingresarVivienda(listaOpcionViviendas, legajosCensista, error);

	if (indice != OCUPADO && *error == 0)
	{
		(*(lista + indice)) = vivienda;
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

int buscarPasajeroPorId(sVivienda* lista, int longitud, int id)
{
	int indice;
	int i;

	indice = -1;

	for (i = 0; i < longitud; i++)
	{
		if ((*(lista + i)).idVivienda == id && (*(lista + i)).idVivienda != VACIO)
		{
			indice = i;
			break;
		}
	}

	return indice;
}

int modificarVivienda(sVivienda* lista, int longitud, sTipoVivienda* listaOpcionViviendas, sCensista* legajosCensista)
{
	int id;
	int indiceVivienda;
	int indiceOpcionVivienda;
	int indiceNombreCensista;
	int opcion;
	int validacion;
	int bandera;

	id = 0;
	indiceVivienda = 0;
	indiceOpcionVivienda = 0;
	indiceNombreCensista = 0;
	opcion = 0;
	validacion = 0;
	bandera = 0;

	printf("|[> 2 <] --| MODIFICAR VIVIENDA <|\n\n");
	listarViviendas(lista, longitud, listaOpcionViviendas, legajosCensista);
	printf("|[INGRESE EL [ID] DE LA VIVIENDA A MODIFICAR]<|:");

	fflush(stdin);
	scanf("%d", &id);

	indiceVivienda = buscarPasajeroPorId(lista, longitud, id);

	while (indiceVivienda == -1)
	{
		printf("|[> 2 <] --| MODIFICAR VIVIENDA <|\n\n"
			   "|<ERROR>| (Vivienda no encontrada)"
			   "|[INGRESE EL [ID] DE LA VIVIENDA A MODIFICAR]<|:");

		fflush(stdin);
		scanf("%d", &id);

		indiceVivienda = buscarPasajeroPorId(lista, longitud, id);
	}

	do
	{
		indiceOpcionVivienda = indiceTipoVivienda((*(lista + indiceVivienda)).tipoVivienda, listaOpcionViviendas, 4);
		indiceNombreCensista = indiceCensista((*(lista + indiceVivienda)).legajoCensista, legajosCensista, 3);
		clear();
		printf("|[> 2 <] --| MODIFICAR VIVIENDA <|\n\n"
				"|[1] >- | MODIFICAR CALLE <[%s]|\n"
				"|[2] >- | MODIFICAR CANTIDAD DE PERSONAS <[%d]|\n"
				"|[3] >- | MODIFICAR CANTIDAD DE HABITACIONES <[%d]|\n"
				"|[4] >- | MODIFICAR TIPO DE VIVIENDA <[[%d] - [%s]]|\n"
				"|[5] >- | MODIFICAR LEGAJO DE CENSISTA <[[%d] - [%s]]|\n"
				"|[6] >- | SALIR Y GUARDAR <|\n\n"
				"|[INGRESE LA OPCION]<|:"
				, (*(lista + indiceVivienda)).calle
				, (*(lista + indiceVivienda)).cantidadPersonas
				, (*(lista + indiceVivienda)).cantidadHabitaciones
				, (*(lista + indiceVivienda)).tipoVivienda
				, (*(listaOpcionViviendas + indiceOpcionVivienda)).descripcionVivienda
				, (*(lista + indiceVivienda)).legajoCensista
				, (*(legajosCensista + indiceNombreCensista)).nombre);

		fflush(stdin);
		scanf("%d", &opcion);

		switch (opcion)
		{
			case 1:
				clear();
				printf("|[> 1 <] --| MODIFICAR CALLE <|\n\n"
					   "|[INGRESE LA CALLE]<|:\n");
				fflush(stdin);
				gets((*(lista + indiceVivienda)).calle);
				validacion = validarCaracteres((*(lista + indiceVivienda)).calle);

				while (validacion == 0)
				{
					clear();
					printf("|[> 1 <] --| MODIFICAR CALLE <|\n\n"
						   "|<ERROR>| (Escriba unicamente caracteres)\n"
						   "|[INGRESE LA CALLE]<|:\n");
					fflush(stdin);
					gets((*(lista + indiceVivienda)).calle);
					validacion = validarCaracteres((*(lista + indiceVivienda)).calle);
				}
				bandera = 1;
			break;

			case 2:
				clear();
				(*(lista + indiceVivienda)).cantidadPersonas = pedirEntero("|[> 2 <] --| MODIFICAR CANTIDAD DE PERSONAS <|\n\n"
																		   "|[INGRESE LA CANTIDAD DE PERSONAS] (1 - 30) <|:\n");
				while ((*(lista + indiceVivienda)).cantidadPersonas < 1 || (*(lista + indiceVivienda)).cantidadPersonas > 30)
				{
					clear();
					(*(lista + indiceVivienda)).cantidadPersonas = pedirEntero("|[> 2 <] --| MODIFICAR CANTIDAD DE PERSONAS <|\n\n"
																			   "|<ERROR>| (Ingrese una cantidad valida)\n"
																			   "|[INGRESE LA CANTIDAD DE PERSONAS] (1 - 30) <|:\n");

				}
				bandera = 1;
			break;

			case 3:
				clear();
				(*(lista + indiceVivienda)).cantidadHabitaciones = pedirEntero("|[> 3 <] --| MODIFICAR CANTIDAD DE HABITACIONES <|\n\n"
															   	   	   	   	   "|[INGRESE LA CANTIDAD DE HABITACIONES] (1 - 25) <|:\n");
				while ((*(lista + indiceVivienda)).cantidadHabitaciones < 1 || (*(lista + indiceVivienda)).cantidadHabitaciones > 25)
				{
					clear();
					(*(lista + indiceVivienda)).cantidadHabitaciones = pedirEntero("|[> 3 <] --| MODIFICAR CANTIDAD DE HABITACIONES <|\n\n"
																   	   	   	   	   "|<ERROR>| (Ingrese una cantidad valida)\n"
																				   "|[INGRESE LA CANTIDAD DE HABITACIONES] (1 - 25) <|:\n");
				}
				bandera = 1;
			break;

			case 4:
				clear();
				(*(lista + indiceVivienda)).tipoVivienda = pedirEntero("|[> 4 <] --| MODIFICAR TIPO DE VIVIENDA <|\n\n"
																	   "|[1] | Casa |\n"
																	   "|[2] | Departamento |\n"
																	   "|[3] | Casilla |\n"
																	   "|[4] | Rancho |\n\n"
																	   "|[INGRESE EL TIPO DE VIVIENDA]<|:\n");
				while ((*(lista + indiceVivienda)).tipoVivienda < 1 || (*(lista + indiceVivienda)).tipoVivienda > 4)
				{
					clear();
					(*(lista + indiceVivienda)).tipoVivienda = pedirEntero("|[> 4 <] --| MODIFICAR TIPO DE VIVIENDA <|\n\n"
																		   "|<ERROR>| (Elija un tipo de vivienda existente)\n"
																		   "|[1] | Casa |\n"
																		   "|[2] | Departamento |\n"
																		   "|[3] | Casilla |\n"
																		   "|[4] | Rancho |\n\n"
																		   "|[INGRESE EL TIPO DE VIVIENDA]<|:\n");

				}
				bandera = 1;
			break;

			case 5:
				clear();
				(*(lista + indiceVivienda)).legajoCensista = pedirEntero("|[> 5 <] --| MODIFICAR LEGAJO CENSISTA <|\n\n"
													   	   	   	   	   	 "|[100] | Ana |\n"
																		 "|[101] | Juan |\n"
																		 "|[102] | Sol |\n\n"
																		 "|[INGRESE EL LEGAJO DEL CENSISTA]<|:\n");
				while ((*(lista + indiceVivienda)).legajoCensista < 100 || (*(lista + indiceVivienda)).legajoCensista > 102)
				{
					clear();
					(*(lista + indiceVivienda)).legajoCensista = pedirEntero("|[> 5 <] --| MODIFICAR LEGAJO CENSISTA <|\n\n"
																			 "|<ERROR>| (Elija un censista existente)\n"
																			 "|[1] | [100] - Ana |\n"
																			 "|[2] | [101] - Juan |\n"
																			 "|[3] | [102] - Sol |\n\n"
																			 "|[INGRESE EL LEGAJO DEL CENSISTA]<|:\n");
				}
				bandera = 1;
			break;

			case 6:
				if (bandera == 1)
				{
					clear();
					animacionCargando();
					clear();
					printf("|<------   | - GUARDADO CON EXITO - |   ------>|\n\n");
					printf("=====================================================================================================\n"
							"||ID     ||CALLE              ||PERSONAS  ||HABITACIONES  ||TIPO DE VIVIENDA    ||LEGAJO CENSISTA  ||\n"
							"=====================================================================================================\n"
							"||%-7d||%-19s||%-10d||%-14d||%-20s||%d | %-11s||\n"
							, (*(lista + indiceVivienda)).idVivienda
							, (*(lista + indiceVivienda)).calle
							, (*(lista + indiceVivienda)).cantidadPersonas
							, (*(lista + indiceVivienda)).cantidadHabitaciones
							, (*(listaOpcionViviendas + indiceOpcionVivienda)).descripcionVivienda
							, (*(lista + indiceVivienda)).legajoCensista
							, (*(legajosCensista + indiceNombreCensista)).nombre);
					printf("=====================================================================================================\n");
					system("pause");
				}
				else
				{
					clear();
					printf("|[> NO SE HAN REALIZADO CAMBIOS <]|\n\n");
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

	return 0;
}

int listarViviendas(sVivienda* lista, int longitud, sTipoVivienda* listaOpcionViviendas, sCensista* legajosCensista)
{
	int i;
	int indiceOpcionVivienda;
	int indiceNombreCensista;

	printf("=====================================================================================================\n"
		   "||ID     ||CALLE              ||PERSONAS  ||HABITACIONES  ||TIPO DE VIVIENDA    ||LEGAJO CENSISTA  ||\n"
		   "=====================================================================================================\n");

	for (i = 0; i < longitud; i++)
	{
		indiceOpcionVivienda = indiceTipoVivienda((*(lista + i)).tipoVivienda, listaOpcionViviendas, 4);
		indiceNombreCensista = indiceCensista((*(lista + i)).legajoCensista, legajosCensista, 3);

		if ((*(lista + i)).idVivienda != VACIO)
		{
				printf("||%-7d||%-19s||%-10d||%-14d||%-20s||%d | %-11s||\n" //
				, (*(lista + i)).idVivienda
				, (*(lista + i)).calle
				, (*(lista + i)).cantidadPersonas
				, (*(lista + i)).cantidadHabitaciones
				, (*(listaOpcionViviendas + indiceOpcionVivienda)).descripcionVivienda
				, (*(lista + i)).legajoCensista
				, (*(legajosCensista + indiceNombreCensista)).nombre);
		}
	}

	printf("=====================================================================================================\n");

	return 0;
}

int eliminarVivienda(sVivienda* lista, int longitud, sTipoVivienda* listaOpcionViviendas, sCensista* legajosCensista)
{
	int id;
	int indiceVivienda;

	id = 0;
	indiceVivienda = 0;

	printf("|[> 3 <] --| ELIMINAR VIVIENDA <|\n\n");
	listarViviendas(lista, longitud, listaOpcionViviendas, legajosCensista);
	printf("|[INGRESE EL [ID] DE LA VIVIENDA A ELIMINAR]<|:");

	fflush(stdin);
	scanf("%d", &id);

	indiceVivienda = buscarPasajeroPorId(lista, longitud, id);

	while (indiceVivienda == -1)
	{
		printf("|[> 3 <] --| ELIMINAR VIVIENDA <|\n\n"
			   "|<ERROR<| (Vivienda no encontrada)"
			   "|[INGRESE EL [ID] DE LA VIVIENDA A ELIMINAR]<|:");

		fflush(stdin);
		scanf("%d", &id);

		indiceVivienda = buscarPasajeroPorId(lista, longitud, id);
	}

	(*(lista + indiceVivienda)).idVivienda = VACIO;

	return indiceVivienda;
}

int ordenarViviendas(sVivienda* lista, int longitud)
{
	sVivienda aux;

	if (lista != NULL || longitud >= 0)
	{
		for (int i = 0; i < longitud - 1; i++)
		{
			for (int j = i + 1; j < longitud; j++)
			{
				if (strcmp((*(lista + i)).calle, (*(lista + j)).calle) > 0)
				{
					aux = (*(lista + i));
					(*(lista + i)) = (*(lista + j));
					(*(lista + j)) = aux;
				}
				if (strcmp((*(lista + i)).calle, (*(lista + j)).calle) == 0)
				{
					if ((*(lista + i)).cantidadPersonas > (*(lista + j)).cantidadPersonas)
					{
						aux = (*(lista + i));
						(*(lista + i)) = (*(lista + j));
						(*(lista + j)) = aux;
					}
				}
			}
		}
	}

	return 0;
}

int listarCensistaMasCensos(sCensista legajosCensista, sCensista* listaLegajosCensista, int longitud, sVivienda* listaViviendas, int longitudViviendas, sTipoVivienda* listaOpcionViviendas)
{
	int j;
	int indiceOpcionVivienda;
	int indiceNombreCensista;

			printf("======================================================\n"
				   "||LEGAJO     ||NOMBRE     ||EDAD    ||NUMERO        ||\n"
				   "======================================================\n");
			printf("||%-11d||%-11s||%-8d||%-14s||\n"
					, legajosCensista.legajoCensista
					, legajosCensista.nombre
					, legajosCensista.edad
					, legajosCensista.telefono);

			printf("=====================================================================================================\n"
				   "||ID     ||CALLE              ||PERSONAS  ||HABITACIONES  ||TIPO DE VIVIENDA    ||LEGAJO CENSISTA  ||\n"
				   "=====================================================================================================\n");

			for (j = 0; j < longitudViviendas; j++)
			{
				if (legajosCensista.legajoCensista == (*(listaViviendas + j)).legajoCensista && (*(listaViviendas + j)).idVivienda != VACIO)
				{
					indiceOpcionVivienda = indiceTipoVivienda((*(listaViviendas + j)).tipoVivienda, listaOpcionViviendas, 4);
					indiceNombreCensista = indiceCensista((*(listaViviendas + j)).legajoCensista, listaLegajosCensista, 3);

					printf("||%-7d||%-19s||%-10d||%-14d||%-20s||%d | %-11s||\n" //
					, (*(listaViviendas + j)).idVivienda
					, (*(listaViviendas + j)).calle
					, (*(listaViviendas + j)).cantidadPersonas
					, (*(listaViviendas + j)).cantidadHabitaciones
					, (*(listaOpcionViviendas + indiceOpcionVivienda)).descripcionVivienda
					, (*(listaViviendas + j)).legajoCensista
					, (*(listaLegajosCensista + indiceNombreCensista)).nombre);

				}
			}
			printf("=====================================================================================================\n\n");
	return 0;
}

int listarCensistasViviendas(sCensista* legajosCensista, int longitud, sVivienda* listaViviendas, int longitudViviendas, sTipoVivienda* listaOpcionViviendas)
{
	int i;
	int j;
	int indiceOpcionVivienda;
	int indiceNombreCensista;

		for (i = 0; i < longitud; i++)
		{
			printf("======================================================\n"
				   "||LEGAJO     ||NOMBRE     ||EDAD    ||NUMERO        ||\n"
				   "======================================================\n");
			printf("||%-11d||%-11s||%-8d||%-14s||\n"
					, (*(legajosCensista + i)).legajoCensista
					, (*(legajosCensista + i)).nombre
					, (*(legajosCensista + i)).edad
					, (*(legajosCensista + i)).telefono);

			printf("=====================================================================================================\n"
				   "||ID     ||CALLE              ||PERSONAS  ||HABITACIONES  ||TIPO DE VIVIENDA    ||LEGAJO CENSISTA  ||\n"
				   "=====================================================================================================\n");

			for (j = 0; j < longitudViviendas; j++)
			{
				if ((*(legajosCensista + i)).legajoCensista == (*(listaViviendas + j)).legajoCensista && (*(listaViviendas + j)).idVivienda != VACIO)
				{
					indiceOpcionVivienda = indiceTipoVivienda((*(listaViviendas + j)).tipoVivienda, listaOpcionViviendas, 4);
					indiceNombreCensista = indiceCensista((*(listaViviendas + j)).legajoCensista, legajosCensista, 3);

					printf("||%-7d||%-19s||%-10d||%-14d||%-20s||%d | %-11s||\n" //
					, (*(listaViviendas + j)).idVivienda
					, (*(listaViviendas + j)).calle
					, (*(listaViviendas + j)).cantidadPersonas
					, (*(listaViviendas + j)).cantidadHabitaciones
					, (*(listaOpcionViviendas + indiceOpcionVivienda)).descripcionVivienda
					, (*(listaViviendas + j)).legajoCensista
					, (*(legajosCensista + indiceNombreCensista)).nombre);

				}
			}
			printf("=====================================================================================================\n\n");
		}
	return 0;
}

int contarCensosRealizados (sVivienda* lista, int longitud, int* censosRealizadosAna, int* censosRealizadosJuan, int* censosRealizadosSol)
{
	int i;
	*censosRealizadosAna = 0;
	*censosRealizadosJuan = 0;
	*censosRealizadosSol = 0;

	for (i = 0; i < longitud; i++)
	{

		switch((*(lista + i)).legajoCensista)
		{
			case 100:
				if ((*(lista + i)).idVivienda != VACIO)
				{
					*censosRealizadosAna = *censosRealizadosAna + 1;
				}
			break;

			case 101:
				if ((*(lista + i)).idVivienda != VACIO)
				{
					*censosRealizadosJuan = *censosRealizadosJuan + 1;
				}
			break;

			case 102:
				if ((*(lista + i)).idVivienda != VACIO)
				{
					*censosRealizadosSol = *censosRealizadosSol + 1;
				}
			break;
		}
	}

	return 0;
}
