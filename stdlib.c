#include "string.h"
#include "stdint.h"
#include "stdbool.h"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
/*A convenience method to shift a digit into a number*/
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
			/*check if there is a leading - sign*/
			if (src[i] == '-') {
				inNumber = true;
				isNegative = true;
			}
			/*if not, check if the leading digit has been found*/
			else if (src[i] >= '0' && src[i] <= '9') {
				inNumber = true;
				ret = addToNumber(ret, src[i]);
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
char* itoa(int value, char* str, size_t base) {
  if (value == 0) {
    str[0] = '0';
    str[1] = 0;
    return str;
  }
  size_t i = 0;
  if (value < 0) {
    str[0] = '-';
    value = value*-1;
    i++;
  }
  int rev = 0;
  size_t j = 0;
  while(value > 0) {
    rev = rev*10+(value%10);
    value = value/10;
  }
  for (j=i; rev>0; j++) {
    str[j] = (rev%10)+48;
    rev = rev/10;
  }
  str[j] = 0;
  return str;
}
char* uitoa(int value, char* str, size_t base) {
  if (value == 0) {
    str[0] = '0';
    str[1] = 0;
    return str;
  }
  size_t i = 0;
  int rev = 0;
  size_t j = 0;
  while(value > 0) {
    rev = rev*base+(value%base);
    value = value/base;
  }
  for (j=i; rev>0; j++) {
    str[j] = (rev%base)+48;
    rev = rev/base;
  }
  str[j] = 0;
  return str;
}
