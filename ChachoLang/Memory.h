#ifndef CHACHO_LANG_MEMORY_H
#define CHACHO_LANG_MEMORY_H

typedef struct{
	int currentPosition;
	int size;
	int* memory;
} ChachoLangMemory;

#endif