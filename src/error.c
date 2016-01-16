#include "global.h"
#include "error.h"

void error(char * m)
{
  fprintf(stderr, "line %d: %s\n", lineno, m);
  exit(1);
}
