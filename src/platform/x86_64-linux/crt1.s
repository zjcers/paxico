#This is the very first file linked into a program (before the program's object file)
#It needs to define _start, which is the entry point
#_start has to do the following:
#	move argv and envp somewhere safe
#	set up the stack
#	call the libc entry point
.text
  .globl _start
  _start:
    call init_malloc
    popq %r15
    movq %r15, %rax
    movq $8, %r10
    mulq %r10
    movq %rax, %rdi
    call malloc
    movq %rax, %r9
    argvloop:
      popq %r8
      cmpq $0, %r8
      jz doneargv
      movq %r8, (%rax)
      addq $8, %rax
      jmp argvloop
    doneargv:
      addq $8, %rsp
    movq %r15, %rdi
    movq %r9, %rsi
    call main
    movq %rax, %rdi
    call _exit
.data
	.globl errno
	errno: .zero 4
