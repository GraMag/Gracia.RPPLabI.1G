#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Menus.h"

/**
 * @brief Muestra las opciones del menu principal
 *
 * @return Int con la opcion seleccionada
 */
int mainMenu()
{
	int option;
	printf("---x---x---x---x---x---x---x---x---x---\n"
			"1.- Cargar archivo\n"
			"2.- Imprimir lista\n"
			"3.- Asignar estadisticas\n"
			"4.- Filtrar por paises exitosos\n"
			"5.- Filtrar por paises en el horno\n"
			"6.- Ordenar por nivel de infeccion\n"
			"7.- Mostrar mas castigado\n"
			"8.- Salir\n"
			"---x---x---x---x---x---x---x---x---x---\n");
	scanf("%d", &option);
	return option;
}

/**
 * @brief Pide confirmacion al usuario para cerrar el programa
 *
 * @return Int [1] Cerrar [2] No cerrar
 */
int exitMenu()
{
	int option;
	printf("Esta seguro que desea salir?\n"
			"1.- Si\n"
			"2.- No\n");
	scanf("%d", &option);
	return option;
}

/**
 * @brief Mensaje de espera, no hace nada, es solo visual.
 *
 * @param mensaje
 */
void waiting(char* mensaje)
{
	printf("%s datos\n", mensaje);
	for(int i = 0; i < 3; i++)
	{
		printf("...\n");
		Sleep(1000);
	}
	printf("Datos listos\n");
}
