/*
 * input.c
 *
 *  Created on: 23 may. 2022
 *      Author: patri
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "desarrollo.h"
#include "censo.h"

int validarCaracteres (char* string)
{
	int validator;
	int i;

	validator = 1;

	for(i = 0; i < strlen(string); i++)
	{
		if (isdigit(*(string + i)))
		{
			validator = 0;
		}
	}
	return validator;
}

int validarNumeros(char* numeros)
{
	int validator;
	int i;

	validator = 1;

	for(i = 0; i < strlen(numeros); i++)
	{
		if (!(isdigit(*(numeros + i))))
		{
			validator = 0;
		}
	}
	return validator;
}

int pedirEntero(char mensaje[])
{
	int entero;

	char numero[1000];

	printf(mensaje);
	scanf("%s", numero);

	while(!validarNumeros(numero))
	{
		clear();
		printf("|<ERROR>| (Escriba unicamente numeros)\n");
		printf(mensaje);
		scanf("%s", numero);
	}

	entero = atoi(numero);

	return entero;
}
