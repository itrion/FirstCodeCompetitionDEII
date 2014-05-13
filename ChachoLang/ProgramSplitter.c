#include "ProgramSplitter.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

char* trim(char* token) {
    char* pointer = token;
    int length = strlen(pointer);
    while(isspace(pointer[length - 1])) pointer[--length] = 0;
    while(* pointer && isspace(* pointer)) ++pointer, --length;
    memmove(token, pointer, length + 1);
    return token;
}

char** splitProgramInCommands(char* program){
	if(strlen(program) == 0) return 0;
	char** result = malloc(sizeof(char*) * (countLines(program)));
	char* token = strtok(program, "\n");
	int resultIndex = 0;
	while(token != NULL){
		*(result + resultIndex++) = trim(strdup(token));
		token = strtok(NULL, "\n");
	}
	return result;
}

int countLines(char* text){
	if (text[0] == 0) return 0;
	int counter = 1;
	while(*text){
		if(*text == '\n'){counter++;}
		text++;
	}
	return counter;
}

char* slice(char* input, int sliceStart, int sliceFinish){
	char* subString = malloc(sizeof(char) * (sliceFinish - sliceStart));
	int subStringIndex = 0;
	for (int i = sliceStart; i <sliceFinish; i++){
		subString[subStringIndex++] = input[i];
	}
	return subString;
}

int convertToInteger(char* input){
	int value;
	sscanf(input, "%d", &value);
	return value;
}
