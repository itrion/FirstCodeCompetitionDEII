#include "../CuTest/CuTest.h"
#include "../CommandIdentifier.h"
#include "../Commands.h"
#include "string.h"


void command_with_no_args(CuTest* cutest){
	CuAssertIntEquals(cutest, BUENAS, identifyCommand("buenas;"));
	CuAssertIntEquals(cutest, VENGA, identifyCommand("venga!;"));
	CuAssertIntEquals(cutest, PALANTE, identifyCommand("palante;"));
	CuAssertIntEquals(cutest, PATRAS, identifyCommand("patras;"));
	CuAssertIntEquals(cutest, INTENTALO, identifyCommand("intentalo;"));
	CuAssertIntEquals(cutest, CHACHO, identifyCommand("chacho!;"));
}

void command_with_args_in_brackets(CuTest* cutest){
	CuAssertTrue(cutest, 1);
}

void command_with_args_joined_at_the_end(CuTest* cutest){
	CuAssertTrue(cutest, 1);
}

CuSuite* loadCommandIdentifierSuit(){
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, command_with_no_args);
	SUITE_ADD_TEST(suite, command_with_args_in_brackets);
	SUITE_ADD_TEST(suite, command_with_args_joined_at_the_end);
	return suite;
}