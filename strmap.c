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

static int grow(StrMap *arr, size_t need) {
  if (need <= arr->c) return 0;

  size_t old_c = arr->c;
  while (arr->c < need) arr->c <<= 1;

  MapElem **old_ptr = arr->ptr;
  arr->ptr = calloc(arr->c, sizeof(MapElem *));
  if (!arr->ptr) return -1;
  arr->l = 0;

  for (size_t i = 0; i < old_c; ++i) {
    if (old_ptr[i] == NULL) continue;
    MapElem *curr = old_ptr[i];
    for (MapElem *nxt; curr != NULL; curr = nxt) {
      nxt = curr->nxt;
      strmap_put(arr, curr->p.k.ptr, curr->p.v.ptr);
      mapElem_free(curr);
    }
  }

  free(old_ptr);
  return 0;
}

// init
int pair_init(Pair *p, size_t c) {
  carr_init(&p->k, c);
  carr_init(&p->v, c);
  return 0;
} // pair_init

int mapElem_init(MapElem **e, MapElem *nxt, size_t c) {
  *e = calloc(1, sizeof(MapElem));
  pair_init(&(*e)->p, c);
  (*e)->nxt = nxt;
  return 0;
} // mapElem_init

static void round_up_bit(size_t *c) {
  // rounds c up to the nearest power of 2 for hash modulo optimization
  --*c;
  *c |= *c >> 1;
  *c |= *c >> 2;
  *c |= *c >> 4;
  *c |= *c >> 8;
  *c |= *c >> 16;
  *c |= *c >> 32;
  ++*c;
}

int strmap_init(StrMap *arr, size_t c) {
  arr->l = 0;
  arr->c = (c ? c : 1);
  round_up_bit(&arr->c);
  arr->ptr = calloc(arr->c, sizeof(MapElem *));  // use calloc since being NULL is important here
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
  if (e->nxt != NULL) {
    printLevel(lvl+1);
    printf("Next:\n");
    mapElem_print(e->nxt, lvl+2);
  }
} // mapElem_print

void strmap_print(StrMap *arr, const unsigned lvl) {
  printLevel(lvl);
  printf("StrMap:\n");
  printLevel(lvl+1);
  printf("Length  : %zu\n", arr->l);
  printLevel(lvl+1);
  printf("Capacity: %zu\n", arr->c);
  for (size_t i = 0; i < arr->c; ++i) {
    if (arr->ptr[i] == NULL) continue;
    printLevel(lvl+1);
    printf("Index %zu:\n", i);
    mapElem_print(arr->ptr[i], lvl+2);
  }
} // strmap_print


// strmap functions
int strmap_put(StrMap *arr, const char *k, const char *v) {
  grow(arr, arr->l + 1);
  size_t h = hash(k) & (arr->c - 1);
  MapElem *curr = arr->ptr[h];
  // Collision handling. if arr.ptr[h] is not free, follow linked chain until free.
  if (curr != NULL) {
    MapElem *prev;
    for (bool deep = false;;) {
      if (strcmp(curr->p.k.ptr, k) == 0) {
        MapElem *nxt = curr->nxt;
        mapElem_free(curr);
        mapElem_init(&curr, nxt, strlen(k));
        if (!deep) arr->ptr[h] = curr;
        else prev->nxt = curr;
        break;
      }
      if (curr->nxt == NULL) {
        mapElem_init(&curr->nxt, NULL, strlen(k));
        curr = curr->nxt;
        ++arr->l;
        break;
      }
      deep = true;
      prev = curr;
      curr = curr->nxt;
    }
  } else { 
    mapElem_init(&curr, NULL, strlen(k));
    arr->ptr[h] = curr;
    ++arr->l;
  }
  setstr(&curr->p.k, k);
  setstr(&curr->p.v, v);
  return 0;
} // strmap_put

char *strmap_get(StrMap *arr, char *k) {
  size_t h = hash(k) & (arr->c - 1);
  MapElem *curr = arr->ptr[h];
  for (;curr != NULL && strcmp(curr->p.k.ptr, k) != 0 ; curr = curr->nxt);
  if (curr == NULL) return NULL;
  return curr->p.v.ptr;
} // strmap_get



// free
void pair_free(Pair *p) {
  free(p->k.ptr);
  free(p->v.ptr);
} // pair_free

void mapElem_free(MapElem *e) {
  pair_free(&e->p);
  free(e);
} // mapElem_free

void mapElem_chain_free(MapElem *e) {
  MapElem *curr = e;
  for (MapElem *nxt; curr != NULL; curr = nxt) {
    nxt = curr->nxt;
    mapElem_free(curr);
  }
} // mapElem_chain_free

void strmap_free(StrMap *arr) {
  for (size_t i = 0; i < arr->c; ++i) {
    if (arr->ptr[i] == NULL) continue;
    mapElem_chain_free(arr->ptr[i]);
  }

  free(arr->ptr);
} // strmap_free

