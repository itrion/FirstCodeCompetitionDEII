#!/bin/bash

clear

if [ -f "AllTests" ];
then
	rm AllTests
fi;

gcc -o AllTests \
	CUtest/CuTest.c \
	test/AllTest.c \
	test/ChachoLangInterpreterTest.c \
	test/CommandIdentifierTest.c \
	test/CommandsBehaviourTest.c \
	ChachoLangInterpreter.c \
	CommandIdentifier.c

time ./AllTests