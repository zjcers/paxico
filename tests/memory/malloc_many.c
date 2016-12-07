/*
 * tests/memory/malloc_many.c
 * Copyright 2016 Zane J Cersovsky
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
