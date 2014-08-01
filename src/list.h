#ifndef _List_
#define _List_

#include <stdio.h>
#include <stdlib.h>
#include "listelmt.h"
#include "listdata.h"

#define	ON		1
#define	OFF		0
#define	TRUE	1
#define	FALSE	0

typedef struct List_ {
	int size;
	ListElmt *head;
	ListElmt *tail;
} List;

List *makeList(FILE *inputFile);
ListElmt *insertNewNode(ListElmt *head, ListElmt *tail, ListElmt *newNode);
void removeInvalidData(List *list);
void lowPassFilter(List *list);
void setStatus(List *list);
void outputResult(List *list, FILE *outputFile);
void freeList(List *list);
#endif
