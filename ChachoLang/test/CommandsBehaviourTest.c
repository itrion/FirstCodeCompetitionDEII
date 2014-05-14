#include "../CuTest/CuTest.h"
#include "../Memory.h"
#include "../Commands.h"
#include <string.h>

void buenas_initializes_the_memory(CuTest* cutest){
	ChachoLangMemory memory;
	buenas(&memory, strdup("buenas;"));
	CuAssertIntEquals(cutest, 0, memory.currentPosition);
	CuAssertIntEquals(cutest, 30000, memory.size);
	venga(&memory, strdup("venga!;"));
}

void palante_moves_pointer_forward(CuTest* cutest){
	ChachoLangMemory memory;
	buenas(&memory, strdup("buenas;"));
	for(int i = 0; i < 250; ++i){
		palante(&memory, strdup("palante;"));
	}
	CuAssertIntEquals(cutest, 250, memory.currentPosition);
	venga(&memory, strdup("venga!;"));
}

void patras_moves_pointer_backward(CuTest* cutest){
	ChachoLangMemory memory;
	buenas(&memory, strdup("buenas;"));
	palante(&memory, strdup("palante;"));palante(&memory, strdup("palante;"));palante(&memory, strdup("palante;"));
	patras(&memory, strdup("patras;"));
	CuAssertIntEquals(cutest, 2, memory.currentPosition);
	venga(&memory, strdup("venga!;"));
}

void aumenta_increases_the_content_of_memory_at_that_position(CuTest* cutest){
	ChachoLangMemory memory;
	buenas(&memory, strdup("buenas;"));
	CuAssertIntEquals(cutest, 0, memory.memory[memory.currentPosition]);
	aumenta(&memory, strdup("aumenta10;"));
	CuAssertIntEquals(cutest, 10, memory.memory[memory.currentPosition]);
	venga(&memory, strdup("venga!;"));
}

void quita_drecreases_the_content_of_memory_at_that_position(CuTest* cutest){
	ChachoLangMemory memory;
	buenas(&memory, strdup("buenas;"));
	aumenta(&memory, strdup("aumenta10;"));
	CuAssertIntEquals(cutest, 10, memory.memory[memory.currentPosition]);
	quita(&memory, strdup("quita8;"));
	CuAssertIntEquals(cutest, 2, memory.memory[memory.currentPosition]);
	venga(&memory, strdup("venga!;"));
}

void vetea_moves_pointer_to_desired_position(CuTest* cutest){
	ChachoLangMemory memory;
	buenas(&memory, strdup("buenas;"));
	vetea(&memory, strdup("vetea10;"));
	CuAssertIntEquals(cutest, 10, memory.currentPosition);
	venga(&memory, strdup("venga!;"));
}

void depende_returns_true_if_current_value_equals_to_value_passed(CuTest* cutest){
	ChachoLangMemory memory;
	buenas(&memory, strdup("buenas;"));
	aumenta(&memory, strdup("aumenta10;"));
	CuAssertTrue(cutest, depende(&memory, strdup("depende 10;")));
	venga(&memory, strdup("venga!;"));
}

CuSuite* loadCommandsBehaviourSuite(){
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, buenas_initializes_the_memory);
	SUITE_ADD_TEST(suite, palante_moves_pointer_forward);
	SUITE_ADD_TEST(suite, patras_moves_pointer_backward);
	SUITE_ADD_TEST(suite, aumenta_increases_the_content_of_memory_at_that_position);
	SUITE_ADD_TEST(suite, quita_drecreases_the_content_of_memory_at_that_position);
	SUITE_ADD_TEST(suite, vetea_moves_pointer_to_desired_position);
	SUITE_ADD_TEST(suite, depende_returns_true_if_current_value_equals_to_value_passed);
	return suite;
}
