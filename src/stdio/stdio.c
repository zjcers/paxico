#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int puts(const char* str) {
	/*Declare variables*/
	size_t length;
	/*End declare variables
		Get the length of the given string */
	length = strlen(str);
	/*The rest is just a wrapper around a system call*/
	return write(STDOUT_FILENO, str, length);

}
int putchar(int str) {
	/*Declare variables*/
	char c;
	int ret;
	/*End declare variables
		Cast the given character to a uint8_t*/
	c = (uint8_t) str;
	/*Execute system call, see write(2)*/
	ret = write(STDOUT_FILENO, &c, 1);
	/*If the write failed return EOF, else return str*/
	ret = (ret == -1) ? EOF : str;
	return ret;
}
