#include <stdlib.h>
#include "chararray.h"


size_t hash(char *str) {
    size_t hash = 5381;
    int c;
    while (c = *str++)
        hash = ((hash << 5) + hash) + c;
    return hash;
}


int pair_init(Pair *p, size_t c) {
  carr_init(&p->k, c);
  carr_init(&p->v, c);
  return 0;
} // pair_init

int mapElem_init(MapElem *e, size_t c) {
  pair_init(&e->p, c);
  e->nxt = NULL;
  return 0;
} // mapElem_init

int strmap_init(StrMap *arr, size_t c) {
  arr->l = 0;
  arr->c = (c ? c : 1);
  arr->ptr = calloc(arr->c, sizeof(MapElem));  // use calloc since being NULL is important here
  if (!arr->ptr)
    return -1;

  return 0;
} // strmap_init
