#include <math.h>
#ifdef PLATFORM_X86_64
/*Computes the base-10 log of x*/
double log10(double x) {
	double output;
	__asm__ __volatile__ (
		"fld1\n"
		"fldl %1\n"
		"fyl2x\n"
		"fldl2t\n"
		"fdivrp\n"
		"fstpl %0\n"
		: "=m" (output)
		: "m" (x)
		: "st"
	);
	return output;
}
#else
	/*Not implemented*/
#endif
