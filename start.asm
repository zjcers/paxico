.globl _start
_start:
  call init_malloc
  popq %rdi;
  popq %rsi;  
  call main;
  movq %rax, %rdi;
  call sys_exit
