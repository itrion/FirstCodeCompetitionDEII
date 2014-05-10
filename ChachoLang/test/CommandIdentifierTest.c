#include "../CuTest/CuTest.h"
#include "CommandIdentifier.h"
#include "string.h"

void command_with_no_args(CuTest* cutest){
	//buenas;
	//venga!;
	//palante;
	//patras;
	//intentalo;
	//chacho!;
}

void command_with_args_in_brackets(CuTest* cutest){
	
}


CuSuite* loadCommandIdentifierSuit(){
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, foo);
	return suite;
}