/*
 * src/stdio/printf.c
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
 * Defines printf()
 */
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "libc.h"
/*
 * These are used to make a linked list of string fragments that get stuck
 * together to form the final string.
 * format_length is the number of bytes used by the original format specifier.
 * This value is NULL if str is just a pointer into format
 */
struct printf_node {
	const char* str;
	char* dynstr;
	size_t length;
	size_t format_length;
	struct printf_node *next;
};

/*
 * Private helper function that appends a new node containing a copy of the
 * given string of the given length.
 * This function is also responsible for the setup of the linked list

static void a_list(struct printf_node **base, struct printf_node **current, char* str, size_t length)
{
	struct printf_node *new_node = (struct printf_node*)malloc(sizeof(struct printf_node));
	new_node->str = str;
	new_node->length = length;
	new_node->next = NULL;
	if (*base) {
		if (*current)
			(*current)->next = new_node;
		else
			(*base)->next = new_node;
		(*current) = new_node;
	} else {
		(*base) = new_node;
	}
} */
/*
 * Private helper that walks the linked list and assembles it into the given
 * string pointer.
 * This function is also responsible for free'ing the nodes of the linked list.
 * DON'T CALL THIS CONTRAPTION TWICE
 */
static void assemble_str(struct printf_node* cur, char *str)
{
	struct printf_node* old = NULL;
	while (cur) {
		old = cur;
		if (cur->dynstr) {
			memcpy(str, cur->dynstr, cur->length);
			free(cur->dynstr);
		} else {
			memcpy(str, cur->str, cur->length);
		}
		str += cur->length;
		cur = cur->next;
		free(old);
	}
	*(str++) = 0;
}
struct printf_node* process_format(const char* format)
{
	struct printf_node *node = (struct printf_node*)malloc(sizeof(struct printf_node));
	node->format_length = 1;
	node->length = 0;
	node->dynstr = NULL;
	for (;;) {
		format++;
		node->format_length += 1;
		switch(*format) {
		case '%':
			node->dynstr = (char*)malloc(1);
			*(node->dynstr) = '%';
			node->length = 1;
			goto process_end;
			break;
		case 0:
			goto process_end;
			break;
		default:
			goto process_end;
			break;
		}
	}
	process_end:
		node->str = NULL;
		node->next = NULL;
		return node;
}
struct printf_node* process_string(const char* format)
{
	struct printf_node *node = (struct printf_node*)malloc(sizeof(struct printf_node));
	char* next = strchr(format, '%');
	node->str = format;
	if (next)
		node->length = next-format;
	else
		node->length = strlen(format);
	node->dynstr = NULL;
	node->format_length = 0;
	node->next = NULL;
	return node;
}
int printf(const char *format, ...)
{
	struct printf_node base;
	struct printf_node *current;
	current = &base;
	base.next = NULL;
	size_t processed = 0;
	for (;;) {
		switch (*format) {
		case '%':
			if ((current->next = process_format(format)))
				format += current->next->format_length;
			else
				goto format_end;
			break;
		case 0:
			goto format_end;
			break;
		default:
			current->next = process_string(format);
			format += current->next->length;
			break;
		}
		current = current->next;
		processed += current->length;
	}
	format_end:
		processed++;
		char* final = (char*)malloc(processed);
		assemble_str(base.next, final);
		write(STDOUT_FILENO, final, processed);
		free(final);
		return processed;
}
