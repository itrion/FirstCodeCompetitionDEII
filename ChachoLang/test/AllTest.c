#include "../CUtest/CuTest.h"
#include "stdio.h"

CuSuite* loadChachoLangInterpreterSuit();
CuSuite* loadCommandIdentifierSuit();
CuSuite* loadCommandsBehaviourSuite();
CuSuite* loadProgramSplitterSuit();
CuSuite* loadStringsOperationsSuit();

void displayResults(char* results){
	printf("%s\n", results);
}

char* runAllTests(CuSuite* allSuites){
	CuString* output = CuStringNew();
	CuSuiteRun(allSuites);
	CuSuiteSummary(allSuites, output);
	CuSuiteDetails(allSuites, output);
	return output->buffer;
}

CuSuite* loadAllSuites(){
	CuSuite* allSuites = CuSuiteNew();
	CuSuiteAddSuite(allSuites, loadChachoLangInterpreterSuit());
	CuSuiteAddSuite(allSuites, loadCommandIdentifierSuit());
	CuSuiteAddSuite(allSuites, loadCommandsBehaviourSuite());
	CuSuiteAddSuite(allSuites, loadProgramSplitterSuit());
	CuSuiteAddSuite(allSuites, loadStringsOperationsSuit());
	return allSuites;
}

int main(void) {
	displayResults(runAllTests(loadAllSuites()));
}
