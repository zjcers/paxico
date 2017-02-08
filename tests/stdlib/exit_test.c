/*
 * tests/stdlib/exit_test.c
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
 * Tests exit() and atexit()
 */
#include <stdlib.h>
#include <stdio.h>
int i;
void printmsg()
{
	puts("Hello World!\n");
}
void increment()
{
	i++;
	puts("hello\n");
}
void printi()
{
	char buf[256];
	itoa(i, buf, 10);
	puts(buf);
	putchar('\n');
}
int main(int argc, const char** argv)
{
	if (argc == 2) {
		i = 0;
		switch(argv[1][0]) {
		case '1':
			atexit(&printmsg);
			exit(0);
			break;
		case '2':
			for (int j=0; j<10; j++)
				atexit(&increment);
			atexit(&printi);
			exit(0);
			break;
		default:
			exit(0);
			break;
		}
	}
	return 1;
}
