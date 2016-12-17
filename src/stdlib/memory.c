/*
 * src/stdlib/memory.c
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
 * Defines malloc() and friends
 */
#include <stdint.h>
#include <memory.h>
#include <unistd.h>
/*Linked list node*/
typedef struct malloc_node {
	struct malloc_node *next;
	unsigned int length;
	void* data;
} malloc_node_t;
static malloc_node_t *base_node;
/*
 * Forward declarations for functions private to this file
 */
static void* getOriginalBreak();
static malloc_node_t* getEndNode();
static malloc_node_t* findHoleInList(size_t n);
static malloc_node_t* findHoleAfterList(size_t n);
static void addAfter(malloc_node_t* front);
static void delAfter(malloc_node_t* front);
size_t getFreeSpace();
#define BLOCK_SIZE 4096
/*
 * The following function must be called only once from the libc_main()
 * The call to getOriginalBreak() saves the original program break before it
 * gets modified by anything
 */
void init_malloc()
{
	getOriginalBreak();
	base_node = NULL;
}
/*
 * This function returns a pointer to the last node currently in the list
 */
static malloc_node_t* getEndNode()
{
	malloc_node_t* curNode = base_node;
	if (base_node == NULL)
		return NULL;
	while (curNode->next != NULL)
		curNode = curNode->next;
	return curNode;
}
/*
 * This function must not be called when base_node is the only node in the list
 * Everything will get borked if base_node is the only element
 */
static malloc_node_t* findHoleInList(size_t n)
{
	malloc_node_t* curNode = base_node;
	if (base_node == NULL)
		return NULL;
	while(curNode->next != NULL) {
		if ((size_t)curNode->next-((size_t)curNode+sizeof(curNode)+curNode->length) >= n+sizeof(malloc_node_t))
			return curNode;
		curNode = curNode->next;
	}
	return NULL;
}
/*
 *
 */
static inline malloc_node_t* findHoleAfterList(size_t n)
{
	malloc_node_t *end = getEndNode();
	size_t total = n+sizeof(malloc_node_t);
	if (end)
		if (((size_t)sbrk(NULL)-((size_t)end+(end->length)+sizeof(malloc_node_t))) >= total)
			return end;
	end = (malloc_node_t*)sbrk(NULL);
	sbrk((((total-1)/BLOCK_SIZE)+1)*BLOCK_SIZE);
	return end;
}
/*
 * addAfter only works when front != base_node
 * this should only be called with a value obtained from findHoleInList
 */
static void addAfter(malloc_node_t* front)
{
	malloc_node_t *next = (malloc_node_t*)(((void*)front)+sizeof(malloc_node_t)+front->length);
	next->next = front->next;
	front->next = next;
	next->data = next+sizeof(next);
}
/*
 * You can call this any time you want. It [shouldn't] segfault
 */
static void delAfter(malloc_node_t* front)
{
	if (front->next != NULL)
		front->next = front->next->next;
}
/*
 * WHO WANTS A SEGFAULT? I DO!
 * malloc is defined to return NULL when given n = 0
 *
 */
void* malloc(size_t n)
{
	if (n == 0)
		return (NULL);
	malloc_node_t* place;
	/*
	 * Case 1: No nodes yet allocated
	 */
/*
	if (base_node == NULL) {
		sbrk((((total-1)/16384)+1)*16384);
		place = (malloc_node_t*)getOriginalBreak();
		base_node = place;
		place->data = getOriginalBreak() + sizeof(malloc_node_t);
		goto malloc_out;
	}
*/
	/*
	 * Case 2: Nodes allocated already
	 */
	if ((place = findHoleInList(n)) == NULL) {
		/*
		 * Case 3: No empty places inside of the list, put it at the end
		 */
		if ((place = findHoleAfterList(n)) == NULL)
			return NULL;
	}
	addAfter(place);
	place = place->next;
	place->length = n;
	return place->data;
}
void free(void *addr)
{
	malloc_node_t *lastNode = base_node;
	malloc_node_t *curNode = base_node;
	while (curNode != NULL) {
		if (curNode->data == addr) {
			if (curNode == base_node)
				base_node = NULL;
			else
				delAfter(lastNode);
			if (getFreeSpace() > 16384)
				sbrk(-16384);
			return;
		}
		lastNode = curNode;
		curNode = curNode->next;
	}
}
size_t getFreeSpace()
{
	malloc_node_t *endNode = getEndNode();
	size_t upperAddr = (size_t)sbrk(0);
	size_t lowerAddr;
	if (endNode)
		lowerAddr = (size_t)endNode+endNode->length+sizeof(malloc_node_t);
	else
		return 0;
	return upperAddr-lowerAddr;
}
void *getOriginalBreak()
{
	static void *original_break = NULL;
	if (original_break == NULL)
		original_break = sbrk(0);
	return original_break;
}
int _PAXICO_check_leaks() {
	return getOriginalBreak() != getEndNode();
}
