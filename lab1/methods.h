#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int letter(char c);
int number(char c);
int cat_identifier(char s[]);
int cat_singleChar(char c);
int cat_doubleChar_first(char c);
int cat_doubleChar(int sign, char c);
void write_doubleChar(int sign, FILE* fw);
int analyzer(FILE* fp, FILE* fw);