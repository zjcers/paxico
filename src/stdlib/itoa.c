/*
 * src/stdlib/itoa.c
 * Copyright 2016 Zane J Cersovsky
 * Defines itoa(), which isn't standard
 */
#include <stdint.h>
#define TOASCII(i) (i < 10) ? (i+48) \
	: (i-10+97)
static void reverse(char *str, int len)
{
	size_t i;
	char tmp;
	for (i = 0; i < len/2; i++) {
		tmp = str[len-i];
		str[len-i] = str[i];
		str[i] = tmp;
	}
}
char* itoa(int value, char *str, int base)
{
	if (value == 0) {
		str[0] = '0';
		str[1] = 0;
		return str;
	}
	size_t i = 0;
	char *tstr = str;
	if (value < 0) {
		value *= -1;
		str[0] = '-';
		tstr++;
	}
	while (value > 0) {
		tstr[i] = TOASCII(value % base);
		value = value/base;
		i++;
	}
	tstr[i] = 0;
	reverse(tstr, i-1);
	return str;
}
