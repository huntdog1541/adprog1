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
  lx = (struct lex*)calloc(1, (sizeof(struct lex)));
  strcpy(lx->fileName, file);
  FILE * fin = fopen(lx->fileName, "r");
  fseek(fin, 0, SEEK_END);
  lx->size = ftell(fin);
  fseek(fin, 0, SEEK_SET);
  lx->content = (char *)calloc(1, (sizeof(char)) * (lx->size));
  readFile(lx, fin);
  lx->lineNumber = 0;
  lx->posNumber = 0;
  fclose(fin);
  return lx;
}

void readFile(struct lex * lx, FILE * fin)
{
  size_t result;
  result = fread(lx->content, 1, lx->size, fin);
  if(result != lx->size)
  {
    fprintf(stderr, "Reading Error\n");
    exit(3);
  }
}

void destLex(struct lex * lx)
{
  free(lx->content);
  free(lx);
}
