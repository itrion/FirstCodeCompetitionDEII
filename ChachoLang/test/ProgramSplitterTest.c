#include "../CuTest/CuTest.h"
#include "../ProgramSplitter.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void empty_program(CuTest* cutest){
	char* program = strdup("\0");
	char** commands = splitIntoCommands(program);
	CuAssertIntEquals(cutest, 0, countLines(program));
	CuAssertPtrEquals(cutest, NULL, commands);
	free(program);
}

void program_with_one_line(CuTest* cutest){
	char* program = strdup("buenas;");
	CuAssertIntEquals(cutest, 0, countLines(program));
	char** commands = splitIntoCommands(program);
	CuAssertStrEquals(cutest, "buenas;", *(commands));
	free(program);
	free(commands);
}

void program_with_several_lines(CuTest* cutest){
	char* program = strdup("buenas;\naumenta20;\naumenta20;\naumenta20;\naumenta20;\naumenta20;\naumenta180;\nvenga!;");
	CuAssertIntEquals(cutest, 7, countLines(program));
	char** commands = splitIntoCommands(program);
	CuAssertStrEquals(cutest, "buenas;", *(commands));
	CuAssertStrEquals(cutest, "aumenta20;", *(commands + 1));
	CuAssertStrEquals(cutest, "aumenta20;", *(commands + 2));
	CuAssertStrEquals(cutest, "aumenta20;", *(commands + 3));
	CuAssertStrEquals(cutest, "aumenta20;", *(commands + 4));
	CuAssertStrEquals(cutest, "aumenta20;", *(commands + 5));
	CuAssertStrEquals(cutest, "aumenta180;", *(commands + 6));
	CuAssertStrEquals(cutest, "venga!;", *(commands + 7));
	free(program);
	free(commands);
}
void program_with_spaces_between_commands(CuTest* cutest){
	char* program = strdup("	buenas;\n  aumenta20;     \n 		aumenta20;\n  aumenta20;	\n 		aumenta20; \naumenta20; \n aumenta180;	\nvenga!; 	");
	CuAssertIntEquals(cutest, 7, countLines(program));
	char** commands = splitIntoCommands(program);
	CuAssertStrEquals(cutest, "buenas;", *(commands));
	CuAssertStrEquals(cutest, "aumenta20;", *(commands + 1));
	CuAssertStrEquals(cutest, "aumenta20;", *(commands + 2));
	CuAssertStrEquals(cutest, "aumenta20;", *(commands + 3));
	CuAssertStrEquals(cutest, "aumenta20;", *(commands + 4));
	CuAssertStrEquals(cutest, "aumenta20;", *(commands + 5));
	CuAssertStrEquals(cutest, "aumenta180;", *(commands + 6));
	CuAssertStrEquals(cutest, "venga!;", *(commands + 7));
	free(program);
	free(commands);
}

void long_program(CuTest* cutest){
	char* program = strdup("buenas;\naumenta72;\npalante;\naumenta111;\npalante;\naumenta108;\npalante;\naumenta97;\npalante;\naumenta32;\npalante;\naumenta77;\npalante;\naumenta117;\npalante;\naumenta110;\npalante;\naumenta100;\npalante;\naumenta111;\npalante;\nvetea0;\nvoyarepetirme 10 veces;\nimprimio();\npalante;\nmaburri;\nvenga!;");
	CuAssertIntEquals(cutest, 26, countLines(program));
}

CuSuite* loadProgramSplitterSuit(){
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, empty_program);
	SUITE_ADD_TEST(suite, program_with_one_line);
	SUITE_ADD_TEST(suite, program_with_several_lines);
	SUITE_ADD_TEST(suite, program_with_spaces_between_commands);
	SUITE_ADD_TEST(suite, long_program);
	return suite;
}
