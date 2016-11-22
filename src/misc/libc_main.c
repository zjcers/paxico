#include <stdlib.h>
#include "memory.h"
int main (int argc, char const *argv[], char const *envp[]);
void _LIBSIMPLEC_libc_main(int argc, char const *argv[], char const *envp[]) {
	init_malloc();
	exit(main(argc, argv, envp));
}
