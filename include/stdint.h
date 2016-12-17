/*
 * include/stdint.h
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
 * Declares specific-width types
 */
#ifndef _PAXICO_STDINT_H
#define _PAXICO_STDINT_H
/*Set the branding macro*/
#ifndef _PAXICO_LIBC_
#define _PAXICO_LIBC_
#endif
/*See https://sourceforge.net/p/predef/wiki/DataModels/ */
#define NULL 0
#ifdef __ILP32__
	typedef unsigned char uint8_t;
	typedef unsigned short uint16_t;
	typedef unsigned int uint32_t;
	typedef unsigned int size_t;
	typedef signed int ssize_t;
	typedef signed char int8_t;
	typedef short int16_t;
	typedef int int32_t;
	typedef int intptr_t;
	typedef unsigned int uintptr_t;
#endif /*end __ILP32__*/
#ifdef __LP64__
	typedef unsigned char uint8_t;
	typedef unsigned short uint16_t;
	typedef unsigned int uint32_t;
	typedef unsigned long uint64_t;
	typedef unsigned long size_t;
	typedef signed long ssize_t;
	typedef signed char int8_t;
	typedef short int16_t;
	typedef int int32_t;
	typedef long int64_t;
	typedef long intptr_t;
	typedef unsigned long uintptr_t;
#endif /*end __LP64__ */
#endif /*end _PAXICO_STDINT_H*/
