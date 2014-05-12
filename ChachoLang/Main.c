#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ChachoLangInterpreter.h"

#define BUFFER_SIZE 2048
const char END_CHARACTER = '"';

char* initializeBufferForConent(){
	char* bufferForContent = malloc(sizeof(char) * BUFFER_SIZE);
	for (int i = 0; i < BUFFER_SIZE; i++){bufferForContent[i] = '\0';}
	return bufferForContent;
}

void dicardFirstCharacter(){
	fgetc(stdin);
}

char* copyProgramFromInputToBuffer(char* targetBuffer){
	char nextChar;
	for (int i = 0; i < BUFFER_SIZE; i++){
		nextChar = (char)fgetc(stdin);
		if (nextChar == END_CHARACTER) return targetBuffer;
		else targetBuffer[i] = nextChar;
	}
	return targetBuffer;
}

int main(int argc, char const *argv[]){
	char* buffer = initializeBufferForConent();
	dicardFirstCharacter();
	execute(copyProgramFromInputToBuffer(buffer));
	free(buffer);
	return 0;
}