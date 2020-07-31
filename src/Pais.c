#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Pais.h"

/**
 * @brief Crea un nuevo pais en memoria sin parametros
 *
 * @return ePais* newPais con datos default o NULL y libera la memoria
 */
ePais* pais_new()
{
	ePais* newPais = (ePais*) malloc (sizeof(ePais));
	if(newPais != NULL)
	{
		pais_setID(newPais, 0);
		pais_setNombre(newPais, "");
		pais_setRecuperados(newPais, 0);
		pais_setInfectados(newPais, 0);
		pais_setMuertos(newPais, 0);
	}
	else
	{
		free(newPais);
		newPais = NULL;
	}
	return newPais;
}

/**
 * @brief Crea un nuevo pais con parametros en memoria
 *
 * @param id
 * @param nombre
 * @param infectados
 * @param recuperados
 * @param muertos
 * @return ePais newPais con los datos asignados, o NULL y libera la memoria
 */
ePais* pais_NewParam(char* id, char* nombre, char* recuperados, char* infectados, char* muertos)
{
	ePais* newPais = (ePais*) malloc (sizeof(ePais));
	newPais = pais_new();

	if(newPais != NULL)
	{
		pais_setID(newPais, atoi(id));
		pais_setNombre(newPais, nombre);
		pais_setRecuperados(newPais, atoi(recuperados));
		pais_setInfectados(newPais, atoi(infectados));
		pais_setMuertos(newPais, atoi(muertos));
	} else {
		free(newPais);
		newPais = NULL;
	}
	return newPais;

}

/**
 * @brief Toma el id de un pais
 *
 * @param this
 * @param id
 * @return error [-1] ePais Null o ID negativo [0] Ok
 */
int pais_getID(ePais* this, int* id)
{
	int error = -1;
	if (this != NULL && id >= 0)
	{
		*id = this->id;
		error = 0;
	}
	return error;
}

/**
 * @brief Asigna un id a un pais
 *
 * @param this
 * @param id
 * @return error [-1] ePais Null o ID negativo [0] Ok
 */
int pais_setID(ePais* this, int id)
{
	int error = -1;
	if (this != NULL && id >= 0)
	{
		this->id = id;
		error = 0;
	}
	return error;
}

/**
 * @brief Toma el nombre de un pais
 *
 * @param this
 * @param name
 * @return error [-1] ePais o Nombre Null  [0] Ok
 */
int pais_getNombre(ePais* this, char* name)
{
	int error = -1;
	if (this != NULL && name != NULL)
	{
		strcpy(name, this->nombre);
		error = 0;
	}
	return error;
}

/**
 * @brief Asigna un nombre a un pais
 *
 * @param this
 * @param name
 * @return error [-1] ePais o nombre Null [0] Ok
 */
int pais_setNombre(ePais* this, char* name)
{
	int error = -1;
	if (this != NULL && name != NULL)
	{
		strcpy(this->nombre, name);
		error = 0;
	}
	return error;
}

/**
 * @brief Toma el numero de infectados de un pais
 *
 * @param this
 * @param infectados
 * @return error [-1] ePais Null o cantidad de Infectados negativo [0] Ok
 */
int pais_getInfectados(ePais* this, int* infectados)
{
	int error = -1;
	if (this != NULL && infectados != NULL)
	{
		*infectados = this->infectados;
		error = 0;
	}
	return error;
}

/**
 * @brief Asigna cantidad de infectados
 *
 * @param this
 * @param infectados
 * @return error [-1] ePais Null o cantidad de Infectados negativo [0] Ok
 */
int pais_setInfectados(ePais* this, int infectados)
{
	int error = -1;
	if (this != NULL && infectados >= 0)
	{
		this->infectados = infectados;
		error = 0;
	}
	return error;
}

/**
 * @brief Toma el numero de recuperados de un pais
 *
 * @param this
 * @param recuperados
 * @return error [-1] ePais Null o cantidad de recuperados negativo [0] Ok
 */
int pais_getRecuperados(ePais* this, int* recuperados)
{
	int error = -1;
	if (this != NULL && recuperados != NULL)
	{
		*recuperados = this->recuperados;
		error = 0;
	}
	return error;
}

/**
 * @brief Asigna cantida de recuperados
 *
 * @param this
 * @param recuperados
 * @return error [-1] ePais Null o cantidad de recuperados negativo [0] Ok
 */
int pais_setRecuperados(ePais* this, int recuperados)
{
	int error = -1;
	if (this != NULL && recuperados >= 0)
	{
		this->recuperados = recuperados;
		error = 0;
	}
	return error;
}

/**
 * @brief Toma el numero de muertos de un pais
 *
 * @param this
 * @param muertos
 * @return error [-1] ePais Null o cantidad de muertos negativo [0] Ok
 */
int pais_getMuertos(ePais* this, int* muertos)
{
	int error = -1;
	if (this != NULL && muertos != NULL)
	{
		*muertos = this->muertos;
		error = 0;
	}
	return error;
}

/**
 * @brief Asigna el numero de muertos a un pais
 *
 * @param this
 * @param muertos
 * @return error [-1] ePais Null o cantidad de muertos negativo [0] Ok
 */
int pais_setMuertos(ePais* this, int muertos)
{
	int error = -1;
	if (this != NULL && muertos >= 0)
	{
		this->muertos = muertos;
		error = 0;
	}
	return error;
}

/**
 * @brief Imprime los datos de un pais
 *
 * @param this
 * @return int [-1] ePais Null [0] Ok
 */
int pais_print(ePais* this)
{
	int error = -1;

	if(this != NULL){
		printf("%d,%s,%d,%d,%d\n", this->id, this->nombre, this->recuperados, this->infectados, this->muertos);
		error = 0;
	}
	return error;
}

/**
 * @brief Imprime un listado de paises
 *
 * @param list
 * @return int [-1] Lista null [0] Ok
 */
int paises_print(LinkedList* list)
{
	int error = -1;
	int len = ll_len(list);

	printf("id,pais,recuperados,infectados,muertos\n");
	if(!ll_isEmpty(list))
	{
		for(int i = 0; i < len; i++)
		{
			pais_print(ll_get(list, i));
		}
		error = 0;
	}
	return error;
}
