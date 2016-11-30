#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
/*A convenience method to shift a digit into a number*/
static int addToNumber(int prevNum, char currDigit);
inline int addToNumber(int prevNum, char currDigit) {
	/*48 is the offset between ASCII character codes and actual numbers*/
	int currNum = (int)currDigit - 48;
	return (prevNum*10)+currNum;
}
int atoi(const char* src) {
	size_t i = 0;
	int ret = 0;
	bool minus = false;
	for(; src[i] !=0; i++) {
		if (!(isspace(src[i])))
			break;
	}
	switch (src[i]) {
	case '-':
		minus = true;
	case '+':
		i++;
		break;
	}
	for(; src[i] != 0; i++) {
		switch (src[i]) {
		case '0' ... '9':
			ret = addToNumber(ret, src[i]);
			break;
		default:
			goto atoi_end;
			break;
		}
	}
	atoi_end:
		if (minus)
			return -1*ret;
		return ret;
}
