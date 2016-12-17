/*
 * tests/math/malloc_many.c
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
 * This program checks if malloc behaves correctly given a bunch of allocations
 */
#include <stdlib.h>
struct node {
	struct node *next;
};
int main()
{
	struct node base;
	struct node *cur;
	cur = &base;
	int i = 0;
	for (; i < 200; i++) {
		cur->next = (struct node*)malloc(sizeof(struct node));
		cur = cur->next;
	}
	cur = &base;
	i = 0;
	while (cur) {
		cur = cur->next;
		i++;
	}
	return !(i == 201);
}
