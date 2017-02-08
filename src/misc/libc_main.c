/*
 * src/misc/libc_main.c
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
 * Defines the REAL main()
 */
#include <stdlib.h>
#include <stdio.h>
#include "memory.h"
FILE *stdout;
FILE *stdin;
FILE *stderr;
struct PAXICO_exit_handler_t* PAXICO_exit_handlers = NULL;
int main (int argc, char const *argv[], char const *envp[]);
void _PAXICO_libc_main(int argc, char const *argv[], char const *envp[]) {
	init_malloc();
	stdin = fdopen(STDIN_FILENO, "r");
	stderr = fdopen(STDERR_FILENO, "w");
	stdout = fdopen(STDOUT_FILENO, "w");
	exit(main(argc, argv, envp));
}
