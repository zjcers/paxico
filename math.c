#include "math.h"
int pow(int base, int power) {
  power--;
  for (; power>0; power--) {
    base *= base;
  }
  return base;
}
