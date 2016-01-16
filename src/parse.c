#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "symbol.h"
#include "parse.h"

int parse()
{
	FILE * fin = fopen("test.txt", "r");
	char temp = getc(fin);
	char str[256];
	int i = 0;
	str[i] = temp;
 	while(temp != EOF)
	{
 	str[i] = temp;
	printf("%c", temp);
	temp = getc(fin);
	i++;
	}
	//str[++i] = '\0';
	int k = lookup(str);
	printf("The word has a value of %d\n", k);
	//Strascii(str);
	trimString(str);
	k = lookup(str);
	k = getTokenType(k);
	printf("The word has a value of %d\n", k);
	fclose(fin);
	return k;
}

void Strascii(char * str)
{
	int i =0;
	int length = strlen(str);
	for(i = 0; i < length; i++)
	{
		printf("The character %c is %d\n", str[i], str[i]);
	}
}

char * trimString(char * str)
{
	int i = 0, j = 0, length = 0;
	length = strlen(str);
	char temp[length];
	while(isalnum(str[i]))
	{
		temp[j] = str[i];
		i++;j++;
	}
	temp[j] = 0;
	Strascii(temp);
	strcpy(str, temp);
	return str;
}
