#include "math.h"
#ifdef PLATFORM_X86
/*Computes floating point absolute value*/
double fabs(double x) {
	__asm__ volatile ("fldl %0\n"
										"fabs\n"
										"fstpl %0\n"
										: "=m" (x)
										: "0" (x)
										: "st");
	return x;
}
#else
double fabs(double x) {
	if (x < 0.0) {
		x *= -1.0;
	}
	return x;
}
#endif
