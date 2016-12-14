/*
 * src/stdio/open.c
 * Copyright 2016 Zane J Cersovsky
 * Defines fdopen(), freopen(), and fopen()
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
