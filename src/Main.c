/*
* Main.c
*/
#include <stdio.h>
#include "parse.h"
#include "global.h"
#include "symbol.h"
#include "lex.h"
#include "error.h"


int main(int argc, char ** argv)
{
	init();
	printSymbol();
	struct lex * lx = initLex("test.txt");
	parse();
	printf("lex\n");
	destLex(lx);
	return 0;
}
//New Edit
