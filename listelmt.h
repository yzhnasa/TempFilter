#ifndef _ListElmt_
#define _ListElmt_

#include <stdio.h>
#include <stdlib.h>
#include "listdata.h"

typedef struct ListElmt_ {
	ListData *data;
	struct ListElmt_ *next;
	struct ListElmt_ *prev;
} ListElmt;

ListElmt *makeNewNode(ListData *data, ListElmt *next, ListElmt *prev);
int getHour(ListElmt *node);
int getMinute(ListElmt *node);
int getValid(ListElmt *node);
void setValid(ListElmt *node, int valid);
int getOnOff(ListElmt *node);
void setOnOff(ListElmt *node, int onOff);
float getTemperature(ListElmt *node);
float getTemperatureResult(ListElmt *node);
void setTemperatureResult(ListElmt *node, float tempResult);
void freeNode(ListElmt *node);
#endif
