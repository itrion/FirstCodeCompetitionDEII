#include "Commands.h"
const int MAX_MEMORY_SIZE = 30000;

void quita(ChachoLangMemory* memory, int posicionesParaQuitar){
	memory->currentPosition -= posicionesParaQuitar;	
}

void vetea(ChachoLangMemory* memory, int posicion){
	memory->currentPosition = posicion;
}

void buenas(ChachoLangMemory* memory){
	memory->size = MAX_MEMORY_SIZE;
	memory->currentPosition = 0;
}

void patras(ChachoLangMemory* memory){
	memory->currentPosition -= 1;
}

void aumenta(ChachoLangMemory* memory, int posicionesParaAumentar){
	memory->currentPosition += posicionesParaAumentar;	
}

void venga(ChachoLangMemory* memory){
}

void palante(ChachoLangMemory* memory){
	memory->currentPosition += 1;
}
