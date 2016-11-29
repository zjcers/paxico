#include <stdarg.h>
/*A little test function that takes a variable number of ints and sums them*/
int test_func(int num_args, ...) {
	va_list ap;
	va_start(ap, num_args);
	int sum = 0;
	for (; num_args >0; num_args--) {
		sum += va_arg(ap, int);
	}
	return sum;
}
int main(int argc, char const *argv[]) {
	int i = test_func(0);
	return !(i == 0);
}
