#include "../CuTest/CuTest.h"
#include "../ChachoLangInterpreter.h"
#include "string.h"

void all_statements_ends_in_semicolon(CuTest* cutest){
	CuAssertStrEquals(cutest, "-1", execute("buenas\npalante\nvenga!"));
	CuAssertStrEquals(cutest, "-1", execute("buenas\npalante;\nvenga!;"));
	CuAssertStrEquals(cutest, "-1", execute("buenas;\npalante;\nvenga!"));
	CuAssertStrEquals(cutest, "-1", execute("buenas;\npalante\nvenga!;"));
	CuAssertStrEquals(cutest, "", execute("buenas;\npalante;\nvenga!;"));
}

void programm_should_start_with_buenas(CuTest* cutest){
	CuAssertStrEquals(cutest, "-1", execute("palante;\nvenga!;"));
	CuAssertStrEquals(cutest, "-1", execute("imprimio();\nvenga!;"));
	CuAssertStrEquals(cutest, "-1", execute("buenas;\npalante;\nvenga!;"));
}

void programm_should_end_with_venga(CuTest* cutest){
	CuAssertTrue(cutest, 1);
}

CuSuite* loadChachoLangInterpreterSuit(){
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, all_statements_ends_in_semicolon);
	SUITE_ADD_TEST(suite, programm_should_start_with_buenas);
	SUITE_ADD_TEST(suite, programm_should_end_with_venga);
	return suite;
}