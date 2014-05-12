#include "../CuTest/CuTest.h"
#include "../Memory.h"
#include "../Commands.h"

void buenas_initializes_the_memory(CuTest* cutest){
	ChachoLangMemory memory;
	buenas(&memory);
	CuAssertIntEquals(cutest, 0, memory.currentPosition);
	CuAssertIntEquals(cutest, 30000, memory.size);
	venga(&memory);
}

void palante_moves_pointer_forward(CuTest* cutest){
	ChachoLangMemory memory;
	buenas(&memory);
	for (int i = 0; i < 250; ++i){
		palante(&memory);
	}
	CuAssertIntEquals(cutest, 250, memory.currentPosition);
	venga(&memory);
}

void patras_moves_pointer_backward(CuTest* cutest){
	ChachoLangMemory memory;
	buenas(&memory);
	palante(&memory); palante(&memory); palante(&memory);
	patras(&memory);
	CuAssertIntEquals(cutest, 2, memory.currentPosition);
	venga(&memory);
}

void aumenta_moves_pointer_n_positions_forward(CuTest* cutest){
	ChachoLangMemory memory;
	buenas(&memory);
	aumenta(&memory, 10);
	CuAssertIntEquals(cutest, 10, memory.currentPosition);
	aumenta(&memory, 10);
	CuAssertIntEquals(cutest, 20, memory.currentPosition);
	aumenta(&memory, 111);
	CuAssertIntEquals(cutest, 131, memory.currentPosition);
	venga(&memory);
}

void quita_moves_pointer_n_positions_backward(CuTest* cutest){
	ChachoLangMemory memory;
	buenas(&memory);
	aumenta(&memory, 111);
	quita(&memory, 111);
	CuAssertIntEquals(cutest, 0, memory.currentPosition);
	venga(&memory);
}

void vetea_moves_pointer_to_desired_position(CuTest* cutest){
	ChachoLangMemory memory;
	buenas(&memory);
	vetea(&memory, 10);
	CuAssertIntEquals(cutest, 10, memory.currentPosition);
	venga(&memory);
}

CuSuite* loadCommandsBehaviourSuite(){
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, buenas_initializes_the_memory);
	SUITE_ADD_TEST(suite, palante_moves_pointer_forward);
	SUITE_ADD_TEST(suite, patras_moves_pointer_backward);
	SUITE_ADD_TEST(suite, aumenta_moves_pointer_n_positions_forward);
	SUITE_ADD_TEST(suite, quita_moves_pointer_n_positions_backward);
	SUITE_ADD_TEST(suite, vetea_moves_pointer_to_desired_position);
	return suite;
}