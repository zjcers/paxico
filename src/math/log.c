#include <math.h>
#ifdef PLATFORM_X86_64
/*Computes the natural log of x*/
double log(double x) {
	double output;
	__asm__ volatile ("fld1\n"
										"fldl %1\n"
										"fyl2x\n"
										"fldl2e\n"
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
