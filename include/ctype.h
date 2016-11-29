#ifndef _PAXICO_CTYPE_H
#define _PAXICO_CTYPE_H
/*Various functions to test if a given character belongs in
 a set*/
int isalnum(int c);
int isalpha(int c);
int iscntrl(int c);
int isdigit(int c);
int isgraph(int c);
int islower(int c);
int isprint(int c);
int ispunct(int c);
int isspace(int c);
int isupper(int c);
int isxdigit(int c);

int isascii(int c);
int isblank(int c);
#endif
