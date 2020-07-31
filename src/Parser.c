#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Pais.h"

/**
 * @brief Carga los datos del archivo y los va agregando a la lista
 *
 * @param pFile
 * @param list
 * @return int [-1] pFile Null o lista !Null [0] Ok
 */
int parser_PaisFromText(FILE* pFile , LinkedList* list)
{
	int error = -1;
	char buffer[5][128];
	int amount;
	ePais* auxPais;
	ePais pais;

	if(pFile != NULL && (ll_isEmpty(list))) {
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]); // Encabezado
		while (!feof(pFile))
		{
			amount = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
			if (amount == 5)
			{
				auxPais = pais_NewParam(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
				if (auxPais != NULL)
				{
					pais_getID(auxPais, &pais.id);
					pais_getNombre(auxPais, pais.nombre);
					pais_getInfectados(auxPais, &pais.infectados);
					pais_getRecuperados(auxPais, &pais.recuperados);
					pais_getMuertos(auxPais, &pais.muertos);
					ll_add(list, auxPais);
				}
			}
			else
			{
				break;
			}
		}
		error = 0;
	}
    return error;
}
