#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void usage(char *progName, FILE *file);
int main(int argc, char *argv[]){
	if(argc != 3){
		usage(argv[0], stderr);
		exit(1);
	}

	FILE *inputFile = fopen(argv[1], "r");

	if(NULL == inputFile){
		fprintf(stderr, "File %s not exist.\n", argv[1]);
		exit(1);
	}

	FILE *outputFile = fopen(argv[2], "w");
	List *list = makeList(inputFile);
	removeInvalidData(list);
	lowPassFilter(list);
	setStatus(list);
	outputResult(list, outputFile);

	fclose(inputFile);
	fclose(outputFile);

	freeList(list);
	return 0;
}

void usage(char *progName, FILE *file){
	fprintf(file, "%s inputFile outputFile\n", progName);
}
