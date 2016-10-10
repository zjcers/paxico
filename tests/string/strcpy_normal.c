#include "string.h"
int main(int argc, char const *argv[]) {
	static char str1[] = "hello";
	static char str2[10];
	if (strcpy(str1, str2) == 6) {
		if (str2[0] == 'h') {
			if (str2[4] == 'o') {
				return 0;
			}
			return 3;
		}
		return 2;
	}
	return 0;
}
