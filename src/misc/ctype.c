/*
 * src/misc/ctype.c
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
 * Defines the character-typing functions for ctype.h
 */
#include <ctype.h>
int inline isalnum(int c) {
	return (isalpha(c) || isdigit(c));
}
int inline isalpha(int c) {
	return (isupper(c) || islower(c));
}
int inline iscntrl(int c) {
	return (c >= 0 && c <= 31) || (c == 127);
}
int inline isdigit(int c) {
	return (c >= '0' && c <= '9');
}
int inline isgraph(int c) {
	return (isalnum(c) || ispunct(c));
}
int inline islower(int c) {
	return (c >= 'a' && c <= 'z');
}
int inline isprint(int c) {
	return (isgraph(c) || c == ' ');
}
int inline ispunct(int c) {
	return (c >= '!' && c <= '/') || (c >= ':' && c <= '@') || (c >= '[' && c <= '`') || (c >= '{' && c <= '~');
}
int inline isspace(int c) {
	return (c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v');
}
int inline isupper(int c) {
	return (c >= 'A' && c <= 'Z');
}
int inline isxdigit(int c) {
	return (isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}
int inline isascii(int c) {
	return (c >= 0 && c <= 127);
}
int inline isblank(int c) {
	return (c == ' ' || c == '\t');
}
