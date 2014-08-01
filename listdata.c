#include "listdata.h"

ListData *makeNewData(int hour, int minu, int valid, int onOff, float temp, float tempResult){
	ListData *newData = (ListData *)malloc(sizeof(ListData));
	if(NULL == newData){
		fprintf(stderr, "Allocate new data fail.\n");
		exit(1);
	}
	newData->hour = hour;
	newData->minu = minu;
	newData->valid = valid;
	newData->temp = temp;
	return newData;
}

int hour(ListData *data){
	return data->hour;
}

int minute(ListData *data){
	return data->minu;
}

int valid(ListData *data){
	return data->valid;
}

void setDataValid(ListData *data, int valid){
	data->valid = valid;
}

int onOff(ListData *data){
	return data->onOff;
}

void setDataOnOff(ListData *data, int onOff){
	data->onOff = onOff;
}

float temperature(ListData *data){
	return data->temp;
}

float temperatureResult(ListData *data){
	return data->tempResult;
}

void setDataTemperatureResult(ListData *data, float temperatureResult){
	data->tempResult = temperatureResult;
}

void freeData(ListData *data){
	free(data);
}
