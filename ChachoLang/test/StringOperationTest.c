#include "../CuTest/CuTest.h"
#include "../ProgramSplitter.h"
#include <string.h>

void slice_of_strings(CuTest* cutest){
	char* aumenta = strdup("aumenta111;");
	char* imprimio = strdup("imprimio(20);");
	CuAssertStrEquals(cutest, "111", slice(aumenta, 7, strlen(aumenta) - 1));
	CuAssertStrEquals(cutest, "20", slice(imprimio, 9, strlen(imprimio) - 2));
}

void converting_to_integer(CuTest* cutest){
	CuAssertIntEquals(cutest, 1, convertToInteger("1"));
	CuAssertIntEquals(cutest, 11, convertToInteger("11"));
	CuAssertIntEquals(cutest, 201, convertToInteger("201"));
	CuAssertIntEquals(cutest, 255, convertToInteger("255"));
}

CuSuite* loadStringsOperationsSuit(){
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, slice_of_strings);
	SUITE_ADD_TEST(suite, converting_to_integer);
	return suite;
}