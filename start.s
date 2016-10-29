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
    call sys_exit

.data
  stuff: .ascii "hello\n\0"
