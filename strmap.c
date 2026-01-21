#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "strmap.h"
#include "chararray.h"

// Standard DJB2 hash
size_t hash(const char *str) {
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

// prints
static void printLevel(unsigned level) {
  for (unsigned i = 0; i < level; ++i)
    printf("  ");
}

void pair_print(Pair *p, const unsigned lvl) {
  printLevel(lvl);
  printf("Pair:\n");
  printLevel(lvl+1);
  printf("Key  : %s\n", p->k.ptr);
  printLevel(lvl+1);
  printf("Value: %s\n", p->v.ptr);
} // pair_print

void mapElem_print(MapElem *e, const unsigned lvl) {
  printLevel(lvl);
  printf("MapElem:\n");
  pair_print(&e->p, lvl+1);
  printLevel(lvl+1);
  printf("Next Null: %b\n", e->nxt == NULL);
} // mapElem_print

void strmap_print(StrMap *arr, const unsigned lvl);


// strmap functions
int strmap_put(StrMap *arr, const char *k, const char *v) {
  size_t h = hash(k);
  MapElem *curr = &arr->ptr[h];
  // if arr.ptr[h] is not free, follow linked chain until free
  if (curr->p.k.ptr != NULL) {
    for (; 
      strncmp(curr->p.k.ptr, k, strlen(k)) == 0 &&
        curr->nxt != NULL;
      curr = curr->nxt
      );
  }
  
  mapElem_init(curr, strlen(k));
  Pair *pair = &(curr->p);
  setstr(&pair->k, k);
  setstr(&pair->v, v);
  return 0;
} // strmap_put

char *strmap_get(StrMap *arr, char *k) {
  return '\0';
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

