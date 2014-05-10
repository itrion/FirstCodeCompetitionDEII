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
	CuAssertTrue(cutest, 0);
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

CuSuite* loadCommandIdentifierSuit(){
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, command_with_no_args);
	SUITE_ADD_TEST(suite, command_with_args_in_brackets);
	SUITE_ADD_TEST(suite, command_with_args_joined_at_the_end);
	return suite;
}