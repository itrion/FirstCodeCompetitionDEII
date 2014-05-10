#include "../CUtest/CuTest.h"
#include "stdio.h"

CuSuite* StrUtilGetSuite();

void RunAllTests(){
	CuString* output = CuStringNew();
	CuSuite* stringUtilitiesSuite = CuSuiteNew();
	CuSuiteAddSuite(stringUtilitiesSuite, StrUtilGetSuite());
	CuSuiteRun(stringUtilitiesSuite);
	CuSuiteSummary(stringUtilitiesSuite, output);
	CuSuiteDetails(stringUtilitiesSuite, output);
	printf("%s\n", output->buffer);
}

int main(void) {
	RunAllTests();
}
