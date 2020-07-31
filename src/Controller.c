#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Informes.h"
#include "File.h"
#include "Menus.h"

/**
 * @brief Llama a la funcion que carga un archivo de texto
 *
 * @param list
 * @return int [-1] La lista no esta vacia [0] Ok
 */
int controller_LoadFile(LinkedList* list)
{
	int error = -1;
	char fileName[100];

	if(ll_isEmpty(list))
	{
		selectFile(fileName);
		loadFile(fileName, list);
		error = 0;
	}
	return error;
}

/**
 * @brief Llama a la funcion que muestra en pantalla el listado de paises
 *
 * @param list
 * @return int [-1] La lista esta vacia [0] Ok
 */
int controller_PrintCountries(LinkedList* list)
{
	int error = -1;

	if(!ll_isEmpty(list))
	{
		paises_print(list);
		error = 0;
	}
	return error;
}

/**
 * @brief Llama a la funcion que asigna valores aleatoreos
 *
 * @param list
 * @return int [-1] La lista no esta vacia [0] Ok
 */
int controller_SetRandom(LinkedList* list)
{
	int error = -1;

	if(!ll_isEmpty(list))
	{
		pais_Random(list);
		waiting("Recopilando");
		error = 0;
	}
	return error;
}

/**
 * @brief Llama a la funcion que guarda en un archivo una sublista con los paises con menos de 5000 muertos
 *
 * @param list
 * @return int [-1] La lista no esta vacia [0] Ok
 */
int controller_FilterSuccess(LinkedList* list)
{
	int error = -1;

	if(!ll_isEmpty(list))
	{
		saveFile("exitosos.csv", ll_filter(list,paises_filterBySuccess));
		error = 0;
	}
	return error;
}

/**
 * @brief Llama a la funcion que guarda en un archivo una sublista con los paises donde los infectados
 *  triplique a los recuperados
 *
 * @param list
 * @return int [-1] La lista no esta vacia [0] Ok
 */
int controller_FilterSuckcess(LinkedList* list)
{
	int error = -1;

	if(!ll_isEmpty(list))
	{
		if(saveFile("fracaso.csv", ll_filter(list, paises_filterByInTheOven)))
		{
			printf("No hay registros que guardar\n");
		}
		error = 0;
	}
	return error;
}

/**
 * @brief Llama a la funcion que ordena los paises por cantidad de infectados de manera descendente
 *
 * @param list
 * @return int [-1] La lista no esta vacia [0] Ok
 */
int controller_Sort(LinkedList* list)
{
	int error = -1;

	if(!ll_isEmpty(list))
	{
		ll_sort(list, paises_SortByLevel, 0);
		waiting("Ordenando");
		error = 0;
	}
	return error;
}

/**
 * @brief Llama a la funcion que busca el pais con más muertos
 *
 * @param list
 * @return int [-1] La lista no esta vacia [0] Ok
 */
int controller_Muertos(LinkedList* list)
{
	int error = -1;

		if(!ll_isEmpty(list))
		{
			pais_MasCastigado(list);
			error = 0;
		}
		return error;
}
