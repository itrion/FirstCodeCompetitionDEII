#include "ChachoLangInterpreter.h"
#include "CommandIdentifier.h"
#include "ProgramSplitter.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int* identifyCommandsCodes(char** commands, int numberOfCommands){
	int* commandsCodes = malloc(sizeof(int) * numberOfCommands);
	for(int i = 0; i < numberOfCommands; i++){
		commandsCodes[i] = identifyCommand(*(commands + i));
	}
	return commandsCodes;
}

int isSomeCommandMalformed(int* commandsCodes, int numberOfCommands){
	for(int i = 0; i < numberOfCommands; i++){
		if(commandsCodes[i] == BAD_COMMAND) {
			return 1;
		}
	}return 0;
}

int startWithBuenas(int* commandsCodes){
	return commandsCodes[0] == BUENAS;
}

int programFinishWithVenga(int* commandsCodes, int numberOfCommands){
	return commandsCodes[numberOfCommands - 1] == VENGAA;
}

int printError(){
	printf("%d\n", BAD_COMMAND);
	return BAD_COMMAND;
}

int findNextStopLoopCommand(int* commandsCodes, int commandIndex, int numberOfCommands){
	for(int i=commandIndex; i<numberOfCommands; i++){
		if(commandsCodes[i] == MABURRI) return i;
	}return -1;
}

int repeat(ChachoLangMemory* memory, int* commandsCodes, char** commands, int* commandIndex, int iterations, int numberOfCommands){
	int loopStopIndex = findNextStopLoopCommand(commandsCodes, *commandIndex, numberOfCommands);
	if(loopStopIndex < 0) return BAD_COMMAND;
	for(int j=0; j<iterations; j++){
		for(int i=*commandIndex + 1; i < loopStopIndex - 1; i++){
			if(commandsFunctions[commandsCodes[i]](memory, *(commands + i)) == BAD_COMMAND) {
				return BAD_COMMAND;
			}
		}
	}
	commandIndex[0] = loopStopIndex + 1;
	return 0;
}

int execute(char* program){
	int numberOfCommands = countLines(program);
	char** commands = splitProgramInCommands(program);
	int* commandsCodes = identifyCommandsCodes(commands, numberOfCommands);
	if(isSomeCommandMalformed(commandsCodes, numberOfCommands)) return printError();
	if(!startWithBuenas(commandsCodes))return printError();
	if(!programFinishWithVenga(commandsCodes, numberOfCommands)) return printError();
	ChachoLangMemory memory;
	int commandIndex = 0;
	while(commandsCodes[commandIndex] != VENGAA){
		if(commandsCodes[commandIndex] == VOYAREPETIRME){
			if(repeat(&memory, commandsCodes, commands, &commandIndex, voyarepetirme(&memory, *(commands + commandIndex)), numberOfCommands) == BAD_COMMAND){
				return printError();
			}
		}
		else if(commandsFunctions[commandsCodes[commandIndex]](&memory, *(commands + commandIndex)) != BAD_COMMAND) {
			commandIndex++;
		}
		else return printError();
	}
	return 0;
}