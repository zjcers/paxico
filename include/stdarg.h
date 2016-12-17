/*
 * include/stdarg.h
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
 * Declares variadic function handling (currently a cop-out to GCC)
 */
#ifndef _PAXICO_STDARG_H
#define _PAXICO_STDARG_H
/*Set the branding macro*/
#ifndef _PAXICO_LIBC_
#define _PAXICO_LIBC_
#endif
#include <stdlib.h>
#ifdef __GNUC__
#define va_list		__builtin_va_list
#define va_start(ap, last_arg)   __builtin_va_start(ap,last_arg)
#define va_end(ap)       __builtin_va_end(ap)
#define va_arg(v, l)     __builtin_va_arg(v,l)
#else
#ifdef WIP_STDARG_H
/*As per the SysV ABI for AMD64*/
typedef struct {
	unsigned int gp_offset;
	unsigned int fp_offset;
	void *overflow_arg_area;
	uint8_t reg_save_area[176];
} va_list[1];
/*ap is a va_list
	last is the name of the last known variable (last non-vararg)*/
/*The following implementation doesn't work and is incomplete, hence the cop-out
 to GCC's builtins*/
#define va_start(ap,last) __asm__ __volatile__ ( \
	"movq %0, %%r10\n" \
	"movq %%rdi, (%%r10)\n" \
	"addq $0x8, %%r10\n" \
	"movq %%rsi, (%%r10)\n" \
	"addq $0x8, %%r10\n" \
	"movq %%rdx, (%%r10)\n" \
	"addq $0x8, %%r10\n" \
	"movq %%rcx, (%%r10)\n" \
	"addq $0x8, %%r10\n" \
	"movq %%r8, (%%r10)\n" \
	"addq $0x8, %%r10\n" \
	"movq %%r9, (%%r10)\n" \
	"test %%al, %%al\n" \
	"jmp 0f\n" \
	"addq $0x8, %%r10\n" \
	"movaps %%xmm0, (%%r10)\n" \
	"addq $0x10, %%r10\n" \
	"movaps %%xmm1, (%%r10)\n" \
	"addq $0x10, %%r10\n" \
	"movaps %%xmm2, (%%r10)\n" \
	"addq $0x10, %%r10\n" \
	"movaps %%xmm3, (%%r10)\n" \
	"addq $0x10, %%r10\n" \
	"movaps %%xmm4, (%%r10)\n" \
	"addq $0x10, %%r10\n" \
	"movaps %%xmm5, (%%r10)\n" \
	"addq $0x10, %%r10\n" \
	"movaps %%xmm6, (%%r10)\n" \
	"addq $0x10, %%r10\n" \
	"movaps %%xmm7, (%%r10)\n" \
	"0: \n" \
	: \
	: "m" (ap->reg_save_area) \
	: "memory", "r10" \
	); \
	__asm__ __volatile__ ( \
	"movq %%rbp, %%r10\n" \
	"addq $0x10, %%r10\n" \
	"movq %%r10, %0" \
	: "=m" (ap->overflow_arg_area) \
	: \
	: "r10" ); \
	ap->gp_offset = 0; \
	ap->fp_offset = 48;
#define va_arg(ap,type) (*(type*)(ap->reg_save_area+(size_t)ap->gp_offset)); ap->gp_offset += sizeof(type);
#endif /* WIP_STDARG_H */
#endif /* Not cop-out */
#endif /* End _PAXICO_STDARG_H */
