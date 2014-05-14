#ifndef CHACHO_LANG_COMMANDS_H
#define CHACHO_LANG_COMMANDS_H

#include "Memory.h"

#define	BAD_COMMAND -1
#define	QUITA 0
#define	VETEA 1
#define	APUNTA 2
#define	BUENAS 3
#define	PATRAS 4
#define	VENGAA 5
#define	AUMENTA 6
#define	CHACHOO 7
#define	DEPENDE 8
#define	EDNEPED 9
#define	IMPRIMO 10
#define	LEEAQUI 11
#define	MABURRI 12
#define	PALANTE 13
#define	IMPRIMIO 14
#define	INTENTALO 15
#define	VOYAREPETIRME 16

int (*commandsFunctions[17])(ChachoLangMemory* memory, char* commandString);

int quita(ChachoLangMemory* memory, char* commandString);
int vetea(ChachoLangMemory* memory, char* commandString);
int apunta(ChachoLangMemory* memory, char* commandString);
int buenas(ChachoLangMemory* memory, char* commandString);
int patras(ChachoLangMemory* memory, char* commandString);
int venga(ChachoLangMemory* memory, char* commandString);
int aumenta(ChachoLangMemory* memory, char* commandString);
int chacho(ChachoLangMemory* memory, char* commandString);
int depende(ChachoLangMemory* memory, char* commandString);
int edneped(ChachoLangMemory* memory, char* commandString);
int imprimo(ChachoLangMemory* memory, char* commandString);
int leeaqui(ChachoLangMemory* memory, char* commandString);
int maburri(ChachoLangMemory* memory, char* commandString);
int palante(ChachoLangMemory* memory, char* commandString);
int imprimio(ChachoLangMemory* memory, char* commandString);
int intentalo(ChachoLangMemory* memory, char* commandString);
int voyarepetirme(ChachoLangMemory* memory, char* commandString);

#endif