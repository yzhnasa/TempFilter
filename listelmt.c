#include "listelmt.h"

ListElmt *makeNewNode(ListData *data, ListElmt *next, ListElmt *prev){
	ListElmt *newNode = (ListElmt *)malloc(sizeof(ListElmt));
	if(NULL == newNode){
		fprintf(stderr, "Allocate new node file.\n");
		exit(1);
	}
	newNode->data = data;
	newNode->next = next;
	newNode->prev = prev;
	return newNode;
}

int getHour(ListElmt *node){
	return hour(node->data);
}

int getMinute(ListElmt *node){
	return minute(node->data);
}

int getValid(ListElmt *node){
	return valid(node->data);
}

void setValid(ListElmt *node, int valid){
	setDataValid(node->data, valid);
}

int getOnOff(ListElmt *node){
	return onOff(node->data);
}

void setOnOff(ListElmt *node, int onOff){
	setDataOnOff(node->data, onOff);
}

float getTemperature(ListElmt *node){
	return temperature(node->data);
}

float getTemperatureResult(ListElmt *node){
	return temperatureResult(node->data);
}

void setTemperatureResult(ListElmt *node, float tempResult){
	setDataTemperatureResult(node->data, tempResult);
}

void freeNode(ListElmt *node){
	freeData(node->data);
	free(node);
}
