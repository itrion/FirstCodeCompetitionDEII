#!/bin/bash

clear

if [ -f "AllTests" ];
then
	rm AllTests
fi;

gcc -o AllTests \
	CUtest/CuTest.c \
	CommandIdentifier.c \
	ChachoLangInterpreter.c \
	Commands.c \
	ProgramSplitter.c \
	test/AllTest.c \
	test/ChachoLangInterpreterTest.c \
	test/CommandIdentifierTest.c \
	test/CommandsBehaviourTest.c
	test/ProgramSplitterTest.c

time ./AllTests