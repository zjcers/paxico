#include <stdlib.h>
#include <stdio.h>
#include "memory.h"
FILE *stdout;
FILE *stdin;
FILE *stderr;
int main (int argc, char const *argv[], char const *envp[]);
void _LIBSIMPLEC_libc_main(int argc, char const *argv[], char const *envp[]) {
	init_malloc();
	stdin = fdopen(STDIN_FILENO, "r");
	stderr = fdopen(STDERR_FILENO, "w");
	stdout = fdopen(STDOUT_FILENO, "w");
	exit(main(argc, argv, envp));
}
