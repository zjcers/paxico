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
	bool inNumber = false;
	bool isNegative = false;
	for(; src[i] != 0; i++) {
		/*before the number is found in the string*/
		if (inNumber == false) {
			switch (src[i]) {
				/*check if there is a leading - sign*/
				case '-':
					inNumber = true;
					isNegative = true;
					break;
				/*if not, check if the leading digit has been found*/
				case '0' ... '9':
					inNumber = true;
					ret = addToNumber(ret, src[i]);
					break;
				/*if we get this point and it's not whitespace, bail*/
				default:
					if (!isspace(src[i])) {
						return ret;
					}
					break;
			}
		}
		/*inside the number, check if the current char is still a digit*/
		else if (src[i] >= '0' && src[i] <= '9'){
			ret = addToNumber(ret, src[i]);
		}
		/*if the current char is not a digit, the number is over*/
		else {
			break;
		}
	}
	if (isNegative) {
		return ret*-1;
	}
	return ret;
}
