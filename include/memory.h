/*
 * src/stdlib/memory.c
 * Copyright 2016 Zane J Cersovsky
 * Defines all dynamic memory functions except for alloca()
 */
#ifndef _PAXICO_MEMORY_H
#define _PAXICO_MEMORY_H
#include <stdint.h>
/*Private functions used mostly by the test suite*/
void init_malloc();
size_t _PAXICO_get_free_space();
int _PAXICO_check_leaks();
#endif
