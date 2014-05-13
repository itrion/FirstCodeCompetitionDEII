#include "Commands.h"
#include "ProgramSplitter.h"
#include <stdlib.h>
#include <string.h>

const int MAX_MEMORY_SIZE = 30000;

int (*commandsFunctions[17])(ChachoLangMemory* memory, char* commandString) = {
	quita, vetea, apunta, buenas, patras, venga, aumenta, chacho, depende,
	edneped, imprimo, leeaqui, maburri, palante, imprimio, intentalo, voyarepetirme};

int quita(ChachoLangMemory* memory, char* commandString){
	int decremento = convertToInteger(slice(commandString, 5, strlen(commandString) - 2));
	memory->memory[memory->currentPosition] -= decremento;
	return BAD_COMMAND;
}

int vetea(ChachoLangMemory* memory, char* commandString){
	//memory->currentPosition = posicion;
	return BAD_COMMAND;
}

int apunta(ChachoLangMemory* memory, char* commandString){
	return BAD_COMMAND;
}

int buenas(ChachoLangMemory* memory, char* commandString){
	memory->size = MAX_MEMORY_SIZE;
	memory->currentPosition = 0;
	memory->memory = malloc(sizeof(int) * MAX_MEMORY_SIZE);
	return 0;
}

int patras(ChachoLangMemory* memory, char* commandString){
	memory->currentPosition -= 1;
	return 0;
}

int venga(ChachoLangMemory* memory, char* commandString){
	return BAD_COMMAND;
}

int aumenta(ChachoLangMemory* memory, char* commandString){
	int incremento = convertToInteger(slice(commandString, 7, strlen(commandString) - 1));
	if(memory->memory[memory->currentPosition] + incremento > 255) return -1;
	memory->memory[memory->currentPosition] += incremento;
	return 0;
}

int chacho(ChachoLangMemory* memory, char* commandString){return BAD_COMMAND;}
int depende(ChachoLangMemory* memory, char* commandString){return BAD_COMMAND;}
int edneped(ChachoLangMemory* memory, char* commandString){return BAD_COMMAND;}
int imprimo(ChachoLangMemory* memory, char* commandString){return BAD_COMMAND;}
int leeaqui(ChachoLangMemory* memory, char* commandString){return BAD_COMMAND;}
int maburri(ChachoLangMemory* memory, char* commandString){return BAD_COMMAND;}

int palante(ChachoLangMemory* memory, char* commandString){
	memory->currentPosition += 1; 
	return BAD_COMMAND;
}

int imprimio(ChachoLangMemory* memory, char* commandString){return BAD_COMMAND;}
int intentalo(ChachoLangMemory* memory, char* commandString){return BAD_COMMAND;}
int voyarepetirme(ChachoLangMemory* memory, char* commandString){return BAD_COMMAND;}
