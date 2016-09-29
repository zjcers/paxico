.globl _start
_start:
  call init_malloc
  popq %rdi; #pop argc off of the stack
  movq %rsp, %rsi; #pop argv off of the stack
  #movq %rcx, %rax; #copy argc to rax
  #movq 8, %rdx; #set rdx to 8
  #mulq %rdx; #multiply rax by rdx (argc*8); store in rax
  #movq %rax, %rdi; #copy the length of the array needed into rdi (first argument)
  #call malloc; #call malloc to allocated [rdi] bytes of memory
  #movq %rax, %rdi; #base address of malloc'd block in rax; copy to rdi
  #movq %rcx, %rax;
  #argv_loop:
  #  popq %rdx;
  #  movq %rdx, (%rdi);
  #  add $8, %rdi;
  #  cmp %rax, 0; #if rax == 0
  #  jne argv_loop; #jump back to top of loop
  call main;
  movq %rax, %rdi;
  call sys_exit
