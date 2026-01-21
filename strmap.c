#include <stdlib.h>
#include "strmap.h"
#include "chararray.h"

// Standard DJB2 hash
size_t hash(char *str) {
    size_t hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}

// init
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


// strmap functions
int strmap_put(StrMap *arr, char *k, char *v) {
  size_t h = hash(k);
  
  return 0;
} // strmap_put

char *strmap_get(StrMap *arr, char *k) {

} // strmap_get



// free
void pair_free(Pair *p) {
  free(p->k.ptr);
  free(p->v.ptr);
} // pair_free

void mapElem_free(MapElem *e) {
  pair_free(&e->p);
  // TODO
} // mapElem_free

void mapElem_chain_free(MapElem *e) {
  // TODO
} // mapElem_chain_free

void strmap_free(StrMap *arr) {
  for (size_t i = 0; i < arr->c; ++i) {
    if (arr->ptr[i].p.k.ptr == NULL) continue;
    mapElem_chain_free(&arr->ptr[i]);
  }

  free(arr->ptr);
} // strmap_free

