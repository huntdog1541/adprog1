#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lex.h"


struct lex {
  char fileName[256];
  char * content;
  char * output;
  int contentNumber;
  int lineNumber;
  int posNumber;
  long size;
  int finished;
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
  lx->output = (char *)calloc(1, (sizeof(char)) * (lx->size));
  readFile(lx, fin);
  lx->contentNumber = 0;
  lx->lineNumber = 0;
  lx->posNumber = 0;
  lx->finished = 0;
  fclose(fin);
  printContent(lx);
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
  free(lx->output);
  free(lx);
}

void printContent(struct lex * lx)
{
  int i = 0;
  printf("=================PRINT CONTENT=====================\n");
  for(i =0; i < lx->size; i++)
  {
    printf("%c", lx->content[i]);
  }
  printf("\n");
  printf("===================================================\n");
}

void startLex(struct lex * lx)
{
  char temp[256];
  while(lx->finished != 1)
  {
    strcpy(temp, tokenier(lx));
    printValue(temp);
  }
}


char * tokenier(struct lex * lx)
{
  char temp = lx->content[contentNumber];
  if(isalnum(temp))
    isId(temp);
}

void printValue(char * str)
{
  printf("Value is Ni\n");
}
