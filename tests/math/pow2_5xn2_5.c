#include <math.h>
int main(int argc, char const *argv[]) {
	if (fabs(pow(2.5, -2.5)-0.10119) < 0.01){
		return 0;
	}
	return 1;
}
