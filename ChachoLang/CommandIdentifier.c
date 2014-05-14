#include "CommandIdentifier.h"
#include <string.h>

const int FIVE_LETTERS_INDEX = 0;
const int SIX_LETTERS_INDEX = 2;
const int SEVEN_LETTERS_INDEX = 6;
const int EIGHT_LETTERS_INDEX = 14;
const int NINE_LETTERS_INDEX = 15;
const int THIRTEEN_LETTERS_INDEX = 16;

int checkQuita(char* command);
int checkVetea(char* command);
int checkVenga(char* command);
int checkApunta(char* command);
int checkBuenas(char* command);
int checkPatras(char* command);
int checkChacho(char* command);
int checkAumenta(char* command);
int checkDepende(char* command);
int checkEdneped(char* command);
int checkImprimo(char* command);
int checkLeeAqui(char* command);
int checkMaburri(char* command);
int checkPalante(char* command);
int checkImprimio(char* command);
int checkIntentalo(char* command);
int checkVoyARepetirme(char* command);

int (*commandChecker[17])(char* command) = {
	checkQuita, checkVetea, checkApunta, checkBuenas, checkPatras, checkVenga, checkAumenta, 
	checkChacho, checkDepende, checkEdneped, checkImprimo, checkLeeAqui, checkMaburri,
	checkPalante, checkImprimio, checkIntentalo, checkVoyARepetirme
};

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

int identifyCommand(char* command){
	if (!commandFinishesWithSemicolon(command)) return BAD_COMMAND;
	for (int i = FIVE_LETTERS_INDEX; i < SIX_LETTERS_INDEX; ++i){
		if(strncmp(command, commandsNames[i], 5) == 0) return commandChecker[i](command);
	}
	for (int i = SIX_LETTERS_INDEX; i < SEVEN_LETTERS_INDEX; ++i){
		if(strncmp(command, commandsNames[i], 6) == 0) return commandChecker[i](command);
	}
	for (int i = SEVEN_LETTERS_INDEX; i < EIGHT_LETTERS_INDEX; ++i){
		if(strncmp(command, commandsNames[i], 7) == 0) return commandChecker[i](command);
	}
	if(strncmp(command, commandsNames[EIGHT_LETTERS_INDEX], 8) == 0) return commandChecker[14](command);
	if(strncmp(command, commandsNames[NINE_LETTERS_INDEX], 9) == 0) return commandChecker[15](command);
	if(strncmp(command, commandsNames[THIRTEEN_LETTERS_INDEX], 13) == 0) return commandChecker[16](command);
	return BAD_COMMAND;
}

int checkQuita(char* command){
	if (strlen(command) <= 5) return BAD_COMMAND;
	return QUITA;
}
int checkVetea(char* command){
	if(strlen(command) <= 6) return BAD_COMMAND;
	return VETEA;
}
int checkVenga(char* command){
	return VENGAA;
}
int checkApunta(char* command){
	if(strlen(command) != 9) return BAD_COMMAND;
	return APUNTA;
}
int checkBuenas(char* command){
	return BUENAS;
}
int checkPatras(char* command){
	return PATRAS;
}
int checkChacho(char* command){
	return CHACHOO;
}
int checkAumenta(char* command){
	if(strlen(command) <= 8) return BAD_COMMAND;
	return AUMENTA;
}
int checkDepende(char* command){
	if(strlen(command) <= 8) return BAD_COMMAND;
	return DEPENDE;
}
int checkEdneped(char* command){
	return EDNEPED;
}
int checkImprimo(char* command){
	if(strlen(command) <= 10) return BAD_COMMAND;
	return IMPRIMO;
}
int checkLeeAqui(char* command){
	if(strlen(command) <= 9) return BAD_COMMAND;
	return LEEAQUI;
}
int checkMaburri(char* command){
	return MABURRI;
}
int checkPalante(char* command){
	return PALANTE;
}
int checkImprimio(char* command){
	if(strlen(command) < 11) return BAD_COMMAND;
	return IMPRIMIO;
}
int checkIntentalo(char* command){
	return INTENTALO;
}
int checkVoyARepetirme(char* command){
	if(strlen(command) <= 21) return BAD_COMMAND;
	return VOYAREPETIRME;
}
