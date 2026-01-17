#ifndef CHARARRAY_H_
#define CHARARRAY_H_

#include <stddef.h>

typedef struct {
  size_t length;
  size_t cap;
  char *ptr;
} CharArray;

void carr_printInfo(CharArray *arr);

// general DynArray functions
int carr_init(CharArray *arr, const size_t cap);
int carr_append(CharArray *arr, const char c);

// specific CharArray functions
int addstr(CharArray *arr, const char *str);
int setstr(CharArray *arr, const char *str);
int getstr(char *dest, CharArray *arr);
#endif // CHARARRAY_H
