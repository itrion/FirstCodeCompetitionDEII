#ifndef PROGRAM_SPLITTER_H
#define PROGRAM_SPLITTER_H

char** splitProgramInCommands(char* program);
int countLines(char* program);
char* slice(char* input, int sliceStart, int sliceFinish);
int convertToInteger(char* input);
int nextSpace(char* input, int startIndex);
#endif