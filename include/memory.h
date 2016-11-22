#ifndef _Z_MEMORY_H
#define _Z_MEMORY_H
#include <stdint.h>
/*Private functions used mostly by the test suite*/
void init_malloc();
size_t _LIBSIMPLEC_get_free_space();
int _LIBSIMPLEC_check_leaks();
#endif
