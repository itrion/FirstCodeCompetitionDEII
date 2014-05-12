#ifndef CHACHO_LANG_COMMANDS_H
#define CHACHO_LANG_COMMANDS_H

#include "Memory.h"

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


void quita(ChachoLangMemory* memory, int posicionesParaQuitar);
void vetea(ChachoLangMemory* memory, int posicion);
void buenas(ChachoLangMemory* memory);
void patras(ChachoLangMemory* memory);
void aumenta(ChachoLangMemory* memory, int posicionesParaAumentar);
void venga(ChachoLangMemory* memory);
void palante(ChachoLangMemory* memory);

#endif