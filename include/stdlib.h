/*
 * include/stdlib.h
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
 * Declares basic functionality and also a few random math things
 */
#ifndef _PAXICO_STDLIB_H
#define _PAXICO_STDLIB_H 1
/*Set the branding macro*/
#ifndef _PAXICO_LIBC_
#define _PAXICO_LIBC_
#endif
#include <stdint.h>
#include <unistd.h>
/*Define various constants if not already defined*/
#ifndef NULL
#define NULL 0x00
#endif
#ifndef EXIT_FAILURE
#define EXIT_FAILURE 0x01
#endif
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0x00
#endif

/*types*/
struct {
	int quot;
	int rem;
} typedef div_t;
struct {
	long int quot;
	long int rem;
} typedef ldiv_t;

/*string to number conversions*/
int atoi(const char* src);
double atof(const char* src);
long atol(const char* src);
long long atoll(const char* src);

double strtod(const char* src, char** endptr);
long strtol(const char* src, char** endptr, int base);
long long int strtoll(const char* src, char** endptr, int base);

/*number to string conversions*/
char* itoa(int value, char* str, int base);

/*dynamic memory*/
void *calloc(size_t nitems, size_t size);
void* malloc(size_t n);
void free(void* addr);

/*Process handling*/
void abort();
int atexit(void (*func)(void));
void exit(int status);

/*Environ and system handling*/
char *getenv(const char *name);
int system(const char* command);

/*binary search and quick sort (actually introsort)*/
void* bsearch(const void* key, const void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*));
void qsort(void* base, size_t nitems, size_t size, int (*compar)(const void *, const void*));

/*misc int math*/
int abs(int x);
long int labs(long int x);
div_t div(int n, int d);
ldiv_t ldiv(long int n, long int d);

/*rando number generation*/
int rand();
void srand(unsigned int seed);

#endif
