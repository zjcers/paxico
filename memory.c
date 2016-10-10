#include "stdint.h"
#include "memory.h"
#include "syscalls.h"
void init_malloc() {
  void* originalBreak = getOriginalBreak();
  void* currentBreak = sys_sbrk(0);
  malloc_node* base;
  if (currentBreak == originalBreak) {
    currentBreak = sys_sbrk(16384);
    base = (malloc_node*)originalBreak;
    base->length = 0;
    base->data = NULL;
    base->next = NULL;
    #ifdef DEBUG_MALLOC
      printf("base at %u, endNode at %u\n", base, getEndNode());
    #endif
  }
}
malloc_node* getEndNode() {
  malloc_node* curNode = (malloc_node*)getOriginalBreak();
  while (curNode->next != NULL) {
    curNode = curNode->next;
  }
  return (curNode);
}
malloc_node* findHoleInList(size_t n) {
  #ifdef DEBUG_MALLOC
    printf("Searching for hole in list (n=%u)\n", n);
  #endif
  size_t i = 0;
  malloc_node* curNode = (malloc_node*)getOriginalBreak();
  while(curNode->next != NULL) {
    #ifdef DEBUG_MALLOC
      printf("findholeinlist at curNode=%u\n",curNode);
    #endif
    if ((size_t)curNode->next-((size_t)curNode+sizeof(curNode)+curNode->length) >= n+sizeof(malloc_node)) {
      #ifdef DEBUG_MALLOC
        printf("Returning after i=%u\n",i);
        printf("sizeof(malloc_node)=%u\n",sizeof(malloc_node) );
        printf("curNode=%u\n", (zjc::size_t)curNode);
        printf("curNode->next=%u\n", (zjc::size_t)curNode->next);
        printf("Space=%u\n",(zjc::size_t)(curNode->next)-((zjc::size_t)curNode+sizeof(malloc_node)+curNode->length));
      #endif
      return (curNode);
    }
    #ifdef DEBUG_MALLOC
      printf("i: %u\n",i);
    #endif
    i++;
    curNode = curNode->next;
  }
  return(NULL);
}
malloc_node* findHoleAfterList(size_t n) {
  if (getFreeSpace() >= n+sizeof(malloc_node)) {
    return(getEndNode());
  }
  return (NULL);
}
void addAfter(malloc_node* front) {
  #ifdef DEBUG_MALLOC
    printf("addAfter called with front=%u", front);
  #endif
  malloc_node* next = (malloc_node*)(((void*)front)+sizeof(malloc_node)+front->length);
  #ifdef DEBUG_MALLOC
    printf("addafter making new node at %u", next);
  #endif
  next->next = front->next;
  front->next = next;
  next->data = next+sizeof(next);
}
void delAfter(malloc_node* front) {
  if (front->next != NULL) {
    front->next = front->next->next;
  }
}
void* malloc(size_t n) {
  if (n == 0) {
    return (NULL);
  }
  static int isInit = 0;
  if (isInit == 0) {
    isInit++;
    init_malloc();
  }
  #ifdef DEBUG_MALLOC
    printf("malloc called with n=%u\n", n);
  #endif
  malloc_node* place = findHoleInList(n);
  if (place == NULL) {
    #ifdef DEBUG_MALLOC
      printf("findHoleInList called with n=%u, hole not found\n", n);
    #endif
    place = findHoleAfterList(n);
    #ifdef DEBUG_MALLOC
      printf("putting node after %u\n", place);
    #endif
    if (place == NULL) {
      void* oldBreak = sys_sbrk(0);
      void* newBreak = sys_sbrk(16384);
      if (newBreak > oldBreak) {
        return (malloc(n));
      }
      else {
        return(NULL);
      }
    }
  }
  addAfter(place);
  place = place->next;
  place->length = n;
  #ifdef DEBUG_MALLOC
    printf("malloc done\n");
  #endif
  return (place->data);
}
int free(void* addr) {
  malloc_node* base = (malloc_node*)getOriginalBreak();
  malloc_node* lastNode = base;
  malloc_node* curNode = base->next;
  while (curNode != NULL) {
    if (curNode->data == addr) {
      delAfter(lastNode);
      if (getFreeSpace() > 16384) {
        sys_sbrk(-16384);
      }
      return(1);
    }
    lastNode = curNode;
    curNode = curNode->next;
  }
  return (0);
}
size_t getFreeSpace() {
  malloc_node* endNode = getEndNode();
  #ifdef DEBUG_MALLOC
    printf("endNode: %u\n", endNode);
  #endif
  size_t upperAddr = (size_t)sys_sbrk(0);
  size_t lowerAddr = (size_t)endNode+endNode->length+sizeof(malloc_node);
  return upperAddr-lowerAddr;
}
void* getOriginalBreak() {
  static void* original_break = NULL;
  if (original_break == NULL) {
    original_break = sys_sbrk(0);
  }
  return(original_break);
}
int checkLeaks() {
  #ifdef DEBUG_MALLOC
    printf("base addr: %u endNode addr: %u\n", base, endNode);
  #endif
  return(getOriginalBreak() != getEndNode());
}
