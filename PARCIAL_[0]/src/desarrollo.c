/*
 * desarrollo.c
 *
 *  Created on: 23 may. 2022
 *      Author: PEREZ CARDENAL PATRICIO
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "desarrollo.h"
#include "censo.h"

int id = 2000;

int generarId()
{
	id++;

	return id;
}

void clear()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void animacionApagado()
{
	int i;
	int frames;
	int tiempo;

	frames = 6;
	tiempo = 250;

	for(i = 0 + 1; i < frames; i++)
	{
		switch(i)
		{
		case 1:
			clear();
			printf("|>--       5          <|");
			Sleep(tiempo);
		break;
		case 2:
			clear();
			printf("|>-----   35          <|");
			Sleep(tiempo);
		break;
		case 3:
			clear();
			printf("|>--------65--        <|");
			Sleep(tiempo);
		break;
		case 4:
			clear();
			printf("|>--------95-------   <|");
			Sleep(tiempo);
		break;
		case 5:
			clear();
			printf("|>--------100---------<|");
			Sleep(tiempo);
		break;
		}
	}
}

void animacionCargando()
{
	int i;
	int frames;
	int tiempo;

	frames = 9;
	tiempo = 100;

	for(i = 0 + 1; i < frames; i++)
	{
		switch(i)
		{
		case 1:
			clear();
			printf("|<[CARGANDO]>|: |>--                 <|");
			Sleep(tiempo);
		break;
		case 2:
			clear();
			printf("|<[CARGANDO]>|: |>-----              <|");
			Sleep(tiempo);
		break;
		case 3:
			clear();
			printf("|<[CARGANDO]>|: |>--------           <|");
			Sleep(tiempo);
		break;
		case 4:
			clear();
			printf("|<[CARGANDO]>|: |>-----------        <|");
			Sleep(tiempo);
		break;
		case 5:
			clear();
			printf("|<[CARGANDO]>|: |>-------------      <|");
			Sleep(tiempo);
		break;
		case 6:
			clear();
			printf("|<[CARGANDO]>|: |>---------------    <|");
			Sleep(tiempo);
		break;
		case 7:
			clear();
			printf("|<[CARGANDO]>|: |>-----------------  <|");
			Sleep(tiempo);
		break;
		case 8:
			clear();
			printf("|<[CARGANDO]>|: |>-------------------<|");
			Sleep(tiempo);
		break;
		}
	}
}
