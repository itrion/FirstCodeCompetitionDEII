#include "CommandIdentifier.h"
#include <string.h>
#include <stdio.h>

const int FIVE_LETTERS_INDEX = 0;
const int SIX_LETTERS_INDEX = 2;
const int SEVEN_LETTERS_INDEX = 6;
const int EIGHT_LETTERS_INDEX = 14;
const int NINE_LETTERS_INDEX = 15;
const int THIRTEEN_LETTERS_INDEX = 16;

const char* commandsNames[] = {
	"quita",
	"vetea",
	"apunta",
	"buenas",
	"patras",
	"venga!",
	"aumenta",
	"chacho!",
	"depende",
	"edneped",
	"imprimo",
	"leeaqui",
	"maburri",
	"palante",
	"imprimio",
	"intentalo",
	"voyarepetirme"};

int commandFinishesWithSemicolon(char* command){
	return command[strlen(command) - 1] == ';';
}

int identifyCommand(char* commandName){
	if (!commandFinishesWithSemicolon(commandName)) return BAD_COMMAND;
	for (int i = FIVE_LETTERS_INDEX; i < SIX_LETTERS_INDEX; ++i){
		if(strncmp(commandName, commandsNames[i], 5) == 0) return i;
	}
	for (int i = SIX_LETTERS_INDEX; i < SEVEN_LETTERS_INDEX; ++i){
		if(strncmp(commandName, commandsNames[i], 6) == 0) return i;
	}
	for (int i = SEVEN_LETTERS_INDEX; i < EIGHT_LETTERS_INDEX; ++i){
		if(strncmp(commandName, commandsNames[i], 7) == 0) return i;
	}
	if(strncmp(commandName, commandsNames[EIGHT_LETTERS_INDEX], 8) == 0) return 14;
	if(strncmp(commandName, commandsNames[NINE_LETTERS_INDEX], 9) == 0) return 15;
	if(strncmp(commandName, commandsNames[THIRTEEN_LETTERS_INDEX], 13) == 0) return 16;
	return -1;
}