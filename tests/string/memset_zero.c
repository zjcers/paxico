#include <string.h>
int main(int argc, char const *argv[]) {
	static char str[256];
	str[64] = 1;
	memset(str, 0, 64);
	size_t i;
	for (i = 0; i < 64; i++) {
		if (str[i] != 0) {
			return 1;
		}
	}
	return !(str[64] == 1);
}
