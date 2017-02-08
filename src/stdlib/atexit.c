/*
 * src/stdlib/atexit.c
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
 * Defines atexit()
 */
#include <stdlib.h>
#include "libc.h"
int atexit(void (*func)(void))
{
	struct PAXICO_exit_handler_t* base = PAXICO_exit_handlers;
	if (PAXICO_exit_handlers == NULL) {
		PAXICO_exit_handlers = (struct PAXICO_exit_handler_t*)malloc(sizeof(struct PAXICO_exit_handler_t));
		base = PAXICO_exit_handlers;
		goto atexit_end;
	}
	while (base->next != NULL)
		base = base->next;
	base->next = (struct PAXICO_exit_handler_t*)malloc(sizeof(struct PAXICO_exit_handler_t));
	base = base->next;
	atexit_end:
		base->next = NULL;
		base->func = func;
		return 0;
}
