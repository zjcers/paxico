#include <math.h>
#ifdef PLATFORM_X86_64
double pow(double base, double power) {
	double output;
	/*This shim is necessary to avoid spitting out a NaN from the log2 operation
		in the following asm*/
	if (base == 0.0) {
		return 0.0;
	}
	__asm__ volatile ("fldl %2\n"
										"fldl %1\n"
										"fyl2x\n"
										"fld %%st(0)\n"
										"frndint\n"
										"fld %%st(0)\n"
										"fxch %%st(2)\n"
										"fsub %%st(2)\n"
										"f2xm1\n"
										"fld1\n"
										"faddp %%st(1)\n"
										"fscale\n"
										"fwait\n"
										"fstpl %0\n"
										: "=m" (output)
										: "m" (base), "m" (power)
										: "st");
	return output;
}
#else
/*Not implemented*/
#endif
