#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lex.h"


struct lex {
  char fileName[256];
  char * content;
  int lineNumber;
  int posNumber;
  long size;
};

struct lex * initLex(char * file)
{
  struct lex * lx;
  lx = (struct lex*)malloc((sizeof(struct lex)));
  strcpy(lx->fileName, file);
  FILE * fin = fopen(lx->fileName, "r");
  fseek(fin, 0, SEEK_END);
  lx->size = ftell(fin);
  fseek(fin, 0, SEEK_SET);
  lx->content = (char *)malloc(sizeof(char) * (lx->size));
  lx->lineNumber = 0;
  lx->posNumber = 0;
  return lx;
}

void destLex(struct lex * lx)
{
  free(lx->content);
  free(lx);
}
