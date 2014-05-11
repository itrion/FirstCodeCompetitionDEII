#include "../CuTest/CuTest.h"
#include "../Memory.h"
#include "../Commands.h"

void buenas_initializes_the_memory(CuTest* cutest){
	ChachoLangMemory* memory;
	buenas(memory);
	CuAssertIntEquals(cutest, 0, memory.initialPosition);
	CuAssertIntEquals(cutest, 30000, memory.size);
}

CuSuite* loadCommandsBehaviourSuite(){
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, buenas_initializes_the_memory);
	return suite;
}