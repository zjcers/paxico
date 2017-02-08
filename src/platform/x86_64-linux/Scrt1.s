/*
 * src/platform/x86_64-linux/Scrt1.s
 * Copyright 2016 Zane J Cersovsky
 * This file is part of Project Paxico.

 * Project Paxico is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Project Paxico is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with Project Paxico.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Declares a bunch of standard system calls
 * This is the very first file linked into a program (before the program's object file)
 * It needs to define _start, which is the entry point
 * _start has to do the following:
 *   move argv and envp somewhere safe
 *   set up the stack
 *   call the libc entry point
 */
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
                call _PAXICO_libc_main
.data
        .globl errno
        errno: .zero 4
