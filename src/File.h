#include "LinkedList.h"
#ifndef FILE_H_
#define FILE_H_


void selectFile(char* fileName);
int loadFile(char* path, LinkedList* list);
int saveFile(char* path, LinkedList* list);


#endif /* FILE_H_ */
