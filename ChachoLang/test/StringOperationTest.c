#include "../CuTest/CuTest.h"
#include "../ProgramSplitter.h"
#include <string.h>

void slice_of_strings(CuTest* cutest){
	char* aumenta = strdup("aumenta111;");
	char* imprimio = strdup("imprimio(20);");
	char* quita = strdup("quita13;");
	char* vetea = strdup("vetea118;");
	CuAssertStrEquals(cutest, "111", slice(aumenta, 7, strlen(aumenta) - 1));
	CuAssertStrEquals(cutest, "20", slice(imprimio, 9, strlen(imprimio) - 2));
	CuAssertStrEquals(cutest, "13", slice(quita, 5, strlen(quita) - 1));
	CuAssertStrEquals(cutest, "118", slice(vetea, 5, strlen(vetea) - 1));
}

void converting_to_char(CuTest* cutest){
	CuAssertTrue(cutest, 1 ==	convertToInteger("1"));
	CuAssertTrue(cutest, 11 == convertToInteger("11"));
	CuAssertTrue(cutest, 201 == convertToInteger("201"));
	CuAssertTrue(cutest, 254 == convertToInteger("254"));
}

CuSuite* loadStringsOperationsSuit(){
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, slice_of_strings);
	SUITE_ADD_TEST(suite, converting_to_char);
	return suite;
}