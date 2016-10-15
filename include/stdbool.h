#ifndef _Z_STDBOOL_H
#define _Z_STDBOOL_H
#define true 1
#define false 0
/*This is supposed to be defined so that outside programs know that stdbool is actually stdbool*/
#define __bool_true_false_are_defined 1
/*For now, bools are really going to be chars*/
typedef char bool;
#endif
