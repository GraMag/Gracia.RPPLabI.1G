#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Informes.h"
#include "Pais.h"

/**
 * @brief Vincula la lista con las funciones que asignan los valores aleatoreos
 *
 * @param list
 * @return int [-1] Lista Null [0] Ok
 */
int pais_Random(LinkedList* list)
{
	int error = -1;

		if(!ll_isEmpty(list))
		{
			ll_map(list, pais_RandomRecuperados);
			ll_map(list, pais_RandomInfectados);
			ll_map(list, pais_RandomMuertos);
			error = 0;
		}

	return error;
}

/**
 * @brief Asigna un valor random a la cantidad de recuperados
 *
 * @param recuperados
 * @return ePais* cantidad de recuperados
 */
void* pais_RandomRecuperados(void *recuperados)
{
	//int random= rand()%950001 + 50000;
	int random = 50000+rand()%(1000001 - 50000);
	pais_setRecuperados(recuperados, random);

	return recuperados;
}

/**
 * @brief Asigna un valor random a la cantidad de infectados
 *
 * @param infectados
 * @return ePais* cantidad de infectados
 */
void* pais_RandomInfectados(void* infectados)
{
//	int random= rand()% 1960001 + 40000;
	int random = 40000+rand()%(2000001 - 40000);

	pais_setInfectados(infectados, random);

	return infectados;
}
/**
 * @brief Asigna un valor random a la cantidad de muertos
 *
 * @param muertos
 * @return ePais* con la cantidad de muertos
 */
void* pais_RandomMuertos(void* muertos)
{
//	int random= rand()% 49001 + 1000;
	int random = 1000+rand()%(50001 - 1000);

	pais_setMuertos(muertos, random);

	return muertos;
}
/**
 * @brief Compara si la cantidad de muertos en el pais es menor a 5000
 *
 * @param muertos
 * @return int filter [1] si la cantidad de muertos es menor que 1 [0] Supera los 5000 casos
 */

int paises_filterBySuccess(void* muertos)
{
	int filter = 0;
	int aux;

	pais_getMuertos(muertos, &aux);

	if(aux < 5000)
	{
		filter = 1;
	}
	return filter;
}

/**
 * @brief Compara si la cantidad de infectados triplica la de recuperados dentro de un mismo pais
 *
 * @param unPais
 * @return int filter [1] Si los infectados triplican a los recuperados [0] No triplica
 */
int paises_filterByInTheOven(void* unPais)
{
	int filter = 0;
	int auxInfectados;
	int auxRecuperados;
	ePais* auxpais;

	auxpais = (ePais*) unPais;
	pais_getInfectados(auxpais, &auxInfectados);
	pais_getRecuperados(auxpais, &auxRecuperados);

	if(auxInfectados > (auxRecuperados*3))
	{
		filter = 1;
	}
	return filter;
}

/**
 * @brief Compara un infectado con otro para su ordenamiento
 *
 * @param infectados1
 * @param infectados2
 * @return Int order [1] Si el primer dato es mayor que el segundo
 * 					 [-1] Si el primer dato es menor que el segundo
 */
int paises_SortByLevel(void* infectados1, void* infectados2)
{
	int order;
	int auxInfectados1;
	int auxInfectados2;

	pais_getInfectados(infectados1, &auxInfectados1);
	pais_getInfectados(infectados2, &auxInfectados2);


	if(auxInfectados1 > auxInfectados2)
	{
		order = 1;
	}
	else
	{
		order = -1;
	}
	return order;
}
/**
 * @brief Busca el pais con maayor cantidad de muertos
 *
 * @param list
 * @return Int [-1] Lista Null [0] Ok
 */
int pais_MasCastigado(LinkedList* list)
{
	int error = -1;
	int max ;
	char pais[50];
	int len = ll_len(list);
	ePais* aux;

	if(!ll_isEmpty(list))
	{
		for(int i = 0; i < len - 1 ; i++){

			for(int j = i + 1 ; j < len; j++){
				aux = ll_get(list,i);
				if(aux->muertos > max || i == 0)
				{
					max = aux->muertos;
					strcpy(pais, aux->nombre);
				}
			}
		}

		printf("El numero mayor de muertes es %d y se da en %s \n", max, pais);

		for(int i = 0; i < len - 1 ; i++){
			for(int j = i + 1 ; j < len; j++){
				aux = ll_get(list,i);
				if(aux->muertos == max && strcmp(aux->nombre,pais) != 0)
				{
					printf(", %s\n", aux->nombre);
				}
			}
		}
		return 0;
	}
	return error;
}
