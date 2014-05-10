#!/bin/bash

clear

gcc -o AllTests \
	CUtest/CuTest.c \
	test/AllTest.c \
	test/StringUtilitiesTest.c \
	StringUtilities.c

./AllTests