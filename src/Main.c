/*
* Main.c
*/
#include <stdio.h>
#include "parse.h"
#include "global.h"
#include "symbol.h"


int main(int argc, char ** argv)
{
	init();
	printSymbol();
	parse();
}
//Here
