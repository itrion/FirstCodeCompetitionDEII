#include "../CuTest/CuTest.h"
#include "../ChachoLangInterpreter.h"
#include "string.h"

void all_statements_ends_in_semicolon(CuTest* cutest){
	CuAssertIntEquals(cutest, -1, execute(strdp("buenas\nleeaqui fich\nvenga!")));
}

void programm_should_start_with_buenas(CuTest* cutest){
	CuAssertIntEquals(cutest, -1, execute("palante;\nvenga!;"));
	CuAssertIntEquals(cutest, -1, execute("imprimio();\nvenga!;"));
	CuAssertIntEquals(cutest, -1, execute("buenas;\npalante;\nvenga!;"));
}

void programm_should_end_with_venga(CuTest* cutest){
	CuAssertTrue(cutest, 0);
}

CuSuite* loadChachoLangInterpreterSuit(){
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, all_statements_ends_in_semicolon);
	SUITE_ADD_TEST(suite, programm_should_start_with_buenas);
	SUITE_ADD_TEST(suite, programm_should_end_with_venga);
	return suite;
}