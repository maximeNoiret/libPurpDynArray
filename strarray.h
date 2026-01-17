#ifndef STRARRAY_H_
#define STRARRAY_H_

#include "chararray.h"
#include <stdio.h>

typedef struct {
  size_t length;
  size_t cap;
  CharArray *ptr;
} StrArray;

// general DynArray functions
void sarr_printInfo(StrArray *arr, unsigned level);
int sarr_init(StrArray *arr, const size_t cap);
int sarr_append(StrArray *arr, const CharArray *s);
int sarr_free(StrArray *arr);

// specific CharArray functions
int addstr(StrArray *arr, const char *str);
int sarr_init_items(StrArray *arr, size_t n, size_t c_cap);

#endif // STRARRAY_H_
