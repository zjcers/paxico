#This is the very first file linked into a program (before the program's object file)
#It needs to define _start, which is the entry point
#_start has to do the following:
#	move argv and envp somewhere safe
#	set up the stack
#	call the libc entry point
.text
  .globl _start
  _start:
    xorq %rbp, %rbp #set the base point to 0
    popq %rdi #get argc off of the stack and put it in rdi
    movq %rsp, %rsi #copy the base address of argv to rsi
    movq %rdi, %rax #copy rdi to rax
    movq $8, %r8
    mulq %r8 #get the length of of argv - 8
    addq $16, %rax #rax now has the length of argv + 8
    addq %rsp, %rax
    movq %rax, %rdx # third argument is envp
    addq $8, %rsp # realign rsp to a 16-byte boundary
    call _LIBSIMPLEC_libc_main
.data
	.globl errno
	errno: .zero 4
