#ifndef _ListData_
#define _ListData_

#include <stdio.h>
#include <stdlib.h>

typedef struct ListData_ {
	int hour;
	int minu;
	int valid;
	int onOff;
	float temp;
	float tempResult;
} ListData;

ListData *makeNewData(int hour, int minu, int valid, int onOff, float temp, float tempResult);
int hour(ListData *data);
int minute(ListData *data);
int valid(ListData *data);
void setDataValid(ListData *data, int valid);
int onOff(ListData *data);
void setDataOnOff(ListData *data, int onOff);
float temperature(ListData *data);
float temperatureResult(ListData *data);
void setDataTemperatureResult(ListData *data, float temperatureResult);
void freeData(ListData *data);
#endif
