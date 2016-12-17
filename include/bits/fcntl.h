/*
 * include/bits/fcntl.h
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
 * Defines macros for various fs-related constants
 */
#ifndef _PAXICO_BITS_FCNTL_H
#define _PAXICO_BITS_FCNTL_H
/*Set the branding macro*/
#ifndef _PAXICO_LIBC_
#define _PAXICO_LIBC_
#endif
/*Constants for open(2)*/
/*Read/write*/
#ifdef PLATFORM_LINUX
#define O_RDONLY		00000000
#define O_WRONLY		00000001
#define O_RDWR			00000002
#define O_ACCMODE 	00000003

/*Access parameters*/
#define O_APPEND		00002000
#define O_CREAT 		00000100
#define O_EXCL			00000200
#define O_NOCTTY		00000400
#define O_NONBLOCK	00004000
#define O_DSYNC			00010000
#define O_SYNC			04010000
#define O_TRUNC			00001000

/*
 * Constants for fcntl(2)
 * cmd values:
 */
#define F_DUPFD	0 /*duplicate fd*/
#define F_GETFD	1 /*get fd flags*/
#define F_SETFD	2 /*set fd flags*/
#define F_GETFL	3 /*get status flags*/
#define F_SETFL	4 /*set status flags*/

#endif /*PLATFORM_LINUX*/
#endif /*_PAXICO_BITS_FCNTL_H*/
