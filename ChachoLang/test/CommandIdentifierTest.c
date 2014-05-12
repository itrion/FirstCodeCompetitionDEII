#include "../CuTest/CuTest.h"
#include "../CommandIdentifier.h"
#include "../Commands.h"
#include "string.h"


void command_with_no_args(CuTest* cutest){
	CuAssertIntEquals(cutest, BUENAS, identifyCommand(strdup("buenas;")));
	CuAssertIntEquals(cutest, VENGAA, identifyCommand(strdup("venga!;")));
	CuAssertIntEquals(cutest, PALANTE, identifyCommand(strdup("palante;")));
	CuAssertIntEquals(cutest, PATRAS, identifyCommand(strdup("patras;")));
	CuAssertIntEquals(cutest, INTENTALO, identifyCommand(strdup("intentalo;")));
	CuAssertIntEquals(cutest, CHACHOO, identifyCommand(strdup("chacho!;")));
}

void command_with_args_in_brackets(CuTest* cutest){
	CuAssertIntEquals(cutest, IMPRIMO, identifyCommand("imprimo(10);"));
	CuAssertIntEquals(cutest, IMPRIMO, identifyCommand("imprimo(10);"));
	CuAssertIntEquals(cutest, APUNTA, identifyCommand("apunta();"));
}

void command_with_args_separated_by_a_space(CuTest* cutest){
	CuAssertIntEquals(cutest, VOYAREPETIRME, identifyCommand(strdup("voyarepetirme 1 veces;")));
	CuAssertIntEquals(cutest, VOYAREPETIRME, identifyCommand(strdup("voyarepetirme 11 veces;")));
	CuAssertIntEquals(cutest, VOYAREPETIRME, identifyCommand(strdup("voyarepetirme 111 veces;")));
	CuAssertIntEquals(cutest, VOYAREPETIRME, identifyCommand(strdup("voyarepetirme 1111 veces;")));
}

void command_with_args_joined_at_the_end(CuTest* cutest){
	CuAssertIntEquals(cutest, AUMENTA, identifyCommand(strdup("aumenta1;")));
	CuAssertIntEquals(cutest, AUMENTA, identifyCommand(strdup("aumenta10;")));
	CuAssertIntEquals(cutest, AUMENTA, identifyCommand(strdup("aumenta100;")));
	CuAssertIntEquals(cutest, QUITA, identifyCommand(strdup("quita2;")));
	CuAssertIntEquals(cutest, QUITA, identifyCommand(strdup("quita22;")));
	CuAssertIntEquals(cutest, QUITA, identifyCommand(strdup("quita222;")));
	CuAssertIntEquals(cutest, VETEA, identifyCommand(strdup("vetea1;")));
	CuAssertIntEquals(cutest, VETEA, identifyCommand(strdup("vetea11;")));
	CuAssertIntEquals(cutest, VETEA, identifyCommand(strdup("vetea111;")));
}

void malformed_commands(CuTest* cutest){
	CuAssertIntEquals(cutest, BAD_COMMAND, identifyCommand(strdup("venga;")));
	CuAssertIntEquals(cutest, BAD_COMMAND, identifyCommand(strdup("venga!")));
	CuAssertIntEquals(cutest, BAD_COMMAND, identifyCommand(strdup("voyarepetirme;")));
	CuAssertIntEquals(cutest, BAD_COMMAND, identifyCommand(strdup("voyarepetirme 12;")));
	CuAssertIntEquals(cutest, BAD_COMMAND, identifyCommand(strdup("voyarepetirme 12 veces")));
	CuAssertIntEquals(cutest, BAD_COMMAND, identifyCommand(strdup("voyarepetirme veces;")));
	CuAssertIntEquals(cutest, BAD_COMMAND, identifyCommand(strdup("leeaqui;")));
	CuAssertIntEquals(cutest, BAD_COMMAND, identifyCommand(strdup("leeaqui file")));
	CuAssertIntEquals(cutest, BAD_COMMAND, identifyCommand(strdup("imprimio;")));
	CuAssertIntEquals(cutest, BAD_COMMAND, identifyCommand(strdup("imprimio(;")));
	CuAssertIntEquals(cutest, BAD_COMMAND, identifyCommand(strdup("imprimio()")));
	CuAssertIntEquals(cutest, BAD_COMMAND, identifyCommand(strdup("imprimio(12)")));
	CuAssertIntEquals(cutest, BAD_COMMAND, identifyCommand(strdup("imprimo(12)")));
	CuAssertIntEquals(cutest, BAD_COMMAND, identifyCommand(strdup("aumenta;")));
	CuAssertIntEquals(cutest, BAD_COMMAND, identifyCommand(strdup("aumenta10")));
	CuAssertIntEquals(cutest, BAD_COMMAND, identifyCommand(strdup("aumenta100")));
	CuAssertIntEquals(cutest, BAD_COMMAND, identifyCommand(strdup("chacho;")));
	CuAssertIntEquals(cutest, BAD_COMMAND, identifyCommand(strdup("chacho!")));
	CuAssertIntEquals(cutest, BAD_COMMAND, identifyCommand(strdup("depende;")));
	CuAssertIntEquals(cutest, BAD_COMMAND, identifyCommand(strdup("depende 10")));
	CuAssertIntEquals(cutest, BAD_COMMAND, identifyCommand(strdup("vetea")));
	CuAssertIntEquals(cutest, BAD_COMMAND, identifyCommand(strdup("vetea10;")));
	
}

CuSuite* loadCommandIdentifierSuit(){
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, command_with_no_args);
	SUITE_ADD_TEST(suite, command_with_args_in_brackets);
	SUITE_ADD_TEST(suite, command_with_args_separated_by_a_space);
	SUITE_ADD_TEST(suite, command_with_args_joined_at_the_end);
	SUITE_ADD_TEST(suite, malformed_commands);
	return suite;
}