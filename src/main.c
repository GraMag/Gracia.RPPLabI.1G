#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "Menus.h"
#include "Controller.h"

int main(void) {

	setbuf(stdout, NULL);
	srand (time(NULL));
	int repeat = 1;
	int fileReady = 0;
	int exitNow;
	LinkedList* pandemicList = ll_newLinkedList();

	do
	{
		system("cls");

		switch(mainMenu()){
			case 1:
				if (!fileReady)
				{
					if(!controller_LoadFile(pandemicList))
					{
						fileReady = 1;
					}
					else
					{
						printf("No se pudo cargar el archivo\n");
					}
				} else {
					printf("El archivo ya esta cargado\n");
				}
				break;
			case 2:
				if(fileReady)
				{
					controller_PrintCountries(pandemicList);
				}
				else
				{
					printf("Aun no se ha cargado el archivo\n");
				}
					break;
			case 3:
				if(fileReady)
				{
					controller_SetRandom(pandemicList);

				}
				else
				{
					printf("Aun no se ha cargado el archivo\n");
				}
					break;
			case 4:
				if(fileReady)
				{
					controller_FilterSuccess(pandemicList);
				}
				else
				{
					printf("Aun no se ha cargado el archivo\n");
				}
				break;
			case 5:
				if(fileReady)
				{
					controller_FilterSuckcess(pandemicList);
				}
				else
				{
					printf("Aun no se ha cargado el archivo\n");
				}
					break;
			case 6:
				if(fileReady)
				{
					controller_Sort(pandemicList);
				}
				else
				{
					printf("Aun no se ha cargado el archivo\n");
				}
				break;
			case 7:
				if(fileReady)
				{
					controller_Muertos(pandemicList);
				}
				else
				{
					printf("Aun no se ha cargado el archivo\n");
				}
				break;
			case 8:
				exitNow = exitMenu();
				if(exitNow == 1)
				{
					exit(1);
				}
				else if (exitNow != 2)
				{
					printf("Opcion invalida\n");
					fflush(stdin);
				}
				break;
			default:
				printf("Opcion invalida\n");
				break;
		}
		system("pause");
	} while (repeat == 1);

	return EXIT_SUCCESS;
}
