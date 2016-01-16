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
	parse();
	struct lex * lx = initLex("test.txt");
	printf("lex\n");
	destLex(lx);
	return 0;
}
//New Edit
