#include <unistd.h>
int main(int argc, char const *argv[]) {
	if (sbrk(0) > 0) {
		return 0;
	}
	return 1;
}
