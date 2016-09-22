#ifndef _Z_MEMORY_H
#define _Z_MEMORY_H
#include "stdint.h"
typedef struct malloc_node {
  struct malloc_node* next;
  unsigned int length;
  void* data;
} malloc_node;
void init_malloc();
size_t getFreeSpace();
int checkLeaks();
void* getOriginalBreak();
malloc_node* findHoleInList(size_t n);
malloc_node* findHoleAfterList(size_t n);
malloc_node* getEndNode();
void addAfter(malloc_node* front);
void delAfter(malloc_node* front);
#endif
