// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "pit_TouchOut.h"
#include "pit_ERROR.h"
int main()
{
	//mouseClickAt(0.01f, 0.99f);
	int check = touchClickAt(0.5f, 0.5f);
	if (check) {
		printf("Failed to generate click do to : %s.\n", ErrorType(check));
	}
	//find awc
	//init awc
	//while true
	//get input from awc
	//get intrupt input
	//generate mouse/touch ouput based on step.
	return 0;
}

