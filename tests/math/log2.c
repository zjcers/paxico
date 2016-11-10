#include <math.h>
int main(int argc, char const *argv[]) {
	if (fabs(log(2.0)-0.693147181) < 0.00001){
		return 0;
	}
	return 1;
}
