/*
 * src/stdio/puts.c
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
 * Defines puts() and putchar()
 */
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int puts(const char* str) {
	/*Declare variables*/
	size_t length;
	/*End declare variables
		Get the length of the given string */
	length = strlen(str);
	/*The rest is just a wrapper around a system call*/
	return write(STDOUT_FILENO, str, length);

}
int putchar(int str) {
	/*Declare variables*/
	char c;
	int ret;
	/*End declare variables
		Cast the given character to a uint8_t*/
	c = (uint8_t) str;
	/*Execute system call, see write(2)*/
	ret = write(STDOUT_FILENO, &c, 1);
	/*If the write failed return EOF, else return str*/
	ret = (ret == -1) ? EOF : str;
	return ret;
}
