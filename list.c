#include "list.h"

List *makeList(FILE *inputFile){
	ListElmt *head = NULL;
	head = makeNewNode(NULL, head, head);
	List *list = (List *)malloc(sizeof(List));
	if(NULL == list){
		fprintf(stderr, "Allocate list fail.\n");
		exit(1);
	}
	list->head = head;
	list->tail = head;

	int hour;
	int minu;
	float temp;
	ListData *tempData = NULL;
	ListElmt *tempNode = NULL;
	while(!feof(inputFile)){
		fscanf(inputFile, "%d:%d %f\n", &hour, &minu, &temp);
		tempData = makeNewData(hour, minu, TRUE, OFF, temp, 0);// 1 means valid, 0 invalid
		tempNode = makeNewNode(tempData, NULL, NULL);
		list->tail = insertNewNode(list->head, list->tail, tempNode);
	}
	return list;
}

ListElmt *insertNewNode(ListElmt *head, ListElmt *tail, ListElmt *newNode){
	newNode->next = head;
	newNode->prev = tail;
	head->prev = newNode;
	tail->next = newNode;
	return newNode;
}

void removeInvalidData(List *list){
	ListElmt *head = list->head;
	ListElmt *currentNode = head->next;
	int lastTemp, currentTemp;
	while(currentNode != head){
		if(currentNode->prev != head){
			lastTemp = getTemperature(currentNode->prev);
			currentTemp = getTemperature(currentNode);
			if((lastTemp + 5 <= currentTemp) && (lastTemp - 5 >= currentTemp))
				setValid(currentNode, FALSE);
		}
		currentNode = currentNode->next;
	}
}

void lowPassFilter(List *list){
	ListElmt *head = list->head;
	ListElmt *currentNode = head->next;
	float lastTemp, currentTemp;
	while(currentNode != head){
		if(currentNode->prev != head){
			if(getValid(currentNode) == FALSE)
				currentTemp = getTemperature(currentNode);
			else
				currentTemp = 0.9375 * lastTemp + 0.0625 * getTemperature(currentNode);
		}
		else
			currentTemp = getTemperature(currentNode);
		setTemperatureResult(currentNode, currentTemp);
		lastTemp = currentTemp;
		currentNode = currentNode->next;
	}
}

void setStatus(List *list){
	ListElmt *head = list->head;
	ListElmt *currentNode = head->next;
	while(currentNode != head){
		if(currentNode->prev != head){
			if(getValid(currentNode) == FALSE)
				setOnOff(currentNode, OFF);

			if(currentNode->next != head 
					&& getValid(currentNode->prev) != FALSE 
					&& getValid(currentNode->next) != FALSE){
				if((getOnOff(currentNode->prev) == OFF) 
						&& (getTemperatureResult(currentNode) < getTemperatureResult(currentNode->prev))
						&& (getTemperatureResult(currentNode) > getTemperatureResult(currentNode->next)))
					setOnOff(currentNode, ON);

				else if((getOnOff(currentNode->prev) == ON) 
						&& (getTemperatureResult(currentNode) <= getTemperatureResult(currentNode->prev)))
					setOnOff(currentNode, ON);

				else
					setOnOff(currentNode, OFF);
			}else{
				if((getOnOff(currentNode->prev) == ON) 
						&& (getTemperatureResult(currentNode) <= getTemperatureResult(currentNode->prev)))
					setOnOff(currentNode, ON);
				else
					setOnOff(currentNode, OFF);
			}
		}
		currentNode = currentNode->next;
	}
}

void outputResult(List *list, FILE *outputFile){
	ListElmt *head = list->head;
	ListElmt *currentNode = head->next;
	while(currentNode != head){
		fprintf(outputFile, "%02d:%02d %05.3f\t%d\n", 
				getHour(currentNode), 
				getMinute(currentNode), 
				getTemperatureResult(currentNode),
				getOnOff(currentNode));
		currentNode = currentNode->next;
	}
}

void freeList(List *list){
	ListElmt *head = list->head;
	ListElmt *lastNode = list->head;
	ListElmt *currentNode = lastNode->next;
	while(currentNode != head){
		lastNode = currentNode;
		currentNode = currentNode->next;
		freeNode(lastNode);
	}
	freeNode(currentNode);
	free(list);
} 
