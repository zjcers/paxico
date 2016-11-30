#include <stdlib.h>
int abs(int x) {
	if (x < 0) {
		return -1*x;
	}
	return x;
}
long int labs(long int x) {
	if (x < 0) {
		return -1*x;
	}
	return x;
}
