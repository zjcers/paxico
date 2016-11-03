#include <math.h>
int main(int argc, char const *argv[]) {
	if (fabs(pow(2.5, 2.5)-9.882117688) < 0.01){
		return 0;
	}
	return 1;
}
