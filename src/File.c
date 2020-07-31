#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Pais.h"

/**
 * @brief Recibe el nombre de un archivo y le agrega la extencion .csv
 *
 * @param fileName
 */
void selectFile(char* fileName)
{
	printf("Abrir archivo: \n");
	fflush(stdin);
	gets(fileName);
	strcat(fileName, ".csv");
}

/**
 * @brief Abre y cierra el archivo para cargar los datos del mismo
 *
 * @param path
 * @param list
 * @return int [-1] Path NULL o Lista no vacia [0] Ok
 */
int loadFile(char* path, LinkedList* list)
{
	int error = -1;

	FILE* file;
	if(path != NULL && (ll_isEmpty(list))) {
			file = fopen(path, "r");
			if(file != NULL){
				parser_PaisFromText(file,list);
			}
			fclose(file);
			printf("\nArchivo cargado con exito. \n\n");
			error = 0;
	}
	return error;
}

/**
 * @brief Abre el archivo, imprime los datos y lo cierra
 *
 * @param path
 * @param list
 * @return int [-1] Path o Lista NULL [0] Ok
 */
int saveFile(char* path, LinkedList* list)
{
	int error = -1;
	ePais auxpais;
	ePais* pais;
	FILE* file;
	int len = ll_len(list);

	if(path != NULL && !(ll_isEmpty(list))) {
			file = fopen(path, "w");

			if(file != NULL)
			{
				fprintf(file, "id,pais,recuperados,infectados,muertos\n");
				for(int i = 0; i < len; i++)
				{
					pais = (ePais*) ll_get(list, i);
					pais_getID(pais, &auxpais.id);
					pais_getNombre(pais, auxpais.nombre);
					pais_getInfectados(pais, &auxpais.infectados);
					pais_getRecuperados(pais, &auxpais.recuperados);
					pais_getMuertos(pais, &auxpais.muertos);;
					fprintf(file, "%d,%s,%d,%d,%d\n",  auxpais.id, auxpais.nombre, auxpais.recuperados, auxpais.infectados, auxpais.muertos);
				}
			}
			fclose(file);
			printf("%s guardado.\n", path);
			error = 0;
	}
	return error;
}

