CuSuite* loadProgramSplitterSuit(){
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, empty_program);
	SUITE_ADD_TEST(suite, program_with_one_line);
	SUITE_ADD_TEST(suite, program_with_several_lines);
	SUITE_ADD_TEST(suite, program_with_espaces_between_commands);
	return suite;
}