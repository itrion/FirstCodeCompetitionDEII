#include "ChachoLangInterpreter.h"
#include "CommandIdentifier.h"
#include "ProgramSplitter.h"
#include <string.h>
#include <stdlib.h>

int* identifyCommandsCodes(char** commands, int numberOfCommands){
	int* commandsCodes = malloc(sizeof(int) * numberOfCommands);
	for(int i = 0; i < numberOfCommands; i++){
		commandsCodes[i] = identifyCommand(*(commands + i));
	}
	return commandsCodes;
}

int isSomeCommandMalformed(int* commandsCodes, int numberOfCommands){
	for(int i = 0; i < numberOfCommands; i++){
		if(commandsCodes[i] == BAD_COMMAND) return 1;
	}return 0;
}

int execute(char* program){
	int numberOfCommands = countLines(program);
	char** commands = splitProgramInCommands(program);
	int* commandsCodes = identifyCommandsCodes(commands, numberOfCommands);
	if(isSomeCommandMalformed(commandsCodes, numberOfCommands)) return BAD_COMMAND;
	ChachoLangMemory memory;
	for (int i = 0; i < numberOfCommands; ++i){
		if(commandsFunctions[i](&memory, *(commands + i))) continue;
		return BAD_COMMAND;
	}
	return 0;
}