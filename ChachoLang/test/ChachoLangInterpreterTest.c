#include "../CuTest/CuTest.h"
#include "../ChachoLangInterpreter.h"
#include "string.h"

void all_statements_ends_in_semicolon(CuTest* cutest){
	CuAssertIntEquals(cutest, -1, execute(strdup("buenas\nleeaqui fich\nvenga!")));
	CuAssertIntEquals(cutest, -1, execute(strdup("buenas\npalante;\nvenga!;")));
	CuAssertIntEquals(cutest, -1, execute(strdup("buenas;\npalante\nvenga!")));
	CuAssertIntEquals(cutest, -1, execute(strdup("buenas;\npalante;\nvenga!")));
}

void programm_should_start_with_buenas(CuTest* cutest){
	CuAssertIntEquals(cutest, -1, execute(strdup("imprimio();\nvenga!;")));
}

void programm_should_end_with_venga(CuTest* cutest){
	CuAssertIntEquals(cutest, -1, execute(strdup("buenas;\naumenta20;\nvenga;")));
}

void very_big_number(CuTest* cutest){
	CuAssertIntEquals(cutest, -1, execute(strdup("buenas;\naumenta20;\naumenta20;\naumenta20;\naumenta20;\naumenta20;\naumenta180;\nvenga!;")));
}

void malformed_exception(CuTest* cutest){
	CuAssertIntEquals(cutest, -1, execute(strdup("buenas;\nintentalo;\naumenta5;\nvenga!;")));
}

void malformed_conditional_statement(CuTest* cutest){
	CuAssertIntEquals(cutest, -1, execute(strdup("buenas;\naumenta5;\nedneped;\nvenga!;")));
}

void malformed_loop_statement(CuTest* cutest){
	CuAssertIntEquals(cutest, -1, execute(strdup("buenas;\nvoyarepetirme veces;\naumenta5;\nmaburri;\nvenga!;")));
}

void hello_world(CuTest* cutest){
	CuAssertIntEquals(cutest, 1, execute(strdup("buenas;\naumenta72;\npalante;\naumenta111;\npalante;\naumenta108;\npalante;\naumenta97;\npalante;\naumenta32;\npalante;\naumenta77;\npalante;\naumenta117;\npalante;\naumenta110;\npalante;\naumenta100;\npalante;\naumenta111;\npalante;\nvetea0;\nvoyarepetirme 10 veces;\nimprimio();\npalante;\nmaburri;\nvenga!;")));
}

void bum_bum(CuTest* cutest){
	CuAssertIntEquals(cutest, 1, execute(strdup("buenas;\nvoyarepetirme 255 veces;\npalante;\naumenta53;\nimprimio();\nquita1;\nimprimio();\nquita1;\nimprimio();\nquita1;\nimprimio();\nquita1;\nimprimio();\nquita1;\nquita48;\npalante;\naumenta66;\nimprimio();\nquita66;\naumenta85;\nimprimio();\nquita85;\naumenta77;\nimprimio();\nquita77;\npatras;\nmaburri;\nvenga!;")));
}

void bad_order(CuTest* cutest){
	CuAssertIntEquals(cutest, 1, execute(strdup("buenas;\naumenta79;\nvoyarepetirme 3 veces;\npalante;\ndepende 5;\nmaburri;\nedneped;\nvenga!;")));
}

void test_conditional(CuTest* cutest){
	CuAssertIntEquals(cutest, 1, execute(strdup("buenas;\naumenta79;\npalante;\nvoyarepetirme 105 veces;\naumenta1;\ndepende 105;\n    aumenta2;\nedneped;\nmaburri;\npatras;\nimprimio();\npalante;\nimprimio();\nvenga!;")));
}


CuSuite* loadChachoLangInterpreterSuit(){
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, all_statements_ends_in_semicolon);
	SUITE_ADD_TEST(suite, programm_should_start_with_buenas);
	SUITE_ADD_TEST(suite, programm_should_end_with_venga);
	SUITE_ADD_TEST(suite, very_big_number);
	SUITE_ADD_TEST(suite, malformed_exception);
	SUITE_ADD_TEST(suite, malformed_conditional_statement);
	SUITE_ADD_TEST(suite, malformed_loop_statement);
	SUITE_ADD_TEST(suite, hello_world);
	SUITE_ADD_TEST(suite, bum_bum);
	SUITE_ADD_TEST(suite, bad_order);
	return suite;
}