#include <sys/types.h>
#include <errno.h>
#include <stdint.h>
#include <bits/fcntl.h>
#ifdef PLATFORM_LINUX
#ifdef PLATFORM_X86_64
/*Forward declarations in unistd.h*/
ssize_t write(int fileno, const char* buffer, size_t length) {
	/*Declare variables*/
	ssize_t ret;
	unsigned int fd;
	/*End variables*/
	ret = 0;
	fd = (unsigned int) fileno;
	/*sys_write:
		%rdi: unsigned int fd
		%rsi: const char* buffer
		%rdx: size_t length
		Returns:
			%rax: see errno.h
	*/
	__asm__ volatile ("movq $1, %%rax\n"
                "syscall;"
                : "=a" (ret)
                : "D" (fd), "S" (buffer), "d" (length)
                : );
  return (ret);
}
ssize_t read(int fileno, void* outbuf, size_t count) {
	/*Declare variables*/
	ssize_t bytes_read;
	unsigned int fd;
	/*End variables*/
	bytes_read = 0;
	fd = (unsigned int) fileno;
	/*sys_read:
		%rdi: unsigned int fd
		%rsi: const char* outbuf
		%rdx: size_t count
		Returns:
			%rax: see errno.h
	*/
	__asm__ volatile ("movq $0, %%rax\n"
                "syscall"
                : "=a" (bytes_read)
                : "D" (fd), "S" (outbuf), "d" (count)
                :);
  return (bytes_read);
}
int _open(const char* pathname, int flags, mode_t mode) {
	/*Declare variables*/
	int file;
	/*End variables*/
	/*sys_open:
		%rdi: const char* pathname
		%rsi: int flags
		%rdx: int mode
		Returns:
			%rax: see errno.h*/
  asm volatile ("movq $2, %%rax\n"
                "syscall"
                : "=a" (file)
                : "D" (pathname), "S" (flags), "d" (mode)
                :);
	/*Set errno to the correct value*/
	if (file < 0) {
		errno = file;
		return -1;
	}
	return file;
}

int close(int file) {
  int ret = 0;
  asm volatile ("movq $3, %%rax\n"
                "syscall"
                : "=a" (ret)
                : "D" (file));
  return(ret);
}
/*Wrapper around the exit system call. Does not call atexit stuff*/
void _exit(int status) {
  asm volatile ("movq $60, %%rax\n"
                "syscall"
                :
                : "D" (status)
                :);
}
/*Convenience wrapper around the real brk system call*/
static inline void* sys_brk(void* requested_break) {
	/*Declare variables*/
	void* brk_ptr;
	/*End variables*/
	__asm__ volatile ("movq $12, %%rax\n"
                    "syscall"
                    : "=a" (brk_ptr)
                    : "D" (requested_break)
                    :);
	return brk_ptr;
}
/*brk() attempts to set the program break to addr. If this succeeds, it returns
	0. If it fails, it returns -1 and sets errno to ENOMEM*/
int brk(void* addr) {
	/*Check if the new program break matches the requested one*/
	if (sys_brk(addr) == addr) {
		return 0;
	}
	/*Set errno if the above fails*/
	errno = ENOMEM;
	return -1;
}
/*sbrk() takes in a increment value to adjust the program break by. If the OS
	hands out the requested memory, it returns the new program break. If not, it
	returns -1 and errno is set to ENOMEM. sbrk(0) gets the current program
	break.*/
void* sbrk(intptr_t incr) {
	/*Declare variables*/
	void* current_break, *new_break;
	/*End variables*/
	current_break = sys_brk(0);
	/*If incr was zero, just return the current_break.
		This isn't strictly necessary, but avoids an extra system call*/
	if (!incr) {
		return current_break;
	}
	new_break = sys_brk(current_break+incr);
	/*Check if we get all of the memory we've requested*/
	if ((current_break+incr) == new_break) {
		/*Return the address of the new program break*/
		return new_break;
	}
	/*Set errno and fail*/
	errno = ENOMEM;
	return (void*)-1;
}
mode_t umask(mode_t cmask)
{
	cmask &= 0777;
	mode_t ret;
	__asm__ __volatile__
	(
		"movq $95, %%rax\n"
		"syscall\n"
		: "=a" (ret)
		: "D" (cmask)
		:
	);
	return cmask;
}
#endif
#endif
