#ifndef _Z_STDINT_H
#define _Z_STDINT_H
/*See https://sourceforge.net/p/predef/wiki/DataModels/ */
#define NULL 0
#ifdef __ILP32__
  typedef unsigned char uint8_t;
  typedef unsigned short uint16_t;
  typedef unsigned int uint32_t;
  typedef unsigned int size_t;
  typedef signed int ssize_t;
  typedef signed char int8_t;
  typedef short int16_t;
  typedef int int32_t;
#endif /*end __ILP32__*/
#ifdef __LP64__
  typedef unsigned char uint8_t;
  typedef unsigned short uint16_t;
  typedef unsigned int uint32_t;
  typedef unsigned long uint64_t;
  typedef unsigned long size_t;
  typedef unsigned long ssize_t;
  typedef signed char int8_t;
  typedef short int16_t;
  typedef int int32_t;
  typedef long int64_t;
#endif /*end __LP64__ */
#endif /*end _Z_STDINT_H*/
