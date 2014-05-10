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

int identifyCommand(char* commandName){
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