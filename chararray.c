#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

#include "chararray.h"

// general DynArray functions
int str_init(CharArray *arr, const size_t cap) {
  arr->length = 0;
  arr->cap = cap;
  arr->ptr = (char *)malloc(sizeof(char) * cap);
  assert(arr->ptr != NULL);

  return 0;
} // str_init

int char_append(CharArray *arr, const char c) {
  if (arr->length == arr->cap) {
    arr->cap *= 2;
    arr->ptr = (char *)realloc(arr->ptr, sizeof(char) * arr->cap);
  }
  arr->ptr[arr->length] = c;
  ++arr->length;
  return 0;
} // char_append

// specific CharArray functions
int addstr(CharArray *arr, const char *str);
int setstr(CharArray *arr, const char *str);
char *getstr(CharArray *arr);
