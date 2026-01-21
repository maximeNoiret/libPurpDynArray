#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "chararray.h"
#include "strarray.h"

static int grow(StrArray *arr, size_t need) {
  if (need <= arr->cap)
    return 0;
  size_t new_cap = arr->cap;
  while (new_cap < need + 1)
    new_cap *= 2;

  CharArray *tmp = realloc(arr->ptr, sizeof(CharArray) * new_cap);
  if (!tmp)
    return -1;
  arr->ptr = tmp;
  arr->cap = new_cap;
  return 0;
} // grow

// General DynArray functions
// TODO: Move this to a common place for every array types
static void printLevel(unsigned level) {
  for (unsigned i = 0; i < level; ++i)
    printf("  ");
}
void sarr_printInfo(StrArray *arr, unsigned level) {
  printLevel(level);
  printf("StrArray:\n");
  printLevel(level + 1);
  printf("Length: %zu\n", arr->length);
  printLevel(level + 1);
  printf("Capacity: %zu\n", arr->cap);
  printLevel(level + 1);
  printf("Content {\n");
  for (size_t i = 0; i < arr->length; ++i) {
    carr_printInfo(&arr->ptr[i], level + 2);
    if (i != arr->length - 1)
      printf(",");
  }
  printLevel(level + 1);
  printf("}\n");
} // sarr_printInfo

int sarr_init(StrArray *arr, const size_t cap) {
  arr->length = 0;
  arr->cap = (cap ? cap : 1);
  arr->ptr = malloc(sizeof(CharArray) * arr->cap);
  if (!arr->ptr)
    return -1;

  return 0;
} // sarr_init

int sarr_append(StrArray *arr, const CharArray *s) {
  grow(arr, arr->length + 1);
  arr->ptr[arr->length++] = *s;
  return 0;
} // sarr_append

int sarr_free(StrArray *arr) {
  for (size_t i = 0; i < arr->length; ++i) {
    free(arr->ptr[i].ptr);
  }

  free(arr->ptr);
  return 0;
}

// specific StrArray functions
int addstr(StrArray *arr, const char *str) {
  grow(arr, arr->length + 1);
  carr_init(&arr->ptr[arr->length++], strlen(str) + 1);
  setstr(&arr->ptr[arr->length - 1], str);
  return 0;
} // addstr

int sarr_init_items(StrArray *arr, size_t n, size_t c_cap) {
  size_t finalLength = arr->length + n;
  grow(arr, finalLength);
  for (size_t i = arr->length; i < finalLength; ++i) {
    carr_init(&arr->ptr[i], c_cap);
    ++arr->length;
  }
  return 0;
} // sarr_init_items
