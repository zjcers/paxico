#include "string.h"
#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
int atoi(const char* src) {
  size_t i = 0;
  int ret = 0;
  for(; src[i] != 0; i++) {
    if (src[i] > 47 && src[i] < 58) {
      ret += (src[i]-48)*pow(10, i);
    }
  }
  if (src[0] == '-') {
    ret *= -1;
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
