#ifndef _Z_FCNTL_H
#define _Z_FCNTL_H
#include <sys/types.h>
/*Constants for open(2)*/
/*Read/write*/
#ifndef PLATFORM_LINUX
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
#endif
int open(const char* pathname, int flags, ...);
#define open(pathname, flags) open(pathname, flags, 00660)
#define creat(filename, mode) open(filename, O_WRONLY | O_CREAT | O_TRUNC, mode)
#endif
