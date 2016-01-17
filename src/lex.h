
#ifndef LEX_H_
#define LEX_H_

struct lex * initLex(char * file);

void destLex(struct lex * lx);

void printContent(struct lex * lx);

char * tokenier(struct lex * lx);

void startLex(struct lex * lx);

void printValue(char * str);

#endif
