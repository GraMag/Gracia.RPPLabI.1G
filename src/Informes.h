#include "Pais.h"
#ifndef INFORMES_H_
#define INFORMES_H_

int pais_Random(LinkedList* list);
void* pais_RandomRecuperados(void *recuperados);
void* pais_RandomInfectados(void* infectados);
void* pais_RandomMuertos(void* muertos);

int paises_filterBySuccess(void* muertos);
int paises_filterByInTheOven(void* unPais);

int paises_SortByLevel(void* infectados1, void* infectados2);

int pais_MasCastigado(LinkedList* list);

#endif /* INFORMES_H_ */
