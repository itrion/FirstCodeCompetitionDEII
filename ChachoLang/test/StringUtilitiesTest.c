#include "../CUtest/CuTest.h"
#include "../StringUtilities.h"
#include "stdio.h"
#include "string.h"

void TestStrToUpper(CuTest* cutest){
	char* input = strdup("hello world");
	char* actual = StrToUpper(input);
	char* expected = "HELLO WORLD";
	CuAssertStrEquals(cutest, expected, actual);
}

CuSuite* StrUtilGetSuite() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, TestStrToUpper);
	return suite;
}