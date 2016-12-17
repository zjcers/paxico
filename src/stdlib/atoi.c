/*
 * src/stdlib/atoi.c
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
 * Defines atoi()
 */
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
/*A convenience method to shift a digit into a number*/
static int addToNumber(int prevNum, char currDigit);
inline int addToNumber(int prevNum, char currDigit) {
	/*48 is the offset between ASCII character codes and actual numbers*/
	int currNum = (int)currDigit - 48;
	return (prevNum*10)+currNum;
}
int atoi(const char* src) {
	size_t i = 0;
	int ret = 0;
	bool minus = false;
	for(; src[i] !=0; i++) {
		if (!(isspace(src[i])))
			break;
	}
	switch (src[i]) {
	case '-':
		minus = true;
	case '+':
		i++;
		break;
	}
	for(; src[i] != 0; i++) {
		switch (src[i]) {
		case '0' ... '9':
			ret = addToNumber(ret, src[i]);
			break;
		default:
			goto atoi_end;
			break;
		}
	}
	atoi_end:
		if (minus)
			return -1*ret;
		return ret;
}
