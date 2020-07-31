#ifndef PAIS_H_
#define PAIS_H_

typedef struct
{
	int id;
	char nombre[50];
	int infectados;
	int recuperados;
	int muertos;
}ePais;

ePais* pais_new();
ePais* pais_NewParam(char* id, char* nombre, char* infectados, char* recuperados, char* muertos);

int pais_getID(ePais* this, int* id);
int pais_setID(ePais* this, int id);
int pais_getNombre(ePais* this, char* name);
int pais_setNombre(ePais* this, char* name);
int pais_getInfectados(ePais* this, int* infectados);
int pais_setInfectados(ePais* this, int infectados);
int pais_getRecuperados(ePais* this, int* recuperados);
int pais_setRecuperados(ePais* this, int recuperados);
int pais_getMuertos(ePais* this, int* muertos);
int pais_setMuertos(ePais* this, int muertos);

int pais_print(ePais* this);
int paises_print(LinkedList* list);

#endif /* PAIS_H_ */
