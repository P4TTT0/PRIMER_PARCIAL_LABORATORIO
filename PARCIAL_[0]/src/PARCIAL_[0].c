/*
 ============================================================================
 Name        : PARCIAL_[0].c
 Author      : P4TTT0
 Version     :
 Copyright   : TTT
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "desarrollo.h"
#include "censo.h"

int main(void) {

	setbuf(stdout, NULL);

	sVivienda listaViviendas[LEN];
	sTipoVivienda opcionesViviendas[4] = {{1, "CASA"}, {2, "DEPARTAMENTO"}, {3, "CASILLA"}, {4, "RANCHO"}};
	sCensista censistas[3] = {{100, "Ana", 34, "1203-2345"}, {101, "Juan", 24, "4301-54678"}, {102, "Sol", 47, "5902-37487"}};

	int opcion;
	int indice;
	int indiceEspacioLleno;
	int indiceViviendaEliminada;
	int error;

	opcion = 0;
	indice = 0;
	indiceEspacioLleno = 0;
	indiceViviendaEliminada = 0;
	error = 0;

	inicializarViviendas(listaViviendas, LEN);

	do
	{
		clear();
		printf("|<------   | - MENU - |   ------>|\n\n"
				"|[1] >- | INGRESAR VIVIENDA |\n"
				"|[2] >- | MODIFICAR VIVIENDA |\n"
				"|[3] >- | ELIMINAR VIVIENDA |\n"
				"|[4] >- | LISTAR VIVIENDAS |\n"
				"|[5] >- | LISTAR CENCISTAS |\n"
				"|[6] >- | SALIR <|\n\n"
				"|[INGRESE LA OPCION]<|: ");


		fflush(stdin);
		scanf("%d", &opcion);

		switch (opcion)
		{
			case 1:
				indice = cargarVivienda(listaViviendas, LEN, opcionesViviendas, censistas, &error);

				if (indice == OCUPADO)
				{
					clear();
					printf("|<------   | - LISTA LLENA - |   ------>|\n\n");
					printf("|<(No quedan espacios disponibles)>|\n");
					system("pause");
				}
			break;

			case 2:
				indiceEspacioLleno = buscarEspacioLleno(listaViviendas, LEN);

				if (indiceEspacioLleno != VACIO)
				{
					clear();
					modificarVivienda(listaViviendas, LEN, opcionesViviendas, censistas);
				}
				else
				{
					clear();
					printf("|<------   | - NO HAY VIVIENDAS EN LISTA - |   ------>|\n\n");
					printf("|<(Imposible modificar)>|\n");
					system("pause");
				}
			break;

			case 3:
				indiceEspacioLleno = buscarEspacioLleno(listaViviendas, LEN);

				if (indiceEspacioLleno != VACIO)
				{
					clear();
					indiceViviendaEliminada = eliminarVivienda(listaViviendas, LEN, opcionesViviendas, censistas);

					if (indiceViviendaEliminada != -1)
					{
						clear();
						animacionCargando();
						clear();
						printf("|<------   | - VIVIENDA ELIMINADA - |   ------>|\n\n"
								"|<POSICION DE LA VIVIENDA>|: [%d]\n"
								, indiceViviendaEliminada);
						system("pause");
					}
				}
				else
				{
					clear();
					printf("|<------   | - NO HAY VIVIENDAS EN LISTA - |   ------>|\n\n");
					printf("|<(Imposible eliminar)>|\n");
					system("pause");
				}
			break;

			case 4:
				indiceEspacioLleno = buscarEspacioLleno(listaViviendas, LEN);

				if (indiceEspacioLleno != VACIO)
				{
					clear();
					ordenarViviendas(listaViviendas, LEN);
					listarViviendas(listaViviendas, LEN, opcionesViviendas, censistas);
					system("pause");
				}
				else
				{
					clear();
					printf("|<------   | - NO HAY VIVIENDAS EN LISTA - |   ------>|\n\n");
					printf("|<(Imposible listar)>|\n");
					system("pause");
				}
			break;

			case 5:
				clear();
				listarCensistas(censistas, 3);
				system("pause");
			break;

			case 6:
				animacionApagado();
				clear();
				printf("|<------   | - SISTEMA APAGADO - |   ------>|");
			break;

			default:
				clear();
				printf("|<------   | - OPCION INVALIDA - |   ------>|\n\n");
				system("pause");
			break;
		}

	}while(opcion != 6);

	return EXIT_SUCCESS;
}
