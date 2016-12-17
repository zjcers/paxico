/*
 * src/stdlib/itoa.c
 * Copyright 2016 Zane J Cersovsky
 * This file is part of Project Paxico.

 * Project Paxico is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Project Paxico is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with Project Paxico.  If not, see <http://www.gnu.org/licenses/>.
 * 
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
