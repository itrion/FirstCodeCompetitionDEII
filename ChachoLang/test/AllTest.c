#include "../CUtest/CuTest.h"
#include "stdio.h"

CuSuite* loadChachoLangInterpreterSuit();
CuSuite* loadCommandIdentifierSuit();

void displayResults(char* results){
	printf("%s\n", results);
}

char* runAllTests(CuSuite* allSuites){
	CuString* output = CuStringNew();
	CuSuiteRun(allSuites);
	CuSuiteDetails(allSuites, output);
	return output->buffer;
}

CuSuite* loadAllSuites(){
	CuSuite* allSuites = CuSuiteNew();
	CuSuiteAddSuite(allSuites, loadChachoLangInterpreterSuit());
	CuSuiteAddSuite(allSuites, loadCommandIdentifierSuit());
	return allSuites;
}

int main(void) {
	displayResults(runAllTests(loadAllSuites()));
}
