#include "CommandIdentifier.h"
#include <string.h>
#include <stdio.h>

const char* commandsNames[] = {
	"quita\0",
	"vetea\0",
	"apunta\0",
	"buenas\0",
	"patras\0",
	"venga!\0",
	"aumenta\0",
	"chacho!\0",
	"depende\0",
	"edneped\0",
	"imprimo\0",
	"leeaqui\0",
	"maburri\0",
	"palante\0",
	"imprimio\0",
	"intentalo\0",
	"voyarepetirme\0"};

int identify(char* commandName);
char* cleanCommand(char* command);
char* removeSemicolon(char* command);

int identifyCommand(char* commandText){
	return identify(cleanCommand(commandText));
}

char* cleanCommand(char* command){
	return removeSemicolon(command);
}

char* removeSemicolon(char* command){
	command[strlen(command) - 1] = '\0';
	return command;
}

int identify(char* commandName){
	for (int i = 0; i <= 1; ++i){
		if(strncmp(commandName, commandsNames[i], 5) == 0) return i;
	}
	for (int i = 2; i <=5; ++i){
		if(strncmp(commandName, commandsNames[i], 6) == 0) return i;
	}
	for (int i = 6; i <=13; ++i){
		if(strncmp(commandName, commandsNames[i], 7) == 0) return i;
	}
	if(strncmp(commandName, commandsNames[14], 8) == 0) return 14;
	if(strncmp(commandName, commandsNames[15], 9) == 0) return 15;
	if(strncmp(commandName, commandsNames[16], 13) == 0) return 16;
	return -1;
}