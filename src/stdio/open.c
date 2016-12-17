/*
 * src/stdio/open.c
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
 * Defines fdopen(), fopen(), and freopen()
 */
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdbool.h>
#include <errno.h>
#include <stdio.h>

/*Makes a FILE object from an open fd*/
FILE *fdopen(int fd, const char *mode)
{
	FILE *nstream;
	mode_t fd_mode = fcntl(fd, F_GETFL);
	switch(mode[0]) {
	case 'r':
		switch (mode[1]) {
		case '+':
			if ((O_ACCMODE & fd_mode) == O_RDWR)
				goto fdopen_cont;
			break;
		case 0:
			if ((O_ACCMODE & fd_mode) != O_WRONLY)
				goto fdopen_cont;
			break;
		}
		break;
	case 'w':
		switch (mode[1]) {
		case '+':
			if ((O_ACCMODE & fd_mode) == O_RDWR)
				goto fdopen_cont;
			break;
		case 0:
			if ((O_ACCMODE & fd_mode) != O_RDONLY)
				goto fdopen_cont;
			break;
		}
		break;
	case 'a':
		switch (mode[1]) {
		case '+':
			if ((O_ACCMODE & fd_mode) == O_RDWR)
				goto fdopen_cont;
			break;
		case '0':
			if ((O_ACCMODE & fd_mode) != O_RDONLY)
				goto fdopen_cont;
			break;
		}
		break;
	}
	errno = EINVAL;
	return NULL;
	fdopen_cont:
		nstream = (FILE*)malloc(sizeof(FILE));
		switch (fd) {
		case STDOUT_FILENO:
			nstream->buff_mode = BUFF_LINE;
			break;
		case STDERR_FILENO:
			nstream->buff_mode = BUFF_NONE;
			nstream->bsize = 0;
			goto skip_buf;
			break;
		default:
			nstream->buff_mode = BUFF_ALL;
			break;
		}
		nstream->bsize = BUFSIZ;
		nstream->buffer = (char*)malloc(BUFSIZ);
		skip_buf:
			nstream->pos = lseek(fd, 0, SEEK_CUR);
			nstream->level = 0;
			nstream->istemp = false;
			return nstream;
}
